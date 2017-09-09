#pragma once

#include "CONSTANTSTRING.h"//�萔�N���X���������߂̃C���N���[�h
#include "StringProcess.h"//�����񏈗��N���X�̃C���N���[�h
#include "TableProcessing.h"
#include "JSONForm.h"

/*�쐬���F2017.9.2
�@���͂��ꂽ������������N���X
 �@�쐬�ҁFK.Asada
  */

namespace process {
	using namespace System;
	using namespace System::Windows::Forms;

	ref class Processing : public StringProcess{
	public:
		//�萔�N���X���C���X�^���X��
		constantstring::CONSTANTSTRING^ MyConst = gcnew constantstring::CONSTANTSTRING();
		String^ LoadFilePath = MyConst->EMPTY_STRING;	//JSON�t�@�C����ǂݍ��ސ�̃t�@�C���p�X���i�[���镶����B
		String^ SendQuery = MyConst->EMPTY_STRING;	//DB�֓�����N�G�����i�[���镶����B
		String^ DbJson = MyConst->EMPTY_STRING;		//DB���擾������������i�[���镶����B
		Int32^ Row = *MyConst->ZERO;					//�\�̍s�����i�[����ϐ�
		Int32^ Column = *MyConst->ZERO;				//�\�̗񐔂��i�[����ϐ�
		vector<pair<string, string>> *rettable = new vector<pair<string, string>>();
		vector<pair<pair<string, string>, string>>* jsontable = new vector<pair<pair<string, string>, string>>();

	public:
		//�f�t�H���g�R���X�g���N�^
		Processing() {
			
		};
		//�󂯎��������ۊǂ���R���X�g���N�^�B
		Processing(String^ Path, String^ Query) :LoadFilePath(MyConst->EMPTY_STRING), SendQuery(MyConst->EMPTY_STRING) {
			this->LoadFilePath = Path;
			this->SendQuery = Query;
		};

		/*�󂯎���������\���o�͂��邽�߂̏���
		�@�쐬���F2017.9.2
		 �@�쐬�ҁFK.Asada
		  */
		Void run() {
			//�t�@�C���p�X���擾���Ă����
			if (this->LoadFilePath != MyConst->EMPTY_STRING) {
				//JSON���\���o�͂��邽�߂ɕK�v�ȏ��𔲂��o���֐����Ăяo��
				StringProcess^ test = gcnew StringProcess();
				this->rettable = test->ReadyString(this->LoadFilePath);
				//JSON���擾�����s���ƃ����o�ϐ��̍s�����r����B
				if (*this->Row < *test->row) {
					//�傫�������̗p����B
					this->Row = test->row;
				}
				//JSON���擾�����񐔂ƃ����o�ϐ��̗񐔂��r����B
				if (*this->Column < *test->column) {
					//�傫�������̗p����
					this->Column = test->column;
				}
			}
			//�\���o�͂���֐����Ăяo���B
		}

		/*�󂯎���������JSON���o�͂��邽�߂̏���
		�쐬���F2017.9.7
		�쐬�ҁFK.Asada
		*/
		Void change() {
			//�󂯎�����e�[�u�����JSON�ɕϊ�����֐����Ăяo���B
		}


		/*
		Void ConversionTable(vector<pair<string, string>> tmptable) {
			auto itr = tmptable.begin();
			for (auto itr = tmptable.begin(); itr != tmptable.end(); itr++) {
				string test = itr->first;
				string test2 = itr->second;
				this->rettable->push_back(pair<String^, String^>(gcnew String (test.c_str()), gcnew String(test2.c_str())));
			}
		}*/
		
	};
}