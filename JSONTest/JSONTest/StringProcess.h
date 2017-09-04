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

	//作成日：2017.9.2
	//作成者：K.Asada
	//文字列を処理する関数群クラス。
	ref class StringProcess {
	public:

		//デフォルトコンストラクタ
		StringProcess() {
		};

		//ファイルパスより文字列を取得してその文字列から行数、列数、文字列を抜き出す。
		String^ ReadyString(String^ JSONPath) {
			ptree pt;		//ファイルより取得したJSONを格納するツリー
			string path = "";
			MarshalString(JSONPath, path);
			//受け取ったファイルパスより文字列を取得する関数を呼び出す。
			//JSON = LoadJSON(JSONPath);
			//受け取ったファイルパスよりJSONを取得する。
			read_json(path, pt);

			jsonchange(pt, "");
/*			auto itr = pt.begin();
			const ptree::value_type& child = pt.get_child(itr->first)) {
				if (boost::optional<std::string> str = pt.get_optional<std::string>(child.first)) {
					path = itr->first;
				}
			}
			*/
			//受け取った文字列をJSONに変換する。
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

		//ファイルより文字列を取得する関数
		//作成日：2017.9．2
		//作成者：K.Asada
		String^ LoadJSON(String^ Path) {
			String^ retString = "";			//返却用文字列。
			//ファイルを開くためのクラスをインスタンス化
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(Path);
			//ファイルに中身が存在するかを確認する。
			if (!reader->EndOfStream) {
				//返却用文字列にファイルから取得した文字列を格納。。
				retString = reader->ReadToEnd();
			}
			//読み取れなければエラーを返す。
			else {
				//ファイルの中身が存在していないエラーを表示する。
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