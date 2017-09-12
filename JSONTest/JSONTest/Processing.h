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
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ retTable = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();
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
				test->ReadyString(this->LoadFilePath);
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
				this->retTable = test->retPointTable;
			}
		}

		/*箇条書き上のJSONを処理するための関数
		作成日：2017.9.12
		作成者：K.Asada*/
		Void Listrun() {
			//ファイルパスを取得していれば
			if (this->LoadFilePath != MyConst->EMPTY_STRING) {
				//JSONより表を出力するために必要な情報を抜き出す関数を呼び出す
				StringProcess^ test = gcnew StringProcess();
				test->ReadyListString(this->LoadFilePath);
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
				this->retTable = test->retPointTable;
			}
		}

		/*受け取った情報よりJSONを出力するための処理
		作成日：2017.9.12
		作成者：K.Asada
		*/
		Void JSONrun() {
			//受け取った文字列リストをもとにJSONに変換する関数を呼び出す
			this->ConversionJSON();
		}


		/*
		Void ConversionTable(vector<pair<string, string>> tmptable) {
			auto itr = tmptable.begin();
			for (auto itr = tmptable.begin(); itr != tmptable.end(); itr++) {
				string test = itr->first;
				string test2 = itr->second;
				this->rettable->push_back(pair<String^, String^>(gcnew String (test.c_str()), gcnew String(test2.c_str())));
			}
		}*/
		
	};
}