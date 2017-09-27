#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <Windows.h>
#include <iostream>
#include <string>
#include "CellDataChain.h"	//����f�[�^�`�F�C���N���X

namespace process{

	using namespace std;
	using namespace System;
	using namespace boost::property_tree;


	/*�T�v�F������֌W�̏������s���֐�
	�쐬���F2017.9.21
	�쐬�ҁFK.Asada*/
	public ref class StringProcessing {
	public:
		//�f�t�H���g�R���X�g���N�^
		StringProcessing() {

		}

		CellDataChain::cellchain^ Tablechain = gcnew CellDataChain::cellchain();	//JSON�𕶎���ɕϊ����Đe�q�A�Z��֌W�̃f�[�^�`�F�C�����s�����߂̍\����
		
		/*�T�v�FJSON��\�ɕK�v�ȕ�����ɕϊ�����֐�
		�����Fstring json�F�t�@�C������ǂݍ���JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void TableString(string json) {
			ptree pt;						//�c���[�\���ɂ���JSON���i�[���邽�߂̃c���[
			stringstream ss;
			ss << json;
			//JSON���������鏀���Ƃ��Ď擾����JSON��������c���[�\���ɂ���
			read_json(ss, pt);
			//�擾����JSON��������`�F�C���\��������֐����Ăяo��
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*�T�v�F�ӏ������^��JSON���`�F�C���\���ɕϊ�����֐�
		�����Fstring json�F�t�@�C�����擾����JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void ListString(string json) {
			ptree pt;						//�c���[�\���ɂ���JSON���i�[���邽�߂̃c���[
			//JSON���������鏀���Ƃ��Ď擾����JSON��������c���[�\���ɂ���
			read_json(json, pt);
			//�擾����JSON��������`�F�C���\��������֐����Ăяo��
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*�T�v�FDB����󂯎����JSON���`�F�C���\���ɕϊ�����֐�
		�����Fstring json�FDB����擾����JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void DBString(string dbresult) {
			ptree pt;		//JSON���i�[���邽�߂̃c���[��錾
			//DB���擾����JSON�������JSON�c���[�ɕϊ�
			read_json(dbresult, pt);
			//JSON���`�F�C���\���ɕϊ�����֐����Ăяo��
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*�T�v�F�����񂩂�JSON�ւ̕ϊ����s���֐�
		�����Fstring key�F�ċA����Ƃ��̐e�̃L�[��
			�Fcellchain^ json�F�l���擾���邽�߂̐e�̍\����
		�߂�l�Fptree�F�����񂩂�쐬����JSON�c���[
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		ptree ConvertJSON(std::string key, CellDataChain::cellchain^ json) {
			ptree parent;	//�q�v�f��A�����邽�߂̐e�c���[
			ptree child;	//�e�c���[�ɘA������q�c���[
			string parentkey;		//�e�L�[���i�[���邽�߂̕�����
			//��Ɍ������đ�������
			for (; json->next != nullptr; json = json->next) {
				//�e�L�[��ۊǂ���
				this->MarshalString(json->key,parentkey);
				//�q������΍ċA���Ďq�ɐ����Ă���
				if (json->lower != nullptr) {
					//�ċA�������ċA���Ă����q�c���[���擾����
					child = ConvertJSON(parentkey, json);
				}//�q�����Ȃ��ꍇ�͐e�L�[�ƒl���Z�b�g�ɂ��ăc���[�ɒǉ�
				else {
					string value;
					MarshalString(json->value, value);
					//�e�L�[�ƒl���Z�b�g�ɂ��Ďq�c���[�Ɋi�[
					child.add(parentkey, value);
				}
				//�e�L�[�Ǝq�c���[��A������
				parent.add_child(parentkey, child);
			}
			//�쐬����JSON�c���[��ԋp����
			return parent;
		}

		/*�T�v�FJSON���`�F�C���\��������ɕϊ�����֐�
		�����Fptree pt�FJSON���c���[�\���ɂ�������
			�Fstring key�F�e�L�[
			�Fcellchain^ parent�F�e�̍\����
		�߂�l�F�Ȃ�
		�쐬���v2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ JSONString(ptree pt, string key, CellDataChain::cellchain^ parent) {
			CellDataChain ChainCtrl;			//�f�[�^�`�F�C���N���X���C���X�^���X��
			string childkey = "";				//�q���̃L�[���i�[���邽�߂̕�����
			CellDataChain::cellchain^ brother = gcnew CellDataChain::cellchain();		//�Z���A�����邽�߂̍\����
			//���񃋁[�v���̏����i����̓L�[�����킩��Ȃ��A�\���̂����݂��Ă��Ȃ����߂ɍ��j
			if (key == "") {
				auto itr = pt.begin();		//�e�L�[���擾���邽�߂̃C�e���[�^�[��錾
				string key = itr->first;	//���񏈗��̎��̓L�[�������m�̂��߃C�e���[�^�[�ɂ�蓮�I�Ɋm��
			}
			//JSON�c���[�̌Z��ɂ��đ�������
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
				//�z�񂩂ǂ����̔�����s�����ߎq�c���[���擾
				const ptree& info = child.second;
				//�����񂩂ǂ����̔�����s�����߂Ɏq�c���[���擾
				ptree childtree = pt.get_child(key);
				//�q�̃L�[�����擾����
				childkey = child.first;
				//�q�̃I�u�W�F�N�g���z�񂩂ǂ����̔�����s��
				if (boost::optional<string>str = info.get_optional <string>(childkey)) {
					//�z��̗v�f���I�u�W�F�N�g�������̔z�񂩂ŏ����𕪊�
					if (info.begin() != info.end()) {
						brother = ChainCtrl.ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(childtree.get <std::string>(childkey)).c_str()), brother);
						//�z��I�u�W�F�N�g���\���̂Ƀ`�F�C������֐����Ăяo��
						brother->lower = this->ArrayJSONobject(info, brother, childkey);
						brother->lower->upper = brother;
					}//�����̔z�񂾂����ꍇ
					else {
						//�z��̍\���̂Ƀ`�F�C������֐����Ăяo��
						brother = this->ArrayJSON(pt, brother, key);
						//�����̔z��̏ꍇ�͈��ŏ����ł���̂ŌZ��ւ̃��[�v�𔲂���
						break;
					}
				//�q���z��ȊO�ł����
				}
				else if (boost::optional<string>str = childtree.get <string>(childkey)) {
					//���̕����񂪂��̏ꍇ�͍ċA�����ɒ�Ƀf�[�^��A�����Ă���
					if (str.get() != "") {
						//�q�v�f�̃L�[�����o��
						childkey = child.first;
						//��Ƀf�[�^��A������֐����Ăяo��
						brother = ChainCtrl.ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(childtree.get <std::string>(childkey)).c_str()), brother);
					} //�e�̏ꍇ�͒�Ƀf�[�^��A�����Ȃ���q�֍ċA���Ă���
					else {
						//��Ƀf�[�^��A������֐����Ăяo��
						brother = ChainCtrl.ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(childtree.get <std::string>(childkey)).c_str()), brother);
						//�q�Ƀf�[�^��A�����邽�߂ɍċA�������s��
						brother->lower = this->JSONString(childtree, childkey, brother);
						brother->lower->upper = brother;
					}
				}
			}
			return %*ChainCtrl.FirstChain(brother);
		}


		

		/*�T�v�F�I�u�W�F�N�g�z��̕����񏈗����s���֐�
		�����Fcons ptree&�FJSON�̃c���[
			�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ ArrayJSONobject(const ptree& info, CellDataChain::cellchain^ brother,string key) {
			CellDataChain::cellchain^ arrayparent = gcnew CellDataChain::cellchain();	//�z��̗v�f��A�����邽�߂̍\���̂�錾
			CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
			//�����Ɏ󂯎�����\���̂̎q�Ƃ��Ĕz��v�f�̍\���̂�A������
		//	arrayparent = ChainCtrl.ChainChild(gcnew String(key.c_str()), "", brother);
			//�C�e���[�^�[�ɂ��z��̗v�f�𑖍����ĘA�����Ă�
			for (auto itr = info.begin(); itr != info.end(); itr++) {
				//��Ƃ��ĘA�����Ă���
				arrayparent = ChainCtrl.ChainYoungBrother(gcnew String(UTF8toSjis(itr->first).c_str()), gcnew String(UTF8toSjis(info.get<string>(itr->first)).c_str()), arrayparent);
			}
			return %*ChainCtrl.FirstChain(arrayparent);
		}

		/*�T�v�F�z��̕����񏈗����s���֐�
		�����Fptree�FJSON�̃c���[
			�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ ArrayJSON(ptree pt, CellDataChain::cellchain^ brother, string key) {
			CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
			//�z��𑀍삷��
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)){
				//�����̍\���̂̒�Ƃ��Ĕz��̗v�f��A�����Ă���
				brother = ChainCtrl.ChainYoungBrother("", gcnew String(UTF8toSjis(child.second.get<string>(child.first)).c_str()), brother);
			}
			return brother;
		}

		/*�T�v�F�����񏈗��̏���Ɏ��s�����֐�
		�����Fptree�FJSON�̃c���[
		�߂�l�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ MakeParent(ptree pt) {
			auto itr = pt.begin();		//�e�L�[���擾���邽�߂̃C�e���[�^�[��錾
			string key = itr->first;	//���񏈗��̎��̓L�[�������m�̂��߃C�e���[�^�[�ɂ�蓮�I�Ɋm��
			CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();		//�ŏ�ʂ̐e�̍\���̂��쐬
			parent->key = gcnew String(key.c_str());								//�L�[����ݒ�
			parent->value = gcnew String((pt.get<std::string>(key)).c_str());		//�c���[�\���ɂ���JSON�̍ŏ�ʂ���e�L�[�ɑΉ������l���擾
			//�쐬�����\���̂�Ԃ�
			return parent;
		}

		/*String^�^��string�^�֕ϊ�����֐�
		�����FString^ sys_string�F�ϊ��Ώۂ̕�����
		�Fstring& std_string�F�ϊ���̕�����̊i�[��
		�߂�l�F�Ȃ�
		�쐬���F2017.9.22
		�쐬�ҁFK.Asada
		*/
		void MarshalString(String^ sys_string, std::string& std_string) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
			std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		/*�����R�[�h�̕ϊ����s���֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada
		*/
		std::string UTF8toSjis(std::string srcUTF8) {
			//Unicode�֕ϊ���̕����񒷂𓾂�
			int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

			//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//UTF8����Unicode�֕ϊ�
			MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

			//ShiftJIS�֕ϊ���̕����񒷂𓾂�
			int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//�K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
			char* bufShiftJis = new char[lengthSJis];

			//Unicode����ShiftJIS�֕ϊ�
			WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

			std::string strSJis(bufShiftJis);

			delete bufUnicode;
			delete bufShiftJis;

			return strSJis;
		}

		/*�����R�[�h�̕ϊ����s���֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada*/
		std::string SjistoUTF8(std::string srcSjis) {
			//Unicode�֕ϊ���̕����񒷂𓾂�
			int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);

			//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//ShiftJIS����Unicode�֕ϊ�
			MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);


			//UTF8�֕ϊ���̕����񒷂𓾂�
			int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//�K�v�ȕ�����UTF8������̃o�b�t�@���m��
			char* bufUTF8 = new char[lengthUTF8];

			//Unicode����UTF8�֕ϊ�
			WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);

			std::string strUTF8(bufUTF8);

			delete bufUnicode;
			delete bufUTF8;

			return strUTF8;
		}
	};
}