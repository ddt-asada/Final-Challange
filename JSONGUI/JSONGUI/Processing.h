#pragma once

#include "CellDataChain.h"	//����̃f�[�^�`�F�C���N���X�̃w�b�_

//���������֌W�̖��O���
namespace process {

	using namespace System;
	/*�T�v�F���������̓�����ƂȂ�N���X
	�쐬���F2017.9.21
	�쐬�ҁFK.Asada*/
	public ref class Processing {
	public:
		//�f�t�H���g�R���X�g���N�^
		Processing() {
		}

		//�t�@�C����ǂݍ���ŏ������邽�߂̃R���X�g���N�^
		Processing(System::String^ path) {

		}

		/*�T�v�FJSON��ǂݍ���ŕ\�ɂ��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void Tablerun() {
		}

		/*�T�v�FJSON��ǂݍ���ŉӏ������̕\���o�͂��邽�߂̕����񏈗����s��������ƂȂ�֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void Listrun() {
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

	};
}