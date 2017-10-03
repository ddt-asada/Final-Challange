#pragma once

namespace CONSTANTS {

	/*概要：定数クラス
	作成日：2017.9.20
	作成者：K.Asada*/
	static public ref class ConstantString {
	public:
		ConstantString() {
		}

		//汎用的に利用する空文字
		System::String^ EMPTY_STRING = "";
		//0を示す文字列
		System::String^ ZERO_STRING = "0";
		//エラーが発生した時にユーザー側に表示するメッセージ
		System::String^ MESSAGE_STRING = "エラーが発生しました。処理を中断します。\nエラー内容はコンソールをご確認ください。";
		//メイン画面の展開ボタンがクリックされたときに展開しなかったときに表示するメッセージ
		System::String^ EXPANSION_STRING = "展開すべき情報がありません。";
		//入力内容がおかしいことを表示するメッセージ
		System::String^ INPUT_ERROR_STRING = "入力情報を確認してください。\n";
		//画像の描画に失敗した時に表示するメッセージ
		System::String^ IMAGE_ERROR_STRING = "画像の描画に失敗しました。\n";
		//描画対象が存在していないことを表示するメッセージ
		System::String^ DRAW_ERROR_STRING = "描画対象が不正です。\n";
		//描画するセルの大きさがオーバーフロウしたときのメッセージ
		System::String^ RECT_ERROR_STRING = "描画するセルが大きすぎます。\n";
		//ファイル読み込みエラー発生時に表示するメッセージ
		System::String^ LOAD_ERROR_STRING = "ファイル読み込みエラー。\n";
		//変換成功時に表示するメッセージ
		System::String^ SUCCES_STRING = "JSONファイルの出力が完了しました。";
		//操作を中断した時に表示するメッセージ
		System::String^ CANCEL_STRING = "操作が中断されました";
		//JSONファイルを読み込んだことを表示するメッセージ
		System::String^ LOAD_STRING = "JSONファイルの読み込みが完了しました。";
		//新規で表を生成するときの案内メッセージ
		System::String^ NEW_STRING = "新規でJSONを作成します。\n最上位となるキー名を入力してください。";
		//表の生成に成功したことを表示するメッセージ
		System::String^ TABLE_STRING = "表が生成されました。";
		//DBとの通信を行ったことを表示するメッセージ
		System::String^ DB_STRING = "DBとの通信結果より表を出力しました。";
		//表に関わるデータが初期化されたことを表示するメッセージ
		System::String^ INITIAL_STRING = "初期化されました。";
		//行・列を追加するときに先頭より先には追加できないことを表示するメッセージ
		System::String^ ADD_ERROR_STRING = "先頭より先には追加できません。";
		//キー名が空の時に描画する配列であることを示す文字列
		System::String^ ARRAY_STRING = "配列";
		//右を示す文字列
		System::String^ RIGHT_STRING = "右";
		//左を示す文字列
		System::String^ LEFT_STRING = "左";
		//上を示す文字列
		System::String^ TOP_STRING = "上";
		//下を示す文字列
		System::String^ UNDER_STRING = "下";
		//自分より上位であることを示すボタンの名前
		System::String^ ELDER_BUTTON_STRING = "ElderButton";
		//自分より下位であることを示すボタンの名前
		System::String^ YOUNG_BUTTON_STRING = "YoungButton";
		//キャンセルボタンの名前
		System::String^ CANCEL_BUTTON_STRING = "CancelButton";
		//構造体を新規で作成するときの初期値となるキー名
		System::String^ CHAIN_KEY_STRING = "";
		//構造体を新規で作成するときの初期値となる値
		System::String^ CHAIN_VALUE_STRING = "";
		//汎用エラー文字列
		System::String^ ERROR_STRING = "エラー";
		//メイン画面の行数テキストボックスの中身の初期値
		System::String^ INITIAL_ROW_STRING = "0";
		//メイン画面の列数テキストボックスの中身の初期値
		System::String^ INITIAL_COLUMN_STRING = "0";
		//0を示す変数
		System::Int32 ZERO = 0;
	};
}