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
