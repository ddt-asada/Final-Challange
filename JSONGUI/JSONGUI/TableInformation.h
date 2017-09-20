#pragma once
#include "ConstantString.h"		//自作定数クラスのヘッダ
#include <list>

namespace TableInformation {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace CONSTANTS;		//自作定数クラス名前空間

	/*概要：メイン画面に出力される表画像関連の関数をまとめた基底クラス
	作成日：2017.9.20
	作成者：K.Asada
	*/
	public ref class TableInformation : public System::Windows::Forms::Form {
	public:
		//デフォルトコンストラクタ
		TableInformation() {
		}

	//	ConstantString^ Constants = gcnew ConstantString();		//定数クラスのインスタンス化
		Int32^ Row = Constants->ZERO;			//表の行数
		Int32^ Column = Constants->ZERO;		//表の列数
		Int32^ RowIndex = Constants->ZERO;		//クリックされた表のタテ座標
		Int32^ ColumnIndex = Constants->ZERO;	//クリックされた表のヨコ座標
		Int32^ RctWidth = 200;					//表の格子一つ当たりの幅
		Int32^ RctHeight = 100;					//表の格子一つ当たりの高さ
	//	List<Int32>^ = gcnew List<Int32>();		//セルの結合情報を保持するリスト型配列
		//cellchain* TableElem = NULL;			//表の情報が格納されたデータチェイン
		String^ JSONFilePath = Constants->EMPTY_STRING;		//読み込むJSONのファイルパス
		String^ DBQuery = Constants->EMPTY_STRING;			//DBよりJSON文字列を取得するためのクエリ
	};
}