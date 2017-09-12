#pragma once

#include "TableProcessing.h"

namespace JSONTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TableInformation �̊T�v
	/// </summary>
	public ref class TableInformation 
		//: public System::Windows::Forms::Form
		: public TableProcessing
	{
	public:
		TableInformation()
		{
			InitializeComponent();
			this->pictureBoxSelect->Parent = this->pictureBoxDetail;
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

		TableInformation(List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ tblinf)
		{
			this->TableInfo = tblinf;
	//		this->RowIndex = rowindex;
		//	this->ColumnIndex = columnindex;
			InitializeComponent();
			this->pictureBoxSelect->Parent = this->pictureBoxDetail;
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~TableInformation()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	public:
	private: System::Windows::Forms::PictureBox^  pictureBoxDetail;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::PictureBox^  pictureBoxSelect;
	public:
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
			this->pictureBoxDetail = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxSelect = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDetail))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSelect))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxDetail
			// 
			this->pictureBoxDetail->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBoxDetail->Location = System::Drawing::Point(0, 0);
			this->pictureBoxDetail->Name = L"pictureBoxDetail";
			this->pictureBoxDetail->Size = System::Drawing::Size(100, 50);
			this->pictureBoxDetail->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxDetail->TabIndex = 0;
			this->pictureBoxDetail->TabStop = false;
			this->pictureBoxDetail->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TableInformation::pictureBoxDetail_MouseClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(682, 234);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(71, 30);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &TableInformation::textBox1_KeyDown);
			this->textBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TableInformation::textBox1_MouseDoubleClick);
			// 
			// pictureBoxSelect
			// 
			this->pictureBoxSelect->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxSelect->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxSelect->Location = System::Drawing::Point(628, 92);
			this->pictureBoxSelect->Name = L"pictureBoxSelect";
			this->pictureBoxSelect->Size = System::Drawing::Size(100, 50);
			this->pictureBoxSelect->TabIndex = 2;
			this->pictureBoxSelect->TabStop = false;
			this->pictureBoxSelect->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TableInformation::pictureBoxSelect_MouseClick);
			// 
			// TableInformation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 360);
			this->Controls->Add(this->pictureBoxSelect);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBoxDetail);
			this->Name = L"TableInformation";
			this->Text = L"TableInformation";
			this->Load += gcnew System::EventHandler(this, &TableInformation::TableInformation_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDetail))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSelect))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBoxDetail_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//�N���b�N�������W���擾����
		this->CalPoint(e);
		//�R���g���[������e�L�X�g�{�b�N�X���폜����
		this->pictureBoxDetail->Controls->Remove(this->textBox1);
		//�I���ӏ����n�C���C�g����
		this->pict(this->pictureBoxSelect);
	}
private: System::Void TableInformation_Load(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBoxDetail->Image = this->ValueChange();
	for (int i = 0; i < this->Index->Count; i++) {
		this->join->Add("");
	}
	this->Row = this->Index->Count;
	this->Column = 2;
}
private: System::Void pictureBoxSelect_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//�R���g���[���Ƀe�L�X�g�{�b�N�X��ǉ�����
	this->pictureBoxDetail->Controls->Add(this->textBox1);
	//�e�L�X�g�{�b�N�X��Ώۂ̃Z���̑傫���Ɠ����ɂ���
	this->textBox1->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
	//�e�L�X�g�{�b�N�X�̔z�u��Ώۂ̃Z���Ɠ����ʒu�ɂ���
	this->textBox1->Location = System::Drawing::Point(0 + *this->RctWidth * *this->ColumnIndex, 0 + *this->RctHeight * *this->RowIndex);
	//�e�L�X�g�{�b�N�X��O�ʂɔz�u����
	this->textBox1->BringToFront();
	//�e�L�X�g�{�b�N�X�֕������z�u���邽�߂̕���
	if (this->ColumnIndex == 0) {
		this->textBox1->Text = this->TableInfo[this->Index[*this->RowIndex]]->first->first;
	}
	else {
		this->textBox1->Text = this->TableInfo[this->Index[*this->RowIndex]]->first->second;
	}
}
private: System::Void textBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	//�G���^�[�L�[�������ꂽ�Ƃ��̃C�x���g
	if (e->KeyCode == Keys::Enter) {
		if (this->ColumnIndex == 0) {
			//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�������Ώۂ̃Z���̕�����Ƃ��Ċi�[����
			this->TableInfo[this->Index[*this->RowIndex]]->first->first = this->textBox1->Text;
			//�Z�����ĕ`�悷��֐����Ăяo��
			this->ReTable(this->pictureBoxDetail, *this->RowIndex);
			//�R���g���[������e�L�X�g�{�b�N�X���폜����
			this->pictureBoxDetail->Controls->Remove(this->textBox1);
		}
		else {
			//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�������Ώۂ̃Z���̕�����Ƃ��Ċi�[����
			this->TableInfo[this->Index[*this->RowIndex]]->first->second = this->textBox1->Text;
			//�Z�����ĕ`�悷��֐����Ăяo��
			this->ReTable(this->pictureBoxDetail, *this->RowIndex);
			//�R���g���[������e�L�X�g�{�b�N�X���폜����
			this->pictureBoxDetail->Controls->Remove(this->textBox1);
		}
	}
}
};
}
