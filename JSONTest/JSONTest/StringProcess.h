#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <cliext/utility>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "CONSTANTSTRING.h"
#include "JSONDBManager.h"

namespace process {
	using namespace std;
	using namespace System;
	using namespace constantstring;
	using namespace System::Collections::Generic;
	using namespace boost::property_tree;

	//�쐬���F2017.9.2
	//�쐬�ҁFK.Asada
	//���������������֐��Q�N���X�B
	ref class StringProcess {
	public:
		//�萔�N���X���C���X�^���X��
		CONSTANTSTRING^ MyConst = gcnew CONSTANTSTRING();
		Int32^ column = *MyConst->ZERO;		//�\�̗�
		Int32^ row = *MyConst->ZERO;		//�\�̍s��
		Int32^ tmp = *MyConst->ZERO;
		int resetcount = 0;
		int colcount = 0;
		int testcount = 0;
		std::set<string> *countset = new std::set<string>;
		List<String^>^ join = gcnew List<String^>;
		List<cliext::pair<String^, String^>^>^ dic = gcnew List<cliext::pair<String^, String^>^>();
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ retPointTable = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();
		vector<pair<pair<string, string>, string>>* jsontable = new vector<pair<pair<string, string>, string>>();

			//�f�t�H���g�R���X�g���N�^
		StringProcess() {
		};

		//�t�@�C���p�X��蕶������擾���Ă��̕����񂩂�s���A�񐔁A������𔲂��o���B
		Void ReadyString(String^ JSONPath) {
			ptree pt;		//�t�@�C�����擾����JSON���i�[����c���[
		//	String^ SJSON = "";
			string JSON = "";
			string path = "";
			MarshalString(JSONPath, path);
			//�󂯎�����t�@�C���p�X��蕶������Ăяo���B
			stringstream ss;
			std::ifstream ifs(path, ios_base::binary);
			ss << ifs.rdbuf();

			//�擾������������JSON���擾����B
			read_json(ss, pt);

			//JSON����\�̏o�͂ɕK�v�ȕ�������Ăяo���B
			TableString(pt, "", "");
			//JSON����\�̍s��������o���֐����Ăяo���B
//			CountRows();
	//		this->tmp = *this->row;
			//JSON����\�̗񐔂�����o���֐����Ăяo���B
			this->row = Convert::ToInt32(this->countset->size());
	/*		CountColumn();

			this->row =  *this->row / *this->column;
			if (this->row < 0) {
				this->row = abs(*this->row);
			}
			//�^�C�g���̍s�����l�����ė񐔂�␳����B
//			this->column = *this->column / *this->row;*/
			//������Ԕ���p�̕����������������B
			for (int i = 0; i < this->row; i++) {
				this->join->Add("");
			}

			SetTablePoint();
		}

		/*�ӏ�������JSON��ǂݍ��ނ��߂̊֐�
		�쐬���F2017.9.12
		�쐬�ҁFK.Asada */
		//�t�@�C���p�X��蕶������擾���Ă��̕����񂩂�s���A�񐔁A������𔲂��o���B
		Void ReadyListString(String^ JSONPath) {
			ptree pt;		//�t�@�C�����擾����JSON���i�[����c���[
							//	String^ SJSON = "";
			string JSON = "";
			string path = "";
			MarshalString(JSONPath, path);
			//�󂯎�����t�@�C���p�X��蕶������Ăяo���B
			stringstream ss;
			std::ifstream ifs(path, ios_base::binary);
			ss << ifs.rdbuf();

			//�擾������������JSON���擾����B
			read_json(ss, pt);

			//JSON����\�̏o�͂ɕK�v�ȕ�������Ăяo���B
//			TableString(pt, "");
			//JSON����\�̍s��������o���֐����Ăяo���B
			CountRows();
			this->tmp = *this->row;
			//JSON����\�̗񐔂�����o���֐����Ăяo���B
			CountColumn();

			this->row = *this->column;
			//�^�C�g���̍s�����l�����ė񐔂�␳����B
			this->column = 1;

			for (int i = 0; i < this->row; i++) {
				this->join->Add("");
			}

			SetTablePoint();
		}

		/*DB�Ƃ̒ʐM���ʂ�\�ɂ��邽�߂ɕK�v�ȕ�������擾����֐�
		�쐬���F2017.9.14
		�쐬�ҁFK.Asada*/
		Void DBTable(string result) {
//	//		StringProcess^ test = gcnew StringProcess();
//		//	string result;			//�ʐM���ʂ��i�[���镶����
//		//	string tmp;
//	//		this->MarshalString(this->SendQuery, tmp);
//			JSONDBManager dbmana;
//			//DB�����ֈڍs����
////			result = dbmana.DBrun(tmp);*/
//			ptree pt;		//�t�@�C�����擾����JSON���i�[����c���[
//			string JSON = "";
//			JSON = dbmana.DBrun(result);
////			JSON = UTF8toSjis(JSON);
////			cout <<JSON << '\n';
//	//		JSON = SjistoUTF8(JSON);
//		//	cout << JSON << '\n';
//			//JSON = UTF8toSjis(JSON);
//			//cout <<JSON << '\n';
//
//			//�󂯎�����t�@�C���p�X��蕶������Ăяo���B
//			stringstream ss;
//			ss << JSON;
//
//			//�擾������������JSON���擾����B
//			read_json(ss, pt);
//
//			//JSON����\�̏o�͂ɕK�v�ȕ�������Ăяo���B
//			TableString(pt, "");
//			//JSON����\�̍s��������o���֐����Ăяo���B
//			//JSON����\�̗񐔂�����o���֐����Ăяo���B
//			CountColumn();
//
//			this->row = *this->row / *this->column;
//			if (this->row < 0) {
//				this->row = abs(*this->row);
//			}
//			//�^�C�g���̍s�����l�����ė񐔂�␳����B
//			//������Ԕ���p�̕����������������B
//			for (int i = 0; i < this->row; i++) {
//				this->join->Add("");
//			}
//
//			SetTablePoint();
		}

		/*�o�͂���\�̗񐔂�����o���֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada
		*/
		Void CountColumn() {
			//�C�e���[�^�[�ɂ�葖������B
			for (int i = 0; i < this->dic->Count; i++) {
				//�\�̗v�f����������񐔂��J�E���g
				if (this->dic[i]->first == "text" || this->dic[i]->first == "array" || this->dic[i]->first == "html") {
					*this->row += 1;
				}
				else if (this->dic[i]->first == "arraybegin") {
					i += 1;
					for (; i < this->dic->Count; i++) {
						if (this->dic[i]->first == "arrayend") {
							break;
						}
						*this->row += 1;
					}
				}
				//�����������L�[���������
				else if (this->dic[i]->first == "colspan") {
					//�����̍s�����v���X����
					*this->row += Convert::ToInt32(this->dic[i]->second) - 1;
				}
			}
		}

		/*�o�͂���\�̍s��������o�����߂̊֐�
		�쐬���F2017.9.4
		�쐬�ҁFK.Asada*/
		Void CountRows() {
			//�C�e���[�^�[�ɂ�葖������B
			for (int i = 0; i < this->dic->Count; i++) {
				//�e�̃m�[�h�܂��͎q���z��̎��ɗ񐔂��J�E���g
				if (this->dic[i]->second == "" || this->dic[i]->first == "html") {
					//�񐔂��C���N�������g
					*this->row += 1;
				}
				else if (this->dic[i]->first == "arraybegin") {
					i += 1;
					*this->row -= 1;
					for (; i < this->dic->Count; i++) {
						if (this->dic[i]->first == "arrayend") {
							break;
						}
						*this->row += 1;
					}
				}
				else if (this->dic[i]->first == "colspan") {
					//�����̍s�����v���X����
					*this->row += Convert::ToInt32(this->dic[i]->second) - 1;
				}
			}
		}

		/*�o�͂���\�ɕK�v�ȕ����񂨂�ї񐔂�����o�����߂̊֐�
		�쐬���F2017.9.4
		�쐬�ҁFK.Asada
		*/
		string TableString(ptree pt, string key, string tmp) {
			string strtest = key;
			string ret = tmp;
			string childkey = "";		//�ċA�����̎��ɕK�v�Ȏq�̃L�[�����i�[���镶����B
			//�L�[������̎��i���񃋁[�v���j
			if (key == "") {
				//�L�[�����擾���邽�߂̃C�e���[�^�[��錾�B
				auto itr = pt.begin();
				//�L�[�����C�e���[�^�[���擾�B
				key = itr->first;
			}
			//�q�ɕ����񂪂������ꍇ
			if (boost::optional<std::string> str = pt.get_optional<std::string>(key)) {
				//��������L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����B
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(key).c_str()), gcnew String(UTF8toSjis(str.get()).c_str())));
			}
			//�q�ɐ������������ꍇ
			else if (boost::optional<int> value = pt.get_optional<int>(key)) {
				//�L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����
				//this->table->push_back(pair<string, string>(UTF8toSjis(key), UTF8toSjis(to_string(value.get()))));
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(key).c_str()), gcnew String((UTF8toSjis(to_string(value.get()))).c_str())));
			}
			//�q���܂�����ꍇ
			if (pt.get_child_optional(key)) {
				//�q�̌Z��𑖍�����
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//������s�����߂�second���擾
					const ptree& info = child.second;
					ptree test = pt.get_child(key);
					//�q�̃L�[�����擾����
					childkey = child.first;
					//�q�v�f���z�񂩂����ł����
					if (boost::optional<int> value = info.get_optional<int>(childkey)) {
						//�L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����
				//		this->table->push_back(pair<string, string>(UTF8toSjis(childkey), UTF8toSjis(to_string(value.get()))));
						this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(to_string(value.get())).c_str())));
						//�q�v�f���z�񂩂�����ł����
					}
					else if (boost::optional<std::string> str = info.get_optional<std::string>(childkey)) {
						//��������r���֐��Ɉڍs����\��
						this->resetcount--;
						//�z��������������A������
						this->dic->Add(%cliext::pair<String^, String^>(gcnew String("arraybegin"), gcnew String("arraybegin")));
						//�L�[�ƒl�̗��������݂��Ă���Ƃ��̓C�e���[�^�[�ő���
						if (info.begin() != info.end()) {
							//�z��̒��g�𑖍�����
							for (auto itr = info.begin(); itr != info.end(); itr++) {
								//�L�[���ƒl���Z�b�g�ɂ��ă}�b�v�Ɋi�[����
								this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(itr->first).c_str()), gcnew String(UTF8toSjis(info.get<std::string>(itr->first)).c_str())));
								//�񐔂��J�E���g����
								this->testcount++;
							}
							if (this->testcount != 0) {
								//�񐔂��擾
								this->column = this->testcount;
								//�K�w�𔻒肷��ϐ������Z�b�g
								this->resetcount = 1;
								//�񐔂��J�E���g����ϐ������Z�b�g
								this->testcount = 0;
							}
							this->testcount = 0;
						}//�l�������݂��Ă��Ȃ��Ƃ��͏����t����for���ő���
						else {
							//�z��𑖍�����
							BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
								//��������L�[�����y�A�ɂ��ă}�b�v�Ɋi�[����B
								this->dic->Add(%cliext::pair<String^, String^>(gcnew String(""), gcnew String(UTF8toSjis(child.second.get<std::string>(childkey)).c_str())));
								//�񐔂��J�E���g����
								this->testcount++;
							}
							if (this->testcount != 0) {
								//�񐔂��擾
								this->column = this->testcount;
								//�K�w�𔻒肷��ϐ������Z�b�g
								this->resetcount = 1;
								//�񐔂��J�E���g����ϐ������Z�b�g
								this->testcount = 0;
							}
							this->testcount = 0;
						}
						//�z��̏I�[��������������i�[����
						this->dic->Add(%cliext::pair<String^, String^>(gcnew String("arrayend"), gcnew String("arrayend")));
						break;
					}
					//�q�̎q�i���j�����݂��Ă��炸�q�̃y�A�𕶎���Ƃ��Ď擾�ł����
					else if (boost::optional<std::string> str = (test.get_optional<std::string>(childkey))) {
						//����������֐��Ɉڍs����\��
						//�q�̃y�A���\�̗v�f�ƂȂ肤�镶����ł������ꍇ
						if (str.get() != "" && childkey == "text") {
							childkey = child.first;
							ret = childkey;
							//��������y�A�ɂ��ă}�b�v�Ɋi�[
							this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(test.get<std::string>(childkey)).c_str())));
							//�񐔂��J�E���g����
							this->testcount++;
						}
						//�\�̗v�f�ȊO�̕t�����ł������ꍇ
						else if (str.get() != "") {
							//��������y�A�ɂ��ă}�b�v�Ɋi�[
							ret = childkey;
							this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(test.get<std::string>(childkey)).c_str())));
						}
						//�q������ꍇ
						else {
							//���łɗ�̗v�f�����擾���Ă����ꍇ��r���s���A�傫�������̗p����B
							//�ċA�������s��			
							ret = TableString(pt.get_child(key), childkey, key);
							cout << key << '\n';
							cout << strtest << "\n\n";
							this->countset->insert(key);
							//���łɗ�̗v�f�����擾���Ă����ꍇ��r���s���A�傫�������̗p����B
							if (strtest != key) {
								if (this->testcount > this->column) {
									this->column = this->testcount;
								}
								this->testcount = 0;
							}
						}
					}
				}
			}
			//JSON�𑖍����I������Ƃ��ɃJ�E���g���Ă����񐔂��傫�����
			return key;
		}

		/*�����񃊃X�g�ɍ��W��R�Â���֐�
		�쐬���F2017.9.11
		�쐬�ҁFK.Asada*/
		Void SetTablePoint() {
			int itr = 0;		//���X�g�𑖍�����ۂ̃C���f�b�N�X
			int count = 0;					//�v�f�����o���������J�E���g����ϐ�
			this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("�e�L�["), dic[itr]->first), gcnew String("title")));
			itr++;
			if (dic[itr]->first == "class") {
				this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("title")));
				itr++;
			}

			for (int i = 0; i < *this->row; i++) {
				count = 0;
				if (dic[itr]->second == "" && ((dic[itr + 1])->first != "text" && (dic[itr + 1])->first != "array" && (dic[itr + 1])->first != "html")) {
					this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("�e�L�["), dic[itr]->first), gcnew String("y") + Convert::ToString(i)));
					itr++;
				}
				if (dic[itr]->first == "class") {
					this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("y") + Convert::ToString(i)));
					itr++;
				}

				for (int j = 0; j < *this->column; j++) {
					for (; itr < this->dic->Count; ++itr) {
						if (dic[itr]->first == "text" || dic[itr]->first == "array" || dic[itr]->first == "html") {
							//							str = gcnew String((dic[itr]->second).c_);
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
							itr++;
							count++;
							break;
						}
						else if (dic[itr]->first == "arraybegin") {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
							itr++;
							for (; j < *this->column; j++) {
								this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
								itr++;
								if (dic[itr]->first == "arrayend") {
									break;
								}
								count++;
							}
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
							itr++;
							break;
						}
						else if (dic[itr]->first == "colspan") {
							j += Convert::ToInt32(dic[itr]->second) - 1;
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else if (dic[itr]->second == "") {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(gcnew String("�e�L�["), dic[itr]->first), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
					}
					//���񏈗����̓^�C�g�����擾�����Ƃ��ă��[�v�𔲂���
					if (i == 0 && j == 0) {
						break;
					}
				}
				if (count == 1) {
					this->join[i] = "0";
				}
			}
		}

		/*�����񃊃X�g���JSON�ɕϊ�����֐�
		�쐬���F2017.9.12
		�쐬�ҁFK.Asada*/
		Void ConversionJSON() {
			ptree parent;
			ptree child;
			string title = "";
			string stmp = "";
			string arrtmp = "";
			ptree tmp;
			//String^�^�̕����񃊃X�g��string�^�֕ϊ�����֐����Ăяo��
			Stos();
			auto itr = this->jsontable->begin();
			title = itr->first.second;
			child.add((itr + 1)->first.first, (itr + 1)->first.second);
			for (int i = 0; i < this->row; i++) {
				for (auto itr = this->jsontable->begin(); itr != this->jsontable->end(); itr++) {
					if (itr->second == "y" + to_string(i)) {
						if (itr->first.first == "�e�L�[") {
							stmp = itr->first.second;
						}
						else {
							child.put(itr->first.first, itr->first.second);
							break;
						}
					}
				}
				for (int j = 0; j < this->column; j++) {
					for (auto  itr = this->jsontable->begin(); itr != this->jsontable->end(); itr++){
						if (itr->second == "x" + to_string(j) + to_string(i)) {
							if (itr->first.first == "arraybegin") {
								arrtmp = (itr - 1)->first.second;
								itr++;
							//	ptree tmp;
								ptree arr;
								string emp = "";
								for (; itr != this->jsontable->end() && itr->first.first != "arrayend"; ++itr) {
						//			tmp.add_child(itr->first.first, itr->first.second);
									arr.push_back(std::make_pair("", tmp.put(itr->first.first, itr->first.second)));
									emp = itr->first.first;
								}
								if (itr != this->jsontable->end()) {
									itr++;
								}
								if (emp != "") {
									tmp.put_child(arrtmp, arr);
									arr = tmp;
								}
								child.add_child(arrtmp, arr);
								j += *this->column;
								break;
							}
							else if (itr->first.first == "�e�L�[") {
								arrtmp = itr->first.second;
							}
							else if (itr->first.first != "�e�L�[" ){// && itr->first.first != "class") {
								child.add((arrtmp + "." + itr->first.first), itr->first.second);
							}/*
							else if (itr->first.first != "�e�L�[") {
								child.put(itr->first.first, itr->first.second);
							}*/
						}
					}
				}
//				tmp.push_back(std::make_pair(stmp, child));
//				parent.push_back(std::make_pair(title, child));
				if (stmp == "") {
					parent.add_child(title, child);
					write_json(std::cout, parent);
				}
				else {
					parent.add_child((title + "." + stmp), child);
					write_json(std::cout, parent);
				}
				child.clear();
				tmp.clear();
			}
			write_json(std::cout, parent);
		}

		//�t�@�C����蕶������擾����֐�
		//�쐬���F2017.9�D2
		//�쐬�ҁFK.Asada
		String^ LoadJSON(String^ Path) {
			String^ retString = "";			//�ԋp�p������B
			//�t�@�C�����J�����߂̃N���X���C���X�^���X��
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(Path);
			//�t�@�C���ɒ��g�����݂��邩���m�F����B
			if (!reader->EndOfStream) {
				//�ԋp�p������Ƀt�@�C������擾������������i�[�B�B
				retString = reader->ReadToEnd();
			}
			//�ǂݎ��Ȃ���΃G���[��Ԃ��B
			else {
				//�t�@�C���̒��g�����݂��Ă��Ȃ��G���[��\������B
			}
			return retString;
		}

		/*String^�^��string�^�֕ϊ�����֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada
		*/
		void MarshalString(String^ sys_string, string& std_string) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
			std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		/*String^�^�̃��X�g��string�^�֕ϊ�����֐�
		�쐬���F2017.9.12
		�쐬�ҁFK.Asada*/
		void Stos() {
			string key = "";
			string value = "";
			string point = "";
			for (int i = 0; i < this->retPointTable->Count; i++) {
				MarshalString(this->retPointTable[i]->first->first, key);
				MarshalString(this->retPointTable[i]->first->second, value);
				MarshalString(this->retPointTable[i]->second, point);
				this->jsontable->push_back(pair<pair<string, string>, string>(make_pair(key, value), point));
			}
		}

		/*�����R�[�h�̕ϊ����s���֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada
		*/
		std::string UTF8toSjis(std::string srcUTF8) {
			//Unicode�֕ϊ���̕����񒷂𓾂�
			int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

			//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//UTF8����Unicode�֕ϊ�
			MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

			//ShiftJIS�֕ϊ���̕����񒷂𓾂�
			int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//�K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
			char* bufShiftJis = new char[lengthSJis];

			//Unicode����ShiftJIS�֕ϊ�
			WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

			std::string strSJis(bufShiftJis);

			delete bufUnicode;
			delete bufShiftJis;

			return strSJis;
		}

		/*�����R�[�h�̕ϊ����s���֐�
		�쐬���F2017.9.5
		�쐬�ҁFK.Asada*/
		std::string SjistoUTF8(std::string srcSjis) {
			//Unicode�֕ϊ���̕����񒷂𓾂�
			int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);

			//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//ShiftJIS����Unicode�֕ϊ�
			MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);


			//UTF8�֕ϊ���̕����񒷂𓾂�
			int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//�K�v�ȕ�����UTF8������̃o�b�t�@���m��
			char* bufUTF8 = new char[lengthUTF8];

			//Unicode����UTF8�֕ϊ�
			WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);

			std::string strUTF8(bufUTF8);

			delete bufUnicode;
			delete bufUTF8;

			return strUTF8;
		}
	};
}