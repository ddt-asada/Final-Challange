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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxParent))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxKey->Location = System::Drawing::Point(209, 250);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(360, 31);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxValue->Location = System::Drawing::Point(209, 337);
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
			this->buttonParent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonParent->Location = System::Drawing::Point(12, 581);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(117, 105);
			this->buttonParent->TabIndex = 3;
			this->buttonParent->Text = L"�e";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &MoreInfoForm::ParentChainButtonClick);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonCancel->Location = System::Drawing::Point(658, 397);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(110, 105);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &MoreInfoForm::CancelButtonClick);
			// 
			// buttonYoungBrother
			// 
			this->buttonYoungBrother->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonYoungBrother->Location = System::Drawing::Point(357, 581);
			this->buttonYoungBrother->Name = L"buttonYoungBrother";
			this->buttonYoungBrother->Size = System::Drawing::Size(102, 105);
			this->buttonYoungBrother->TabIndex = 5;
			this->buttonYoungBrother->Text = L"��";
			this->buttonYoungBrother->UseVisualStyleBackColor = true;
			this->buttonYoungBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::YoungBrotherButtonClick);
			// 
			// buttonElderBrother
			// 
			this->buttonElderBrother->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonElderBrother->Location = System::Drawing::Point(251, 581);
			this->buttonElderBrother->Name = L"buttonElderBrother";
			this->buttonElderBrother->Size = System::Drawing::Size(100, 105);
			this->buttonElderBrother->TabIndex = 6;
			this->buttonElderBrother->Text = L"�Z";
			this->buttonElderBrother->UseVisualStyleBackColor = true;
			this->buttonElderBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::ElderBrotherChainButtonClick);
			// 
			// buttonChild
			// 
			this->buttonChild->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonChild->Location = System::Drawing::Point(135, 581);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(110, 105);
			this->buttonChild->TabIndex = 7;
			this->buttonChild->Text = L"�q";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &MoreInfoForm::ChildChainButtonClick);
			// 
			// buttonOK
			// 
			this->buttonOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonOK->Location = System::Drawing::Point(550, 397);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(102, 105);
			this->buttonOK->TabIndex = 8;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &MoreInfoForm::OKButtonClick);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(108, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"�L�[��";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(148, 340);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 24);
			this->label2->TabIndex = 10;
			this->label2->Text = L"�l";
			// 
			// MoreInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(815, 514);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
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
		Int32^ ParentIndex = 0;	//�e�̐����i�[���郁���o�ϐ�

	/*�T�v�F�ڍ׃_�C�A���O�̃��[�h���̃C�x���g
	�쐬���F2017.9.25
	�쐬�ҁFK.Asada*/
	private: System::Void MoreInfoForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//�L�[�����e�L�X�g�{�b�N�X�Ɋi�[����
		this->textBoxKey->Text = this->TableElem->key;
		//�l���e�L�X�g�{�b�N�X�Ɋi�[����
		this->textBoxValue->Text = this->TableElem->value;
		//�e�̐����J�E���g����
		this->ParentIndex = this->CountParent(this->TableElem);
		//�e�����Ȃ��ꍇ�͉摜�̕`����s��Ȃ�
		if (*this->ParentIndex > 0) {
			//�e��񋓂������̂�`�悷��֐����Ăяo��
			this->infoTableGenerate(this->TableElem, this->pictureBoxParent, *this->ParentIndex);
			//�s�N�`���{�b�N�X��O�ʂɉ����o��
			this->pictureBoxParent->BringToFront();
		}
		return;
	}

	/*�T�v�F�e��ǉ�����Ƃ��ȂǁA�ڍ׃_�C�A���O��������x�J���Ƃ��̊֐�
	�����Fcellchain^ parent�F�ڍׂ��m�F�������\����
	�߂�l�F�Ȃ�
	�쐬���F2017.9.26
	�쐬�ҁFK.Asada*/
			 Void ParentInfo(CellDataChain::cellchain^ parent) {
				 //�ڍ׃_�C�A���O���C���X�^���X��
				 MoreInfoForm^ more = gcnew MoreInfoForm();
				 //�ڍׂ��m�F�������\���̂�n��
				 more->TableElem = parent;
				 //�ڍ׃_�C�A���O���J��
				 more->ShowDialog();
				 //�e�̐����ăJ�E���g����
				 this->ParentIndex = this->CountParent(this->TableElem);
				 //�e��񋓂������̂��ĕ`�悷��֐����Ăяo��
				 this->infoTableGenerate(this->TableElem, this->pictureBoxParent, *this->ParentIndex);
				 return;
			 }

	/*�T�v�F�\���̂̐e�̐����J�E���g����֐�
	�����Fcellchain^ child�F�J�E���g�Ώۂ̍\����
	�߂�l�FInt32 parentcount�F�J�E���g�����e�̐�
	�쐬���F2017.9.26
	�쐬�ҁFK.Asada*/
			 Int32 CountParent(CellDataChain::cellchain^ child) {
				 //�\���̂𑀍삷�邽�߂̃N���X���C���X�^���X��
				 CellDataChain^ CellCtrl = gcnew CellDataChain();
				 //�ԋp�p�̕ϐ���錾
				 Int32 parentcount = 0;
				 //�e���Ȃ��Ȃ�܂ő������Đe�̐����J�E���g
				 for (;;parentcount++) {
					 //�e���擾���Ă���
					 child = CellCtrl->GetParent(child, 1);
					 //�e���擾�ł��Ă��Ȃ���ΏI��
					 if (child == nullptr) {
						 break;
					 }
				 }
				 //�J�E���g�����e��Ԃ�
				 return parentcount;
	}

