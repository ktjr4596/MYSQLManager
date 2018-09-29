#pragma once
#include <vector>
#include <string>

//class SQLManager;
class SQLConnect {
private:
	MYSQL * conn;	
	const bool mytransaction() const;
	const bool mycommit() const ;
	const bool myrollback() const;
public :
	SQLConnect();
	~SQLConnect();
	SQLConnect(const SQLConnect &) = delete;
	SQLConnect & operator=(const SQLConnect &) = delete;
	const SQLConnect & getDB (const char *);
	
	operator MYSQL *() const { return conn; }
	const std::vector<std::vector<std::string>> executeQuery (const std::string &) const;
	void getadd() const {
		std::cout << &conn << std::endl;
	}
	void showresult(const std::vector<std::vector<std::string>> &) const;


};