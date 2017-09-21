#pragma once

#include "OptionForm.h"			//設定画面クラスのヘッダ
#include "TableInformation.h"	//表画像関係の関数をまとめたクラスのヘッダ
#include "MoreDetailForm.h"		//詳細画面クラスのヘッダ
#include "Processing.h"			//内部処理クラスのヘッダ

namespace JSONGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace TableInformation;

	/// <summary>
	/// JSONGUI の概要
	/// </summary>
	/*概要：JSONを視覚的に作成するためのGUIメイン画面
	作成日：2017.9.20
	作成者：K.Asada*/
	public ref class JSONGUI
		: public TableInformation
	//	: public System::Windows::Forms::Form
	{
	public:
		JSONGUI(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~JSONGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage;
	private: System::Windows::Forms::Button^  buttonTableCancel;
	private: System::Windows::Forms::Button^  buttonTableOK;
	private: System::Windows::Forms::Button^  buttonConnect;
	private: System::Windows::Forms::Button^  buttonOption;
	private: System::Windows::Forms::TextBox^  textBoxRow;
	private: System::Windows::Forms::TextBox^  textBoxCol;
	private: System::Windows::Forms::TextBox^  textBoxCell;
	private: System::Windows::Forms::PictureBox^  pictureBoxCurrent;
	private: System::Windows::Forms::PictureBox^  pictureBoxTable;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  buttonTableConv;
	private: System::Windows::Forms::Button^  buttonListConv;



	private: System::Windows::Forms::Button^  buttonListCancel;

	private: System::Windows::Forms::Button^  buttonListOK;

	private: System::Windows::Forms::Button^  buttonListConnect;

	private: System::Windows::Forms::Button^  buttonListOption;

	private: System::Windows::Forms::TextBox^  textBoxListRow;
	private: System::Windows::Forms::TextBox^  textBoxList;
	private: System::Windows::Forms::PictureBox^  pictureBoxListCurr;
	private: System::Windows::Forms::PictureBox^  pictureBoxList;
	private: System::Windows::Forms::Button^  buttonJoin;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage = (gcnew System::Windows::Forms::TabPage());
			this->buttonJoin = (gcnew System::Windows::Forms::Button());
			this->buttonTableConv = (gcnew System::Windows::Forms::Button());
			this->buttonTableCancel = (gcnew System::Windows::Forms::Button());
			this->buttonTableOK = (gcnew System::Windows::Forms::Button());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->buttonOption = (gcnew System::Windows::Forms::Button());
			this->textBoxRow = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCol = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCell = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxCurrent = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxTable = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->buttonListConv = (gcnew System::Windows::Forms::Button());
			this->buttonListCancel = (gcnew System::Windows::Forms::Button());
			this->buttonListOK = (gcnew System::Windows::Forms::Button());
			this->buttonListConnect = (gcnew System::Windows::Forms::Button());
			this->buttonListOption = (gcnew System::Windows::Forms::Button());
			this->textBoxListRow = (gcnew System::Windows::Forms::TextBox());
			this->textBoxList = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxListCurr = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxList = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->tabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCurrent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTable))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxListCurr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxList))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1460, 869);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage
			// 
			this->tabPage->AutoScroll = true;
			this->tabPage->Controls->Add(this->buttonJoin);
			this->tabPage->Controls->Add(this->buttonTableConv);
			this->tabPage->Controls->Add(this->buttonTableCancel);
			this->tabPage->Controls->Add(this->buttonTableOK);
			this->tabPage->Controls->Add(this->buttonConnect);
			this->tabPage->Controls->Add(this->buttonOption);
			this->tabPage->Controls->Add(this->textBoxRow);
			this->tabPage->Controls->Add(this->textBoxCol);
			this->tabPage->Controls->Add(this->textBoxCell);
			this->tabPage->Controls->Add(this->pictureBoxCurrent);
			this->tabPage->Controls->Add(this->pictureBoxTable);
			this->tabPage->Location = System::Drawing::Point(8, 39);
			this->tabPage->Name = L"tabPage";
			this->tabPage->Padding = System::Windows::Forms::Padding(3);
			this->tabPage->Size = System::Drawing::Size(1444, 822);
			this->tabPage->TabIndex = 0;
			this->tabPage->Text = L"テーブル";
			this->tabPage->UseVisualStyleBackColor = true;
			// 
			// buttonJoin
			// 
			this->buttonJoin->Location = System::Drawing::Point(507, 6);
			this->buttonJoin->Name = L"buttonJoin";
			this->buttonJoin->Size = System::Drawing::Size(167, 68);
			this->buttonJoin->TabIndex = 10;
			this->buttonJoin->Text = L"結合/解除";
			this->buttonJoin->UseVisualStyleBackColor = true;
			this->buttonJoin->Click += gcnew System::EventHandler(this, &JSONGUI::TableJoinClick);
			// 
			// buttonTableConv
			// 
			this->buttonTableConv->Location = System::Drawing::Point(1292, 6);
			this->buttonTableConv->Name = L"buttonTableConv";
			this->buttonTableConv->Size = System::Drawing::Size(146, 68);
			this->buttonTableConv->TabIndex = 9;
			this->buttonTableConv->Text = L"変換";
			this->buttonTableConv->UseVisualStyleBackColor = true;
			this->buttonTableConv->Click += gcnew System::EventHandler(this, &JSONGUI::TableConvClick);
			// 
			// buttonTableCancel
			// 
			this->buttonTableCancel->Location = System::Drawing::Point(1140, 6);
			this->buttonTableCancel->Name = L"buttonTableCancel";
			this->buttonTableCancel->Size = System::Drawing::Size(146, 68);
			this->buttonTableCancel->TabIndex = 8;
			this->buttonTableCancel->Text = L"キャンセル";
			this->buttonTableCancel->UseVisualStyleBackColor = true;
			this->buttonTableCancel->Click += gcnew System::EventHandler(this, &JSONGUI::TableCancelClick);
			// 
			// buttonTableOK
			// 
			this->buttonTableOK->Location = System::Drawing::Point(988, 6);
			this->buttonTableOK->Name = L"buttonTableOK";
			this->buttonTableOK->Size = System::Drawing::Size(146, 68);
			this->buttonTableOK->TabIndex = 7;
			this->buttonTableOK->Text = L"OK";
			this->buttonTableOK->UseVisualStyleBackColor = true;
			this->buttonTableOK->Click += gcnew System::EventHandler(this, &JSONGUI::TableOKClick);
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(844, 6);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(138, 68);
			this->buttonConnect->TabIndex = 6;
			this->buttonConnect->Text = L"通信";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &JSONGUI::ButtonConnectClick);
			// 
			// buttonOption
			// 
			this->buttonOption->Location = System::Drawing::Point(680, 6);
			this->buttonOption->Name = L"buttonOption";
			this->buttonOption->Size = System::Drawing::Size(158, 68);
			this->buttonOption->TabIndex = 5;
			this->buttonOption->Text = L"設定";
			this->buttonOption->UseVisualStyleBackColor = true;
			this->buttonOption->Click += gcnew System::EventHandler(this, &JSONGUI::buttonOption_Click);
			// 
			// textBoxRow
			// 
			this->textBoxRow->Location = System::Drawing::Point(124, 6);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(100, 31);
			this->textBoxRow->TabIndex = 4;
			// 
			// textBoxCol
			// 
			this->textBoxCol->Location = System::Drawing::Point(124, 43);
			this->textBoxCol->Name = L"textBoxCol";
			this->textBoxCol->Size = System::Drawing::Size(100, 31);
			this->textBoxCol->TabIndex = 3;
			// 
			// textBoxCell
			// 
			this->textBoxCell->Location = System::Drawing::Point(1246, 316);
			this->textBoxCell->Multiline = true;
			this->textBoxCell->Name = L"textBoxCell";
			this->textBoxCell->Size = System::Drawing::Size(140, 76);
			this->textBoxCell->TabIndex = 2;
			this->textBoxCell->DoubleClick += gcnew System::EventHandler(this, &JSONGUI::TextBoxCellClick);
			// 
			// pictureBoxCurrent
			// 
			this->pictureBoxCurrent->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxCurrent->Location = System::Drawing::Point(1254, 425);
			this->pictureBoxCurrent->Name = L"pictureBoxCurrent";
			this->pictureBoxCurrent->Size = System::Drawing::Size(83, 102);
			this->pictureBoxCurrent->TabIndex = 1;
			this->pictureBoxCurrent->TabStop = false;
			this->pictureBoxCurrent->Click += gcnew System::EventHandler(this, &JSONGUI::PictureBoxCurrentClick);
			// 
			// pictureBoxTable
			// 
			this->pictureBoxTable->Location = System::Drawing::Point(38, 377);
			this->pictureBoxTable->Name = L"pictureBoxTable";
			this->pictureBoxTable->Size = System::Drawing::Size(647, 424);
			this->pictureBoxTable->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxTable->TabIndex = 0;
			this->pictureBoxTable->TabStop = false;
			this->pictureBoxTable->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONGUI::PictureBoxTableMouseClick);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->buttonListConv);
			this->tabPage2->Controls->Add(this->buttonListCancel);
			this->tabPage2->Controls->Add(this->buttonListOK);
			this->tabPage2->Controls->Add(this->buttonListConnect);
			this->tabPage2->Controls->Add(this->buttonListOption);
			this->tabPage2->Controls->Add(this->textBoxListRow);
			this->tabPage2->Controls->Add(this->textBoxList);
			this->tabPage2->Controls->Add(this->pictureBoxListCurr);
			this->tabPage2->Controls->Add(this->pictureBoxList);
			this->tabPage2->Location = System::Drawing::Point(8, 39);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1444, 822);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"リスト";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonListConv
			// 
			this->buttonListConv->Location = System::Drawing::Point(1276, 14);
			this->buttonListConv->Name = L"buttonListConv";
			this->buttonListConv->Size = System::Drawing::Size(146, 68);
			this->buttonListConv->TabIndex = 19;
			this->buttonListConv->Text = L"変換";
			this->buttonListConv->UseVisualStyleBackColor = true;
			this->buttonListConv->Click += gcnew System::EventHandler(this, &JSONGUI::ListConvClick);
			// 
			// buttonListCancel
			// 
			this->buttonListCancel->Location = System::Drawing::Point(1124, 14);
			this->buttonListCancel->Name = L"buttonListCancel";
			this->buttonListCancel->Size = System::Drawing::Size(146, 68);
			this->buttonListCancel->TabIndex = 18;
			this->buttonListCancel->Text = L"キャンセル";
			this->buttonListCancel->UseVisualStyleBackColor = true;
			this->buttonListCancel->Click += gcnew System::EventHandler(this, &JSONGUI::ListCancelClilck);
			// 
			// buttonListOK
			// 
			this->buttonListOK->Location = System::Drawing::Point(972, 14);
			this->buttonListOK->Name = L"buttonListOK";
			this->buttonListOK->Size = System::Drawing::Size(146, 68);
			this->buttonListOK->TabIndex = 17;
			this->buttonListOK->Text = L"OK";
			this->buttonListOK->UseVisualStyleBackColor = true;
			this->buttonListOK->Click += gcnew System::EventHandler(this, &JSONGUI::ListOKClick);
			// 
			// buttonListConnect
			// 
			this->buttonListConnect->Location = System::Drawing::Point(828, 14);
			this->buttonListConnect->Name = L"buttonListConnect";
			this->buttonListConnect->Size = System::Drawing::Size(138, 68);
			this->buttonListConnect->TabIndex = 16;
			this->buttonListConnect->Text = L"通信";
			this->buttonListConnect->UseVisualStyleBackColor = true;
			this->buttonListConnect->Click += gcnew System::EventHandler(this, &JSONGUI::ListConnectClick);
			// 
			// buttonListOption
			// 
			this->buttonListOption->Location = System::Drawing::Point(664, 14);
			this->buttonListOption->Name = L"buttonListOption";
			this->buttonListOption->Size = System::Drawing::Size(158, 68);
			this->buttonListOption->TabIndex = 15;
			this->buttonListOption->Text = L"設定";
			this->buttonListOption->UseVisualStyleBackColor = true;
			this->buttonListOption->Click += gcnew System::EventHandler(this, &JSONGUI::ListOptionClick);
			// 
			// textBoxListRow
			// 
			this->textBoxListRow->Location = System::Drawing::Point(94, 14);
			this->textBoxListRow->Name = L"textBoxListRow";
			this->textBoxListRow->Size = System::Drawing::Size(100, 31);
			this->textBoxListRow->TabIndex = 14;
			// 
			// textBoxList
			// 
			this->textBoxList->Location = System::Drawing::Point(1230, 324);
			this->textBoxList->Multiline = true;
			this->textBoxList->Name = L"textBoxList";
			this->textBoxList->Size = System::Drawing::Size(140, 76);
			this->textBoxList->TabIndex = 13;
			this->textBoxList->DoubleClick += gcnew System::EventHandler(this, &JSONGUI::TextBoxListClick);
			// 
			// pictureBoxListCurr
			// 
			this->pictureBoxListCurr->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxListCurr->Location = System::Drawing::Point(1238, 433);
			this->pictureBoxListCurr->Name = L"pictureBoxListCurr";
			this->pictureBoxListCurr->Size = System::Drawing::Size(83, 102);
			this->pictureBoxListCurr->TabIndex = 12;
			this->pictureBoxListCurr->TabStop = false;
			this->pictureBoxListCurr->Click += gcnew System::EventHandler(this, &JSONGUI::PictureBoxListCurrClick);
			// 
			// pictureBoxList
			// 
			this->pictureBoxList->Location = System::Drawing::Point(22, 385);
			this->pictureBoxList->Name = L"pictureBoxList";
			this->pictureBoxList->Size = System::Drawing::Size(647, 424);
			this->pictureBoxList->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxList->TabIndex = 11;
			this->pictureBoxList->TabStop = false;
			this->pictureBoxList->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONGUI::PictureBoxListMouseClick);
			// 
			// JSONGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1460, 869);
			this->Controls->Add(this->tabControl1);
			this->Name = L"JSONGUI";
			this->Text = L"JSONGUI";
			this->Load += gcnew System::EventHandler(this, &JSONGUI::JSONGUI_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage->ResumeLayout(false);
			this->tabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCurrent))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTable))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxListCurr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxList))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

