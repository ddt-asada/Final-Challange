#pragma once

#include "CONSTANTSTRING.h"//定数クラスを扱うためのインクルード
#include "StringProcess.h"//文字列処理クラスのインクルード

/*作成日：2017.9.2
　入力された情報を処理するクラス
 　作成者：K.Asada
  */

namespace process {
	using namespace System;

	ref class Processing {
	private:
		//定数クラスをインスタンス化
		constantstring::CONSTANTSTRING^ CONST = gcnew constantstring::CONSTANTSTRING();
		String^ LoadFilePath = CONST->EMPTY_STRING;	//JSONファイルを読み込む先のファイルパスを格納する文字列。
		String^ SendQuery = CONST->EMPTY_STRING;	//DBへ投げるクエリを格納する文字列。
		String^ DbJson = CONST->EMPTY_STRING;		//DBより取得した文字列を格納する文字列。
		Int32^ Row = CONST->ZERO;					//表の行数を格納する変数
		Int32^ Column = CONST->ZERO;				//表の列数を格納する変数

	public:
		//デフォルトコンストラクタ
		Processing() {
			
		};
		//受け取った情報を保管するコンストラクタ。
		Processing(String^ Path, String^ Query) :LoadFilePath(CONST->EMPTY_STRING), SendQuery(CONST->EMPTY_STRING) {
			this->LoadFilePath = Path;
			this->SendQuery = Query;
		};

		/*受け取った情報より表を出力するための処理
		　作成日：2017.9.2
		 　作成者：K.Asada
		  */
		Void run() {
			//ファイルパスを取得していれば
			if (this->LoadFilePath != CONST->EMPTY_STRING) {
				//JSONより表を出力するために必要な情報を抜き出す関数を呼び出す
				StringProcess^ test = gcnew StringProcess();
				test->ReadyString(this->LoadFilePath);
				//JSONより取得した行数とメンバ変数の行数を比較する。
				//JSONより取得した列数とメンバ変数の列数を比較する。
			}

			//表を出力する関数を呼び出す。
		}

	};
}