#pragma once
#include "OptionForm.h"			//�ݒ��ʃN���X�̃w�b�_
#include "ConstantString.h"		//����萔�N���X�̃w�b�_
#include "CellDataChain.h"		//����f�[�^�`�F�C���N���X�̃w�b�_
#include <list>

namespace TableInformation {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace CONSTANTS;		//����萔�N���X���O���

	/*�T�v�F���C����ʂɏo�͂����\�摜�֘A�̊֐����܂Ƃ߂����N���X
	�쐬���F2017.9.20
	�쐬�ҁFK.Asada
	*/
	public ref class TableInformation : public System::Windows::Forms::Form {
	public:
		//�f�t�H���g�R���X�g���N�^
		TableInformation() {
		};

		ConstantString^ Constants = gcnew ConstantString();	//�萔�N���X�̃C���X�^���X��
		Int32^ Row = Constants->ZERO;						//�\�̍s��
		Int32^ Column = Constants->ZERO;					//�\�̗�
		Int32^ RowIndex = Constants->ZERO;					//�N���b�N���ꂽ�\�̃^�e���W
		Int32^ ColumnIndex = Constants->ZERO;				//�N���b�N���ꂽ�\�̃��R���W
		Int32^ RctWidth = 200;								//�\�̊i�q�������̕�
		Int32^ RctHeight = 100;								//�\�̊i�q�������̍���
		List<Int32>^ JoinIndex = gcnew List<Int32>();		//�Z���̌�������ێ����郊�X�g�^�z��
		CellDataChain::cellchain* TableElem = NULL;					//�\�̏�񂪊i�[���ꂽ�f�[�^�`�F�C��
		String^ JSONFilePath = Constants->EMPTY_STRING;		//�ǂݍ���JSON�̃t�@�C���p�X
		String^ DBQuery = Constants->EMPTY_STRING;			//DB���JSON��������擾���邽�߂̃N�G��

		/*�T�v�F�����o�ϐ��̏������Ƃɕ\�摜�𐶐�����֐�
		�����F�Ȃ�
		�߂�l�FBitmap^�F���������\�摜
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ TableGenerate(PictureBox^ pict) {
			//�`�F�C���\������N���X���C���X�^���X��
			CellDataChain* CellCtrl = new CellDataChain();
			//��̃r�b�g�}�b�v�𐶐�
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
			//�`����s�����߂̃O���t�B�b�N�N���X���C���X�^���X��
			Graphics^ gr = Graphics::FromImage(img);
			//�������`�悷��Ƃ��̏��̂�錾
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//�s���ɂ��ă��[�v
			for (int i = 0; i < *this->Row; i++) {
				//�`��Ώۂ̃f�[�^���A����Ԃł����
				if (this->JoinIndex[i] != Constants->ZERO) {
					//���̍s����̊i�q�ŕ\������
					gr->DrawRectangle(Pens::Black, 0, *this->RctHeight * i, *this->RctWidth * *this->Column, *this->RctHeight);
					//�A�����ɑI�����Ă����i�q�̕������`�悷��
					gr->DrawString(gcnew String(CellCtrl->GetChainData(*this->RowIndex, *this->ColumnIndex, this->TableElem)), myFont, Brushes::Black, *this->RctWidth * *this->Column / 2, *this->RctHeight* i);
				}//��������Ă��Ȃ���΂��̂܂ܗ�̃��[�v�Ɉڂ�
				else {
					for (int j = 0; j < *this->Column; j++) {
						//�i�q���쐬����
						gr->DrawRectangle(Pens::Black, *this->RctWidth * j, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
						//�A�����ɑI�����Ă����i�q�̕������`�悷��
						gr->DrawString(gcnew String(CellCtrl->GetChainData(*this->RowIndex, *this->ColumnIndex, this->TableElem)), myFont, Brushes::Black, *this->RctWidth * j, *this->RctHeight * i);
					}
				}
			}
			//�쐬�����摜���s�N�`���{�b�N�X�ւ̃Z��
			pict->Image = img;
			//�쐬�̏I�����r�b�g�}�b�v�摜��Ԃ�
			return pict;
		}

		/*�T�v�F�I���ӏ��̃Z�����n�C���C�g����֐�
		�����FPictureBox^�F�摜���ڂ���R���g���[��
		�߂�l�GPictureBox^�F�摜���ڂ����R���g���[��
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ SelecteCell(PictureBox^ Pictselect) {
			//�������F�̓h��Ԃ��p�u���V���쐬
			Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Yellow));
			//�摜�f�[�^�𐶐�����
			Bitmap^ img = gcnew Bitmap(*this->RctWidth + 1, *this->RctHeight + 1);
			//�`��p�̃O���t�B�b�N�N���X���C���X�^���X��
			Graphics^ gr = Graphics::FromImage(img);
			//�I�������Z����������Ԃł����
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//�摜���ڂ���ʒu��ݒ肷��
				Pictselect->Location = System::Drawing::Point(0, *this->RctHeight * *this->RowIndex);
				//�摜�̃T�C�Y��ݒ肷��
				Pictselect->Size = System::Drawing::Size(*this->RctWidth * *this->Column, *this->RctHeight);
				//�n�C���C�g�p�̔������F�h��Ԃ��摜��`��
				gr->FillRectangle(br, 0, 0, *this->RctWidth * *this->Column - 1, *this->RctHeight - 1);
			}//������ԂłȂ����
			else {
				//�摜���ڂ���ʒu��ݒ肷��
				Pictselect->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//�摜�̃T�C�Y��ݒ�
				Pictselect->Size = System::Drawing::Size(*this->RctWidth, *this->RctHeight);
				//�n�C���C�g�p�̓h��Ԃ��摜��`��
				gr->FillRectangle(br, 0, 0, *this->RctWidth - 1, *this->RctHeight - 1);
			}
			//�`��̏I������摜���s�N�`���{�b�N�X�̃R���g���[���ɏ悹��
			Pictselect->Image = img;
			//�����̏I������s�N�`���{�b�N�X��Ԃ�
			return Pictselect;
		}

		/*�T�v�F�ڍ׃_�C�A���O�ɏo�͂���摜�𐶐�����֐�
		�����FPictureBox^�F�摜���ڂ���s�N�`���{�b�N�X
		�߂�l�FPictureBox^�F���������摜���ڂ����s�N�`���{�b�N�X
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ MoreDetail(PictureBox^ detailtable) {
			CellDataChain::cellchain* detail;	//�ڍ׉�ʂɏ悹�邽�߂̍\����
			//�`�F�C���\������N���X���C���X�^���X��
			CellDataChain CellCtrl;
			//�`��p�̃r�b�g�}�b�v�𐶐�
			Bitmap^ img = gcnew Bitmap(*this->RctWidth, *this->RctHeight * *this->Row);
			//�������`�悷��Ƃ��̏��̂�錾
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//�I���ӏ��̍\���̂��擾����
			//detail = CellCtrl.GetChainData(*this->RowIndex, *this->ColumnIndex, this->TableElem);
			//�\���̂̑I���ӏ��̐e�L�[�����ׂĘA������֐����Ăяo��
			//detail = CellCtrl.GetChainParent(detail);
			//�\���̂̒��g���Ȃ��Ȃ�܂Ń��[�v
			for (CellDataChain::cellchain* tmp = detail; tmp->lower != nullptr; tmp = tmp->lower) {
				//�O���t�B�b�N�N���X���C���X�^���X��
				Graphics^ gr = Graphics::FromImage(img);
				//�Z����`�悷��
				//gr->DrawRectangle(Pens::Black, *this->RctWidth, *this->RctHeight);
				//������`�悷��
				//gr->DrawString(tmp->key, myFont, Brushes::Black);
			}
			//���������摜���s�N�`���{�b�N�X�ɔ��f����
			detailtable->Image = img;
			//�s�N�`���{�b�N�X��Ԃ�
			return detailtable;
		}

		/*�T�v�F�I���ӏ�������/��������֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		Void JoinRelease() {
			//���łɌ�����Ԃł����
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//������Ԃ���������
				this->JoinIndex[*this->RowIndex] = Constants->ZERO;
			}//������ԂłȂ����
			else {
				//������Ԃɂ���
				this->JoinIndex[*this->RowIndex] = Constants->ZERO;
			}
		}

		/*�T�v�F�N���b�N���ꂽ�Z���̍��W���擾����֐�
		�����FSystem::Windows::Forms::MouseEventArgs^�F�}�E�X�̃C�x���g�̕ϐ����i�[���ꂽ�N���X
		�߂�l�F�Ȃ�
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		Void GetCellPoint(System::Windows::Forms::MouseEventArgs^ e) {
			//�}�E�X�C�x���g�N���X���N���b�N�����Ƃ��̃}�E�X��Y���W���擾����
			this->RowIndex = e->Location.Y / *this->RctHeight;
			//�N���b�N�����s��������Ԃł����
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//�s�̂ǂ����N���b�N���Ă���Ɍ������Ă�����W���擾
				this->ColumnIndex = this->JoinIndex[*this->RowIndex];
			}//������ԂłȂ����
			else {
				//���̂܂܂̍��W���擾
				this->ColumnIndex = e->Location.X / *this->RctWidth;
			}
		}

		/*�T�v�F�\�摜�̈ꕔ���ĕ`�悷��֐�
		�����FPitcutreBox^�F�\�摜���ڂ���ꂽ�s�N�`���{�b�N�X
		�߂�l�FPictureBox^�F�\�摜�̈ꕔ���ĕ`�悵�����̂��̂����s�N�`���{�b�N�X
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ ReTableGenerate(PictureBox^ repict) {
			CellDataChain CellCtrl;
			//�`��̑Ώۂ����łɐ�������Ă���\�摜�ɂ��ăO���t�B�b�N�N���X���C���X�^���X��
			Graphics^ gr = Graphics::FromImage(repict->Image);
			//�h��Ԃ��p�̃u���V���쐬
			Brush^ br = gcnew SolidBrush(Color::FromArgb(255, Color::White));
			//���ŏ㏑�����邽�߂ɃZ���̑傫���Ɠ����h��Ԃ������`��`��
			gr->FillRectangle(br, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
			//���œh��Ԃ����Ƃ��ɘg���������邽�ߍĕ`�悷��
			gr->DrawRectangle(Pens::Black, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
			//�����������Ă��邽�ߍĕ`�悷��
			//gr->DrawString(CellCtrl.GetChainData(*this->RowIndex, *this->ColumnIndex), myFont, Brushes::Black, *this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
			//�ĕ`��̏I�����s�N�`���{�b�N�X��Ԃ�
			return repict;
		}

		/*�T�v�F�N���b�N���ꂽ�Z���ɕҏW�p�̃e�L�X�g�{�b�N�X��z�u����֐�
		�����F�z�u����e�L�X�g�{�b�N�X
		�߂�l�F�e�L�X�g�{�b�N�X�Ɉʒu���╶��������i�[��������
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		TextBox^ CellTextGenerate(TextBox^ cell) {
			CellDataChain CellCtrl;
			//������Ԃł����
			if (this->JoinIndex[*this->RowIndex] != Constants->ZERO) {
				//������Ԃ̂��ߍ��W�����̍s�̍���ɍ��킹��
				cell->Location = System::Drawing::Point(0, *this->RctHeight * *this->RowIndex);
				//������Ԃ̂��߁A�T�C�Y�����̍s�S�̂̑傫���ɍ��킹��
				cell->Size = System::Drawing::Size(*this->RctWidth * *this->Column, *this->RctHeight);
			}//������ԂłȂ����
			else {
				//���W��I�𒆂̃Z���̍���ɍ��킹��
				cell->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//�T�C�Y���Z���������̑傫���ɍ��킹��
				cell->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
			}
			//�e�L�X�g�{�b�N�X�Ɍ��̕\�摜�ɂ�������������ڂ���
//			cell->Text = CellCtrl.GetChainData(*this->RowIndex, *this->ColumnIndex);
			//�e�L�X�g�{�b�N�X�����ɉB��Č����Ȃ����Ƃ�����̂Ŗ����I�ɑO�ɔz�u
			cell->BringToFront();
			//���H���I�����e�L�X�g�{�b�N�X��Ԃ�
			return cell;
		}

		/*�T�v�F���̃N���X�̃����o�ϐ�������������֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		Void InfoInit() {
			this->Row = Constants->ZERO;				//�s��������������
			this->Column = Constants->ZERO;				//�񐔂�����������
			this->RctWidth = 200;						//�Z���������̕�������������
			this->RctHeight = 100;						//�Z���������̍���������������
			this->JoinIndex->Clear();					//������������������
			this->JSONFilePath = Constants->EMPTY_STRING;//�ǂݍ��ݐ�̃t�@�C���p�X������������
			this->DBQuery = Constants->EMPTY_STRING;	//DB�֓�����N�G��������������
		}

		/*�T�v�F�ݒ��ʂ��J�����߂̊֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void ShowOptionForm() {
			//�ݒ��ʂ��J�����߂ɐݒ��ʃN���X���C���X�^���X��
			OptionForm^ opt = gcnew OptionForm();
			//�O��Ăяo�����̃f�[�^���ݒ��ʂ̃e�L�X�g�{�b�N�X�Ɋi�[�����悤�ɓn��
			opt->FilePath = this->JSONFilePath;
			//�O��Ăяo�����̃f�[�^���ݒ��ʂ̃e�L�X�g�{�b�N�X�Ɋi�[�����悤�ɓn��
			opt->SendQuery = this->DBQuery;
			//�ݒ��ʂ��J��
			opt->ShowDialog();
			//�ݒ��ʂɂĎ擾����JSON�t�@�C���p�X���擾����
			this->JSONFilePath = opt->FilePath;
			//�ݒ��ʂɂĎ擾����DB�N�G�����擾����
			this->DBQuery = opt->SendQuery;
		}
	};
}