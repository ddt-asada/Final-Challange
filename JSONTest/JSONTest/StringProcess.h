#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector> 
#include "CONSTANTSTRING.h"

namespace process {
	using namespace std;
	using namespace System;
	using namespace constantstring;
	using namespace boost::property_tree;

	//�쐬���F2017.9.2
	//�쐬�ҁFK.Asada
	//���������������֐��Q�N���X�B
	ref class StringProcess {
	public:
		//�萔�N���X���C���X�^���X��
		CONSTANTSTRING^ MyConst = gcnew CONSTANTSTRING();
		Int32^ column = *MyConst->ZERO;		//�\�̗�
		Int32^ row = *MyConst->ZERO;		//�\�̍s��
		Int32^ tmp = *MyConst->ZERO;
		vector<pair<string, string>>* table = new vector<pair<string, string>>();
		//�f�t�H���g�R���X�g���N�^
		StringProcess() {
		};

		//�t�@�C���p�X��蕶������擾���Ă��̕����񂩂�s���A�񐔁A������𔲂��o���B
		vector<pair<string, string>>* ReadyString(String^ JSONPath) {
			ptree pt;		//�t�@�C�����擾����JSON���i�[����c���[
		//	String^ SJSON = "";
			string JSON = "";
			string path = "";
			MarshalString(JSONPath, path);
			//�󂯎�����t�@�C���p�X��蕶������Ăяo���B
			stringstream ss;
			std::ifstream ifs(path, ios_base::binary);
			ss << ifs.rdbuf();

			//�擾������������JSON���擾����B
			read_json(ss, pt);

			//JSON����\�̏o�͂ɕK�v�ȕ�������Ăяo���B
			TableString(pt, "");
			//JSON����\�̍s��������o���֐����Ăяo���B
			CountRows();
			this->tmp = *this->row;
			//JSON����\�̗񐔂�����o���֐����Ăяo���B
			CountColumn();

			this->row = *this->row - *this->column;
			//�^�C�g���̍s�����l�����ė񐔂�␳����B
			this->column = *this->tmp / *this->row;

			return this->table;
		}

		/*�o�͂���\�̗񐔂�����o���֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada
		*/
		Void CountColumn() {
			//�C�e���[�^�[�ɂ�葖������B
			for (auto itr = this->table->begin(); itr != this->table->end(); ++itr) {
				Int32 tmp = 0;
				//�\�̗v�f����������񐔂��J�E���g
				if (itr->first == "text" || itr->first == "array" || itr->first == "html") {
					*this->column += 1;
				}
				//�����������L�[���������
				else if (itr->first == "colspan") {
					//�����̍s�����v���X����
					*this->column += stoi(itr->second) - 1;
				}
			}
		}

		/*�o�͂���\�̍s��������o�����߂̊֐�
		�쐬���F2017.9.4
		�쐬�ҁFK.Asada*/
		Void CountRows() {
			//�C�e���[�^�[�ɂ�葖������B
			for (auto itr = this->table->begin(); itr != this->table->end(); ++itr) {
				//�e�̃m�[�h�܂��͎q���z��̎��ɗ񐔂��J�E���g
				if ((itr->second == "" && (itr + 1)->first != "array") || itr->first == "array" || itr->first == "html") {
					//�񐔂��C���N�������g
					*this->row += 1;
				}
				else if (itr->first == "colspan") {
					//�����̍s�����v���X����
					*this->row += stoi(itr->second) - 1;
				}
			}
		}

		/*�o�͂���\�ɕK�v�ȕ����񂨂�ї񐔂�����o�����߂̊֐�
		�쐬���F2017.9.4
		�쐬�ҁFK.Asada
		*/
		Void TableString(ptree pt, string key) {
			string childkey = "";		//�ċA�����̎��ɕK�v�Ȏq�̃L�[�����i�[���镶����B
			//�L�[������̎��i���񃋁[�v���j
			if (key == "") {
				//�L�[�����擾���邽�߂̃C�e���[�^�[��錾�B
				auto itr = pt.begin();
				//�L�[�����C�e���[�^�[���擾�B
				key = itr->first;
			}
			//�q�ɕ����񂪂������ꍇ
			if (boost::optional<std::string> str = pt.get_optional<std::string>(key)) {
				//��������L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����B
				this->table->push_back(pair<string, string>(UTF8toSjis(key), UTF8toSjis(str.get())));
			}
			//�q�ɐ������������ꍇ
			else if (boost::optional<int> value = pt.get_optional<int>(key)) {
				//�L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����
				this->table->push_back(pair<string, string>(UTF8toSjis(key), UTF8toSjis(to_string(value.get()))));
			}
			//�q���܂�����ꍇ
			if (pt.get_child_optional(key)) {
				//�q�̌Z��𑖍�����
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//������s�����߂�second���擾
					const ptree& info = child.second;
					//�q�̃L�[�����擾����
					childkey = child.first;
					//�q�v�f���z�񂩂����ł����
					if (boost::optional<int> value = info.get_optional<int>(childkey)) {
						//�L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����
						this->table->push_back(pair<string, string>(UTF8toSjis(childkey), UTF8toSjis(to_string(value.get()))));
					//�q�v�f���z�񂩂�����ł����
					}
					else if (boost::optional<std::string> str = info.get_optional<std::string>(childkey)) {
						this->table->push_back(pair<string, string>(UTF8toSjis("array"), UTF8toSjis(str.get())));
						//��������L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����B					
					}
					else {
						//�ċA�������s��
						TableString(pt.get_child(key), childkey);
					}
				}
			}
		}

		//�t�@�C����蕶������擾����֐�
		//�쐬���F2017.9�D2
		//�쐬�ҁFK.Asada
		String^ LoadJSON(String^ Path) {
			String^ retString = "";			//�ԋp�p������B
			//�t�@�C�����J�����߂̃N���X���C���X�^���X��
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(Path);
			//�t�@�C���ɒ��g�����݂��邩���m�F����B
			if (!reader->EndOfStream) {
				//�ԋp�p������Ƀt�@�C������擾������������i�[�B�B
				retString = reader->ReadToEnd();
			}
			//�ǂݎ��Ȃ���΃G���[��Ԃ��B
			else {
				//�t�@�C���̒��g�����݂��Ă��Ȃ��G���[��\������B
			}
			return retString;
		}

		/*String^�^��string�^�֕ϊ�����֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada
		*/
		void MarshalString(String^ sys_string, string& std_string) {
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