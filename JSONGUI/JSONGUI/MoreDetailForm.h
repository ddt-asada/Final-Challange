#pragma once

namespace JSONGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MoreDetailForm の概要
	/// </summary>
	/*概要：詳細情報入力画面
	作成日：2017.9.20
	作成者：K.Asada*/
	public ref class MoreDetailForm : public System::Windows::Forms::Form
	{
	public:
		MoreDetailForm(void)
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
	/*概要：フォームロード時のイベント、画面に表示する表画像を生成する
	引数：
	戻り値：なし
	作成日：2017.9.20
	作成者：K.Asada*/
	private: System::Void MoreDetailLoad(System::Object^  sender, System::EventArgs^  e) {
		//表画像生成関数を呼ぶ
		//MoreDetail(this->PictureBoxDetail);
		//作成した画像をコントロールに乗せる
		this->Controls->Add(this->pictureBoxDetail);
	}

	/*概要：表画像クリック時のイベント、選択箇所の記録、ハイライトを行う
	引数：
	戻り値：なし
	作成日：2017.9.20
	作成者：K.Asada*/
	private: System::Void PictureBoxDetailClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
	}
};
}
