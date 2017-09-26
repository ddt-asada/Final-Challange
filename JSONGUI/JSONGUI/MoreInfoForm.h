#pragma once

#include "CellDataChain.h"
#include "TableInformation.h"

namespace JSONGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace TableInformation;

	/// <summary>
	/// MoreInfoForm の概要
	/// </summary>
	public ref class MoreInfoForm
		: public TableInformation
//		: public System::Windows::Forms::Form
	{
	public:
		MoreInfoForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}
	private: System::Windows::Forms::Button^  buttonParent;
	public:
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonYoungBrother;
	private: System::Windows::Forms::Button^  buttonElderBrother;
	private: System::Windows::Forms::Button^  buttonChild;
	private: System::Windows::Forms::Button^  buttonOK;

		CellDataChain::cellchain^ ParentChain = gcnew CellDataChain::cellchain();

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MoreInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxKey;
	protected:
	private: System::Windows::Forms::TextBox^  textBoxValue;
	private: System::Windows::Forms::PictureBox^  pictureBoxParent;

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
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxParent = (gcnew System::Windows::Forms::PictureBox());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonYoungBrother = (gcnew System::Windows::Forms::Button());
			this->buttonElderBrother = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxParent))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(156, 260);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(360, 31);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(156, 320);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(360, 31);
			this->textBoxValue->TabIndex = 1;
			// 
			// pictureBoxParent
			// 
			this->pictureBoxParent->Location = System::Drawing::Point(12, 12);
			this->pictureBoxParent->Name = L"pictureBoxParent";
			this->pictureBoxParent->Size = System::Drawing::Size(48, 26);
			this->pictureBoxParent->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxParent->TabIndex = 2;
			this->pictureBoxParent->TabStop = false;
			this->pictureBoxParent->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MoreInfoForm::PictureBoxParentMouseClick);
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(12, 417);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(117, 105);
			this->buttonParent->TabIndex = 3;
			this->buttonParent->Text = L"親";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &MoreInfoForm::ParentChainButtonClick);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(573, 417);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(110, 105);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &MoreInfoForm::CancelButtonClick);
			// 
			// buttonYoungBrother
			// 
			this->buttonYoungBrother->Location = System::Drawing::Point(357, 417);
			this->buttonYoungBrother->Name = L"buttonYoungBrother";
			this->buttonYoungBrother->Size = System::Drawing::Size(102, 105);
			this->buttonYoungBrother->TabIndex = 5;
			this->buttonYoungBrother->Text = L"弟";
			this->buttonYoungBrother->UseVisualStyleBackColor = true;
			this->buttonYoungBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::YoungBrotherButtonClick);
			// 
			// buttonElderBrother
			// 
			this->buttonElderBrother->Location = System::Drawing::Point(251, 417);
			this->buttonElderBrother->Name = L"buttonElderBrother";
			this->buttonElderBrother->Size = System::Drawing::Size(100, 105);
			this->buttonElderBrother->TabIndex = 6;
			this->buttonElderBrother->Text = L"兄";
			this->buttonElderBrother->UseVisualStyleBackColor = true;
			this->buttonElderBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::ElderBrotherChainButtonClick);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(135, 417);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(110, 105);
			this->buttonChild->TabIndex = 7;
			this->buttonChild->Text = L"子";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &MoreInfoForm::ChildChainButtonClick);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(465, 417);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(102, 105);
			this->buttonOK->TabIndex = 8;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &MoreInfoForm::OKButtonClick);
			// 
			// MoreInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 534);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonElderBrother);
			this->Controls->Add(this->buttonYoungBrother);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->pictureBoxParent);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKey);
			this->Name = L"MoreInfoForm";
			this->Text = L"MoreInfoForm";
			this->Load += gcnew System::EventHandler(this, &MoreInfoForm::MoreInfoForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxParent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*概要：詳細ダイアログのロード時のイベント
	作成日：2017.9.25
	作成者：K.Asada*/
	private: System::Void MoreInfoForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//キー名テキストボックスに受け取った構造体のキー名を設定する
		this->textBoxKey->Text = this->ParentChain->key;
		//値テキストボックスに受け取った構造体の値を設定する
		this->textBoxValue->Text = this->ParentChain->value;
		//表画像を生成する関数を呼び出す
		this->infoTableGenerate(this->pictureBoxParent);
		//ピクチャボックスを前面に押し出す
		this->pictureBoxParent->BringToFront();
		
		return;
	}

/*概要：OKボタンのクリックイベント
作成日：2017.9.25
作成者：K.Asada*/
	private: System::Void OKButtonClick(System::Object^  sender, System::EventArgs^  e) {
		//テキストボックスのキー名を取得する
		this->ParentChain->key = this->textBoxKey->Text;
		//テキストボックスの値を取得する
		this->ParentChain->value = this->textBoxValue->Text;
		//画面を閉じる
		this->Close();
	}

/*概要：キャンセルボタンのクリックイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void CancelButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//何もせずに画面を閉じる
	this->Close();
}

/*概要：親ボタンクリック時のイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void ParentChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//値入力用のテキストボックスを新規に作成
	TextBox^ parentkey = gcnew TextBox();
	//値入力用のテキストボックスを新規ダイアログで開く
	parentkey->Show();
	//入力された値を親に連結する
	CellCtrl->ChainParent(parentkey->Text, "", this->ParentChain);
	return;
}

/*概要：子ボタンクリック時のイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void ChildChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//値入力用のテキストボックスを新規に作成
	TextBox^ childkey = gcnew TextBox();
	//値入力用のテキストボックスを新規ダイアログで開く
	childkey->Show();
	//入力された値を親に連結する
	CellCtrl->ChainChild(childkey->Text, "", this->ParentChain);
	return;
}

/*概要：兄ボタンクリック時のイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void ElderBrotherChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//値入力用のテキストボックスを新規に作成
	TextBox^ brotherkey = gcnew TextBox();
	//値入力用のテキストボックスを新規ダイアログで開く
	brotherkey->Show();
	//入力された値を親に連結する
	CellCtrl->ChainElderBrother(brotherkey->Text, "", this->ParentChain);
	return;
}

/*概要：弟ボタンクリック時のイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void YoungBrotherButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//値入力用のテキストボックスを新規に作成
	TextBox^ brotherkey = gcnew TextBox();
	//値入力用のテキストボックスを新規ダイアログで開く
	brotherkey->Show();
	//入力された値を親に連結する
	CellCtrl->ChainYoungBrother(brotherkey->Text, "", this->ParentChain);
	return;
}

/*概要：画面上部のキー名が表示された画像をクリックしたときのイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void PictureBoxParentMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//クリックした座標をメンバ変数へ取得する
	this->GetCellPoint(e);
	//クリックした位置の構造体を取得するための構造体を宣言
	CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
	//クリックした位置の構造体を取得する関数を呼び出す
	parent = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->ParentChain);
	//詳細ダイアログをインスタンス化
	MoreInfoForm^ more = gcnew MoreInfoForm();
	//構造体を渡す
	more->ParentChain = parent;
	//ダイアログを表示する
	more->ShowDialog();
}
};
}
