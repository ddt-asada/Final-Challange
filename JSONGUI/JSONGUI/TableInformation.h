#pragma once
#include "OptionForm.h"			//設定画面クラスのヘッダ
#include "ConstantString.h"		//自作定数クラスのヘッダ
#include "CellDataChain.h"		//自作データチェインクラスのヘッダ
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
		};

		ConstantString^ Constants = gcnew ConstantString();	//定数クラスのインスタンス化
		Int32^ Row = Constants->ZERO;						//表の行数
		Int32^ Column = Constants->ZERO;					//表の列数
		Int32^ RowIndex = Constants->ZERO;					//クリックされた表のタテ座標
		Int32^ ColumnIndex = Constants->ZERO;				//クリックされた表のヨコ座標
		Int32^ RctWidth = 200;								//表の格子一つ当たりの幅
		Int32^ RctHeight = 100;								//表の格子一つ当たりの高さ
		List<Int32>^ JoinIndex = gcnew List<Int32>();		//セルの結合情報を保持するリスト型配列
		CellDataChain::cellchain* TableElem = NULL;					//表の情報が格納されたデータチェイン
		String^ JSONFilePath = Constants->EMPTY_STRING;		//読み込むJSONのファイルパス
		String^ DBQuery = Constants->EMPTY_STRING;			//DBよりJSON文字列を取得するためのクエリ

		/*概要：メンバ変数の情報をもとに表画像を生成する関数
		引数：なし
		戻り値：Bitmap^：生成した表画像
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ TableGenerate(PictureBox^ pict) {
			//チェイン構造操作クラスをインスタンス化
			CellDataChain* CellCtrl = new CellDataChain();
			//空のビットマップを生成
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
			//描画を行うためのグラフィッククラスをインスタンス化
			Graphics^ gr = Graphics::FromImage(img);
			//文字列を描画するときの書体を宣言
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//行数についてループ
			for (int i = 0; i < *this->Row; i++) {
				//描画対象のデータが連結状態であれば
				if (this->JoinIndex[i] != Constants->ZERO) {
					//その行を一つの格子で表現する
					gr->DrawRectangle(Pens::Black, 0, *this->RctHeight * i, *this->RctWidth * *this->Column, *this->RctHeight);
					//連結時に選択していた格子の文字列を描画する
					gr->DrawString(gcnew String(CellCtrl->GetChainData(*this->RowIndex, *this->ColumnIndex, this->TableElem)), myFont, Brushes::Black, *this->RctWidth * *this->Column / 2, *this->RctHeight* i);
				}//結合されていなければそのまま列のループに移る
				else {
					for (int j = 0; j < *this->Column; j++) {
						//格子を作成する
						gr->DrawRectangle(Pens::Black, *this->RctWidth * j, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
						//連結時に選択していた格子の文字列を描画する
						gr->DrawString(gcnew String(CellCtrl->GetChainData(*this->RowIndex, *this->ColumnIndex, this->TableElem)), myFont, Brushes::Black, *this->RctWidth * j, *this->RctHeight * i);
					}
				}
			}
			//作成した画像をピクチャボックスへのセル
			pict->Image = img;
			//作成の終えたビットマップ画像を返す
			return pict;
		}

		/*概要：選択箇所のセルをハイライトする関数
		引数：PictureBox^：画像を載せるコントロール
		戻り値；PictureBox^：画像を載せたコントロール
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ SelecteCell(PictureBox^ Pictselect) {
			//半透明色の塗りつぶし用ブラシを作成
			Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Yellow));
			//画像データを生成する
			Bitmap^ img = gcnew Bitmap(*this->RctWidth + 1, *this->RctHeight + 1);
			//描画用のグラフィッククラスをインスタンス化
			Graphics^ gr = Graphics::FromImage(img);
			//選択したセルが結合状態であれば
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//画像を載せる位置を設定する
				Pictselect->Location = System::Drawing::Point(0, *this->RctHeight * *this->RowIndex);
				//画像のサイズを設定する
				Pictselect->Size = System::Drawing::Size(*this->RctWidth * *this->Column, *this->RctHeight);
				//ハイライト用の半透明色塗りつぶし画像を描画
				gr->FillRectangle(br, 0, 0, *this->RctWidth * *this->Column - 1, *this->RctHeight - 1);
			}//結合状態でなければ
			else {
				//画像を載せる位置を設定する
				Pictselect->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//画像のサイズを設定
				Pictselect->Size = System::Drawing::Size(*this->RctWidth, *this->RctHeight);
				//ハイライト用の塗りつぶし画像を描画
				gr->FillRectangle(br, 0, 0, *this->RctWidth - 1, *this->RctHeight - 1);
			}
			//描画の終わった画像をピクチャボックスのコントロールに乗せる
			Pictselect->Image = img;
			//処理の終わったピクチャボックスを返す
			return Pictselect;
		}

		/*概要：詳細ダイアログに出力する画像を生成する関数
		引数：PictureBox^：画像を載せるピクチャボックス
		戻り値：PictureBox^：生成した画像を載せたピクチャボックス
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ MoreDetail(PictureBox^ detailtable) {
			CellDataChain::cellchain* detail;	//詳細画面に乗せるための構造体
			//チェイン構造操作クラスをインスタンス化
			CellDataChain CellCtrl;
			//描画用のビットマップを生成
			Bitmap^ img = gcnew Bitmap(*this->RctWidth, *this->RctHeight * *this->Row);
			//文字列を描画するときの書体を宣言
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//選択箇所の構造体を取得する
			//detail = CellCtrl.GetChainData(*this->RowIndex, *this->ColumnIndex, this->TableElem);
			//構造体の選択箇所の親キーをすべて連結する関数を呼び出す
			//detail = CellCtrl.GetChainParent(detail);
			//構造体の中身がなくなるまでループ
			for (CellDataChain::cellchain* tmp = detail; tmp->lower != nullptr; tmp = tmp->lower) {
				//グラフィッククラスをインスタンス化
				Graphics^ gr = Graphics::FromImage(img);
				//セルを描画する
				//gr->DrawRectangle(Pens::Black, *this->RctWidth, *this->RctHeight);
				//文字を描画する
				//gr->DrawString(tmp->key, myFont, Brushes::Black);
			}
			//生成した画像をピクチャボックスに反映する
			detailtable->Image = img;
			//ピクチャボックスを返す
			return detailtable;
		}

		/*概要：選択箇所を結合/解除する関数
		引数：なし
		戻り値：なし
		作成日：2017.9.20
		作成者：K.Asada*/
		Void JoinRelease() {
			//すでに結合状態であれば
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//結合状態を解除する
				this->JoinIndex[*this->RowIndex] = Constants->ZERO;
			}//結合状態でなければ
			else {
				//結合状態にする
				this->JoinIndex[*this->RowIndex] = Constants->ZERO;
			}
		}

		/*概要：クリックされたセルの座標を取得する関数
		引数：System::Windows::Forms::MouseEventArgs^：マウスのイベントの変数が格納されたクラス
		戻り値：なし
		作成日：2017.9.20
		作成者：K.Asada*/
		Void GetCellPoint(System::Windows::Forms::MouseEventArgs^ e) {
			//マウスイベントクラスよりクリックしたときのマウスのY座標を取得する
			this->RowIndex = e->Location.Y / *this->RctHeight;
			//クリックした行が結合状態であれば
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//行のどこをクリックしても常に結合している座標を取得
				this->ColumnIndex = this->JoinIndex[*this->RowIndex];
			}//結合状態でなければ
			else {
				//そのままの座標を取得
				this->ColumnIndex = e->Location.X / *this->RctWidth;
			}
		}

		/*概要：表画像の一部を再描画する関数
		引数：PitcutreBox^：表画像が載せられたピクチャボックス
		戻り値：PictureBox^：表画像の一部を再描画したものをのせたピクチャボックス
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ ReTableGenerate(PictureBox^ repict) {
			CellDataChain CellCtrl;
			//描画の対象をすでに生成されている表画像にしてグラフィッククラスをインスタンス化
			Graphics^ gr = Graphics::FromImage(repict->Image);
			//塗りつぶし用のブラシを作成
			Brush^ br = gcnew SolidBrush(Color::FromArgb(255, Color::White));
			//白で上書きするためにセルの大きさと同じ塗りつぶし長方形を描画
			gr->FillRectangle(br, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
			//白で塗りつぶしたときに枠線が消えるため再描画する
			gr->DrawRectangle(Pens::Black, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
			//文字が消えているため再描画する
			//gr->DrawString(CellCtrl.GetChainData(*this->RowIndex, *this->ColumnIndex), myFont, Brushes::Black, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
			//再描画の終えたピクチャボックスを返す
			return repict;
		}

		/*概要：クリックされたセルに編集用のテキストボックスを配置する関数
		引数：配置するテキストボックス
		戻り値：テキストボックスに位置情報や文字列情報を格納したもの
		作成日：2017.9.20
		作成者：K.Asada*/
		TextBox^ CellTextGenerate(TextBox^ cell) {
			CellDataChain CellCtrl;
			//結合状態であれば
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//結合状態のため座標をその行の左上に合わせる
				cell->Location = System::Drawing::Point(0, *this->RctHeight * *this->RowIndex);
				//結合状態のため、サイズをその行全体の大きさに合わせる
				cell->Size = System::Drawing::Size(*this->RctWidth * *this->Column, *this->RctHeight);
			}//結合状態でなければ
			else {
				//座標を選択中のセルの左上に合わせる
				cell->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//サイズをセル一つ当たりの大きさに合わせる
				cell->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
			}
			//テキストボックスに元の表画像にあった文字列を載せる
