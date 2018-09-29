#include "sqlheader.h"

SQLpool::SQLpool() {
	std::cout << "hi" << std::endl;
	pool_list.resize(MAX_CONNECT);
}


void SQLpool::setParameter(const char * host, const char * user, const char * pw, const char * db, unsigned int max_conn = 10) {
	pool_host = host;
	pool_user = user;
	pool_pw = pw;
	pool_dbname = db;
	MAX_CONNECT = max_conn;
}

const SQLConnect & SQLpool::getConn(const char * dbname) {
	mysql_real_connect(*pool_list.begin(), pool_host, pool_user, pool_pw, dbname, 0, nullptr, 0);
	pool_list.begin()->getadd();
	
	return *pool_list.begin();
}