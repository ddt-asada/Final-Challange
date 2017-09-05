#pragma once

#include "CONSTANTSTRING.h"//定数クラスを扱うためのインクルード
#include "StringProcess.h"//文字列処理クラスのインクルード
#include "JSONForm.h"

/*作成日：2017.9.2
　入力された情報を処理するクラス
 　作成者：K.Asada
  */

namespace process {
	using namespace System;
	using namespace System::Windows::Forms;

	ref class Processing : public StringProcess{
	public:
		//定数クラスをインスタンス化
		constantstring::CONSTANTSTRING^ MyConst = gcnew constantstring::CONSTANTSTRING();
		String^ LoadFilePath = MyConst->EMPTY_STRING;	//JSONファイルを読み込む先のファイルパスを格納する文字列。
		String^ SendQuery = MyConst->EMPTY_STRING;	//DBへ投げるクエリを格納する文字列。
		String^ DbJson = MyConst->EMPTY_STRING;		//DBより取得した文字列を格納する文字列。
		Int32^ Row = *MyConst->ZERO;					//表の行数を格納する変数
		Int32^ Column = *MyConst->ZERO;				//表の列数を格納する変数
		vector<pair<string, string>>* rettable = new vector<pair<string, string>>();

	public:
		//デフォルトコンストラクタ
		Processing() {
			
		};
		//受け取った情報を保管するコンストラクタ。
		Processing(String^ Path, String^ Query) :LoadFilePath(MyConst->EMPTY_STRING), SendQuery(MyConst->EMPTY_STRING) {
			this->LoadFilePath = Path;
			this->SendQuery = Query;
		};

		/*受け取った情報より表を出力するための処理
		　作成日：2017.9.2
		 　作成者：K.Asada
		  */
		Void run() {
			//ファイルパスを取得していれば
			if (this->LoadFilePath != MyConst->EMPTY_STRING) {
				//JSONより表を出力するために必要な情報を抜き出す関数を呼び出す
				StringProcess^ test = gcnew StringProcess();
				this->rettable = test->ReadyString(this->LoadFilePath);
				//JSONより取得した行数とメンバ変数の行数を比較する。
				if (*this->Row < *test->row) {
					//大きい方を採用する。
					this->Row = test->row;
				}
				//JSONより取得した列数とメンバ変数の列数を比較する。
				if (*this->Column < *test->column) {
					//大きい方を採用する
					this->Column = test->column;
				}
			}
			//表を出力する関数を呼び出す。
		}
	};
}