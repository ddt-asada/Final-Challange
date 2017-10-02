#pragma once

#include "OptionForm.h"			//�ݒ��ʃN���X�̃w�b�_
#include "TableInformation.h"	//�\�摜�֌W�̊֐����܂Ƃ߂��N���X�̃w�b�_
#include "SelectForm.h"
#include "Processing.h"			//���������N���X�̃w�b�_
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
	/// JSONGUI �̊T�v
	/// </summary>
	/*�T�v�FJSON�����o�I�ɍ쐬���邽�߂�GUI���C�����
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	public ref class JSONGUIForm
		: public TableInformation
//		: public System::Windows::Forms::Form
	{
	public:
		JSONGUIForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
			this->pictureBoxCurrent->Parent = this->pictureBoxTable;
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
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
			this->tabPage->Text = L"�e�[�u��";
			this->tabPage->UseVisualStyleBackColor = true;
			// 
			// radioButtonValue
			// 
			this->radioButtonValue->AutoSize = true;
			this->radioButtonValue->Location = System::Drawing::Point(421, 80);
			this->radioButtonValue->Name = L"radioButtonValue";
			this->radioButtonValue->Size = System::Drawing::Size(168, 28);
			this->radioButtonValue->TabIndex = 18;
			this->radioButtonValue->TabStop = true;
			this->radioButtonValue->Text = L"�l�ҏW���[�h";
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
			this->radioButtonKey->Text = L"�L�[���ҏW���[�h";
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
			this->labelRow->Text = L"�^�e";
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
			this->labelColumn->Text = L"���R";
			// 
			// buttonNewTable
			// 
			this->buttonNewTable->Location = System::Drawing::Point(794, 6);
			this->buttonNewTable->Name = L"buttonNewTable";
			this->buttonNewTable->Size = System::Drawing::Size(95, 68);
			this->buttonNewTable->TabIndex = 16;
			this->buttonNewTable->Text = L"�V�K";
			this->buttonNewTable->UseVisualStyleBackColor = true;
			this->buttonNewTable->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonNewTableClick);
			// 
			// buttonDeleteColumn
			// 
			this->buttonDeleteColumn->Location = System::Drawing::Point(334, 6);
			this->buttonDeleteColumn->Name = L"buttonDeleteColumn";
			this->buttonDeleteColumn->Size = System::Drawing::Size(122, 68);
			this->buttonDeleteColumn->TabIndex = 15;
			this->buttonDeleteColumn->Text = L"��폜";
			this->buttonDeleteColumn->UseVisualStyleBackColor = true;
			this->buttonDeleteColumn->Click += gcnew System::EventHandler(this, &JSONGUIForm::DeleteColumnButtonClick);
			// 
			// buttonDeleteRow
			// 
			this->buttonDeleteRow->Location = System::Drawing::Point(202, 6);
			this->buttonDeleteRow->Name = L"buttonDeleteRow";
			this->buttonDeleteRow->Size = System::Drawing::Size(126, 68);
			this->buttonDeleteRow->TabIndex = 14;
			this->buttonDeleteRow->Text = L"�s�폜";
			this->buttonDeleteRow->UseVisualStyleBackColor = true;
			this->buttonDeleteRow->Click += gcnew System::EventHandler(this, &JSONGUIForm::DeleteRowButtonClick);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(689, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(99, 68);
			this->button3->TabIndex = 13;
			this->button3->Text = L"�W�J";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonExpansionClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(462, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 68);
			this->button2->TabIndex = 12;
			this->button2->Text = L"�s�ǉ�";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &JSONGUIForm::AddRowButtonClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(579, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 68);
			this->button1->TabIndex = 11;
			this->button1->Text = L"��ǉ�";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &JSONGUIForm::AddColumnButtonClick);
			// 
			// buttonTableConv
			// 
			this->buttonTableConv->Location = System::Drawing::Point(1209, 6);
			this->buttonTableConv->Name = L"buttonTableConv";
			this->buttonTableConv->Size = System::Drawing::Size(98, 68);
			this->buttonTableConv->TabIndex = 9;
			this->buttonTableConv->Text = L"�ϊ�";
			this->buttonTableConv->UseVisualStyleBackColor = true;
			this->buttonTableConv->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableConvClick);
			// 
			// buttonTableCancel
			// 
			this->buttonTableCancel->Location = System::Drawing::Point(1313, 6);
			this->buttonTableCancel->Name = L"buttonTableCancel";
			this->buttonTableCancel->Size = System::Drawing::Size(117, 68);
			this->buttonTableCancel->TabIndex = 8;
			this->buttonTableCancel->Text = L"�L�����Z��";
			this->buttonTableCancel->UseVisualStyleBackColor = true;
			this->buttonTableCancel->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableCancelClick);
			// 
			// buttonTableOK
			// 
			this->buttonTableOK->Location = System::Drawing::Point(1101, 6);
			this->buttonTableOK->Name = L"buttonTableOK";
			this->buttonTableOK->Size = System::Drawing::Size(102, 68);
			this->buttonTableOK->TabIndex = 7;
			this->buttonTableOK->Text = L"�Ǎ�";
			this->buttonTableOK->UseVisualStyleBackColor = true;
			this->buttonTableOK->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableOKClick);
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(996, 6);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(99, 68);
			this->buttonConnect->TabIndex = 6;
			this->buttonConnect->Text = L"�ʐM";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonConnectClick);
			// 
			// buttonOption
			// 
			this->buttonOption->Location = System::Drawing::Point(895, 6);
			this->buttonOption->Name = L"buttonOption";
			this->buttonOption->Size = System::Drawing::Size(95, 68);
			this->buttonOption->TabIndex = 5;
			this->buttonOption->Text = L"�ݒ�";
			this->buttonOption->UseVisualStyleBackColor = true;
			this->buttonOption->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonOptionClick);
			// 
			// textBoxRow
			// 
			this->textBoxRow->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBoxRow->Location = System::Drawing::Point(73, 0);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(100, 31);
			this->textBoxRow->TabIndex = 4;
			this->textBoxRow->Text = L"0";
			// 
			// textBoxCol
			// 
			this->textBoxCol->Location = System::Drawing::Point(73, 43);
			this->textBoxCol->Name = L"textBoxCol";
			this->textBoxCol->Size = System::Drawing::Size(100, 31);
			this->textBoxCol->TabIndex = 3;
			this->textBoxCol->Text = L"0";
			// 
			// textBoxCell
			// 
			this->textBoxCell->ImeMode = System::Windows::Forms::ImeMode::On;
			this->textBoxCell->Location = System::Drawing::Point(1288, 319);
			this->textBoxCell->Multiline = true;
			this->textBoxCell->Name = L"textBoxCell";
			this->textBoxCell->Size = System::Drawing::Size(140, 31);
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
			this->buttonJoin->Location = System::Drawing::Point(823, 6);
			this->buttonJoin->Name = L"buttonJoin";
			this->buttonJoin->Size = System::Drawing::Size(133, 68);
			this->buttonJoin->TabIndex = 10;
			this->buttonJoin->Text = L"����/����";
			this->buttonJoin->UseVisualStyleBackColor = true;
			this->buttonJoin->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableJoinClick);
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
			this->tabPage2->Text = L"���X�g";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonListConv
			// 
			this->buttonListConv->Location = System::Drawing::Point(1276, 14);
			this->buttonListConv->Name = L"buttonListConv";
			this->buttonListConv->Size = System::Drawing::Size(146, 68);
			this->buttonListConv->TabIndex = 19;
			this->buttonListConv->Text = L"�ϊ�";
			this->buttonListConv->UseVisualStyleBackColor = true;
			this->buttonListConv->Click += gcnew System::EventHandler(this, &JSONGUIForm::ListConvClick);
			// 
			// buttonListCancel
			// 
			this->buttonListCancel->Location = System::Drawing::Point(1124, 14);
			this->buttonListCancel->Name = L"buttonListCancel";
			this->buttonListCancel->Size = System::Drawing::Size(146, 68);
			this->buttonListCancel->TabIndex = 18;
			this->buttonListCancel->Text = L"�L�����Z��";
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
			this->buttonListConnect->Text = L"�ʐM";
			this->buttonListConnect->UseVisualStyleBackColor = true;
			this->buttonListConnect->Click += gcnew System::EventHandler(this, &JSONGUIForm::ListConnectClick);
			// 
			// buttonListOption
			// 
			this->buttonListOption->Location = System::Drawing::Point(664, 14);
			this->buttonListOption->Name = L"buttonListOption";
			this->buttonListOption->Size = System::Drawing::Size(158, 68);
			this->buttonListOption->TabIndex = 15;
			this->buttonListOption->Text = L"�ݒ�";
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
			// JSONGUIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1460, 869);
			this->Controls->Add(this->tabControl1);
			this->Name = L"JSONGUIForm";
			this->Text = L"JSONGUI";
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

/*�T�v�F���C����ʃ��[�h���̏������C�x���g�A�ċA�ɂ��g���̂ŕ��򂷂�
�쐬���F2017.9.30
�쐬�ҁFK.ASada*/
private: System::Void JSONGUI_Load(System::Object^  sender, System::EventArgs^  e) {
	//���b�Z�[�W��\�����邽�߂̗�O����
	try {
		//�W�J����̂��߂ɍċA���Ă����Ƃ��ɕ��򂳂���
		if (this->TableElem != nullptr) {
			//�W�J��ɂăL�����Z���{�^���͕s�v�Ȃ̂ō폜����
			this->tabPage->Controls->Remove(this->buttonTableCancel);
			//�W�J��ɂ�OK�{�^���͕s�v�Ȃ̂ō폜����
			this->tabPage->Controls->Remove(this->buttonTableOK);
			//�W�J��ɂĒʐM�{�^���͕s�v�Ȃ̂ō폜����
			this->tabPage->Controls->Remove(this->buttonConnect);
			//�W�J��ɂĐݒ�{�^���͕s�v�Ȃ̂ō폜����
			this->tabPage->Controls->Remove(this->buttonOption);
			//�W�J��ɂĐV�K�{�^���͕s�v�Ȃ̂ō폜����
			this->tabPage->Controls->Remove(this->buttonNewTable);
			//�\�摜�𐶐����邽�߂̏����֐����Ăяo��
			this->ReadyPict(this->TableElem);
			//�\�摜�𐶐�����֐����Ăяo��
			this->TableGenerate(this->pictureBoxTable);
			//�R���g���[���փs�N�`���{�b�N�X��ǉ�����
			this->tabPage->Controls->Add(this->pictureBoxTable);
			//�\�摜��������Ă��邱�Ƃ�����̂őO�ʂɉ����o��
			this->pictureBoxTable->BringToFront();
		}
		return;
	}
	//�S�Ă̗�O��ߑ�����
	catch (System::Exception^ e) {
		//���������f���ꂽ�|��\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�e�[�u���^�u�̐ݒ�{�^���N���b�N���̃C�x���g�A�ݒ��ʂ��J��
�����FSender�F�N���b�N���̃t�H�[���̏�񂪊i�[���ꂽ�I�u�W�F�N�g�N���X
	�FEventArgs�F�N���b�N���̃}�E�X�֌W�̏�񂪊i�[���ꂽ�C�x���g�N���X
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada*/
private: System::Void ButtonOptionClick(System::Object^  sender, System::EventArgs^  e) {
	//�������ɔ����������ׂẴG���[���L���b�`����
	try {
		//�ݒ��ʂ��J���֐����Ăяo��
		this->ShowOptionForm();
	}
	catch (System::Exception^ e) {
		//�G���[���������ď��������f���ꂽ���Ƃ�m�点��
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�v���O�����I�����̃C�x���g�A�I������ǂ����̊m�F���s���B
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada*/
private: System::Void FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//����O�Ƀ��b�Z�[�W�{�b�N�X��\�����Ċm�F���s���B
	if (System::Windows::Forms::DialogResult::Cancel == MessageBox::Show("�I�����܂����H", "�m�F", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)) {
		//�v���O�������I������B
		e->Cancel = true;
	}
}

/*�T�v�F�e�[�u���^�u�Ɋւ����������������֐�
�����F�Ȃ�
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada
�X�V���F2017.10.2
�X�V�ҁFK.Asada
�X�V���e�F�폜����R���g���[�����Ԉ���Ă����̂ŏC��*/
private: Void TableInit() {
	//���N���X�̏������֐����Ăяo��
	this->InfoInit();
	//�I���ӏ����n�C���C�g����摜���R���g���[�����珜�O����
	this->pictureBoxTable->Controls->Remove(this->pictureBoxCurrent);
	//�\�摜��̃e�L�X�g�{�b�N�X���R���g���[�����珜�O����
	this->pictureBoxTable->Controls->Remove(this->textBoxCell);
	//�\�摜���R���g���[�����珜�O����
	this->tabPage->Controls->Remove(this->pictureBoxTable);
	//�s�������͂��ꂽ�e�L�X�g�{�b�N�X������������
	this->textBoxRow->Text = Constants->INITIAL_ROW_STRING;
	//�񐔂����͂��ꂽ�e�L�X�g�{�b�N�X������������
	this->textBoxCol->Text = Constants->INITIAL_COLUMN_STRING;
	//����������
	return;
}

/*�T�v�F�e�[�u���^�u�̃L�����Z���{�^���N���b�N���̃C�x���g�A�e�[�u���^�u�Ɋւ����������������֐����Ăяo��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada*/
private: System::Void TableCancelClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̃G���[�ƏE�����߂̗�O����
	try {
		//�e�[�u���^�u�Ɋւ����������������֐����Ăяo��
		this->TableInit();
		//���������ꂽ���Ƃ�\������
		MessageBox::Show(Constants->INITIAL_STRING);
	}
	//�������̂��ׂĂ̗�O��ߑ�����
	catch (System::Exception^ e) {
		//���炩�̃G���[���������ď��������f���ꂽ���Ƃ�m�点��
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�ʐM�{�^���̃N���b�N�C�x���g�ADB�N�G�������֐����Ăяo��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada
�X�V���F2017.10.2
�X�V�ҁFK.Asada
�X�V���e�F���������\�摜�̒ǉ���ƂȂ�R���g���[�����Ԉ���Ă����̂ŏC��*/
private: System::Void ButtonConnectClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̃G���[��ߑ����邽�߂̗�O����
	try {
		//���������N���X���C���X�^���X��
		process::Processing^ proc = gcnew process::Processing();
		//DB�̓��������֐����Ăяo��
		proc->DBrun(this->DBQuery);
		//�擾�����\���̂������o�֊i�[����
		this->TableElem = proc->Tablechain;
		//�\�摜�𐶐����邽�߂̏����֐����Ăяo��
		this->ReadyPict(this->TableElem);
		//�\�摜�𐶐�����֐����Ăяo��
		this->TableGenerate(this->pictureBoxTable);
		//�R���g���[���ւ��s�N�`���{�b�N�X��ǉ�����
		this->Controls->Add(this->pictureBoxTable);
		//�\�摜��������Ă��邱�Ƃ����邽�߃s�N�`���{�b�N�X��O�ʂɉ����o��
		this->pictureBoxTable->BringToFront();
		//DB�Ƃ̒ʐM���s�������ʂ��o��
		MessageBox::Show(Constants->DB_STRING);
	}
	//�G���[���������ď��������f���ꂽ���Ƃ�\������
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�e�[�u���^�u��OK�{�^���N���b�N�C�x���g�A���������N���X�ֈڍs����
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada
�X�V���F2017.10.2
�X�V�ҁFK.Asada
�X�V���e�F���������\�摜�̒ǉ���ƂȂ�R���g���[�����Ԉ���Ă����̂ŏC��*/
private: System::Void TableOKClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̃G���[��ߑ����邽�߂̗�O����
	try {
		//���������N���X���C���X�^���X��
		process::Processing^ proc = gcnew process::Processing();
		//JSON���`�F�C���\���ɕϊ�����֐����Ăяo��
		proc->Tablerun(this->JSONFilePath);
		//�\���̂������o�֊i�[����
		this->TableElem = %*proc->Tablechain;
		//�\�摜�𐶐����邽�߂̏����֐����Ăяo��
		this->ReadyPict(this->TableElem);
		//�\�摜�𐶐�����֐����Ăяo��
		this->TableGenerate(this->pictureBoxTable);
		//�R���g���[���փs�N�`���{�b�N�X��ǉ�����
		this->tabPage->Controls->Add(this->pictureBoxTable);
		//�\�摜��������Ȃ��悤�ɑO�ʂɈړ�������
		this->pictureBoxTable->BringToFront();
		//JSON��ǂݍ��񂾂��Ƃ�\������
		MessageBox::Show(Constants->LOAD_STRING);
	}
	//�S�ẴG���[��ߑ����������f���ꂽ���Ƃ�\�����邽�߂̕⑫
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�e�[�u���^�u�̕ϊ��{�^���N���b�N���̃C�x���g
�쐬���F201.9.21
�쐬�ҁFK.Asada*/
private: System::Void TableConvClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̗�O��ߑ����ă��b�Z�[�W��\�����邽�߂̗�O����
	try {
		//JSON�t�@�C���̕ۑ����ۊǂ��镶����
		String^ outJSONpath = "";
		//���������N���X���C���X�^���X��
		process::Processing^ proc = gcnew process::Processing();
		//JSON�t�@�C���̕ۑ����I������_�C�A���O��\������
		if (this->saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//OK�{�^���������ꂽ��t�@�C���̏o�͐��ۊǂ���
			outJSONpath = this->saveFileDialog1->FileName;
		}
		else{
			//���삪���f���ꂽ�|��\������
			MessageBox::Show(Constants->CANCEL_STRING);
			//���������Ƀ_�C�A���O�����
			return;
		}
		//JSON�ɕϊ�����֐����Ăяo��
		proc->Convertrun(outJSONpath, this->TableElem);
		//�ϊ������������|��\������
		MessageBox::Show(Constants->SUCCES_STRING);
		//�ϊ�����
		return;
	}
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void TableJoinClick(System::Object^  sender, System::EventArgs^  e) {
}

/*�T�v�F�ӏ������֌W�̏�������������֐�
�����F�Ȃ�
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: Void ListInit() {
	//�\�摜���폜����
	this->Controls->Remove(this->pictureBoxList);
	//�\�摜�n�C���C�g�p�̉摜���폜����
	this->Controls->Remove(this->pictureBoxListCurr);
	//�z�񐔃e�L�X�g�^�u������������
	this->textBoxListRow->Clear();
	//�\�摜�̒l�ҏW�p�e�L�X�g�{�b�N�X������������
	this->textBoxList->Text = Constants->INITIAL_ROW_STRING;
	//�e�L�X�g�{�b�N�X����������
	this->Controls->Remove(this->textBoxList);
	//���N���X�̏������֐����Ăяo��
	this->InfoInit();
}

/*�T�v�F���X�g�^�u��OK�{�^���N���b�N�C�x���g�A�t�@�C���p�X����JSON��ǂݍ���ŏ�������
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void ListOKClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̃G���[�ߑ����邽�߂̗�O����
	try {
		//���������N���X���C���X�^���X��
		process::Processing^ proc = gcnew process::Processing();
		//���������֐����Ăяo��
		proc->Listrun(this->JSONFilePath);
		//�擾�����\���̂������o�֊i�[����
		this->TableElem = %*proc->Tablechain;
		//�\�摜�𐶐����邽�߂̏����֐����Ăяo��
		this->ReadyPict(this->TableElem);
		//�\�摜�����֐����Ăяo��
		this->TableGenerate(this->pictureBoxList);
		//�쐬�����摜���R���g���[���֒ǉ�����
		this->Controls->Add(this->pictureBoxList);
		//�\�摜��������Ă��邱�Ƃ����邽�߃s�N�`���{�b�N�X��O�ʂɉ����o��
		this->pictureBoxList->BringToFront();
	}
	//��O��ߑ������珈�������f���ꂽ�|��\������
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F���X�g�^�u�̃L�����Z���{�^���N���b�N�C�x���g�A�������֐����Ăяo��
�����F
�߂�l�F
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void ListCancelClilck(System::Object^  sender, System::EventArgs^  e) {
	//�������̃G���[���E�����߂̗�O����
	try {
		//�������֐����Ăяo��
		this->ListInit();
		//����������
		return;
	}
	//�S�ẴG���[��ߑ����Čx�����o�����߂̗�O
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void ListConvClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̗�O��ߑ����ă��b�Z�[�W��\�����邽�߂̗�O����
	try {
		//���������N���X���C���X�^���X��
		process::Processing^ proc = gcnew process::Processing();
		//������\���̂�n��
		proc->Tablechain = this->TableElem;
		//JSON�ɕϊ�����֐����Ăяo��
		proc->Convertrun("aaa", this->TableElem);
		//�ϊ�����
		return;
	}
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void ListConnectClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̃G���[��ߑ����邽�߂̗�O����
	try {
		//���������N���X���C���X�^���X��
		process::Processing^ proc = gcnew process::Processing();
		//DB�̓��������֐����Ăяo��
		proc->DBrun(this->DBQuery);
		//�擾�����\���̂������o�֊i�[����
		this->TableElem = proc->Tablechain;
		//�\�摜�𐶐����邽�߂̏����֐����Ăяo��
		this->ReadyPict(this->TableElem);
		//�\�摜�𐶐�����֐����Ăяo��
		this->TableGenerate(this->pictureBoxList);
		//�R���g���[���ւ��s�N�`���{�b�N�X��ǉ�����
		this->Controls->Add(this->pictureBoxList);
		//�\�摜��������Ă��邱�Ƃ����邽�߃s�N�`���{�b�N�X��O�ʂɉ����o��
		this->pictureBoxList->BringToFront();
	}
	//�G���[���������ď��������f���ꂽ���Ƃ�\������
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void ListOptionClick(System::Object^  sender, System::EventArgs^  e) {
	//�������ɔ����������ׂẴG���[���L���b�`����
	try {
		//�ݒ��ʂ��J���֐����Ăяo��
		this->ShowOptionForm();
	}
	catch (System::Exception^ e) {
		//�G���[���������ď��������f���ꂽ���Ƃ�m�点��
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�\�摜����N���b�N�����Ƃ��̃C�x���g�A�I����Ԃɂ���֐����Ăяo��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada
�X�V���e�F���ɑI����ԂɂȂ��Ă���ꏊ�ȊO���N���b�N�����Ƃ��Ƀe�L�X�g�{�b�N�X���\������Ă����������悤�ɕύX
�X�V���F2017.9.30
�X�V�ҁFK.Asada*/
private: System::Void PictureBoxTableMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//���b�Z�[�W��\�����邽�߂̗�O����
	try {
		//�e�L�X�g�{�b�N�X���폜����
		this->pictureBoxTable->Controls->Remove(this->textBoxCell);
		//�I����Ԃ�ێ����邽�߂ɃN���b�N�����\�摜��̍��W�������o�֕ۑ�����֐����Ăяo��
		this->GetCellPoint(e);
		//�I���ӏ����킩��₷���悤�Ƀn�C���C�g����֐����Ăяo��
		this->SelecteCell(this->pictureBoxCurrent);
		//�n�C���C�g�摜���R���g���[���֒ǉ�����
		this->pictureBoxTable->Controls->Add(this->pictureBoxCurrent);
		//�摜��O�ʂɉ����o��
		this->pictureBoxCurrent->BringToFront();
	}
	//�S�Ă̗�O��ߑ�����
	catch (System::Exception^ e) {
		//���������f���ꂽ�|��\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F���X�g�^�u�̕\�摜����N���b�N�����Ƃ��̃C�x���g�A�I����Ԃɂ���֐����Ăяo��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void PictureBoxListMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//�I����Ԃ�ێ����邽�߂ɃN���b�N�����\�摜��̍��W�������o�֕ۑ�����֐����Ăяo��
	this->GetCellPoint(e);
	//�I���ӏ����킩��₷���悤�Ƀn�C���C�g����֐����Ăяo��
	this->SelecteCell(this->pictureBoxListCurr);
	//�n�C���C�g�摜���R���g���[���֒ǉ�����
	this->pictureBoxList->Controls->Add(this->pictureBoxListCurr);
	//������Ă��邱�Ƃ����邽�ߑO�ʂɉ����o��
	this->pictureBoxListCurr->BringToFront();
	return;
}

/*�T�v�F�\�摜�̃n�C���C�g����Ă���ӏ����N���b�N�����Ƃ��̃C�x���g�A�e�L�X�g�{�b�N�X��z�u���ĕҏW�\��Ԃɂ���
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada
�X�V���F2017.10.2
�X�V�ҁFK.Asada
�X�V���e�F�L�[��/�l�ҏW���[�h�ɑΉ������f�[�^���e�L�X�g�{�b�N�X�ɕ\������悤�ɕύX�A�e�L�X�g�{�b�N�X���\�����ꂽ�Ƃ��ɃJ�[�\���������ɗ���悤�ɕύX*/
private: System::Void PictureBoxCurrentClick(System::Object^  sender, System::EventArgs^  e) {
	//���b�Z�[�W��\�����邽�߂̗�O����
	try {
		//�e�L�X�g�{�b�N�X�ɏ���ݒ肷��֐����Ăяo��
		this->CellTextGenerate(this->textBoxCell, this->radioButtonKey->Checked, this->radioButtonValue->Checked);
		//���������e�L�X�g�{�b�N�X�����C����ʂ̃R���g���[���ɏ悹��
		this->pictureBoxTable->Controls->Add(this->textBoxCell);
		//�e�L�X�g�{�b�N�X��������Ȃ��悤�ɑO�ʂɔz�u����
		this->textBoxCell->BringToFront();
		//�e�L�X�g�{�b�N�X�̖����ɃJ�[�\�����ړ�����
		this->textBoxCell->SelectionStart = this->textBoxCell->Text->Length;
		//�J�[�\����\�����邽�߂Ƀe�L�X�g�{�b�N�X�Ƀt�H�[�J�X��
		this->textBoxCell->Focus();
		return;
	}
	//�S�Ă̗�O��ߑ�����
	catch (System::Exception^ e) {
		//���������f���ꂽ�|��\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F���X�g�^�u�̉摜�̃n�C���C�g�������N���b�N�����Ƃ��̃C�x���g�A�ҏW�p�̃e�L�X�g�{�b�N�X��\��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void PictureBoxListCurrClick(System::Object^  sender, System::EventArgs^  e) {
	//�e�L�X�g�{�b�N�X��z�u���邽�߂̏���ݒ肷��֐����Ăяo��
	this->CellTextGenerate(this->textBoxList, this->radioButtonKey->Checked, this->radioButtonValue->Checked);
	//��񂪐ݒ肳�ꂽ�e�L�X�g�{�b�N�X���R���g���[���ɒǉ����ĕ\������
	this->pictureBoxListCurr->Controls->Add(this->textBoxList);
	//�e�L�X�g�{�b�N�X��O�ʂɉ����o��
	this->textBoxList->BringToFront();
}

/*�T�v�F�\�摜�̒l�ҏW�p�̃e�L�X�g�{�b�N�X���_�u���N���b�N���ꂽ�Ƃ��̃C�x���g
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void TextBoxListClick(System::Object^  sender, System::EventArgs^  e) {

}

/*�T�v�F�\�摜�̒l�ҏW�p�̃e�L�X�g�{�b�N�X���_�u���N���b�N���ꂽ�Ƃ��̃C�x���g
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void TextBoxCellClick(System::Object^  sender, System::EventArgs^  e) {
try{
	//�N���b�N�����Z���̐e�L�[��ҏW���邽�߂̏ڍ׉�ʃN���X���C���X�^���X��
	MoreInfoForm^ more = gcnew MoreInfoForm();
	//�ڍ׃_�C�A���O�֓n���\���̂�錾
	CellDataChain::cellchain^ child = gcnew CellDataChain::cellchain();
	//�\���̑���N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�n���\���̂��擾����
	child = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
	//nullptr���擾�����ꍇ�Ώۂ̈ʒu�ɐV�K�ō\���̂��쐬���ĘA������
	if (child == nullptr) {
		//���b�Z�[�W��\��
		//�Ώۂ̈ʒu�̍\���̂ɕ������}������֐����Ăяo��
		child = CellCtrl->SetChainCell(*this->RowIndex, *this->ColumnIndex, "", this->TableElem, false, false);
	}//����ɏ����擾�ł��Ă����ꍇ�͏ڍ׃_�C�A���O��\��
	//�ڍ׃_�C�A���O�֍\���̂�n��
	more->TableElem = child;
	//�V�K�_�C�A���O�ŕ\������
	more->ShowDialog();
	//�I�������\�摜���ĕ`�悷��
	this->ReadyPict(this->TableElem);
	//�\�摜���ĕ`�悷��
	this->TableGenerate(this->pictureBoxTable);
	return;
	}
		 catch (System::NullReferenceException^ e) {
			 System::Console::WriteLine(e);
		 }
		 catch (System::ArgumentNullException^ e) {
			 System::Console::WriteLine(e);
		 }
}

/*�s�ǉ��{�^���̃N���b�N�C�x���g�A�\�摜�ɍs��}������
�쐬���F2017.9.25
�쐬�ҁFK.Asada
�X�V���e�F�s��}�����������I��������@�\��ǉ�
�X�V���F2017.9.28
�X�V�ҁFK.Asada
�X�V���e�F�������萔��
�X�V���F2017.10.2
�X�V�ҁFK.Asada*/
private: System::Void AddRowButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//��O�����C����ʂł��ߑ����邽�߂ɗ�O����
	try {
		//�I����ʃt�H�[�����C���X�^���X��
		SelectForm^ sele = gcnew SelectForm();
		String^ select = "";		//�I����ʂɂđI�������{�^���̖��O���擾���邽�߂̕�����
		//�I����ʂ̃{�^���ɕ\�����镶����n��
		sele->ElderButton->Text = Constants->TOP_STRING;
		//�I����ʂ̃{�^���ɕ\�����镶����n��
		sele->YoungButton->Text = Constants->UNDER_STRING;
		//�I����ʂ�\������
		sele->ShowDialog();
		//�I�����ꂽ�{�^���̖��O���擾����
		select = sele->selectbutton;
		//�擪����ɍs��ǉ����悤�Ƃ����Ƃ��͒ǉ����Ȃ�
		if (*this->RowIndex <= 0 && select == Constants->ELDER_BUTTON_STRING) {
			//�擪����ɂ͒ǉ��ł��Ȃ��|��\��
			MessageBox::Show(Constants->ADD_ERROR_STRING);
		}
		//�L�����Z���{�^���ȊO�Ȃ�ǉ����������s
		else if (select != Constants->CANCEL_BUTTON_STRING) {
			//�s��}������֐����Ăяo��
			this->RowAdd(*this->RowIndex, select);
			//�s����ǉ�����
			this->textBoxRow->Text = Convert::ToString(Convert::ToInt32(this->textBoxRow->Text) + 1);
			//�s��ǉ��������ߕ\���ĕ`�悵�����̂ŏ������s��
			this->ReadyPict(this->TableElem);
			//�s��}��������̕\�摜���ĕ`�悷��֐����Ăяo��
			this->TableGenerate(this->pictureBoxTable);
		}//�L�����Z���{�^���Ȃ�ǉ������𒆒f����
		else {
			//���f����|����ʏ�ɏo�͂���
			MessageBox::Show(Constants->CANCEL_STRING);
		}
		return;
	}
	//�S�Ă̗�O��ߑ�����
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ�|��\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*��ǉ��{�^���̃N���b�N�C�x���g�A�\�ɗ��}������
�쐬���F2017.9.25
�쐬�ҁFK.Asada
�X�V���e�F���ǉ���������̑I����������@�\��ǉ�
�X�V���F2017.9.28
�쐬�ҁFK.Asada
�X�V���e�F�������萔��
�X�V���F2017.10.2
�X�V�ҁFK.Asada*/
private: System::Void AddColumnButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//��O�������Ƃ��Ɍx����\�����邽�߂ɂ��ׂĂ̗�O����
	try {
		//�I����ʃt�H�[�����C���X�^���X��
		SelectForm^ sele = gcnew SelectForm();
		String^ select = "";		//�I����ʂɂđI�������{�^���̖��O���擾���邽�߂̕�����
		//�I����ʂ̃{�^���ɕ\�����镶����n��
		sele->ElderButton->Text = Constants->LEFT_STRING;
		//�I����ʂ̃{�^���ɕ\�����镶����n��
		sele->YoungButton->Text = Constants->RIGHT_STRING;
		//�I����ʂ�\������
		sele->ShowDialog();
		//�I�����ꂽ�{�^���̖��O���擾����
		select = sele->selectbutton;
		//�擪��荶�ɗ��ǉ����悤�Ƃ��Ă���Ƃ��͒ǉ��ł��Ȃ��悤�ɂ���
		if (*this->ColumnIndex <= 0 && select == Constants->ELDER_BUTTON_STRING) {
			//�擪��荶�ɗ��ǉ��ł��Ȃ��|��\��
			MessageBox::Show(Constants->ADD_ERROR_STRING);
		}
		//�L�����Z���ȊO�Ȃ珈�������s����
		else if (select != Constants->CANCEL_BUTTON_STRING) {
			//�񐔂��v���X����
			this->textBoxCol->Text = Convert::ToString(Convert::ToInt32(this->textBoxCol->Text) + 1);
			//���}������֐����Ăяo��
			this->ColumnAdd(*this->Row, *this->ColumnIndex, select);
			//���ǉ��������ߕ\���ĕ`�悵�����̂ŏ������s��
			this->ReadyPict(this->TableElem);
			//���}��������̕\���ĕ`��
			this->TableGenerate(this->pictureBoxTable);
		}//�L�����Z���{�^����������Ă����珈���𒆒f����
		else {
			MessageBox::Show(Constants->CANCEL_STRING);
		}
		return;
	}
	//�S�Ă̗�O��ߑ�
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���N���đ��삪���f���ꂽ�|��\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�l�ҏW�p�̃e�L�X�g�{�b�N�X���ŃG���^�[�L�[�������ꂽ�Ƃ��̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada
�X�V���e�F�G���^�[�L�[�������ꂽ�Ƃ��Ƀe�L�X�g�{�b�N�X��������悤�ɕύX
�X�V���F2017.9.30
�X�V�ҁFK.Asada
�X�V���F2017.10.2
�X�V�ҁFK.Asada
�X�V���e�F�L�[��/�l�ҏW���[�h�ɑΉ������������ҏW����悤�ɕύX*/
private: System::Void TextBoxCellEnter(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	try {	
		//�G���^�[�L�[�������ꂽ�Ƃ��̃C�x���g
		if (e->KeyCode == Keys::Enter) {
			//Focusleave�C�x���g�𔭐������邽�߂ɃA�N�e�B�u�𖳂ɂ���
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

/*�T�v�F�W�J�{�^���N���b�N���̃C�x���g
�����F�Ȃ�
�߂�l�F�Ȃ�
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void ButtonExpansionClick(System::Object^  sender, System::EventArgs^  e) {
	//�������̃G���[���E�����߂̗�O����
	try {
		//�W�J�����摜�𐶐����ĐV�K�_�C�A���O�ɕ\������֐����Ăяo��
		this->Expansion();
		return;
	}
	//�S�ẴG���[��ߑ����ăG���[���b�Z�[�W��\�����邽�߂̕⑫
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�e�L�[�ɂ���JSON��W�J�����\�摜�𐶐�����֐�
�����F�Ȃ�
�߂�l�F�Ȃ�
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
 private:Void Expansion() {
	 //�\���̂̑������ɔ�������nullptr�̗�O����
	 try{
	 //�`�F�C���\������N���X���C���X�^���X��
	 CellDataChain^ CellCtrl = gcnew CellDataChain();
	 //�\�摜��\�����邽�߂̃N���X���C���X�^���X��
	 JSONGUIForm^ more = gcnew JSONGUIForm();
	 //�\������\���̂��擾���Ċi�[���邽�߂̍\����
	 CellDataChain::cellchain^ detailtable = gcnew CellDataChain::cellchain();
	 //�\���̂��擾����
	 detailtable = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
	 //����nullptr���擾���Ă���Ε\�����ׂ���񂪂Ȃ��Ƃ��ă��b�Z�[�W��\������
	 if (detailtable == nullptr) {
		 //�W�J���ׂ���񂪂Ȃ����Ƃ�\������
		 MessageBox::Show(Constants->EXPANSION_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK);
	 }
	 else {//����ɏ����擾�ł��Ă����ꍇ�͏ڍ׃_�C�A���O���J��
		 //�V�K�ɊJ���_�C�A���O�̏����l�Ƃ��č\���̂�ݒ�
		 more->TableElem = detailtable;
		 //�_�C�A���O���J��
		 more->ShowDialog();
		 //�I�������\�摜���ĕ`�悷��
		 this->ReadyPict(this->TableElem);
		 //�\�摜���ĕ`�悷��
		 this->TableGenerate(this->pictureBoxTable);
	 }
	 return;
	 }
	 //null���Q�Ƃ��ꂽ��G���[���e���R���\�[���ɏo�͂���
	 catch (System::NullReferenceException^ e) {
		 //null�֌W�̃G���[���R���\�[���ɕ\������
		 System::Console::WriteLine(e);
	 }
	 //null���Q�Ƃ��ꂽ��G���[���e���R���\�[���ɕ\������
	 catch (System::ArgumentNullException^ e) {
		 //null�֌W�̃G���[���R���\�[���ɕ\������
		 System::Console::WriteLine(e);
	 }
}


		 /*�T�v�F�\�摜�𐶐����邽�߂̏����̊֐��A�񐔁A�s�����擾����
		 �����Fcellchain^ tablechain�F�\�摜�ɕϊ�����\��̍\����
		 �߂�l�F�Ȃ�
		 �쐬���F2017.9.25
		 �쐬�ҁFK.Asada
		 �X�V���F2017.10.2
		 �X�V�ҁFK.Asada
		 �X�V���e�F�s���Ɨ񐔂̂ǂ��炩��0�ł���΃G���[�𑗏o����悤�ɕύX*/
		 Void ReadyPict(CellDataChain::cellchain^ tablechain) {
			 //���͏�񂪐��������ǂ�����ߑ����邽�߂̗�O����
			 try {
				 //�n�����\���̂����Ƃɍs���Ɨ񐔂�����o���֐����Ăяo��
				 this->CountRow(tablechain->lower);
				 //��ʏ�̃e�L�X�g�{�b�N�X�̒l�Ƃ̔�r���s��
				 if (*this->Row < Convert::ToInt32(this->textBoxRow->Text)) {
					 //�傫�������̗p����
					 this->Row = Convert::ToInt32(this->textBoxRow->Text);
				 }
				 else {
					 //���ݕ\�����Ă���\�̍s���Ƃ��ăe�L�X�g�{�b�N�X�Ɋi�[����
					 this->textBoxRow->Text = Convert::ToString(*this->Row);
				 }
				 //��ʏ�̃e�L�X�g�{�b�N�X�̒l�Ƃ̔�r���s��
				 if (*this->Column < Convert::ToInt32(this->textBoxCol->Text)) {
					 //�傫�������̗p����
					 this->Column = Convert::ToInt32(this->textBoxCol->Text);
				 }
				 else {
					 //���ݕ\�����Ă���\�̍s���Ƃ��ăe�L�X�g�{�b�N�X�Ɋi�[����
					 this->textBoxCol->Text = Convert::ToString(*this->Column);
				 }
				 //�s���Ɨ񐔂̂����ꂩ��0�ł���Ε\�Ƃ��Đ��藧���Ȃ��̂ŃG���[�𓊂���
				 if (*this->Row <= 0 || *this->Column <= 0) {
					 throw(gcnew System::FormatException());
				 }
				 return;
			 }
			 //�e�L�X�g�{�b�N�X�̓��͓��e���������Ȃ������Ƃ��ɕߑ�
			 catch (System::FormatException^ e) {
				 //���͓��e�����������|���R���\�[���ɕ\������
				 System::Console::WriteLine(Constants->INPUT_ERROR_STRING + e);
				 throw e;
			 }
		 }

/*�T�v�F��폜�{�^���̃N���b�N�C�x���g
�쐬��2017.9.29
�쐬�ҁFK.Asada
�X�V���e�F�擪�̗�͍폜�ł��Ȃ��悤�ɕ����ǉ�
�X�V���F2017.9.30
�쐬�ҁFK.Asada*/
private: System::Void DeleteColumnButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�S�Ă̗�O��ߑ������烁�C����ʑ��Ōx����\�����邽�߂̗�O����
	try {
		//�폜�Ώۂ��擪�̗�̏ꍇ�͐e���폜���邱�ƂɂȂ�̂ō폜���Ȃ�
		if (*this->ColumnIndex > 0) {
			//�w�肵������폜����֐����Ăяo��
			this->ColumnDelete(*this->Row, *this->ColumnIndex);
			//�񐔂����炷
			this->textBoxCol->Text = Convert::ToString(Convert::ToInt32(this->textBoxCol->Text) - 1);
			//�\�̓��e���ύX����Ă��邽�ߍĕ`�悷�鏀�����s��
			this->ReadyPict(this->TableElem);
			//�\�S�̂��ĕ`�悷��
			this->TableGenerate(this->pictureBoxTable);
		}
		//�擪��͍폜���Ȃ�
		else {
			//�폜�ł��Ȃ��|��`����
			MessageBox::Show("�擪�̗�͍폜�ł��܂���");
		}
		return;
	}
	//�S�Ă̗�O��ߑ�����
	catch (System::Exception^ e) {
		//���C����ʂŌx����\������A�G���[���e�̓R���\�[���ɕ\��
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�s�폜�{�^���̃N���b�N�C�x���g
�쐬���F2017.9.29
�쐬�ҁFK.Asada
�X�V���e�F1�s�����Ȃ��Ƃ��͍폜�ł��Ȃ��悤�ɕύX
�X�V���F2017.9.30
�X�V�ҁFK.Asada*/
private: System::Void DeleteRowButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�S�Ă̗�O�ɑ΂��ă��C����ʂŌx����\������悤�ɗ�O����
	try {
		//�s��1�s�ȏ�̎��̂ݍ폜�Ɉڂ�
		if (*this->Row > 1) {
			//�w�肵���s���폜����֐����Ăяo��
			this->RowDelete(*this->RowIndex);
			//�s�������炷
			this->textBoxRow->Text = Convert::ToString(Convert::ToInt32(this->textBoxRow->Text) - 1);
			//�\�̓��e���ύX����Ă��邽�ߍĕ`�悷�鏀�����s��
			this->ReadyPict(this->TableElem);
			//�\�S�̂��ĕ`�悷��
			this->TableGenerate(this->pictureBoxTable);
		}
		//1�s�����Ȃ��Ƃ��͍폜�ł��Ȃ��|��\��
		else {
			MessageBox::Show("����ȏ�s�̍폜�͂ł��܂���");
		}
		return;
	}
	//�S�Ă̗�O��ߑ�
	catch (System::Exception^ e) {
		//�G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*�T�v�F�V�K�{�^���̃N���b�N�C�x���g�A�V�K�ɕ\�摜���쐬����
�쐬���F2017.9.30
�쐬�ҁFK.Asada
�X�V���F2017.10.2
�X�V�ҁFK.Asada
�X�V���e�F������̕\�摜�̃R���g���[���ǉ��悪�Ԉ���Ă����̂ŏC��*/
private: System::Void ButtonNewTableClick(System::Object^  sender, System::EventArgs^  e) {
	//�S�Ă̗�O�Ń��C����ʑ��Ōx�����o�������̂ŗ�O����
	try {
		MoreInfoForm^ more = gcnew MoreInfoForm();			//�ڍ׏��ҏW�N���X���C���X�^���X��
		CellDataChain^ CellCtrl = gcnew CellDataChain();	//�\���̑���N���X���C���X�^���X��
		//�V�K�ł����Ƃ��e�ƂȂ��̍\���̂���쐬���ă����o�Ɋi�[
		this->TableElem = CellCtrl->ChainParent(Constants->EMPTY_STRING, Constants->EMPTY_STRING, nullptr);
		//�񐔂ƍs�����擾����֐����Ăяo��
		this->ReadyPict(this->TableElem);
		//�V�K�ŕ\��JSON�𐶐�����ۂɕK�v�ȏ��̓��͂𑣂�
		MessageBox::Show(Constants->NEW_STRING);
		//��قǐ���������̍\���̂̏ڍ׏�����͂����邽�߂ɏڍ׉�ʂ֓n��
		more->TableElem = this->TableElem;
		//�ڍ׉�ʂ��J���ĕҏW���s��
		more->ShowDialog();
		//�\�摜�̕`����s��
		this->TableGenerate(this->pictureBoxTable);
		//�R���g���[���Ƀs�N�`���{�b�N�X��ǉ�����
		this->tabPage->Controls->Add(this->pictureBoxTable);
		//�\�摜��������Ă��邱�Ƃ�����̂őO�ʂɉ����o��
		this->pictureBoxTable->BringToFront();
		//�\���������ꂽ���Ƃ��o�͂���
		MessageBox::Show(Constants->TABLE_STRING);
		return;
	}
	//�S�Ă̗�O��ߑ�
	catch (System::Exception^ e) {
		//�Ȃ�炩�̃G���[���������ď��������f���ꂽ���Ƃ�\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void textBoxCell_Leave(System::Object^  sender, System::EventArgs^  e) {
	//���b�Z�[�W��\�����邽�߂̗�O����
	try {
		//�`�F�C���\������N���X���C���X�^���X��
		CellDataChain^ CellCtrl = gcnew CellDataChain();
		Int32 rowindex = *this->RowIndex;		//�ҏW����\���̂��w�肷�邽�߂ɍ��W���擾
		Int32 colindex = *this->ColumnIndex;	//�ҏW����\���̂��w�肷�邽�߂ɍ��W���擾
		String^ data = this->textBoxCell->Text;	//�\���̂񂢓n�����߂̕�������e�L�X�g�{�b�N�X���擾
		//�Ώۂ̈ʒu�̍\���̂ɕ������}������֐����Ăяo��
		CellCtrl->SetChainCell(rowindex, colindex, data, this->TableElem, this->radioButtonKey->Checked, this->radioButtonValue->Checked);
		//�Z���̍ĕ`����s��
		this->ReTableGenerate(this->pictureBoxTable);
		//�e�L�X�g�{�b�N�X��\������O��
		this->pictureBoxTable->Controls->Remove(this->textBoxCell);
	}
	//�S�Ă̗�O��ߑ�����
	catch (System::Exception^ e) {
		//���������f���ꂽ�|��\������
		MessageBox::Show(Constants->MESSAGE_STRING, Constants->ERROR_STRING, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}