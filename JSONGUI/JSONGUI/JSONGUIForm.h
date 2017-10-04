#pragma once

#include "OptionForm.h"			//設定画面クラスのヘッダ
#include "TableInformation.h"	//表画像関係の関数をまとめたクラスのヘッダ
#include "SelectForm.h"
#include "Processing.h"			//内部処理クラスのヘッダ
#include "MoreInfoForm.h"

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
	public ref class JSONGUIForm
		: public TableInformation
	//	: public System::Windows::Forms::Form
	{
	public:
		JSONGUIForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			this->pictureBoxCurrent->Parent = this->pictureBoxTable;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~JSONGUIForm()
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
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  buttonDeleteColumn;

	private: System::Windows::Forms::Button^  buttonDeleteRow;
	private: System::Windows::Forms::Button^  buttonNewTable;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  labelRow;
	private: System::Windows::Forms::Label^  labelColumn;
	private: System::Windows::Forms::RadioButton^  radioButtonValue;
	private: System::Windows::Forms::RadioButton^  radioButtonKey;
	private: System::Windows::Forms::Button^  buttonEnter;

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
			this->radioButtonValue = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonKey = (gcnew System::Windows::Forms::RadioButton());
			this->labelRow = (gcnew System::Windows::Forms::Label());
			this->labelColumn = (gcnew System::Windows::Forms::Label());
			this->buttonNewTable = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteColumn = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteRow = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->buttonJoin = (gcnew System::Windows::Forms::Button());
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
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->buttonEnter = (gcnew System::Windows::Forms::Button());
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
			this->tabPage->Controls->Add(this->radioButtonValue);
			this->tabPage->Controls->Add(this->radioButtonKey);
			this->tabPage->Controls->Add(this->labelRow);
			this->tabPage->Controls->Add(this->labelColumn);
			this->tabPage->Controls->Add(this->buttonNewTable);
			this->tabPage->Controls->Add(this->buttonDeleteColumn);
			this->tabPage->Controls->Add(this->buttonDeleteRow);
			this->tabPage->Controls->Add(this->button3);
			this->tabPage->Controls->Add(this->button2);
			this->tabPage->Controls->Add(this->button1);
			this->tabPage->Controls->Add(this->buttonTableConv);
			this->tabPage->Controls->Add(this->buttonTableCancel);
			this->tabPage->Controls->Add(this->buttonTableOK);
			this->tabPage->Controls->Add(this->buttonConnect);
			this->tabPage->Controls->Add(this->buttonOption);
			this->tabPage->Controls->Add(this->textBoxRow);
			this->tabPage->Controls->Add(this->textBoxCol);
			this->tabPage->Location = System::Drawing::Point(8, 39);
			this->tabPage->Name = L"tabPage";
			this->tabPage->Padding = System::Windows::Forms::Padding(3);
			this->tabPage->Size = System::Drawing::Size(1444, 822);
			this->tabPage->TabIndex = 0;
			this->tabPage->Text = L"テーブル";
			this->tabPage->UseVisualStyleBackColor = true;
			// 
			// radioButtonValue
			// 
			this->radioButtonValue->AutoSize = true;
			this->radioButtonValue->Location = System::Drawing::Point(434, 80);
			this->radioButtonValue->Name = L"radioButtonValue";
			this->radioButtonValue->Size = System::Drawing::Size(168, 28);
			this->radioButtonValue->TabIndex = 18;
			this->radioButtonValue->TabStop = true;
			this->radioButtonValue->Text = L"値編集モード";
			this->radioButtonValue->UseVisualStyleBackColor = true;
			// 
			// radioButtonKey
			// 
			this->radioButtonKey->AutoSize = true;
			this->radioButtonKey->Location = System::Drawing::Point(207, 80);
			this->radioButtonKey->Name = L"radioButtonKey";
			this->radioButtonKey->Size = System::Drawing::Size(208, 28);
			this->radioButtonKey->TabIndex = 18;
			this->radioButtonKey->TabStop = true;
			this->radioButtonKey->Text = L"キー名編集モード";
			this->radioButtonKey->UseVisualStyleBackColor = true;
			// 
			// labelRow
			// 
			this->labelRow->AutoSize = true;
			this->labelRow->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelRow->Location = System::Drawing::Point(6, 6);
			this->labelRow->Name = L"labelRow";
			this->labelRow->Size = System::Drawing::Size(55, 29);
			this->labelRow->TabIndex = 17;
			this->labelRow->Text = L"タテ";
			// 
			// labelColumn
			// 
			this->labelColumn->AutoSize = true;
			this->labelColumn->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelColumn->Location = System::Drawing::Point(10, 45);
			this->labelColumn->Name = L"labelColumn";
			this->labelColumn->Size = System::Drawing::Size(51, 29);
			this->labelColumn->TabIndex = 17;
			this->labelColumn->Text = L"ヨコ";
			// 
			// buttonNewTable
			// 
			this->buttonNewTable->Location = System::Drawing::Point(906, 6);
			this->buttonNewTable->Name = L"buttonNewTable";
			this->buttonNewTable->Size = System::Drawing::Size(95, 68);
			this->buttonNewTable->TabIndex = 16;
			this->buttonNewTable->Text = L"新規";
			this->buttonNewTable->UseVisualStyleBackColor = true;
			this->buttonNewTable->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonNewTableClick);
			// 
			// buttonDeleteColumn
			// 
			this->buttonDeleteColumn->Location = System::Drawing::Point(334, 6);
			this->buttonDeleteColumn->Name = L"buttonDeleteColumn";
			this->buttonDeleteColumn->Size = System::Drawing::Size(122, 68);
			this->buttonDeleteColumn->TabIndex = 15;
			this->buttonDeleteColumn->Text = L"列削除";
			this->buttonDeleteColumn->UseVisualStyleBackColor = true;
			this->buttonDeleteColumn->Click += gcnew System::EventHandler(this, &JSONGUIForm::DeleteColumnButtonClick);
			// 
			// buttonDeleteRow
			// 
			this->buttonDeleteRow->Location = System::Drawing::Point(202, 6);
			this->buttonDeleteRow->Name = L"buttonDeleteRow";
			this->buttonDeleteRow->Size = System::Drawing::Size(126, 68);
			this->buttonDeleteRow->TabIndex = 14;
			this->buttonDeleteRow->Text = L"行削除";
			this->buttonDeleteRow->UseVisualStyleBackColor = true;
			this->buttonDeleteRow->Click += gcnew System::EventHandler(this, &JSONGUIForm::DeleteRowButtonClick);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(700, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(99, 68);
			this->button3->TabIndex = 13;
			this->button3->Text = L"展開";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonExpansionClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(462, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 68);
			this->button2->TabIndex = 12;
			this->button2->Text = L"行追加";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &JSONGUIForm::AddRowButtonClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(579, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 68);
			this->button1->TabIndex = 11;
			this->button1->Text = L"列追加";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &JSONGUIForm::AddColumnButtonClick);
			// 
			// buttonTableConv
			// 
			this->buttonTableConv->Location = System::Drawing::Point(1220, 6);
			this->buttonTableConv->Name = L"buttonTableConv";
			this->buttonTableConv->Size = System::Drawing::Size(98, 68);
			this->buttonTableConv->TabIndex = 9;
			this->buttonTableConv->Text = L"変換";
			this->buttonTableConv->UseVisualStyleBackColor = true;
			this->buttonTableConv->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableConvClick);
			// 
			// buttonTableCancel
			// 
			this->buttonTableCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonTableCancel->Location = System::Drawing::Point(1323, 6);
			this->buttonTableCancel->Name = L"buttonTableCancel";
			this->buttonTableCancel->Size = System::Drawing::Size(117, 68);
			this->buttonTableCancel->TabIndex = 8;
			this->buttonTableCancel->Text = L"キャンセル";
			this->buttonTableCancel->UseVisualStyleBackColor = true;
			this->buttonTableCancel->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableCancelClick);
			// 
			// buttonTableOK
			// 
			this->buttonTableOK->Location = System::Drawing::Point(1007, 6);
			this->buttonTableOK->Name = L"buttonTableOK";
			this->buttonTableOK->Size = System::Drawing::Size(102, 68);
			this->buttonTableOK->TabIndex = 7;
			this->buttonTableOK->Text = L"読込";
			this->buttonTableOK->UseVisualStyleBackColor = true;
			this->buttonTableOK->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableOKClick);
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(1115, 6);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(99, 68);
			this->buttonConnect->TabIndex = 6;
			this->buttonConnect->Text = L"通信";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonConnectClick);
			// 
			// buttonOption
			// 
			this->buttonOption->Location = System::Drawing::Point(805, 6);
			this->buttonOption->Name = L"buttonOption";
			this->buttonOption->Size = System::Drawing::Size(95, 68);
			this->buttonOption->TabIndex = 5;
			this->buttonOption->Text = L"設定";
			this->buttonOption->UseVisualStyleBackColor = true;
			this->buttonOption->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonOptionClick);
			// 
			// textBoxRow
			// 
			this->textBoxRow->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBoxRow->Location = System::Drawing::Point(73, 0);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(100, 31);
			this->textBoxRow->TabIndex = 1;
			this->textBoxRow->Text = L"0";
			// 
			// textBoxCol
			// 
			this->textBoxCol->Location = System::Drawing::Point(73, 43);
			this->textBoxCol->Name = L"textBoxCol";
			this->textBoxCol->Size = System::Drawing::Size(100, 31);
			this->textBoxCol->TabIndex = 2;
			this->textBoxCol->Text = L"0";
			// 
			// textBoxCell
			// 
			this->textBoxCell->ImeMode = System::Windows::Forms::ImeMode::On;
			this->textBoxCell->Location = System::Drawing::Point(1288, 319);
			this->textBoxCell->Multiline = true;
			this->textBoxCell->Name = L"textBoxCell";
			this->textBoxCell->Size = System::Drawing::Size(100, 70);
			this->textBoxCell->TabIndex = 2;
			this->textBoxCell->DoubleClick += gcnew System::EventHandler(this, &JSONGUIForm::TextBoxCellClick);
			this->textBoxCell->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JSONGUIForm::TextBoxCellEnter);
			this->textBoxCell->Leave += gcnew System::EventHandler(this, &JSONGUIForm::textBoxCell_Leave);
			// 
			// pictureBoxCurrent
			// 
			this->pictureBoxCurrent->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxCurrent->Location = System::Drawing::Point(1289, 356);
			this->pictureBoxCurrent->Name = L"pictureBoxCurrent";
			this->pictureBoxCurrent->Size = System::Drawing::Size(83, 102);
			this->pictureBoxCurrent->TabIndex = 1;
			this->pictureBoxCurrent->TabStop = false;
			this->pictureBoxCurrent->Click += gcnew System::EventHandler(this, &JSONGUIForm::PictureBoxCurrentClick);
			// 
			// pictureBoxTable
			// 
			this->pictureBoxTable->BackColor = System::Drawing::Color::White;
			this->pictureBoxTable->Location = System::Drawing::Point(6, 187);
			this->pictureBoxTable->Name = L"pictureBoxTable";
			this->pictureBoxTable->Size = System::Drawing::Size(647, 424);
			this->pictureBoxTable->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxTable->TabIndex = 0;
			this->pictureBoxTable->TabStop = false;
			this->pictureBoxTable->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONGUIForm::PictureBoxTableMouseClick);
			// 
			// buttonJoin
			// 
			this->buttonJoin->Location = System::Drawing::Point(0, 0);
			this->buttonJoin->Name = L"buttonJoin";
			this->buttonJoin->Size = System::Drawing::Size(75, 23);
			this->buttonJoin->TabIndex = 0;
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
			this->buttonListConv->Click += gcnew System::EventHandler(this, &JSONGUIForm::ListConvClick);
			// 
			// buttonListCancel
			// 
			this->buttonListCancel->Location = System::Drawing::Point(1124, 14);
			this->buttonListCancel->Name = L"buttonListCancel";
			this->buttonListCancel->Size = System::Drawing::Size(146, 68);
			this->buttonListCancel->TabIndex = 18;
			this->buttonListCancel->Text = L"キャンセル";
			this->buttonListCancel->UseVisualStyleBackColor = true;
			this->buttonListCancel->Click += gcnew System::EventHandler(this, &JSONGUIForm::ListCancelClilck);
			// 
			// buttonListOK
			// 
			this->buttonListOK->Location = System::Drawing::Point(972, 14);
			this->buttonListOK->Name = L"buttonListOK";
			this->buttonListOK->Size = System::Drawing::Size(146, 68);
			this->buttonListOK->TabIndex = 17;
			this->buttonListOK->Text = L"OK";
			this->buttonListOK->UseVisualStyleBackColor = true;
			this->buttonListOK->Click += gcnew System::EventHandler(this, &JSONGUIForm::ListOKClick);
			// 
			// buttonListConnect
			// 
			this->buttonListConnect->Location = System::Drawing::Point(828, 14);
			this->buttonListConnect->Name = L"buttonListConnect";
			this->buttonListConnect->Size = System::Drawing::Size(138, 68);
			this->buttonListConnect->TabIndex = 16;
			this->buttonListConnect->Text = L"通信";
			this->buttonListConnect->UseVisualStyleBackColor = true;
			this->buttonListConnect->Click += gcnew System::EventHandler(this, &JSONGUIForm::ListConnectClick);
			// 
			// buttonListOption
			// 
			this->buttonListOption->Location = System::Drawing::Point(664, 14);
			this->buttonListOption->Name = L"buttonListOption";
			this->buttonListOption->Size = System::Drawing::Size(158, 68);
			this->buttonListOption->TabIndex = 15;
			this->buttonListOption->Text = L"設定";
			this->buttonListOption->UseVisualStyleBackColor = true;
			this->buttonListOption->Click += gcnew System::EventHandler(this, &JSONGUIForm::ListOptionClick);
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
			this->textBoxList->DoubleClick += gcnew System::EventHandler(this, &JSONGUIForm::TextBoxListClick);
			// 
			// pictureBoxListCurr
			// 
			this->pictureBoxListCurr->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxListCurr->Location = System::Drawing::Point(1238, 433);
			this->pictureBoxListCurr->Name = L"pictureBoxListCurr";
			this->pictureBoxListCurr->Size = System::Drawing::Size(83, 102);
			this->pictureBoxListCurr->TabIndex = 12;
			this->pictureBoxListCurr->TabStop = false;
			this->pictureBoxListCurr->Click += gcnew System::EventHandler(this, &JSONGUIForm::PictureBoxListCurrClick);
			// 
			// pictureBoxList
			// 
			this->pictureBoxList->Location = System::Drawing::Point(22, 385);
			this->pictureBoxList->Name = L"pictureBoxList";
			this->pictureBoxList->Size = System::Drawing::Size(647, 424);
			this->pictureBoxList->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxList->TabIndex = 11;
			this->pictureBoxList->TabStop = false;
			this->pictureBoxList->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONGUIForm::PictureBoxListMouseClick);
			// 
			// buttonEnter
			// 
			this->buttonEnter->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonEnter->Location = System::Drawing::Point(1195, 225);
			this->buttonEnter->Name = L"buttonEnter";
			this->buttonEnter->Size = System::Drawing::Size(100, 64);
			this->buttonEnter->TabIndex = 19;
			this->buttonEnter->Text = L"OK";
			this->buttonEnter->UseVisualStyleBackColor = true;
			this->buttonEnter->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonEnterClick);
			// 
			// JSONGUIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1460, 869);
			this->Controls->Add(this->tabControl1);
			this->Name = L"JSONGUIForm";
			this->Text = L"JSONGUI";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JSONGUIForm::FormClosings);
			this->Load += gcnew System::EventHandler(this, &JSONGUIForm::JSONGUI_Load);
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



