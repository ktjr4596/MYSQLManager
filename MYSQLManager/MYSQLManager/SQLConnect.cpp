#include"sqlheader.h"


SQLConnect::SQLConnect() {
	conn=mysql_init(nullptr);
}

SQLConnect::~SQLConnect() {
	if (!conn) {
		mysql_close(conn);
	}
}



const SQLConnect & SQLConnect::getDB  (const char * dbname) {
	return SQLManager::getConn(dbname);
}


const std::vector<std::vector<std::string>> SQLConnect::executeQuery(const std::string & query) const{

	

	MYSQL_RES * sql_res;
	MYSQL_ROW sql_row;
	if (!mytransaction())
	{
		if (!mysql_query(conn, query.c_str()))
		{
			sql_res = mysql_store_result(conn);
			if (sql_res)
			{	
				std::vector<std::vector < std::string >> res;
				while (sql_row = mysql_fetch_row(sql_res)) 
				{
					std::vector<std::string> temp;
					for (int i = 0; i < mysql_num_fields(sql_res); ++i) {
						
						temp.emplace_back(sql_row[i]);
					}
					res.emplace_back(temp);
					
				}
				showresult(res);
				if(!mycommit())
				return res;
			}
		}
		else {
			if (!myrollback()) {
				std::cerr << "query failed" << std::endl;
				return {};
			}
		}
		if (!mycommit())
			std::cout << "query success" << std::endl;
	}

	return {};
	
}

void SQLConnect::showresult(const std::vector<std::vector<std::string>>& res) const
{
	if (!res.empty()) {
		for (auto &m : res) {
			for (auto &p : m) {
				std::cout << p << "\t";
			}
			std::cout << std::endl;
		}
	}
}

const bool SQLConnect::mytransaction() const  {
	return mysql_query(conn, "start transaction");
}


const bool SQLConnect::mycommit() const {
	return mysql_query(conn, "commit");
}

const bool SQLConnect::myrollback() const{
	return mysql_query(conn,"rollback");
}