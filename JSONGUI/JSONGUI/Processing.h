#pragma once

#include "CellDataChain.h"	//自作のデータチェインクラスのヘッダ
#include "StringProcessing.h"	//文字列処理クラスのヘッダ
#include "JSONDBManager.h"

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
			std::string json = "";		//ファイルから読み込んだJSONを格納する文字列
			//ファイルからJSONを読み込む
			json = this->LoadJSON(jsonpath);
			//文字列処理関数を呼び出す
			this->TableString(json);

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
			std::string json = "";		//ファイルから読み込んだJSONを格納する文字列
			//ファイルからJSONを読み込む
			json = this->LoadJSON(jsonpath);
			//文字列処理関数を呼び出す
			this->ListString(json);
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
			string result = "";		//DBから取得したJSON文字列を格納するための文字列
			string query = "";		//DBへ渡すクエリを格納する文字列
			JSONDBManager db;				//DBとの通信を行うクラスをインスタンス化
			//メイン画面より受け取ったクエリの型変換を行う
			this->MarshalString(DBquery, query);
			//DBからJSON文字列を取得する
			result = db.GetDBResult(query);
			//文字列処理関数を呼び出す
			this->DBString(result);
			//戻り値なし
			return;
		}

		/*概要：文字列からJSONへの変換を行う入り口となる関数
		引数：String^：変換したJSONファイルの出力先
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void Convertrun(String^ jsonpath, CellDataChain::cellchain^ jsonelem) {
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

		/*概要：ファイルから文字列を取得するための関数
		引数：String^：読み込み先のファイルパス
		戻り値：String^；読み込んだ文字列
		作成日：207.9.21
		作成者：K.Asada*/
		std::string LoadJSON(String^ jsonpath) {
			//ファイル読み込みエラーを送出する例外処理
			try {
				//読み込んんだJSONを格納するための文字列
				std::string json = "";
				//ストリームリーダーよりUTF-8に指定してファイルを読み込む
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(jsonpath, System::Text::Encoding::GetEncoding("utf-8"));
				//読み込んだJSONをstringに変換する
				this->MarshalString(sr->ReadToEnd(), json);
				//読み込んだJSONを返す
				return json;
			}
			//ファイルの読み込みに失敗したらcatch
			catch (System::IO::FileNotFoundException^ e) {
				//ファイルの読み込みエラー内容をコンソールに出力
				Console::WriteLine(e);
			}
		}
	};
}