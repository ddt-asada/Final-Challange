#pragma once

#include "CellDataChain.h"	//����̃f�[�^�`�F�C���N���X�̃w�b�_
#include "StringProcessing.h"	//�����񏈗��N���X�̃w�b�_
#include "JSONDBManager.h"

//���������֌W�̖��O���
namespace process {

	/*�T�v�F���������̓�����ƂȂ�N���X
	�쐬���F2017.9.21
	�쐬�ҁFK.Asada*/
	public ref class Processing : public StringProcessing{
	public:
		//�f�t�H���g�R���X�g���N�^
		Processing() {
		}

		/*�T�v�FJSON��ǂݍ���ŕ\�ɂ��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����FString^ jsonpath�FJSON�t�@�C���̓ǂݍ��ݐ�̃t�@�C���p�X
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada
		�X�V���F2017.9.22
		�X�V�ҁFK.Asada
		�X�V���e�F�������󂯎���ăt�@�C������ǂݍ���JSON��n���悤�ɕύX*/
		Void Tablerun(String^ jsonpath) {
			std::string json = "";		//�t�@�C������ǂݍ���JSON���i�[���镶����
			//�t�@�C������JSON��ǂݍ���
			json = this->LoadJSON(jsonpath);
			//�����񏈗��֐����Ăяo��
			this->TableString(json);

		}

		/*�T�v�FJSON��ǂݍ���ŉӏ������̕\���o�͂��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada
		�X�V���F2017.9.22
		�X�V�ҁFK.Asada
		�X�V���e�F�������󂯎���ăt�@�C������ǂݍ���JSON��n���悤�ɕύX*/
		Void Listrun(String^ jsonpath) {
			std::string json = "";		//�t�@�C������ǂݍ���JSON���i�[���镶����
			//�t�@�C������JSON��ǂݍ���
			json = this->LoadJSON(jsonpath);
			//�����񏈗��֐����Ăяo��
			this->ListString(json);
		}

		/*�T�v�FDB����JSON��ǂݍ���ŕ\���o�͂��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����FString^�FJSON���擾���邽�߂�DB�ɓ�����N�G��
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada
		�X�V���F2017.9.22
		�X�V�ҁFK.Asada
		�X�V���e�F�������󂯎���ăt�@�C������ǂݍ���JSON��n���悤�ɕύX*/
		Void DBrun(String^ DBquery) {
			string result = "";		//DB����擾����JSON��������i�[���邽�߂̕�����
			string query = "";		//DB�֓n���N�G�����i�[���镶����
		//	JSONDBManager db;				//DB�Ƃ̒ʐM���s���N���X���C���X�^���X��
			//���C����ʂ��󂯎�����N�G���̌^�ϊ����s��
			this->MarshalString(DBquery, query);
			//DB����JSON��������擾����
		//	result = db.GetDBResult(query);
			//�����񏈗��֐����Ăяo��
			this->DBString(result);
			//�߂�l�Ȃ�
			return;
		}

		/*�T�v�F�����񂩂�JSON�ւ̕ϊ����s��������ƂȂ�֐�
		�����FString^�F�ϊ�����JSON�t�@�C���̏o�͐�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void Convertrun(String^ jsonpath, CellDataChain::cellchain^ jsonelem) {
			ptree json;		//�����񂩂�쐬����JSON�c���[���i�[���邽�߂̃c���[
			string path = "";	//�t�@�C���p�X��string�^�ɕϊ��������̂��i�[���邽�߂̕�����
			//�t�@�C���p�X��string�^�ɕϊ�����
			this->MarshalString(jsonpath, path);
			//�����񂩂�JSON�c���[���쐬����
			json = this->ConvertJSON("", jsonelem);
			//�쐬����JSON�c���[���t�@�C���ɏo�͂���
			write_json(path, json);
			//�߂�l�Ȃ�
			return;
		}

		/*�T�v�F�t�@�C�����當������擾���邽�߂̊֐�
		�����FString^�F�ǂݍ��ݐ�̃t�@�C���p�X
		�߂�l�FString^�G�ǂݍ��񂾕�����
		�쐬���F207.9.21
		�쐬�ҁFK.Asada*/
		std::string LoadJSON(String^ jsonpath) {
			std::string path = "";		//String^�^����string�^�֕ϊ������t�@�C���p�X���i�[���镶����
			//�^�ϊ����s��
			this->MarshalString(jsonpath, path);
			//�t�@�C����ǂݍ��ޏ���
			std::ifstream ifs(path);
			//�t�@�C���̓ǂݍ��݂Ɏ��s�������̗�O����
			if (ifs.fail()) {
				//��O�𑗏o����
				throw gcnew Exception("�t�@�C���ǂݍ��݃G���[");
			}
			//�t�@�C�����JSON���擾����
			std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
			return json;
		}
	};
}