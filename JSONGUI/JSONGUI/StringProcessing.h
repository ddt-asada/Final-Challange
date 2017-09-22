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
	using namespace std;
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
		CellDataChain::cellchain^ Tablechain = gcnew CellDataChain::cellchain();	//JSON�𕶎���ɕϊ����Đe�q�A�Z��֌W�̃f�[�^�`�F�C�����s�����߂̍\����
//		List<int>^ joinInfo = gcnew List<int>();	//��������ێ����铮�I�z��
		
		/*�T�v�FJSON��\�ɕK�v�ȕ�����ɕϊ�����֐�
		�����Fstring json�F�t�@�C������ǂݍ���JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void TableString(string json) {
			ptree pt;						//�c���[�\���ɂ���JSON���i�[���邽�߂̃c���[
			stringstream ss;
			ss << json;
			//JSON���������鏀���Ƃ��Ď擾����JSON��������c���[�\���ɂ���
			read_json(ss, pt);
			//�擾����JSON��������`�F�C���\��������֐����Ăяo��
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*�T�v�F�ӏ������^��JSON���`�F�C���\���ɕϊ�����֐�
		�����Fstring json�F�t�@�C�����擾����JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void ListString(string json) {
			ptree pt;						//�c���[�\���ɂ���JSON���i�[���邽�߂̃c���[
			//JSON���������鏀���Ƃ��Ď擾����JSON��������c���[�\���ɂ���
			read_json(json, pt);
			//�擾����JSON��������`�F�C���\��������֐����Ăяo��
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*�T�v�FDB����󂯎����JSON���`�F�C���\���ɕϊ�����֐�
		�����Fstring json�FDB����擾����JSON������
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		Void DBString(string dbresult) {
			ptree pt;		//JSON���i�[���邽�߂̃c���[��錾
			//DB���擾����JSON�������JSON�c���[�ɕϊ�
			read_json(dbresult, pt);
			//JSON���`�F�C���\���ɕϊ�����֐����Ăяo��
			this->Tablechain = this->JSONString(pt, "", nullptr);
		}

		/*�T�v�F�����񂩂�JSON�ւ̕ϊ����s���֐�
		�����Fstring key�F�ċA����Ƃ��̐e�̃L�[��
			�Fcellchain^ json�F�l���擾���邽�߂̐e�̍\����
		�߂�l�Fptree�F�����񂩂�쐬����JSON�c���[
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		ptree ConvertJSON(std::string key, CellDataChain::cellchain^ json) {
			ptree parent;	//�q�v�f��A�����邽�߂̐e�c���[
			ptree child;	//�e�c���[�ɘA������q�c���[
			string parentkey;		//�e�L�[���i�[���邽�߂̕�����
			//��Ɍ������đ�������
			for (; json->next != nullptr; json = json->next) {
				//�e�L�[��ۊǂ���
				this->MarshalString(json->key,parentkey);
				//�q������΍ċA���Ďq�ɐ����Ă���
				if (json->lower != nullptr) {
					//�ċA�������ċA���Ă����q�c���[���擾����
					child = ConvertJSON(parentkey, json);
				}//�q�����Ȃ��ꍇ�͐e�L�[�ƒl���Z�b�g�ɂ��ăc���[�ɒǉ�
				else {
					string value;
					MarshalString(json->value, value);
					//�e�L�[�ƒl���Z�b�g�ɂ��Ďq�c���[�Ɋi�[
					child.add(parentkey, value);
				}
				//�e�L�[�Ǝq�c���[��A������
				parent.add_child(parentkey, child);
			}
			//�쐬����JSON�c���[��ԋp����
			return parent;
		}

		/*�T�v�FJSON���`�F�C���\��������ɕϊ�����֐�
		�����Fptree pt�FJSON���c���[�\���ɂ�������
			�Fstring key�F�e�L�[
			�Fcellchain^ parent�F�e�̍\����
		�߂�l�F�Ȃ�
		�쐬���v2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ JSONString(ptree pt, string key, CellDataChain::cellchain^ parent) {
			CellDataChain ChainCtrl;			//�f�[�^�`�F�C���N���X���C���X�^���X��
			string childkey = "";				//�q���̃L�[���i�[���邽�߂̕�����
			CellDataChain::cellchain^ brother = gcnew CellDataChain::cellchain();		//�Z���A�����邽�߂̍\����
			//���񃋁[�v���̏����i����̓L�[�����킩��Ȃ��A�\���̂����݂��Ă��Ȃ����߂ɍ��j
			if (key == "") {
				auto itr = pt.begin();		//�e�L�[���擾���邽�߂̃C�e���[�^�[��錾
				string key = itr->first;	//���񏈗��̎��̓L�[�������m�̂��߃C�e���[�^�[�ɂ�蓮�I�Ɋm��
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
				if (boost::optional<string>str = info.get_optional <string>(childkey)) {
					//�z��̗v�f���I�u�W�F�N�g�������̔z�񂩂ŏ����𕪊�
					if (info.begin() != info.end()) {
						//�z��I�u�W�F�N�g���\���̂Ƀ`�F�C������֐����Ăяo��
						brother = this->ArrayJSONobject(info, brother, childkey);
					}//�����̔z�񂾂����ꍇ
					else {
						//�z��̍\���̂Ƀ`�F�C������֐����Ăяo��
						brother = this->ArrayJSON(pt, brother, key);
						//�����̔z��̏ꍇ�͈��ŏ����ł���̂ŌZ��ւ̃��[�v�𔲂���
						break;
					}
				//�q���z��ȊO�ł����
				}
				else if (boost::optional<string>str = childtree.get <string>(childkey)) {
					//���̕����񂪂��̏ꍇ�͍ċA�����ɒ�Ƀf�[�^��A�����Ă���
					if (str.get() != "") {
						//�q�v�f�̃L�[�����o��
						childkey = child.first;
						//��Ƀf�[�^��A������֐����Ăяo��
						brother = ChainCtrl.ChainYoungBrother(gcnew String(childkey.c_str()), gcnew String(childtree.get <std::string>(childkey).c_str()), brother);
					} //�e�̏ꍇ�͒�Ƀf�[�^��A�����Ȃ���q�֍ċA���Ă���
					else {
						//��Ƀf�[�^��A������֐����Ăяo��
						brother = ChainCtrl.ChainYoungBrother(gcnew String(childkey.c_str()), gcnew String(childtree.get <std::string>(childkey).c_str()), brother);
						//�q�Ƀf�[�^��A�����邽�߂ɍċA�������s��
						brother->lower = this->JSONString(childtree, childkey, brother);
					}
				}
			}
			return %*ChainCtrl.FirstChain(brother);
		}


		

		/*�T�v�F�I�u�W�F�N�g�z��̕����񏈗����s���֐�
		�����Fcons ptree&�FJSON�̃c���[
			�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ ArrayJSONobject(const ptree& info, CellDataChain::cellchain^ brother,string key) {
			CellDataChain::cellchain^ arrayparent = gcnew CellDataChain::cellchain();	//�z��̗v�f��A�����邽�߂̍\���̂�錾
			CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
			//�����Ɏ󂯎�����\���̂̎q�Ƃ��Ĕz��v�f�̍\���̂�A������
			arrayparent = ChainCtrl.ChainChild(gcnew String(key.c_str()), "", brother);
			//�C�e���[�^�[�ɂ��z��̗v�f�𑖍����ĘA�����Ă�
			for (auto itr = info.begin(); itr != info.end(); itr++) {
				//��Ƃ��ĘA�����Ă���
				arrayparent = ChainCtrl.ChainYoungBrother(gcnew String(itr->first.c_str()), gcnew String(info.get<string>(itr->first).c_str()), arrayparent);
			}
			return brother;
		}

		/*�T�v�F�z��̕����񏈗����s���֐�
		�����Fptree�FJSON�̃c���[
			�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ ArrayJSON(ptree pt, CellDataChain::cellchain^ brother, string key) {
			CellDataChain ChainCtrl;				//�f�[�^�`�F�C���𑀍삷�邽�߂ɃN���X���C���X�^���X��
			//�z��𑀍삷��
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)){
				//�����̍\���̂̒�Ƃ��Ĕz��̗v�f��A�����Ă���
				brother = ChainCtrl.ChainYoungBrother("", gcnew String(child.first.c_str()), brother);
			}
			return brother;
		}

		/*�T�v�F�����񏈗��̏���Ɏ��s�����֐�
		�����Fptree�FJSON�̃c���[
		�߂�l�FCellDataChain::cellchain^�FJSON���`�F�C�������\����
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		CellDataChain::cellchain^ MakeParent(ptree pt) {
			auto itr = pt.begin();		//�e�L�[���擾���邽�߂̃C�e���[�^�[��錾
			string key = itr->first;	//���񏈗��̎��̓L�[�������m�̂��߃C�e���[�^�[�ɂ�蓮�I�Ɋm��
			CellDataChain::cellchain^ parent = gcnew CellDataChain::cellchain();		//�ŏ�ʂ̐e�̍\���̂��쐬
			parent->key = gcnew String(key.c_str());								//�L�[����ݒ�
			parent->value = gcnew String((pt.get<std::string>(key)).c_str());		//�c���[�\���ɂ���JSON�̍ŏ�ʂ���e�L�[�ɑΉ������l���擾
			//�쐬�����\���̂�Ԃ�
			return parent;
		}

		/*�T�v�F�s���Ɨ񐔂��J�E���g����֐�
		�����FCellDataChain::cellchain^�F�J�E���g�Ώۂ̍\����
			�Fint�F�ċA�����̍ۂɗ��p����ϐ�
		�߂�l�F�Ȃ�
		�쐬���F2017.9.21
		�쐬�ҁFK.Asada*/
		int CountCell(CellDataChain::cellchain^ target, int retcount) {
			CellDataChain::cellchain^ scan = gcnew CellDataChain::cellchain();		//�����p�̍\���̂�錾
			//������ɑ��삷��
			for (scan = target; scan->next != nullptr; scan = scan->next) {
				//�\�ɕ\�����ׂ��v�f�i�e�L�[�ȊO�j�������
				if (scan->value != "") {
					//�s�J�E���g���C���N�������g
					*this->rowcount = 1;
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
					*this->row += *this->rowcount;
					//�����o�̗񐔂Ɣ�r���傫�������̗p
					if (*this->column < *this->colcount) {
						//�傫�������̗p����
						*this->column = *this->colcount;
						//�ċA�񐔂����Z�b�g����
						retcount = -1;
						//�񐔃J�E���g�����Z�b�g����
						this->colcount = 0;
					}
					this->rowcount = 0;
				}
				//�K�w�J�E���g���C���N�������g���Ȃ���߂�
				return ++retcount;
			}
		}

		/*String^�^��string�^�֕ϊ�����֐�
		�����FString^ sys_string�F�ϊ��Ώۂ̕�����
		�Fstring& std_string�F�ϊ���̕�����̊i�[��
		�߂�l�F�Ȃ�
		�쐬���F2017.9.22
		�쐬�ҁFK.Asada
		*/
		void MarshalString(String^ sys_string, std::string& std_string) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
			std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	};
}