#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <cliext/utility>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector> 
#include "CONSTANTSTRING.h"

namespace process {
	using namespace std;
	using namespace System;
	using namespace constantstring;
	using namespace  System::Collections::Generic;
	using namespace boost::property_tree;

	//作成日：2017.9.2
	//作成者：K.Asada
	//文字列を処理する関数群クラス。
	ref class StringProcess {
	public:
		//定数クラスをインスタンス化
		CONSTANTSTRING^ MyConst = gcnew CONSTANTSTRING();
		Int32^ column = *MyConst->ZERO;		//表の列数
		Int32^ row = *MyConst->ZERO;		//表の行数
		Int32^ tmp = *MyConst->ZERO;
		int test = 0;
		List<String^>^ join = gcnew List<String^>;
		List<cliext::pair<String^, String^>^>^ dic = gcnew List<cliext::pair<String^, String^>^>();
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ retPointTable = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();
		vector<pair<pair<string, string>, string>>* jsontable = new vector<pair<pair<string, string>, string>>();

			//デフォルトコンストラクタ
		StringProcess() {
		};

		//ファイルパスより文字列を取得してその文字列から行数、列数、文字列を抜き出す。
		Void ReadyString(String^ JSONPath) {
			ptree pt;		//ファイルより取得したJSONを格納するツリー
		//	String^ SJSON = "";
			string JSON = "";
			string path = "";
			MarshalString(JSONPath, path);
			//受け取ったファイルパスより文字列を呼び出す。
			stringstream ss;
			std::ifstream ifs(path, ios_base::binary);
			ss << ifs.rdbuf();

			//取得した文字列よりJSONを取得する。
			read_json(ss, pt);

			//JSONから表の出力に必要な文字列を呼び出す。
			TableString(pt, "");
			//JSONから表の行数を割り出す関数を呼び出す。
			CountRows();
			this->tmp = *this->row;
			//JSONから表の列数を割り出す関数を呼び出す。
			CountColumn();

			this->row = *this->row - *this->column;
			//タイトルの行数を考慮して列数を補正する。
			this->column = *this->tmp / *this->row;
			//結合状態判定用の文字列を初期化する。
			for (int i = 0; i < this->row; i++) {
				this->join->Add("");
			}

			SetTablePoint();
		}

		/*箇条書きのJSONを読み込むための関数
		作成日：2017.9.12
		作成者：K.Asada */
		//ファイルパスより文字列を取得してその文字列から行数、列数、文字列を抜き出す。
		Void ReadyListString(String^ JSONPath) {
			ptree pt;		//ファイルより取得したJSONを格納するツリー
							//	String^ SJSON = "";
			string JSON = "";
			string path = "";
			MarshalString(JSONPath, path);
			//受け取ったファイルパスより文字列を呼び出す。
			stringstream ss;
			std::ifstream ifs(path, ios_base::binary);
			ss << ifs.rdbuf();

			//取得した文字列よりJSONを取得する。
			read_json(ss, pt);

			//JSONから表の出力に必要な文字列を呼び出す。
			TableString(pt, "");
			//JSONから表の行数を割り出す関数を呼び出す。
			CountRows();
			this->tmp = *this->row;
			//JSONから表の列数を割り出す関数を呼び出す。
			CountColumn();

			this->row = *this->column;
			//タイトルの行数を考慮して列数を補正する。
			this->column = 1;

			SetTablePoint();
		}

		/*出力する表の列数を割り出す関数
		作成日：2017.9.5
		作成者：K.Asada
		*/
		Void CountColumn() {
			//イテレーターにより走査する。
			for (int i = 0; i < this->dic->Count; i++) {
				//表の要素を見つけたら列数をカウント
				if (this->dic[i]->first == "text" || this->dic[i]->first == "array" || this->dic[i]->first == "html") {
					*this->column += 1;
				}
				//結合を示すキー名があれば
				else if (this->dic[i]->first == "colspan") {
					//結合の行数をプラスする
					*this->column += Convert::ToInt32(this->dic[i]->second) - 1;
				}
			}
		}

		/*出力する表の行数を割り出すための関数
		作成日：2017.9.4
		作成者：K.Asada*/
		Void CountRows() {
			//イテレーターにより走査する。
			for (int i = 0; i < this->dic->Count; i++) {
				//親のノードまたは子が配列の時に列数をカウント
				if ((this->dic[i]->second == "" && (this->dic[i + 1])->first != "array") || this->dic[i]->first == "array" || this->dic[i]->first == "html") {
					//列数をインクリメント
					*this->row += 1;
				}
				else if (this->dic[i]->first == "colspan") {
					//結合の行数をプラスする
					*this->row += Convert::ToInt32(this->dic[i]->second) - 1;
				}
			}
		}

		/*出力する表に必要な文字列および列数を割り出すための関数
		作成日：2017.9.4
		作成者：K.Asada
		*/
		Void TableString(ptree pt, string key) {
			string childkey = "";		//再帰処理の時に必要な子のキー名を格納する文字列。
			//キー名が空の時（初回ループ時）
			if (key == "") {
				//キー名を取得するためのイテレーターを宣言。
				auto itr = pt.begin();
				//キー名をイテレーターより取得。
				key = itr->first;
			}
			//子に文字列があった場合
			if (boost::optional<std::string> str = pt.get_optional<std::string>(key)) {
				//文字列をキー名をペアにしてマップに格納する。
				//this->table->push_back(pair<string, string>(UTF8toSjis(key), UTF8toSjis(str.get())));
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(key).c_str()), gcnew String(UTF8toSjis(str.get()).c_str())));
			}
