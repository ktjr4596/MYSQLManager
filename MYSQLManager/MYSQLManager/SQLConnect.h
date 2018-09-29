#pragma once
//class SQLManager;
class SQLConnect {
private:
	MYSQL * conn;
public :
	SQLConnect();
	~SQLConnect();
	const SQLConnect & getDB (const char *);
	
	operator MYSQL *() const { return conn; }
	int executeQuery (const std::string &) const ;
	void getadd() const {
		std::cout << &conn << std::endl;
	}
};