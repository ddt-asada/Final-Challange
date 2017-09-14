//#pragma once
//
//#include <stdlib.h>
//#include <iostream>
//
//#include "mysql_connection.h"
//
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//
//class DbConnect
//{
//public:
//	sql::Connection *con;
//	DbConnect() {
//
//	};
//
//	/* 関数名:connect
//	* 概要:DBとの接続を行う。
//	* 引数:無し
//	* 戻り値:無し
//	* 作成日:2017.9.13
//	* 作成者:R.Shibata
//	*/
//	void connect() {
//		sql::Driver *driver;
//		sql::Statement *stmt;
//
//		driver = get_driver_instance();
//
//		//接続を行う。
//		con = driver->connect("tcp://localhost/ddthink-com00006","root", "asada");
//
//	}
//
//	/* 関数名:disconnect
//	* 概要:DBとの接続を閉じる。
//	* 引数:無し
//	* 戻り値:無し
//	* 作成日:2017.9.13
//	* 作成者:R.Shibata
//	*/
//	void disconnect() {
//
//		con->close();
//	}
//};