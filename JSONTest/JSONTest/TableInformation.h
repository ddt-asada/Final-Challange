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
	public ref class TableInformation 
		//: public System::Windows::Forms::Form
		: public TableProcessing
	{
	public:
		TableInformation()
		{
			InitializeComponent();
			this->pictureBoxSelect->Parent = this->pictureBoxDetail;
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

		TableInformation(List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ tblinf)
		{
			this->TableInfo = tblinf;
	//		this->RowIndex = rowindex;
		//	this->ColumnIndex = columnindex;
			InitializeComponent();
			this->pictureBoxSelect->Parent = this->pictureBoxDetail;
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
			this->textBox1->Location = System::Drawing::Point(682, 234);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(71, 30);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &TableInformation::textBox1_KeyDown);
			this->textBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TableInformation::textBox1_MouseDoubleClick);
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
			this->pictureBoxSelect->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TableInformation::pictureBoxSelect_MouseClick);
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
			this->Load += gcnew System::EventHandler(this, &TableInformation::TableInformation_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDetail))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSelect))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBoxDetail_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//クリックした座標を取得する
		this->CalPoint(e);
		//選択箇所をハイライトする
		this->pict(this->pictureBoxSelect);
	}
private: System::Void TableInformation_Load(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBoxDetail->Image = this->ValueChange();
	for (int i = 0; i < this->Index->Count; i++) {
		this->join->Add("");
	}
	this->Row = this->Index->Count;
	this->Column = 2;
}
private: System::Void pictureBoxSelect_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//コントロールにテキストボックスを追加する
	this->pictureBoxDetail->Controls->Add(this->textBox1);
	//テキストボックスを対象のセルの大きさと同じにする
	this->textBox1->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
	//テキストボックスの配置を対象のセルと同じ位置にする
	this->textBox1->Location = System::Drawing::Point(0 + *this->RctWidth * *this->ColumnIndex, 0 + *this->RctHeight * *this->RowIndex);
	//テキストボックスを前面に配置する
	this->textBox1->BringToFront();
	//テキストボックスへ文字列を配置するための分岐
	if (this->ColumnIndex == 0) {
		this->textBox1->Text = this->TableInfo[this->Index[*this->RowIndex]]->first->first;
	}
	else {
		this->textBox1->Text = this->TableInfo[this->Index[*this->RowIndex]]->first->second;
	}
}
private: System::Void textBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	//エンターキーが押されたときのイベント
	if (e->KeyCode == Keys::Enter) {
		if (this->ColumnIndex == 0) {
			//テキストボックスに入力された文字列を対象のセルの文字列として格納する
			this->TableInfo[this->Index[*this->RowIndex]]->first->first = this->textBox1->Text;
			//コントロールからテキストボックスを削除する
			this->pictureBoxDetail->Controls->Remove(this->textBox1);
		}
		else {
			//テキストボックスに入力された文字列を対象のセルの文字列として格納する
			this->TableInfo[this->Index[*this->RowIndex]]->first->second = this->textBox1->Text;
			//コントロールからテキストボックスを削除する
			this->pictureBoxDetail->Controls->Remove(this->textBox1);
		}
	}
}
};
}
