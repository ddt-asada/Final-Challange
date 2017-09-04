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

	//作成日：2017.9.2
	//作成者：K.Asada
	//文字列を処理する関数群クラス。
	ref class StringProcess {
	public:
		//定数クラスをインスタンス化
		CONSTANTSTRING^ CONST = gcnew CONSTANTSTRING();
		int column;		//表の列数
		int row;		//表の行数
		map<string, string> table;

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

			//JSONから表の行数を割り出す関数を呼び出す。
			CountRows(pt);

			//JSONから表の出力に必要な文字列を呼び出す。
			TableString(pt, "");

			//タイトルの行数を考慮して列数を補正する。
			this->column = (column - 1) / (row - 1);

			return "";
		}

		/*出力する表の行数を割り出すための関数
		作成日：2017.9.4
		作成者：K.Asada*/
		Void CountRows(ptree pt) {
			//イテレーターにより一番親のキー名を取り出す。
			auto itr = pt.begin();
			//1階層下がったところにある兄弟を数えて行数にする。
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(itr->first)) {
				//"class"は付加情報であるので行数から除外する。
				if (child.first != "class") {
					//行数をインクリメントする。
					this->row++;
				}
			}
		}

		/*出力する表に必要な文字列および列数を割り出すための関数
		作成日：2017.9.4
		作成者：K.Asada
		*/
		Void TableString(ptree pt, string key) {
			string childkey = "";		//再帰処理の時に必要な子のキー名を格納する文字列。
			//表の要素を見つけたら。
			if (key == "text") {
				//列数をカウントする。
				this->column++;
			//キー名が空の時（初回ループ時）
			}else if (key == "") {
				//キー名を取得するためのイテレーターを宣言。
				auto itr = pt.begin();
				//キー名をイテレーターより取得。
				key = itr->first;
			}
			//子に文字列があった場合
			if (boost::optional<std::string> str = pt.get_optional<std::string>(key)) {
			//文字列をキー名をペアにしてマップに格納する。

			}
			//子に整数があった場合
			else if (boost::optional<int> value = pt.get_optional<int>(key)) {
			//キー名をペアにしてマップに格納する
				//	std::cout << "value : " << value.get() << std::endl;
			}
			//子がまだいる場合
			if (pt.get_child_optional(key)) {
				//子の兄弟を走査する
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//再帰処理に必要な子のキー名を取得する
					childkey = child.first;
					//再帰処理を行う
					TableString(pt.get_child(key), childkey);
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