#include "sqlheader.h"

SQLpool::SQLpool() {
	pool_list.resize(MAX_CONNECT);
	p = pool_list.begin();
}


void SQLpool::setParameter(const char * host, const char * user, const char * pw, const char * db, unsigned int max_conn = 10) {
	pool_host = host;
	pool_user = user;
	pool_pw = pw;
	pool_dbname = db;
	MAX_CONNECT = max_conn;
}

const SQLConnect & SQLpool::getConn(const char * dbname) {
	if (p == pool_list.end())
		pool_resize();
		
	
	mysql_real_connect(*p, pool_host, pool_user, pool_pw, dbname, 0, nullptr, 0);
	p->getadd();
	
	return *p++;
}

void SQLpool::pool_resize() {
	pool_list.resize(MAX_CONNECT * 2);
	MAX_CONNECT *= 2;
}