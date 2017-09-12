#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <cliext/utility>
#include <string>
#include <vector> 
#include "CONSTANTSTRING.h"

namespace JSONTest {
//	using namespace JSONTest;
	using namespace std;
	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace constantstring;
	using namespace boost::property_tree;

	/*表画像を生成するクラス
	作成日：2017.9.9
	作成者；K.Asada*/
	public ref class TableProcessing : public System::Windows::Forms::Form{
	public:

		Int32^ Row = 0;			//表の行数
		Int32^ Column = 0;		//表の列数
		Int32^ RowIndex = 0;		//クリックされたセルの行座標
		Int32^ ColumnIndex = 0;	//クリックされたセルの列座標
		Int32^ RctWidth = 200;		//セル一つ当たりの幅
		Int32^ RctHeight = 100;	//セル一つ当たりの高さ
		List<String^>^ join = gcnew List<String^>;
		List<int>^ Index = gcnew List<int>();
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ TableInfo = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();

		TableProcessing() {
		};

		/*表を生成する関数
		*/
		PictureBox^ TableGenerate(PictureBox^ PictBox) {
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
			//描画を行うグラフィックスクラスを生成
			Graphics^ gr = Graphics::FromImage(img);
			for (int i = 0; i < this->Row; i++) {
				//結合状態であれば
				if (this->join[i] != "") {
					for(int k = 0; k < this->TableInfo->Count; k++){
						if ((this->TableInfo[k]->first->first == "text" || this->TableInfo[k]->first->first == "array") && this->TableInfo[k]->second == ("x" + "0" + Convert::ToString(i))) {
							gr->DrawRectangle(Pens::Black, 0, *this->RctHeight * i, *this->RctWidth * *this->Column, *this->RctHeight);
							// 画像領域に文字列を書き込む
							System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
							//表にインデックスを付ける
							gr->DrawString(this->TableInfo[k++]->first->second, myFont, Brushes::Black, *this->RctWidth * *this->Row / 2, *this->RctHeight * i);
							break;
						}
					}
				}
				else {
					for (int j = 0; j < this->Column; j++) {
						// 画像領域に線を描画
						for (int k = 0; k < this->TableInfo->Count; k++) {
						/*	if (i == 0 && j == 0 && this->TableInfo[k]->first->first == "text") {
								gr->DrawRectangle(Pens::Black, 0, *this->RctHeight * i, *this->RctWidth * *this->Column, *this->RctHeight);
								System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
								//表にインデックスを付ける
								gr->DrawString(this->TableInfo[k++]->first->second, myFont, Brushes::Black, *this->RctWidth * j, *this->RctHeight * i);
								break;
							}*/
							if ((this->TableInfo[k]->first->first == "text" || this->TableInfo[k]->first->first == "array") && this->TableInfo[k]->second == ("x" + Convert::ToString(j) + Convert::ToString(i))) {
								gr->DrawRectangle(Pens::Black, *this->RctWidth * j, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
								// 画像領域に文字列を書き込む
								System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
								//表にインデックスを付ける
								gr->DrawString(this->TableInfo[k++]->first->second, myFont, Brushes::Black, *this->RctWidth * j, *this->RctHeight * i);
								break;
							}
						}
					}
				}
			}
			//作成した表画像を反映
			PictBox->Image = img;
			//ピクチャーボックスを返却
			return PictBox;
		}
		/*選択箇所をハイライトする関数*/

		/*選択箇所をハイライトするための画像を生成する関数*/
		PictureBox^ pict(PictureBox^ PictSelect) {
		//半透明の塗りつぶし用のブラシを作成
		Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Yellow));
		//ビットマップを生成
		Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
		//描画を行うグラフィックスクラスを生成
		Graphics^ gr = Graphics::FromImage(img);
		//結合状態であれば
		if (this->join[*this->RowIndex] != "") {
			// 画像領域に線を描画
			PictSelect->Location = System::Drawing::Point(0, *this->RctHeight * *this->RowIndex);
			PictSelect->Size = System::Drawing::Size(*this->RctWidth * *this->Column, *this->RctHeight);
			gr->FillRectangle(br, 0, 0, *this->RctWidth * *this->Column - 1, *this->RctHeight - 1);
		}
		else {
			PictSelect->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
			PictSelect->Size = System::Drawing::Size(*this->RctWidth, *this->RctHeight);
			gr->FillRectangle(br, 0, 0, *this->RctWidth - 1, *this->RctHeight - 1);
		}
		PictSelect->Image = img;
		return PictSelect;
	}

		/*値の変更画面に表示する画像を生成する関数*/
		Bitmap^ ValueChange() {
			String^ Xindex = "x" + Convert::ToString(this->ColumnIndex) + Convert::ToString(this->RowIndex);
			String^ Yindex = "y" + Convert::ToString(this->RowIndex);
			//ビットマップを生成
			Bitmap^ img = gcnew Bitmap(1000, 1000);
			//描画を行うグラフィッククラスを生成
			Graphics^ gr = Graphics::FromImage(img);
			int count = 0;
			//クリックされたセルに対応した情報を取得し、描画
			for (int i = 0; i < this->TableInfo->Count; i++) {
				//クリックされたセルに対応した情報を見つけたら
				if (this->TableInfo[i]->second == Xindex || this->TableInfo[i]->second == Yindex || this->TableInfo[i]->second == "title") {
					gr->DrawRectangle(Pens::Black, 0, *this->RctHeight * count, *this->RctWidth, *this->RctHeight);
					// 画像領域に文字列を書き込む
					System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
					//表にインデックスを付ける
					gr->DrawString(this->TableInfo[i]->first->first, myFont, Brushes::Black, 0, *this->RctHeight * count);
					gr->DrawRectangle(Pens::Black, *this->RctWidth, *this->RctHeight * count, *this->RctWidth, *this->RctHeight);
					// 画像領域に文字列を書き込む
					//表にインデックスを付ける
					gr->DrawString(this->TableInfo[i]->first->second, myFont, Brushes::Black, *this->RctWidth, *this->RctHeight * count++);
					//値をとりだした箇所の添え字を取得する。
					this->Index->Add(i);
				}
			}
			return img;
		}

		/*選択箇所を結合/解除する関数*/
		Void JoinRelease() {
			//すでに結合状態であれば
			if (join[*this->RowIndex] != "") {
				//結合状態に解除する。
				this->join[*this->RowIndex] = "";
			}
			else {
				//結合状態にする。
				this->join[*this->RowIndex] = Convert::ToString(this->ColumnIndex);
			}
		}

		/*表を再描画する関数*/

		/*クリックされたセルを取得する関数
		作成日：2017.9.11
		作成者：K.Asada
		*/
		Void CalPoint(System::Windows::Forms::MouseEventArgs^  e) {
			//表の行の座標を取得する
			this->RowIndex = (e->Location.Y / *this->RctHeight);
			//表の列の座標を取得する
			if (this->join[*this->RowIndex] != "") {
				//結合の座標を取得。
				this->ColumnIndex = Convert::ToInt32(this->join[*this->RowIndex]);
			}
			else {
				//表の行の座標を取得する
				this->ColumnIndex = (e->Location.X / *this->RctWidth);
			}
		}

		
	};
}