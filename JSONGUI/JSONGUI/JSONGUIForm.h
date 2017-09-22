#pragma once

#include "OptionForm.h"			//�ݒ��ʃN���X�̃w�b�_
#include "TableInformation.h"	//�\�摜�֌W�̊֐����܂Ƃ߂��N���X�̃w�b�_
#include "MoreDetailForm.h"		//�ڍ׉�ʃN���X�̃w�b�_
#include "Processing.h"			//���������N���X�̃w�b�_

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
	//	: public System::Windows::Forms::Form
	{
	public:
		JSONGUIForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
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
			this->tabPage->Text = L"�e�[�u��";
			this->tabPage->UseVisualStyleBackColor = true;
			// 
			// buttonJoin
			// 
			this->buttonJoin->Location = System::Drawing::Point(507, 6);
			this->buttonJoin->Name = L"buttonJoin";
			this->buttonJoin->Size = System::Drawing::Size(167, 68);
			this->buttonJoin->TabIndex = 10;
			this->buttonJoin->Text = L"����/����";
			this->buttonJoin->UseVisualStyleBackColor = true;
			this->buttonJoin->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableJoinClick);
			// 
			// buttonTableConv
			// 
			this->buttonTableConv->Location = System::Drawing::Point(1292, 6);
			this->buttonTableConv->Name = L"buttonTableConv";
			this->buttonTableConv->Size = System::Drawing::Size(146, 68);
			this->buttonTableConv->TabIndex = 9;
			this->buttonTableConv->Text = L"�ϊ�";
			this->buttonTableConv->UseVisualStyleBackColor = true;
			this->buttonTableConv->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableConvClick);
			// 
			// buttonTableCancel
			// 
			this->buttonTableCancel->Location = System::Drawing::Point(1140, 6);
			this->buttonTableCancel->Name = L"buttonTableCancel";
			this->buttonTableCancel->Size = System::Drawing::Size(146, 68);
			this->buttonTableCancel->TabIndex = 8;
			this->buttonTableCancel->Text = L"�L�����Z��";
			this->buttonTableCancel->UseVisualStyleBackColor = true;
			this->buttonTableCancel->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableCancelClick);
			// 
			// buttonTableOK
			// 
			this->buttonTableOK->Location = System::Drawing::Point(988, 6);
			this->buttonTableOK->Name = L"buttonTableOK";
			this->buttonTableOK->Size = System::Drawing::Size(146, 68);
			this->buttonTableOK->TabIndex = 7;
			this->buttonTableOK->Text = L"OK";
			this->buttonTableOK->UseVisualStyleBackColor = true;
			this->buttonTableOK->Click += gcnew System::EventHandler(this, &JSONGUIForm::TableOKClick);
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(844, 6);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(138, 68);
			this->buttonConnect->TabIndex = 6;
			this->buttonConnect->Text = L"�ʐM";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &JSONGUIForm::ButtonConnectClick);
			// 
			// buttonOption
			// 
			this->buttonOption->Location = System::Drawing::Point(680, 6);
			this->buttonOption->Name = L"buttonOption";
			this->buttonOption->Size = System::Drawing::Size(158, 68);
			this->buttonOption->TabIndex = 5;
			this->buttonOption->Text = L"�ݒ�";
			this->buttonOption->UseVisualStyleBackColor = true;
			this->buttonOption->Click += gcnew System::EventHandler(this, &JSONGUIForm::buttonOption_Click);
			// 
			// textBoxRow
			// 
			this->textBoxRow->Location = System::Drawing::Point(124, 6);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(100, 31);
			this->textBoxRow->TabIndex = 4;
			this->textBoxRow->Text = L"0";
			// 
			// textBoxCol
			// 
			this->textBoxCol->Location = System::Drawing::Point(124, 43);
			this->textBoxCol->Name = L"textBoxCol";
			this->textBoxCol->Size = System::Drawing::Size(100, 31);
			this->textBoxCol->TabIndex = 3;
			this->textBoxCol->Text = L"0";
			// 
			// textBoxCell
			// 
			this->textBoxCell->Location = System::Drawing::Point(1246, 316);
			this->textBoxCell->Multiline = true;
			this->textBoxCell->Name = L"textBoxCell";
			this->textBoxCell->Size = System::Drawing::Size(140, 76);
			this->textBoxCell->TabIndex = 2;
			this->textBoxCell->DoubleClick += gcnew System::EventHandler(this, &JSONGUIForm::TextBoxCellClick);
			// 
			// pictureBoxCurrent
			// 
			this->pictureBoxCurrent->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxCurrent->Location = System::Drawing::Point(1254, 425);
			this->pictureBoxCurrent->Name = L"pictureBoxCurrent";
			this->pictureBoxCurrent->Size = System::Drawing::Size(83, 102);
			this->pictureBoxCurrent->TabIndex = 1;
			this->pictureBoxCurrent->TabStop = false;
			this->pictureBoxCurrent->Click += gcnew System::EventHandler(this, &JSONGUIForm::PictureBoxCurrentClick);
			// 
			// pictureBoxTable
			// 
			this->pictureBoxTable->Location = System::Drawing::Point(38, 377);
			this->pictureBoxTable->Name = L"pictureBoxTable";
			this->pictureBoxTable->Size = System::Drawing::Size(647, 424);
			this->pictureBoxTable->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxTable->TabIndex = 0;
			this->pictureBoxTable->TabStop = false;
			this->pictureBoxTable->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONGUIForm::PictureBoxTableMouseClick);
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

