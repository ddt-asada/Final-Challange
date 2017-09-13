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

	/*�\�摜�𐶐�����N���X
	�쐬���F2017.9.9
	�쐬�ҁGK.Asada*/
	public ref class TableProcessing : public System::Windows::Forms::Form{
	public:

		Int32^ Row = 0;			//�\�̍s��
		Int32^ Column = 0;		//�\�̗�
		Int32^ RowIndex = 0;		//�N���b�N���ꂽ�Z���̍s���W
		Int32^ ColumnIndex = 0;	//�N���b�N���ꂽ�Z���̗���W
		Int32^ RctWidth = 200;		//�Z���������̕�
		Int32^ RctHeight = 100;	//�Z���������̍���
		List<String^>^ join = gcnew List<String^>;
		List<int>^ Index = gcnew List<int>();
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ TableInfo = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();

		TableProcessing() {
		};

		/*�\�𐶐�����֐�
		*/
		PictureBox^ TableGenerate(PictureBox^ PictBox) {
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
			//�`����s���O���t�B�b�N�X�N���X�𐶐�
			Graphics^ gr = Graphics::FromImage(img);
			for (int i = 0; i < this->Row; i++) {
				//������Ԃł����
				if (this->join[i] != "") {
					for(int k = 0; k < this->TableInfo->Count; k++){
						if ((this->TableInfo[k]->first->first == "text" || this->TableInfo[k]->first->first == "arraybegin") && this->TableInfo[k]->second == ("x" + "0" + Convert::ToString(i))) {
							gr->DrawRectangle(Pens::Black, 0, *this->RctHeight * i, *this->RctWidth * *this->Column, *this->RctHeight);
							// �摜�̈�ɕ��������������
							System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
							//�\�ɃC���f�b�N�X��t����
							gr->DrawString(this->TableInfo[k++]->first->second, myFont, Brushes::Black, *this->RctWidth * *this->Column / 2, *this->RctHeight * i);
							break;
						}
					}
				}
				else {
					for (int j = 0; j < this->Column; j++) {
						// �摜�̈�ɐ���`��
						for (int k = 0; k < this->TableInfo->Count; k++) {
							if ((this->TableInfo[k]->first->first == "text" || this->TableInfo[k]->first->first == "array") && this->TableInfo[k]->second == ("x" + Convert::ToString(j) + Convert::ToString(i))) {
								System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * j, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
								gr->DrawRectangle(Pens::Black, *rct);
								// �摜�̈�ɕ��������������
								System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
								//�\�ɃC���f�b�N�X��t����
								gr->DrawString(this->TableInfo[k++]->first->second, myFont, Brushes::Black, *rct);
								break;
							}
							else if (this->TableInfo[k]->first->first == "arraybegin") {
								k += 1;
								for (; j < this->Column; j++) {
									System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * j, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
									gr->DrawRectangle(Pens::Black, *rct);
									// �摜�̈�ɕ��������������
									System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
									//�\�ɃC���f�b�N�X��t����
									gr->DrawString(this->TableInfo[k++]->first->second, myFont, Brushes::Black, *rct);
								}
								break;
							}
						}
					}
				}
			}
			//�쐬�����\�摜�𔽉f
			PictBox->Image = img;
			//�s�N�`���[�{�b�N�X��ԋp
			return PictBox;
		}
		/*�I���ӏ����n�C���C�g����֐�*/

		/*�I���ӏ����n�C���C�g���邽�߂̉摜�𐶐�����֐�*/
		PictureBox^ pict(PictureBox^ PictSelect) {
		//�������̓h��Ԃ��p�̃u���V���쐬
		Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Yellow));
		//�r�b�g�}�b�v�𐶐�
		Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
		//�`����s���O���t�B�b�N�X�N���X�𐶐�
		Graphics^ gr = Graphics::FromImage(img);
		//������Ԃł����
		if (this->join[*this->RowIndex] != "") {
			// �摜�̈�ɐ���`��
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

		/*�l�̕ύX��ʂɕ\������摜�𐶐�����֐�*/
		Bitmap^ ValueChange() {
			String^ Xindex = "x" + Convert::ToString(this->ColumnIndex) + Convert::ToString(this->RowIndex);
			String^ Yindex = "y" + Convert::ToString(this->RowIndex);
			//�r�b�g�}�b�v�𐶐�
			Bitmap^ img = gcnew Bitmap(1000, 1000);
			//�`����s���O���t�B�b�N�N���X�𐶐�
			Graphics^ gr = Graphics::FromImage(img);
			int count = 0;
			//�N���b�N���ꂽ�Z���ɑΉ����������擾���A�`��
			for (int i = 0; i < this->TableInfo->Count; i++) {
				//�N���b�N���ꂽ�Z���ɑΉ�����������������
				if (this->TableInfo[i]->second == Xindex || this->TableInfo[i]->second == Yindex || this->TableInfo[i]->second == "title") {
					gr->DrawRectangle(Pens::Black, 0, *this->RctHeight * count, *this->RctWidth, *this->RctHeight);
					// �摜�̈�ɕ��������������
					System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
					//�\�ɃC���f�b�N�X��t����
					gr->DrawString(this->TableInfo[i]->first->first, myFont, Brushes::Black, 0, *this->RctHeight * count);
					gr->DrawRectangle(Pens::Black, *this->RctWidth, *this->RctHeight * count, *this->RctWidth, *this->RctHeight);
					// �摜�̈�ɕ��������������
					//�\�ɃC���f�b�N�X��t����
					gr->DrawString(this->TableInfo[i]->first->second, myFont, Brushes::Black, *this->RctWidth, *this->RctHeight * count++);
					//�l���Ƃ肾�����ӏ��̓Y�������擾����B
					this->Index->Add(i);
				}
			}
			return img;
		}

		/*�I���ӏ�������/��������֐�*/
		Void JoinRelease() {
			//���łɌ�����Ԃł����
			if (join[*this->RowIndex] != "") {
				//������Ԃɉ�������B
				this->join[*this->RowIndex] = "";
			}
			else {
				//������Ԃɂ���B
				this->join[*this->RowIndex] = Convert::ToString(this->ColumnIndex);
			}
		}

		/*�\���ĕ`�悷��֐�
		�쐬���F2017.9.12
		�쐬�ҁFK.Asada*/
		PictureBox^ ReTable(PictureBox^ pct,int dex) {
			//�ĕ`��̂��߂̃O���t�B�b�N�N���X���C���X�^���X��
			Graphics^ gr = Graphics::FromImage(pct->Image);
			//�h��Ԃ��p�̃u���V�𐶐�
			Brush^ br = gcnew SolidBrush(Color::FromArgb(255, Color::White));
			//������Ԃł����
			if (this->join[*this->RowIndex] != "") {
				// �摜�̈�ɐ���`��
//				gr->DrawingRectangle(br, 0, 0, *this->RctWidth * *this->Column - 1, *this->RctHeight - 1);
			}
			else {
				gr->FillRectangle(br, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
				gr->DrawRectangle(Pens::Black, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
				// �摜�̈�ɕ������������
				System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
				//�\�ɃC���f�b�N�X��t����
				gr->DrawString(this->TableInfo[this->Index[dex]]->first->second, myFont, Brushes::Black, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
			}
			return pct;
		}

		/*�N���b�N���ꂽ�Z�����擾����֐�
		�쐬���F2017.9.11
		�쐬�ҁFK.Asada
		*/
		Void CalPoint(System::Windows::Forms::MouseEventArgs^  e) {
			//�\�̍s�̍��W���擾����
			this->RowIndex = (e->Location.Y / *this->RctHeight);
			//�\�̗�̍��W���擾����
			if (this->join[*this->RowIndex] != "") {
				//�����̍��W���擾�B
				this->ColumnIndex = Convert::ToInt32(this->join[*this->RowIndex]);
			}
			else {
				//�\�̍s�̍��W���擾����
				this->ColumnIndex = (e->Location.X / *this->RctWidth);
			}
		}

		
	};
}