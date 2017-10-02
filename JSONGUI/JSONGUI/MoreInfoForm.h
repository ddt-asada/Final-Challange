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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxParent))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxKey->Location = System::Drawing::Point(209, 250);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(360, 31);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxValue->Location = System::Drawing::Point(209, 337);
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
			this->buttonParent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonParent->Location = System::Drawing::Point(12, 581);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(117, 105);
			this->buttonParent->TabIndex = 3;
			this->buttonParent->Text = L"親";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &MoreInfoForm::ParentChainButtonClick);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonCancel->Location = System::Drawing::Point(658, 397);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(110, 105);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &MoreInfoForm::CancelButtonClick);
			// 
			// buttonYoungBrother
			// 
			this->buttonYoungBrother->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonYoungBrother->Location = System::Drawing::Point(357, 581);
			this->buttonYoungBrother->Name = L"buttonYoungBrother";
			this->buttonYoungBrother->Size = System::Drawing::Size(102, 105);
			this->buttonYoungBrother->TabIndex = 5;
			this->buttonYoungBrother->Text = L"弟";
			this->buttonYoungBrother->UseVisualStyleBackColor = true;
			this->buttonYoungBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::YoungBrotherButtonClick);
			// 
			// buttonElderBrother
			// 
			this->buttonElderBrother->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonElderBrother->Location = System::Drawing::Point(251, 581);
			this->buttonElderBrother->Name = L"buttonElderBrother";
			this->buttonElderBrother->Size = System::Drawing::Size(100, 105);
			this->buttonElderBrother->TabIndex = 6;
			this->buttonElderBrother->Text = L"兄";
			this->buttonElderBrother->UseVisualStyleBackColor = true;
			this->buttonElderBrother->Click += gcnew System::EventHandler(this, &MoreInfoForm::ElderBrotherChainButtonClick);
			// 
			// buttonChild
			// 
			this->buttonChild->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonChild->Location = System::Drawing::Point(135, 581);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(110, 105);
			this->buttonChild->TabIndex = 7;
			this->buttonChild->Text = L"子";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &MoreInfoForm::ChildChainButtonClick);
			// 
			// buttonOK
			// 
			this->buttonOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonOK->Location = System::Drawing::Point(550, 397);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(102, 105);
			this->buttonOK->TabIndex = 8;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &MoreInfoForm::OKButtonClick);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(108, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"キー名";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(148, 340);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 24);
			this->label2->TabIndex = 10;
			this->label2->Text = L"値";
			// 
			// MoreInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(815, 514);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
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
		Int32^ ParentIndex = 0;	//親の数を格納するメンバ変数

	/*概要：詳細ダイアログのロード時のイベント
	作成日：2017.9.25
	作成者：K.Asada*/
	private: System::Void MoreInfoForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//キー名をテキストボックスに格納する
		this->textBoxKey->Text = this->TableElem->key;
		//値をテキストボックスに格納する
		this->textBoxValue->Text = this->TableElem->value;
		//親の数をカウントする
		this->ParentIndex = this->CountParent(this->TableElem);
		//親がいない場合は画像の描画を行わない
		if (*this->ParentIndex > 0) {
			//親を列挙したものを描画する関数を呼び出す
			this->infoTableGenerate(this->TableElem, this->pictureBoxParent, *this->ParentIndex);
			//ピクチャボックスを前面に押し出す
			this->pictureBoxParent->BringToFront();
		}
		return;
	}

	/*概要：親を追加するときなど、詳細ダイアログをもう一度開くときの関数
	引数：cellchain^ parent：詳細を確認したい構造体
	戻り値：なし
	作成日：2017.9.26
	作成者：K.Asada*/
			 Void ParentInfo(CellDataChain::cellchain^ parent) {
				 //詳細ダイアログをインスタンス化
				 MoreInfoForm^ more = gcnew MoreInfoForm();
				 //詳細を確認したい構造体を渡す
				 more->TableElem = parent;
				 //詳細ダイアログを開く
				 more->ShowDialog();
				 //親の数を再カウントする
				 this->ParentIndex = this->CountParent(this->TableElem);
				 //親を列挙したものを再描画する関数を呼び出す
				 this->infoTableGenerate(this->TableElem, this->pictureBoxParent, *this->ParentIndex);
				 return;
			 }

	/*概要：構造体の親の数をカウントする関数
	引数：cellchain^ child：カウント対象の構造体
	戻り値：Int32 parentcount：カウントした親の数
	作成日：2017.9.26
	作成者：K.Asada*/
			 Int32 CountParent(CellDataChain::cellchain^ child) {
				 //構造体を操作するためのクラスをインスタンス化
				 CellDataChain^ CellCtrl = gcnew CellDataChain();
				 //返却用の変数を宣言
				 Int32 parentcount = 0;
				 //親がなくなるまで走査して親の数をカウント
				 for (;;parentcount++) {
					 //親を取得していく
					 child = CellCtrl->GetParent(child, 1);
					 //親が取得できていなければ終了
					 if (child == nullptr) {
						 break;
					 }
				 }
				 //カウントした親を返す
				 return parentcount;
	}

