#pragma once

namespace JSONTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// InputOption の概要
	/// </summary>
	public ref class InputOption : public System::Windows::Forms::Form
	{
	public:
		InputOption(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}
		//JSONファイルパスのプロパティ
		//作成日：2017.9.2
		//作成者：K.Asada
		property String^ FilePath {
			System::Void set(String^ Path) {
				this->JFilePath = Path;
			}

			System::String^ get() {
				return this->JFilePath;
			}
		}

		//DBとの通信するクエリのプロパティ
		//作成日：2017,9,2
		//作成者：K.Asada
		property String^ SendQuery{
			System::Void set(String^ query) {
				this->Query = query;
			}

			System::String^ get() {
				return this->Query;
			}
		}

		//DBとの通信結果のプロパティ
		//作成日：2017,9,2
		//作成者：K.Asada
		property String^ ResultJSON {
			System::Void set(String^ result) {
				this->DbJson = result;
			}

			System::String^ get() {
				return this->DbJson;
			}
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~InputOption()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  labelLoadJSON;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  buttonLoadFileJSON;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxDBquery;
	private: System::Windows::Forms::Button^  buttonDBConnect;
	private: System::Windows::Forms::Button^  buttonOptionOK;
	private: System::Windows::Forms::Button^  buttonCancelOption;
	protected:


	protected:

	private:
		String^ JFilePath;		//入力されたJSONのファイルパスを格納するための文字列。
		String^ Query;			//入力されたDBへ投げるクエリを格納する文字列。
		String^ DbJson;			//DBとの通信結果を格納する文字列。
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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->labelLoadJSON = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonLoadFileJSON = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxDBquery = (gcnew System::Windows::Forms::TextBox());
			this->buttonDBConnect = (gcnew System::Windows::Forms::Button());
			this->buttonOptionOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancelOption = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &InputOption::openFileDialog1_FileOk);
			// 
			// labelLoadJSON
			// 
			this->labelLoadJSON->AutoSize = true;
			this->labelLoadJSON->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelLoadJSON->Location = System::Drawing::Point(13, 29);
			this->labelLoadJSON->Name = L"labelLoadJSON";
			this->labelLoadJSON->Size = System::Drawing::Size(215, 33);
			this->labelLoadJSON->TabIndex = 0;
			this->labelLoadJSON->Text = L"JSONファイル";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(234, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(868, 31);
			this->textBox1->TabIndex = 1;
			// 
			// buttonLoadFileJSON
			// 
			this->buttonLoadFileJSON->Location = System::Drawing::Point(953, 85);
			this->buttonLoadFileJSON->Name = L"buttonLoadFileJSON";
			this->buttonLoadFileJSON->Size = System::Drawing::Size(148, 67);
			this->buttonLoadFileJSON->TabIndex = 2;
			this->buttonLoadFileJSON->Text = L"参照";
			this->buttonLoadFileJSON->UseVisualStyleBackColor = true;
			this->buttonLoadFileJSON->Click += gcnew System::EventHandler(this, &InputOption::buttonLoadFileJSON_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(12, 195);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 33);
			this->label1->TabIndex = 3;
			this->label1->Text = L"DBクエリ";
			// 
			// textBoxDBquery
			// 
			this->textBoxDBquery->Location = System::Drawing::Point(234, 195);
			this->textBoxDBquery->Name = L"textBoxDBquery";
			this->textBoxDBquery->Size = System::Drawing::Size(867, 31);
			this->textBoxDBquery->TabIndex = 4;
			// 
			// buttonDBConnect
			// 
			this->buttonDBConnect->Location = System::Drawing::Point(953, 248);
			this->buttonDBConnect->Name = L"buttonDBConnect";
			this->buttonDBConnect->Size = System::Drawing::Size(147, 75);
			this->buttonDBConnect->TabIndex = 5;
			this->buttonDBConnect->Text = L"通信";
			this->buttonDBConnect->UseVisualStyleBackColor = true;
			// 
			// buttonOptionOK
			// 
			this->buttonOptionOK->Location = System::Drawing::Point(757, 523);
			this->buttonOptionOK->Name = L"buttonOptionOK";
			this->buttonOptionOK->Size = System::Drawing::Size(160, 99);
			this->buttonOptionOK->TabIndex = 6;
			this->buttonOptionOK->Text = L"OK";
			this->buttonOptionOK->UseVisualStyleBackColor = true;
			this->buttonOptionOK->Click += gcnew System::EventHandler(this, &InputOption::buttonOptionOK_Click);
			// 
			// buttonCancelOption
			// 
			this->buttonCancelOption->Location = System::Drawing::Point(953, 523);
			this->buttonCancelOption->Name = L"buttonCancelOption";
			this->buttonCancelOption->Size = System::Drawing::Size(160, 99);
			this->buttonCancelOption->TabIndex = 7;
			this->buttonCancelOption->Text = L"キャンセル";
			this->buttonCancelOption->UseVisualStyleBackColor = true;
			this->buttonCancelOption->Click += gcnew System::EventHandler(this, &InputOption::buttonCancelOption_Click);
			// 
			// InputOption
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1468, 676);
			this->Controls->Add(this->buttonCancelOption);
			this->Controls->Add(this->buttonOptionOK);
			this->Controls->Add(this->buttonDBConnect);
			this->Controls->Add(this->textBoxDBquery);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonLoadFileJSON);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->labelLoadJSON);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"InputOption";
			this->Text = L"InputOption";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		this->textBox1->Text = this->openFileDialog1->FileName;
	}
	private: System::Void buttonLoadFileJSON_Click(System::Object^  sender, System::EventArgs^  e) {
		
		//ファイルフィルタ  
		this->openFileDialog1->Filter = "画像ﾌｧｲﾙ(*.bmp,*.jpg,*.png,*.tif,*.ico)|*.bmp;*.jpg;*.png;*.tif;*.ico";
		//ダイアログの表示 （Cancelボタンがクリックされた場合は何もしない）
		if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
	}
	private: System::Void buttonOptionOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//取得したファイルパスをメンバ変数へ保存する。
		this->JFilePath = this->textBox1->Text;
		//取得したDBへ投げるクエリをメンバ変数へ保存する。
		this->Query = this->textBoxDBquery->Text;

		//メイン画面へ戻る。
		this->Close();
	}
private: System::Void buttonCancelOption_Click(System::Object^  sender, System::EventArgs^  e) {
	//テキストボックスの中身を画面を開いたときの状態に戻す。
	this->textBox1->Text = this->JFilePath;
	//テキストボックスの中身を画面を開いたときの状態に戻す。
	this->textBoxDBquery->Text = this->Query;

	//メイン画面へ戻る。
	this->Close();
}
};
}
