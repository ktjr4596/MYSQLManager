#pragma once

class SQLManager {


private:
	static std::list<SQLpool> pool;
	//struct static_constructor { static한 객체를 생성할때 static 한 멤버변수를 생성
	//	static_constructor() {

	//	}
	//};
	//static static_constructor sc;
public:

	SQLManager() = delete;
	static void addDB(const char *, const char *, const char *, const char *);
	static const SQLConnect & getConn(const char *);
	
};