//子に整数があった場合
			else if (boost::optional<int> value = pt.get_optional<int>(key)) {
				//キー名をペアにしてマップに格納する
				//this->table->push_back(pair<string, string>(UTF8toSjis(key), UTF8toSjis(to_string(value.get()))));
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(key).c_str()), gcnew String((UTF8toSjis(to_string(value.get()))).c_str())));
			}
			//子がまだいる場合
			if (pt.get_child_optional(key)) {
				//子の兄弟を走査する
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					this->test++;
					//判定を行うためにsecondを取得
					const ptree& info = child.second;
					//子のキー名を取得する
					childkey = child.first;
					//子要素が配列かつ整数であれば
					if (boost::optional<int> value = info.get_optional<int>(childkey)) {
						//キー名をペアにしてマップに格納する
				//		this->table->push_back(pair<string, string>(UTF8toSjis(childkey), UTF8toSjis(to_string(value.get()))));
						this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(to_string(value.get())).c_str())));
						//子要素が配列かつ文字列であれば
					}
					else if (boost::optional<std::string> str = info.get_optional<std::string>(childkey)) {
						//	this->table->push_back(pair<string, string>(UTF8toSjis("array"), UTF8toSjis(str.get())));
						this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis("array").c_str()), gcnew String(UTF8toSjis(str.get()).c_str())));
						//文字列をキー名をペアにしてマップに格納する。					
					}
					else {
						//再帰処理を行う
						TableString(pt.get_child(key), childkey);
					}
				}
			}
		}

		/*文字列リストに座標を紐づける関数
		作成日：2017.9.11
		作成者：K.Asada*/
		Void SetTablePoint() {
			int itr = 0;		//リストを走査する際のインデックス
			int count = 0;					//要素を取り出した数をカウントする変数
			this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("title")));
			itr++;
			if (dic[itr]->first == "class") {
				this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("title")));
				itr++;
			}

			for (int i = 0; i < *this->row; i++) {
				count = 0;
				if (dic[itr]->second == "" && ((dic[itr + 1])->first != "text" && (dic[itr + 1])->first != "array" && (dic[itr + 1])->first != "html")) {
					this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("y") + Convert::ToString(i)));
					itr++;
				}
				if (dic[itr]->first == "class") {
					this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("y") + Convert::ToString(i)));
					itr++;
				}

				for (int j = 0; j < *this->column; j++) {
					for (; itr < this->dic->Count; ++itr) {
						if (dic[itr]->first == "text" || dic[itr]->first == "array" || dic[itr]->first == "html") {
							//							str = gcnew String((dic[itr]->second).c_);
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
							itr++;
							count++;
							break;
						}
						else if (dic[itr]->first == "colspan") {
							j += Convert::ToInt32(dic[itr]->second) - 1;
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else if (dic[itr]->second == "") {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
					}
					//初回処理時はタイトルを取得したとしてループを抜ける
					if (i == 0 && j == 0) {
						break;
					}
				}
				if (count == 1) {
					this->join[i] = "0";
				}
			}
		}

		/*文字列リストよりJSONに変換する関数
		作成日：2017.9.12
		作成者：K.Asada*/
		Void ConversionJSON() {
			ptree parent;
			ptree child;
			string tmp = "courseGuide";
			string arrtmp = "";
			//String^型の文字列リストをstring型へ変換する関数を呼び出す
			Stos();
			for (int i = 0; i < this->row; i++) {
				child.clear();
				for (auto itr = this->jsontable->begin(); itr != this->jsontable->end(); itr++) {
					if (itr->second == "y" + to_string(i)) {
						if (itr->first.first == "親キー") {
							tmp = itr->first.second;
						}
						else {
							child.put(itr->first.first, itr->first.second);
							break;
						}
					}
				}
				for (int j = 0; j < this->column; j++) {
					for (auto  itr = this->jsontable->begin(); itr != this->jsontable->end(); itr++){
						if (itr->second == "x" + to_string(j) + to_string(i)) {
							if (itr->first.first == "text") {
								child.put((arrtmp + "." + itr->first.first), itr->first.second);
							}
							else if (itr->first.first == "array") {
								arrtmp = (itr - 1)->first.second;
								ptree tmp;
								ptree arr;
								for (; itr->first.first == "array"; itr++) {
									arr.push_back(std::make_pair("", (tmp.put("", itr->first.second))));
									write_json(std::cout, arr);
								}
								child.put_child(arrtmp, arr);
								j += *this->column;
								break;
							}
							else if (itr->first.first != "親キー") {
								child.put(itr->first.first, itr->first.second);
							}
							else if (itr->first.first == "親キー") {
								arrtmp = itr->first.second;
							}
						}
					}
				}
				parent.add_child(tmp, child);
			}
			write_json(std::cout, parent);
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

		/*String^型をstring型へ変換する関数
		作成日：2017.9.5
		作成者：K.Asada
		*/
		void MarshalString(String^ sys_string, string& std_string) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
			std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		/*String^型のリストをstring型へ変換する関数
		作成日：2017.9.12
		作成者：K.Asada*/
		void Stos() {
			string key = "";
			string value = "";
			string point = "";
			for (int i = 0; i < this->retPointTable->Count; i++) {
				MarshalString(this->retPointTable[i]->first->first, key);
				MarshalString(this->retPointTable[i]->first->second, value);
				MarshalString(this->retPointTable[i]->second, point);
				this->jsontable->push_back(pair<pair<string, string>, string>(make_pair(key, value), point));
			}
		}

		/*文字コードの変換を行う関数
		作成日：2017.9.5
		作成者：K.Asada
		*/
		std::string UTF8toSjis(std::string srcUTF8) {
			//Unicodeへ変換後の文字列長を得る
			int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

			//必要な分だけUnicode文字列のバッファを確保
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//UTF8からUnicodeへ変換
			MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

			//ShiftJISへ変換後の文字列長を得る
			int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//必要な分だけShiftJIS文字列のバッファを確保
			char* bufShiftJis = new char[lengthSJis];

			//UnicodeからShiftJISへ変換
			WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

			std::string strSJis(bufShiftJis);

			delete bufUnicode;
			delete bufShiftJis;

			return strSJis;
		}

		/*文字コードの変換を行う関数
		作成日：2017.9.5
		作成者：K.Asada*/
		std::string SjistoUTF8(std::string srcSjis) {
			//Unicodeへ変換後の文字列長を得る
			int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);

			//必要な分だけUnicode文字列のバッファを確保
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//ShiftJISからUnicodeへ変換
			MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);


			//UTF8へ変換後の文字列長を得る
			int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//必要な分だけUTF8文字列のバッファを確保
			char* bufUTF8 = new char[lengthUTF8];

			//UnicodeからUTF8へ変換
			WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);

			std::string strUTF8(bufUTF8);

			delete bufUnicode;
			delete bufUTF8;

			return strUTF8;
		}
	};
}