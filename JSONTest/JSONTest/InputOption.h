#pragma once

namespace JSONTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// InputOption �̊T�v
	/// </summary>
	public ref class InputOption : public System::Windows::Forms::Form
	{
	public:
		InputOption(void)
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
		~InputOption()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelJSON;
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
			this->labelJSON = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelJSON
			// 
			this->labelJSON->AutoSize = true;
			this->labelJSON->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelJSON->Location = System::Drawing::Point(44, 51);
			this->labelJSON->Name = L"labelJSON";
			this->labelJSON->Size = System::Drawing::Size(83, 33);
			this->labelJSON->TabIndex = 0;
			this->labelJSON->Text = L"JSON";
			// 
			// InputOption
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1468, 676);
			this->Controls->Add(this->labelJSON);
			this->Name = L"InputOption";
			this->Text = L"InputOption";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
