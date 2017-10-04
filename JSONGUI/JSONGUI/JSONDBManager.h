/* �֐����FcreateJSON
* �T�v:DB����f�[�^���擾����JSON�����
* ����:Map<String,Object> json:�J�����g��JSON
*     String:key:JSON�̃L�[
*     DBResultTree:dbrt_parent:DB����擾�����f�[�^���i�[���ăc���[�\������邽�߂̃N���X�̃C���X�^���X
* �߂�l:����
* �쐬��:2017.9.13
* �쐬��:K.Asada
*/
#pragma once

#include <iostream>
#include <fstream>//�e�X�g�p
#include <string>
#include <vector>
#include <sstream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <boost/uuid/sha1.hpp>
#include <boost/cstdint.hpp>
#include <boost/array.hpp>

#include "mysql_connection.h"

#include "DBConnect.h"		//����N���X�BDB�ڑ��̊֐������B

class JSONDBManager : public DBConnect {
public:int processedRecords = 0;

public:

	JSONDBManager() {

	};
	/*�֐����FDBrun
	�T�v�FDB�Ƃ̒ʐM���s���֐����Ăяo��
	�����Fstring:query�F���s����N�G��
	�߂�l�FDB����擾�����f�[�^
	�쐬���F2017.9.13
	�쐬�ҁFK.Asada*/
	std::string GetDBResult(std::string query) {
		std::string queryResult = "";	//DB�Ƃ̒ʐM���ʂ��i�[���镶����
		//DB�ւ̐ڑ����s��
		this->connect();
		//DB���當������擾���邽�߂̊֐����Ăяo��
		queryResult = this->getListJSON(query);
		//DB����ؒf����
		this->disconnect();
		//�ʐM���ʂ�ԋp����
		return queryResult;
	}


	/* �֐����FexecuteQuery
	* �T�v:�N�G�������s����DB���猋�ʃZ�b�g���擾����
	* ����:Map<String,Object> json:�J�����g��JSON�A�z�z��
	*     String:queryKey:���s����N�G���̃x�[�X�ƂȂ镶����
	* �߂�l:ResultSet retRs:DB����擾�������ʃZ�b�g��Ԃ�
	�쐬���F2017.9.13
	�쐬�ҁFK.Asada
	*/

	//���Ƃŗ�O������ǋL����B
	//�e�X�g�����B
	//�p�X�֌W�̂݌���ǋL�\��B
	sql::ResultSet* executeQuery(std::string queryKey) {
		//�ԋp���錋�ʃZ�b�g�̕ϐ����쐬����
		int tmp = 0;
		std::string query;			//�L�[���ɑΉ������l���i�[���镶����B
		std::string replaceValue;	//�u���Ώۂ̕�������i�[���镶����B
		std::string passString;		//�p�X���[�h�̕R�Â�����������i�[���镶����B
		sql::Statement *stmt;		//�X�e�[�g�����g���i�[����B
		sql::ResultSet *res = NULL;		//Connecter/C++�Ŏg���B
		try {
			//���s�ł��Ȃ��p�^�[���̃N�G�����C������
			query = queryCorrection(queryKey);
			std::cout << query << '\n';
			//�X�e�[�g�����g���쐬����
			stmt = con->createStatement();

			//�N�G�������s�����ʃZ�b�g��Ԃ��N�G���ł���΁B
			if (stmt->execute(query)) {
				res = stmt->getResultSet();
				//�s�����擾���邽�߁A���R�[�h�Z�b�g�̈ʒu��last�ɂ���
				res->last();
				//�������s�������R�[�h�������ʃZ�b�g���擾���ă����o�ɕۑ�����
				processedRecords = res->getRow();
				//�s�����擾���邽�߂�last�ɂ����J�[�\���ʒu��擪�ɖ߂��B
				res->beforeFirst();
			}
			else {
				//���ʂ�Ԃ��Ȃ��ꍇ�͍X�V�����s�����擾����B
				processedRecords = stmt->getUpdateCount();
			}
		}
		catch (sql::SQLException &e) {
			std::cout << "# ERR: SQLException in " << __FILE__;
			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << '\n';
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << '\n';

		}
		//���ʃZ�b�g��Ԃ�
		return res;
	}

	/* �֐����FgetListJSON
	* �T�v:���X�g�`����JSON���쐬���ĕԂ�
	* ����:Map<String, Object> json:JSON�̃I�u�W�F�N�g�B
	* �߂�l:String strAll:JSON�̕�����z��𕶎���ŕԂ�
	�쐬���F2017.9.13
	�쐬�ҁFK.Asada
	*/

