#pragma once

#include <iostream>
#include "MyForm.h"

namespace buttontest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ButtonTest �̊T�v
	/// </summary>
	public ref class ButtonTest : public System::Windows::Forms::Form
	{
	public:
		ButtonTest(void)
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
		~ButtonTest()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
		int x = 0;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
			 array<String^, 2>^ ary = gcnew array<String^, 2>(10, 10);



	protected:



	protected:

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ButtonTest::pictureBox1_Click);
			// 
			// ButtonTest
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1405, 827);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ButtonTest";
			this->Load += gcnew System::EventHandler(this, &ButtonTest::ButtonTest_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//�z��̒��g������������֐�
private: System::Void arrayinit() {
	//�z��Ɋi�[���邽�߂̒l
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//�z��0�`99�̕���������Ɋi�[
			this->ary[i, j] = Convert::ToString(count++);
		}
	}
}

//���C����ʂɔz�u����摜��`�悵�Ĕ��f����֐�
private: System::Void init() {
	//�r�b�g�}�b�v�̒��ɕ`�悷�鐔��
	int count = 0;
	//�`�悷��}�`�������̕�
	int rctwidth = 100;
	  //�`�悷��}�`�������̍���
	int rctheight = 100;
	// �r�b�g�}�b�v�N���X(�C���[�W�摜)�̐���
	Bitmap^ img = gcnew Bitmap(1001, 1001);//this->pictureBox1->Width, this->pictureBox1->Height);
	//�`����s���O���t�B�b�N�X�N���X�𐶐�
	Graphics^ gr = Graphics::FromImage(img);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			// �摜�̈�ɐ���`��
			gr->DrawRectangle(Pens::Black, rctwidth * j, rctheight * i, rctwidth, rctheight);
			// �摜�̈�ɕ��������������
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//�����o�̔z����\�Ɋi�[���镶������擾����
			gr->DrawString(this->ary[i, j], myFont, Brushes::Black, rctwidth * j, rctheight * i);
		}
	}
	//pictureBox�ɍ쐬�����摜�i�\�j�𔽉f
	this->pictureBox1->Image = img;
}

private: System::Void ButtonTest_Load(System::Object^  sender, System::EventArgs^  e) {
	this->init();
	
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//�\�̒l�����������邽�߂̕ʃE�B���h�E���C���X�^���X��
	MyForm^ rewrite = gcnew MyForm();
	//�\�̗�̍��W���擾����
	int columnindex = (e->Location.X / (this->pictureBox1->Width / this->ary->GetLength(1)));
	//�\�̍s�̍��W���擾����
	int rowindex = (e->Location.Y / (this->pictureBox1->Height / this->ary->GetLength(0)));
	//�ʃE�B���h�E�̃e�L�X�g�{�b�N�X�ɕ\�̑Ή������l�𔽉f������
	rewrite->textBox1->Text = this->ary[rowindex, columnindex];
	//�ʃE�B���h�E���J��
	rewrite->ShowDialog();
	//���͂����l���擾���ă����o�̔z��Ɋi�[
	this->ary[rowindex, columnindex] = rewrite->textBox1->Text;
	//���C����ʂ̕\�̏������֐����Ăяo���B
	this->init();
}
};
}