/*�T�v�FOK�{�^���̃N���b�N�C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
	private: System::Void OKButtonClick(System::Object^  sender, System::EventArgs^  e) {
		//�e�L�X�g�{�b�N�X�̃L�[�����擾����
		this->TableElem->key = this->textBoxKey->Text;
		//�e�L�X�g�{�b�N�X�̒l���擾����
		this->TableElem->value = this->textBoxValue->Text;
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
	//�q��A�������\���̂��i�[����\���̂�錾
	CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
	//���݂̍\���̂Ɏq��A�����Ă��̘A�������q�̍\���̂��擾����
	parent = CellCtrl->ChainParent("", "", this->TableElem);
	//�V�K�ɍ쐬�����q�̍\���̂�Ώۂɂ��ďڍ׃_�C�A���O���J���Ēl����͂���
	this->ParentInfo(parent);
	return;
}

/*�T�v�F�q�{�^���N���b�N���̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void ChildChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�q��A�������\���̂��i�[����\���̂�錾
	CellDataChain::cellchain^ child = gcnew CellDataChain::cellchain();
	//���݂̍\���̂Ɏq��A�����Ă��̘A�������q�̍\���̂��擾����
	child = CellCtrl->ChainChild("", "", this->TableElem);
	//�V�K�ɍ쐬�����q�̍\���̂�Ώۂɂ��ďڍ׃_�C�A���O���J���Ēl����͂���
	this->ParentInfo(child);
	return;
}

/*�T�v�F�Z�{�^���N���b�N���̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void ElderBrotherChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�q��A�������\���̂��i�[����\���̂�錾
	CellDataChain::cellchain^ brother = gcnew CellDataChain::cellchain();
	//���݂̍\���̂Ɏq��A�����Ă��̘A�������q�̍\���̂��擾����
	brother = CellCtrl->ChainElderBrother("", "", this->TableElem);
	//�V�K�ɍ쐬�����q�̍\���̂�Ώۂɂ��ďڍ׃_�C�A���O���J���Ēl����͂���
	this->ParentInfo(brother);
	return;
}

/*�T�v�F��{�^���N���b�N���̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void YoungBrotherButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�q��A�������\���̂��i�[����\���̂�錾
	CellDataChain::cellchain^ brother = gcnew CellDataChain::cellchain();
	//���݂̍\���̂Ɏq��A�����Ă��̘A�������q�̍\���̂��擾����
	brother = CellCtrl->ChainYoungBrother("", "", this->TableElem);
	//�V�K�ɍ쐬�����q�̍\���̂�Ώۂɂ��ďڍ׃_�C�A���O���J���Ēl����͂���
	this->ParentInfo(brother);
	return;
}

/*�T�v�F��ʏ㕔�̃L�[�����\�����ꂽ�摜���N���b�N�����Ƃ��̃C�x���g
�쐬���F2017.9.25
�쐬�ҁFK.Asada*/
private: System::Void PictureBoxParentMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//�`�F�C���\������N���X���C���X�^���X��
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//�N���b�N�������W���i�[���邽�߂̕ϐ���錾
	Int32 clickpoint = 0;
	//�N���b�N�������W�������o�ϐ��֎擾����
	clickpoint = this->GetPoint(e);
	//�N���b�N�����ʒu�̍\���̂��擾���邽�߂̍\���̂�錾
	CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
	//�N���b�N�����ʒu�̍\���̂��擾����֐����Ăяo��
	parent = CellCtrl->GetParent(this->TableElem, clickpoint);
	//�ڍ׃_�C�A���O��\������֐����Ăяo��
	this->ParentInfo(parent);
	return;
}

/*�T�v�F�N���b�N�����摜��̍��W���擾���邽�߂̊֐�
�쐬���F2017.9.26
�쐬�ҁFK.Asada*/
		 Int32 GetPoint(MouseEventArgs^ e) {
			 //�擾�������W���i�[���邽�߂̕ϐ�
			 Int32 point = 0;
			 //���W���v�Z���Ď擾����A�[�����؂�̂Ă��邽�ߍŌ��+1���ĕ␳����
			 point = ((*this->RctWidth * *this->ParentIndex - e->Location.X)/ *this->RctWidth) +1;
			 //�擾�������W��ԋp����
			 return point;
}
};
}
