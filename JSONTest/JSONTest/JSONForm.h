#pragma once

#include "CONSTANTSTRING.h"
#include "TableInformation.h"
#include "TableProcessing.h"
#include "InputOption.h"
#include "Processing.h"

namespace JSONTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace process;

	/// <summary>
	/// JSONForm の概要
	/// </summary>
	public ref class JSONForm 
		//: public System::Windows::Forms::Form
		: public TableProcessing
	{
	public:
		JSONForm(void)
		{
			InitializeComponent();
			this->pictureBox2->Parent = this->pictureBox1;
			this->pictureBox4->Parent = this->pictureBox3;
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  buttonJoin;
	private: System::Windows::Forms::TextBox^  textBoxCell;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::TextBox^  textBoxList;

	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Button^  buttonListConv;
	private: System::Windows::Forms::Button^  buttonConnect;


	public:
		constantstring::CONSTANTSTRING^ MyConst = gcnew constantstring::CONSTANTSTRING();

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~JSONForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelRow;
	protected:
	private: System::Windows::Forms::Label^  labelColumn;
	private: System::Windows::Forms::TextBox^  textBoxRow;
	private: System::Windows::Forms::TextBox^  textBoxColumn;
	private: System::Windows::Forms::Button^  buttonInputOption;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;


	private: System::Windows::Forms::Button^  buttonCancel2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonOK2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonInputOption2;
	private: System::Windows::Forms::TextBox^  textBoxRow2;
	private: System::Windows::Forms::TextBox^  textBoxColumn2;




	private: System::Windows::Forms::Button^  buttonConversion;


	private:
		String^ JSONFilePath = MyConst->EMPTY_STRING;		//入力されたJSONのファイルパスを格納するための文字列。
		String^ DBQuery = MyConst->EMPTY_STRING;			//入力されたDBへ投げるクエリを格納する文字列。
		String^ DBResult = MyConst->EMPTY_STRING;			//DBとの通信結果を格納する文字列。
		Int32^ TextIndex = 0;				//フォーカス中の文字列判定用の変数
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
			this->labelRow = (gcnew System::Windows::Forms::Label());
			this->labelColumn = (gcnew System::Windows::Forms::Label());
			this->textBoxRow = (gcnew System::Windows::Forms::TextBox());
			this->textBoxColumn = (gcnew System::Windows::Forms::TextBox());
			this->buttonInputOption = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBoxCell = (gcnew System::Windows::Forms::TextBox());
			this->buttonJoin = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonConversion = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->buttonListConv = (gcnew System::Windows::Forms::Button());
			this->textBoxList = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonCancel2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonOK2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonInputOption2 = (gcnew System::Windows::Forms::Button());
			this->textBoxRow2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxColumn2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// labelRow
			// 
			this->labelRow->AutoSize = true;
			this->labelRow->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelRow->Location = System::Drawing::Point(0, 13);
			this->labelRow->Name = L"labelRow";
			this->labelRow->Size = System::Drawing::Size(81, 33);
			this->labelRow->TabIndex = 0;
			this->labelRow->Text = L"タテ";
			// 
			// labelColumn
			// 
			this->labelColumn->AutoSize = true;
			this->labelColumn->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelColumn->Location = System::Drawing::Point(0, 79);
			this->labelColumn->Name = L"labelColumn";
			this->labelColumn->Size = System::Drawing::Size(81, 33);
			this->labelColumn->TabIndex = 1;
			this->labelColumn->Text = L"ヨコ";
			// 
			// textBoxRow
			// 
			this->textBoxRow->Location = System::Drawing::Point(102, 13);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(100, 31);
			this->textBoxRow->TabIndex = 2;
			this->textBoxRow->Text = L"0";
			// 
			// textBoxColumn
			// 
			this->textBoxColumn->Location = System::Drawing::Point(102, 83);
			this->textBoxColumn->Name = L"textBoxColumn";
			this->textBoxColumn->Size = System::Drawing::Size(100, 31);
			this->textBoxColumn->TabIndex = 3;
			this->textBoxColumn->Text = L"0";
			// 
			// buttonInputOption
			// 
			this->buttonInputOption->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonInputOption->Location = System::Drawing::Point(249, 13);
			this->buttonInputOption->Name = L"buttonInputOption";
			this->buttonInputOption->Size = System::Drawing::Size(169, 101);
			this->buttonInputOption->TabIndex = 4;
			this->buttonInputOption->Text = L"設定";
			this->buttonInputOption->UseVisualStyleBackColor = true;
			this->buttonInputOption->Click += gcnew System::EventHandler(this, &JSONForm::buttonInputOption_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(797, 14);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(143, 36);
			this->buttonOK->TabIndex = 5;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &JSONForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(797, 76);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(143, 36);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"キャンセル";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &JSONForm::buttonCancel_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1466, 898);
			this->tabControl1->TabIndex = 9;
			// 
			// tabPage1
			// 
			this->tabPage1->AutoScroll = true;
			this->tabPage1->Controls->Add(this->buttonConnect);
			this->tabPage1->Controls->Add(this->textBoxCell);
			this->tabPage1->Controls->Add(this->buttonJoin);
			this->tabPage1->Controls->Add(this->pictureBox2);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->buttonConversion);
			this->tabPage1->Controls->Add(this->buttonCancel);
			this->tabPage1->Controls->Add(this->labelRow);
			this->tabPage1->Controls->Add(this->buttonOK);
			this->tabPage1->Controls->Add(this->labelColumn);
			this->tabPage1->Controls->Add(this->buttonInputOption);
			this->tabPage1->Controls->Add(this->textBoxRow);
			this->tabPage1->Controls->Add(this->textBoxColumn);
			this->tabPage1->Location = System::Drawing::Point(8, 39);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1450, 851);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &JSONForm::tabPage1_Click);
			// 
			// textBoxCell
			// 
			this->textBoxCell->BackColor = System::Drawing::Color::White;
			this->textBoxCell->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxCell->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBoxCell->Location = System::Drawing::Point(1132, 354);
			this->textBoxCell->Multiline = true;
			this->textBoxCell->Name = L"textBoxCell";
			this->textBoxCell->Size = System::Drawing::Size(221, 79);
			this->textBoxCell->TabIndex = 20;
			this->textBoxCell->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JSONForm::textBoxCell_KeyDown);
			this->textBoxCell->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONForm::textBoxCell_MouseDoubleClick);
			// 
			// buttonJoin
			// 
			this->buttonJoin->Location = System::Drawing::Point(424, 13);
			this->buttonJoin->Name = L"buttonJoin";
			this->buttonJoin->Size = System::Drawing::Size(182, 99);
			this->buttonJoin->TabIndex = 19;
			this->buttonJoin->Text = L"結合/解除";
			this->buttonJoin->UseVisualStyleBackColor = true;
			this->buttonJoin->Click += gcnew System::EventHandler(this, &JSONForm::buttonJoin_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox2->Location = System::Drawing::Point(1275, 265);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(78, 83);
			this->pictureBox2->TabIndex = 18;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONForm::pictureBox2_MouseClick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(4, 120);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(231, 133);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONForm::pictureBox1_MouseClick);
			// 
			// buttonConversion
			// 
			this->buttonConversion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonConversion->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonConversion->Location = System::Drawing::Point(1275, 744);
			this->buttonConversion->Name = L"buttonConversion";
			this->buttonConversion->Size = System::Drawing::Size(169, 101);
			this->buttonConversion->TabIndex = 15;
			this->buttonConversion->Text = L"変換";
			this->buttonConversion->UseVisualStyleBackColor = true;
			this->buttonConversion->Click += gcnew System::EventHandler(this, &JSONForm::buttonConversion_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->AutoScroll = true;
			this->tabPage2->Controls->Add(this->buttonListConv);
			this->tabPage2->Controls->Add(this->textBoxList);
			this->tabPage2->Controls->Add(this->pictureBox4);
			this->tabPage2->Controls->Add(this->pictureBox3);
			this->tabPage2->Controls->Add(this->buttonCancel2);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->buttonOK2);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->buttonInputOption2);
			this->tabPage2->Controls->Add(this->textBoxRow2);
			this->tabPage2->Controls->Add(this->textBoxColumn2);
			this->tabPage2->Location = System::Drawing::Point(8, 39);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1450, 851);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonListConv
			// 
			this->buttonListConv->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonListConv->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonListConv->Location = System::Drawing::Point(1275, 744);
			this->buttonListConv->Name = L"buttonListConv";
			this->buttonListConv->Size = System::Drawing::Size(169, 101);
			this->buttonListConv->TabIndex = 20;
			this->buttonListConv->Text = L"変換";
			this->buttonListConv->UseVisualStyleBackColor = true;
			this->buttonListConv->Click += gcnew System::EventHandler(this, &JSONForm::buttonListConv_Click);
			// 
			// textBoxList
			// 
			this->textBoxList->Location = System::Drawing::Point(1192, 204);
			this->textBoxList->Multiline = true;
			this->textBoxList->Name = L"textBoxList";
			this->textBoxList->Size = System::Drawing::Size(199, 84);
			this->textBoxList->TabIndex = 17;
			this->textBoxList->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JSONForm::textBoxList_KeyDown);
			this->textBoxList->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONForm::textBoxList_MouseDoubleClick);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox4->Location = System::Drawing::Point(1034, 32);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(120, 78);
			this->pictureBox4->TabIndex = 16;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONForm::pictureBox4_MouseClick);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::White;
			this->pictureBox3->Location = System::Drawing::Point(4, 123);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(305, 216);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONForm::pictureBox3_MouseClick);
			// 
			// buttonCancel2
			// 
			this->buttonCancel2->Location = System::Drawing::Point(621, 79);
			this->buttonCancel2->Name = L"buttonCancel2";
			this->buttonCancel2->Size = System::Drawing::Size(143, 36);
			this->buttonCancel2->TabIndex = 13;
			this->buttonCancel2->Text = L"キャンセル";
			this->buttonCancel2->UseVisualStyleBackColor = true;
			this->buttonCancel2->Click += gcnew System::EventHandler(this, &JSONForm::buttonCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(9, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 33);
			this->label1->TabIndex = 7;
			this->label1->Text = L"タテ";
			// 
			// buttonOK2
			// 
			this->buttonOK2->Location = System::Drawing::Point(621, 16);
			this->buttonOK2->Name = L"buttonOK2";
			this->buttonOK2->Size = System::Drawing::Size(143, 36);
			this->buttonOK2->TabIndex = 12;
			this->buttonOK2->Text = L"OK";
			this->buttonOK2->UseVisualStyleBackColor = true;
			this->buttonOK2->Click += gcnew System::EventHandler(this, &JSONForm::buttonOK2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(9, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 33);
			this->label2->TabIndex = 8;
			this->label2->Text = L"ヨコ";
			// 
			// buttonInputOption2
			// 
			this->buttonInputOption2->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonInputOption2->Location = System::Drawing::Point(258, 14);
			this->buttonInputOption2->Name = L"buttonInputOption2";
			this->buttonInputOption2->Size = System::Drawing::Size(169, 101);
			this->buttonInputOption2->TabIndex = 11;
			this->buttonInputOption2->Text = L"設定";
			this->buttonInputOption2->UseVisualStyleBackColor = true;
			this->buttonInputOption2->Click += gcnew System::EventHandler(this, &JSONForm::buttonInputOption_Click);
			// 
			// textBoxRow2
			// 
			this->textBoxRow2->Location = System::Drawing::Point(111, 16);
			this->textBoxRow2->Name = L"textBoxRow2";
			this->textBoxRow2->Size = System::Drawing::Size(100, 31);
			this->textBoxRow2->TabIndex = 9;
			this->textBoxRow2->Text = L"0";
			// 
			// textBoxColumn2
			// 
			this->textBoxColumn2->Location = System::Drawing::Point(111, 86);
			this->textBoxColumn2->Name = L"textBoxColumn2";
			this->textBoxColumn2->Size = System::Drawing::Size(100, 31);
			this->textBoxColumn2->TabIndex = 10;
			this->textBoxColumn2->Text = L"0";
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(612, 13);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(179, 99);
			this->buttonConnect->TabIndex = 21;
			this->buttonConnect->Text = L"接続";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &JSONForm::buttonConnect_Click);
			// 
			// JSONForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1466, 898);
			this->Controls->Add(this->tabControl1);
			this->DoubleBuffered = true;
			this->Name = L"JSONForm";
			this->Text = L"JSONForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JSONForm::JSONForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &JSONForm::JSONForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
//			InputOption^ iopt;	//設定ダイアログをインスタンス化するための準備

	private: System::Void JSONForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	//設定ボタンをクリックしたときの処理
private: System::Void buttonInputOption_Click(System::Object^  sender, System::EventArgs^  e) {
	//設定ダイアログを開くために設定クラスをインスタンス化する。
	InputOption^ iopt = gcnew InputOption();
	//設定ダイアログのJSONファイルパスが入力されたテキストボックスに前回に受け取ったパスを設定する。
	iopt->FilePath = this->JSONFilePath;
	//設定ダイアログのクエリのテキストボックスに前回受け取った値をセットする。
	iopt->SendQuery = this->DBQuery;
	//設定ダイアログを開く。
	iopt->ShowDialog();
	//設定画面にて取得したファイルパスをメンバ変数へ格納する。
	this->JSONFilePath = iopt->FilePath;
	//設定画面にて取得したDBとの通信結果をメンバ変数へ格納する。
	this->DBResult;
	//設定画面にて取得したDBとの通信結果をメンバ変数へ格納する。
	this->DBQuery = iopt->SendQuery;
}

//メインのフォームを閉じるときの処理
private: System::Void JSONForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//閉じる前にメッセージボックスを表示して確認を行う。
	if (System::Windows::Forms::DialogResult::Cancel == MessageBox::Show("終了しますか？", "確認", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)) {
		//プログラムを終了する。
		e->Cancel = true;
	}
}

