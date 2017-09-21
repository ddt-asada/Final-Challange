#pragma once

#include "CellDataChain.h"	//自作データチェインクラス
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

namespace process {

	using namespace System;

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
		List<Int32>^ joinInfo = gcnew List<Int32>();	//結合情報を保持する動的配列
		
		/*概要：JSONを表に必要な文字列に変換する関数
		引数：String^：DBから取得したJSONまたはファイルからJSONを読み込むためのファイルパス
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void TableString(String^ json) {

		}

		/*概要：ファイルから文字列を取得するための関数
		引数：String^：読み込み先のファイルパス
		戻り値：String^；読み込んだ文字列
		作成日：207.9.21
		作成者：K.Asada*/
		String^ LoadJSON(String^ path) {

		}

		/*概要：JSONをチェイン構造文字列に変換する関数
		引数：ptree：JSONをツリー構造にしたもの
			：string：キー名
		戻り値：なし
		作成日」2017.9.21
		作成者：K.Asada*/
		Void JSONString(boost::property_tree::ptree pt, std::string key) {

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

		}

		/*概要：オブジェクト配列の文字列処理を行う関数
		引数：cons ptree&：JSONのツリー
			：CellDataChain::cellchain*：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain* ArrayJSONocject(const boost::property_tree::ptree& info, CellDataChain::cellchain* brother) {
			
		}

		/*概要：配列の文字列処理を行う関数
		引数：ptree：JSONのツリー
			：CellDataChain::cellchain*：JSONをチェインした構造体
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain* ArrayJSON(boost::property_tree::ptree pt, CellDataChain::cellchain* brother) {

		}

		/*概要：文字列処理の初回に実行される関数
		引数：ptree：JSONのツリー
		戻り値：CellDataChain::cellchain*：JSONをチェインした構造体
		作成日：2017.9.21
		作成者：K.Asada*/
		CellDataChain::cellchain* MakeParent(boost::property_tree::ptree pt) {
			
		}

		/*概要：行数と列数をカウントする関数
		引数：CellDataChain::cellchain*：カウント対象の構造体
			：int：再帰処理の際に利用する変数
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void CountCell(CellDataChain::cellchain* target, int tmp) {

		}
	};
}