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
		Int32^ rowcount = Constants->ZERO;					//表の行数をカウントするための変数
		Int32^ colcount = Constants->ZERO;					//表の列数をカウントするための変数
		Int32^ RowIndex = Constants->ZERO;					//クリックされた表のタテ座標
		Int32^ ColumnIndex = Constants->ZERO;				//クリックされた表のヨコ座標
		Int32^ RctWidth = 200;								//表の格子一つ当たりの幅
		Int32^ RctHeight = 100;								//表の格子一つ当たりの高さ
		List<int>^ JoinIndex = gcnew List<int>();		//セルの結合情報を保持するリスト型配列
		CellDataChain::cellchain^ TableElem = gcnew CellDataChain::cellchain();					//表の情報が格納されたデータチェイン
		String^ JSONFilePath = Constants->EMPTY_STRING;		//読み込むJSONのファイルパス
		String^ DBQuery = Constants->EMPTY_STRING;			//DBよりJSON文字列を取得するためのクエリ

		/*概要：メンバ変数の情報をもとに表画像を生成する関数
		引数：なし
		戻り値：Bitmap^：生成した表画像
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ TableGenerate(PictureBox^ pict) {
			//チェイン構造操作クラスをインスタンス化
			CellDataChain^ CellCtrl = gcnew CellDataChain();
			//空のビットマップを生成
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
			//描画を行うためのグラフィッククラスをインスタンス化
			Graphics^ gr = Graphics::FromImage(img);
			//表に表示する要素としてオブジェクトがあった場合に色付けを行うためのブラシを生成
			Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Blue));
			//文字列を描画するときの書体を宣言
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//行数についてループ
			for (int i = 0; i < *this->Row; i++) {
				//長方形の大きさを指定
				Rectangle^ rct = gcnew Rectangle(0, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
				//描画対象のデータが連結状態であれば
				if (this->JoinIndex[i] != Constants->ZERO) {
					//表に表示するデータが入った構造体を取得
					CellDataChain::cellchain^ elem = CellCtrl->GetColumnChain(i, JoinIndex[i], this->TableElem->lower);
					//その行を一つの格子で表現する
					gr->DrawRectangle(Pens::Black, *rct);
					//連結時に選択していた格子の文字列を描画する
					gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
				}//結合されていなければそのまま列のループに移る
				else {
					//表に表示するデータが入った構造体を取得
					CellDataChain::cellchain^ elem = CellCtrl->GetRowChain(i, this->TableElem->lower);
					//長方形を描画する
					gr->DrawRectangle(Pens::Black, *rct);
					//表示すべき要素がオブジェクトであれば
					if (elem->lower != nullptr) {
						//子要素を持っていることを明示するために色付けを行う
						gr->FillRectangle(br, *rct);
						//塗りつぶしたうえにキー名を描画する
						gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
					}//データだった場合には
					else {
						//塗りつぶしを行わずに値のみを描画する
						gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
					}
					//行の要素の描画に移行する
					for (int j = 0; j < *this->Column; j++) {
						//表示すべき要素が入った構造体を取得する
						CellDataChain::cellchain^ elem = CellCtrl->GetColumnChain(i, j, this->TableElem->lower);
						//描画する長方形の大きさを設定する
						Rectangle^ rct = gcnew Rectangle(*this->RctWidth*(j + 1), *this->RctHeight*i, *this->RctWidth, *this->RctHeight);
						//格子を作成する
						gr->DrawRectangle(Pens::Black, *rct);
						//表示すべき要素がオブジェクトかデータかを判定する
						if (elem->lower != nullptr) {
							//子要素を持っていることを明示するために色付けを行う
							gr->FillRectangle(br, *rct);
							//塗りつぶしたうえにキー名を描画する
							gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
						}//データばあいは値を表示
						else {
							gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
						}
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
			//背景色を親の色と同化させる
			Pictselect->BackColor = Color::Transparent;
			//処理の終わったピクチャボックスを返す
			return Pictselect;
		}

		/*概要：詳細ダイアログに出力する画像を生成する関数
		引数：PictureBox^：画像を載せるピクチャボックス
		戻り値：PictureBox^：生成した画像を載せたピクチャボックス
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ MoreDetail(PictureBox^ detailtable) {
			CellDataChain::cellchain^ detail = gcnew CellDataChain::cellchain();	//詳細画面に乗せるための構造体
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
			for (CellDataChain::cellchain^ tmp = detail; tmp->lower != nullptr; tmp = tmp->lower) {
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
			option::OptionForm^ opt = gcnew option::OptionForm();
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

		/*概要：表に行を挿入するための関数
		引数：Int32 rowindex：挿入対象の行
			：Int32 column：表全体の列数
		戻り値：なし
		作成日：2017.9.25
		作成者：K.Asada*/
		Void RowAdd(Int32 rowindex, Int32 column) {
			CellDataChain cellctrl;
			//挿入対象の構造体を格納するための構造体
			CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
			//挿入対象の構造体を取得する
			parent = cellctrl.GetRowChain(rowindex, this->TableElem);
			//対象の弟として空の構造体を連結する
			parent = cellctrl.ChainYoungBrother("", "", parent);
			//子として連結する構造体を宣言する
			CellDataChain::cellchain^ child = gcnew CellDataChain::cellchain();
			//子を連結する
			child = cellctrl.ChainChild("", "", parent);
			//孫を連結する
			cellctrl.ChainChild("", "", child);
			//列数と同じだけ子に弟を連結してく
			for (int i = 0; i < column; i++) {
				//弟を連結する
				child = cellctrl.ChainYoungBrother("", "", child);
				//孫を連結する
				cellctrl.ChainChild("", "" , child);
			}
			//行数が増えたのでその分行数をインクリメントする
			*this->Row += 1;
			return;
		}

		/*概要：表に列を追加するための関数
		引数：Int32 row:表全体の行数
			：Int32 columnindex：追加対象の列座標
		戻り値：なし
		作成日：2017.9.25
		作成者：K.Asada*/
		Void ColumnAdd(Int32 row, Int32 columnindex) {
			CellDataChain cellctrl;
			//表の親の構造体を格納するための構造体
			CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
			//列要素に当たる構造体を挿入するための関数
			for (int i = 0; i < row; i++) {
				//行ごとの追加対象の構造体を取得する
				parent = cellctrl.GetColumnChain(row, columnindex, this->TableElem);
				//対象に弟を連結する
				cellctrl.ChainYoungBrother("", "", parent);
			}
		}

		/*概要：表の列数を割り出すための関数
		引数：cellchain^ colchain：カウント対象の構造体
		戻り値：なし
		作成日：2017.9.25
		作成者：K.Asada*/
		Void CountColumn(CellDataChain::cellchain^ colchain) {
			//列要素の構造体を走査して列数をカウントする
			for (; colchain != nullptr; colchain = colchain->next) {
				//列数カウント用のメンバ変数をインクリメント
				*this->colcount += 1;
			}
			return;
		}

		/*概要：表の列数を割り出すための関数
		引数：cellchain^ rowchain：カウント対象の構造体
		戻り値：なし
		作成日：2017.9.25
		作成者：K.Asada*/
		Void CountRow(CellDataChain::cellchain^ rowchain) {
			//行の最後まで走査して行数をカウントする
			for (; rowchain != nullptr; rowchain = rowchain->next) {
				//行の親も列の要素の一つとするために列数カウントをインクリメント
				*this->colcount += 1;
				//行数をインクリメント
				*this->Row += 1;
				//子がいれば再帰して列数のカウントに移る
				if (rowchain->lower != nullptr) {
					//列数をカウントする関数を呼び出す
					this->CountColumn(rowchain->lower);
				}
				//ここまでカウントしてきた列数が既存の列数より大きければ
				if (*this->colcount > *this->Column) {
					//大きい方を採用する
					this->Column = this->colcount;
				}
				//列数カウントをリセットする
				this->colcount = 0;
			}
			return;
		}

		/*概要：詳細編集画面に出力する表画像を生成する関数
		引数：PictureBox^ pict：生成した表画像を載せるピクチャボックス
		戻り値：PictureBox^ pict：必要情報を設定したピクチャボックス
		作成日：2017.9.25
		作成者：K.Asada*/
		PictureBox^ infoTableGenerate(PictureBox^ pict) {
			CellDataChain cellctrl;
			//表画像に表示する要素が含まれた構造体を取得するための空の構造体
			CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
			//対象の構造体のすべての親キーを連結した構造体
			elem = cellctrl.GetParents(this->TableElem);
			//表画像を描画するための空のビットマップを宣言
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column, *this->RctHeight);
			//描画のための関数群クラスをインスタンス化
			Graphics^ gr = Graphics::FromImage(img);
			//文字列を描画するときの書体を宣言
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//取得した構造体に腹案れる親キーをすべて描画する
			for (int i = 0; i < *this->Column; i++) {
				//描画するセル一つ当たりの大きさを設定
				Rectangle^ rct = gcnew Rectangle(*this->RctWidth * i, 0, *this->RctWidth, *this->RctHeight);
				//セルを描画する
				gr->DrawRectangle(Pens::Black, *rct);
				//セルに対応した文字を描画する
				gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
				//次の要素を描画するために構造体の中身を移動させる
				elem = elem->upper;
			}
			//描画した表画像を受け取ったピクチャボックスに渡す
			pict->Image= img;
			//設定の終えたピクチャボックスを返す
			return pict;
		}
	};
}