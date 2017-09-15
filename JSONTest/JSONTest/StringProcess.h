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

	//作成日：2017.9.2
	//作成者：K.Asada
	//文字列を処理する関数群クラス。
	ref class StringProcess {
	public:
		//定数クラスをインスタンス化
		CONSTANTSTRING^ MyConst = gcnew CONSTANTSTRING();
		Int32^ column = *MyConst->ZERO;		//表の列数
		Int32^ row = *MyConst->ZERO;		//表の行数
		Int32^ tmp = *MyConst->ZERO;
		int testcount = 0;
		int resetcount = 0;
		int colcount = 0;					//列数カウント用の変数
		std::set<string> *countset = new std::set<string>;
		List<String^>^ join = gcnew List<String^>;
		List<cliext::pair<String^, String^>^>^ dic = gcnew List<cliext::pair<String^, String^>^>();
		List<cliext::pair<cliext::pair<String^, String^>^, String^>^>^ retPointTable = gcnew List<cliext::pair<cliext::pair<String^, String^>^, String^>^>();
		vector<pair<pair<string, string>, string>>* jsontable = new vector<pair<pair<string, string>, string>>();

			//デフォルトコンストラクタ
		StringProcess() {
		};

		//ファイルパスより文字列を取得してその文字列から行数、列数、文字列を抜き出す。
		Void ReadyString(String^ JSONPath) {
			ptree pt;		//ファイルより取得したJSONを格納するツリー
			string JSON = "";
			string path = "";
			MarshalString(JSONPath, path);
			//受け取ったファイルパスより文字列を呼び出す。
			stringstream ss;
			std::ifstream ifs(path, ios_base::binary);
			ss << ifs.rdbuf();

			//取得した文字列よりJSONを取得する。
			read_json(ss, pt);

			//JSONから表の出力に必要な文字列を呼び出す。
			TableString(pt, "");

			this->row = *this->row + Convert::ToInt32(this->countset->size());

			//結合状態判定用の文字列を初期化する。
			for (int i = 0; i < this->row; i++) {
				this->join->Add("");
			}

			SetTablePoint();
		}

		/*箇条書きのJSONを読み込むための関数
		作成日：2017.9.12
		作成者：K.Asada */
		//ファイルパスより文字列を取得してその文字列から行数、列数、文字列を抜き出す。
		Void ReadyListString(String^ JSONPath) {
			ptree pt;		//ファイルより取得したJSONを格納するツリー
							//	String^ SJSON = "";
			string JSON = "";
			string path = "";
			MarshalString(JSONPath, path);
			//受け取ったファイルパスより文字列を呼び出す。
			stringstream ss;
			std::ifstream ifs(path, ios_base::binary);
			ss << ifs.rdbuf();

			//取得した文字列よりJSONを取得する。
			read_json(ss, pt);

			//JSONから表の出力に必要な文字列を呼び出す。
			TableString(pt, "");
			//JSONから表の行数を割り出す関数を呼び出す。

			this->row = *this->column + 1;
			//タイトルの行数を考慮して列数を補正する。
			this->column = 1;

			for (int i = 0; i < this->row; i++) {
				this->join->Add("");
			}

			SetListTablePoint();
		}

		/*リスト形式のJSON用の座標を格納する関数
		作成日：2017.9.15
		作成者：K.Asada*/
		Void SetListTablePoint() {
			int itr = 0;		//リストを走査する際のインデックス
			int count = 0;					//要素を取り出した数をカウントする変数
			this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("title")));
			itr++;
			if (dic[itr]->first == "class") {
				this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("title")));
				itr++;
			}

			for (int i = 0; i < *this->row; i++) {
				count = 0;
				if (dic[itr]->second == "" && ((dic[itr + 1])->first != "text" && (dic[itr + 1])->first != "array" && (dic[itr + 1])->first != "html")) {
					this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("y") + Convert::ToString(i)));
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
							for (; i < *this->row; i++) {
								this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
								itr++;
								if (itr > this->dic->Count || dic[itr]->first == "arrayend") {
									break;
								}
								count++;
							}
							if (dic[itr]->first == "arrayend") {
								this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
								itr++;
							}
							break;
						}
						else if (dic[itr]->first == "colspan") {
							j += Convert::ToInt32(dic[itr]->second) - 1;
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else if (dic[itr]->second == "") {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
					}
					//初回処理時はタイトルを取得したとしてループを抜ける
					if (i == 0 && j == 0) {
						break;
					}
				}
				if (count == 1) {
					this->join[i] = "0";
				}
			}
		}

		/*DBとの通信結果を表にするために必要な文字列を取得する関数
		作成日：2017.9.14
		作成者：K.Asada*/
		Void DBTable(string result) {
//	//		StringProcess^ test = gcnew StringProcess();
//		//	string result;			//通信結果を格納する文字列
//		//	string tmp;
//	//		this->MarshalString(this->SendQuery, tmp);
//			JSONDBManager dbmana;
//			//DB処理へ移行する
////			result = dbmana.DBrun(tmp);*/
//			ptree pt;		//ファイルより取得したJSONを格納するツリー
//			string JSON = "";
//			JSON = dbmana.DBrun(result);
////			JSON = UTF8toSjis(JSON);
////			cout <<JSON << '\n';
//	//		JSON = SjistoUTF8(JSON);
//		//	cout << JSON << '\n';
//			//JSON = UTF8toSjis(JSON);
//			//cout <<JSON << '\n';
//
//			//受け取ったファイルパスより文字列を呼び出す。
//			stringstream ss;
//			ss << JSON;
//
//			//取得した文字列よりJSONを取得する。
//			read_json(ss, pt);
//
//			//JSONから表の出力に必要な文字列を呼び出す。
//			TableString(pt, "");
//			//JSONから表の行数を割り出す関数を呼び出す。
//			//JSONから表の列数を割り出す関数を呼び出す。
//			CountColumn();
//
//			this->row = *this->row / *this->column;
//			if (this->row < 0) {
//				this->row = abs(*this->row);
//			}
//			//タイトルの行数を考慮して列数を補正する。
//			//結合状態判定用の文字列を初期化する。
//			for (int i = 0; i < this->row; i++) {
//				this->join->Add("");
//			}
//
//			SetTablePoint();
		}

		/*出力する表に必要な文字列および列数を割り出すための関数
		作成日：2017.9.4
		作成者：K.Asada
		*/
		Void TableString(ptree pt, string key) {
			string strtest = key;		//兄弟を判定用の文字列を格納する文字列
			string childkey = "";		//再帰処理の時に必要な子のキー名を格納する文字列。
			//キー名が空の時（初回ループ時）
			if (key == "") {
				//キー名を取得するためのイテレーターを宣言。
				auto itr = pt.begin();
				//キー名をイテレーターより取得。
				key = itr->first;
			}
			//子に文字列があった場合
			if (boost::optional<std::string> str = pt.get_optional<std::string>(key)) {
				//文字列をキー名をペアにしてマップに格納する。
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(key).c_str()), gcnew String(UTF8toSjis(str.get()).c_str())));
			}
			//子に整数があった場合
			else if (boost::optional<int> value = pt.get_optional<int>(key)) {
				//キー名をペアにしてマップに格納する
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(key).c_str()), gcnew String((UTF8toSjis(to_string(value.get()))).c_str())));
			}
			//子がまだいる場合
			if (pt.get_child_optional(key)) {
				//子の兄弟を走査する
				BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
					//判定を行うためにsecondを取得
					const ptree& info = child.second;
					ptree test = pt.get_child(key);
					//子のキー名を取得する
					childkey = child.first;
					//子要素が配列かつ整数であれば
					if (boost::optional<int> value = info.get_optional<int>(childkey)) {
						//キー名をペアにしてマップに格納する
						this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(to_string(value.get())).c_str())));
					//子要素が配列かつ文字列であれば
					}
					else if (boost::optional<std::string> str = info.get_optional<std::string>(childkey)) {
						//配列を示す文字列を連結する
						this->dic->Add(%cliext::pair<String^, String^>(gcnew String("arraybegin"), gcnew String("arraybegin")));
						//キーと値の両方が存在しているときはイテレーターで走査
						if (info.begin() != info.end()) {
							//文字列に変換する関数を呼び出す
							this->ArrayJSONpair(info);
						}//値しか存在していないとき（中身がただの配列の時）
						else {
							//文字列に変換する関数を呼び出す
							this->ArrayJSON(pt, key);
							//兄弟のループを抜ける
							break;
						}
					}
					//子の子（孫）が存在しておらず子のペアを文字列として取得できれば
					else if (boost::optional<std::string> str = (test.get_optional<std::string>(childkey))) {
						//完成したら関数に移行する予定
						//子のペアが表の要素となりうる文字列であった場合
						if (str.get() != "" && childkey == "text") {
							childkey = child.first;
							//文字列をペアにしてマップに格納
							this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(test.get<std::string>(childkey)).c_str())));
							//列数をカウントする
							this->colcount++;
						}
						//表の要素以外の付加情報であった場合
						else if (str.get() != "") {
							//文字列をペアにしてマップに格納
							this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(childkey).c_str()), gcnew String(UTF8toSjis(test.get<std::string>(childkey)).c_str())));
						}
						//子がいる場合
						else {
							//再帰処理を行う			
							TableString(pt.get_child(key), childkey);
							//再帰処理を行ったときの親を重複しないように取得
							this->countset->insert(key);
							//キーの比較を行う。異なる場合は兄弟を移動しているため列数のカウントをリセット
							if (strtest != key) {
								//列数を比較する関数を呼び出す
								this->CountColumn();
							}
						}
					}
				}
			}
		}

		/*表の列数を取得するための比較を行う関数
		作成日：2017.9.15
		作成者：K.Asada*/
		Void CountColumn() {
			//メンバの列数と比較し、大きい方を採用する
			if (this->colcount > this->column) {
				this->column = this->colcount;
			}
			//列数のカウントをリセットする
			this->colcount = 0;
		}

		/*JSONの中身がオブジェクトの配列になっているものを文字列に格納する関数
		作成日：2017.9.15
		作成者：K.Asada*/
		Void ArrayJSONpair(const ptree& info) {
			//配列の中身を走査する
			for (auto itr = info.begin(); itr != info.end(); itr++) {
				//キー名と値をセットにしてマップに格納する
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(UTF8toSjis(itr->first).c_str()), gcnew String(UTF8toSjis(info.get<std::string>(itr->first)).c_str())));
				//列数をカウントする
				this->colcount++;
			}
			//列数をカウントしていれば
			if (this->colcount != 0) {
				//列数を比較する関数を呼び出す
				this->CountColumn();
			}
			this->row = *this->row + 1;
			//配列の終端を示す文字列を格納する
			this->dic->Add(%cliext::pair<String^, String^>(gcnew String("arrayend"), gcnew String("arrayend")));
		}

		/*JSONの中身がただの配列になっているものを文字列に格納する関数
		作成日：2017.9.15
		作成者：K.Asada*/
		Void ArrayJSON(ptree pt, string key) {
			//配列を走査する
			BOOST_FOREACH(const ptree::value_type& child, pt.get_child(key)) {
				//文字列をキー名をペアにしてマップに格納する。
				this->dic->Add(%cliext::pair<String^, String^>(gcnew String(""), gcnew String(UTF8toSjis(child.second.get<std::string>(child.first)).c_str())));
				//列数をカウントする
				this->colcount++;
			}
			//列数をカウントしていれば
			if (this->colcount != 0) {
				this->column = this->colcount;
				//階層を判定する変数をリセット
				this->resetcount = 1;
				//列数をカウントする変数をリセット
				this->colcount = 0;
				//列数を比較する関数を呼び出す
				//this->CountColumn();
			}
			//配列の終端を示す文字列を格納する
			this->dic->Add(%cliext::pair<String^, String^>(gcnew String("arrayend"), gcnew String("arrayend")));
		}

		/*文字列リストに座標を紐づける関数
		作成日：2017.9.11
		作成者：K.Asada*/
		Void SetTablePoint() {
			int itr = 0;		//リストを走査する際のインデックス
			int count = 0;					//要素を取り出した数をカウントする変数
			this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("title")));
			itr++;
			if (dic[itr]->first == "class") {
				this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("title")));
				itr++;
			}

			for (int i = 0; i < *this->row; i++) {
				count = 0;
				if (dic[itr]->second == "" && ((dic[itr + 1])->first != "text" && (dic[itr + 1])->first != "array" && (dic[itr + 1])->first != "html")) {
					this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String^>(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("y") + Convert::ToString(i)));
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
								if (itr > this->dic->Count || dic[itr]->first == "arrayend") {
									break;
								}
								count++;
							}
							if (dic[itr]->first == "arrayend") {
								this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^>(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
								itr++;
							}
							break;
						}
						else if (dic[itr]->first == "colspan") {
							j += Convert::ToInt32(dic[itr]->second) - 1;
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else if (dic[itr]->second == "") {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(gcnew String("親キー"), dic[itr]->first), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
						else {
							this->retPointTable->Add(%cliext::pair<cliext::pair<String^, String^>^, String ^ >(%cliext::make_pair(dic[itr]->first, dic[itr]->second), gcnew String("x") + Convert::ToString(j) + Convert::ToString(i)));
						}
					}
					//初回処理時はタイトルを取得したとしてループを抜ける
					if (i == 0 && j == 0) {
						break;
					}
				}
				if (count == 1) {
					this->join[i] = "0";
				}
			}
		}

		/*文字列リストよりJSONに変換する関数
		作成日：2017.9.12
		作成者：K.Asada*/
		Void ConversionJSON() {
			ptree parent;
			ptree child;
			string title = "";
			string stmp = "";
			string arrtmp = "";
			ptree tmp;
			//String^型の文字列リストをstring型へ変換する関数を呼び出す
			Stos();
			auto itr = this->jsontable->begin();
			title = itr->first.second;
			child.add((itr + 1)->first.first, (itr + 1)->first.second);
			for (int i = 0; i < this->row; i++) {
				for (auto itr = this->jsontable->begin(); itr != this->jsontable->end(); itr++) {
					if (itr->second == "y" + to_string(i)) {
						if (itr->first.first == "親キー") {
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
							else if (itr->first.first == "親キー") {
								arrtmp = itr->first.second;
							}
							else if (itr->first.first != "親キー" ){// && itr->first.first != "class") {
								child.add((arrtmp + "." + itr->first.first), itr->first.second);
							}/*
							else if (itr->first.first != "親キー") {
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

		//ファイルより文字列を取得する関数
		//作成日：2017.9．2
		//作成者：K.Asada
		String^ LoadJSON(String^ Path) {
			String^ retString = "";			//返却用文字列。
			//ファイルを開くためのクラスをインスタンス化
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(Path);
			//ファイルに中身が存在するかを確認する。
			if (!reader->EndOfStream) {
				//返却用文字列にファイルから取得した文字列を格納。。
				retString = reader->ReadToEnd();
			}
			//読み取れなければエラーを返す。
			else {
				//ファイルの中身が存在していないエラーを表示する。
			}
			return retString;
		}

		/*String^型をstring型へ変換する関数
		作成日：2017.9.5
		作成者：K.Asada
		*/
		void MarshalString(String^ sys_string, string& std_string) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
			std_string = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		/*String^型のリストをstring型へ変換する関数
		作成日：2017.9.12
		作成者：K.Asada*/
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

		/*文字コードの変換を行う関数
		作成日：2017.9.5
		作成者：K.Asada
		*/
		std::string UTF8toSjis(std::string srcUTF8) {
			//Unicodeへ変換後の文字列長を得る
			int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

			//必要な分だけUnicode文字列のバッファを確保
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//UTF8からUnicodeへ変換
			MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

			//ShiftJISへ変換後の文字列長を得る
			int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//必要な分だけShiftJIS文字列のバッファを確保
			char* bufShiftJis = new char[lengthSJis];

			//UnicodeからShiftJISへ変換
			WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

			std::string strSJis(bufShiftJis);

			delete bufUnicode;
			delete bufShiftJis;

			return strSJis;
		}

		/*文字コードの変換を行う関数
		作成日：2017.9.5
		作成者：K.Asada*/
		std::string SjistoUTF8(std::string srcSjis) {
			//Unicodeへ変換後の文字列長を得る
			int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);

			//必要な分だけUnicode文字列のバッファを確保
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

			//ShiftJISからUnicodeへ変換
			MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);


			//UTF8へ変換後の文字列長を得る
			int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

			//必要な分だけUTF8文字列のバッファを確保
			char* bufUTF8 = new char[lengthUTF8];

			//UnicodeからUTF8へ変換
			WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);

			std::string strUTF8(bufUTF8);

			delete bufUnicode;
			delete bufUTF8;

			return strUTF8;
		}

		/*string型のペアをString^型のペアに変換する関数
		作成日：2017.9.15
		作成者：K.Asada*/
//		List<cliext::pair<String^, String^>^> MyStrPair(string pair, string with) {
			//String型のペアにして返却する
	//		return cliext::pair<String^, String^>(%cliext::make_pair(gcnew String(pair.c_str()), gcnew String(with.c_str())));
		//}
	};
}