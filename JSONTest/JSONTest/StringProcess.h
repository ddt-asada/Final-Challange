#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <cliext/map> 
#include "CONSTANTSTRING.h"

namespace process {
	using namespace std;
	using namespace System;
	using namespace constantstring;
	using namespace boost::property_tree;
	using namespace cliext;
	typedef map<String^, String^ > mymap;

	//�쐬���F2017.9.2
	//�쐬�ҁFK.Asada
	//���������������֐��Q�N���X�B
	ref class StringProcess {
	public:
		//�萔�N���X���C���X�^���X��
		CONSTANTSTRING^ CONST = gcnew CONSTANTSTRING();
		int column;		//�\�̗�
		int row;		//�\�̍s��
		map<string, string> table;

		//�f�t�H���g�R���X�g���N�^
		StringProcess() {
		};

		//�t�@�C���p�X��蕶������擾���Ă��̕����񂩂�s���A�񐔁A������𔲂��o���B
		String^ ReadyString(String^ JSONPath) {
			ptree pt;		//�t�@�C�����擾����JSON���i�[����c���[
			string path = "";
			MarshalString(JSONPath, path);
			//�󂯎�����t�@�C���p�X��蕶������擾����֐����Ăяo���B
			//JSON = LoadJSON(JSONPath);
			//�󂯎�����t�@�C���p�X���JSON���擾����B
			read_json(path, pt);

			//JSON����\�̍s��������o���֐����Ăяo���B
			CountRows(pt);

			//JSON����\�̏o�͂ɕK�v�ȕ�������Ăяo���B
			TableString(pt, "");

			//�^�C�g���̍s�����l�����ė񐔂�␳����B
			this->column = (column - 1) / (row - 1);

			return "";
		}

		/*�o�͂���\�̍s��������o�����߂̊֐�
		�쐬���F2017.9.4
		�쐬�ҁFK.Asada*/
		Void CountRows(ptree pt) {
			//�C�e���[�^�[�ɂ���Ԑe�̃L�[�������o���B
			auto itr = pt.begin();
			//1�K�w���������Ƃ���ɂ���Z��𐔂��čs���ɂ���B
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(itr->first)) {
				//"class"�͕t�����ł���̂ōs�����珜�O����B
				if (child.first != "class") {
					//�s�����C���N�������g����B
					this->row++;
				}
			}
		}

		/*�o�͂���\�ɕK�v�ȕ����񂨂�ї񐔂�����o�����߂̊֐�
		�쐬���F2017.9.4
		�쐬�ҁFK.Asada
		*/
		Void TableString(ptree pt, string key) {
			string childkey = "";		//�ċA�����̎��ɕK�v�Ȏq�̃L�[�����i�[���镶����B
			//�\�̗v�f����������B
			if (key == "text") {
				//�񐔂��J�E���g����B
				this->column++;
			//�L�[������̎��i���񃋁[�v���j
			}else if (key == "") {
				//�L�[�����擾���邽�߂̃C�e���[�^�[��錾�B
				auto itr = pt.begin();
				//�L�[�����C�e���[�^�[���擾�B
				key = itr->first;
			}
			//�q�ɕ����񂪂������ꍇ
			if (boost::optional<std::string> str = pt.get_optional<std::string>(key)) {
			//��������L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����B

			}
			//�q�ɐ������������ꍇ
			else if (boost::optional<int> value = pt.get_optional<int>(key)) {
			//�L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����
				//	std::cout << "value : " << value.get() << std::endl;
			}
			//�q���܂�����ꍇ
			if (pt.get_child_optional(key)) {
				//�q�̌Z��𑖍�����
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//�ċA�����ɕK�v�Ȏq�̃L�[�����擾����
					childkey = child.first;
					//�ċA�������s��
					TableString(pt.get_child(key), childkey);
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

		void MarshalString(String^ sys_string, string& std_string) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
			std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	};
}