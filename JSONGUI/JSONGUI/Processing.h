#pragma once

#include "CellDataChain.h"	//自作のデータチェインクラスのヘッダ
#include "StringProcessing.h"	//文字列処理クラスのヘッダ
#include "JSONDBManager.h"
#include "ConstantString.h"

//内部処理関係の名前空間
namespace process {

	/*概要：内部処理の入り口となるクラス
	作成日：2017.9.21
	作成者：K.Asada*/
	public ref class Processing : public StringProcessing{
	public:
		//デフォルトコンストラクタ
		Processing() {
		}

		/*概要：JSONを読み込んで表にするための文字列処理を行う入り口となる関数
		引数：String^ jsonpath：JSONファイルの読み込み先のファイルパス
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada
		更新日：2017.9.22
		更新者：K.Asada
		更新内容：引数を受け取ってファイルから読み込んだJSONを渡すように変更*/
		Void Tablerun(String^ jsonpath) {
			try {
				//ファイルパスを受け取っていなければファイルを読み込めないので例外を投げる
				if (jsonpath == "") {
					throw gcnew System::IO::FileNotFoundException("ファイルパスが入力されていません\n");
				}
				std::string json = "";		//ファイルから読み込んだJSONを格納する文字列
				//ファイルからJSONを読み込む
				json = this->LoadJSON(jsonpath);
				//文字列処理関数を呼び出す
				this->TableString(json);
				return;
			}
			//ファイルパスが入力されていなければ例外を投げる
			catch(System::IO::FileNotFoundException^ e){
				//コンソールにエラー内容を表示
				Console::WriteLine(e);
			}
		}

		/*概要：JSONを読み込んで箇条書きの表を出力するための文字列処理を行う入り口となる関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada
		更新日：2017.9.22
		更新者：K.Asada
		更新内容：引数を受け取ってファイルから読み込んだJSONを渡すように変更*/
		Void Listrun(String^ jsonpath) {
			try {
				//ファイルパスを受け取っていなければファイルを読み込めないので例外を投げる
				if (jsonpath == "") {
					throw gcnew System::IO::FileNotFoundException("ファイルパスが入力されていません\n");
				}
				std::string json = "";		//ファイルから読み込んだJSONを格納する文字列
				//ファイルからJSONを読み込む
				json = this->LoadJSON(jsonpath);
				//文字列処理関数を呼び出す
				this->ListString(json);
				return;
			}
			//ファイルパスが入力されていなければ例外を投げる
			catch (System::IO::FileNotFoundException^ e) {
				//コンソールにエラー内容を表示
				Console::WriteLine(e);
			}
		}

		/*概要：DBからJSONを読み込んで表を出力するための文字列処理を行う入り口となる関数
		引数：String^：JSONを取得するためにDBに投げるクエリ
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada
		更新日：2017.9.22
		更新者：K.Asada
		更新内容：引数を受け取ってファイルから読み込んだJSONを渡すように変更*/
		Void DBrun(String^ DBquery) {
			try {
				//クエリが未入力なら例外を投げる
				if (DBquery == "") {
					throw gcnew System::IO::FileNotFoundException("クエリが未入力です。\n");
				}
				string result = "";		//DBから取得したJSON文字列を格納するための文字列
				string query = "";		//DBへ渡すクエリを格納する文字列
			//	JSONDBManager db;				//DBとの通信を行うクラスをインスタンス化
				//メイン画面より受け取ったクエリの型変換を行う
				this->MarshalString(DBquery, query);
				//DBからJSON文字列を取得する
			//	result = db.GetDBResult(query);
				//文字列処理関数を呼び出す
				this->DBString(result);
				//戻り値なし
				return;
			}
			//ファイルパスが入力されていなければ例外を投げる
			catch (System::IO::FileNotFoundException^ e) {
				//コンソールにエラー内容を表示
				Console::WriteLine(e);
			}
		}

		/*概要：文字列からJSONへの変換を行う入り口となる関数
		引数：String^：変換したJSONファイルの出力先
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void Convertrun(String^ jsonpath, CellDataChain::cellchain^ jsonelem) {
			try {
				//保存先ファイルパスが未入力であれば例外処理
				if (jsonpath == "") {
					//例外を投げる
					throw gcnew System::IO::FileNotFoundException("保存先ファイルパスが入力されていません。\n");
				}
				ptree json;		//文字列から作成したJSONツリーを格納するためのツリー
				string path = "";	//ファイルパスをstring型に変換したものを格納するための文字列
				//ファイルパスをstring型に変換する
				this->MarshalString(jsonpath, path);
				//文字列からJSONツリーを作成する
				json = this->ConvertJSON("", jsonelem);
				//作成したJSONツリーをファイルに出力する
				write_json(path, json);
				//戻り値なし
				return;
			}
			//ファイルパスが入力されていなければ例外を投げる
			catch (System::IO::FileNotFoundException^ e) {
				//コンソールにエラー内容を表示
				Console::WriteLine(e);
			}
		}

		/*概要：ファイルから文字列を取得するための関数
		引数：String^：読み込み先のファイルパス
		戻り値：String^；読み込んだ文字列
		作成日：207.9.21
		作成者：K.Asada*/
		std::string LoadJSON(String^ jsonpath) {
			//ファイル読み込み関係の例外を捕捉
			try {
				CONSTANTS::ConstantString^ Constants = gcnew CONSTANTS::ConstantString();
				std::string path = "";		//String^型からstring型へ変換したファイルパスを格納する文字列
				//型変換を行う
				this->MarshalString(jsonpath, path);
				//ファイルを読み込む準備
				std::ifstream ifs(path);
				//ファイルの読み込みに失敗した時の例外処理
				if (ifs.fail()) {
					//例外を送出する
					throw gcnew System::IO::FileNotFoundException(Constants->LOAD_ERROR_STRING);
				}
				//ファイルよりJSONを取得する
				std::string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
				return json;
			}
			//ファイル読み込みエラーを捕捉
			catch (System::IO::FileNotFoundException^ e) {
				//コンソールに詳細内容を表示
				Console::WriteLine(e);
			}
		}
	};
}