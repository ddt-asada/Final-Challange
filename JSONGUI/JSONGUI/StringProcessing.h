#pragma once

#include "CellDataChain.h"	//����f�[�^�`�F�C���N���X
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <string>

namespace process {

	using namespace System;
	using namespace boost::property_tree;

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
		CellDataChain::cellchain* Tablechain = nullptr;	//JSON�𕶎���ɕϊ����Đe�q�A�Z��֌W�̃f�[�^�`�F�C�����s�����߂̍\����
		List<int>^ joinInfo = gcnew List<int>();	//��������ێ����铮�I�z��
		
		/*�T�v�FJSON��\�ɕK�v�ȕ�����ɕϊ�����֐�
		�����FString^�FDB����擾����JSON�܂��̓t�@�C������JSON��ǂݍ��ނ��߂̃t�@�C���p�X
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void TableString(String^ jsonpath) {
			std::stringstream JSON;			//�ǂݍ���JSON���i�[���邽�߂̕�����X�g���[��
			ptree pt;						//�c���[�\���ɂ���JSON���i�[���邽�߂̃c���[
			//�ݒ��ʂ��󂯎�����t�@�C���p�X��蕶�����ǂݍ���
			std::ifstream ifs(jsonpath, ios_base::binary);
			//�������ǂݍ���
			JSON << ifs.rdbuf();
			//JSON���������鏀���Ƃ��Ď擾����JSON��������c���[�\���ɂ���
			read_json(JSON, pt);
			//�擾����JSON��������`�F�C���\��������֐����Ăяo��
			JSONString(pt, "", nullptr);
		}

		/*�T�v�FJSON���`�F�C���\��������ɕϊ�����֐�
		�����Fptree�FJSON���c���[�\���ɂ�������
			�Fstring�F�L�[��
		�߂�l�F�Ȃ�
		�쐬���v2017.9.21
		�쐬�ҁFK.Asada*/
		Void JSONString(boost::property_tree::ptree pt, std::string key, CellDataChain::cellchain* parent) {
			CellDataChain ChainCtrl;							//�f�[�^�`�F�C���N���X���C���X�^���X��
			std::string childkey = "";							//�q���̃L�[���i�[���邽�߂̕�����
			CellDataChain::cellchain* brother = nullptr;		//�Z���A�����邽�߂̍\����
			//���񃋁[�v���̏����i����̓L�[�����킩��Ȃ��A�\���̂����݂��Ă��Ȃ����߂ɍ��j
			if (key == "") {
				//�ŏ�ʂ̐e�̍\���̂��쐬����
				brother = MakeParent(pt);
			}
			//JSON�c���[�̌Z��ɂ��đ�������
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
				//�z�񂩂ǂ����̔�����s�����ߎq�c���[���擾
				const ptree& info = child.second;
				//�����񂩂ǂ����̔�����s�����߂Ɏq�c���[���擾
				ptree childtree = pt.get_child(key);
				//�q�̃L�[�����擾����
				childkey = child.first;
				//�q�̃I�u�W�F�N�g���z�񂩂ǂ����̔�����s��
				if (boost::optional<std::string>str = info.get_optional <std::string>(childkey)) {
					//�z��̗v�f���I�u�W�F�N�g�������̔z�񂩂ŏ����𕪊�
					if (info.begin() != info.end()) {
						//�z��I�u�W�F�N�g���\���̂Ƀ`�F�C������֐����Ăяo��
						brother = this->ArrayJSONocject(info, brother);
					}//�����̔z�񂾂����ꍇ
					else {
						//�z��̍\���̂Ƀ`�F�C������֐����Ăяo��
						brother = this->ArrayJSON(pt, key, brother);
						//�����̔z��̏ꍇ�͈��ŏ����ł���̂ŌZ��ւ̃��[�v�𔲂���
						break;
					}
				//�q���z��ȊO�ł����
				}
				else if (boost::optional<std::string>str = childtree.get <std::string>(childkey)) {
					//���̕����񂪂��̏ꍇ�͍ċA�����ɒ�Ƀf�[�^��A�����Ă���
					if (str.get() != "") {
						//��Ƀf�[�^��A������֐����Ăяo��
						brother = ChainCtrl.ChainYoungBrother(childkey, childtree.get <std::string>(childkey), brother, nullptr);
					} //�e�̏ꍇ�͒�Ƀf�[�^��A�����Ȃ���q�֍ċA���Ă���
					else {
						//��Ƀf�[�^��A������֐����Ăяo��
						brother = ChainCtrl.ChainYoungBrother(childkey, childtree.get <std::string>(childkey), brother, nullptr);
						//�q�Ƀf�[�^��A�����邽�߂ɍċA�������s��
						this->JSONString(childtree, childkey, brother);
					}
				}
			}
		}

		/*�T�v�F�����񂩂�JSON�ւ̕ϊ����s���֐�
		�����Fstring�F�ċA����Ƃ��̐e�̃L�[��
			�Fjson�F�����񂩂�JSON�֕ϊ����邽�߂�JSON�̃c���[
		�߂�l�Fptree�F�����񂩂�쐬����JSON�c���[
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		ptree ConvertJSON(std::string key, ptree json) {
			ptree parent;	//�q�v�f��A�����邽�߂̐e�c���[
			ptree child;	//�e�c���[�ɘA������q�c���[
			CellDataChain::cellchain* parentchain;	//�������邽�߂̃`�F�C���\����
			std::string parentkey;		//�e�L�[���i�[���邽�߂̕�����
			//��Ɍ������đ�������
			for (parentchain = this->Tablechain; parentchain->next != nullptr; parentchain = parentchain->next) {
				//�e�L�[��ۊǂ���
				parentkey = parentchain->key;
				//�q������΍ċA���Ďq�ɐ����Ă���
				if (parentchain->lower != nullptr) {
					//�ċA�������ċA���Ă����q�c���[���擾����
					child = ConvertJSON(parentkey, parentchain);
					//�e�L�[�Ǝq�c���[��A������
					parent.add_child(parentkey, child);
				}//�q�����Ȃ��ꍇ�͐e�L�[�ƒl���Z�b�g�ɂ��ăc���[�ɒǉ�
				else {
					//�e�L�[�ƒl���Z�b�g�ɂ��Ďq�c���[�Ɋi�[
					child.add((parentkey + "." + parentchain->key), parentchain->value);
				}
			}
			//�쐬����JSON�c���[��ԋp����
			return child;
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
			ptree pt;		//JSON���i�[���邽�߂̃c���[��錾
			//DB���擾����JSON�������JSON�c���[�ɕϊ�
			read_json(dbresult, pt);
			//JSON���`�F�C���\���ɕϊ�����֐����Ăяo��
			this->JSONString(pt, "", nullptr);
		}

		/*�T�v�F�I�u�W�F�N�g�z��̕����񏈗����s���֐�
		�����Fcons ptree&�FJSON�̃c���[
			�FCellDataChain::cellchain*�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain* ArrayJSONocject(const boost::property_tree::ptree& info, CellDataChain::cellchain* brother) {
			CellDataChain::cellchain* arrayparent;	//�z��̗v�f��A�����邽�߂̍\���̂�錾
			CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
			//�����Ɏ󂯎�����\���̂̎q�Ƃ��Ĕz��v�f�̍\���̂�A������
			arrayparent = ChainCtrl.ChainChild(key, "", brother, nullptr);
			//�C�e���[�^�[�ɂ��z��̗v�f�𑖍����ĘA�����Ă�
			for (auto itr = info.begin; itr != info.end; itr++) {
				//��Ƃ��ĘA�����Ă���
				arrayparent = ChainCtrl.ChainYoungBrother(itr->first, itr->second, arrayparent, nullptr);
			}
			return brother;
		}

		/*�T�v�F�z��̕����񏈗����s���֐�
		�����Fptree�FJSON�̃c���[
			�FCellDataChain::cellchain*�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain* ArrayJSON(boost::property_tree::ptree pt, std::string key, ::cellchain* brother) {
			CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
			//�z��𑀍삷��
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)){
				//�����̍\���̂̒�Ƃ��Ĕz��̗v�f��A�����Ă���
				brother = ChainCtrl.ChainYoungBrother("", child.first, brother, nullptr);
			}
			return brother;
		}

		/*�T�v�F�����񏈗��̏���Ɏ��s�����֐�
		�����Fptree�FJSON�̃c���[
		�߂�l�FCellDataChain::cellchain*�FJSON���`�F�C�������\����
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain* MakeParent(boost::property_tree::ptree pt) {
			auto itr = pt.begin();		//�e�L�[���擾���邽�߂̃C�e���[�^�[��錾
			std::string key = itr->first;	//���񏈗��̎��̓L�[�������m�̂��߃C�e���[�^�[�ɂ�蓮�I�Ɋm��
			CellDataChain::cellchain* parent = nullptr;		//�ŏ�ʂ̐e�̍\���̂��쐬
			parent->key = key;								//�L�[����ݒ�
			parent->value = (pt.get<std::string>(key));		//�c���[�\���ɂ���JSON�̍ŏ�ʂ���e�L�[�ɑΉ������l���擾
			//�쐬�����\���̂�Ԃ�
			return parent;
		}

		/*�T�v�F�s���Ɨ񐔂��J�E���g����֐�
		�����FCellDataChain::cellchain*�F�J�E���g�Ώۂ̍\����
			�Fint�F�ċA�����̍ۂɗ��p����ϐ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		int CountCell(CellDataChain::cellchain* target, int retcount) {
			CellDataChain::cellchain* scan;		//�����p�̍\���̂�錾
			//������ɑ��삷��
			for (scan = target; scan = nullptr; scan = scan->next) {
				//�\�ɕ\�����ׂ��v�f�i�e�L�[�ȊO�j�������
				if (scan->value != "") {
					//�s�J�E���g���C���N�������g
					*this->rowcount += 1;
					//��J�E���g���C���N�������g
					*this->colcount += 1;
				}
				//�q������ꍇ�͍ċA�������Ă���
				if (scan->lower != nullptr) {
					//2��ڈȍ~�̍ċA�ł����
					if (retcount > 0) {
						//�ċA�����񐔂ɕ␳�������Ȃ���ċA
						CountCell(scan, retcount - 1);
					}
					else {
						//���̂܂܍ċA����
						CountCell(scan, retcount);
					}
				}
				//2�K�w�ȏ�オ�邩�ŏ�ʊK�w�܂Ŗ߂�����
				if (scan->upper == nullptr || retcount >= 2) {
					//�����o�̍s�����C���N�������g
					*this->row += 1;
					//�����o�̗񐔂Ɣ�r���傫�������̗p
					if (*this->column < *this->colcount) {
						//�傫�������̗p����
						this->column = this->colcount;
						//�ċA�񐔂����Z�b�g����
						retcount = -1;
						//�񐔃J�E���g�����Z�b�g����
						this->colcount = 0;
					}
				}
				//�K�w�J�E���g���C���N�������g���Ȃ���߂�
				return ++retcount;
			}
		}
	};
}