/*�T�v�F���C����ʃ��[�h���̏������C�x���g*/
private: System::Void JSONGUI_Load(System::Object^  sender, System::EventArgs^  e) {
}

/*�T�v�F�e�[�u���^�u�̐ݒ�{�^���N���b�N���̃C�x���g�A�ݒ��ʂ��J��
�����FSender�F�N���b�N���̃t�H�[���̏�񂪊i�[���ꂽ�I�u�W�F�N�g�N���X
	�FEventArgs�F�N���b�N���̃}�E�X�֌W�̏�񂪊i�[���ꂽ�C�x���g�N���X
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada*/
private: System::Void buttonOption_Click(System::Object^  sender, System::EventArgs^  e) {
	//�ݒ��ʂ��J���֐����Ăяo��
	this->ShowOptionForm();
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
�쐬�ҁFK.Asada*/
private: Void TableInit() {
	//���N���X�̏������֐����Ăяo��
	this->InfoInit();
	//�\�摜���R���g���[�����珜�O����
	this->Controls->Remove(this->pictureBoxTable);
	//�I���ӏ����n�C���C�g����摜���R���g���[�����珜�O����
	this->Controls->Remove(this->pictureBoxCurrent);
	//�\�摜��̃e�L�X�g�{�b�N�X���R���g���[�����珜�O����
	this->Controls->Remove(this->textBoxCell);
}

/*�T�v�F�e�[�u���^�u�̃L�����Z���{�^���N���b�N���̃C�x���g�A�e�[�u���^�u�Ɋւ����������������֐����Ăяo��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada*/
private: System::Void TableCancelClick(System::Object^  sender, System::EventArgs^  e) {
	//�e�[�u���^�u�Ɋւ����������������֐����Ăяo��
	this->TableInit();
}

/*�T�v�F�ʐM�{�^���̃N���b�N�C�x���g�ADB�N�G�������֐����Ăяo��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void ButtonConnectClick(System::Object^  sender, System::EventArgs^  e) {
	//���������N���X���C���X�^���X��
	process::Processing^ proc = gcnew process::Processing();
	//�s�������͂���Ă���΍s����n���A�e�L�X�g�{�b�N�X�̒��g��String^�^�̂���Int32�ɕϊ����s��
	proc->row = Convert::ToInt32(this->textBoxRow->Text);
	//�񐔂����͂���Ă���Η񐔂�n���A�e�L�X�g�{�b�N�X�̒��g��String^�^�̂���Int32�ɕϊ����s��
	proc->column = Convert::ToInt32(this->textBoxCol->Text);
	//DB�̓��������֐����Ăяo��
	proc->DBrun(this->DBQuery);
	//���������ɂĎ擾�����s���������o�֊i�[����
	this->Column = proc->column;
	//���������ɂĎ擾�����񐔂������o�֊i�[����
	this->Row = proc->row;
	//�擾�����\���̂������o�֊i�[����
	this->TableElem = proc->Tablechain;
	//�擾�����������������o�֊i�[����
//	this->JoinIndex = proc->joinInfo;
	//�\�摜�𐶐�����֐����Ăяo��
	this->TableGenerate(this->pictureBoxTable);
	//�R���g���[���ւ��s�N�`���{�b�N�X��ǉ�����
	this->Controls->Add(this->pictureBoxTable);
}

/*�T�v�F�e�[�u���^�u��OK�{�^���N���b�N�C�x���g�A���������N���X�ֈڍs����
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void TableOKClick(System::Object^  sender, System::EventArgs^  e) {
	//���������N���X���C���X�^���X��
	process::Processing^ proc = gcnew process::Processing();
	//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�s����Int32�^�ɕϊ����Ă���n��
	proc->row = Convert::ToInt32(this->textBoxRow->Text);
	//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�񐔂�Int32�^�ɕϊ����Ă���n��
	proc->column = Convert::ToInt32(this->textBoxCol->Text);
	//JSON���`�F�C���\���ɕϊ�����֐����Ăяo��
	proc->Tablerun(this->JSONFilePath);
	//�擾�����񐔂������o�֊i�[����
	this->Column = proc->column;
	//�擾�����s���������o�֊i�[����
	this->Row = proc->row;
	//�\���̂������o�֊i�[����
	this->TableElem = proc->Tablechain;
	//�������������o�֊i�[����
//	this->JoinIndex = proc->joinInfo;
	//�\�摜�𐶐�����֐����Ăяo��
	this->TableGenerate(this->pictureBoxTable);
	//�R���g���[���փs�N�`���{�b�N�X��ǉ�����
	this->Controls->Add(this->pictureBoxTable);
}

/*�T�v�F�e�[�u���^�u�̕ϊ��{�^���N���b�N���̃C�x���g
�쐬���F201.9.21
�쐬�ҁFK.Asada*/
private: System::Void TableConvClick(System::Object^  sender, System::EventArgs^  e) {
	//���������N���X���C���X�^���X��
	//�R���X�g���N�^��ύX����\������
	process::Processing^ proc = gcnew process::Processing();
	//������\���̂�n��
	proc->Tablechain = this->TableElem;
	//�s����n��
	proc->row = this->Row;
	//�񐔂�n��
	proc->column = this->Column;
	//JSON�ɕϊ�����֐����Ăяo��
	//proc->JSONRUN();
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
	this->textBoxList->Clear();
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
	//���������N���X���C���X�^���X��
	process::Processing^ proc = gcnew process::Processing();
	//�s����n��
	proc->row = Convert::ToInt32(this->textBoxListRow);
	//���������֐����Ăяo��
	proc->Listrun(this->JSONFilePath);
	//�擾�����s���������o�֊i�[����
	this->Row = proc->row;
	//�擾�����\���̂������o�֊i�[����
	this->TableElem = proc->Tablechain;
	//�擾�����������������o�֊i�[����
//	this->JoinIndex = proc->joinInfo;
	//�\�摜�����֐����Ăяo��
	this->TableGenerate(this->pictureBoxList);
	//�쐬�����摜���R���g���[���֒ǉ�����
	this->Controls->Add(this->pictureBoxList);
}

/*�T�v�F���X�g�^�u�̃L�����Z���{�^���N���b�N�C�x���g�A�������֐����Ăяo��
�����F
�߂�l�F
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void ListCancelClilck(System::Object^  sender, System::EventArgs^  e) {
	//�������֐����Ăяo��
	this->ListInit();
}
private: System::Void ListConvClick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ListConnectClick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ListOptionClick(System::Object^  sender, System::EventArgs^  e) {
}

/*�\�摜����N���b�N�����Ƃ��̃C�x���g�A�I����Ԃɂ���֐����Ăяo��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void PictureBoxTableMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//�I����Ԃ�ێ����邽�߂ɃN���b�N�����\�摜��̍��W�������o�֕ۑ�����֐����Ăяo��
	this->GetCellPoint(e);
	//�I���ӏ����킩��₷���悤�Ƀn�C���C�g����֐����Ăяo��
	this->SelecteCell(this->pictureBoxCurrent);
	//�n�C���C�g�摜���R���g���[���֒ǉ�����
	this->Controls->Add(this->pictureBoxCurrent);
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
	this->Controls->Add(this->pictureBoxListCurr);
}

/*�T�v�F�\�摜�̃n�C���C�g����Ă���ӏ����N���b�N�����Ƃ��̃C�x���g�A�e�L�X�g�{�b�N�X��z�u���ĕҏW�\��Ԃɂ���
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.20
�쐬�ҁFK.Asada*/
private: System::Void PictureBoxCurrentClick(System::Object^  sender, System::EventArgs^  e) {
	//�e�L�X�g�{�b�N�X�ɏ���ݒ肷��֐����Ăяo��
	this->CellTextGenerate(this->textBoxCell);
	//���������e�L�X�g�{�b�N�X�����C����ʂ̃R���g���[���ɏ悹��
	this->Controls->Add(this->textBoxCell);
}

/*�T�v�F���X�g�^�u�̉摜�̃n�C���C�g�������N���b�N�����Ƃ��̃C�x���g�A�ҏW�p�̃e�L�X�g�{�b�N�X��\��
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void PictureBoxListCurrClick(System::Object^  sender, System::EventArgs^  e) {
	//�e�L�X�g�{�b�N�X��z�u���邽�߂̏���ݒ肷��֐����Ăяo��
	this->CellTextGenerate(this->textBoxList);
	//��񂪐ݒ肳�ꂽ�e�L�X�g�{�b�N�X���R���g���[���ɒǉ����ĕ\������
	this->Controls->Add(this->textBoxList);
}

/*�T�v�F�\�摜�̒l�ҏW�p�̃e�L�X�g�{�b�N�X���_�u���N���b�N���ꂽ�Ƃ��̃C�x���g
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void TextBoxListClick(System::Object^  sender, System::EventArgs^  e) {
	//�N���b�N�����Z���̐e�L�[��ҏW���邽�߂̏ڍ׉�ʃN���X���C���X�^���X��
	MoreDetailForm^ more = gcnew MoreDetailForm();
	//�V�K�_�C�A���O�ŕ\������
	more->ShowDialog();
}

/*�T�v�F�\�摜�̒l�ҏW�p�̃e�L�X�g�{�b�N�X���_�u���N���b�N���ꂽ�Ƃ��̃C�x���g
�����F
�߂�l�F�Ȃ�
�쐬���F2017.9.21
�쐬�ҁFK.Asada*/
private: System::Void TextBoxCellClick(System::Object^  sender, System::EventArgs^  e) {
	//�N���b�N�����Z���̐e�L�[��ҏW���邽�߂̏ڍ׉�ʃN���X���C���X�^���X��
	MoreDetailForm^ more = gcnew MoreDetailForm();
	//�V�K�_�C�A���O�ŕ\������
	more->ShowDialog();
}
};
}
