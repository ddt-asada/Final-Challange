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
		CellDataChain::cellchain^ TableElem = nullptr;					//�\�̏�񂪊i�[���ꂽ�f�[�^�`�F�C��
		String^ JSONFilePath = Constants->EMPTY_STRING;		//�ǂݍ���JSON�̃t�@�C���p�X
		String^ DBQuery = Constants->EMPTY_STRING;			//DB���JSON��������擾���邽�߂̃N�G��

		/*�T�v�F�����o�ϐ��̏������Ƃɕ\�摜�𐶐�����֐�
		�����F�Ȃ�
		�߂�l�FBitmap^�F���������\�摜
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ TableGenerate(PictureBox^ pict) {
			//�\�̕`��̎��ɕs�����o���Ƃ��̗�O��ߑ�
			try {
				//�`�F�C���\������N���X���C���X�^���X��
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//��̃r�b�g�}�b�v�𐶐�
				Bitmap^ img = gcnew Bitmap(*this->RctWidth * *this->Column + 1, *this->RctHeight * *this->Row + 1);
				//�`����s�����߂̃O���t�B�b�N�N���X���C���X�^���X��
				Graphics^ gr = Graphics::FromImage(img);
				//�s���ɂ��ă��[�v
				for (int i = 0; i < *this->Row; i++) {
					//�s�̗v�f�̕`��Ɉڍs����
					for (int j = 0; j < *this->Column; j++) {
						//�\�����ׂ��v�f���������\���̂��擾����
						CellDataChain::cellchain^ elem = CellCtrl->GetColumnChain(i, j, this->TableElem->lower);
						//�`�悷�钷���`�̑傫����ݒ肷��
						System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth*j, *this->RctHeight*i, *this->RctWidth, *this->RctHeight);
						//�Z����`�悷��֐����Ăяo��
						this->DrawFigure(*rct, gr, elem);
					}
				}
				//�쐬�����摜���s�N�`���{�b�N�X�ւ̃Z��
				pict->Image = img;
				//�쐬�̏I�����r�b�g�}�b�v�摜��Ԃ�
				return pict;
			}
			//�`��Ώۂ�Image�����������������̗�O��ߑ�
			catch (System::FormatException^ e) {
				//�`��Ώۂ����݂��Ă��Ȃ����Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->DRAW_ERROR_STRING + e);
			}
			//�`�悷��Z���i�����`�̑傫���j�̌v�Z�ŕs���l���o���Ƃ��̗�O��ߑ�
			catch (System::OverflowException^ e) {
				//�Z���̑傫����񂪕s���ł��邱�Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->RECT_ERROR_STRING + e);
			}
		}

		/*�T�v�F�I���ӏ��̃Z�����n�C���C�g����֐�
		�����FPictureBox^�F�摜���ڂ���R���g���[��
		�߂�l�GPictureBox^�F�摜���ڂ����R���g���[��
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ SelecteCell(PictureBox^ Pictselect) {
			try {
				//�������F�̓h��Ԃ��p�u���V���쐬
				Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Yellow));
				//�摜�f�[�^�𐶐�����
				Bitmap^ img = gcnew Bitmap(*this->RctWidth + 1, *this->RctHeight + 1);
				//�`��p�̃O���t�B�b�N�N���X���C���X�^���X��
				Graphics^ gr = Graphics::FromImage(img);
				//�摜���ڂ���ʒu��ݒ肷��
				Pictselect->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//�摜�̃T�C�Y��ݒ�
				Pictselect->Size = System::Drawing::Size(*this->RctWidth, *this->RctHeight);
				//�n�C���C�g�p�̓h��Ԃ��摜��`��
				gr->FillRectangle(br, 0, 0, *this->RctWidth - 1, *this->RctHeight - 1);
				//�`��̏I������摜���s�N�`���{�b�N�X�̃R���g���[���ɏ悹��
				Pictselect->Image = img;
				//�w�i�F��e�̐F�Ɠ���������
				Pictselect->BackColor = Color::Transparent;
				//�����̏I������s�N�`���{�b�N�X��Ԃ�
				return Pictselect;
			}
			//�`��Ώۂ�Image�����������������̗�O��ߑ�
			catch (System::FormatException^ e) {
				//�`��Ώۂ����݂��Ă��Ȃ����Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->DRAW_ERROR_STRING + e);
			}
			//�`�悷��Z���i�����`�̑傫���j�̌v�Z�ŕs���l���o���Ƃ��̗�O��ߑ�
			catch (System::OverflowException^ e) {
				//�Z���̑傫����񂪕s���ł��邱�Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->RECT_ERROR_STRING + e);
			}
		}

		/*�T�v�F�N���b�N���ꂽ�Z���̍��W���擾����֐�
		�����FSystem::Windows::Forms::MouseEventArgs^�F�}�E�X�̃C�x���g�̕ϐ����i�[���ꂽ�N���X
		�߂�l�F�Ȃ�
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada
		�X�V���e�F������Ԃ̔�����폜
		�X�V���F2017.9.29
		�X�V�ҁFK.Asada*/
		Void GetCellPoint(System::Windows::Forms::MouseEventArgs^ e) {
			//�Z�p�G���[��ߑ����邽�߂̗�O����
			try {
				//�}�E�X�C�x���g�N���X���N���b�N�����Ƃ��̃}�E�X��Y���W���擾����
				this->RowIndex = e->Location.Y / *this->RctHeight;
				//X�̍��W���擾
				this->ColumnIndex = e->Location.X / *this->RctWidth;
				return;
			}
			//���������W���擾�ł��Ȃ������Ƃ��̃G���[��ߑ�
			catch (System::DivideByZeroException^ er) {
				//0�Ŋ����Ă�����Z�p�G���[�ɂ����W���擾�ł��Ȃ��������ƃR���\�[���ɕ\��
				Console::WriteLine(Constants->INPUT_ERROR_STRING + er);
			}
		}

		/*�T�v�F�\�摜�̈ꕔ���ĕ`�悷��֐�
		�����FPitcutreBox^�F�\�摜���ڂ���ꂽ�s�N�`���{�b�N�X
		�߂�l�FPictureBox^�F�\�摜�̈ꕔ���ĕ`�悵�����̂��̂����s�N�`���{�b�N�X
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		PictureBox^ ReTableGenerate(PictureBox^ repict) {
			//����ɕ`��ł��Ȃ������Ƃ��̗�O����
			try {
				//�`��̑Ώۂ����łɐ�������Ă���\�摜�ɂ��ăO���t�B�b�N�N���X���C���X�^���X��
				Graphics^ gr = Graphics::FromImage(repict->Image);
				//�h��Ԃ��p�̃u���V���쐬����
				Brush^ br = gcnew SolidBrush(Color::FromArgb(255, Color::White));
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
				//�Z����`�悷��֐����Ăяo��
				this->DrawFigure(*rct, gr, elem);
				//�ĕ`��̏I�����s�N�`���{�b�N�X��Ԃ�
				return repict;
			}
			//�`��Ώۂ̃s�N�`���{�b�N�X�̒���Image�����������������̗�O��ߑ�
			catch (System::FormatException^ e) {
				//�`��Ώۂ����݂��Ă��Ȃ����Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->DRAW_ERROR_STRING + e);
			}
			//�`�悷��Z���i�����`�̑傫���j�̌v�Z�ŕs���l���o���Ƃ��̗�O��ߑ�
			catch (System::OverflowException^ e) {
				//�Z���̑傫����񂪕s���ł��邱�Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->RECT_ERROR_STRING + e);
			}
		}

		/*�T�v�F�N���b�N���ꂽ�Z���ɕҏW�p�̃e�L�X�g�{�b�N�X��z�u����֐�
		�����F�z�u����e�L�X�g�{�b�N�X
		�߂�l�F�e�L�X�g�{�b�N�X�Ɉʒu���╶��������i�[��������
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada
		�X�V���F2017.9.29
		�X�V�ҁFK.Asada
		�X�V���e�F������Ԃ̔�����폜*/
		TextBox^ CellTextGenerate(TextBox^ cell) {
			//nullptr���w�����Ƃ��̗�O����
			try {
				//���W��I�𒆂̃Z���̍���ɍ��킹��
				cell->Location = System::Drawing::Point(*this->RctWidth * *this->ColumnIndex, *this->RctHeight * *this->RowIndex);
				//�T�C�Y���Z���������̑傫���ɍ��킹��
				cell->Size = System::Drawing::Size(*this->RctWidth + 1, *this->RctHeight + 1);
				//�\���̂𑀍삷�邽�߂̃N���X���C���X�^���X��
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//�v�f���������\���̂��i�[���邽�߂̍\���̂�錾
				CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
				//�Ώۂ̍\���̂��擾����
				elem = CellCtrl->GetColumnChain(*this->RowIndex, *this->ColumnIndex, this->TableElem->lower);
				//�\���̂��I�u�W�F�N�g���ǂ����𔻒肷��
				if (elem != nullptr && elem->lower != nullptr) {
					//�e�L�X�g�{�b�N�X�ɑΏۂ̍\���̂̃L�[�����ڂ���
					cell->Text = elem->key;
				}
				else if (elem != nullptr) {
					//�f�[�^�̏ꍇ�͒l���ڂ���
					cell->Text = elem->value;
				}
				else {
					//�\���̂��擾�ł��Ă��Ȃ��ꍇ�͋󕶎���}������
					cell->Text = Constants->EMPTY_STRING;
				}
				//���H���I�����e�L�X�g�{�b�N�X��Ԃ�
				return cell;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*�T�v�F���̃N���X�̃����o�ϐ�������������֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.20
		�쐬�ҁFK.Asada*/
		Void InfoInit() {
			this->Row = Constants->ZERO;				//�s��������������
			this->Column = Constants->ZERO;				//�񐔂�����������
			this->RowIndex = Constants->ZERO;			//�s���W������������
			this->ColumnIndex = Constants->ZERO;		//����W������������
			this->RctWidth = 200;						//�Z���������̕�������������
			this->RctHeight = 100;						//�Z���������̍���������������
			this->JSONFilePath = Constants->EMPTY_STRING;//�ǂݍ��ݐ�̃t�@�C���p�X������������
			this->DBQuery = Constants->EMPTY_STRING;	//DB�֓�����N�G��������������
			CellDataChain^ CellCtrl = gcnew CellDataChain();	//�\���̑���N���X���C���X�^���X��
			//�\���̂��폜����
			CellCtrl->DeleteChain(this->TableElem);
			return;
		}

		/*�T�v�F�ݒ��ʂ��J�����߂̊֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void ShowOptionForm() {
			//���͂��ꂽ�t�@�C���p�X�A�N�G���ɂ������Ȓl���������Ƃ��ɗ�O��ߑ����邽�߂̗�O����
			try {
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
			//�������ȕ����񂪋A���Ă����Ƃ��ɗ�O��ߑ�
			catch (System::FormatException^ e) {
				//�R���\�[���ɗ�O���e�A�x����\��
				Console::WriteLine(Constants->INPUT_ERROR_STRING + e);
			}
		}

		/*�T�v�F�\�ɍs��}�����邽�߂̊֐�
		�����FInt32 rowindex�F�}���Ώۂ̍s
		�����FString^ select�F�}������������������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada
		�X�V���e�F�����Ƃ��čs��^���邾���œ��삷��悤�ɕύX�A�ǉ��Ώۂ��Z�킾���ɕύX
		�X�V���F2017.9.27
		�X�V�ҁFK.Asasda
		�X�V���e�F�}���������w�肷��悤�ɕύX
		�X�V���F2017.9.28
		�X�V�ҁFK.Asada
		*/
		Void RowAdd(Int32 rowindex, String^ select) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//�}���Ώۂ̍\���̂��i�[���邽�߂̍\����
				CellDataChain::cellchain^ parent = nullptr;
				//�}���Ώۂ̍\���̂��擾����
				parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
				//�s�̑}����������Ɏw�肳��Ă�����
				if (select == "ElderButton") {
					//������ɍs��ǉ�����
					CellCtrl->ChainElderBrother("", "", parent);
				}//�s�̑}�����������Ɏw�肷��
				else {
					//�������ɍs��ǉ�����
					CellCtrl->ChainYoungBrother("", "", parent);
				}
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*�T�v�F�\�ɗ��ǉ����邽�߂̊֐�
		�����FInt32 row:�\�S�̂̍s��
			�FInt32 columnindex�F�ǉ��Ώۂ̗���W
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada
		�X�V���e�F�ǉ��Ώۂ̍\���̂��擾�ł��Ȃ������Ƃ��͂��̍s�̈�Ԓ�̍\���̂Ɉ���ǉ�����悤�ɕύX
		�X�V���F2017.9.27
		�X�V�ҁFK.Asada
		�X�V���e�F���ǉ�����������w�肷��悤�ɕύX
		�X�V���F2017.9.28
		�X�V�ҁFK.Asada*/
		Void ColumnAdd(Int32 row, Int32 columnindex, String^ select) {
			try {
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//�\�̐e�̍\���̂��i�[���邽�߂̍\����
				CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();
				//��v�f�ɓ�����\���̂�}�����邽�߂̊֐�
				for (int i = 0; i < row; i++) {
					//�s���Ƃ̒ǉ��Ώۂ̍\���̂��擾����
					parent = CellCtrl->GetColumnChain(i, columnindex, this->TableElem->lower);
					//����W��0��艺�̎��͍s�̐擪��I�����Ă���Ƃ��邽�߂̕���
					if (columnindex > 0) {
						//�Ώۂ��擾�ł����ꍇ�͂ǂ̕����ɒǉ����邩�𔻒肷��
						if (parent != nullptr) {
							//�ǉ������ɍ��i��������j���w�肳��Ă�����
							if (select == "ElderButton") {
								//�V�K�ŌZ��A������֐����Ăяo��
								CellCtrl->ChainElderBrother("", "", parent);
							}
							else {
								//�Ώۂɒ��A������
								CellCtrl->ChainYoungBrother("", "", parent);
							}
						}
					}//�s��I�����Ă���ꍇ�͍s�̒����̎q����ǉ�����悤�ɂ���
					else {
							this->AddYoungColumn(i);
					}
				}
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*�T�v�F�\�̗񐔂�����o�����߂̊֐�
		�����Fcellchain^ colchain�F�J�E���g�Ώۂ̍\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada*/
		Int32 CountColumn(CellDataChain::cellchain^ colchain) {
			try {
				Int32 colcount = 0;			//�񐔂��J�E���g���邽�߂̕ϐ�
				//��v�f�̍\���̂𑖍����ė񐔂��J�E���g����
				for (; colchain != nullptr; colchain = colchain->next) {
					//�񐔃J�E���g���C���N�������g
					colcount++;
				}
				//�J�E���g�����񐔂�ԋp����
				return colcount;
			}
			//�J�E���g�Ώۂ̍\���̂�NULL���w�����Ƃ��̗�O��ߑ�
			catch (System::NullReferenceException^ e) {
				//�R���\�[���ɃG���[��`����
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
			//�v�Z���I�[�o�[���Q�������̗�O��ߑ�
			catch (System::OverflowException^ e) {
				//�R���\�[���ɃG���[��`����
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
		}

		/*�T�v�F�\�̗񐔂�����o�����߂̊֐�
		�����Fcellchain^ rowchain�F�J�E���g�Ώۂ̍\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada
		�X�V���F2017.10.2
		�X�V�ҁFK.Asada
		�X�V���e�F��O�����������Ă����̂Œǉ�*/
		Void CountRow(CellDataChain::cellchain^ rowchain) {
			try {
				Int32 column = 0;		//�񐔂��i�[���邽�߂̕ϐ�
				Int32 colcount = 0;		//�J�E���g�����񐔂��i�[���邽�߂̕ϐ�
				Int32 row = 0;			//�s�����i�[���邽�߂̕ϐ�
				//�s�̍Ō�܂ő������čs�����J�E���g����
				for (; rowchain != nullptr; rowchain = rowchain->next) {
					//�s�̐擪����̗v�f�Ȃ̂ŗ񐔃J�E���g���C���N�������g
					colcount++;
					//�q������΍ċA���ė񐔂̃J�E���g�Ɉڂ�
					if (rowchain->lower != nullptr) {
						//�񐔂��J�E���g����֐����Ăяo��
						colcount += this->CountColumn(rowchain->lower);
					}
					//�����܂ŃJ�E���g���Ă����񐔂������̗񐔂��傫�����
					if (colcount > column) {
						//�傫�������̗p����
						column = colcount;
					}
					//�񐔃J�E���g�����Z�b�g����
					colcount = 0;
					//�s�����C���N�������g
					row++;
				}
				//�s���������o�ɕۊǂ���
				this->Row = row;
				//�񐔂������o�ɕۊǂ���
				this->Column = column;
				return;
			}
			//�J�E���g�Ώۂ̍\���̂�NULL���w�����Ƃ��̗�O��ߑ�
			catch (System::NullReferenceException^ e) {
				//�R���\�[���ɃG���[��`����
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
			//�v�Z���I�[�o�[���Q�������̗�O��ߑ�
			catch (System::OverflowException^ e) {
				//�R���\�[���ɃG���[��`����
				Console::WriteLine(Constants->INPUT_ERROR_STRING, e);
			}
		}

		/*�T�v�F�ڍוҏW��ʂɏo�͂���\�摜�𐶐�����֐�
		�����FPictureBox^ pict�F���������\�摜���ڂ���s�N�`���{�b�N�X
		�߂�l�FPictureBox^ pict�F�K�v����ݒ肵���s�N�`���{�b�N�X
		�쐬���F2017.9.25
		�쐬�ҁFK.Asada*/
		PictureBox^ infoTableGenerate(CellDataChain::cellchain^ tableelem, PictureBox^ pict, Int32 parentcount) {
			//�\�̕`��Ɏ��s�������̗�O��ߑ�
			try {
				//�\���̂𑀍삷�邽�߂̃N���X���C���X�^���X������
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				//�`�悷��Ώۂ̍\���̂��擾���邽�߂̍\����
				CellDataChain::cellchain^ elem = gcnew CellDataChain::cellchain();
				//�`����s����̃r�b�g�}�b�v���쐬����
				Bitmap^ img = gcnew Bitmap(*this->RctWidth * parentcount, *this->RctHeight);
				//�`����s�����߂̃O���t�B�b�N�N���X���C���X�^���X��
				Graphics^ gr = Graphics::FromImage(img);
				//�e�L�[���Ȃ��Ȃ�܂ő�������
				for (int i = parentcount; i > 0; i--) {
					//�b���Ώۂ̃L�[�����i�[���ꂽ�\���̂��擾����
					elem = CellCtrl->GetParent(tableelem, i);
					//�`�悷��Z���̃v���p�e�B����͂���
					System::Drawing::Rectangle^ rct = gcnew System::Drawing::Rectangle(*this->RctWidth * (parentcount - i), 0, *this->RctWidth, *this->RctHeight);
					//�Z���̕`����s���֐����Ăяo��
					this->DrawFigure(*rct, gr, elem);
				}
				//�`����I�����r�b�g�}�b�v��ݒ肷��
				pict->Image = img;
				//�s�N�`���{�b�N�X��ԋp����
				return pict;
			}
			//�`��Ώۂ�Image�����������������̗�O��ߑ�
			catch (System::FormatException^ e) {
				//�`��Ώۂ����݂��Ă��Ȃ����Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->DRAW_ERROR_STRING + e);
			}
			//�`�悷��Z���i�����`�̑傫���j�̌v�Z�ŕs���l���o���Ƃ��̗�O��ߑ�
			catch (System::OverflowException^ e) {
				//�Z���̑傫����񂪕s���ł��邱�Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->RECT_ERROR_STRING + e);
			}
		}

		/*�T�v�F�擾�����f�[�^���\�摜�̃Z��������`�悷��֐�
		�����FRectangle^ rct�F�`�悷��Z���̑傫���ƍ��W���
			�FGraphics^ gr�F�`��Ώۂ̃O���t�B�b�N�N���X
			�Fcellchain^ elem�F�`�悵���Z���̒��ɕ\�����镶���񂪊i�[���ꂽ�\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.27
		�쐬�ҁFK.Asada
		�X�V���F2017.10.2
		�X�V�ҁFK.Asada
		�X�V���e�F�L�[������̎��͔z��ł��邱�Ƃ��킩��₷�����邽�߂ɕ`�悷����e��ύX*/
		Void DrawFigure(System::Drawing::Rectangle^ rct, Graphics^ gr, CellDataChain::cellchain^ elem) {
			//�`�掞�̃G���[��ߑ�
			try {
				//�`�悷�镶����̃t�H���g��錾
				System::Drawing::Font^ myFont = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold);
				//�`��Ώۂ̍\���̂��I�u�W�F�N�g�ł������Ƃ��ɐF�t�����s�����߂̃u���V��錾
				Brush^ br = gcnew SolidBrush(Color::FromArgb(100, Color::Blue));
				//�Z���̊O�g��`�悷��
				gr->DrawRectangle(Pens::Black, *rct);
				//�Ώۂ̍\���̂Ɏq�����݂��Ă���ꍇ�̓I�u�W�F�N�g�Ƃ��Ĉ���
				if (elem != nullptr && elem->lower != nullptr) {
					//�I�u�W�F�N�g�ł��邱�Ƃ𖾎����邽�߂ɐF�t�����s��
					gr->FillRectangle(br, *rct);
					//�L�[�����󕶎��ł���Ƃ��͔z��ƂȂ�|��\������
					if (elem->key == "") {
						gr->DrawString(Constants->ARRAY_STRING, myFont, Brushes::Black, *rct);
					}
					else {
						//�I�u�W�F�N�g�̏ꍇ�̓L�[����`�悷��
						gr->DrawString(elem->key, myFont, Brushes::Black, *rct);
					}
				}//�q�����Ȃ��\���̂ł���ꍇ�̓f�[�^�Ƃ��Ĉ���
				else if (elem != nullptr) {
					//�f�[�^�̏ꍇ�͒l��`�悷��
					gr->DrawString(elem->value, myFont, Brushes::Black, *rct);
				}//�\���̂��擾���Ă��Ȃ������Ƃ��͉����`�悵�Ȃ�
				return;
			}
			//�`��Ώۂ��s���̎��ɗ�O��ߑ�
			catch (System::FormatException^ e) {
				//�`��Ώۂ����݂��Ă��Ȃ����Ƃ��R���\�[���ɏo��
				Console::WriteLine(Constants->IMAGE_ERROR_STRING + Constants->DRAW_ERROR_STRING + e);
			}
		}

		/*�T�v�F�Ώۂ̃Z�����Ⴂ�����i�e�܂��͌Z�j�ɍ\���̂�V�K�ŘA������֐�
		�����FInt32 rowindex�F�ǉ��Ώۂ̃Z��
		�߂�l�F�Ȃ�
		�쐬���F2017.9.28
		�쐬�ҁFK.Asada*/
		Void AddYoungColumn(Int32 rowindex) {
			try {
				//�\���̑���N���X���C���X�^���X��
				CellDataChain^ CellCtrl = gcnew CellDataChain();
				CellDataChain::cellchain^ parent = nullptr;		//�ΏۂƂȂ�\���̂��i�[���邽�߂̍\����
				//�ΏۂƂȂ�\���̂��擾����
				parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
				//�Ώۂ̍\���̂Ɏq�������
				if (parent->lower != nullptr) {
					//�Ώۂ̌Z�Ƃ��ĐV�K�ō\���̂�A������
					CellCtrl->ChainElderBrother("", "", parent->lower);
				}//�q�����Ȃ��ꍇ�͎q��A������
				else {
					//�V�K�Ŏq��A������
					CellCtrl->ChainChild("", "", parent);
				}
				return;
			}
			catch (System::NullReferenceException^ e) {
				System::Console::WriteLine(e);
			}
			catch (System::ArgumentNullException^ e) {
				System::Console::WriteLine(e);
			}
		}

		/*�T�v�F�w�肵���s�̍\���̂��폜����֐�
		�����FInt32 rowindex�F�폜�Ώۂ̍s���W
		�߂�l�F�Ȃ�
		�쐬���F2017.9.29
		�쐬�ҁFK.Asada*/
		Void RowDelete(Int32 rowindex) {
			CellDataChain::cellchain^ parent = nullptr;			//�Ώۂ̍\���̂��i�[���邽�߂̋�̍\����
			CellDataChain^ CellCtrl = gcnew CellDataChain();	//�\���̂𑀍삷��N���X���C���X�^���X��
			//�Ώۂ̍\���̂��擾����
			parent = CellCtrl->GetRowChain(rowindex, this->TableElem->lower);
			//�Ώۂ̍\���̂��폜����
			CellCtrl->DeleteChain(parent);
			*this->Row -= 1;
			return;
		}

		/*�T�v�F�w�肵����̍\���̂��폜����֐�
		�����FInt32 row�F�\�̍s���A
			�FInt32 columnindex�F�Ώۂ̗���W
		�߂�l�F�Ȃ�
		�쐬���F2017.9.29
		�쐬�ҁFK.Asada*/
		Void ColumnDelete(Int32 row, Int32 columnindex) {
			CellDataChain::cellchain^ parent = nullptr;		//�폜�Ώۂ̍\���̂��i�[���邽�߂̋�̍\����
			CellDataChain^ CellCtrl = gcnew CellDataChain();//�\���̂𑀍삷��N���X���C���X�^���X��
			//�Ώۂ����ׂč폜����܂ő�������
			for (int i = 0; i < row; i++) {
				//�폜�Ώۂ��擾����
				parent = CellCtrl->GetColumnChain(i, columnindex, this->TableElem->lower);
				//�Ώۂ��擾�ł�����
				if (parent != nullptr) {
					//�Ώۂ��擾�ł����ꍇ�͍폜����
					CellCtrl->DeleteChain(parent);
				}
			}
			return;
		}
	};
}