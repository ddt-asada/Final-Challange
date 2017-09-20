#pragma once
#include "ConstantString.h"	//自作定数クラスのヘッダ

namespace JSONGUI {

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
			this->SuspendLayout();
			// 
			// textBoxPath
			// 
			this->textBoxPath->Location = System::Drawing::Point(125, 88);
			this->textBoxPath->Multiline = true;
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->Size = System::Drawing::Size(927, 53);
			this->textBoxPath->TabIndex = 0;
			// 
			// textBoxDBQuery
			// 
			this->textBoxDBQuery->Location = System::Drawing::Point(125, 235);
			this->textBoxDBQuery->Multiline = true;
			this->textBoxDBQuery->Name = L"textBoxDBQuery";
			this->textBoxDBQuery->Size = System::Drawing::Size(927, 53);
			this->textBoxDBQuery->TabIndex = 1;
			// 
			// buttonOptionCancel
			// 
			this->buttonOptionCancel->Location = System::Drawing::Point(1074, 767);
			this->buttonOptionCancel->Name = L"buttonOptionCancel";
			this->buttonOptionCancel->Size = System::Drawing::Size(191, 71);
			this->buttonOptionCancel->TabIndex = 2;
			this->buttonOptionCancel->Text = L"キャンセル";
			this->buttonOptionCancel->UseVisualStyleBackColor = true;
			// 
			// buttonOptionOK
			// 
			this->buttonOptionOK->Location = System::Drawing::Point(1271, 767);
			this->buttonOptionOK->Name = L"buttonOptionOK";
			this->buttonOptionOK->Size = System::Drawing::Size(157, 71);
			this->buttonOptionOK->TabIndex = 3;
			this->buttonOptionOK->Text = L"OK";
			this->buttonOptionOK->UseVisualStyleBackColor = true;
			// 
			// buttonLoadFile
			// 
			this->buttonLoadFile->Location = System::Drawing::Point(1067, 88);
			this->buttonLoadFile->Name = L"buttonLoadFile";
			this->buttonLoadFile->Size = System::Drawing::Size(145, 53);
			this->buttonLoadFile->TabIndex = 4;
			this->buttonLoadFile->Text = L"参照";
			this->buttonLoadFile->UseVisualStyleBackColor = true;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// OptionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1440, 850);
			this->Controls->Add(this->buttonLoadFile);
			this->Controls->Add(this->buttonOptionOK);
			this->Controls->Add(this->buttonOptionCancel);
			this->Controls->Add(this->textBoxDBQuery);
			this->Controls->Add(this->textBoxPath);
			this->Name = L"OptionForm";
			this->Text = L"OptionForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		ConstantString^ Constants = gcnew ConstantString();		//定数クラスをインスタンス化
		String^ FilePath = Constants->EMPTY_STRING;				//テキストボックスに入力されたJSONのファイルパスを保管する文字列
		String^ SendQuery = Constants->EMPTY_STRING;			//テキストボックスに入力されたDBクエリを保管する文字列
	};
}
