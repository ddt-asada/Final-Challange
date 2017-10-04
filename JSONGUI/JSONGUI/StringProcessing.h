#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <Windows.h>
#include <iostream>
#include <string>
#include "CellDataChain.h"	//自作データチェインクラス
#include "ConstantString.h"

namespace process{

	using namespace std;
	using namespace System;
	using namespace boost::property_tree;


	/*概要：文字列関係の処理を行う関数
	作成日：2017.9.21
	作成者：K.Asada*/
	public ref class StringProcessing {
	public:
		//デフォルトコンストラクタ
		StringProcessing() {

		}

		CellDataChain::cellchain^ Tablechain = gcnew CellDataChain::cellchain();	//JSONを文字列に変換して親子、兄弟関係のデータチェインを行うための構造体
		CONSTANTS::ConstantString^ Constants = gcnew CONSTANTS::ConstantString();
		
		/*概要：JSONを表に必要な文字列に変換する関数
		引数：string json：ファイルから読み込んだJSON文字列
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void TableString(string json) {
			//JSON以外のファイルが読み込まれたときの例外処理
			try {
				ptree pt;						//ツリー構造にしたJSONを格納するためのツリー
				stringstream ss;				//文字列を読み込むためのストリーム
				//文字列ストリームへ文字列を読み込ませる
				ss << json;
				//JSONを処理する準備として取得したJSON文字列をツリー構造にする
				read_json(ss, pt);
				//取得したJSON文字列をチェイン構造化する関数を呼び出す
				this->Tablechain = this->JSONString(pt, "", nullptr);
				return;
			}
			//読み込んだファイルからJSONに変換できなかったときの例外
			catch (boost::property_tree::json_parser_error& e) {
				//コンソールにJSONファイルでない旨を表示
				cout << e.what();
				Console::WriteLine(Constants->NOT_JSON_MESSAGE);
			}
		}

		/*概要：文字列からJSONへの変換を行う関数
		引数：string key：再帰するときの親のキー名
			：cellchain^ json：値を取得するための親の構造体
		戻り値：ptree：文字列から作成したJSONツリー
		作成日：2017.9.21
		作成者：K.Asada
		更新日：2017.9.27
		更新者：K.Asada
		更新内容：オブジェクト配列にも対応するように変更*/
		ptree ConvertJSON(string parentkey, CellDataChain::cellchain^ parentjson) {
			try {
				ptree child;		//同じ階層のツリーを連結したものを格納するためのツリー
				ptree grandchild;	//再帰から帰ってきたツリーを格納するためのツリー
				string key = "";	//キー名を格納するための文字列
				string value = "";	//値を格納するための文字列
				//構造体の中身がなくなるまで走査する
				for (; parentjson != nullptr; parentjson = parentjson->next) {
					//文字列のキャストを行う
					this->MarshalString(parentjson->key, key);
					//文字列のキャストを行う
					this->MarshalString(parentjson->value, value);
					//キー名が空かどうかで配列の処理と通常の処理に分岐する
					if (key != "") {
						//構造体に子がいる場合は再帰処理して子のJSONをつくる
						if(parentjson->lower != nullptr){
							//再帰処理を行い子ツリーを取得する
							grandchild = this->ConvertJSON(key, parentjson->lower);
							//子ツリーをこの階層のツリーに連結していく
							child.push_back(std::make_pair(this->SjistoUTF8(key), grandchild));
							//再帰処理にて取得した子ツリーを次の処理に備えて初期化する
							grandchild.clear();
						}//子がいない場合はキーと値をペアにしてノードを作る
						else {
							//子ノードを作る
							child.add(this->SjistoUTF8(key), this->SjistoUTF8(value));
						}
					}
					//キー名が空の場合は配列として配列用の処理に分岐
					else {
						//子が存在する場合はオブジェクト配列として扱う
						if (parentjson->lower != nullptr) {
							//再帰処理を行い子ツリーを取得する
							grandchild = this->ConvertJSON(key, parentjson->lower);
							//子ツリーをこの階層のツリーに連結しいていく
							child.push_back(std::make_pair(this->SjistoUTF8(key), grandchild));
							//再帰処理にて取得した子ツリーを次の処理に備えて初期化する
							grandchild.clear();
						}
						//子がいない場合は配列としてツリーに連結していく
						else {
							//子ノードを作る
							grandchild.put(this->SjistoUTF8(key), this->SjistoUTF8(value));
							//子ノードを配列としてこの階層のツリーに連結していく
							child.push_back(std::make_pair(this->SjistoUTF8(key), grandchild));
							//子ノードを次の処理に備えて初期化する
							grandchild.clear();
						}
					}
				}
				//作成したJSONツリーを返却する
				return child;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
			//ptree関係の例外を捕捉
			catch (boost::property_tree::ptree_error& e) {
				//コンソールにエラー内容を表示
				cout << e.what();
				System::Console::WriteLine(Constants->JSON_CONV_MESSAGE);
			}
		}


		/*概要：JSONをチェイン構造文字列に変換する関数
		引数：ptree pt：JSONをツリー構造にしたもの
			：string key：親キー
			：cellchain^ parent：親の構造体
		戻り値：なし
		作成日」2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain^ JSONString(ptree pt, string key, CellDataChain::cellchain^ parent) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();			//データチェインクラスをインスタンス化
				string childkey = "";				//子供のキーを格納するための文字列
				CellDataChain::cellchain^ brother = nullptr;		//兄弟を連結するための構造体
				//初回ループ時の処理（初回はキー名がわからない、構造体が存在していないために作る）
				if (key == "") {
					auto itr = pt.begin();		//親キーを取得するためのイテレーターを宣言
					string key = itr->first;	//初回処理の時はキー名が未知のためイテレーターにより動的に確保
				}
				//JSONツリーの兄弟について走査する
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//配列かどうかの判定を行うため子ツリーを取得
					const ptree& info = child.second;
					//文字列かどうかの判定を行うために子ツリーを取得
					ptree childtree = pt.get_child(key);
					//子のキー名を取得する
					childkey = child.first;
					//子のオブジェクトが配列かどうかの判定を行う
					if (boost::optional<string>str = info.get_optional <string>(childkey)) {
						//配列の要素がオブジェクトかただの配列かで処理を分岐
						if (info.begin() != info.end()) {
							brother = CellCtrl->ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(str.get()).c_str()), brother);
							//配列オブジェクトを構造体にチェインする関数を呼び出す
							brother->lower = this->ArrayJSONobject(info, brother, childkey);
							brother->lower->upper = brother;
						}//ただの配列だった場合
						else {
							//配列の構造体にチェインする関数を呼び出す
							brother = this->ArrayJSON(pt, brother, key);
							//ただの配列の場合は一回で処理できるので兄弟へのループを抜ける
							break;
						}
						//子が配列以外であれば
					}
					else if (boost::optional<string>str = childtree.get <string>(childkey)) {
						//子がいなければ再帰せずに弟にデータを連結していく
						if ((childtree.get_child(childkey)).empty()) {
							//子要素のキーを取り出す
							childkey = child.first;
							//弟にデータを連結する関数を呼び出す
							brother = CellCtrl->ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(childtree.get <std::string>(childkey)).c_str()), brother);
						} //親の場合は弟にデータを連結しながら子へ再帰していく
						else {
							//弟にデータを連結する関数を呼び出す
							brother = CellCtrl->ChainYoungBrother(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(childtree.get <std::string>(childkey)).c_str()), brother);
							//子にデータを連結するために再帰処理を行う
							brother->lower = this->JSONString(childtree, childkey, brother);
							brother->lower->upper = brother;
						}
					}
				}
				return %*CellCtrl->GetElderChain(brother);
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
			//ptree関係の例外を捕捉
			catch (boost::property_tree::ptree_error& e) {
				//コンソールにエラー内容を表示
				cout << e.what();
				System::Console::WriteLine(Constants->JSON_CONV_MESSAGE);
			}
		}


		

		/*概要：オブジェクト配列の文字列処理を行う関数
		引数：cons ptree&：JSONのツリー
			：CellDataChain::cellchain^：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain^ ArrayJSONobject(const ptree& info, CellDataChain::cellchain^ brother,string key) {
			try {
				CellDataChain::cellchain^ arrayparent = nullptr;	//配列の要素を連結するための構造体を宣言
				CellDataChain ChainCtrl;				//データチェインを操作するためにクラスをインスタンス化
				//イテレーターにより配列の要素を走査して連結してく
				for (auto itr = info.begin(); itr != info.end(); itr++) {
					//弟として連結していく
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
			//ptree関係の例外を捕捉
			catch (boost::property_tree::ptree_error& e) {
				//コンソールにエラー内容を表示
				cout << e.what();
				System::Console::WriteLine(Constants->JSON_CONV_MESSAGE);
			}
		}

		/*概要：配列の文字列処理を行う関数
		引数：ptree：JSONのツリー
			：CellDataChain::cellchain^：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain^ ArrayJSON(ptree pt, CellDataChain::cellchain^ brother, string key) {
			try {
				CellDataChain ChainCtrl;				//データチェインを操作するためにクラスをインスタンス化
				//配列を操作する
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//引数の構造体の弟として配列の要素を連結していく
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
			//ptree関係の例外を捕捉
			catch (boost::property_tree::ptree_error& e) {
				//コンソールにエラー内容を表示
				cout << e.what();
				System::Console::WriteLine(Constants->JSON_CONV_MESSAGE);
			}
		}

		/*String^型をstring型へ変換する関数
		引数：String^ sys_string：変換対象の文字列
		：string& std_string：変換後の文字列の格納先
		戻り値：なし
		作成日：2017.9.22
		作成者：K.Asada
		*/
		void MarshalString(String^ sys_string, std::string& std_string) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
			std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return;
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