#pragma once
#include "ConstantString.h"		//����萔�N���X�̃w�b�_
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
		}

	//	ConstantString^ Constants = gcnew ConstantString();		//�萔�N���X�̃C���X�^���X��
		Int32^ Row = Constants->ZERO;			//�\�̍s��
		Int32^ Column = Constants->ZERO;		//�\�̗�
		Int32^ RowIndex = Constants->ZERO;		//�N���b�N���ꂽ�\�̃^�e���W
		Int32^ ColumnIndex = Constants->ZERO;	//�N���b�N���ꂽ�\�̃��R���W
		Int32^ RctWidth = 200;					//�\�̊i�q�������̕�
		Int32^ RctHeight = 100;					//�\�̊i�q�������̍���
	//	List<Int32>^ = gcnew List<Int32>();		//�Z���̌�������ێ����郊�X�g�^�z��
		//cellchain* TableElem = NULL;			//�\�̏�񂪊i�[���ꂽ�f�[�^�`�F�C��
		String^ JSONFilePath = Constants->EMPTY_STRING;		//�ǂݍ���JSON�̃t�@�C���p�X
		String^ DBQuery = Constants->EMPTY_STRING;			//DB���JSON��������擾���邽�߂̃N�G��
	};
}