#pragma once

#include <iostream>
#include "MyForm.h"

namespace buttontest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ButtonTest の概要
	/// </summary>
	public ref class ButtonTest : public System::Windows::Forms::Form
	{
	public:
		ButtonTest(void)
		{
			arrayinit();
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~ButtonTest()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
		int x = 0;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
			 array<String^, 2>^ ary = gcnew array<String^, 2>(10, 10);



	protected:



	protected:

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ButtonTest::pictureBox1_Click);
			// 
			// ButtonTest
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1405, 827);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ButtonTest";
			this->Load += gcnew System::EventHandler(this, &ButtonTest::ButtonTest_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//配列の中身を初期化する関数
private: System::Void arrayinit() {
	//配列に格納するための値
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//配列0～99の文字列を順に格納
			this->ary[i, j] = Convert::ToString(count++);
		}
	}
}

//メイン画面に配置する画像を描画して反映する関数
private: System::Void init() {
	//ビットマップの中に描画する数字
	int count = 0;
	//描画する図形一つ当たりの幅
	int rctwidth = 100;
	  //描画する図形一つ当たりの高さ
	int rctheight = 100;
	// ビットマップクラス(イメージ画像)の生成
	Bitmap^ img = gcnew Bitmap(1001, 1001);//this->pictureBox1->Width, this->pictureBox1->Height);
	//描画を行うグラフィックスクラスを生成
	Graphics^ gr = Graphics::FromImage(img);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			// 画像領域に線を描画
			gr->DrawRectangle(Pens::Black, rctwidth * j, rctheight * i, rctwidth, rctheight);
			// 画像領域に文字列を書き込む
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//メンバの配列より表に格納する文字列を取得する
			gr->DrawString(this->ary[i, j], myFont, Brushes::Black, rctwidth * j, rctheight * i);
		}
	}
	//pictureBoxに作成した画像（表）を反映
	this->pictureBox1->Image = img;
}

private: System::Void ButtonTest_Load(System::Object^  sender, System::EventArgs^  e) {
	this->init();
	
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//表の値を書き換えるための別ウィンドウをインスタンス化
	MyForm^ rewrite = gcnew MyForm();
	//表の列の座標を取得する
	int columnindex = (e->Location.X / (this->pictureBox1->Width / this->ary->GetLength(1)));
	//表の行の座標を取得する
	int rowindex = (e->Location.Y / (this->pictureBox1->Height / this->ary->GetLength(0)));
	//別ウィンドウのテキストボックスに表の対応した値を反映させる
	rewrite->textBox1->Text = this->ary[rowindex, columnindex];
	//別ウィンドウを開く
	rewrite->ShowDialog();
	//入力した値を取得してメンバの配列に格納
	this->ary[rowindex, columnindex] = rewrite->textBox1->Text;
	//メイン画面の表の初期化関数を呼び出す。
	this->init();
}
};
}
