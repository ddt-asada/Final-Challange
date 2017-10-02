#pragma once

namespace JSONGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SelectForm の概要
	/// </summary>
	/*概要：メイン画面で何らかの動作をするためにどちらかを選択させたいときに呼び出される選択画面
	作成日：2017.9.28
	作成者：K.Asada*/
	public ref class SelectForm : public System::Windows::Forms::Form
	{
	public:
		SelectForm(void)
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
		~SelectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	public: System::Windows::Forms::Button^  ElderButton;
	public: System::Windows::Forms::Button^  YoungButton;
	private: System::Windows::Forms::Button^  CancelButton;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ElderButton = (gcnew System::Windows::Forms::Button());
			this->YoungButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(524, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"どちらかを選択してください";
			// 
			// ElderButton
			// 
			this->ElderButton->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->ElderButton->Location = System::Drawing::Point(12, 85);
			this->ElderButton->Name = L"ElderButton";
			this->ElderButton->Size = System::Drawing::Size(163, 77);
			this->ElderButton->TabIndex = 1;
			this->ElderButton->UseVisualStyleBackColor = true;
			this->ElderButton->Click += gcnew System::EventHandler(this, &SelectForm::ElderButtonClick);
			// 
			// YoungButton
			// 
			this->YoungButton->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->YoungButton->Location = System::Drawing::Point(181, 85);
			this->YoungButton->Name = L"YoungButton";
			this->YoungButton->Size = System::Drawing::Size(172, 77);
			this->YoungButton->TabIndex = 2;
			this->YoungButton->UseVisualStyleBackColor = true;
			this->YoungButton->Click += gcnew System::EventHandler(this, &SelectForm::YoungButtonClick);
			// 
			// CancelButton
			// 
			this->CancelButton->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->CancelButton->Location = System::Drawing::Point(359, 85);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(177, 77);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"キャンセル";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &SelectForm::CancelButtonClick);
			// 
			// SelectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(547, 191);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->YoungButton);
			this->Controls->Add(this->ElderButton);
			this->Controls->Add(this->label1);
			this->Name = L"SelectForm";
			this->Text = L"SelectForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public:
			String^ selectbutton = "";		//選択したボタンの名前を保持させる文字列

/*概要：メイン画面へ選択したボタンの情報を渡すために選択したボタンをメンバに持たせて保持させるイベント
作成日：2017.9.28
作成者：K.Asada*/
private: System::Void ElderButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//メンバへクリックしたボタンの情報を保持させる
	this->selectbutton = this->ElderButton->Name;
	//選択画面を閉じる
	this->Close();
}

 /*概要：メイン画面へ選択したボタンの情報を渡すために選択したボタンをメンバに持たせて保持させるイベント
 作成日：2017.9.28
 作成者：K.Asada*/
private: System::Void YoungButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//メンバへクリックしたボタンの情報を保持させる
	this->selectbutton = this->YoungButton->Name;
	//選択画面を閉じる
	this->Close();
}

 /*概要：メイン画面へ選択したボタンの情報を渡すために選択したボタンをメンバに持たせて保持させるイベント
 作成日：2017.9.28
 作成者：K.Asada*/
private: System::Void CancelButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//メンバへクリックしたボタンの情報を保持させる
	this->selectbutton = this->CancelButton->Name;
	//選択画面を閉じる
	this->Close();
}
};
}
