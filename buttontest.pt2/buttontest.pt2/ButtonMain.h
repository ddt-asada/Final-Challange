#pragma once

#include "MyForm.h"

namespace buttontestpt2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ButtonMain の概要
	/// </summary>
	public ref class ButtonMain : public System::Windows::Forms::Form
	{
	public:
		ButtonMain(void)
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
		~ButtonMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonJoin;
	protected:
	private: System::Windows::Forms::Button^  buttonRetouch;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
			 int Rowindex = 0;			//クリックした行を保持する
			 int Columnindex = 0;		//クリックした列を保持する
			 int row = 3;				//描画する表の行
			 int column = 3;			//描画する表の列
			//array<String^, 2>^ ary = gcnew array<String^, 2>(3, 3);//
			 array<String^, 2>^ str = gcnew array<String^, 2>(this->row, this->column);//表の中身
			 array<String^>^ join = gcnew array<String^>(this->row);				//結合箇所を保持する


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
			this->buttonJoin = (gcnew System::Windows::Forms::Button());
			this->buttonRetouch = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonJoin
			// 
			this->buttonJoin->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonJoin->Location = System::Drawing::Point(12, 12);
			this->buttonJoin->Name = L"buttonJoin";
			this->buttonJoin->Size = System::Drawing::Size(246, 84);
			this->buttonJoin->TabIndex = 0;
			this->buttonJoin->Text = L"結合/解除";
			this->buttonJoin->UseVisualStyleBackColor = true;
			this->buttonJoin->Click += gcnew System::EventHandler(this, &ButtonMain::buttonJoin_Click);
			// 
			// buttonRetouch
			// 
			this->buttonRetouch->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonRetouch->Location = System::Drawing::Point(264, 10);
			this->buttonRetouch->Name = L"buttonRetouch";
			this->buttonRetouch->Size = System::Drawing::Size(198, 84);
			this->buttonRetouch->TabIndex = 1;
			this->buttonRetouch->Text = L"修正";
			this->buttonRetouch->UseVisualStyleBackColor = true;
			this->buttonRetouch->Click += gcnew System::EventHandler(this, &ButtonMain::buttonRetouch_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(12, 102);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(289, 184);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ButtonMain::pictureBox1_MouseClick);
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ButtonMain::pictureBox1_MouseDoubleClick);
			// 
			// ButtonMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1442, 820);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->buttonRetouch);
			this->Controls->Add(this->buttonJoin);
			this->Name = L"ButtonMain";
			this->Text = L"ButtonMain";
			this->Load += gcnew System::EventHandler(this, &ButtonMain::ButtonMain_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//配列の中身を初期化する関数
	private: System::Void arrayinit() {
		//配列に格納するための値
		int count = 1;
		for (int i = 0; i < this->row; i++) {
			//結合判定用の文字列配列を初期化
			this->join[i] = "";
			for (int j = 0; j < this->column; j++) {
				//配列1～9の文字列を順に格納
			//	this->ary[i, j] = Convert::ToString(count++);
				//Valueの初期値として「無」を格納
				this->str[i, j] = "無";
			}
		}
	}

			 //メイン画面に配置する画像を描画して反映する関数
	private: System::Void init() {
		//ビットマップの中に描画する数字
		int count = 1;
		//描画する図形一つ当たりの幅
		int rctwidth = 100;
		//描画する図形一つ当たりの高さ
		int rctheight = 100;
		// ビットマップクラス(イメージ画像)の生成
		Bitmap^ img = gcnew Bitmap(rctwidth * this->column + 1, rctheight * this->row + 1);
		//描画を行うグラフィックスクラスを生成
		Graphics^ gr = Graphics::FromImage(img);
		for (int i = 0; i < this->row; i++) {
			//結合状態であれば
			if (this->join[i] != "") {
				count = Convert::ToInt32(this->join[i]) + (i * this->row) + 1;
				// 画像領域に線を描画
				gr->DrawRectangle(Pens::Black, 0, rctheight * i, rctwidth * this->row, rctheight);
				// 画像領域に文字列を書き込む
				System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
				//行の中心にインデックスを付ける
				gr->DrawString(Convert::ToString(count++), myFont, Brushes::Black, rctwidth *this-> row / 2, rctheight * i);
			}
			else {
				for (int j = 0; j < this->column; j++) {
					// 画像領域に線を描画
					gr->DrawRectangle(Pens::Black, rctwidth * j, rctheight * i, rctwidth, rctheight);
					// 画像領域に文字列を書き込む
					System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
					//表にインデックスを付ける
					gr->DrawString(Convert::ToString(count++), myFont, Brushes::Black, rctwidth * j, rctheight * i);
				}
			}
		}
		//pictureBoxに作成した画像（表）を反映
		this->pictureBox1->Image = img;
	}

	//Value変更画面を表示する関数
	private: System::Void ValueDisplay() {
		//表の値を書き換えるための別ウィンドウをインスタンス化
		MyForm^ rewrite = gcnew MyForm();
		//別ウィンドウのテキストボックスに表の対応した値を反映させる
		rewrite->textBox1->Text = this->str[this->Rowindex, this->Columnindex];
		//別ウィンドウを開く
		rewrite->ShowDialog();
		//入力した値を取得してメンバの配列に格納
		this->str[this->Rowindex, this->Columnindex] = rewrite->textBox1->Text;
		//メイン画面の表の初期化関数を呼び出す。
		this->init();
	}


	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

	}

private: System::Void pictureBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Value変更画面を表示する関数を呼び出す
	this->ValueDisplay();
}
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//表の行の座標を取得する
	this->Rowindex = (e->Location.Y / (this->pictureBox1->Height / this->row));
	//表の列の座標を取得する
	if (this->join[this->Rowindex] != "") {
		//結合の座標を取得。
		this->Columnindex = Convert::ToInt32(this->join[this->Rowindex]);
	}
	else {
		//表の行の座標を取得する
		this->Columnindex = (e->Location.X / (this->pictureBox1->Width / this->column));
	}
}
private: System::Void buttonRetouch_Click(System::Object^  sender, System::EventArgs^  e) {
	//Value変更画面を表示する関数を呼び出す
	this->ValueDisplay();
}
private: System::Void ButtonMain_Load(System::Object^  sender, System::EventArgs^  e) {
	this->init();
}
private: System::Void buttonJoin_Click(System::Object^  sender, System::EventArgs^  e) {
	//すでに結合状態であれば
	if (join[this->Rowindex] != "") {
		//結合状態に解除する。
		this->join[this->Rowindex] = "";
	}
	else {
		//結合状態にする。
		this->join[this->Rowindex] = Convert::ToString(this->Columnindex);
	}
	//表を再描画する
	this->init();
}
};
}
