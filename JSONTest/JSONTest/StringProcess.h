#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>

namespace process {
	using namespace std;
	using namespace System;

	using namespace boost::property_tree;

	//�쐬���F2017.9.2
	//�쐬�ҁFK.Asada
	//���������������֐��Q�N���X�B
	ref class StringProcess {
	public:

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

			jsonchange(pt, "");
/*			auto itr = pt.begin();
			const ptree::value_type& child = pt.get_child(itr->first)) {
				if (boost::optional<std::string> str = pt.get_optional<std::string>(child.first)) {
					path = itr->first;
				}
			}
			*/
			//�󂯎�����������JSON�ɕϊ�����B
			write_json(cout, pt);
			
			return "";
		}

		Void jsonchange(ptree pt, string key) {
			auto itr = pt.begin();
			string json;
			if (key == "") {
				key = itr->first;
			}
			if (boost::optional<std::string> str = pt.get_optional<std::string>(key)) {
			}
			else if (boost::optional<int> value = pt.get_optional<int>(key)) {
			//	std::cout << "value : " << value.get() << std::endl;
			}
			if (pt.get_child_optional(key)) {
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					json = child.first;
					jsonchange(pt.get_child(key), json);
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