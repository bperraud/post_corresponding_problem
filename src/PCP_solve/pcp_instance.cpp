#include "pcp_instance.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>


Pcp_instance::Pcp_instance(std::initializer_list<std::string> blocs) : _length(blocs.size()/2), _instance(blocs.size()/2, Pcp_bloc())
{
	auto bloc = blocs.begin();
	for (std::size_t i = 0; i < _length; i++)
	{
		_instance[i] = Pcp_bloc(*bloc, *(bloc+1));
		bloc += 2;
	}
}


bool Pcp_instance::prefix_filter()
{
	for (int i = 0; i < _length ; i++)
	{
		if (_instance[i].has_prefix())
			return (false);
	}
	return (true);
}


bool Pcp_instance::length_balance_filter()
{
	for (int i = 0; i < _length ; i++)
	{
		if (_instance[i].has_prefix())																		 // le bloc i peut être placé en premier
		{
			for (int j = 0; j < _length; j++)
			{
				if ( j != i && _instance[j].top_less_bottom_len() + _instance[i].top_less_bottom_len() <= 0) // il existe un autre bloc qui contrebalance la longueur de la plus grande string
					return (false);
			}
		}
	}
	return (true);
}


bool Pcp_instance::element_balance_filter()
{
	for (int i = 0; i < _length ; i++)
	{
		if (_instance[i].has_prefix())																		 // le bloc i peut être placé en premier
		{
			for (int j = 0; j < _length; j++)
			{
				if ( j != i && _instance[j].top_less_bottom_ones() + _instance[i].top_less_bottom_ones() <= 0) // il existe un autre bloc qui contrebalance le nombre de 1
					return (false);
			}
		}
	}
	return (true);
}


std::string Pcp_instance::stringify()
{
    std::string res;
    for (int i = 0; i < _length; i++){
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
