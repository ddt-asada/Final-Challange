#pragma once

namespace JSONGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MoreDetailForm �̊T�v
	/// </summary>
	/*�T�v�F�ڍ׏����͉��
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	public ref class MoreDetailForm : public System::Windows::Forms::Form
	{
	public:
		MoreDetailForm(void)
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
		~MoreDetailForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxCell;
	private: System::Windows::Forms::PictureBox^  pictureBoxSelect;
	protected:

	private: System::Windows::Forms::PictureBox^  pictureBoxDetail;

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
			this->textBoxCell = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxSelect = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDetail = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSelect))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDetail))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxCell
			// 
			this->textBoxCell->Location = System::Drawing::Point(675, 69);
			this->textBoxCell->Name = L"textBoxCell";
			this->textBoxCell->Size = System::Drawing::Size(100, 31);
			this->textBoxCell->TabIndex = 0;
			// 
			// pictureBoxSelect
			// 
			this->pictureBoxSelect->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxSelect->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxSelect->Location = System::Drawing::Point(481, 260);
			this->pictureBoxSelect->Name = L"pictureBoxSelect";
			this->pictureBoxSelect->Size = System::Drawing::Size(100, 50);
			this->pictureBoxSelect->TabIndex = 1;
			this->pictureBoxSelect->TabStop = false;
			// 
			// pictureBoxDetail
			// 
			this->pictureBoxDetail->Location = System::Drawing::Point(12, 12);
			this->pictureBoxDetail->Name = L"pictureBoxDetail";
			this->pictureBoxDetail->Size = System::Drawing::Size(100, 50);
			this->pictureBoxDetail->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxDetail->TabIndex = 2;
			this->pictureBoxDetail->TabStop = false;
			this->pictureBoxDetail->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MoreDetailForm::PictureBoxDetailClick);
			// 
			// MoreDetailForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1308, 738);
			this->Controls->Add(this->pictureBoxDetail);
			this->Controls->Add(this->pictureBoxSelect);
			this->Controls->Add(this->textBoxCell);
			this->Name = L"MoreDetailForm";
			this->Text = L"MoreDetailForm";
			this->Load += gcnew System::EventHandler(this, &MoreDetailForm::MoreDetailLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSelect))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDetail))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*�T�v�F�t�H�[�����[�h���̃C�x���g�A��ʂɕ\������\�摜�𐶐�����
	�����F
	�߂�l�F�Ȃ�
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	private: System::Void MoreDetailLoad(System::Object^  sender, System::EventArgs^  e) {
		//�\�摜�����֐����Ă�
		//MoreDetail(this->PictureBoxDetail);
		//�쐬�����摜���R���g���[���ɏ悹��
		this->Controls->Add(this->pictureBoxDetail);
	}

	/*�T�v�F�\�摜�N���b�N���̃C�x���g�A�I���ӏ��̋L�^�A�n�C���C�g���s��
	�����F
	�߂�l�F�Ȃ�
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada*/
	private: System::Void PictureBoxDetailClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
	}
};
}
