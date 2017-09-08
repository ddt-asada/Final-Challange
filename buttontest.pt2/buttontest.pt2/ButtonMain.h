#pragma once

#include "MyForm.h"

namespace buttontestpt2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ButtonMain �̊T�v
	/// </summary>
	public ref class ButtonMain : public System::Windows::Forms::Form
	{
	public:
		ButtonMain(void)
		{
			arrayinit();
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~ButtonMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonJoin;
	protected:
	private: System::Windows::Forms::Button^  buttonRetouch;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
			 int Rowindex = 0;			//�N���b�N�����s��ێ�����
			 int Columnindex = 0;		//�N���b�N�������ێ�����
			 int row = 3;				//�`�悷��\�̍s
			 int column = 3;			//�`�悷��\�̗�
			//array<String^, 2>^ ary = gcnew array<String^, 2>(3, 3);//
			 array<String^, 2>^ str = gcnew array<String^, 2>(this->row, this->column);//�\�̒��g
			 array<String^>^ join = gcnew array<String^>(this->row);				//�����ӏ���ێ�����


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
			this->buttonJoin = (gcnew System::Windows::Forms::Button());
			this->buttonRetouch = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonJoin
			// 
			this->buttonJoin->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonJoin->Location = System::Drawing::Point(12, 12);
			this->buttonJoin->Name = L"buttonJoin";
			this->buttonJoin->Size = System::Drawing::Size(246, 84);
			this->buttonJoin->TabIndex = 0;
			this->buttonJoin->Text = L"����/����";
			this->buttonJoin->UseVisualStyleBackColor = true;
			this->buttonJoin->Click += gcnew System::EventHandler(this, &ButtonMain::buttonJoin_Click);
			// 
			// buttonRetouch
			// 
			this->buttonRetouch->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonRetouch->Location = System::Drawing::Point(264, 10);
			this->buttonRetouch->Name = L"buttonRetouch";
			this->buttonRetouch->Size = System::Drawing::Size(198, 84);
			this->buttonRetouch->TabIndex = 1;
			this->buttonRetouch->Text = L"�C��";
			this->buttonRetouch->UseVisualStyleBackColor = true;
			this->buttonRetouch->Click += gcnew System::EventHandler(this, &ButtonMain::buttonRetouch_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(12, 102);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(289, 184);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ButtonMain::pictureBox1_MouseClick);
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ButtonMain::pictureBox1_MouseDoubleClick);
			// 
			// ButtonMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1442, 820);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->buttonRetouch);
			this->Controls->Add(this->buttonJoin);
			this->Name = L"ButtonMain";
			this->Text = L"ButtonMain";
			this->Load += gcnew System::EventHandler(this, &ButtonMain::ButtonMain_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//�z��̒��g������������֐�
	private: System::Void arrayinit() {
		//�z��Ɋi�[���邽�߂̒l
		int count = 1;
		for (int i = 0; i < this->row; i++) {
			//��������p�̕�����z���������
			this->join[i] = "";
			for (int j = 0; j < this->column; j++) {
				//�z��1�`9�̕���������Ɋi�[
			//	this->ary[i, j] = Convert::ToString(count++);
				//Value�̏����l�Ƃ��āu���v���i�[
				this->str[i, j] = "��";
			}
		}
	}

			 //���C����ʂɔz�u����摜��`�悵�Ĕ��f����֐�
	private: System::Void init() {
		//�r�b�g�}�b�v�̒��ɕ`�悷�鐔��
		int count = 1;
		//�`�悷��}�`�������̕�
		int rctwidth = 100;
		//�`�悷��}�`�������̍���
		int rctheight = 100;
		// �r�b�g�}�b�v�N���X(�C���[�W�摜)�̐���
		Bitmap^ img = gcnew Bitmap(rctwidth * this->column + 1, rctheight * this->row + 1);
		//�`����s���O���t�B�b�N�X�N���X�𐶐�
		Graphics^ gr = Graphics::FromImage(img);
		for (int i = 0; i < this->row; i++) {
			//������Ԃł����
			if (this->join[i] != "") {
				count = Convert::ToInt32(this->join[i]) + (i * this->row) + 1;
				// �摜�̈�ɐ���`��
				gr->DrawRectangle(Pens::Black, 0, rctheight * i, rctwidth * this->row, rctheight);
				// �摜�̈�ɕ��������������
				System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
				//�s�̒��S�ɃC���f�b�N�X��t����
				gr->DrawString(Convert::ToString(count++), myFont, Brushes::Black, rctwidth *this-> row / 2, rctheight * i);
			}
			else {
				for (int j = 0; j < this->column; j++) {
					// �摜�̈�ɐ���`��
					gr->DrawRectangle(Pens::Black, rctwidth * j, rctheight * i, rctwidth, rctheight);
					// �摜�̈�ɕ��������������
					System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
					//�\�ɃC���f�b�N�X��t����
					gr->DrawString(Convert::ToString(count++), myFont, Brushes::Black, rctwidth * j, rctheight * i);
				}
			}
		}
		//pictureBox�ɍ쐬�����摜�i�\�j�𔽉f
		this->pictureBox1->Image = img;
	}

	//Value�ύX��ʂ�\������֐�
	private: System::Void ValueDisplay() {
		//�\�̒l�����������邽�߂̕ʃE�B���h�E���C���X�^���X��
		MyForm^ rewrite = gcnew MyForm();
		//�ʃE�B���h�E�̃e�L�X�g�{�b�N�X�ɕ\�̑Ή������l�𔽉f������
		rewrite->textBox1->Text = this->str[this->Rowindex, this->Columnindex];
		//�ʃE�B���h�E���J��
		rewrite->ShowDialog();
		//���͂����l���擾���ă����o�̔z��Ɋi�[
		this->str[this->Rowindex, this->Columnindex] = rewrite->textBox1->Text;
		//���C����ʂ̕\�̏������֐����Ăяo���B
		this->init();
	}


	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

	}

private: System::Void pictureBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Value�ύX��ʂ�\������֐����Ăяo��
	this->ValueDisplay();
}
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//�\�̍s�̍��W���擾����
	this->Rowindex = (e->Location.Y / (this->pictureBox1->Height / this->row));
	//�\�̗�̍��W���擾����
	if (this->join[this->Rowindex] != "") {
		//�����̍��W���擾�B
		this->Columnindex = Convert::ToInt32(this->join[this->Rowindex]);
	}
	else {
		//�\�̍s�̍��W���擾����
		this->Columnindex = (e->Location.X / (this->pictureBox1->Width / this->column));
	}
}
private: System::Void buttonRetouch_Click(System::Object^  sender, System::EventArgs^  e) {
	//Value�ύX��ʂ�\������֐����Ăяo��
	this->ValueDisplay();
}
private: System::Void ButtonMain_Load(System::Object^  sender, System::EventArgs^  e) {
	this->init();
}
private: System::Void buttonJoin_Click(System::Object^  sender, System::EventArgs^  e) {
	//���łɌ�����Ԃł����
	if (join[this->Rowindex] != "") {
		//������Ԃɉ�������B
		this->join[this->Rowindex] = "";
	}
	else {
		//������Ԃɂ���B
		this->join[this->Rowindex] = Convert::ToString(this->Columnindex);
	}
	//�\���ĕ`�悷��
	this->init();
}
};
}