//			cell->Text = CellCtrl.GetChainData(*this->RowIndex, *this->ColumnIndex);
			//テキストボックスが後ろに隠れて見えないことがあるので明示的に前に配置
			cell->BringToFront();
			//加工を終えたテキストボックスを返す
			return cell;
		}

		/*概要：このクラスのメンバ変数を初期化する関数
		引数：なし
		戻り値：なし
		作成日：2017.9.20
		作成者：K.Asada*/
		Void InfoInit() {
			this->Row = Constants->ZERO;				//行数を初期化する
			this->Column = Constants->ZERO;				//列数を初期化する
			this->RctWidth = 200;						//セル一つ当たりの幅を初期化する
			this->RctHeight = 100;						//セル一つ当たりの高さを初期化する
			this->JoinIndex->Clear();					//結合情報を初期化する
			this->JSONFilePath = Constants->EMPTY_STRING;//読み込み先のファイルパスを初期化する
			this->DBQuery = Constants->EMPTY_STRING;	//DBへ投げるクエリを初期化する
		}

		/*概要：設定画面を開くための関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void ShowOptionForm() {
			//設定画面を開くために設定画面クラスをインスタンス化
			OptionForm^ opt = gcnew OptionForm();
			//前回呼び出し時のデータが設定画面のテキストボックスに格納されるように渡す
			opt->FilePath = this->JSONFilePath;
			//前回呼び出し時のデータが設定画面のテキストボックスに格納されるように渡す
			opt->SendQuery = this->DBQuery;
			//設定画面を開く
			opt->ShowDialog();
			//設定画面にて取得したJSONファイルパスを取得する
			this->JSONFilePath = opt->FilePath;
			//設定画面にて取得したDBクエリを取得する
			this->DBQuery = opt->SendQuery;
		}
	};
}