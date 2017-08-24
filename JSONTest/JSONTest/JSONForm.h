#pragma once

#include "InputOption.h"

namespace JSONTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// JSONForm �̊T�v
	/// </summary>
	public ref class JSONForm : public System::Windows::Forms::Form
	{
	public:
		JSONForm(void)
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
		~JSONForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelRow;
	protected:
	private: System::Windows::Forms::Label^  labelColumn;
	private: System::Windows::Forms::TextBox^  textBoxRow;
	private: System::Windows::Forms::TextBox^  textBoxColumn;
	private: System::Windows::Forms::Button^  buttonInputOption;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::DataGridView^  dataGridViewJSON;

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
			this->labelRow = (gcnew System::Windows::Forms::Label());
			this->labelColumn = (gcnew System::Windows::Forms::Label());
			this->textBoxRow = (gcnew System::Windows::Forms::TextBox());
			this->textBoxColumn = (gcnew System::Windows::Forms::TextBox());
			this->buttonInputOption = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->dataGridViewJSON = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewJSON))->BeginInit();
			this->SuspendLayout();
			// 
			// labelRow
			// 
			this->labelRow->AutoSize = true;
			this->labelRow->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelRow->Location = System::Drawing::Point(46, 25);
			this->labelRow->Name = L"labelRow";
			this->labelRow->Size = System::Drawing::Size(81, 33);
			this->labelRow->TabIndex = 0;
			this->labelRow->Text = L"�^�e";
			// 
			// labelColumn
			// 
			this->labelColumn->AutoSize = true;
			this->labelColumn->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelColumn->Location = System::Drawing::Point(46, 79);
			this->labelColumn->Name = L"labelColumn";
			this->labelColumn->Size = System::Drawing::Size(81, 33);
			this->labelColumn->TabIndex = 1;
			this->labelColumn->Text = L"���R";
			// 
			// textBoxRow
			// 
			this->textBoxRow->Location = System::Drawing::Point(133, 29);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(100, 31);
			this->textBoxRow->TabIndex = 2;
			// 
			// textBoxColumn
			// 
			this->textBoxColumn->Location = System::Drawing::Point(133, 79);
			this->textBoxColumn->Name = L"textBoxColumn";
			this->textBoxColumn->Size = System::Drawing::Size(100, 31);
			this->textBoxColumn->TabIndex = 3;
			// 
			// buttonInputOption
			// 
			this->buttonInputOption->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonInputOption->Location = System::Drawing::Point(270, 25);
			this->buttonInputOption->Name = L"buttonInputOption";
			this->buttonInputOption->Size = System::Drawing::Size(148, 85);
			this->buttonInputOption->TabIndex = 4;
			this->buttonInputOption->Text = L"�ݒ�";
			this->buttonInputOption->UseVisualStyleBackColor = true;
			this->buttonInputOption->Click += gcnew System::EventHandler(this, &JSONForm::buttonInputOption_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(441, 22);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(143, 36);
			this->buttonOK->TabIndex = 5;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &JSONForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(441, 78);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(143, 36);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"�L�����Z��";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &JSONForm::buttonCancel_Click);
			// 
			// dataGridViewJSON
			// 
			this->dataGridViewJSON->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewJSON->Location = System::Drawing::Point(52, 143);
			this->dataGridViewJSON->Name = L"dataGridViewJSON";
			this->dataGridViewJSON->RowTemplate->Height = 33;
			this->dataGridViewJSON->Size = System::Drawing::Size(532, 343);
			this->dataGridViewJSON->TabIndex = 8;
			// 
			// JSONForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1455, 660);
			this->Controls->Add(this->dataGridViewJSON);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonInputOption);
			this->Controls->Add(this->textBoxColumn);
			this->Controls->Add(this->textBoxRow);
			this->Controls->Add(this->labelColumn);
			this->Controls->Add(this->labelRow);
			this->Name = L"JSONForm";
			this->Text = L"JSONForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JSONForm::JSONForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &JSONForm::JSONForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewJSON))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			InputOption^ iopt;	//�ݒ�_�C�A���O���C���X�^���X�����邽�߂̏���
			int row = 0;		//�s�����i�[���鐮���l
			int column = 0;		//�񐔂��i�[���鐮���l

	private: System::Void JSONForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

			 //�ݒ�{�^�����N���b�N�����Ƃ��̏���
