#include "sqlheader.h"

std::list<SQLpool> SQLManager::pool;
//SQLManager::static_constructor SQLManager::sc;

void SQLManager::addDB(const char * host, const char *user, const char * pw, const char *db) {
	pool.emplace_back();
	pool.begin()->setParameter(host, user, pw, db,10);


	
}

const SQLConnect & SQLManager::getConn(const char * dbname) {
	return pool.begin()->getConn(dbname);
	
}