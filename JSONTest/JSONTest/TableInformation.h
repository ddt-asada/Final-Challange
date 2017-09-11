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
	public ref class TableInformation : public System::Windows::Forms::Form
	{
	public:
		TableInformation(void)
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
		String^ JSONFilePath = MyConst->EMPTY_STRING;		//���͂��ꂽJSON�̃t�@�C���p�X���i�[���邽�߂̕�����B
		String^ DBQuery = MyConst->EMPTY_STRING;			//���͂��ꂽDB�֓�����N�G�����i�[���镶����B
		String^ DBResult = MyConst->EMPTY_STRING;			//DB�Ƃ̒ʐM���ʂ��i�[���镶����B
		Int32^ TextIndex = 0;				//�t�H�[�J�X���̕����񔻒�p�̕ϐ�
		Int32^ column = MyConst->ZERO;						//�\�̗�
		Int32^ row = MyConst->ZERO;							//�\�̍s��
		Int32^ Row = 3;			//�\�̍s��
		Int32^ Column = 3;		//�\�̗�
		Int32^ RowIndex = 0;		//�N���b�N���ꂽ�Z���̍s���W
		Int32^ ColumnIndex = 0;	//�N���b�N���ꂽ�Z���̗���W
		Int32^ RctWidth = 200;		//�Z���������̕�
		Int32^ RctHeight = 100;	//�Z���������̍���
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ TableInfo = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();
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
			this->textBox1->Location = System::Drawing::Point(657, 208);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(71, 30);
			this->textBox1->TabIndex = 1;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDetail))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSelect))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBoxDetail_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	}
};
}
