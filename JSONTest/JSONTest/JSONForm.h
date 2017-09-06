#pragma once

#include "InputOption.h"
#include "TableInformation.h"
#include "CONSTANTSTRING.h"
#include "Processing.h"

namespace JSONTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace process;

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
	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: System::Data::DataSet^  dataSet1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;





















	public:
		constantstring::CONSTANTSTRING^ MyConst = gcnew constantstring::CONSTANTSTRING();

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

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  buttonConversion2;

	private: System::Windows::Forms::Button^  buttonCancel2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonOK2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonInputOption2;
	private: System::Windows::Forms::TextBox^  textBoxRow2;
	private: System::Windows::Forms::TextBox^  textBoxColumn2;




	private: System::Windows::Forms::Button^  buttonConversion;


	private:
		String^ JSONFilePath = MyConst->EMPTY_STRING;		//���͂��ꂽJSON�̃t�@�C���p�X���i�[���邽�߂̕�����B
		String^ DBQuery = MyConst->EMPTY_STRING;			//���͂��ꂽDB�֓�����N�G�����i�[���镶����B
		String^ DBResult = MyConst->EMPTY_STRING;			//DB�Ƃ̒ʐM���ʂ��i�[���镶����B
		Int32^ column = MyConst->ZERO;						//�\�̗�
		Int32^ row = MyConst->ZERO;							//�\�̍s��
		vector<pair<pair<string, string>, string>>* infotable = new vector<pair<pair<string, string>, string>>();
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonConversion = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->buttonConversion2 = (gcnew System::Windows::Forms::Button());
			this->buttonCancel2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonOK2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonInputOption2 = (gcnew System::Windows::Forms::Button());
			this->textBoxRow2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxColumn2 = (gcnew System::Windows::Forms::TextBox());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->SuspendLayout();
			// 
			// labelRow
			// 
			this->labelRow->AutoSize = true;
			this->labelRow->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelRow->Location = System::Drawing::Point(0, 13);
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
			this->labelColumn->Location = System::Drawing::Point(0, 79);
			this->labelColumn->Name = L"labelColumn";
			this->labelColumn->Size = System::Drawing::Size(81, 33);
			this->labelColumn->TabIndex = 1;
			this->labelColumn->Text = L"���R";
			// 
			// textBoxRow
			// 
			this->textBoxRow->Location = System::Drawing::Point(102, 13);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(100, 31);
			this->textBoxRow->TabIndex = 2;
			this->textBoxRow->Text = L"0";
			// 
			// textBoxColumn
			// 
			this->textBoxColumn->Location = System::Drawing::Point(102, 83);
			this->textBoxColumn->Name = L"textBoxColumn";
			this->textBoxColumn->Size = System::Drawing::Size(100, 31);
			this->textBoxColumn->TabIndex = 3;
			this->textBoxColumn->Text = L"0";
			// 
			// buttonInputOption
			// 
			this->buttonInputOption->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonInputOption->Location = System::Drawing::Point(249, 13);
			this->buttonInputOption->Name = L"buttonInputOption";
			this->buttonInputOption->Size = System::Drawing::Size(169, 101);
			this->buttonInputOption->TabIndex = 4;
			this->buttonInputOption->Text = L"�ݒ�";
			this->buttonInputOption->UseVisualStyleBackColor = true;
			this->buttonInputOption->Click += gcnew System::EventHandler(this, &JSONForm::buttonInputOption_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(612, 13);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(143, 36);
			this->buttonOK->TabIndex = 5;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &JSONForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(612, 76);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(143, 36);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"�L�����Z��";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &JSONForm::buttonCancel_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1466, 898);
			this->tabControl1->TabIndex = 9;
			// 
			// tabPage1
			// 
			this->tabPage1->AutoScroll = true;
			this->tabPage1->Controls->Add(this->dataGridView2);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->buttonConversion);
			this->tabPage1->Controls->Add(this->buttonCancel);
			this->tabPage1->Controls->Add(this->labelRow);
			this->tabPage1->Controls->Add(this->buttonOK);
			this->tabPage1->Controls->Add(this->labelColumn);
			this->tabPage1->Controls->Add(this->buttonInputOption);
			this->tabPage1->Controls->Add(this->textBoxRow);
			this->tabPage1->Controls->Add(this->textBoxColumn);
			this->tabPage1->Location = System::Drawing::Point(8, 39);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1450, 851);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &JSONForm::tabPage1_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(662, 185);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 33;
			this->dataGridView2->Size = System::Drawing::Size(559, 612);
			this->dataGridView2->TabIndex = 17;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 185);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(597, 660);
			this->dataGridView1->TabIndex = 16;
			this->dataGridView1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &JSONForm::dataGridView1_MouseDown);
			// 
			// buttonConversion
			// 
			this->buttonConversion->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonConversion->Location = System::Drawing::Point(1275, 744);
			this->buttonConversion->Name = L"buttonConversion";
			this->buttonConversion->Size = System::Drawing::Size(169, 101);
			this->buttonConversion->TabIndex = 15;
			this->buttonConversion->Text = L"�ϊ�";
			this->buttonConversion->UseVisualStyleBackColor = true;
			this->buttonConversion->Click += gcnew System::EventHandler(this, &JSONForm::buttonConversion_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->buttonConversion2);
			this->tabPage2->Controls->Add(this->buttonCancel2);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->buttonOK2);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->buttonInputOption2);
			this->tabPage2->Controls->Add(this->textBoxRow2);
			this->tabPage2->Controls->Add(this->textBoxColumn2);
			this->tabPage2->Location = System::Drawing::Point(8, 39);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1450, 851);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonConversion2
			// 
			this->buttonConversion2->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonConversion2->Location = System::Drawing::Point(1246, 482);
			this->buttonConversion2->Name = L"buttonConversion2";
			this->buttonConversion2->Size = System::Drawing::Size(169, 101);
			this->buttonConversion2->TabIndex = 14;
			this->buttonConversion2->Text = L"�ϊ�";
			this->buttonConversion2->UseVisualStyleBackColor = true;
			this->buttonConversion2->Click += gcnew System::EventHandler(this, &JSONForm::buttonConversion_Click);
			// 
			// buttonCancel2
			// 
			this->buttonCancel2->Location = System::Drawing::Point(621, 79);
			this->buttonCancel2->Name = L"buttonCancel2";
			this->buttonCancel2->Size = System::Drawing::Size(143, 36);
			this->buttonCancel2->TabIndex = 13;
			this->buttonCancel2->Text = L"�L�����Z��";
			this->buttonCancel2->UseVisualStyleBackColor = true;
			this->buttonCancel2->Click += gcnew System::EventHandler(this, &JSONForm::buttonCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(9, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 33);
			this->label1->TabIndex = 7;
			this->label1->Text = L"�^�e";
			// 
			// buttonOK2
			// 
			this->buttonOK2->Location = System::Drawing::Point(621, 16);
			this->buttonOK2->Name = L"buttonOK2";
			this->buttonOK2->Size = System::Drawing::Size(143, 36);
			this->buttonOK2->TabIndex = 12;
			this->buttonOK2->Text = L"OK";
			this->buttonOK2->UseVisualStyleBackColor = true;
			this->buttonOK2->Click += gcnew System::EventHandler(this, &JSONForm::buttonOK_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(9, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 33);
			this->label2->TabIndex = 8;
			this->label2->Text = L"���R";
			// 
			// buttonInputOption2
			// 
			this->buttonInputOption2->Font = (gcnew System::Drawing::Font(L"�l�r �S�V�b�N", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonInputOption2->Location = System::Drawing::Point(258, 14);
			this->buttonInputOption2->Name = L"buttonInputOption2";
			this->buttonInputOption2->Size = System::Drawing::Size(169, 101);
			this->buttonInputOption2->TabIndex = 11;
			this->buttonInputOption2->Text = L"�ݒ�";
			this->buttonInputOption2->UseVisualStyleBackColor = true;
			this->buttonInputOption2->Click += gcnew System::EventHandler(this, &JSONForm::buttonInputOption_Click);
			// 
			// textBoxRow2
			// 
			this->textBoxRow2->Location = System::Drawing::Point(111, 16);
			this->textBoxRow2->Name = L"textBoxRow2";
			this->textBoxRow2->Size = System::Drawing::Size(100, 31);
			this->textBoxRow2->TabIndex = 9;
			this->textBoxRow2->Text = L"0";
			// 
			// textBoxColumn2
			// 
			this->textBoxColumn2->Location = System::Drawing::Point(111, 86);
			this->textBoxColumn2->Name = L"textBoxColumn2";
			this->textBoxColumn2->Size = System::Drawing::Size(100, 31);
			this->textBoxColumn2->TabIndex = 10;
			this->textBoxColumn2->Text = L"0";
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// JSONForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1466, 898);
			this->Controls->Add(this->tabControl1);
			this->DoubleBuffered = true;
			this->Name = L"JSONForm";
			this->Text = L"JSONForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JSONForm::JSONForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &JSONForm::JSONForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
//			InputOption^ iopt;	//�ݒ�_�C�A���O���C���X�^���X�����邽�߂̏���

	private: System::Void JSONForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	//�ݒ�{�^�����N���b�N�����Ƃ��̏���
private: System::Void buttonInputOption_Click(System::Object^  sender, System::EventArgs^  e) {
	//�ݒ�_�C�A���O���J�����߂ɐݒ�N���X���C���X�^���X������B
	InputOption^ iopt = gcnew InputOption();
	//�ݒ�_�C�A���O��JSON�t�@�C���p�X�����͂��ꂽ�e�L�X�g�{�b�N�X�ɑO��Ɏ󂯎�����p�X��ݒ肷��B
	iopt->FilePath = this->JSONFilePath;
	//�ݒ�_�C�A���O�̃N�G���̃e�L�X�g�{�b�N�X�ɑO��󂯎�����l���Z�b�g����B
	iopt->SendQuery = this->DBQuery;
	//�ݒ�_�C�A���O���J���B
	iopt->ShowDialog();
	//�ݒ��ʂɂĎ擾�����t�@�C���p�X�������o�ϐ��֊i�[����B
	this->JSONFilePath = iopt->FilePath;
	//�ݒ��ʂɂĎ擾����DB�Ƃ̒ʐM���ʂ������o�ϐ��֊i�[����B
	this->DBResult;
	//�ݒ��ʂɂĎ擾����DB�Ƃ̒ʐM���ʂ������o�ϐ��֊i�[����B
	this->DBQuery = iopt->SendQuery;
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
	//�\�𐶐����邽�߂̃N���X���C���X�^���X��
	Processing^ table = gcnew Processing(this->JSONFilePath, this->DBQuery);
	table->Row = Convert::ToInt32(this->textBoxRow->Text);
	table->Column = Convert::ToInt32(this->textBoxColumn->Text);

	table->run();

	this->column = table->Column;
	this->row = table->Row;

	this->dataGridView1->ColumnCount = *this->column;
	this->dataGridView1->RowCount = *this->row;

	//�\�𐶐��B
	//�^�C�g����ݒ�B
	auto itr = table->rettable->begin();
	String^ str;

	this->infotable->push_back(pair<pair<string, string>, string>(make_pair("�e�L�[", itr->first), "title"));
	itr++;
	if (itr->first == "class") {
		this->infotable->push_back(pair<pair<string, string>, string>(make_pair(itr->first, itr->second), "title"));
		itr++;
	}

	for (int i = 0; i < *this->row; i++) {
		if (itr->second == "" && ((itr + 1)->first != "text" && (itr + 1)->first != "array" && (itr + 1)->first != "html")) {
			this->infotable->push_back(pair<pair<string, string>, string>(make_pair("�e�L�[", itr->first), 'y' + to_string(i)));
			itr++;
		}
		if (itr->first == "class") {
			this->infotable->push_back(pair<pair<string, string>, string>(make_pair(itr->first, itr->second), 'y'+ to_string(i)));
			itr++;
		}

		for (int j = 0; j < *this->column; j++) {
			for (; itr != table->rettable->end(); ++itr) {
				if (itr->first == "text" || itr->first == "array" || itr->first == "html") {
					str = gcnew String((itr->second).c_str());
					this->infotable->push_back(pair<pair<string, string>, string>(make_pair(itr->first, itr->second), 'x' + to_string(j) + to_string(i)));
					itr++;
					this->dataGridView1->Rows[i]->Cells[j]->Value = str;
					break;
				}
				else if (itr->first == "colspan") {
					this->infotable->push_back(pair<pair<string, string>, string>(make_pair(itr->first, itr->second), 'x' + to_string(j) + to_string(i)));
					j += stoi(itr->second) - 1;
				}
				else if (itr->second == "") {
					this->infotable->push_back(pair<pair<string, string>, string>(make_pair("�e�L�[", itr->first), 'x' + to_string(j) + to_string(i)));
				}
				else {
					this->infotable->push_back(pair<pair<string, string>, string>(make_pair(itr->first, itr->second), 'x' + to_string(j) + to_string(i)));
				}
			}
			//���񏈗����̓^�C�g�����擾�����Ƃ��ă��[�v�𔲂���
			if (i == 0 && j == 0) {
				break;
			}
		}
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
	this->textBoxRow->Text = MyConst->ZERO_STRING;//�^�e�����͂��ꂽ�e�L�X�g�{�b�N�X���������B
	this->textBoxColumn->Text = MyConst->ZERO_STRING;//���R�����͂��ꂽ�e�L�X�g�{�b�N�X���������B
	this->textBoxRow2->Text = MyConst->ZERO_STRING;//�^�e�����͂��ꂽ�e�L�X�g�{�b�N�X���������B
	this->textBoxColumn2->Text = MyConst->ZERO_STRING;//���R�����͂��ꂽ�e�L�X�g�{�b�N�X���������B
	this->JSONFilePath = MyConst->EMPTY_STRING;		//JSON�̓ǂݍ��ݐ�̃t�@�C���p�X���������B
	this->DBQuery = MyConst->EMPTY_STRING;			//DB�N�G�����������B
	this->DBResult = MyConst->EMPTY_STRING;			//DB�Ƃ̒ʐM���ʂ�����������B
}

//�L�����Z���{�^���������ꂽ�Ƃ��̏���
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	//���C���t�H�[���Ɋւ����̂����ׂď���������B
	this->initMainForm();
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void buttonConversion_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void dataGridView1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		DataGridView::HitTestInfo^ hit = ((DataGridView^)sender)->HitTest(e->X, e->Y);
		string xindex = 'x' + to_string(hit->ColumnIndex) + to_string(hit->RowIndex);
		string yindex = 'y' + to_string(hit->RowIndex);
		auto itr = this->infotable->begin();
		this->dataGridView2->RowCount = 1;
		this->dataGridView2->ColumnCount = 2;
		for (; itr != this->infotable->end(); itr++) {
			if (itr->second == "title") {
				this->dataGridView2->Rows->Add(gcnew String((itr->first.first).c_str()), gcnew String((itr->first.second).c_str()));
			}
			else if (itr->second == "y0" || itr->second == yindex || itr->second == xindex) {
				this->dataGridView2->Rows->Add(gcnew String((itr->first.first).c_str()), gcnew String((itr->first.second).c_str()));
			}
		}
}
};
}
