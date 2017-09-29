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
		CellDataChain::cellchain^ TableElem = nullptr;					//表の情報が格納されたデータチェイン
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
			//行数についてループ
			for (int i = 0; i < *this->Row; i++) {
				//描画対象のデータが連結状態であれば
				if (this->JoinIndex[i] != Constants->ZERO) {
					//表に表示するデータが入った構造体を取得
					CellDataChain::cellchain^ elem = CellCtrl->GetColumnChain(i, JoinIndex[i], this->TableElem->lower);
					//描画するセルの情報を設定する
					System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * *this->Column, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
					//セルを描画する関数を呼び出す
					this->DrawFigure(*rct, gr, elem);
				}//結合されていなければそのまま列のループに移る
				else {
					//行の要素の描画に移行する
					for (int j = 0; j < *this->Column; j++) {
						//表示すべき要素が入った構造体を取得する
						CellDataChain::cellchain^ elem = CellCtrl->GetColumnChain(i, j, this->TableElem->lower);
						//描画する長方形の大きさを設定する
						System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth*j, *this->RctHeight*i, *this->RctWidth, *this->RctHeight);
						//セルを描画する関数を呼び出す
						this->DrawFigure(*rct, gr, elem);
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
			//構造体の中身がなくなるまでループ
			for (CellDataChain::cellchain^ tmp = detail; tmp->lower != nullptr; tmp = tmp->lower) {
				//グラフィッククラスをインスタンス化
				Graphics^ gr = Graphics::FromImage(img);
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
			//描画の対象をすでに生成されている表画像にしてグラフィッククラスをインスタンス化
			Graphics^ gr = Graphics::FromImage(repict->Image);
			//塗りつぶし用のブラシを作成する
			Brush^ br = gcnew SolidBrush(Color::FromArgb(255, Color::White));
			//構造体操作クラスをインスタンス化
			CellDataChain^ CellCtrl = gcnew CellDataChain();
			//要素が格納された構造体を取得する
			CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
			//描画するセルを設定する
			System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
			//描画する要素が書くのされた構造体を取得する
			elem = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
			//白で上書きするためにセルの大きさと同じ塗りつぶし長方形を描画
			gr->FillRectangle(br, *rct);
			//セルを描画する関数を呼び出す
			this->DrawFigure(*rct, gr, elem);
			//再描画の終えたピクチャボックスを返す
			return repict;
		}

		/*概要：クリックされたセルに編集用のテキストボックスを配置する関数
		引数：配置するテキストボックス
		戻り値：テキストボックスに位置情報や文字列情報を格納したもの
		作成日：2017.9.20
		作成者：K.Asada*/
		TextBox^ CellTextGenerate(TextBox^ cell) {
			//nullptrを指したときの例外処理
			try {
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
				//構造体を操作するためのクラスをインスタンス化
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//要素が入った構造体を格納するための構造体を宣言
				CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
				//対象の構造体を取得する
				elem = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
				//構造体がオブジェクトかどうかを判定する
				if (elem != nullptr && elem->lower != nullptr) {
					//テキストボックスに対象の構造体のキー名を載せる
					cell->Text = elem->key;
				}
				else if (elem != nullptr) {
					//データの場合は値を載せる
					cell->Text = elem->value;
				}
				else {
					//構造体が取得できていない場合は空文字を挿入する
					cell->Text = "";
				}
				//加工を終えたテキストボックスを返す
				return cell;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
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
		引数：String^ select：挿入方向を示す文字列
		戻り値：なし
		作成日：2017.9.25
		作成者：K.Asada
		更新内容：引数として行を与えるだけで動作するように変更、追加対象を兄弟だけに変更
		更新日：2017.9.27
		更新者：K.Asasda
		更新内容：挿入方向を指定するように変更
		更新日：2017.9.28
		更新者：K.Asada
		*/
		Void RowAdd(Int32 rowindex, String^ select) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//挿入対象の構造体を格納するための構造体
				CellDataChain::cellchain^ parent = nullptr;
				//挿入対象の構造体を取得する
				parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
				//行の挿入方向が上に指定されていたら
				if (select == "ElderButton") {
					//上方向に行を追加する
					CellCtrl->ChainElderBrother("", "", parent);
				}//行の挿入方向を下に指定する
				else {
					//下方向に行を追加する
					parent = CellCtrl->ChainYoungBrother("", "", parent);
				}
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*概要：表に列を追加するための関数
		引数：Int32 row:表全体の行数
			：Int32 columnindex：追加対象の列座標
		戻り値：なし
		作成日：2017.9.25
		作成者：K.Asada
		更新内容：追加対象の構造体が取得できなかったときはその行の一番弟の構造体に一つ弟を追加するように変更
		更新日：2017.9.27
		更新者：K.Asada
		更新内容：列を追加する方向を指定するように変更
		更新日：2017.9.28
		更新者：K.Asada*/
		Void ColumnAdd(Int32 row, Int32 columnindex, String^ select) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//表の親の構造体を格納するための構造体
				CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
				//列要素に当たる構造体を挿入するための関数
				for (int i = 0; i < row; i++) {
					//列座標が0より下の時は行の先頭を選択しているとするための分岐
					if (columnindex > 0) {
						//行ごとの追加対象の構造体を取得する
						parent = CellCtrl->GetColumnChain(i, columnindex, this->TableElem->lower);
						//対象の構造体が取得できなかったときはその行の先頭の構造体を取得する
						if (parent == nullptr) {
							//新規で列方向に構造体を連結するための関数を呼び出す
							this->AddYoungColumn(i);
						}//対象を取得できた場合はどの方向に追加するかを判定する
						else {
							//追加方向に左（自分より上）が指定されていたら
							if (select == "ElderButton") {
								//新規で兄を連結する関数を呼び出す
								CellCtrl->ChainElderBrother("", "", parent);
							}
							else {
								//対象に弟を連結する
								CellCtrl->ChainYoungBrother("", "", parent);
							}
						}
					}//行を選択している場合は行の直下の子供を追加するようにする
					else {
						//先頭より左側には列を追加できないのでそれをはじくための分岐
						if (select == "ElderButton") {
							//左側に列を追加できない旨を出力
							MessageBox::Show("先頭より左方向に列は追加できません");
						}//それ以外の時は右方向に列を構造体を連結する関数を呼び出す
						else {
							this->AddYoungColumn(i);
						}
					}
				}
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
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
				*this->rowcount += 1;
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
			//ここまでカウントしてきた行数が既存の行数より大きければ
			if (*this->rowcount > *this->Row) {
				//大きい方を採用する
				this->Row = this->rowcount;
			}
			//行数カウントをリセットする
			this->rowcount = 0;
			return;
		}

		/*概要：詳細編集画面に出力する表画像を生成する関数
		引数：PictureBox^ pict：生成した表画像を載せるピクチャボックス
		戻り値：PictureBox^ pict：必要情報を設定したピクチャボックス
		作成日：2017.9.25
		作成者：K.Asada*/
		PictureBox^ infoTableGenerate(CellDataChain::cellchain^ tableelem, PictureBox^ pict, Int32 parentcount) {
			//構造体を操作するためのクラスをインスタンス化する
			CellDataChain^ CellCtrl = gcnew CellDataChain();
			//描画する対象の構造体を取得するための構造体
			CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
			//描画を行う空のビットマップを作成する
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * parentcount, *this->RctHeight);
			//描画を行うためのグラフィッククラスをインスタンス化
			Graphics^ gr = Graphics::FromImage(img);
			//親キーがなくなるまで走査する
			for (int i = parentcount;i > 0 ;i--) {
				//秒が対象のキー名が格納された構造体を取得する
				elem = CellCtrl->GetParent(tableelem, i);
				//描画するセルのプロパティを入力する
				System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * (parentcount - i), 0, *this->RctWidth, *this->RctHeight);
				//セルの描画を行う関数を呼び出す
				this->DrawFigure(*rct, gr, elem);
			}
			//描画を終えたビットマップを設定する
			pict->Image = img;
			//ピクチャボックスを返却する
			return pict;
		}

		/*概要：取得したデータより表画像のセルを一つ分描画する関数
		引数：Rectangle^ rct：描画するセルの大きさと座標情報
			：Graphics^ gr：描画対象のグラフィッククラス
			：cellchain^ elem：描画したセルの中に表示する文字列が格納された構造体
		戻り値：なし
		作成日：2017.9.27
		作成者：K.Asada*/
		Void DrawFigure(System::Drawing::Rectangle^ rct, Graphics^ gr, CellDataChain::cellchain^ elem) {
			//描画する文字列のフォントを宣言
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//描画対象の構造体がオブジェクトであったときに色付けを行うためのブラシを宣言
			Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Blue));
			//セルの外枠を描画する
			gr->DrawRectangle(Pens::Black, *rct);
			//対象の構造体に子が存在している場合はオブジェクトとして扱う
			if (elem != nullptr && elem->lower != nullptr) {
				//オブジェクトであることを明示するために色付けを行う
				gr->FillRectangle(br, *rct);
				//オブジェクトの場合はキー名を描画する
				gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
			}//子がいない構造体である場合はデータとして扱う
			else if (elem != nullptr) {
				//データの場合は値を描画する
				gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
			}//構造体を取得していなかったときは何も描画しない
			return;
		}

		/*概要：対象のセルより若い方向（親または兄）に構造体を新規で連結する関数
		引数：Int32 rowindex：追加対象のセル
		戻り値：なし
		作成日：2017.9.28
		作成者：K.Asada*/
		Void AddYoungColumn(Int32 rowindex) {
			try {
				//構造体操作クラスをインスタンス化
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				CellDataChain::cellchain^ parent = nullptr;		//対象となる構造体を格納するための構造体
				//対象となる構造体を取得する
				parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
				//対象の構造体に子がいれば
				if (parent->lower != nullptr) {
					//対象の構造体の一番弟を取得する
					parent = CellCtrl->GetYoungChain(parent->lower);
					//対象の弟として新規で構造体を連結する
					CellCtrl->ChainYoungBrother("", "", parent);
				}//子がいない場合は子を連結する
				else {
					//新規で子を連結する
					CellCtrl->ChainChild("", "", parent);
				}
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}
	};
}