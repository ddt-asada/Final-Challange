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
		CellDataChain::cellchain^ TableElem = nullptr;					//表の情報が格納されたデータチェイン
		String^ JSONFilePath = Constants->EMPTY_STRING;		//読み込むJSONのファイルパス
		String^ DBQuery = Constants->EMPTY_STRING;			//DBよりJSON文字列を取得するためのクエリ

		/*概要：メンバ変数の情報をもとに表画像を生成する関数
		引数：なし
		戻り値：Bitmap^：生成した表画像
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ TableGenerate(PictureBox^ pict) {
			//表の描画の時に不正が出たときの例外を捕捉
			try {
				//チェイン構造操作クラスをインスタンス化
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//空のビットマップを生成
				Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
				//描画を行うためのグラフィッククラスをインスタンス化
				Graphics^ gr = Graphics::FromImage(img);
				//行数についてループ
				for (int i = 0; i < *this->Row; i++) {
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
				//作成した画像をピクチャボックスへのセル
				pict->Image = img;
				//ピクチャボックスの位置を設定する
				pict->Location = Constants->TABLE_LOCATION;
				//作成の終えたビットマップ画像を返す
				return pict;
			}
			//描画対象のImageがおかしかった時の例外を捕捉
			catch (System::FormatException^ e) {
				//描画対象が存在していないことをコンソールに出力
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->DRAW_ERROR_STRING + e);
			}
			//描画するセル（長方形の大きさ）の計算で不正値が出たときの例外を捕捉
			catch (System::OverflowException^ e) {
				//セルの大きさ情報が不正であることをコンソールに出力
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->RECT_ERROR_STRING + e);
			}
		}

		/*概要：選択箇所のセルをハイライトする関数
		引数：PictureBox^：画像を載せるコントロール
		戻り値；PictureBox^：画像を載せたコントロール
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ SelecteCell(PictureBox^ Pictselect) {
			try {
				//画像データを生成する
				Bitmap^ img = gcnew Bitmap(*this->RctWidth + 1, *this->RctHeight + 1);
				//描画用のグラフィッククラスをインスタンス化
				Graphics^ gr = Graphics::FromImage(img);
				//画像を載せる位置を設定する
				Pictselect->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//画像のサイズを設定
				Pictselect->Size = System::Drawing::Size(*this->RctWidth, *this->RctHeight);
				//ハイライト用の塗りつぶし画像を描画
				gr->FillRectangle(Constants->SELECT_COLOR, 0, 0, *this->RctWidth - 1, *this->RctHeight - 1);
				//描画の終わった画像をピクチャボックスのコントロールに乗せる
				Pictselect->Image = img;
				//背景色を親の色と同化させる
				Pictselect->BackColor = Color::Transparent;
				//処理の終わったピクチャボックスを返す
				return Pictselect;
			}
			//描画対象のImageがおかしかった時の例外を捕捉
			catch (System::FormatException^ e) {
				//描画対象が存在していないことをコンソールに出力
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->DRAW_ERROR_STRING + e);
			}
			//描画するセル（長方形の大きさ）の計算で不正値が出たときの例外を捕捉
			catch (System::OverflowException^ e) {
				//セルの大きさ情報が不正であることをコンソールに出力
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->RECT_ERROR_STRING + e);
			}
		}

		/*概要：クリックされたセルの座標を取得する関数
		引数：System::Windows::Forms::MouseEventArgs^：マウスのイベントの変数が格納されたクラス
		戻り値：なし
		作成日：2017.9.20
		作成者：K.Asada
		更新内容：結合状態の判定を削除
		更新日：2017.9.29
		更新者：K.Asada*/
		Void GetCellPoint(System::Windows::Forms::MouseEventArgs^ e) {
			//算術エラーを捕捉するための例外処理
			try {
				//マウスイベントクラスよりクリックしたときのマウスのY座標を取得する
				this->RowIndex = e->Location.Y / *this->RctHeight;
				//Xの座標を取得
				this->ColumnIndex = e->Location.X / *this->RctWidth;
				return;
			}
			//正しく座標が取得できなかったときのエラーを捕捉
			catch (System::DivideByZeroException^ er) {
				//0で割られていたら算術エラーにより座標が取得できなかったことコンソールに表示
				Console::WriteLine(Constants->INPUT_ERROR_STRING + er);
			}
		}

		/*概要：表画像の一部を再描画する関数
		引数：PitcutreBox^：表画像が載せられたピクチャボックス
		戻り値：PictureBox^：表画像の一部を再描画したものをのせたピクチャボックス
		作成日：2017.9.20
		作成者：K.Asada*/
		PictureBox^ ReTableGenerate(PictureBox^ repict) {
			//正常に描画できなかったときの例外処理
			try {
				//描画の対象をすでに生成されている表画像にしてグラフィッククラスをインスタンス化
				Graphics^ gr = Graphics::FromImage(repict->Image);
				//構造体操作クラスをインスタンス化
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//要素が格納された構造体を取得する
				CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
				//描画するセルを設定する
				System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
				//描画する要素が書くのされた構造体を取得する
				elem = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
				//白で上書きするためにセルの大きさと同じ塗りつぶし長方形を描画
				gr->FillRectangle(Constants->BACK_COLOR, *rct);
				//セルを描画する関数を呼び出す
				this->DrawFigure(*rct, gr, elem);
				//再描画の終えたピクチャボックスを返す
				return repict;
			}
			//描画対象のピクチャボックスの中のImageがおかしかった時の例外を捕捉
			catch (System::FormatException^ e) {
				//描画対象が存在していないことをコンソールに出力
				Console::WriteLine(Constants->DRAW_ERROR_STRING + e);
			}
			//描画するセル（長方形の大きさ）の計算で不正値が出たときの例外を捕捉
			catch (System::OverflowException^ e) {
				//セルの大きさ情報が不正であることをコンソールに出力
				Console::WriteLine(Constants->RECT_ERROR_STRING + e);
			}
		}

		/*概要：クリックされたセルに編集用のテキストボックスを配置する関数
		引数：配置するテキストボックス
		戻り値：テキストボックスに位置情報や文字列情報を格納したもの
		作成日：2017.9.20
		作成者：K.Asada
		更新日：2017.9.29
		更新者：K.Asada
		更新内容：結合状態の判定を削除
		更新日：2017.10.2
		更新者：K.Asada
		更新内容：キー名/値編集モードに対応するように判定を追加*/
		TextBox^ CellTextGenerate(TextBox^ cell, Boolean getkey, Boolean getvalue) {
			//nullptrを指したときの例外処理
			try {
				String^ data = Constants->EMPTY_STRING;			//構造体より取得した文字列を格納する文字列
				//座標を選択中のセルの左上に合わせる
				cell->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//サイズをセル一つ当たりの大きさに合わせる
				cell->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
				//構造体を操作するためのクラスをインスタンス化
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//要素が入った構造体を格納するための構造体を宣言
				CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
				//対象の構造体を取得する
				elem = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
				//対象の構造体の状態を判別して文字列を取得する関数を呼び出す
				data = CellCtrl->GetCellString(elem, getkey, getvalue);
				//テキストボックスに取得した文字列を格納する
				cell->Text = data;
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
			//構造体の削除時にNULLを指すかもしれないので例外処理
			try {
				this->Row = Constants->ZERO;				//行数を初期化する
				this->Column = Constants->ZERO;				//列数を初期化する
				this->RowIndex = Constants->ZERO;			//行座標を初期化する
				this->ColumnIndex = Constants->ZERO;		//列座標を初期化する
				this->RctWidth = 200;						//セル一つ当たりの幅を初期化する
				this->RctHeight = 100;						//セル一つ当たりの高さを初期化する
				this->JSONFilePath = Constants->EMPTY_STRING;//読み込み先のファイルパスを初期化する
				this->DBQuery = Constants->EMPTY_STRING;	//DBへ投げるクエリを初期化する
				CellDataChain^ CellCtrl = gcnew CellDataChain();	//構造体操作クラスをインスタンス化
				//構造体を削除する
				CellCtrl->DeleteChain(this->TableElem);
				return;
			}
			//NULL関係の例外を捕捉
			catch (System::NullReferenceException^ e) {
				//コンソールにエラー内容を表示
				System::Console::WriteLine(e);
			}
			//NULL関係の例外を捕捉
			catch (System::ArgumentNullException^ e) {
				//コンソールにエラー内容を表示
				System::Console::WriteLine(e);
			}
		}

		/*概要：設定画面を開くための関数
		引数：なし
		戻り値：なし
		作成日：2017.9.21
		作成者：K.Asada*/
		Void ShowOptionForm() {
			//入力されたファイルパス、クエリにおかしな値があったときに例外を捕捉するための例外処理
			try {
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
			//おかしな文字列が帰ってきたときに例外を捕捉
			catch (System::FormatException^ e) {
				//コンソールに例外内容、警告を表示
				Console::WriteLine(Constants->INPUT_ERROR_STRING + e);
			}
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
		更新日：2017.10.2
		更新者：K.Asada
		更新内容：内部処理を一部サブルーチン化
		*/
		Void RowAdd(Int32 rowindex, String^ select) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//挿入対象の構造体を格納するための構造体
				CellDataChain::cellchain^ parent = nullptr;
				//挿入対象の構造体を取得する
				parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
				//行を追加する関数を呼び出す
				this->AddProcess(select, parent);
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
		更新者：K.Asada
		更新内容：内部処理を一部サブルーチン化
		更新日：2017.10.2
		更新者：K.Asada*/
		Void ColumnAdd(Int32 row, Int32 columnindex, String^ select) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//表の親の構造体を格納するための構造体
				CellDataChain::cellchain^ parent = nullptr;
				//列要素に当たる構造体を挿入するための関数
				for (int i = 0; i < row; i++) {
					//行ごとの追加対象の構造体を取得する
					parent = CellCtrl->GetColumnChain(i, columnindex, this->TableElem->lower);
					//列座標が0より下の時は行の先頭を選択しているとするための分岐
					if (columnindex > 0) {
						//列を追加する関数を呼び出す
						this->AddProcess(select, parent);
					}//行を選択している場合は行の直下の子供を追加するようにする
					else {
							this->AddYoungColumn(i);
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
		Int32 CountColumn(CellDataChain::cellchain^ colchain) {
			try {
				Int32 colcount = 0;			//列数をカウントするための変数
				//列要素の構造体を走査して列数をカウントする
				for (; colchain != nullptr; colchain = colchain->next) {
					//列数カウントをインクリメント
					colcount++;
				}
				//カウントした列数を返却する
				return colcount;
			}
			//カウント対象の構造体がNULLを指したときの例外を捕捉
			catch (System::NullReferenceException^ e) {
				//コンソールにエラーを伝える
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
			//計算がオーバー浮浪した時の例外を捕捉
			catch (System::OverflowException^ e) {
				//コンソールにエラーを伝える
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
		}

		/*概要：表の列数を割り出すための関数
		引数：cellchain^ rowchain：カウント対象の構造体
		戻り値：なし
		作成日：2017.9.25
		作成者：K.Asada
		更新日：2017.10.2
		更新者：K.Asada
		更新内容：例外処理が抜けていたので追加*/
		Void CountRow(CellDataChain::cellchain^ rowchain) {
			try {
				Int32 column = 0;		//列数を格納するための変数
				Int32 colcount = 0;		//カウントした列数を格納するための変数
				Int32 row = 0;			//行数を格納するための変数
				//行の最後まで走査して行数をカウントする
				for (; rowchain != nullptr; rowchain = rowchain->next) {
					//行の先頭も列の要素なので列数カウントをインクリメント
					colcount++;
					//子がいれば再帰して列数のカウントに移る
					if (rowchain->lower != nullptr) {
						//列数をカウントする関数を呼び出す
						colcount += this->CountColumn(rowchain->lower);
					}
					//ここまでカウントしてきた列数が既存の列数より大きければ
					if (colcount > column) {
						//大きい方を採用する
						column = colcount;
					}
					//列数カウントをリセットする
					colcount = 0;
					//行数をインクリメント
					row++;
				}
				//行数をメンバに保管する
				this->Row = row;
				//列数をメンバに保管する
				this->Column = column;
				return;
			}
			//カウント対象の構造体がNULLを指したときの例外を捕捉
			catch (System::NullReferenceException^ e) {
				//コンソールにエラーを伝える
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
			//計算がオーバー浮浪した時の例外を捕捉
			catch (System::OverflowException^ e) {
				//コンソールにエラーを伝える
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
		}

		/*概要：詳細編集画面に出力する表画像を生成する関数
		引数：PictureBox^ pict：生成した表画像を載せるピクチャボックス
		戻り値：PictureBox^ pict：必要情報を設定したピクチャボックス
		作成日：2017.9.25
		作成者：K.Asada*/
		PictureBox^ infoTableGenerate(CellDataChain::cellchain^ tableelem, PictureBox^ pict, Int32 parentcount) {
			//表の描画に失敗した時の例外を捕捉
			try {
				//構造体を操作するためのクラスをインスタンス化する
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//描画する対象の構造体を取得するための構造体
				CellDataChain::cellchain^ elem = nullptr;
				//描画を行う空のビットマップを作成する
				Bitmap^ img = gcnew Bitmap(*this->RctWidth * parentcount, *this->RctHeight);
				//描画を行うためのグラフィッククラスをインスタンス化
				Graphics^ gr = Graphics::FromImage(img);
				//親キーがなくなるまで走査する
				for (int i = parentcount; i > 0; i--) {
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
			//描画対象のImageがおかしかった時の例外を捕捉
			catch (System::FormatException^ e) {
				//描画対象が存在していないことをコンソールに出力
				Console::WriteLine(Constants->DRAW_ERROR_STRING + e);
			}
			//描画するセル（長方形の大きさ）の計算で不正値が出たときの例外を捕捉
			catch (System::OverflowException^ e) {
				//セルの大きさ情報が不正であることをコンソールに出力
				Console::WriteLine(Constants->RECT_ERROR_STRING + e);
			}
		}

		/*概要：取得したデータより表画像のセルを一つ分描画する関数
		引数：Rectangle^ rct：描画するセルの大きさと座標情報
			：Graphics^ gr：描画対象のグラフィッククラス
			：cellchain^ elem：描画したセルの中に表示する文字列が格納された構造体
		戻り値：なし
		作成日：2017.9.27
		作成者：K.Asada
		更新日：2017.10.2
		更新者：K.Asada
		更新内容：キー名が空の時は配列であることをわかりやすくするために描画する内容を変更*/
		Void DrawFigure(System::Drawing::Rectangle^ rct, Graphics^ gr, CellDataChain::cellchain^ elem) {
			//描画時のエラーを捕捉
			try {
				String^ celldata = "";		//表画像に描画する文字列
				CellDataChain^ CellCtrl = gcnew CellDataChain();		//構造体操作クラスをインスタンス化
				//構造体より描画対象の文字列を取得
				celldata = CellCtrl->GetCellString(elem, false, false);
				//セルの外枠を描画する
				gr->DrawRectangle(Pens::Black, *rct);
				//対象の構造体に子が存在している場合はオブジェクトとして扱う
				if (elem != nullptr && elem->lower != nullptr) {
					//オブジェクトであることを明示するために色付けを行う
					gr->FillRectangle(Constants->OBJECT_COLOR, *rct);
				}
				//取得した文字列がからであり、構造体に子が存在する場合は配列である旨を描画
				if (elem != nullptr && celldata == Constants->EMPTY_STRING && elem->lower != nullptr) {
					//配列と描画する
					gr->DrawString(Constants->ARRAY_STRING, Constants->TABLE_FONT, Brushes::Black, *rct);
				}//それ以外の時は取得した文字列をそのまま描画する
				else{
					//取得した文字列を描画する
					gr->DrawString(celldata, Constants->TABLE_FONT, Brushes::Black, *rct);
				}
				return;
			}
			//描画対象が不正の時に例外を捕捉
			catch (System::FormatException^ e) {
				//描画対象が存在していないことをコンソールに出力
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->DRAW_ERROR_STRING + e);
			}
		}

		/*概要：対象のセルより若い方向（親または兄）に構造体を新規で連結する関数
		引数：Int32 rowindex：追加対象のセル
		戻り値：なし
		作成日：2017.9.28
		作成者：K.Asada
		更新内容：下位に構造体を追加しないように変更
		更新日：2017.10.2
		更新者：K.Asda*/
		Void AddYoungColumn(Int32 rowindex) {
			try {
				//構造体操作クラスをインスタンス化
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				CellDataChain::cellchain^ parent = nullptr;		//対象となる構造体を格納するための構造体
				//対象となる構造体を取得する
				parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
				//対象の構造体に子がいれば
				if (parent->lower != nullptr) {
					//対象の兄として新規で構造体を連結する
					CellCtrl->ChainElderBrother(Constants->CHAIN_KEY_STRING, Constants->CHAIN_VALUE_STRING, parent->lower);
				}//子がいない場合は子を連結する
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*概要：指定した行の構造体を削除する関数
		引数：Int32 rowindex：削除対象の行座標
		戻り値：なし
		作成日：2017.9.29
		作成者：K.Asada*/
		Void RowDelete(Int32 rowindex) {
			//構造体でNULLを指すかもしれないので例外処理
			try {
				CellDataChain::cellchain^ parent = nullptr;			//対象の構造体を格納するための空の構造体
				CellDataChain^ CellCtrl = gcnew CellDataChain();	//構造体を操作するクラスをインスタンス化
				//対象の構造体を取得する
				parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
				//対象の構造体を削除する
				CellCtrl->DeleteChain(parent);
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*概要：指定した列の構造体を削除する関数
		引数：Int32 row：表の行数、
			：Int32 columnindex：対象の列座標
		戻り値：なし
		作成日：2017.9.29
		作成者：K.Asada*/
		Void ColumnDelete(Int32 row, Int32 columnindex) {
			//構造体でNULLを指すかもしれないので例外処理
			try {
				CellDataChain::cellchain^ parent = nullptr;		//削除対象の構造体を格納するための空の構造体
				CellDataChain^ CellCtrl = gcnew CellDataChain();//構造体を操作するクラスをインスタンス化
				//対象をすべて削除するまで走査する
				for (int i = 0; i < row; i++) {
					//削除対象を取得する
					parent = CellCtrl->GetColumnChain(i, columnindex, this->TableElem->lower);
					//対象が取得できたか
					if (parent != nullptr) {
						//対象が取得できた場合は削除する
						CellCtrl->DeleteChain(parent);
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

		/*概要：行・列の追加関数で利用する処理関数
		引数：String^ select：どの方向に追加するかを示す文字列
			：cellchain^ parent：追加対象となる文字列
		作成日：2017.10.2
		作成者：K.Asada*/
		System::Void AddProcess(String^ select, CellDataChain::cellchain^ parent) {
			//NULLを指す恐れがあるので例外処理
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();		//構造体操作クラスをインスタンス化
				//構造体が取得できていなければ処理を行わない
				if (parent != nullptr) {
					//上位ボタンが押されていたら自分より上位に追加
					if (select == Constants->ELDER_BUTTON_STRING) {
						//兄として構造体を追加する
						CellCtrl->ChainElderBrother(Constants->CHAIN_KEY_STRING, Constants->CHAIN_VALUE_STRING, parent);
					}//下位ボタンが押されていて追加対象の構造体に弟が存在したら
					else if (select == Constants->YOUNG_BUTTON_STRING && parent->next != nullptr) {
						//弟として構造体を追加する
						CellCtrl->ChainYoungBrother(Constants->CHAIN_KEY_STRING, Constants->CHAIN_VALUE_STRING, parent);
					}
				}
				return;
			}
			//参照先がNULLであった場合捕捉
			catch (System::NullReferenceException^ e) {
				//エラー内容をコンソールに出力
				Console::WriteLine(Constants->INPUT_ERROR_STRING + e);
			}
		}
	};
}