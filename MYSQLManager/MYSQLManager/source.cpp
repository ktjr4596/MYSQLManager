#include "sqlheader.h"

int main()
{
	std::cout << "hello" << std::endl;
	SQLManager::addDB("35.221.101.18", "ktjr4596", "seo1031202", "ktjr4596");
	
	const SQLConnect & conn= SQLManager::getConn("ktjr4596");
	conn.getadd();
	//conn.getDB("ktjr4596");
	conn.executeQuery("insert into test values (10,'r')");
	//getchar();

}