//OKボタンが押されたときの処理
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	
	//文字列から表に必要な情報を取得するためのクラスをインスタンス化
	Processing^ proc = gcnew Processing(this->JSONFilePath, this->DBQuery);
	//メイン画面の「タテ」テキストボックスの中身を処理のメンバへ格納
	proc->Row = Convert::ToInt32(this->textBoxRow->Text);
	//メイン画面の「ヨコ」テキストボックスの中身を処理のメンバへ格納
	proc->Column = Convert::ToInt32(this->textBoxColumn->Text);

	//JSON文字列の処理を実行
	proc->run();
	
	//取得した表の行数をメンバへ格納
	this->Column = *proc->Column;
	//取得した表の列数をメンバへ格納
	this->Row = *proc->Row;
	//取得した表に出力する文字列をメンバへ格納
	this->TableInfo = proc->retTable;
	//結合判定用の文字列を取得する
	this->join = proc->Join;

	this->TableGenerate(this->pictureBox1);
}

/*関数名：IntToString
  概要：受け取った文字列を整数値に変換して返却する関数
        エラー処理を加えたかったので関数化しています
  引数：String：整数値に変換したい文字列
  戻り値：int：受け取った文字列を整数値に変換した値。
  作成日：2017.8.24
  作成者：K.Asada
  */
