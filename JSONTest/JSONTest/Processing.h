#pragma once

#include "CONSTANTSTRING.h"//�萔�N���X���������߂̃C���N���[�h
#include "StringProcess.h"//�����񏈗��N���X�̃C���N���[�h

/*�쐬���F2017.9.2
�@���͂��ꂽ������������N���X
 �@�쐬�ҁFK.Asada
  */

namespace process {
	using namespace System;

	ref class Processing : public StringProcess{
	private:
		//�萔�N���X���C���X�^���X��
		constantstring::CONSTANTSTRING^ CONST = gcnew constantstring::CONSTANTSTRING();
		String^ LoadFilePath = CONST->EMPTY_STRING;	//JSON�t�@�C����ǂݍ��ސ�̃t�@�C���p�X���i�[���镶����B
		String^ SendQuery = CONST->EMPTY_STRING;	//DB�֓�����N�G�����i�[���镶����B
		String^ DbJson = CONST->EMPTY_STRING;		//DB���擾������������i�[���镶����B
		Int32^ Row = CONST->ZERO;					//�\�̍s�����i�[����ϐ�
		Int32^ Column = CONST->ZERO;				//�\�̗񐔂��i�[����ϐ�

	public:
		//�f�t�H���g�R���X�g���N�^
		Processing() {
			
		};
		//�󂯎��������ۊǂ���R���X�g���N�^�B
		Processing(String^ Path, String^ Query) :LoadFilePath(CONST->EMPTY_STRING), SendQuery(CONST->EMPTY_STRING) {
			this->LoadFilePath = Path;
			this->SendQuery = Query;
		};

		/*�󂯎���������\���o�͂��邽�߂̏���
		�@�쐬���F2017.9.2
		 �@�쐬�ҁFK.Asada
		  */
		Void run() {
			//�t�@�C���p�X���擾���Ă����
			if (this->LoadFilePath != CONST->EMPTY_STRING) {
				//JSON���\���o�͂��邽�߂ɕK�v�ȏ��𔲂��o���֐����Ăяo��
				StringProcess^ test = gcnew StringProcess();
				test->ReadyString(this->LoadFilePath);
				//JSON���擾�����s���ƃ����o�ϐ��̍s�����r����B
				if (*this->Row > *this->row) {
					//�傫�������̗p����B
					this->row = Row;
				}
				//JSON���擾�����񐔂ƃ����o�ϐ��̗񐔂��r����B
				if (*this->Column > *this->column) {
					//�傫�������̗p����
					this->column = Column;
				}
			}
			//�\���o�͂���֐����Ăяo���B

		}

	};
}