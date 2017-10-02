#pragma once

#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class DBConnect
{
public:
	sql::Connection *con;
	DBConnect() {

	};

	/* �֐���:connect
	* �T�v:DB�Ƃ̐ڑ����s���B
	* ����:����
	* �߂�l:����
	* �쐬��:2017.9.13
	* �쐬��:R.Shibata
	*/
	void connect() {
		sql::Driver *driver;
		sql::Statement *stmt;

		driver = get_driver_instance();

		//�ڑ����s���B
		con = driver->connect("tcp://localhost/ddthink-com00006","root", "asada");

	}

	/* �֐���:disconnect
	* �T�v:DB�Ƃ̐ڑ������B
	* ����:����
	* �߂�l:����
	* �쐬��:2017.9.13
	* �쐬��:R.Shibata
	*/
	void disconnect() {

		con->close();
	}
};