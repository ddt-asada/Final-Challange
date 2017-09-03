#pragma once

namespace process {
	using namespace System;

	//作成日：2017.9.2
	//作成者：K.Asada
	//文字列を処理する関数群クラス。
	ref class StringProcess {
	public:
		//デフォルトコンストラクタ
		StringProcess() {
		};

		//ファイルパスより文字列を取得してその文字列から行数、列数、文字列を抜き出す。
		String^ ReadyString(String^ JSONPath) {
			String^ ret = "";
			//受け取ったファイルパスより文字列を取得する関数を呼び出す。
			ret = LoadJSON(JSONPath);
			return ret;
		}

		//ファイルより文字列を取得する関数
		//作成日：2017.9．2
		//作成者：K.Asada
		String^ LoadJSON(String^ Path) {
			//ファイルを開くためのクラスをインスタンス化
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(Path);
			//ファイルに中身が存在するかを確認する。
			if (!reader->EndOfStream) {
				//テスト用。
				System::Windows::Forms::MessageBox::Show(reader->ReadToEnd());
			}
			//読み取れなければエラーを返す。
			else {
				//ファイルの中身が存在していないエラーを表示する。
			}
			return "aaa";
		}
	};
}