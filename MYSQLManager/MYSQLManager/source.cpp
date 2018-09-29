#include "sqlheader.h"
int main()
{

	SQLManager::addDB("35.221.101.18", "ktjr4596", "seo1031202", "ktjr4596");
	
	const auto & conn= SQLManager::getConn("ktjr4596");
	const auto & conn2 = SQLManager::getConn("ktjr4596");
	conn2.executeQuery("delete from test");
	//conn.executeQuery("select * from test where test1=5555");
	//conn.executeQuery("select * from test");


}