private:System::Int32 IntToString(String^ con) {
	//整数値に変換できない文字列が入力されていた時の例外処理
	try{
		//文字列を整数値に変換した値を返却する。
		return Convert::ToInt32(con);
	}
	catch (FormatException^ ex) {
		//変換できないことを伝える。
		throw gcnew Exception("整数値に変換できない文字列です。");
	}
}

/*関数名：initMainForm
  概要：全ての表と値を初期化する処理
  引数：なし
  戻り値：なし
  作成日2017.8.24
  作成者：K.Asada
  */
private:System::Void initMainForm() {
	this->textBoxRow->Text = MyConst->ZERO_STRING;//タテが入力されたテキストボックスを初期化。
	this->textBoxColumn->Text = MyConst->ZERO_STRING;//ヨコが入力されたテキストボックスを初期化。
	this->textBoxRow2->Text = MyConst->ZERO_STRING;//タテが入力されたテキストボックスを初期化。
	this->textBoxColumn2->Text = MyConst->ZERO_STRING;//ヨコが入力されたテキストボックスを初期化。
	this->JSONFilePath = MyConst->EMPTY_STRING;		//JSONの読み込み先のファイルパスを初期化。
	this->DBQuery = MyConst->EMPTY_STRING;			//DBクエリを初期化。
	this->DBResult = MyConst->EMPTY_STRING;			//DBとの通信結果を初期化する。
}

