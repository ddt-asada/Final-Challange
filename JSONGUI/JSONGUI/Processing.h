#pragma once

#include "CellDataChain.h"	//自作のデータチェインクラスのヘッダ
#include "StringProcessing.h"	//文字列処理クラスのヘッダ

//内部処理関係の名前空間
namespace process {

	using namespace System;
	/*概要：内部処理の入り口となるクラス
	作成日：2017.9.21
	作成者：K.Asada*/
	public ref class Processing : public StringProcessing{
	public:
		//デフォルトコンストラクタ
		Processing() {
		}

		//ファイルを読み込んで処理するためのコンストラクタ
		Processing(System::String^ path) {

		}

		/*概要：JSONを読み込んで表にするための文字列処理を行う入り口となる関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void Tablerun(String^ path) {
		}

		/*概要：JSONを読み込んで箇条書きの表を出力するための文字列処理を行う入り口となる関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void Listrun(String^ path) {
		}

		/*概要：DBからJSONを読み込んで表を出力するための文字列処理を行う入り口となる関数
		引数：String^：JSONを取得するためにDBに投げるクエリ
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void DBrun(String^ query) {

		}

		/*概要：文字列からJSONへの変換を行う入り口となる関数
		引数：String^：JSONに変換したい文字列
			：cellchain*：表から取得した文字列のデータチェイン
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void Convertrun(String^ stringJSON, CellDataChain::cellchain* table) {
			
		}

	};
}