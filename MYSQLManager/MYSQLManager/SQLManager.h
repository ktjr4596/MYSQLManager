#pragma once

class SQLManager {


private:
	static std::list<SQLpool> pool;
	//struct static_constructor { static�� ��ü�� �����Ҷ� static �� ��������� ����
	//	static_constructor() {

	//	}
	//};
	//static static_constructor sc;
public:

	SQLManager() = delete;
	static void addDB(const char *, const char *, const char *, const char *);
	static const SQLConnect & getConn(const char *);
	
};
