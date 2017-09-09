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

namespace process {
	using namespace std;
	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace constantstring;
	using namespace boost::property_tree;

	/*�\�摜�𐶐�����N���X
	�쐬���F2017.9.9
	�쐬�ҁGK.Asada*/
	ref class TableProcessing {
	private:
		TableProcessing() {
		};

	public:

		Int32 Row = 0;			//�\�̍s��
		Int32 Column = 0;		//�\�̗�
		Int32 RowIndex = 0;		//�N���b�N���ꂽ�Z���̍s���W
		Int32 ColumnIndex = 0;	//�N���b�N���ꂽ�Z���̗���W
		Int32 RctWidth = 0;		//�Z���������̕�
		Int32 RctHeight = 0;	//�Z���������̍���
		cli::array<String^>^ join = gcnew cli::array<String^>(this->Row);
		List<cliext::pair<String^, String^>^>^ TableOut = gcnew List<cliext::pair<String^, String^>^>();
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ TableInfo = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();

		//�R���X�g���N�^
		TableProcessing(Int32 row, Int32 column, Int32 rowindex, Int32 columnindex, List<cliext::pair<String^, String^>^>^ strout, List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ tblinfo): Row(0), Column(0), RowIndex(0),ColumnIndex(0) {
			this->TableOut = strout;
			this->TableInfo = tblinfo;
		}

		/*�\�𐶐�����֐�
		*/
		Bitmap^ TableGenerate() {
			Bitmap^ img = gcnew Bitmap(this->RctWidth * this->Column + 1, this->RctHeight * this->Row + 1);
			//�`����s���O���t�B�b�N�X�N���X�𐶐�
			Graphics^ gr = Graphics::FromImage(img);
			for (int i = 0; i < this->Row; i++) {
				//������Ԃł����
				if (this->join[i] != "") {
					// �摜�̈�ɐ���`��
					gr->DrawRectangle(Pens::Black, 0, this->RctHeight * i, this->RctWidth * this->Row, this->RctHeight);
					// �摜�̈�ɕ��������������
					System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
					//�s�̒��S�ɃC���f�b�N�X��t����
					//gr->DrawString(Convert::ToString(count++), myFont, Brushes::Black, this->rctwidth *this-> row / 2, this->rctheight * i);
				}
				else {
					for (int j = 0; j < this->Column; j++) {
						// �摜�̈�ɐ���`��
						gr->DrawRectangle(Pens::Black, this->RctWidth * j, this->RctHeight * i, this->RctWidth, this->RctHeight);
						// �摜�̈�ɕ��������������
						System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
						//�\�ɃC���f�b�N�X��t����
						//gr->DrawString(Convert::ToString(count++), myFont, Brushes::Black, this->rctwidth * j, this->rctheight * i);
					}
				}
			}
			//�쐬�����\�摜�𔽉f
			return img;
		}
		/*�I���ӏ����n�C���C�g����֐�*/

		/*�l�̕ύX��ʂ�\������֐�*/

		/*�I���ӏ�������/��������֐�*/

		/*�\���ĕ`�悷��֐�*/
	};
}