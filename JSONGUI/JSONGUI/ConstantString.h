#pragma once

namespace CONSTANTS {

	/*概要：定数クラス
	作成日：2017.9.20
	作成者：K.Asada*/
	public ref class ConstantString {
	public:
		ConstantString() {
		}

		//汎用的に利用する空文字
		System::String^ EMPTY_STRING = "";
		//0を示す文字列
		System::String^ ZERO_STRING = "0";
		//エラーが発生した時にユーザー側に表示するメッセージ
		System::String^ MESSAGE_STRING = "エラーが発生しました。処理を中断します。";
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
		//キー名が空の時に描画する配列であることを示す文字列
		System::String^ ARRAY_STRING = "配列";
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