//キャンセルボタンが押されたときの処理
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	//メインフォームに関わるものをすべて初期化する。
	this->initMainForm();
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void buttonConversion_Click(System::Object^  sender, System::EventArgs^  e) {
	Processing^ proc = gcnew Processing();
	proc->retPointTable = this->TableInfo;
	proc->row = this->Row;
	proc->column = this->Column;
	proc->JSONrun();
}
//選択箇所を取得する
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//クリックしたセルの座標を取得する関数を呼び出す
	this->CalPoint(e);
	//テキストボックスを削除する
	this->pictureBox1->Controls->Remove(this->textBoxCell);
	//選択箇所をハイライトする関数を呼び出す
	this->pict(this->pictureBox2);
}
private: System::Void buttonJoin_Click(System::Object^  sender, System::EventArgs^  e) {
	//選択箇所を結合状態にする関数を呼び出す
	this->JoinRelease();
	//表を再描画する
	this->TableGenerate(this->pictureBox1);
	//選択箇所をハイライトする
	this->pict(this->pictureBox2);
}
private: System::Void pictureBox2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//コントロールにテキストボックスを追加する
	this->pictureBox1->Controls->Add(this->textBoxCell);
	//テキストボックスを対象のセルの大きさと同じにする
	this->textBoxCell->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
	//テキストボックスの配置を対象のセルと同じ位置にする
	this->textBoxCell->Location = System::Drawing::Point(0 + *this->RctWidth * *this->ColumnIndex, 0 + *this->RctHeight * *this->RowIndex);
	//テキストボックスを前面に配置する
	this->textBoxCell->BringToFront();
	//テキストボックスへ文字列を配置するためのループ
	for (int i = 0; i < this->TableInfo->Count; i++) {
		if ((this->TableInfo[i]->first->first == "text" || this->TableInfo[i]->first->first == "array") && this->TableInfo[i]->second == ("x" + Convert::ToString(this->ColumnIndex) + Convert::ToString(this->RowIndex))) {
			this->textBoxCell->Text = this->TableInfo[i]->first->second;
			this->Index->Add(i);
			break;
		}
	}
}
private: System::Void textBoxCell_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	//エンターキーが押されたときのイベント
	if (e->KeyCode == Keys::Enter) {
		//テキストボックスに入力された文字列を対象のセルの文字列として格納する
		this->TableInfo[this->Index[0]]->first->second = this->textBoxCell->Text;
		//コントロールからテキストボックスを削除する
		this->pictureBox1->Controls->Remove(this->textBoxCell);
		//書き換えた部分だけ再描画する
		this->ReTable(this->pictureBox1, 0);
		//インデックスを削除する
		this->Index->Clear();
	}
}
private: System::Void textBoxCell_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//値変更画面をインスタンス化
	TableInformation^ tble = gcnew TableInformation(this->TableInfo);
	tble->RowIndex = this->RowIndex;
	tble->ColumnIndex = this->ColumnIndex;
	//画面を表示
	tble->ShowDialog();
}
private: System::Void buttonOK2_Click(System::Object^  sender, System::EventArgs^  e) {
	//文字列から表に必要な情報を取得するためのクラスをインスタンス化
	Processing^ proc = gcnew Processing(this->JSONFilePath, this->DBQuery);
	//メイン画面の「タテ」テキストボックスの中身を処理のメンバへ格納
	proc->Row = Convert::ToInt32(this->textBoxRow->Text);
	//メイン画面の「ヨコ」テキストボックスの中身を処理のメンバへ格納
	proc->Column = Convert::ToInt32(this->textBoxColumn->Text);

	//JSON文字列の処理を実行
	proc->Listrun();

	//取得した表の行数をメンバへ格納
	this->Row = *proc->Row;
	//取得した表の列数をメンバへ格納
	this->Column = *proc->Column;
	//取得した表に出力する文字列をメンバへ格納
	this->TableInfo = proc->retTable;
	//列用にセル一つ値の長さを伸ばす
	this->RctWidth = 1000;
	this->join = proc->Join;
	
	this->TableGenerate(this->pictureBox3);
}
private: System::Void pictureBox4_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//コントロールにテキストボックスを追加する
	this->pictureBox3->Controls->Add(this->textBoxList);
	//テキストボックスを対象のセルの大きさと同じにする
	this->textBoxList->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
	//テキストボックスの配置を対象のセルと同じ位置にする
	this->textBoxList->Location = System::Drawing::Point(0 + *this->RctWidth * *this->ColumnIndex, 0 + *this->RctHeight * *this->RowIndex);
	//テキストボックスを前面に配置する
	this->textBoxList->BringToFront();
	//テキストボックスへ文字列を配置するためのループ
	for (int i = 0; i < this->TableInfo->Count; i++) {
		if ((this->TableInfo[i]->first->first == "text" || this->TableInfo[i]->first->first == "array") && this->TableInfo[i]->second == ("x" + Convert::ToString(this->ColumnIndex) + Convert::ToString(this->RowIndex))) {
			this->textBoxList->Text = this->TableInfo[i]->first->second;
			this->Index->Add(i);
			break;
		}
	}
}
private: System::Void textBoxList_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//値変更画面をインスタンス化
	TableInformation^ tble = gcnew TableInformation(this->TableInfo);
	tble->RowIndex = this->RowIndex;
	tble->ColumnIndex = this->ColumnIndex;
	//画面を表示
	tble->ShowDialog();
}
private: System::Void pictureBox3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//クリックしたセルの座標を取得する関数を呼び出す
	this->CalPoint(e);
	//テキストボックスを削除する
	this->pictureBox3->Controls->Remove(this->textBoxList);
	//選択箇所をハイライトする関数を呼び出す
	this->pict(this->pictureBox4);
	this->pictureBox3->Controls->Add(this->pictureBox4);
}
private: System::Void textBoxList_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	//エンターキーが押されたときのイベント
	if (e->KeyCode == Keys::Enter) {
		//テキストボックスに入力された文字列を対象のセルの文字列として格納する
		this->TableInfo[this->Index[0]]->first->second = this->textBoxList->Text;
		//コントロールからテキストボックスを削除する
		this->pictureBox3->Controls->Remove(this->textBoxList);
		//書き換えた部分だけ再描画する
		this->ReTable(this->pictureBox3, 0);
		//インデックスを削除する
		this->Index->Clear();
	}
}
private: System::Void buttonListConv_Click(System::Object^  sender, System::EventArgs^  e) {
	Processing^ proc = gcnew Processing();
	proc->retPointTable = this->TableInfo;
	proc->row = this->Row;
	proc->column = this->Column;
	proc->JSONrun();
}
private: System::Void buttonConnect_Click(System::Object^  sender, System::EventArgs^  e) {
	//文字列から表に必要な情報を取得するためのクラスをインスタンス化
	Processing^ proc = gcnew Processing(this->JSONFilePath, this->DBQuery);
	//メイン画面の「タテ」テキストボックスの中身を処理のメンバへ格納
	proc->Row = Convert::ToInt32(this->textBoxRow->Text);
	//メイン画面の「ヨコ」テキストボックスの中身を処理のメンバへ格納
	proc->Column = Convert::ToInt32(this->textBoxColumn->Text);

	//JSON文字列の処理を実行
	proc->Queryrun();

	//取得した表の行数をメンバへ格納
	this->Column = *proc->Column;
	System::Windows::Forms::MessageBox::Show(Convert::ToString(this->Column));
	//取得した表の列数をメンバへ格納
	this->Row = *proc->Row;
	System::Windows::Forms::MessageBox::Show(Convert::ToString(this->Row));
	//取得した表に出力する文字列をメンバへ格納
	this->TableInfo = proc->retTable;
	//結合判定用の文字列を取得する
	this->join = proc->Join;

	this->TableGenerate(this->pictureBox1);
}
};
}