/*概要：メイン画面ロード時の初期化イベント、再帰にも使うので分岐する
作成日：2017.9.30
作成者：K.ASada*/
private: System::Void JSONGUI_Load(System::Object^  sender, System::EventArgs^  e) {
	//メッセージを表示するための例外処理
	try {
		//展開動作のために再帰してきたときに分岐させる
		if (this->TableElem != nullptr) {
			//展開先に入力確定ボタンを追加する
			this->tabPage->Controls->Add(this->buttonEnter);
			//サイズを設定ボタンに合わせる
			this->buttonEnter->Size = this->buttonOption->Size;
			//確定ボタンの位置を設定ボタンの位置にする
			this->buttonEnter->Location = this->buttonOption->Location;
			//位置を新規ボタンの位置に設定する
			this->buttonTableCancel->Location = this->buttonNewTable->Location;
			//展開先にて読込ボタンは不要なので削除する
			this->tabPage->Controls->Remove(this->buttonTableOK);
			//展開先にて通信ボタンは不要なので削除する
			this->tabPage->Controls->Remove(this->buttonConnect);
			//展開先にて設定ボタンは不要なので削除する
			this->tabPage->Controls->Remove(this->buttonOption);
			//展開先にて新規ボタンは不要なので削除する
			this->tabPage->Controls->Remove(this->buttonNewTable);
			//展開先にて変換ボタンは不要なので削除する
			this->tabPage->Controls->Remove(this->buttonTableConv);
			//展開先にてキャンセルボタンのイベントを削除する
			this->buttonTableCancel->Click -= gcnew System::EventHandler(this, &JSONGUIForm::TableCancelClick);
			//キャンセルボタンに新たに入力キャンセルイベントを紐づける
			this->buttonTableCancel->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonExpansionCancel);
			//フォームを閉じるときのイベントを削除する
			this->FormClosing -= gcnew System::Windows::Forms::FormClosingEventHandler(this, &JSONGUIForm::FormClosings);
			//表画像を生成するための準備関数を呼び出す
			this->ReadyPict(this->TableElem);
			//表画像を生成する関数を呼び出す
			this->TableGenerate(this->pictureBoxTable);
			//コントロールへピクチャボックスを追加する
			this->tabPage->Controls->Add(this->pictureBoxTable);
			//表画像が埋もれていることがあるので前面に押し出す
			this->pictureBoxTable->BringToFront();
		}
		return;
	}
	//全ての例外を捕捉する
	catch (System::Exception^ e) {
		//処理が中断された旨を表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：テーブルタブの設定ボタンクリック時のイベント、設定画面を開く
引数：Sender：クリック時のフォームの情報が格納されたオブジェクトクラス
	：EventArgs：クリック時のマウス関係の情報が格納されたイベントクラス
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: System::Void ButtonOptionClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中に発生したすべてのエラーをキャッチする
	try {
		//設定画面を開く関数を呼び出す
		this->ShowOptionForm();
	}
	catch (System::Exception^ e) {
		//エラーが発生して処理が中断されたことを知らせる
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：プログラム終了時のイベント、終了するどうかの確認を行う。
引数：
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: System::Void FormClosings(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//閉じるときにテキストボックスの中身を構造体に保持させるためにフォーカスを外す
	this->ActiveControl = nullptr;
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
作成者：K.Asada
更新日：2017.10.2
更新者：K.Asada
更新内容：削除するコントロールが間違っていたので修正*/
private: Void TableInit() {
	//基底クラスの初期化関数を呼び出す
	this->InfoInit();
	//選択箇所をハイライトする画像をコントロールから除外する
	this->pictureBoxTable->Controls->Remove(this->pictureBoxCurrent);
	//表画像上のテキストボックスをコントロールから除外する
	this->pictureBoxTable->Controls->Remove(this->textBoxCell);
	//表画像をコントロールから除外する
	this->tabPage->Controls->Remove(this->pictureBoxTable);
	//行数が入力されたテキストボックスを初期化する
	this->textBoxRow->Text = Constants->INITIAL_ROW_STRING;
	//列数が入力されたテキストボックスを初期化する
	this->textBoxCol->Text = Constants->INITIAL_COLUMN_STRING;
	//初期化完了
	return;
}

/*概要：テーブルタブのキャンセルボタンクリック時のイベント、テーブルタブに関する情報を初期化する関数を呼び出す
引数：
戻り値：なし
作成日：2017.9.20
作成者：K.Asada*/
private: System::Void TableCancelClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中のエラーと拾うための例外処理
	try {
		//テーブルタブに関する情報を初期化する関数を呼び出す
		this->TableInit();
		//初期化されたことを表示する
		MessageBox::Show(Constants->INITIAL_STRING);
	}
	//処理中のすべての例外を捕捉する
	catch (System::Exception^ e) {
		//何らかのエラーが発生して処理が中断されたことを知らせる
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：通信ボタンのクリックイベント、DBクエリ処理関数を呼び出す
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada
更新日：2017.10.2
更新者：K.Asada
更新内容：生成した表画像の追加先となるコントロールが間違っていたので修正*/
private: System::Void ButtonConnectClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中のエラーを捕捉するための例外処理
	try {
		//内部処理クラスをインスタンス化
		process::Processing^ proc = gcnew process::Processing();
		//DBの内部処理関数を呼び出す
		proc->DBrun(this->DBQuery);
		//取得した構造体をメンバへ格納する
		this->TableElem = proc->Tablechain;
		//表画像を生成するための準備関数を呼び出す
		this->ReadyPict(this->TableElem);
		//表画像を生成する関数を呼び出す
		this->CreateTablePict(this->pictureBoxTable);
		//コントロールへがピクチャボックスを追加する
		this->tabPage->Controls->Add(this->pictureBoxTable);
		//表画像が埋もれていることがあるためピクチャボックスを前面に押し出す
		this->pictureBoxTable->BringToFront();
		//DBとの通信を行った結果を出力
		MessageBox::Show(Constants->DB_STRING);
	}
	//エラーが発生して処理が中断されたことを表示する
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：テーブルタブのOKボタンクリックイベント、内部処理クラスへ移行する
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada
更新日：2017.10.2
更新者：K.Asada
更新内容：生成した表画像の追加先となるコントロールが間違っていたので修正*/
private: System::Void TableOKClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中のエラーを捕捉するための例外処理
	try {
		//内部処理クラスをインスタンス化
		process::Processing^ proc = gcnew process::Processing();
		//JSONをチェイン構造に変換する関数を呼び出す
		proc->Tablerun(this->JSONFilePath);
		//構造体をメンバへ格納する
		this->TableElem = %*proc->Tablechain;
		//表画像を生成するための準備関数を呼び出す
		this->ReadyPict(this->TableElem);
		//表画像を生成する関数を呼び出す
		this->CreateTablePict(this->pictureBoxTable);
		//コントロールへピクチャボックスを追加する
		this->tabPage->Controls->Add(this->pictureBoxTable);
		//表画像が埋もれないように前面に移動させる
		this->pictureBoxTable->BringToFront();
		//JSONを読み込んだことを表示する
		MessageBox::Show(Constants->LOAD_STRING);
	}
	//全てのエラーを捕捉処理が中断されたことを表示するための補足
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：テーブルタブの変換ボタンクリック時のイベント
作成日：201.9.21
作成者：K.Asada*/
private: System::Void TableConvClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中の例外を捕捉してメッセージを表示するための例外処理
	try {
		//JSONファイルの保存先を保管する文字列
		String^ outJSONpath = Constants->EMPTY_STRING;
		//内部処理クラスをインスタンス化
		process::Processing^ proc = gcnew process::Processing();
		//保存先を選択させるメッセージを表示する
		MessageBox::Show(Constants->OUT_PATH_MESSAGE);
		//JSONファイルの保存先を選択するダイアログを表示する
		if (this->saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//OKボタンが押されたらファイルの出力先を保管する
			outJSONpath = this->saveFileDialog1->FileName;
		}
		else{
			//操作が中断された旨を表示する
			MessageBox::Show(Constants->CANCEL_STRING);
			//何もせずにダイアログを閉じる
			return;
		}
		//JSONに変換する関数を呼び出す
		proc->Convertrun(outJSONpath, this->TableElem);
		//変換が完了した旨を表示する
		MessageBox::Show(Constants->SUCCES_STRING);
		//変換完了
		return;
	}
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
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
	this->textBoxList->Text = Constants->INITIAL_ROW_STRING;
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
	//処理中のエラー捕捉するための例外処理
	try {
		//内部処理クラスをインスタンス化
		process::Processing^ proc = gcnew process::Processing();
		//内部処理関数を呼び出す
		proc->Listrun(this->JSONFilePath);
		//取得した構造体をメンバへ格納する
		this->TableElem = %*proc->Tablechain;
		//表画像を生成するための準備関数を呼び出す
		this->ReadyPict(this->TableElem);
		//表画像生成関数を呼び出す
		this->CreateTablePict(this->pictureBoxList);
		//作成した画像をコントロールへ追加する
		this->Controls->Add(this->pictureBoxList);
		//表画像が埋もれていることがあるためピクチャボックスを前面に押し出す
		this->pictureBoxList->BringToFront();
	}
	//例外を捕捉したら処理が中断された旨を表示する
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：リストタブのキャンセルボタンクリックイベント、初期化関数を呼び出す
引数：
戻り値：
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void ListCancelClilck(System::Object^  sender, System::EventArgs^  e) {
	//処理中のエラーを拾うための例外処理
	try {
		//初期化関数を呼び出す
		this->ListInit();
		//初期化完了
		return;
	}
	//全てのエラーを捕捉して警告を出すための例外
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void ListConvClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中の例外を捕捉してメッセージを表示するための例外処理
	try {
		//内部処理クラスをインスタンス化
		process::Processing^ proc = gcnew process::Processing();
		//文字列構造体を渡す
		proc->Tablechain = this->TableElem;
		//JSONに変換する関数を呼び出す
		proc->Convertrun("aaa", this->TableElem);
		//変換完了
		return;
	}
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void ListConnectClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中のエラーを捕捉するための例外処理
	try {
		//内部処理クラスをインスタンス化
		process::Processing^ proc = gcnew process::Processing();
		//DBの内部処理関数を呼び出す
		proc->DBrun(this->DBQuery);
		//取得した構造体をメンバへ格納する
		this->TableElem = proc->Tablechain;
		//表画像を生成するための準備関数を呼び出す
		this->ReadyPict(this->TableElem);
		//表画像を生成する関数を呼び出す
		this->CreateTablePict(this->pictureBoxList);
		//コントロールへがピクチャボックスを追加する
		this->Controls->Add(this->pictureBoxList);
		//表画像が埋もれていることがあるためピクチャボックスを前面に押し出す
		this->pictureBoxList->BringToFront();
	}
	//エラーが発生して処理が中断されたことを表示する
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void ListOptionClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中に発生したすべてのエラーをキャッチする
	try {
		//設定画面を開く関数を呼び出す
		this->ShowOptionForm();
	}
	catch (System::Exception^ e) {
		//エラーが発生して処理が中断されたことを知らせる
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*表画像上をクリックしたときのイベント、選択状態にする関数を呼び出す
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada
更新内容：既に選択状態になっている場所以外をクリックしたときにテキストボックスが表示されていたら消えるように変更
更新日：2017.9.30
更新者：K.Asada*/
private: System::Void PictureBoxTableMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//メッセージを表示するための例外処理
	try {
		//テキストボックスからフォーカスを外し、イベントを発生させる
		this->ActiveControl = nullptr;
		//選択状態を保持するためにクリックした表画像上の座標をメンバへ保存する関数を呼び出す
		this->GetCellPoint(e);
		//選択箇所がわかりやすいようにハイライトする関数を呼び出す
		this->SelecteCell(this->pictureBoxCurrent);
		//ハイライト画像をコントロールへ追加する
		this->pictureBoxTable->Controls->Add(this->pictureBoxCurrent);
		//画像を前面に押し出す
		this->pictureBoxCurrent->BringToFront();
		return;
	}
	//全ての例外を捕捉する
	catch (System::Exception^ e) {
		//処理が中断された旨を表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
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
	this->pictureBoxList->Controls->Add(this->pictureBoxListCurr);
	//埋もれていることがあるため前面に押し出す
	this->pictureBoxListCurr->BringToFront();
	return;
}

/*概要：表画像のハイライトされている箇所をクリックしたときのイベント、テキストボックスを配置して編集可能状態にする
引数：
戻り値：なし
作成日：2017.9.20
作成者：K.Asada
更新日：2017.10.2
更新者：K.Asada
更新内容：キー名/値編集モードに対応したデータをテキストボックスに表示するように変更、テキストボックスが表示されたときにカーソルが末尾に来るように変更*/
private: System::Void PictureBoxCurrentClick(System::Object^  sender, System::EventArgs^  e) {
	//メッセージを表示するための例外処理
	try {
		//テキストボックスに情報を設定する関数を呼び出す
		this->CellTextGenerate(this->textBoxCell, this->radioButtonKey->Checked, this->radioButtonValue->Checked);
		//生成したテキストボックスをメイン画面のコントロールに乗せる
		this->pictureBoxTable->Controls->Add(this->textBoxCell);
		//テキストボックスが埋もれないように前面に配置する
		this->textBoxCell->BringToFront();
		//テキストボックスの末尾にカーソルを移動する
		this->textBoxCell->SelectionStart = this->textBoxCell->Text->Length;
		//カーソルを表示するためにテキストボックスにフォーカスる
		this->textBoxCell->Focus();
		return;
	}
	//全ての例外を捕捉する
	catch (System::Exception^ e) {
		//処理が中断された旨を表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：リストタブの画像のハイライト部分をクリックしたときのイベント、編集用のテキストボックスを表示
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void PictureBoxListCurrClick(System::Object^  sender, System::EventArgs^  e) {
	//テキストボックスを配置するための情報を設定する関数を呼び出す
	this->CellTextGenerate(this->textBoxList, this->radioButtonKey->Checked, this->radioButtonValue->Checked);
	//情報が設定されたテキストボックスをコントロールに追加して表示する
	this->pictureBoxListCurr->Controls->Add(this->textBoxList);
	//テキストボックスを前面に押し出す
	this->textBoxList->BringToFront();
}

/*概要：表画像の値編集用のテキストボックスがダブルクリックされたときのイベント
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada*/
private: System::Void TextBoxListClick(System::Object^  sender, System::EventArgs^  e) {

}

/*概要：表画像の値編集用のテキストボックスがダブルクリックされたときのイベント
引数：
戻り値：なし
作成日：2017.9.21
作成者：K.Asada
更新内容：キャンセルされたときには構造体を更新しないように変更
更新日：2017.10.3
更新者：K.Asada*/
private: System::Void TextBoxCellClick(System::Object^  sender, System::EventArgs^  e) {
try{
	MoreInfoForm^ more = gcnew MoreInfoForm();			//クリックしたセルの親キーを編集するための詳細画面クラスをインスタンス化
	CellDataChain::cellchain^ child = nullptr;				//詳細ダイアログへ渡す構造体を宣言
	CellDataChain::cellchain^ copy = nullptr;				//メンバの構造体をコピーするための構造体
	//構造体操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//メンバの構造体が更新されないようにいったんコピーする
	copy = CellCtrl->CopyChain(this->TableElem);
	//渡す構造体をコピーから取得する
	child = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, copy->lower);
	//nullptrを取得した場合対象の位置に新規で構造体を作成して連結する
	if (child == nullptr) {
		//対象の位置の構造体に文字列を挿入する関数を呼び出す
		child = CellCtrl->SetChainCell(*this->RowIndex, *this->ColumnIndex, Constants->EMPTY_STRING, copy, false, false);
	}//正常に情報を取得できていた場合は詳細ダイアログを表示
	//詳細ダイアログへ構造体を渡す
	more->TableElem = child;
	//新規ダイアログで表示する
	more->ShowDialog();
	//OKボタンが押されていたら確定
	if (more->DialogResult == System::Windows::Forms::DialogResult::OK) {
		//コピーしていた構造体をもとの構造体に代入して更新を行う
		this->TableElem = copy;
		//終わったら表画像を再描画する
		this->ReadyPict(this->TableElem);
		//表画像を再描画する
		this->CreateTablePict(this->pictureBoxTable);
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

/*行追加ボタンのクリックイベント、表画像に行を挿入する
作成日：2017.9.25
作成者：K.Asada
更新内容：行を挿入する方向を選択させる機能を追加
更新日：2017.9.28
更新者：K.Asada
更新内容：文字列を定数化
更新日：2017.10.2
更新者：K.Asada*/
private: System::Void AddRowButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//例外をメイン画面でも捕捉するために例外処理
	try {
		//表が存在していないときは対象が存在していないとして例外を送出
		if (*this->Column <= 0 || *this->Row <= 0) {
			//コンソールにエラー内容を表示する
			Console::WriteLine(Constants->NOT_FOUND_ERROR);
			//対象が存在していないとして例外を送出
			throw gcnew System::FormatException(Constants->NOT_FOUND_ERROR);
		}
		//選択画面フォームをインスタンス化
		SelectForm^ sele = gcnew SelectForm();
		String^ select = Constants->EMPTY_STRING;		//選択画面にて選択したボタンの名前を取得するための文字列
		//選択画面のボタンに表示する文字を渡す
		sele->ElderButton->Text = Constants->TOP_STRING;
		//選択画面のボタンに表示する文字を渡す
		sele->YoungButton->Text = Constants->UNDER_STRING;
		//選択画面を表示する
		sele->ShowDialog();
		//選択されたボタンの名前を取得する
		select = sele->selectbutton;
		//先頭より先に行を追加しようとしたときは追加しない
		if (*this->RowIndex <= 0 && select == Constants->ELDER_BUTTON_STRING) {
			//先頭より先には追加できない旨を表示
			MessageBox::Show(Constants->ADD_ERROR_STRING);
		}
		//キャンセルボタン以外なら追加処理を実行
		else if (select != Constants->CANCEL_BUTTON_STRING) {
			//行を挿入する関数を呼び出す
			this->RowAdd(*this->RowIndex, select);
			//行数を追加する
			this->textBoxRow->Text = Convert::ToString(Convert::ToInt32(this->textBoxRow->Text) + 1);
			//行を追加したため表を再描画したいので準備を行う
			this->ReadyPict(this->TableElem);
			//行を挿入した後の表画像を再描画する関数を呼び出す
			this->CreateTablePict(this->pictureBoxTable);
		}//キャンセルボタンなら追加処理を中断する
		else {
			//中断する旨を画面上に出力する
			MessageBox::Show(Constants->CANCEL_STRING);
		}
		return;
	}
	//全ての例外を捕捉する
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断された旨を表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*列追加ボタンのクリックイベント、表に列を挿入する
作成日：2017.9.25
作成者：K.Asada
更新内容：列を追加する方向の選択をさせる機能を追加
更新日：2017.9.28
作成者：K.Asada
更新内容：文字列を定数化、表が存在していないときに例外を送出
更新日：2017.10.2
更新者：K.Asada*/
private: System::Void AddColumnButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//例外が来たときに警告を表示するためにすべての例外処理
	try {
		//表が存在していないときは対象が存在していないとして例外を送出
		if (*this->Column <= 0 || *this->Row <= 0) {
			//コンソールにエラー内容を表示する
			Console::WriteLine(Constants->NOT_FOUND_ERROR);
			//対象が存在していないとして例外を送出
			throw gcnew System::FormatException(Constants->NOT_FOUND_ERROR);
		}
		//選択画面フォームをインスタンス化
		SelectForm^ sele = gcnew SelectForm();
		String^ select = "";		//選択画面にて選択したボタンの名前を取得するための文字列
		//選択画面のボタンに表示する文字を渡す
		sele->ElderButton->Text = Constants->LEFT_STRING;
		//選択画面のボタンに表示する文字を渡す
		sele->YoungButton->Text = Constants->RIGHT_STRING;
		//選択画面を表示する
		sele->ShowDialog();
		//選択されたボタンの名前を取得する
		select = sele->selectbutton;
		//先頭より左に列を追加しようとしているときは追加できないようにする
		if (*this->ColumnIndex <= 0 && select == Constants->ELDER_BUTTON_STRING) {
			//先頭より左に列を追加できない旨を表示
			MessageBox::Show(Constants->ADD_ERROR_STRING);
		}
		//キャンセル以外なら処理を実行する
		else if (select != Constants->CANCEL_BUTTON_STRING) {
			//列数をプラスする
			this->textBoxCol->Text = Convert::ToString(Convert::ToInt32(this->textBoxCol->Text) + 1);
			//列を挿入する関数を呼び出す
			this->ColumnAdd(*this->Row, *this->ColumnIndex, select);
			//列を追加したため表を再描画したいので準備を行う
			this->ReadyPict(this->TableElem);
			//列を挿入した後の表を再描画
			this->CreateTablePict(this->pictureBoxTable);
		}//キャンセルボタンが押されていたら処理を中断する
		else {
			MessageBox::Show(Constants->CANCEL_STRING);
		}
		return;
	}
	//全ての例外を捕捉
	catch (System::Exception^ e) {
		//なんらかのエラーが起きて操作が中断された旨を表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：値編集用のテキストボックス内でエンターキーが押されたときのイベント
作成日：2017.9.25
作成者：K.Asada
更新内容：エンターキーが押されたときにテキストボックスが消えるように変更
更新日：2017.9.30
更新者：K.Asada
更新日：2017.10.2
更新者：K.Asada
更新内容：キー名/値編集モードに対応した文字列を編集するように変更*/
private: System::Void TextBoxCellEnter(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	try {	
		//エンターキーが押されたときのイベント
		if (e->KeyCode == Keys::Enter) {
			//Focusleaveイベントを発生させるためにアクティブを無にする
			this->ActiveControl = nullptr;
		}
	}
	catch (System::NullReferenceException^ e) {
		System::Console::WriteLine(e);
	}
	catch (System::ArgumentNullException^ e) {
		System::Console::WriteLine(e);
	}
}

/*概要：展開ボタンクリック時のイベント
引数：なし
戻り値：なし
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void ButtonExpansionClick(System::Object^  sender, System::EventArgs^  e) {
	//処理中のエラーを拾うための例外処理
	try {
		//展開した画像を生成して新規ダイアログに表示する関数を呼び出す
		this->Expansion();
		return;
	}
	//全てのエラーを捕捉してエラーメッセージを表示するための補足
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：親キーについてJSONを展開した表画像を生成する関数
引数：なし
戻り値：なし
作成日：2017.9.25
作成者：K.Asada
更新内容：分岐の条件が間違っていたので修正
更新日：2017.10.4
更新者：K.Asada*/
 private:Void Expansion() {
	 //構造体の走査中に発生したnullptrの例外処理
	 try{
	 CellDataChain^ CellCtrl = gcnew CellDataChain();	 //チェイン構造操作クラスをインスタンス化
	 JSONGUIForm^ more = gcnew JSONGUIForm();			 //表画像を表示するためのクラスをインスタンス化
	 CellDataChain::cellchain^ detailtable = nullptr;	 //表示する構造体を取得して格納するための構造体
	 CellDataChain::cellchain^ copy = nullptr;			//元の構造体が更新されないようにコピーするための構造体
	 //構造体の内容を変更するのでいったんコピーを取る
	 copy = CellCtrl->CopyChain(this->TableElem);
	 //構造体を取得する
	 detailtable = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, copy->lower);
	 //展開すべき構造体が存在していれば展開ダイアログを開く
	 if (detailtable != nullptr && detailtable->lower != nullptr) {
		 //新規に開くダイアログの初期値として構造体を設定
		 more->TableElem = detailtable;
		 //ダイアログを開く
		 more->ShowDialog();
		 //OKボタンが押されていたら構造体の更新を行う
		 if (more->DialogResult == System::Windows::Forms::DialogResult::OK) {
			//構造体の更新を行う
			 this->TableElem = copy;
			 //終わったら表画像を再描画する
			 this->ReadyPict(this->TableElem);
			 //表画像を再描画する
			 this->CreateTablePict(this->pictureBoxTable);
		 }
	 }
	 else {
		 //展開すべき情報がないことを表示する
		 MessageBox::Show(Constants->EXPANSION_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK);
	 }
	 return;
	 }
	 //nullが参照されたらエラー内容をコンソールに出力する
	 catch (System::NullReferenceException^ e) {
		 //null関係のエラーをコンソールに表示する
		 System::Console::WriteLine(e);
	 }
	 //nullが参照されたらエラー内容をコンソールに表示する
	 catch (System::ArgumentNullException^ e) {
		 //null関係のエラーをコンソールに表示する
		 System::Console::WriteLine(e);
	 }//ReadyPictないで発生した例外を捕捉
	 catch (System::FormatException^ e) {
		 //例外をメイン画面へ再送出する
		 throw e;
	 }
}


		 /*概要：表画像を生成するための準備の関数、列数、行数を取得する
		 引数：cellchain^ tablechain：表画像に変換する予定の構造体
		 戻り値：なし
		 作成日：2017.9.25
		 作成者：K.Asada
		 更新日：2017.10.2
		 更新者：K.Asada
		 更新内容：行数と列数のどちらかが0であればエラーを送出するように変更*/
		 Void ReadyPict(CellDataChain::cellchain^ tablechain) {
			 //入力情報が正しいかどうかを捕捉するための例外処理
			 try {
				 //渡した構造体をもとに行数と列数を割り出す関数を呼び出す
				 this->CountRow(tablechain->lower);
				 //画面上のテキストボックスの値との比較を行う
				 if (*this->Row < Convert::ToInt32(this->textBoxRow->Text)) {
					 //大きい方を採用する
					 this->Row = Convert::ToInt32(this->textBoxRow->Text);
				 }
				 else {
					 //現在表示している表の行数としてテキストボックスに格納する
					 this->textBoxRow->Text = Convert::ToString(*this->Row);
				 }
				 //画面上のテキストボックスの値との比較を行う
				 if (*this->Column < Convert::ToInt32(this->textBoxCol->Text)) {
					 //大きい方を採用する
					 this->Column = Convert::ToInt32(this->textBoxCol->Text);
				 }
				 else {
					 //現在表示している表の行数としてテキストボックスに格納する
					 this->textBoxCol->Text = Convert::ToString(*this->Column);
				 }
				 //行数と列数のいずれかが0であれば表として成り立たないのでエラーを投げる
				 if (*this->Row <= 0 || *this->Column <= 0) {
					 throw(gcnew System::FormatException());
				 }
				 return;
			 }
			 //テキストボックスの入力内容が正しくなかったときに捕捉
			 catch (System::FormatException^ e) {
				 //入力内容がおかしい旨をコンソールに表示する
				 System::Console::WriteLine(Constants->INPUT_ERROR_STRING + e);
				 throw e;
			 }
		 }

/*概要：列削除ボタンのクリックイベント
作成日2017.9.29
作成者：K.Asada
更新内容：先頭の列は削除できないように分岐を追加
更新日：2017.9.30
作成者：K.Asada*/
private: System::Void DeleteColumnButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//全ての例外を捕捉したらメイン画面側で警告を表示するための例外処理
	try {
		//表が存在していないときは対象が存在していないとして例外を送出
		if (*this->Column <= 0 || *this->Row <= 0) {
			//コンソールにエラー内容を表示する
			Console::WriteLine(Constants->NOT_FOUND_ERROR);
			//対象が存在していないとして例外を送出
			throw gcnew System::FormatException(Constants->NOT_FOUND_ERROR);
		}
		//削除対象が先頭の列の場合は親を削除することになるので削除しない
		if (*this->ColumnIndex > 0) {
			//指定した列を削除する関数を呼び出す
			this->ColumnDelete(*this->Row, *this->ColumnIndex);
			//列数を減らす
			this->textBoxCol->Text = Convert::ToString(Convert::ToInt32(this->textBoxCol->Text) - 1);
			//表の内容が変更されているため再描画する準備を行う
			this->ReadyPict(this->TableElem);
			//表全体を再描画する
			this->CreateTablePict(this->pictureBoxTable);
		}
		//先頭列は削除しない
		else {
			//削除できない旨を伝える
			MessageBox::Show(Constants->DELETE_ERROR_STRING);
		}
		return;
	}
	//全ての例外を捕捉する
	catch (System::Exception^ e) {
		//メイン画面で警告を表示する、エラー内容はコンソールに表示
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：行削除ボタンのクリックイベント
作成日：2017.9.29
作成者：K.Asada
更新内容：1行しかないときは削除できないように変更
更新日：2017.9.30
更新者：K.Asada*/
private: System::Void DeleteRowButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//全ての例外に対してメイン画面で警告を表示するように例外処理
	try {
		//表が存在していないときは対象が存在していないとして例外を送出
		if (*this->Column <= 0 || *this->Row <= 0) {
			//コンソールにエラー内容を表示する
			Console::WriteLine(Constants->NOT_FOUND_ERROR);
			//対象が存在していないとして例外を送出
			throw gcnew System::FormatException(Constants->NOT_FOUND_ERROR);
		}
		//行が1行以上の時のみ削除に移る
		if (*this->Row > 1) {
			//指定した行を削除する関数を呼び出す
			this->RowDelete(*this->RowIndex);
			//行数を減らす
			this->textBoxRow->Text = Convert::ToString(Convert::ToInt32(this->textBoxRow->Text) - 1);
			//表の内容が変更されているため再描画する準備を行う
			this->ReadyPict(this->TableElem);
			//表全体を再描画する
			this->CreateTablePict(this->pictureBoxTable);
		}
		//1行しかないときは削除できない旨を表示
		else {
			MessageBox::Show(Constants->DELETE_ERROR_STRING);
		}
		return;
	}
	//全ての例外を捕捉
	catch (System::Exception^ e) {
		//エラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：新規ボタンのクリックイベント、新規に表画像を作成する
作成日：2017.9.30
作成者：K.Asada
更新日：2017.10.2
更新者：K.Asada
更新内容：生成後の表画像のコントロール追加先が間違っていたので修正*/
private: System::Void ButtonNewTableClick(System::Object^  sender, System::EventArgs^  e) {
	//全ての例外でメイン画面側で警告を出したいので例外処理
	try {
		MoreInfoForm^ more = gcnew MoreInfoForm();			//詳細情報編集クラスをインスタンス化
		CellDataChain^ CellCtrl = gcnew CellDataChain();	//構造体操作クラスをインスタンス化
		//新規でもっとも親となる空の構造体を一つ作成してメンバに格納
		this->TableElem = CellCtrl->ChainParent(Constants->CHAIN_KEY_STRING, Constants->CHAIN_VALUE_STRING, nullptr);
		//列数と行数を取得する関数を呼び出す
		this->ReadyPict(this->TableElem);
		//新規で表をJSONを生成する際に必要な情報の入力を促す
		MessageBox::Show(Constants->NEW_STRING);
		//先ほど生成した空の構造体の詳細情報を入力させるために詳細画面へ渡す
		more->TableElem = this->TableElem;
		//詳細画面を開いて編集を行う
		more->ShowDialog();
		//表画像の描画を行う
		this->CreateTablePict(this->pictureBoxTable);
		//コントロールにピクチャボックスを追加する
		this->tabPage->Controls->Add(this->pictureBoxTable);
		//表画像が埋もれていることがあるので前面に押し出す
		this->pictureBoxTable->BringToFront();
		//表が生成されたことを出力する
		MessageBox::Show(Constants->TABLE_STRING);
		return;
	}
	//全ての例外を捕捉
	catch (System::Exception^ e) {
		//なんらかのエラーが発生して処理が中断されたことを表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void textBoxCell_Leave(System::Object^  sender, System::EventArgs^  e) {
	//メッセージを表示するための例外処理
	try {
		//チェイン構造操作クラスをインスタンス化
		CellDataChain^ CellCtrl = gcnew CellDataChain();
		Int32 rowindex = *this->RowIndex;		//編集する構造体を指定するために座標を取得
		Int32 colindex = *this->ColumnIndex;	//編集する構造体を指定するために座標を取得
		String^ data = this->textBoxCell->Text;	//構造体んい渡すための文字列をテキストボックスより取得
		//テキストボックスの中身が空文字でない場合のみ更新を行う
		if (data != Constants->EMPTY_STRING) {
			//対象の位置の構造体に文字列を挿入する関数を呼び出す
			CellCtrl->SetChainCell(rowindex, colindex, data, this->TableElem, this->radioButtonKey->Checked, this->radioButtonValue->Checked);
			//セルの再描画を行う
			this->CreateTablePict(this->pictureBoxTable);
			this->pictureBoxTable->Location = System::Drawing::Point((Constants->TABLE_LOCATION.X + this->tabPage->AutoScrollPosition.X), (Constants->TABLE_LOCATION.Y + this->tabPage->AutoScrollPosition.Y));
		}
		//テキストボックスを表示から外す
		this->pictureBoxTable->Controls->Remove(this->textBoxCell);
	}
	//全ての例外を捕捉する
	catch (System::Exception^ e) {
		//処理が中断された旨を表示する
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*概要：展開先ダイアログにて使用する入力確定イベント
作成日：2017.10.3
作成者：K.Asada*/
private: System::Void ButtonEnterClick(System::Object^  sender, System::EventArgs^  e) {
	//開いているダイアログを閉じる
	this->Close();
	return;
}

/*概要：展開先ダイアログにて使用する入力キャンセルイベント
作成日：2017.10.3
作成者：K.Asada*/
private: System::Void ButtonExpansionCancel(System::Object^  sender, System::EventArgs^  e) {
	//開いているダイアログを閉じる
	this->Close();
	return;
}

/*概要：表画像の生成に関わる関数をまとめて呼び出す関数
作成日：2017.10.4
作成者：K.Asada*/
private: System::Void CreateTablePict(PictureBox^ pict) {
	//表画像を生成する関数を呼び出す
	this->TableGenerate(pict);
	//表の座標などを設定する関数を呼び出す
	this->SetPictProperty(pict);
	return;
}

/*概要：表画像を載せるピクチャボックスのプロパティを設定する関数
作成日：2017.10.4
作成者：K.Asada*/
private: System::Void SetPictProperty(PictureBox^ pict) {
	//ピクチャボックスの座標を設定する
	pict->Location = System::Drawing::Point((Constants->TABLE_LOCATION.X + this->tabPage->AutoScrollPosition.X), (Constants->TABLE_LOCATION.Y + this->tabPage->AutoScrollPosition.Y));
	//ピクチャボックスを前面に押し出す
	pict->BringToFront();
	//ピクチャボックスをセットする起点を設定する
	pict->Anchor = (AnchorStyles::Top | AnchorStyles::Left);
	return;
}

};
}