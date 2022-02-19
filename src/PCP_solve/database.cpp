#include "database.h"


std::string Pcp_instance::stringify()
{
	std::string res;
	for (int i = 0; i < _size; i++)
	{
		Pcp_bloc bloc = _instance[i];
		res += bloc.get_top() + "," + bloc.get_bottom() + ",";
	}
	res.pop_back(); //removes last ','
	return res;
}


void Pcp_instance::write_instance()
{
	try
	{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("localhost", "PCPadmin", "AXaHUKc])n2D%t*\"T6Ve");
		con->setSchema("PCP");

		stmt = con->createStatement();
		stmt->execute("INSERT INTO instances(pairs, sol_len) VALUES ('" + stringify() + "', '" + std::to_string(sol_len)+ "')");

		delete stmt;
		delete con;
	}
	catch (sql::SQLException &e)
	{
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line "
				  << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}


bool Pcp_instance::is_in_db()
{
	try
	{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		bool is_in_db;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("localhost", "PCPadmin", "AXaHUKc])n2D%t*\"T6Ve");
		con->setSchema("PCP");

		stmt = con->createStatement();
		res = stmt->executeQuery("Select * from instances where pairs='" + stringify() + "'");

		is_in_db = res->rowsCount() == 1;

		delete res;
		delete stmt;
		delete con;
		return is_in_db;
	}
	catch (sql::SQLException &e)
	{
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line "
				  << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}

