#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <Windows.h>
#include <iostream>
#include <string>
#include "CellDataChain.h"	//����f�[�^�`�F�C���N���X
#include "ConstantString.h"

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
		CONSTANTS::ConstantString^ Constants = gcnew CONSTANTS::ConstantString();
		
		/*�T�v�FJSON��\�ɕK�v�ȕ�����ɕϊ�����֐�
		�����Fstring json�F�t�@�C������ǂݍ���JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void TableString(string json) {
			ptree pt;						//�c���[�\���ɂ���JSON���i�[���邽�߂̃c���[
			stringstream ss;				//�������ǂݍ��ނ��߂̃X�g���[��
			//������X�g���[���֕������ǂݍ��܂���
			ss << json;
			//JSON���������鏀���Ƃ��Ď擾����JSON��������c���[�\���ɂ���
			read_json(ss, pt);
			//�擾����JSON��������`�F�C���\��������֐����Ăяo��
			this->Tablechain = this->JSONString(pt, "", nullptr);
			return;
		}

		/*�T�v�F�����񂩂�JSON�ւ̕ϊ����s���֐�
		�����Fstring key�F�ċA����Ƃ��̐e�̃L�[��
			�Fcellchain^ json�F�l���擾���邽�߂̐e�̍\����
		�߂�l�Fptree�F�����񂩂�쐬����JSON�c���[
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada
		�X�V���F2017.9.27
		�X�V�ҁFK.Asada
		�X�V���e�F�I�u�W�F�N�g�z��ɂ��Ή�����悤�ɕύX*/
		ptree ConvertJSON(string parentkey, CellDataChain::cellchain^ parentjson) {
			try {
				ptree child;		//�����K�w�̃c���[��A���������̂��i�[���邽�߂̃c���[
				ptree grandchild;	//�ċA����A���Ă����c���[���i�[���邽�߂̃c���[
				string key = "";	//�L�[�����i�[���邽�߂̕�����
				string value = "";	//�l���i�[���邽�߂̕�����
				//�\���̂̒��g���Ȃ��Ȃ�܂ő�������
				for (; parentjson != nullptr; parentjson = parentjson->next) {
					//������̃L���X�g���s��
					this->MarshalString(parentjson->key, key);
					//������̃L���X�g���s��
					this->MarshalString(parentjson->value, value);
					//�L�[�����󂩂ǂ����Ŕz��̏����ƒʏ�̏����ɕ��򂷂�
					if (key != "") {
						//�\���̂Ɏq������ꍇ�͍ċA�������Ďq��JSON������
						if(parentjson->lower != nullptr){
							//�ċA�������s���q�c���[���擾����
							grandchild = this->ConvertJSON(key, parentjson->lower);
							//�q�c���[�����̊K�w�̃c���[�ɘA�����Ă���
							child.push_back(std::make_pair(this->SjistoUTF8(key), grandchild));
							//�ċA�����ɂĎ擾�����q�c���[�����̏����ɔ����ď���������
							grandchild.clear();
						}//�q�����Ȃ��ꍇ�̓L�[�ƒl���y�A�ɂ��ăm�[�h�����
						else {
							//�q�m�[�h�����
							child.add(this->SjistoUTF8(key), this->SjistoUTF8(value));
						}
					}
					//�L�[������̏ꍇ�͔z��Ƃ��Ĕz��p�̏����ɕ���
					else {
						//�q�����݂���ꍇ�̓I�u�W�F�N�g�z��Ƃ��Ĉ���
						if (parentjson->lower != nullptr) {
							//�ċA�������s���q�c���[���擾����
							grandchild = this->ConvertJSON(key, parentjson->lower);
							//�q�c���[�����̊K�w�̃c���[�ɘA�������Ă���
							child.push_back(std::make_pair(this->SjistoUTF8(key), grandchild));
							//�ċA�����ɂĎ擾�����q�c���[�����̏����ɔ����ď���������
							grandchild.clear();
						}
						//�q�����Ȃ��ꍇ�͔z��Ƃ��ăc���[�ɘA�����Ă���
						else {
							//�q�m�[�h�����
							grandchild.put(this->SjistoUTF8(key), this->SjistoUTF8(value));
							//�q�m�[�h��z��Ƃ��Ă��̊K�w�̃c���[�ɘA�����Ă���
							child.push_back(std::make_pair(this->SjistoUTF8(key), grandchild));
							//�q�m�[�h�����̏����ɔ����ď���������
							grandchild.clear();
						}
					}
				}
				//�쐬����JSON�c���[��ԋp����
				return child;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}


		/*�T�v�FJSON���`�F�C���\��������ɕϊ�����֐�
		�����Fptree pt�FJSON���c���[�\���ɂ�������
			�Fstring key�F�e�L�[
			�Fcellchain^ parent�F�e�̍\����
		�߂�l�F�Ȃ�
		�쐬���v2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ JSONString(ptree pt, string key, CellDataChain::cellchain^ parent) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();			//�f�[�^�`�F�C���N���X���C���X�^���X��
				string childkey = "";				//�q���̃L�[���i�[���邽�߂̕�����
				CellDataChain::cellchain^ brother = nullptr;		//�Z���A�����邽�߂̍\����
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
							brother = CellCtrl->ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(str.get()).c_str()), brother);
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
						//�q�����Ȃ���΍ċA�����ɒ�Ƀf�[�^��A�����Ă���
						if ((childtree.get_child(childkey)).empty()) {
							//�q�v�f�̃L�[�����o��
							childkey = child.first;
							//��Ƀf�[�^��A������֐����Ăяo��
							brother = CellCtrl->ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(childtree.get <std::string>(childkey)).c_str()), brother);
						} //�e�̏ꍇ�͒�Ƀf�[�^��A�����Ȃ���q�֍ċA���Ă���
						else {
							//��Ƀf�[�^��A������֐����Ăяo��
							brother = CellCtrl->ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(childtree.get <std::string>(childkey)).c_str()), brother);
							//�q�Ƀf�[�^��A�����邽�߂ɍċA�������s��
							brother->lower = this->JSONString(childtree, childkey, brother);
							brother->lower->upper = brother;
						}
					}
				}
				return %*CellCtrl->GetYoungChain(brother);
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}


		

		/*�T�v�F�I�u�W�F�N�g�z��̕����񏈗����s���֐�
		�����Fcons ptree&�FJSON�̃c���[
			�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ ArrayJSONobject(const ptree& info, CellDataChain::cellchain^ brother,string key) {
			try {
				CellDataChain::cellchain^ arrayparent = nullptr;	//�z��̗v�f��A�����邽�߂̍\���̂�錾
				CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
				//�C�e���[�^�[�ɂ��z��̗v�f�𑖍����ĘA�����Ă�
				for (auto itr = info.begin(); itr != info.end(); itr++) {
					//��Ƃ��ĘA�����Ă���
					arrayparent = ChainCtrl.ChainYoungBrother(gcnew String(UTF8toSjis(itr->first).c_str()), gcnew String(UTF8toSjis(info.get<string>(itr->first)).c_str()), arrayparent);
				}
				return %*ChainCtrl.GetElderChain(arrayparent);
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*�T�v�F�z��̕����񏈗����s���֐�
		�����Fptree�FJSON�̃c���[
			�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ ArrayJSON(ptree pt, CellDataChain::cellchain^ brother, string key) {
			try {
				CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
				//�z��𑀍삷��
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//�����̍\���̂̒�Ƃ��Ĕz��̗v�f��A�����Ă���
					brother = ChainCtrl.ChainYoungBrother("", gcnew String(UTF8toSjis(child.second.get<string>(child.first)).c_str()), brother);
				}
				return brother;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
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
			return;
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