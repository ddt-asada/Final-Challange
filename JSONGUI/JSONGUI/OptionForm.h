#pragma once
#include "ConstantString.h"	//自作定数クラスのヘッダ

namespace option {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CONSTANTS;		//自作定数クラスの名前空間


	/// <summary>
	/// OptionForm の概要
	/// </summary>
	/*概要：読み込むファイルの選択やDBクエリの入力を行う設定画面
	作成日：2017.9.20
	作成者：K.Asada*/
	public ref class OptionForm : public System::Windows::Forms::Form
	{
	public:
		OptionForm(void)
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
		~OptionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxPath;
	protected:
	private: System::Windows::Forms::TextBox^  textBoxDBQuery;
	private: System::Windows::Forms::Button^  buttonOptionCancel;
	private: System::Windows::Forms::Button^  buttonOptionOK;
	private: System::Windows::Forms::Button^  buttonLoadFile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

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
			this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDBQuery = (gcnew System::Windows::Forms::TextBox());
			this->buttonOptionCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOptionOK = (gcnew System::Windows::Forms::Button());
			this->buttonLoadFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxPath
			// 
			this->textBoxPath->Location = System::Drawing::Point(208, 102);
			this->textBoxPath->Multiline = true;
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->Size = System::Drawing::Size(927, 53);
			this->textBoxPath->TabIndex = 0;
			// 
			// textBoxDBQuery
			// 
			this->textBoxDBQuery->Location = System::Drawing::Point(208, 223);
			this->textBoxDBQuery->Multiline = true;
			this->textBoxDBQuery->Name = L"textBoxDBQuery";
			this->textBoxDBQuery->Size = System::Drawing::Size(927, 53);
			this->textBoxDBQuery->TabIndex = 1;
			// 
			// buttonOptionCancel
			// 
			this->buttonOptionCancel->Location = System::Drawing::Point(1237, 347);
			this->buttonOptionCancel->Name = L"buttonOptionCancel";
			this->buttonOptionCancel->Size = System::Drawing::Size(191, 71);
			this->buttonOptionCancel->TabIndex = 2;
			this->buttonOptionCancel->Text = L"キャンセル";
			this->buttonOptionCancel->UseVisualStyleBackColor = true;
			this->buttonOptionCancel->Click += gcnew System::EventHandler(this, &OptionForm::OptionCancelClisk);
			// 
			// buttonOptionOK
			// 
			this->buttonOptionOK->Location = System::Drawing::Point(1062, 347);
			this->buttonOptionOK->Name = L"buttonOptionOK";
			this->buttonOptionOK->Size = System::Drawing::Size(157, 71);
			this->buttonOptionOK->TabIndex = 3;
			this->buttonOptionOK->Text = L"OK";
			this->buttonOptionOK->UseVisualStyleBackColor = true;
			this->buttonOptionOK->Click += gcnew System::EventHandler(this, &OptionForm::OptionOKClick);
			// 
			// buttonLoadFile
			// 
			this->buttonLoadFile->Location = System::Drawing::Point(1157, 102);
			this->buttonLoadFile->Name = L"buttonLoadFile";
			this->buttonLoadFile->Size = System::Drawing::Size(145, 53);
			this->buttonLoadFile->TabIndex = 4;
			this->buttonLoadFile->Text = L"参照";
			this->buttonLoadFile->UseVisualStyleBackColor = true;
			this->buttonLoadFile->Click += gcnew System::EventHandler(this, &OptionForm::LoadButtonClick);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &OptionForm::FileDialogOK);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(93, 233);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"DBクエリ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(50, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 29);
			this->label2->TabIndex = 5;
			this->label2->Text = L"読み込み先";
			// 
			// OptionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1440, 438);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonLoadFile);
			this->Controls->Add(this->buttonOptionOK);
			this->Controls->Add(this->buttonOptionCancel);
			this->Controls->Add(this->textBoxDBQuery);
			this->Controls->Add(this->textBoxPath);
			this->Name = L"OptionForm";
			this->Text = L"OptionForm";
			this->Load += gcnew System::EventHandler(this, &OptionForm::OptionForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		ConstantString^ Constants = gcnew ConstantString();		//定数クラスをインスタンス化
		String^ FilePath = Constants->EMPTY_STRING;				//テキストボックスに入力されたJSONのファイルパスを保管する文字列
		String^ SendQuery = Constants->EMPTY_STRING;			//テキストボックスに入力されたDBクエリを保管する文字列

	/*概要：フォームロード時のイベント、前回起動したときの情報を対応したテキストボックスに配置する
	引数：sender：イベント発生時の各種情報を格納したオブジェクトクラス
		：EventArg：
	戻り値：なし
	作成日：2017.9.20
	作成者：K.Asada*/
	private: System::Void OptionForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//ファイルパステキストボックスに前回起動時に取得したファイルパスを格納する
		this->textBoxPath->Text = this->FilePath;
		//DBクエリテキストボックスに前回起動時に取得したDBクエリを格納する
		this->textBoxDBQuery->Text = this->SendQuery;
	}

	/*参照ボタンクリック時のイベント、ファイルパスを取得するためのダイアログを開く
	引数：Sender
		：EventArgs
	作成日：2017.9.20
	作成者：K.Asada*/
	private: System::Void LoadButtonClick(System::Object^  sender, System::EventArgs^  e) {
		//新規ダイアログを開き、キャンセルボタンが押されたときの動作を設定しておく
		if (this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			//何もせずにダイアログを閉じる
			return;
		}
}

	/*概要：JSONファイル読み込みダイアログ上でOKボタンがクリックされたときにそのファイルパスをテキストボックスに格納する
	引数：
	戻り値：
	作成日：2017.9.20
	作成者：K.Asada */
	private: System::Void FileDialogOK(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		//OKボタンが押されたときはテキストボックスにファイルパスを格納する
		this->textBoxPath->Text = this->openFileDialog->FileName;
}

	/*概要：OKボタンがクリックされたときのイベント、テキストボックスの値をメンバの文字列に格納する
	引数：
	戻り値：なし
	作成日：2017.9.20
	作成者：K.Asada*/
private: System::Void OptionOKClick(System::Object^  sender, System::EventArgs^  e) {
	//呼び出し元の画面に渡すためにテキストボックスに入力されたファイルパスをメンバの文字列に格納する
	this->FilePath = this->textBoxPath->Text;
	//呼び出し元の画面に渡すためにテキストボックスに入力されたDBクエリをメンバの文字列に格納する
	this->SendQuery = this->textBoxDBQuery->Text;
	//画面を閉じる
	this->Close();
}

	/*概要：キャンセルボタンクリック時のイベント、テキストボックスの値をそのままにして画面を閉じる
	引数：
	戻り値：なし
	作成日：2017.9.20
	作成者：K.Asada*/
private: System::Void OptionCancelClisk(System::Object^  sender, System::EventArgs^  e) {
	//テキストボックスの値を破棄したいので何も処理せずに画面を閉じる
	this->Close();
}
};
}
