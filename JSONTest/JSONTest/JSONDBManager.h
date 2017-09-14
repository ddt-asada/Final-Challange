///* 関数名：createJSON
//* 概要:DBからデータを取得してJSONを作る
//* 引数:Map<String,Object> json:カレントのJSON
//*     String:key:JSONのキー
//*     DBResultTree:dbrt_parent:DBから取得したデータを格納してツリー構造を作るためのクラスのインスタンス
//* 戻り値:無し
//* 作成日:2017.9.13
//* 作成者:K.Asada
//*/
//#pragma once
//
//#include <iostream>
//#include <fstream>//テスト用
//#include <string>
//#include <vector>
//#include <sstream>
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include <boost/uuid/sha1.hpp>
//#include <boost/cstdint.hpp>
//#include <boost/array.hpp>
//
//#include "mysql_connection.h"
//
//#include "DbConnect.h"		//自作クラス。DB接続の関数を持つ。
//
//class JSONDBManager : public DbConnect {
//public:int processedRecords = 0;
//
//public:
//
//	JSONDBManager() {
//
//	};
//	/*関数名：DBrun
//	概要：DBとの通信を行う関数を呼び出す
//	引数：string:query：実行するクエリ
//	戻り値：DBから取得したデータ
//	作成日：2017.9.13
//	作成者：K.Asada*/
//	std::string DBrun(std::string query) {
//		std::string queryResult = "";	//DBとの通信結果を格納する文字列
//		//DBへの接続を行う
//		this->connect();
//		//DBから文字列を取得するための関数を呼び出す
//		queryResult = this->getListJSON(query);
//		std::cout << queryResult << '\n';
//		//DBから切断する
//		this->disconnect();
//		//通信結果を返却する
//		return queryResult;
//	}
//
//
//	/* 関数名：executeQuery
//	* 概要:クエリを実行してDBから結果セットを取得する
//	* 引数:Map<String,Object> json:カレントのJSON連想配列
//	*     String:queryKey:実行するクエリのベースとなる文字列
//	* 戻り値:ResultSet retRs:DBから取得した結果セットを返す
//	* 作成日:2016.10.19
//	* 作成者:R.Shibata
//	* 更新日:2017.8.15
//	* 更新者:K.Asada
//	* 更新内容:C++に対応するように引数などjava特有のものを変更。
//	*/
//
//	//あとで例外処理を追記する。
//	//テスト完了。
//	//パス関係のみ後程追記予定。
//	sql::ResultSet* executeQuery(std::string queryKey) {
//		//返却する結果セットの変数を作成する
//		int tmp = 0;
//		std::string query;			//キー名に対応した値を格納する文字列。
//		std::string replaceValue;	//置換対象の文字列を格納する文字列。
//		std::string passString;		//パスワードの紐づいた文字列を格納する文字列。
//		sql::Statement *stmt;		//ステートメントを格納する。
//		sql::ResultSet *res = NULL;		//Connecter/C++で使う。
//		try {
//			//実行できないパターンのクエリを修正する
//			query = queryCorrection(queryKey);
//			std::cout << query << '\n';
//			//ステートメントを作成する
//			stmt = con->createStatement();
//
//			//クエリを実行し結果セットを返すクエリであれば。
//			if (stmt->execute(query)) {
//				res = stmt->getResultSet();
//				//行数を取得するため、レコードセットの位置をlastにする
//				res->last();
//				//処理を行ったレコード数を結果セットより取得してメンバに保存する
//				processedRecords = res->getRow();
//				//行数を取得するためにlastにしたカーソル位置を先頭に戻す。
//				res->beforeFirst();
//			}
//			else {
//				//結果を返さない場合は更新した行数を取得する。
//				processedRecords = stmt->getUpdateCount();
//			}
//		}
//		catch (sql::SQLException &e) {
//			std::cout << "# ERR: SQLException in " << __FILE__;
//			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << '\n';
//			std::cout << "# ERR: " << e.what();
//			std::cout << " (MySQL error code: " << e.getErrorCode();
//			std::cout << ", SQLState: " << e.getSQLState() << " )" << '\n';
//
//		}
//		//結果セットを返す
//		return res;
//	}
//
//	/* 関数名：getListJSON
//	* 概要:リスト形式のJSONを作成して返す
//	* 引数:Map<String, Object> json:JSONのオブジェクト。
//	* 戻り値:String strAll:JSONの文字列配列を文字列で返す
//	* 作成日:2016.10.20
//	* 作成者:R.Shibata
//	*/
//
//	std::string getListJSON(std::string str) {
//		//返却する文字列を作成するための変数を3つ宣言、初期化する。
//		std::string strAll = "";
//		std::string strBlock = "";
//		std::string strLine = "";
//		try {
//			//データベースから当該レコード群を取得する(結果セットを取得する)
//			sql::ResultSet* rs = executeQuery(str);
//			//レコードセットの列名を取得する、あとでいじる。
//			sql::ResultSetMetaData* rsMeta = rs->getMetaData();
//			//レコードセットの列数を取得する、あとでいじる。
//			int columnCount = rsMeta->getColumnCount();
//			//結果セットの行についてのループ
//			while (rs->next()) {
//				//レコードの文字列を初期化する
//				strLine = "";
//				//列についてのループ
//				for (int i = 0; i < columnCount; i++) {
//					//列名を取得する(別名の取得)
//					std::string sColName = rsMeta->getColumnLabel(i + 1);
//					//列の値を取得する
//					std::string value = rs->getString(i + 1);
//					//列の値がNULLだった場合、ブランクに置換する
//					value = value == "" ? "" : value;
//					//文字列の行単位の変数が空でない時、行の文字列をカンマで区切る
//					strLine += strLine == "" ? "" : ",";
//
//					//取得した値に、JSON用のエスケープ処理を行う
//					value = escapeJSONValue(value);
//
//					//1行分のデータを文字列に追加する
//					strLine += "\"" + sColName + "\":\"" + value + "\"";
//				}
//				//行に文字列が入っていたら、カンマで区切る
//				strBlock += strBlock == "" ? "" : ",";
//				//作成した行の文字列をブロックの文字列に追加する
//				strBlock += "{" + strLine + "}";
//
//			}
//		}
//		catch (std::exception) {
//
//			throw;
//		}
//		//作成した全ブロックを配列の括弧で囲む
//		strAll = "{\"TableData\":[" + strBlock + "]}";
//		//作成した文字列を返す
//		return strAll;
//	}
//	/* 関数名：escapeJSONValue
//	* 概要:引数で受け取った文字列をJSON用のエスケープ処理を行い返却する
//	* 引数:String str:エスケープする文字列
//	* 戻り値:String:エスケープした文字列
//	* 作成日:2016.10.27
//	* 作成者:R.Shibata
//	*/
//	std::string escapeJSONValue(std::string str) {
//		//返却用文字列に、引数の文字列をセットする
//		std::string retStr = str;
//		//￥マークをエスケープ文字に置き換える(replaceAllは正規表現として扱われるため、￥一つが\4つ分となる）
//		//文字列を置き換える関数を呼び出す。
//		retStr = Replace(retStr, "\\\\", "\\\\\\\\");
//		//改行文字をエスケープ文字に置き換える
//		retStr = Replace(retStr, "\r\n", "\\\\n");
//		//改行文字をエスケープ文字に置き換える
//		retStr = Replace(retStr, "\r", "\\\\n");
//		//改行文字をエスケープ文字に置き換える
//		retStr = Replace(retStr, "\n", "\\\\n");
//		//ダブルクォートをエスケープ文字に置き換える
//		retStr = Replace(retStr, "\"", "\\\\\"");
//		//エスケープした値を返却する
//		return retStr;
//	}
//
//	/*関数名：Replace
//	概要：引数で受け取った文字列を入れ替える関数
//	引数：string rep：中身を変更したい文字列
//		：string target：置き換え対象の文字列
//		：string change：置き換え後の文字列
//	戻り値：String：文字列から対象の文字列をすべて置き換えた文字列
//	作成日：2017.9.13
//	作成者：K.Asada
//	*/
//	std::string Replace(std::string rep, std::string target, std::string change) {
//		for (int i = 0; i < rep.length();) {
//			//置き換え対象の文字列を探す。
//			i = rep.find(target, i);
//			//置き換え対象の文字が見つかったら。
//			if (i <= rep.length()) {
//				//文字列を置き換える。
//				rep.replace(i, target.length(), change);
//				//インデックスの位置を置き換えた文字列の後ろに移動させる
//				i += change.length();
//			}
//		}
//		//置き換え後の文字列を返す。
//		return rep;
//	}
//	/* 関数名：queryCorrection
//	* 概要:Javaでは実行できないタイプのクエリーを修正して返却する
//	*    :本来であればこんな処理は不要のはず
//	* 引数:String query:修正対象のクエリー
//	* 戻り値:String:修正後のクエリーを返却する
//	* 作成日:2017.9.13
//	* 作成者:K.Asada
//	*/
//	//いるかわからないけどとりあえず置いておく。
//	std::string queryCorrection(std::string query) {
//		//返却用クエリーの文字列を宣言し、入力のクエリーをセットする
//		std::string retQuery = query;
//		//クエリーの中にセミコロンが含まれている場合
//		if (retQuery.find(";") != -1) {
//			//クエリの最初の;を検索しindexを保持する。;も出力対象のため、数値を+1する
//			int index = retQuery.find(";") + 1;
//			//クエリー文字列から最初の";"までを切り出す
//			retQuery = retQuery.substr(0, index);
//		}
//		//修正したクエリーを返却する
//		return retQuery;
//	}
//};
