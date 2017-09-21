#pragma once

#include "CellDataChain.h"	//����f�[�^�`�F�C���N���X
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

namespace process {

	using namespace System;

	/*�T�v�F������֌W�̏������s���֐�
	�쐬���F2017.9.21
	�쐬�ҁFK.Asada*/
	public ref class StringProcessing {
	public:
		//�f�t�H���g�R���X�g���N�^
		StringProcessing() {

		}

		Int32^ row = 0;			//�\�̍s��
		Int32^ column = 0;		//�\�̗�
		Int32^ colcount = 0;	//�񐔂��J�E���g����ϐ�
		Int32^ rowcount = 0;	//�s�����J�E���g����ϐ�
		CellDataChain::cellchain* Tablechain;	//JSON�𕶎���ɕϊ����Đe�q�A�Z��֌W�̃f�[�^�`�F�C�����s�����߂̍\����
		
		/*�T�v�FJSON��\�ɕK�v�ȕ�����ɕϊ�����֐�
		�����FString^�FDB����擾����JSON�܂��̓t�@�C������JSON��ǂݍ��ނ��߂̃t�@�C���p�X
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void TableString(String^ json) {

		}

		/*�T�v�F�t�@�C�����當������擾���邽�߂̊֐�
		�����FString^�F�ǂݍ��ݐ�̃t�@�C���p�X
		�߂�l�FString^�G�ǂݍ��񂾕�����
		�쐬���F207.9.21
		�쐬�ҁFK.Asada*/
		String^ LoadJSON(String^ path) {

		}

		/*�T�v�FJSON���`�F�C���\��������ɕϊ�����֐�
		�����Fptree�FJSON���c���[�\���ɂ�������
			�Fstring�F�L�[��
		�߂�l�F�Ȃ�
		�쐬���v2017.9.21
		�쐬�ҁFK.Asada*/
		Void JSONString(boost::property_tree::ptree pt, std::string key) {

		}

		/*�T�v�F�񐔂��J�E���g����֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void CountColumn() {

		}

		/*�T�v�F�s�����J�E���g����֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void CountRow() {

		}

		/*�T�v�F�������JSON�ɕϊ�����֐�
		�����F�Ȃ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void StringtoJSON() {

		}

		/*�T�v�F�ӏ������^��JSON���`�F�C���\���ɕϊ�����֐�
		�����FString^�F�ǂݍ��ݐ�̃t�@�C���p�X
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void ListString(String^ path) {

		}

		/*�T�v�FDB����󂯎����JSON���`�F�C���\���ɕϊ�����֐�
		�����FString^�FDB����擾����JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void DBString(String^ dbresult) {

		}

		/*�T�v�F�I�u�W�F�N�g�z��̕����񏈗����s���֐�
		�����Fcons ptree&�FJSON�̃c���[
			�FCellDataChain::cellchain*�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain* ArrayJSONocject(const boost::property_tree::ptree& info, CellDataChain::cellchain* brother) {
			
		}

		/*�T�v�F�z��̕����񏈗����s���֐�
		�����Fptree�FJSON�̃c���[
			�FCellDataChain::cellchain*�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain* ArrayJSON(boost::property_tree::ptree pt, CellDataChain::cellchain* brother) {

		}

		/*�T�v�F�����񏈗��̏���Ɏ��s�����֐�
		�����Fptree�FJSON�̃c���[
		�߂�l�FCellDataChain::cellchain*�FJSON���`�F�C�������\����
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain* MakeParent(boost::property_tree::ptree pt) {
			
		}

		/*�T�v�F�s���Ɨ񐔂��J�E���g����֐�
		�����FCellDataChain::cellchain*�F�J�E���g�Ώۂ̍\����
			�Fint�F�ċA�����̍ۂɗ��p����ϐ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void CountCell(CellDataChain::cellchain* target, int tmp) {

		}

	};
}