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
	/// TableInformation の概要
	/// </summary>
	public ref class TableInformation : public System::Windows::Forms::Form
	{
	public:
		TableInformation(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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
		String^ JSONFilePath = MyConst->EMPTY_STRING;		//入力されたJSONのファイルパスを格納するための文字列。
		String^ DBQuery = MyConst->EMPTY_STRING;			//入力されたDBへ投げるクエリを格納する文字列。
		String^ DBResult = MyConst->EMPTY_STRING;			//DBとの通信結果を格納する文字列。
		Int32^ TextIndex = 0;				//フォーカス中の文字列判定用の変数
		Int32^ column = MyConst->ZERO;						//表の列数
		Int32^ row = MyConst->ZERO;							//表の行数
		Int32^ Row = 3;			//表の行数
		Int32^ Column = 3;		//表の列数
		Int32^ RowIndex = 0;		//クリックされたセルの行座標
		Int32^ ColumnIndex = 0;	//クリックされたセルの列座標
		Int32^ RctWidth = 200;		//セル一つ当たりの幅
		Int32^ RctHeight = 100;	//セル一つ当たりの高さ
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ TableInfo = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();
	private: System::Windows::Forms::PictureBox^  pictureBoxDetail;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::PictureBox^  pictureBoxSelect;
	public:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
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
