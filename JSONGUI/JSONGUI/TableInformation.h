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
		Int32^ rowcount = Constants->ZERO;					//�\�̍s�����J�E���g���邽�߂̕ϐ�
		Int32^ colcount = Constants->ZERO;					//�\�̗񐔂��J�E���g���邽�߂̕ϐ�
		Int32^ RowIndex = Constants->ZERO;					//�N���b�N���ꂽ�\�̃^�e���W
		Int32^ ColumnIndex = Constants->ZERO;				//�N���b�N���ꂽ�\�̃��R���W
		Int32^ RctWidth = 200;								//�\�̊i�q�������̕�
		Int32^ RctHeight = 100;								//�\�̊i�q�������̍���
		List<int>^ JoinIndex = gcnew List<int>();		//�Z���̌�������ێ����郊�X�g�^�z��
		CellDataChain::cellchain^ TableElem = nullptr;					//�\�̏�񂪊i�[���ꂽ�f�[�^�`�F�C��
		String^ JSONFilePath = Constants->EMPTY_STRING;		//�ǂݍ���JSON�̃t�@�C���p�X
		String^ DBQuery = Constants->EMPTY_STRING;			//DB���JSON��������擾���邽�߂̃N�G��

		/*�T�v�F�����o�ϐ��̏������Ƃɕ\�摜�𐶐�����֐�
		�����F�Ȃ�
		�߂�l�FBitmap^�F���������\�摜
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ TableGenerate(PictureBox^ pict) {
			//�`�F�C���\������N���X���C���X�^���X��
			CellDataChain^ CellCtrl = gcnew CellDataChain();
			//��̃r�b�g�}�b�v�𐶐�
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
			//�`����s�����߂̃O���t�B�b�N�N���X���C���X�^���X��
			Graphics^ gr = Graphics::FromImage(img);
			//�\�ɕ\������v�f�Ƃ��ăI�u�W�F�N�g���������ꍇ�ɐF�t�����s�����߂̃u���V�𐶐�
			Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Blue));
			//�������`�悷��Ƃ��̏��̂�錾
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//�s���ɂ��ă��[�v
			for (int i = 0; i < *this->Row; i++) {
				//�����`�̑傫�����w��
				System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(0, *this->RctHeight * i, *this->RctWidth, *this->RctHeight);
				//�`��Ώۂ̃f�[�^���A����Ԃł����
				if (this->JoinIndex[i] != Constants->ZERO) {
					//�\�ɕ\������f�[�^���������\���̂��擾
					CellDataChain::cellchain^ elem = CellCtrl->GetColumnChain(i, JoinIndex[i], this->TableElem->lower);
					//���̍s����̊i�q�ŕ\������
					gr->DrawRectangle(Pens::Black, *rct);
					//�A�����ɑI�����Ă����i�q�̕������`�悷��
					gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
				}//��������Ă��Ȃ���΂��̂܂ܗ�̃��[�v�Ɉڂ�
				else {
					//�s�̗v�f�̕`��Ɉڍs����
					for (int j = 0; j < *this->Column; j++) {
						//�\�����ׂ��v�f���������\���̂��擾����
						CellDataChain::cellchain^ elem = CellCtrl->GetColumnChain(i, j, this->TableElem->lower);
						//�`�悷�钷���`�̑傫����ݒ肷��
						System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth*j, *this->RctHeight*i, *this->RctWidth, *this->RctHeight);
						//�i�q���쐬����
						gr->DrawRectangle(Pens::Black, *rct);
						//�\�����ׂ��v�f���I�u�W�F�N�g���f�[�^���𔻒肷��
						if (elem->lower != nullptr) {
							//�q�v�f�������Ă��邱�Ƃ𖾎����邽�߂ɐF�t�����s��
							gr->FillRectangle(br, *rct);
							//�h��Ԃ��������ɃL�[����`�悷��
							gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
						}//�f�[�^�΂����͒l��\��
						else {
							gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
						}
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
			//�w�i�F��e�̐F�Ɠ���������
			Pictselect->BackColor = Color::Transparent;
			//�����̏I������s�N�`���{�b�N�X��Ԃ�
			return Pictselect;
		}

		/*�T�v�F�ڍ׃_�C�A���O�ɏo�͂���摜�𐶐�����֐�
		�����FPictureBox^�F�摜���ڂ���s�N�`���{�b�N�X
		�߂�l�FPictureBox^�F���������摜���ڂ����s�N�`���{�b�N�X
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ MoreDetail(PictureBox^ detailtable) {
			CellDataChain::cellchain^ detail = gcnew CellDataChain::cellchain();	//�ڍ׉�ʂɏ悹�邽�߂̍\����
			//�`�F�C���\������N���X���C���X�^���X��
			CellDataChain CellCtrl;
			//�`��p�̃r�b�g�}�b�v�𐶐�
			Bitmap^ img = gcnew Bitmap(*this->RctWidth, *this->RctHeight * *this->Row);
			//�������`�悷��Ƃ��̏��̂�錾
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//�\���̂̒��g���Ȃ��Ȃ�܂Ń��[�v
			for (CellDataChain::cellchain^ tmp = detail; tmp->lower != nullptr; tmp = tmp->lower) {
				//�O���t�B�b�N�N���X���C���X�^���X��
				Graphics^ gr = Graphics::FromImage(img);
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
			//�`��̑Ώۂ����łɐ�������Ă���\�摜�ɂ��ăO���t�B�b�N�N���X���C���X�^���X��
			Graphics^ gr = Graphics::FromImage(repict->Image);
			//�h��Ԃ��p�̃u���V���쐬����
			Brush^ br = gcnew SolidBrush(Color::FromArgb(255, Color::White));
			//�`�悷�镶���̃t�H���g���쐬����
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//�\���̑���N���X���C���X�^���X��
			CellDataChain^ CellCtrl = gcnew CellDataChain();
			//�v�f���i�[���ꂽ�\���̂��擾����
			CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
			//�`�悷��Z����ݒ肷��
			System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex, *this->RctWidth, *this->RctHeight);
			//�`�悷��v�f�������̂��ꂽ�\���̂��擾����
			elem = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
			//���ŏ㏑�����邽�߂ɃZ���̑傫���Ɠ����h��Ԃ������`��`��
			gr->FillRectangle(br, *rct);
			//�q�����邩�ǂ����ŃI�u�W�F�N�g���ǂ����𔻒肷��
			if (elem->lower != nullptr) {
				//�h��Ԃ��p�̃u���V���쐬����
				Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Blue));
				//�q������΃I�u�W�F�N�g�Ƃ��ĐF�t�����s��
				gr->FillRectangle(br, *rct);
				//�����`�̘g����`�悷��
				gr->DrawRectangle(Pens::Black, *rct);
				//�I�u�W�F�N�g�̂��ߍ\���̂���L�[�����擾���ĕ`�悷��
				gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
			}//�q�����Ȃ��Ƃ��̓f�[�^�Ƃ��ĐF�t���͍s��Ȃ�
			else {
				//�g���������邽�ߍĕ`�悷��
				gr->DrawRectangle(Pens::Black,*rct);
				//�f�[�^�̂��߃L�[���ł͂Ȃ��l��`�悷��
				gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
			}
			//�ĕ`��̏I�����s�N�`���{�b�N�X��Ԃ�
			return repict;
		}

		/*�T�v�F�N���b�N���ꂽ�Z���ɕҏW�p�̃e�L�X�g�{�b�N�X��z�u����֐�
		�����F�z�u����e�L�X�g�{�b�N�X
		�߂�l�F�e�L�X�g�{�b�N�X�Ɉʒu���╶��������i�[��������
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		TextBox^ CellTextGenerate(TextBox^ cell) {
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
			//�\���̂𑀍삷�邽�߂̃N���X���C���X�^���X��
			CellDataChain^ CellCtrl = gcnew CellDataChain();
			//�v�f���������\���̂��i�[���邽�߂̍\���̂�錾
			CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
			//�Ώۂ̍\���̂��擾����
			elem = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
			//�\���̂��I�u�W�F�N�g���ǂ����𔻒肷��
			if (elem->lower != nullptr) {
				//�e�L�X�g�{�b�N�X�ɑΏۂ̍\���̂̃L�[�����ڂ���
				cell->Text = elem->key;
			}
			else {
				//�f�[�^�̏ꍇ�͒l���ڂ���
				cell->Text = elem->value;
			}
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
			option::OptionForm^ opt = gcnew option::OptionForm();
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

		/*�T�v�F�\�ɍs��}�����邽�߂̊֐�
		�����FInt32 rowindex�F�}���Ώۂ̍s
			�FInt32 column�F�\�S�̗̂�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada*/
		Void RowAdd(Int32 rowindex, Int32 column) {
			CellDataChain cellctrl;
			//�}���Ώۂ̍\���̂��i�[���邽�߂̍\����
			CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
			//�}���Ώۂ̍\���̂��擾����
			parent = cellctrl.GetRowChain(rowindex, this->TableElem->lower);
			//�Ώۂ̒�Ƃ��ċ�̍\���̂�A������
			parent = cellctrl.ChainYoungBrother("", "", parent);
			//�q�Ƃ��ĘA������\���̂�錾����
			CellDataChain::cellchain^ child = gcnew CellDataChain::cellchain();
			//�q��A������
			child = cellctrl.ChainChild("", "", parent);
			//�񐔂Ɠ��������q�ɒ��A�����Ă�
			for (int i = 2; i < column; i++) {
				//���A������
				child = cellctrl.ChainYoungBrother("", "", child);
			}
			return;
		}

		/*�T�v�F�\�ɗ��ǉ����邽�߂̊֐�
		�����FInt32 row:�\�S�̂̍s��
			�FInt32 columnindex�F�ǉ��Ώۂ̗���W
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada*/
		Void ColumnAdd(Int32 row, Int32 columnindex) {
			CellDataChain cellctrl;
			//�\�̐e�̍\���̂��i�[���邽�߂̍\����
			CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
			//��v�f�ɓ�����\���̂�}�����邽�߂̊֐�
			for (int i = 0; i < row; i++) {
				//�s���Ƃ̒ǉ��Ώۂ̍\���̂��擾����
				parent = cellctrl.GetColumnChain(i, columnindex, this->TableElem->lower);
				//�Ώۂɒ��A������
				cellctrl.ChainYoungBrother("", "", parent);
			}
		}

		/*�T�v�F�\�̗񐔂�����o�����߂̊֐�
		�����Fcellchain^ colchain�F�J�E���g�Ώۂ̍\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada*/
		Void CountColumn(CellDataChain::cellchain^ colchain) {
			//��v�f�̍\���̂𑖍����ė񐔂��J�E���g����
			for (; colchain != nullptr; colchain = colchain->next) {
				//�񐔃J�E���g�p�̃����o�ϐ����C���N�������g
				*this->colcount += 1;
			}
			return;
		}

		/*�T�v�F�\�̗񐔂�����o�����߂̊֐�
		�����Fcellchain^ rowchain�F�J�E���g�Ώۂ̍\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada*/
		Void CountRow(CellDataChain::cellchain^ rowchain) {
			//�s�̍Ō�܂ő������čs�����J�E���g����
			for (; rowchain != nullptr; rowchain = rowchain->next) {
				//�s�̐e����̗v�f�̈�Ƃ��邽�߂ɗ񐔃J�E���g���C���N�������g
				*this->colcount += 1;
				//�s�����C���N�������g
				*this->rowcount += 1;
				//�q������΍ċA���ė񐔂̃J�E���g�Ɉڂ�
				if (rowchain->lower != nullptr) {
					//�񐔂��J�E���g����֐����Ăяo��
					this->CountColumn(rowchain->lower);
				}
				//�����܂ŃJ�E���g���Ă����񐔂������̗񐔂��傫�����
				if (*this->colcount > *this->Column) {
					//�傫�������̗p����
					this->Column = this->colcount;
				}
				//�񐔃J�E���g�����Z�b�g����
				this->colcount = 0;
			}
			//�����܂ŃJ�E���g���Ă����s���������̍s�����傫�����
			if (*this->rowcount > *this->Row) {
				//�傫�������̗p����
				this->Row = this->rowcount;
			}
			//�s���J�E���g�����Z�b�g����
			this->rowcount = 0;
			return;
		}

		/*�T�v�F�ڍוҏW��ʂɏo�͂���\�摜�𐶐�����֐�
		�����FPictureBox^ pict�F���������\�摜���ڂ���s�N�`���{�b�N�X
		�߂�l�FPictureBox^ pict�F�K�v����ݒ肵���s�N�`���{�b�N�X
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada*/
		PictureBox^ infoTableGenerate(CellDataChain::cellchain^ tableelem, PictureBox^ pict, Int32 parentcount) {
			//�\���̂𑀍삷�邽�߂̃N���X���C���X�^���X������
			CellDataChain^ CellCtrl = gcnew CellDataChain();
			//�`�悷��Ώۂ̍\���̂��擾���邽�߂̍\����
			CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
			//�`����s����̃r�b�g�}�b�v���쐬����
			Bitmap^ img = gcnew Bitmap(*this->RctWidth * parentcount, *this->RctHeight);
			//�`����s�����߂̃O���t�B�b�N�N���X���C���X�^���X��
			Graphics^ gr = Graphics::FromImage(img);
			//�`�悷�镶���̃t�H���g���쐬����
			System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
			//�e�L�[���Ȃ��Ȃ�܂ő�������
			for (int i = parentcount;i > 0;i--) {
				//�b���Ώۂ̃L�[�����i�[���ꂽ�\���̂��擾����
				elem = CellCtrl->GetParent(tableelem, i);
				//�`�悷��Z���̃v���p�e�B����͂���
				System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * (parentcount - i), 0, *this->RctWidth, *this->RctHeight);
				//�����`��`�悷��
				gr->DrawRectangle(Pens::Black, *rct);
				//�������`�悷��
				gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
			}
			//�`����I�����r�b�g�}�b�v��ݒ肷��
			pict->Image = img;
			//�s�N�`���{�b�N�X��ԋp����
			return pict;
		}
	};
}