/*概要：メイン画面ロード時の初期化イベント*/
private: System::Void JSONGUI_Load(System::Object^  sender, System::EventArgs^  e) {
}

/*概要：テーブルタブの設定ボタンクリック時のイベント、設定画面を開く
引数：Sender：クリック時のフォームの情報が格納されたオブジェクトクラス
	：EventArgs：クリック時のマウス関係の情報が格納されたイベントクラス
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: System::Void buttonOption_Click(System::Object^  sender, System::EventArgs^  e) {
	//設定画面を開く関数を呼び出す
	this->ShowOptionForm();
}

/*概要：プログラム終了時のイベント、終了するどうかの確認を行う。
引数：
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: System::Void FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//閉じる前にメッセージボックスを表示して確認を行う。
	if (System::Windows::Forms::DialogResult::Cancel == MessageBox::Show("終了しますか？", "確認", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)) {
		//プログラムを終了する。
		e->Cancel = true;
	}
}

/*概要：テーブルタブに関する情報を初期化する関数
引数：なし
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: Void TableInit() {
	//基底クラスの初期化関数を呼び出す
	this->InfoInit();
	//表画像をコントロールから除外する
	this->Controls->Remove(this->pictureBoxTable);
	//選択箇所をハイライトする画像をコントロールから除外する
	this->Controls->Remove(this->pictureBoxCurrent);
	//表画像上のテキストボックスをコントロールから除外する
	this->Controls->Remove(this->textBoxCell);
}

/*概要：テーブルタブのキャンセルボタンクリック時のイベント、テーブルタブに関する情報を初期化する関数を呼び出す
引数：
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: System::Void TableCancelClick(System::Object^  sender, System::EventArgs^  e) {
	//テーブルタブに関する情報を初期化する関数を呼び出す
	this->TableInit();
}

/*概要：通信ボタンのクリックイベント、DBクエリ処理関数を呼び出す
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void ButtonConnectClick(System::Object^  sender, System::EventArgs^  e) {
	//内部処理クラスをインスタンス化
	process::Processing^ proc = gcnew process::Processing(this->DBQuery);
	//行数が入力されていれば行数を渡す、テキストボックスの中身はString^型のためInt32に変換を行う
	proc->row = Convert::ToInt32(this->textBoxRow->Text);
	//列数が入力されていれば列数を渡す、テキストボックスの中身はString^型のためInt32に変換を行う
	proc->column = Convert::ToInt32(this->textBoxCol->Text);
	//DBの内部処理関数を呼び出す
	proc->DBrun(this->DBQuery);
	//内部処理にて取得した行数をメンバへ格納する
	this->Column = proc->column;
	//内部処理にて取得した列数をメンバへ格納する
	this->Row = proc->row;
	//取得した構造体をメンバへ格納する
	this->TableElem = proc->Tablechain;
	//取得した結合情報をメンバへ格納する
	this->JoinIndex = proc->joinInfo;
	//表画像を生成する関数を呼び出す
	this->TableGenerate(this->pictureBoxTable);
	//コントロールへがピクチャボックスを追加する
	this->Controls->Add(this->pictureBoxTable);
}

/*概要：テーブルタブのOKボタンクリックイベント、内部処理クラスへ移行する
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void TableOKClick(System::Object^  sender, System::EventArgs^  e) {
	//内部処理クラスをインスタンス化
	process::Processing^ proc = gcnew process::Processing();
	//テキストボックスに入力された行数をInt32型に変換してから渡す
	proc->row = Convert::ToInt32(this->textBoxRow->Text);
	//テキストボックスに入力された列数をInt32型に変換してから渡す
	proc->column = Convert::ToInt32(this->textBoxCol->Text);
	//JSONをチェイン構造に変換する関数を呼び出す
	proc->Tablerun(this->JSONFilePath);
	//取得した列数をメンバへ格納する
	this->Column = proc->column;
	//取得した行数をメンバへ格納する
	this->Row = proc->row;
	//構造体をメンバへ格納する
	this->TableElem = proc->Tablechain;
	//結合情報をメンバへ格納する
	this->JoinIndex = proc->joinInfo;
	//表画像を生成する関数を呼び出す
	this->TableGenerate(this->pictureBoxTable);
	//コントロールへピクチャボックスを追加する
	this->Controls->Add(this->pictureBoxTable);
}

/*概要：テーブルタブの変換ボタンクリック時のイベント
作成日：201.9.21
作成者：K.Asada*/
private: System::Void TableConvClick(System::Object^  sender, System::EventArgs^  e) {
	//内部処理クラスをインスタンス化
	//コンストラクタを変更する可能性あり
	process::Processing^ proc = gcnew process::Processing();
	//文字列構造体を渡す
	proc->Tablechain = this->TableElem;
	//行数を渡す
	proc->row = this->Row;
	//列数を渡す
	proc->column = this->Column;
	//JSONに変換する関数を呼び出す
	//proc->JSONRUN();
}
private: System::Void TableJoinClick(System::Object^  sender, System::EventArgs^  e) {
}

