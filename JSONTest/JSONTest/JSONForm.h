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
	/// JSONForm の概要
	/// </summary>
	public ref class JSONForm : public System::Windows::Forms::Form
	{
	public:
		JSONForm(void)
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
			this->labelRow->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelRow->Location = System::Drawing::Point(46, 25);
			this->labelRow->Name = L"labelRow";
			this->labelRow->Size = System::Drawing::Size(81, 33);
			this->labelRow->TabIndex = 0;
			this->labelRow->Text = L"タテ";
			// 
			// labelColumn
			// 
			this->labelColumn->AutoSize = true;
			this->labelColumn->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelColumn->Location = System::Drawing::Point(46, 79);
			this->labelColumn->Name = L"labelColumn";
			this->labelColumn->Size = System::Drawing::Size(81, 33);
			this->labelColumn->TabIndex = 1;
			this->labelColumn->Text = L"ヨコ";
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
			this->buttonInputOption->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonInputOption->Location = System::Drawing::Point(270, 25);
			this->buttonInputOption->Name = L"buttonInputOption";
			this->buttonInputOption->Size = System::Drawing::Size(148, 85);
			this->buttonInputOption->TabIndex = 4;
			this->buttonInputOption->Text = L"設定";
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
			this->buttonCancel->Text = L"キャンセル";
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
			InputOption^ iopt;	//設定ダイアログをインスタンス化するための準備
			int row = 0;		//行数を格納する整数値
			int column = 0;		//列数を格納する整数値

	private: System::Void JSONForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

			 //設定ボタンをクリックしたときの処理
private: System::Void buttonInputOption_Click(System::Object^  sender, System::EventArgs^  e) {
	//設定ダイアログを開くために設定クラスをインスタンス化する。
	iopt = gcnew InputOption();
	//設定ダイアログを開く。
	iopt->ShowDialog();
}

//メインのフォームを閉じるときの処理
private: System::Void JSONForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//閉じる前にメッセージボックスを表示して確認を行う。
	if (System::Windows::Forms::DialogResult::Cancel == MessageBox::Show("終了しますか？", "確認", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)) {
		//プログラムを終了する。
		e->Cancel = true;
	}
}

//OKボタンが押されたときの処理
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		//テキストボックスに入力された文字列を整数値に変換する関数を呼び出す
		//タテを取得
		this->row = this->IntToString(this->textBoxRow->Text);
		//ヨコを取得
		this->column = this->IntToString(this->textBoxColumn->Text);
		//タテとヨコのテキストボックスに値が入っているかを判定する。
		if (row >= 1 && column >= 1) {
			//タテを分割
			this->dataGridViewJSON->ColumnCount = column;
			//ヨコを分割
			this->dataGridViewJSON->RowCount = row;
		}
	}
	catch (Exception^ ex) {
		//受け取ったエラー内容を表示する。
		MessageBox::Show(ex->ToString(), "警告", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

/*関数名：IntToString
  概要：受け取った文字列を整数値に変換して返却する関数
        エラー処理を加えたかったので関数化しています
  引数：String：整数値に変換したい文字列
  戻り値：int：受け取った文字列を整数値に変換した値。
  作成日：2017.8.24
  作成者：K.Asada
  */
private:System::Int32 IntToString(String^ con) {
	//整数値に変換できない文字列が入力されていた時の例外処理
	try{
		//文字列を整数値に変換した値を返却する。
		return Convert::ToInt32(con);
	}
	catch (FormatException^ ex) {
		//変換できないことを伝える。
		throw gcnew Exception("整数値に変換できない文字列です。");
	}
}

/*関数名：initMainForm
  概要：全ての表と値を初期化する処理
  引数：なし
  戻り値：なし
  作成日2017.8.24
  作成者：K.Asada
  */
private:System::Void initMainForm() {
	this->row = 0;//取得したタテを初期化。
	this->column = 0;//取得したヨコを初期化。
	this->textBoxRow->ResetText();//タテが入力されたテキストボックスを初期化。
	this->textBoxColumn->ResetText();//ヨコが入力されたテキストボックスを初期化。
	this->dataGridViewJSON->Columns->Clear();	//表のヨコを初期化する。
	this->dataGridViewJSON->Rows->Clear();		//表のタテを初期化する。
}

//キャンセルボタンが押されたときの処理
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	//メインフォームに関わるものをすべて初期化する。
	this->initMainForm();
}
};
}