private: System::Void buttonInputOption_Click(System::Object^  sender, System::EventArgs^  e) {
	//�ݒ�_�C�A���O���J�����߂ɐݒ�N���X���C���X�^���X������B
	iopt = gcnew InputOption();
	//�ݒ�_�C�A���O���J���B
	iopt->ShowDialog();
}

//���C���̃t�H�[�������Ƃ��̏���
private: System::Void JSONForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//����O�Ƀ��b�Z�[�W�{�b�N�X��\�����Ċm�F���s���B
	if (System::Windows::Forms::DialogResult::Cancel == MessageBox::Show("�I�����܂����H", "�m�F", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)) {
		//�v���O�������I������B
		e->Cancel = true;
	}
}

//OK�{�^���������ꂽ�Ƃ��̏���
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ������𐮐��l�ɕϊ�����֐����Ăяo��
		//�^�e���擾
		this->row = this->IntToString(this->textBoxRow->Text);
		//���R���擾
		this->column = this->IntToString(this->textBoxColumn->Text);
		//�^�e�ƃ��R�̃e�L�X�g�{�b�N�X�ɒl�������Ă��邩�𔻒肷��B
		if (row >= 1 && column >= 1) {
			//�^�e�𕪊�
			this->dataGridViewJSON->ColumnCount = column;
			//���R�𕪊�
			this->dataGridViewJSON->RowCount = row;
		}
	}
	catch (Exception^ ex) {
		//�󂯎�����G���[���e��\������B
		MessageBox::Show(ex->ToString(), "�x��", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

/*�֐����FIntToString
  �T�v�F�󂯎����������𐮐��l�ɕϊ����ĕԋp����֐�
        �G���[�������������������̂Ŋ֐������Ă��܂�
  �����FString�F�����l�ɕϊ�������������
  �߂�l�Fint�F�󂯎����������𐮐��l�ɕϊ������l�B
  �쐬���F2017.8.24
  �쐬�ҁFK.Asada
  */
private:System::Int32 IntToString(String^ con) {
	//�����l�ɕϊ��ł��Ȃ������񂪓��͂���Ă������̗�O����
	try{
		//������𐮐��l�ɕϊ������l��ԋp����B
		return Convert::ToInt32(con);
	}
	catch (FormatException^ ex) {
		//�ϊ��ł��Ȃ����Ƃ�`����B
		throw gcnew Exception("�����l�ɕϊ��ł��Ȃ�������ł��B");
	}
}

/*�֐����FinitMainForm
  �T�v�F�S�Ă̕\�ƒl�����������鏈��
  �����F�Ȃ�
  �߂�l�F�Ȃ�
  �쐬��2017.8.24
  �쐬�ҁFK.Asada
  */
private:System::Void initMainForm() {
	this->row = 0;//�擾�����^�e���������B
	this->column = 0;//�擾�������R���������B
	this->textBoxRow->ResetText();//�^�e�����͂��ꂽ�e�L�X�g�{�b�N�X���������B
	this->textBoxColumn->ResetText();//���R�����͂��ꂽ�e�L�X�g�{�b�N�X���������B
	this->dataGridViewJSON->Columns->Clear();	//�\�̃��R������������B
	this->dataGridViewJSON->Rows->Clear();		//�\�̃^�e������������B
}

//�L�����Z���{�^���������ꂽ�Ƃ��̏���
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	//���C���t�H�[���Ɋւ����̂����ׂď���������B
	this->initMainForm();
}
};
}
