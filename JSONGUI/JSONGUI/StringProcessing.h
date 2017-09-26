#pragma once

#include "CellDataChain.h"	//自作データチェインクラス
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <string>

namespace process {

	using namespace System;
	using namespace std;
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
		
		/*概要：JSONを表に必要な文字列に変換する関数
		引数：string json：ファイルから読み込んだJSON文字列
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void TableString(string json) {
			ptree pt;						//ツリー構造にしたJSONを格納するためのツリー
			stringstream ss;
			ss << json;
			//JSONを処理する準備として取得したJSON文字列をツリー構造にする
			read_json(ss, pt);
			//取得したJSON文字列をチェイン構造化する関数を呼び出す
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*概要：箇条書き型のJSONをチェイン構造に変換する関数
		引数：string json：ファイルより取得したJSON文字列
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void ListString(string json) {
			ptree pt;						//ツリー構造にしたJSONを格納するためのツリー
			//JSONを処理する準備として取得したJSON文字列をツリー構造にする
			read_json(json, pt);
			//取得したJSON文字列をチェイン構造化する関数を呼び出す
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*概要：DBから受け取ったJSONをチェイン構造に変換する関数
		引数：string json：DBから取得したJSON文字列
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void DBString(string dbresult) {
			ptree pt;		//JSONを格納するためのツリーを宣言
			//DBより取得したJSON文字列をJSONツリーに変換
			read_json(dbresult, pt);
			//JSONをチェイン構造に変換する関数を呼び出す
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*概要：文字列からJSONへの変換を行う関数
		引数：string key：再帰するときの親のキー名
			：cellchain^ json：値を取得するための親の構造体
		戻り値：ptree：文字列から作成したJSONツリー
		作成日：2017.9.21
		作成者：K.Asada*/
		ptree ConvertJSON(std::string key, CellDataChain::cellchain^ json) {
			ptree parent;	//子要素を連結するための親ツリー
			ptree child;	//親ツリーに連結する子ツリー
			string parentkey;		//親キーを格納するための文字列
			//弟に向かって走査する
			for (; json->next != nullptr; json = json->next) {
				//親キーを保管する
				this->MarshalString(json->key,parentkey);
				//子がいれば再帰して子に潜っていく
				if (json->lower != nullptr) {
					//再帰処理して帰ってきた子ツリーを取得する
					child = ConvertJSON(parentkey, json);
				}//子がいない場合は親キーと値をセットにしてツリーに追加
				else {
					string value;
					MarshalString(json->value, value);
					//親キーと値をセットにして子ツリーに格納
					child.add(parentkey, value);
				}
				//親キーと子ツリーを連結する
				parent.add_child(parentkey, child);
			}
			//作成したJSONツリーを返却する
			return parent;
		}

		/*概要：JSONをチェイン構造文字列に変換する関数
		引数：ptree pt：JSONをツリー構造にしたもの
			：string key：親キー
			：cellchain^ parent：親の構造体
		戻り値：なし
		作成日」2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain^ JSONString(ptree pt, string key, CellDataChain::cellchain^ parent) {
			CellDataChain ChainCtrl;			//データチェインクラスをインスタンス化
			string childkey = "";				//子供のキーを格納するための文字列
			CellDataChain::cellchain^ brother = gcnew CellDataChain::cellchain();		//兄弟を連結するための構造体
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
						brother = ChainCtrl.ChainYoungBrother(gcnew String(childkey.c_str()), gcnew String(childtree.get <std::string>(childkey).c_str()), brother);
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
					//この文字列がこの場合は再帰せずに弟にデータを連結していく
					if (str.get() != "") {
						//子要素のキーを取り出す
						childkey = child.first;
						//弟にデータを連結する関数を呼び出す
						brother = ChainCtrl.ChainYoungBrother(gcnew String(childkey.c_str()), gcnew String(childtree.get <std::string>(childkey).c_str()), brother);
					} //親の場合は弟にデータを連結しながら子へ再帰していく
					else {
						//弟にデータを連結する関数を呼び出す
						brother = ChainCtrl.ChainYoungBrother(gcnew String(childkey.c_str()), gcnew String(childtree.get <std::string>(childkey).c_str()), brother);
						//子にデータを連結するために再帰処理を行う
						brother->lower = this->JSONString(childtree, childkey, brother);
						brother->lower->upper = brother;
					}
				}
			}
			return %*ChainCtrl.FirstChain(brother);
		}


		

		/*概要：オブジェクト配列の文字列処理を行う関数
		引数：cons ptree&：JSONのツリー
			：CellDataChain::cellchain^：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain^ ArrayJSONobject(const ptree& info, CellDataChain::cellchain^ brother,string key) {
			CellDataChain::cellchain^ arrayparent = gcnew CellDataChain::cellchain();	//配列の要素を連結するための構造体を宣言
			CellDataChain ChainCtrl;				//データチェインを操作するためにクラスをインスタンス化
			//引数に受け取った構造体の子として配列要素の構造体を連結する
		//	arrayparent = ChainCtrl.ChainChild(gcnew String(key.c_str()), "", brother);
			//イテレーターにより配列の要素を走査して連結してく
			for (auto itr = info.begin(); itr != info.end(); itr++) {
				//弟として連結していく
				arrayparent = ChainCtrl.ChainYoungBrother(gcnew String(itr->first.c_str()), gcnew String(info.get<string>(itr->first).c_str()), arrayparent);
			}
			return %*ChainCtrl.FirstChain(arrayparent);
		}

		/*概要：配列の文字列処理を行う関数
		引数：ptree：JSONのツリー
			：CellDataChain::cellchain^：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain^ ArrayJSON(ptree pt, CellDataChain::cellchain^ brother, string key) {
			CellDataChain ChainCtrl;				//データチェインを操作するためにクラスをインスタンス化
			//配列を操作する
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)){
				//引数の構造体の弟として配列の要素を連結していく
				brother = ChainCtrl.ChainYoungBrother("", gcnew String(child.second.get<string>(child.first).c_str()), brother);
			}
			return brother;
		}

		/*概要：文字列処理の初回に実行される関数
		引数：ptree：JSONのツリー
		戻り値：CellDataChain::cellchain^：JSONをチェインした構造体
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain^ MakeParent(ptree pt) {
			auto itr = pt.begin();		//親キーを取得するためのイテレーターを宣言
			string key = itr->first;	//初回処理の時はキー名が未知のためイテレーターにより動的に確保
			CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();		//最上位の親の構造体を作成
			parent->key = gcnew String(key.c_str());								//キー名を設定
			parent->value = gcnew String((pt.get<std::string>(key)).c_str());		//ツリー構造にしたJSONの最上位から親キーに対応した値を取得
			//作成した構造体を返す
			return parent;
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
		}

	};
}