/*概要：OKボタンのクリックイベント
作成日：2017.9.25
作成者：K.Asada*/
	private: System::Void OKButtonClick(System::Object^  sender, System::EventArgs^  e) {
		//テキストボックスのキー名を取得する
		this->TableElem->key = this->textBoxKey->Text;
		//テキストボックスの値を取得する
		this->TableElem->value = this->textBoxValue->Text;
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
	//子を連結した構造体を格納する構造体を宣言
	CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
	//現在の構造体に子を連結してその連結した子の構造体を取得する
	parent = CellCtrl->ChainParent("", "", this->TableElem);
	//新規に作成した子の構造体を対象にして詳細ダイアログを開いて値を入力する
	this->ParentInfo(parent);
	return;
}

/*概要：子ボタンクリック時のイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void ChildChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//子を連結した構造体を格納する構造体を宣言
	CellDataChain::cellchain^ child = gcnew CellDataChain::cellchain();
	//現在の構造体に子を連結してその連結した子の構造体を取得する
	child = CellCtrl->ChainChild("", "", this->TableElem);
	//新規に作成した子の構造体を対象にして詳細ダイアログを開いて値を入力する
	this->ParentInfo(child);
	return;
}

/*概要：兄ボタンクリック時のイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void ElderBrotherChainButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//子を連結した構造体を格納する構造体を宣言
	CellDataChain::cellchain^ brother = gcnew CellDataChain::cellchain();
	//現在の構造体に子を連結してその連結した子の構造体を取得する
	brother = CellCtrl->ChainElderBrother("", "", this->TableElem);
	//新規に作成した子の構造体を対象にして詳細ダイアログを開いて値を入力する
	this->ParentInfo(brother);
	return;
}

/*概要：弟ボタンクリック時のイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void YoungBrotherButtonClick(System::Object^  sender, System::EventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//子を連結した構造体を格納する構造体を宣言
	CellDataChain::cellchain^ brother = gcnew CellDataChain::cellchain();
	//現在の構造体に子を連結してその連結した子の構造体を取得する
	brother = CellCtrl->ChainYoungBrother("", "", this->TableElem);
	//新規に作成した子の構造体を対象にして詳細ダイアログを開いて値を入力する
	this->ParentInfo(brother);
	return;
}

/*概要：画面上部のキー名が表示された画像をクリックしたときのイベント
作成日：2017.9.25
作成者：K.Asada*/
private: System::Void PictureBoxParentMouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//チェイン構造操作クラスをインスタンス化
	CellDataChain^ CellCtrl = gcnew CellDataChain();
	//クリックした座標を格納するための変数を宣言
	Int32 clickpoint = 0;
	//クリックした座標をメンバ変数へ取得する
	clickpoint = this->GetPoint(e);
	//クリックした位置の構造体を取得するための構造体を宣言
	CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
	//クリックした位置の構造体を取得する関数を呼び出す
	parent = CellCtrl->GetParent(this->TableElem, clickpoint);
	//詳細ダイアログを表示する関数を呼び出す
	this->ParentInfo(parent);
	return;
}

/*概要：クリックした画像上の座標を取得するための関数
作成日：2017.9.26
作成者：K.Asada*/
		 Int32 GetPoint(MouseEventArgs^ e) {
			 //取得した座標を格納するための変数
			 Int32 point = 0;
			 //座標を計算して取得する、端数が切り捨てられるため最後に+1して補正する
			 point = ((*this->RctWidth * *this->ParentIndex - e->Location.X)/ *this->RctWidth) +1;
			 //取得した座標を返却する
			 return point;
}
};
}