/*概要：箇条書き関係の情報を初期化する関数
引数：なし
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: Void ListInit() {
	//表画像を削除する
	this->Controls->Remove(this->pictureBoxList);
	//表画像ハイライト用の画像を削除する
	this->Controls->Remove(this->pictureBoxListCurr);
	//配列数テキストタブを初期化する
	this->textBoxListRow->Clear();
	//表画像の値編集用テキストボックスを初期化する
	this->textBoxList->Clear();
	//テキストボックスを除去する
	this->Controls->Remove(this->textBoxList);
	//基底クラスの初期化関数を呼び出す
	this->InfoInit();
}

/*概要：リストタブのOKボタンクリックイベント、ファイルパスからJSONを読み込んで処理する
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void ListOKClick(System::Object^  sender, System::EventArgs^  e) {
	//内部処理クラスをインスタンス化
	process::Processing^ proc = gcnew process::Processing();
	//行数を渡す
	proc->row = Convert::ToInt32(this->textBoxListRow);
	//内部処理関数を呼び出す
	proc->Listrun(this->JSONFilePath);
	//取得した行数をメンバへ格納する
	this->Row = proc->row;
	//取得した構造体をメンバへ格納する
	this->TableElem = proc->Tablechain;
	//取得した結合情報をメンバへ格納する
	this->JoinIndex = proc->joinInfo;
	//表画像生成関数を呼び出す
	this->TableGenerate(this->pictureBoxList);
	//作成した画像をコントロールへ追加する
	this->Controls->Add(this->pictureBoxList);
}

/*概要：リストタブのキャンセルボタンクリックイベント、初期化関数を呼び出す
引数：
戻り値：
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void ListCancelClilck(System::Object^  sender, System::EventArgs^  e) {
	//初期化関数を呼び出す
	this->ListInit();
}
private: System::Void ListConvClick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ListConnectClick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ListOptionClick(System::Object^  sender, System::EventArgs^  e) {
}

/*表画像上をクリックしたときのイベント、選択状態にする関数を呼び出す
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void PictureBoxTableMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//選択状態を保持するためにクリックした表画像上の座標をメンバへ保存する関数を呼び出す
	this->GetCellPoint(e);
	//選択箇所がわかりやすいようにハイライトする関数を呼び出す
	this->SelecteCell(this->pictureBoxCurrent);
	//ハイライト画像をコントロールへ追加する
	this->Controls->Add(this->pictureBoxCurrent);
}

/*概要：リストタブの表画像上をクリックしたときのイベント、選択状態にする関数を呼び出す
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void PictureBoxListMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//選択状態を保持するためにクリックした表画像上の座標をメンバへ保存する関数を呼び出す
	this->GetCellPoint(e);
	//選択箇所がわかりやすいようにハイライトする関数を呼び出す
	this->SelecteCell(this->pictureBoxListCurr);
	//ハイライト画像をコントロールへ追加する
	this->Controls->Add(this->pictureBoxListCurr);
}

/*概要：表画像のハイライトされている箇所をクリックしたときのイベント、テキストボックスを配置して編集可能状態にする
引数：
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: System::Void PictureBoxCurrentClick(System::Object^  sender, System::EventArgs^  e) {
	//テキストボックスに情報を設定する関数を呼び出す
	this->CellTextGenerate(this->textBoxCell);
	//生成したテキストボックスをメイン画面のコントロールに乗せる
	this->Controls->Add(this->textBoxCell);
}

/*概要：リストタブの画像のハイライト部分をクリックしたときのイベント、編集用のテキストボックスを表示
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void PictureBoxListCurrClick(System::Object^  sender, System::EventArgs^  e) {
	//テキストボックスを配置するための情報を設定する関数を呼び出す
	this->CellTextGenerate(this->textBoxList);
	//情報が設定されたテキストボックスをコントロールに追加して表示する
	this->Controls->Add(this->textBoxList);
}

/*概要：表画像の値編集用のテキストボックスがダブルクリックされたときのイベント
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void TextBoxListClick(System::Object^  sender, System::EventArgs^  e) {
	//クリックしたセルの親キーを編集するための詳細画面クラスをインスタンス化
	MoreDetailForm^ more = gcnew MoreDetailForm();
	//新規ダイアログで表示する
	more->ShowDialog();
}

/*概要：表画像の値編集用のテキストボックスがダブルクリックされたときのイベント
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void TextBoxCellClick(System::Object^  sender, System::EventArgs^  e) {
	//クリックしたセルの親キーを編集するための詳細画面クラスをインスタンス化
	MoreDetailForm^ more = gcnew MoreDetailForm();
	//新規ダイアログで表示する
	more->ShowDialog();
}
};
}
