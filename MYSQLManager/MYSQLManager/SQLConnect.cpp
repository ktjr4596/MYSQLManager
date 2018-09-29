#include"sqlheader.h"
#include <string>
SQLConnect::SQLConnect() {
	conn=mysql_init(nullptr);
	std::cout << "sqlconnect()" << std::endl;
}

SQLConnect::~SQLConnect() {
	std::cout << "~sqlconnect()" << std::endl;
	if (!conn) {
		mysql_close(conn);
	}
	//delete conn;
}



const SQLConnect & SQLConnect::getDB  (const char * dbname) {
	return SQLManager::getConn(dbname);
}

int SQLConnect::executeQuery  (const std::string & query) const  {
	std::string command;


		
	for (auto p = query.begin(); p != query.end(); ++p) {
		command += *p;
		if (*p == ' ')
			break;
	}
	std::cout << command << std::endl;
	std::cout<<mysql_query(conn, query.c_str());
	return 0;
}