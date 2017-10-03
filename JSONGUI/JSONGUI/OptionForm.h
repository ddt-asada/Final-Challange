#pragma once
#include "ConstantString.h"	//����萔�N���X�̃w�b�_

namespace option {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CONSTANTS;		//����萔�N���X�̖��O���


	/// <summary>
	/// OptionForm �̊T�v
	/// </summary>
	/*�T�v�F�ǂݍ��ރt�@�C���̑I����DB�N�G���̓��͂��s���ݒ���
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	public ref class OptionForm : public System::Windows::Forms::Form
	{
	public:
		OptionForm(void)
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
		~OptionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxPath;
	protected:
	private: System::Windows::Forms::TextBox^  textBoxDBQuery;
	private: System::Windows::Forms::Button^  buttonOptionCancel;
	private: System::Windows::Forms::Button^  buttonOptionOK;
	private: System::Windows::Forms::Button^  buttonLoadFile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

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
			this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDBQuery = (gcnew System::Windows::Forms::TextBox());
			this->buttonOptionCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOptionOK = (gcnew System::Windows::Forms::Button());
			this->buttonLoadFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxPath
			// 
			this->textBoxPath->Location = System::Drawing::Point(208, 102);
			this->textBoxPath->Multiline = true;
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->Size = System::Drawing::Size(927, 53);
			this->textBoxPath->TabIndex = 0;
			// 
			// textBoxDBQuery
			// 
			this->textBoxDBQuery->Location = System::Drawing::Point(208, 223);
			this->textBoxDBQuery->Multiline = true;
			this->textBoxDBQuery->Name = L"textBoxDBQuery";
			this->textBoxDBQuery->Size = System::Drawing::Size(927, 53);
			this->textBoxDBQuery->TabIndex = 1;
			// 
			// buttonOptionCancel
			// 
			this->buttonOptionCancel->Location = System::Drawing::Point(1237, 347);
			this->buttonOptionCancel->Name = L"buttonOptionCancel";
			this->buttonOptionCancel->Size = System::Drawing::Size(191, 71);
			this->buttonOptionCancel->TabIndex = 2;
			this->buttonOptionCancel->Text = L"�L�����Z��";
			this->buttonOptionCancel->UseVisualStyleBackColor = true;
			this->buttonOptionCancel->Click += gcnew System::EventHandler(this, &OptionForm::OptionCancelClisk);
			// 
			// buttonOptionOK
			// 
			this->buttonOptionOK->Location = System::Drawing::Point(1062, 347);
			this->buttonOptionOK->Name = L"buttonOptionOK";
			this->buttonOptionOK->Size = System::Drawing::Size(157, 71);
			this->buttonOptionOK->TabIndex = 3;
			this->buttonOptionOK->Text = L"OK";
			this->buttonOptionOK->UseVisualStyleBackColor = true;
			this->buttonOptionOK->Click += gcnew System::EventHandler(this, &OptionForm::OptionOKClick);
			// 
			// buttonLoadFile
			// 
			this->buttonLoadFile->Location = System::Drawing::Point(1157, 102);
			this->buttonLoadFile->Name = L"buttonLoadFile";
			this->buttonLoadFile->Size = System::Drawing::Size(145, 53);
			this->buttonLoadFile->TabIndex = 4;
			this->buttonLoadFile->Text = L"�Q��";
			this->buttonLoadFile->UseVisualStyleBackColor = true;
			this->buttonLoadFile->Click += gcnew System::EventHandler(this, &OptionForm::LoadButtonClick);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(93, 233);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"DB�N�G��";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(50, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 29);
			this->label2->TabIndex = 5;
			this->label2->Text = L"�ǂݍ��ݐ�";
			// 
			// OptionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1440, 438);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonLoadFile);
			this->Controls->Add(this->buttonOptionOK);
			this->Controls->Add(this->buttonOptionCancel);
			this->Controls->Add(this->textBoxDBQuery);
			this->Controls->Add(this->textBoxPath);
			this->Name = L"OptionForm";
			this->Text = L"OptionForm";
			this->Load += gcnew System::EventHandler(this, &OptionForm::OptionForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		ConstantString^ Constants = gcnew ConstantString();		//�萔�N���X���C���X�^���X��
		String^ FilePath = Constants->EMPTY_STRING;				//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽJSON�̃t�@�C���p�X��ۊǂ��镶����
		String^ SendQuery = Constants->EMPTY_STRING;			//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽDB�N�G����ۊǂ��镶����

	/*�T�v�F�t�H�[�����[�h���̃C�x���g�A�O��N�������Ƃ��̏���Ή������e�L�X�g�{�b�N�X�ɔz�u����
	�����Fsender�F�C�x���g�������̊e������i�[�����I�u�W�F�N�g�N���X
		�FEventArg�F
	�߂�l�F�Ȃ�
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	private: System::Void OptionForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//�t�@�C���p�X�e�L�X�g�{�b�N�X�ɑO��N�����Ɏ擾�����t�@�C���p�X���i�[����
		this->textBoxPath->Text = this->FilePath;
		//DB�N�G���e�L�X�g�{�b�N�X�ɑO��N�����Ɏ擾����DB�N�G�����i�[����
		this->textBoxDBQuery->Text = this->SendQuery;
	}

	/*�Q�ƃ{�^���N���b�N���̃C�x���g�A�t�@�C���p�X���擾���邽�߂̃_�C�A���O���J��
	�����FSender
		�FEventArgs
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada
	�X�V���e�F�L�����Z���{�^���ł͂Ȃ�OK�{�^���̃C�x���g���E���悤�ɕύX
	�X�V���F2017.10.3
	�X�V�ҁFK.Asada*/
	private: System::Void LoadButtonClick(System::Object^  sender, System::EventArgs^  e) {
		//�t�@�C���I���_�C�A���O��OK�{�^���������ꂽ��t�@�C���p�X���e�L�X�g�{�b�N�X�֕ۊǂ���
		if (this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//�e�L�X�g�{�b�N�X�փt�@�C���p�X��⊮����
			this->textBoxPath->Text = this->openFileDialog->FileName;
		}
		return;
}

	/*�T�v�FOK�{�^�����N���b�N���ꂽ�Ƃ��̃C�x���g�A�e�L�X�g�{�b�N�X�̒l�������o�̕�����Ɋi�[����
	�����F
	�߂�l�F�Ȃ�
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
private: System::Void OptionOKClick(System::Object^  sender, System::EventArgs^  e) {
	//�Ăяo�����̉�ʂɓn�����߂Ƀe�L�X�g�{�b�N�X�ɓ��͂��ꂽ�t�@�C���p�X�������o�̕�����Ɋi�[����
	this->FilePath = this->textBoxPath->Text;
	//�Ăяo�����̉�ʂɓn�����߂Ƀe�L�X�g�{�b�N�X�ɓ��͂��ꂽDB�N�G���������o�̕�����Ɋi�[����
	this->SendQuery = this->textBoxDBQuery->Text;
	//��ʂ����
	this->Close();
}

	/*�T�v�F�L�����Z���{�^���N���b�N���̃C�x���g�A�e�L�X�g�{�b�N�X�̒l�����̂܂܂ɂ��ĉ�ʂ����
	�����F
	�߂�l�F�Ȃ�
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
private: System::Void OptionCancelClisk(System::Object^  sender, System::EventArgs^  e) {
	//�e�L�X�g�{�b�N�X�̒l��j���������̂ŉ������������ɉ�ʂ����
	this->Close();
}
};
}