	std::string getListJSON(std::string str) {
		//�ԋp���镶������쐬���邽�߂̕ϐ���3�錾�A����������B
		std::string strAll = "";
		std::string strBlock = "";
		std::string strLine = "";
		try {
			//�f�[�^�x�[�X���瓖�Y���R�[�h�Q���擾����(���ʃZ�b�g���擾����)
			sql::ResultSet* rs = executeQuery(str);
			//���R�[�h�Z�b�g�̗񖼂��擾����A���Ƃł�����B
			sql::ResultSetMetaData* rsMeta = rs->getMetaData();
			//���R�[�h�Z�b�g�̗񐔂��擾����A���Ƃł�����B
			int columnCount = rsMeta->getColumnCount();
			//���ʃZ�b�g�̍s�ɂ��Ẵ��[�v
			while (rs->next()) {
				//���R�[�h�̕����������������
				strLine = "";
				//��ɂ��Ẵ��[�v
				for (int i = 0; i < columnCount; i++) {
					//�񖼂��擾����(�ʖ��̎擾)
					std::string sColName = rsMeta->getColumnLabel(i + 1);
					//��̒l���擾����
					std::string value = rs->getString(i + 1);
					//��̒l��NULL�������ꍇ�A�u�����N�ɒu������
					value = value == "" ? "" : value;
					//������̍s�P�ʂ̕ϐ�����łȂ����A�s�̕�������J���}�ŋ�؂�
					strLine += strLine == "" ? "" : ",";

					//�擾�����l�ɁAJSON�p�̃G�X�P�[�v�������s��
					value = escapeJSONValue(value);

					//1�s���̃f�[�^�𕶎���ɒǉ�����
					strLine += "\"" + sColName + "\":\"" + value + "\"";
				}
				//�s�ɕ����񂪓����Ă�����A�J���}�ŋ�؂�
				strBlock += strBlock == "" ? "" : ",";
				//�쐬�����s�̕�������u���b�N�̕�����ɒǉ�����
				strBlock += "{" + strLine + "}";

			}
		}
		catch (std::exception) {

			throw;
		}
		//�쐬�����S�u���b�N��z��̊��ʂň͂�
		strAll = "{\"TableData\":[" + strBlock + "]}";
		//�쐬�����������Ԃ�
		return strAll;
	}
	/* �֐����FescapeJSONValue
	* �T�v:�����Ŏ󂯎�����������JSON�p�̃G�X�P�[�v�������s���ԋp����
	* ����:String str:�G�X�P�[�v���镶����
	* �߂�l:String:�G�X�P�[�v����������
	�쐬���F2017.9.13
	�쐬�ҁFK.Asada
	*/
	std::string escapeJSONValue(std::string str) {
		//�ԋp�p������ɁA�����̕�������Z�b�g����
		std::string retStr = str;
		//���}�[�N���G�X�P�[�v�����ɒu��������(replaceAll�͐��K�\���Ƃ��Ĉ����邽�߁A�����\4���ƂȂ�j
		//�������u��������֐����Ăяo���B
		retStr = Replace(retStr, "\\\\", "\\\\\\\\");
		//���s�������G�X�P�[�v�����ɒu��������
		retStr = Replace(retStr, "\r\n", "\\\\n");
		//���s�������G�X�P�[�v�����ɒu��������
		retStr = Replace(retStr, "\r", "\\\\n");
		//���s�������G�X�P�[�v�����ɒu��������
		retStr = Replace(retStr, "\n", "\\\\n");
		//�_�u���N�H�[�g���G�X�P�[�v�����ɒu��������
		retStr = Replace(retStr, "\"", "\\\\\"");
		//�G�X�P�[�v�����l��ԋp����
		return retStr;
	}

	/*�֐����FReplace
	�T�v�F�����Ŏ󂯎��������������ւ���֐�
	�����Fstring rep�F���g��ύX������������
		�Fstring target�F�u�������Ώۂ̕�����
		�Fstring change�F�u��������̕�����
	�߂�l�FString�F�����񂩂�Ώۂ̕���������ׂĒu��������������
	�쐬���F2017.9.13
	�쐬�ҁFK.Asada
	*/
	std::string Replace(std::string rep, std::string target, std::string change) {
		for (int i = 0; i < rep.length();) {
			//�u�������Ώۂ̕������T���B
			i = rep.find(target, i);
			//�u�������Ώۂ̕���������������B
			if (i <= rep.length()) {
				//�������u��������B
				rep.replace(i, target.length(), change);
				//�C���f�b�N�X�̈ʒu��u��������������̌��Ɉړ�������
				i += change.length();
			}
		}
		//�u��������̕������Ԃ��B
		return rep;
	}
	/* �֐����FqueryCorrection
	* �T�v:Java�ł͎��s�ł��Ȃ��^�C�v�̃N�G���[���C�����ĕԋp����
	* ����:String query:�C���Ώۂ̃N�G���[
	* �߂�l:String:�C����̃N�G���[��ԋp����
	* �쐬��:2017.9.13
	* �쐬��:K.Asada
	*/
	//���邩�킩��Ȃ����ǂƂ肠�����u���Ă����B
	std::string queryCorrection(std::string query) {
		//�ԋp�p�N�G���[�̕������錾���A���͂̃N�G���[���Z�b�g����
		std::string retQuery = query;
		//�N�G���[�̒��ɃZ�~�R�������܂܂�Ă���ꍇ
		if (retQuery.find(";") != -1) {
			//�N�G���̍ŏ���;��������index��ێ�����B;���o�͑Ώۂ̂��߁A���l��+1����
			int index = retQuery.find(";") + 1;
			//�N�G���[�����񂩂�ŏ���";"�܂ł�؂�o��
			retQuery = retQuery.substr(0, index);
		}
		//�C�������N�G���[��ԋp����
		return retQuery;
	}
};
