#pragma once
#pragma comment (lib,"libmysql.lib")

class SQLpool {
private:

	std::list<SQLConnect> pool_list;
	const char * pool_host;
	const char * pool_user;
	const char * pool_pw;
	const char * pool_dbname;

	unsigned int MAX_CONNECT = 10;

public :
	SQLpool();
	//~SQLpool() {};
	SQLpool(const SQLpool &) = delete;
	SQLpool & operator=(const SQLpool &) = delete;
	std::list<SQLConnect>::iterator p;
	void setParameter(const char *, const char *, const char *, const char *, unsigned int);
	const SQLConnect & getConn(const char *);
	void pool_resize();

};