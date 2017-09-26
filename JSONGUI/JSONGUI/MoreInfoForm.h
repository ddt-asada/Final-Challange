#pragma once

#include "CellDataChain.h"
#include "TableInformation.h"

namespace JSONGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace TableInformation;

	/// <summary>
	/// MoreInfoForm �̊T�v
	/// </summary>
	public ref class MoreInfoForm
		: public TableInformation
//		: public System::Windows::Forms::Form
	{
	public:
		MoreInfoForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}
	private: System::Windows::Forms::Button^  buttonParent;
	public:
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonYoungBrother;
	private: System::Windows::Forms::Button^  buttonElderBrother;
	private: System::Windows::Forms::Button^  buttonChild;
	private: System::Windows::Forms::Button^  buttonOK;

		CellDataChain::cellchain^ ParentChain = gcnew CellDataChain::cellchain();

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~MoreInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxKey;
	protected:
	private: System::Windows::Forms::TextBox^  textBoxValue;
	private: System::Windows::Forms::PictureBox^  pictureBoxParent;

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
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxParent = (gcnew System::Windows::Forms::PictureBox());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonYoungBrother = (gcnew System::Windows::Forms::Button());
			this->buttonElderBrother = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxParent))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(156, 260);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(360, 31);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(156, 320);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(360, 31);
			this->textBoxValue->TabIndex = 1;
			// 
			// pictureBoxParent
			// 
			this->pictureBoxParent->Location = System::Drawing::Point(12, 12);
			this->pictureBoxParent->Name = L"pictureBoxParent";
			this->pictureBoxParent->Size = System::Drawing::Size(48, 26);
			this->pictureBoxParent->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxParent->TabIndex = 2;
			this->pictureBoxParent->TabStop = false;
			this->pictureBoxParent->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MoreInfoForm::PictureBoxParentMouseClick);
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(12, 417);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(117, 105);
			this->buttonParent->TabIndex = 3;
			this->buttonParent->Text = L"�e";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &MoreInfoForm::ParentChainButtonClick);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(573, 417);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(110, 105);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &MoreInfoForm::CancelButtonClick);
			// 
			// buttonYoungBrother
			// 
			this->buttonYoungBrother->Location = System::Drawing::Point(357, 417);
			this->buttonYoungBrother->Name = L"buttonYoungBrother";
			this->buttonYoungBrother->Size = System::Drawing::Size(102, 105);
			this->buttonYoungBrother->TabIndex = 5;
			this->buttonYoungBrother->Text = L"��";
			this->buttonYoungBrother->UseVisualStyleBackColor = true;
			this->buttonYoungBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::YoungBrotherButtonClick);
			// 
			// buttonElderBrother
			// 
			this->buttonElderBrother->Location = System::Drawing::Point(251, 417);
			this->buttonElderBrother->Name = L"buttonElderBrother";
			this->buttonElderBrother->Size = System::Drawing::Size(100, 105);
			this->buttonElderBrother->TabIndex = 6;
			this->buttonElderBrother->Text = L"�Z";
			this->buttonElderBrother->UseVisualStyleBackColor = true;
			this->buttonElderBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::ElderBrotherChainButtonClick);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(135, 417);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(110, 105);
			this->buttonChild->TabIndex = 7;
			this->buttonChild->Text = L"�q";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &MoreInfoForm::ChildChainButtonClick);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(465, 417);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(102, 105);
			this->buttonOK->TabIndex = 8;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &MoreInfoForm::OKButtonClick);
			// 
			// MoreInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 534);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonElderBrother);
			this->Controls->Add(this->buttonYoungBrother);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->pictureBoxParent);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKey);
			this->Name = L"MoreInfoForm";
			this->Text = L"MoreInfoForm";
			this->Load += gcnew System::EventHandler(this, &MoreInfoForm::MoreInfoForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxParent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*�T�v�F�ڍ׃_�C�A���O�̃��[�h���̃C�x���g
	�쐬���F2017.9.25
	�쐬�ҁFK.Asada*/
	private: System::Void MoreInfoForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//�L�[���e�L�X�g�{�b�N�X�Ɏ󂯎�����\���̂̃L�[����ݒ肷��
		this->textBoxKey->Text = this->ParentChain->key;
		//�l�e�L�X�g�{�b�N�X�Ɏ󂯎�����\���̂̒l��ݒ肷��
		this->textBoxValue->Text = this->ParentChain->value;
		//�\�摜�𐶐�����֐����Ăяo��
		this->infoTableGenerate(this->pictureBoxParent);
		//�s�N�`���{�b�N�X��O�ʂɉ����o��
		this->pictureBoxParent->BringToFront();
		
		return;
	}

/*�T�v�FOK�{�^���̃N���b�N�C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
	private: System::Void OKButtonClick(System::Object^  sender, System::EventArgs^  e) {
		//�e�L�X�g�{�b�N�X�̃L�[�����擾����
		this->ParentChain->key = this->textBoxKey->Text;
		//�e�L�X�g�{�b�N�X�̒l���擾����
		this->ParentChain->value = this->textBoxValue->Text;
		//��ʂ����
		this->Close();
	}

/*�T�v�F�L�����Z���{�^���̃N���b�N�C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void CancelButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//���������ɉ�ʂ����
	this->Close();
}

/*�T�v�F�e�{�^���N���b�N���̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void ParentChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�ɍ쐬
	TextBox^ parentkey = gcnew TextBox();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�_�C�A���O�ŊJ��
	parentkey->Show();
	//���͂��ꂽ�l��e�ɘA������
	CellCtrl->ChainParent(parentkey->Text, "", this->ParentChain);
	return;
}

/*�T�v�F�q�{�^���N���b�N���̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void ChildChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�ɍ쐬
	TextBox^ childkey = gcnew TextBox();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�_�C�A���O�ŊJ��
	childkey->Show();
	//���͂��ꂽ�l��e�ɘA������
	CellCtrl->ChainChild(childkey->Text, "", this->ParentChain);
	return;
}

/*�T�v�F�Z�{�^���N���b�N���̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void ElderBrotherChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�ɍ쐬
	TextBox^ brotherkey = gcnew TextBox();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�_�C�A���O�ŊJ��
	brotherkey->Show();
	//���͂��ꂽ�l��e�ɘA������
	CellCtrl->ChainElderBrother(brotherkey->Text, "", this->ParentChain);
	return;
}

/*�T�v�F��{�^���N���b�N���̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void YoungBrotherButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�ɍ쐬
	TextBox^ brotherkey = gcnew TextBox();
	//�l���͗p�̃e�L�X�g�{�b�N�X��V�K�_�C�A���O�ŊJ��
	brotherkey->Show();
	//���͂��ꂽ�l��e�ɘA������
	CellCtrl->ChainYoungBrother(brotherkey->Text, "", this->ParentChain);
	return;
}

/*�T�v�F��ʏ㕔�̃L�[�����\�����ꂽ�摜���N���b�N�����Ƃ��̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void PictureBoxParentMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�N���b�N�������W�������o�ϐ��֎擾����
	this->GetCellPoint(e);
	//�N���b�N�����ʒu�̍\���̂��擾���邽�߂̍\���̂�錾
	CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
	//�N���b�N�����ʒu�̍\���̂��擾����֐����Ăяo��
	parent = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->ParentChain);
	//�ڍ׃_�C�A���O���C���X�^���X��
	MoreInfoForm^ more = gcnew MoreInfoForm();
	//�\���̂�n��
	more->ParentChain = parent;
	//�_�C�A���O��\������
	more->ShowDialog();
}
};
}
