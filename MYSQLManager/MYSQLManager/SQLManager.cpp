#include "sqlheader.h"

SQLpool SQLManager::pool;
//SQLManager::static_constructor SQLManager::sc;

void SQLManager::addDB(const char * host, const char *user, const char * pw, const char *db) {
	pool.setParameter(host, user, pw, db,10);


	
}

const SQLConnect & SQLManager::getConn(const char * dbname) {
	return pool.getConn(dbname);
	
}