#pragma once

#include "CellDataChain.h"	//����̃f�[�^�`�F�C���N���X�̃w�b�_
#include "StringProcessing.h"	//�����񏈗��N���X�̃w�b�_

//���������֌W�̖��O���
namespace process {

	/*�T�v�F���������̓�����ƂȂ�N���X
	�쐬���F2017.9.21
	�쐬�ҁFK.Asada*/
	public ref class Processing : public StringProcessing{
	public:
		//�f�t�H���g�R���X�g���N�^
		Processing() {
		}

		/*�T�v�FJSON��ǂݍ���ŕ\�ɂ��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void Tablerun(String^ path) {
			//�����񏈗��֐����Ăяo��
			this->TableString(path);

		}

		/*�T�v�FJSON��ǂݍ���ŉӏ������̕\���o�͂��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void Listrun(String^ path) {
		}

		/*�T�v�FDB����JSON��ǂݍ���ŕ\���o�͂��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����FString^�FJSON���擾���邽�߂�DB�ɓ�����N�G��
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void DBrun(String^ query) {

		}

		/*�T�v�F�����񂩂�JSON�ւ̕ϊ����s��������ƂȂ�֐�
		�����FString^�FJSON�ɕϊ�������������
			�Fcellchain*�F�\����擾����������̃f�[�^�`�F�C��
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void Convertrun(String^ stringJSON, CellDataChain::cellchain* table) {
			
		}

		/*�T�v�F�t�@�C�����當������擾���邽�߂̊֐�
		�����FString^�F�ǂݍ��ݐ�̃t�@�C���p�X
		�߂�l�FString^�G�ǂݍ��񂾕�����
		�쐬���F207.9.21
		�쐬�ҁFK.Asada*/
		String^ LoadJSON(String^ path) {
			return path;
		}
	};
}