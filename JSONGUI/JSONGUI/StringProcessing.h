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
	using namespace boost::property_tree;

	/*概要：文字列関係の処理を行う関数
	作成日：2017.9.21
	作成者：K.Asada*/
	public ref class StringProcessing {
	public:
		//デフォルトコンストラクタ
		StringProcessing() {

		}

		Int32^ row = 0;			//表の行数
		Int32^ column = 0;		//表の列数
		Int32^ colcount = 0;	//列数をカウントする変数
		Int32^ rowcount = 0;	//行数をカウントする変数
		CellDataChain::cellchain* Tablechain = nullptr;	//JSONを文字列に変換して親子、兄弟関係のデータチェインを行うための構造体
		List<int>^ joinInfo = gcnew List<int>();	//結合情報を保持する動的配列
		
		/*概要：JSONを表に必要な文字列に変換する関数
		引数：String^：DBから取得したJSONまたはファイルからJSONを読み込むためのファイルパス
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void TableString(String^ jsonpath) {
			std::stringstream JSON;			//読み込んだJSONを格納するための文字列ストリーム
			ptree pt;						//ツリー構造にしたJSONを格納するためのツリー
			//設定画面より受け取ったファイルパスより文字列を読み込む
			std::ifstream ifs(jsonpath, ios_base::binary);
			//文字列を読み込む
			JSON << ifs.rdbuf();
			//JSONを処理する準備として取得したJSON文字列をツリー構造にする
			read_json(JSON, pt);
			//取得したJSON文字列をチェイン構造化する関数を呼び出す
			JSONString(pt, "", nullptr);
		}

		/*概要：JSONをチェイン構造文字列に変換する関数
		引数：ptree：JSONをツリー構造にしたもの
			：string：キー名
		戻り値：なし
		作成日」2017.9.21
		作成者：K.Asada*/
		Void JSONString(boost::property_tree::ptree pt, std::string key, CellDataChain::cellchain* parent) {
			CellDataChain ChainCtrl;							//データチェインクラスをインスタンス化
			std::string childkey = "";							//子供のキーを格納するための文字列
			CellDataChain::cellchain* brother = nullptr;		//兄弟を連結するための構造体
			//初回ループ時の処理（初回はキー名がわからない、構造体が存在していないために作る）
			if (key == "") {
				//最上位の親の構造体を作成する
				brother = MakeParent(pt);
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
				if (boost::optional<std::string>str = info.get_optional <std::string>(childkey)) {
					//配列の要素がオブジェクトかただの配列かで処理を分岐
					if (info.begin() != info.end()) {
						//配列オブジェクトを構造体にチェインする関数を呼び出す
						brother = this->ArrayJSONocject(info, brother);
					}//ただの配列だった場合
					else {
						//配列の構造体にチェインする関数を呼び出す
						brother = this->ArrayJSON(pt, key, brother);
						//ただの配列の場合は一回で処理できるので兄弟へのループを抜ける
						break;
					}
				//子が配列以外であれば
				}
				else if (boost::optional<std::string>str = childtree.get <std::string>(childkey)) {
					//この文字列がこの場合は再帰せずに弟にデータを連結していく
					if (str.get() != "") {
						//弟にデータを連結する関数を呼び出す
						brother = ChainCtrl.ChainYoungBrother(childkey, childtree.get <std::string>(childkey), brother, nullptr);
					} //親の場合は弟にデータを連結しながら子へ再帰していく
					else {
						//弟にデータを連結する関数を呼び出す
						brother = ChainCtrl.ChainYoungBrother(childkey, childtree.get <std::string>(childkey), brother, nullptr);
						//子にデータを連結するために再帰処理を行う
						this->JSONString(childtree, childkey, brother);
					}
				}
			}
		}

		/*概要：文字列からJSONへの変換を行う関数
		引数：string：再帰するときの親のキー名
			：json：文字列からJSONへ変換するためのJSONのツリー
		戻り値：ptree：文字列から作成したJSONツリー
		作成日：2017.9.21
		作成者：K.Asada*/
		ptree ConvertJSON(std::string key, ptree json) {
			ptree parent;	//子要素を連結するための親ツリー
			ptree child;	//親ツリーに連結する子ツリー
			CellDataChain::cellchain* parentchain;	//走査するためのチェイン構造体
			std::string parentkey;		//親キーを格納するための文字列
			//弟に向かって走査する
			for (parentchain = this->Tablechain; parentchain->next != nullptr; parentchain = parentchain->next) {
				//親キーを保管する
				parentkey = parentchain->key;
				//子がいれば再帰して子に潜っていく
				if (parentchain->lower != nullptr) {
					//再帰処理して帰ってきた子ツリーを取得する
					child = ConvertJSON(parentkey, parentchain);
					//親キーと子ツリーを連結する
					parent.add_child(parentkey, child);
				}//子がいない場合は親キーと値をセットにしてツリーに追加
				else {
					//親キーと値をセットにして子ツリーに格納
					child.add((parentkey + "." + parentchain->key), parentchain->value);
				}
			}
			//作成したJSONツリーを返却する
			return child;
		}

		/*概要：列数をカウントする関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void CountColumn() {

		}

		/*概要：行数をカウントする関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void CountRow() {

		}

		/*概要：文字列をJSONに変換する関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void StringtoJSON() {

		}

		/*概要：箇条書き型のJSONをチェイン構造に変換する関数
		引数：String^：読み込み先のファイルパス
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void ListString(String^ path) {

		}

		/*概要：DBから受け取ったJSONをチェイン構造に変換する関数
		引数：String^：DBから取得したJSON文字列
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void DBString(String^ dbresult) {
			ptree pt;		//JSONを格納するためのツリーを宣言
			//DBより取得したJSON文字列をJSONツリーに変換
			read_json(dbresult, pt);
			//JSONをチェイン構造に変換する関数を呼び出す
			this->JSONString(pt, "", nullptr);
		}

		/*概要：オブジェクト配列の文字列処理を行う関数
		引数：cons ptree&：JSONのツリー
			：CellDataChain::cellchain*：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain* ArrayJSONocject(const boost::property_tree::ptree& info, CellDataChain::cellchain* brother) {
			CellDataChain::cellchain* arrayparent;	//配列の要素を連結するための構造体を宣言
			CellDataChain ChainCtrl;				//データチェインを操作するためにクラスをインスタンス化
			//引数に受け取った構造体の子として配列要素の構造体を連結する
			arrayparent = ChainCtrl.ChainChild(key, "", brother, nullptr);
			//イテレーターにより配列の要素を走査して連結してく
			for (auto itr = info.begin; itr != info.end; itr++) {
				//弟として連結していく
				arrayparent = ChainCtrl.ChainYoungBrother(itr->first, itr->second, arrayparent, nullptr);
			}
			return brother;
		}

		/*概要：配列の文字列処理を行う関数
		引数：ptree：JSONのツリー
			：CellDataChain::cellchain*：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain* ArrayJSON(boost::property_tree::ptree pt, std::string key, ::cellchain* brother) {
			CellDataChain ChainCtrl;				//データチェインを操作するためにクラスをインスタンス化
			//配列を操作する
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)){
				//引数の構造体の弟として配列の要素を連結していく
				brother = ChainCtrl.ChainYoungBrother("", child.first, brother, nullptr);
			}
			return brother;
		}

		/*概要：文字列処理の初回に実行される関数
		引数：ptree：JSONのツリー
		戻り値：CellDataChain::cellchain*：JSONをチェインした構造体
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain* MakeParent(boost::property_tree::ptree pt) {
			auto itr = pt.begin();		//親キーを取得するためのイテレーターを宣言
			std::string key = itr->first;	//初回処理の時はキー名が未知のためイテレーターにより動的に確保
			CellDataChain::cellchain* parent = nullptr;		//最上位の親の構造体を作成
			parent->key = key;								//キー名を設定
			parent->value = (pt.get<std::string>(key));		//ツリー構造にしたJSONの最上位から親キーに対応した値を取得
			//作成した構造体を返す
			return parent;
		}

		/*概要：行数と列数をカウントする関数
		引数：CellDataChain::cellchain*：カウント対象の構造体
			：int：再帰処理の際に利用する変数
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		int CountCell(CellDataChain::cellchain* target, int retcount) {
			CellDataChain::cellchain* scan;		//走査用の構造体を宣言
			//弟方向に操作する
			for (scan = target; scan = nullptr; scan = scan->next) {
				//表に表示すべき要素（親キー以外）があれば
				if (scan->value != "") {
					//行カウントをインクリメント
					*this->rowcount += 1;
					//列カウントをインクリメント
					*this->colcount += 1;
				}
				//子がいる場合は再帰処理していく
				if (scan->lower != nullptr) {
					//2回目以降の再帰であれば
					if (retcount > 0) {
						//再帰した回数に補正をかけながら再帰
						CountCell(scan, retcount - 1);
					}
					else {
						//そのまま再帰する
						CountCell(scan, retcount);
					}
				}
				//2階層以上上がるか最上位階層まで戻ったら
				if (scan->upper == nullptr || retcount >= 2) {
					//メンバの行数をインクリメント
					*this->row += 1;
					//メンバの列数と比較し大きい方を採用
					if (*this->column < *this->colcount) {
						//大きい方を採用する
						this->column = this->colcount;
						//再帰回数をリセットする
						retcount = -1;
						//列数カウントをリセットする
						this->colcount = 0;
					}
				}
				//階層カウントをインクリメントしながら戻る
				return ++retcount;
			}
		}
	};
}