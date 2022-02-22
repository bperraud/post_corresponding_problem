#include "pcp_solution.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>


bool Pcp_solution::is_solution()
{
	// peut être opti
	if (!_pcp.empty())
	{
		std::string top;
		std::string bottom;
		for (std::size_t i = 0; i < _length; i++)
		{
			Pcp_bloc bloc = _pcp[i];
			top += bloc.get_top();
			bottom += bloc.get_bottom();
		}
		return (top == bottom);
	}
	return (false);
}

bool Pcp_solution::is_bloc_possible(Pcp_bloc &bloc)
{
	size_t size;
	if (!_pcp.empty())
	{
		std::string top;
		std::string bottom;
		for (std::size_t i = 0; i < _length; i++)
		{
			Pcp_bloc b = _pcp[i];
			top += b.get_top();
			bottom += b.get_bottom();
		}
		top += bloc.get_top();
		bottom += bloc.get_bottom();
		size = MIN(top.length(), bottom.length());
		return (!top.compare(0, size, bottom, 0, size));
	}
	return (bloc.has_prefix());
}

void Pcp_solution::push(Pcp_bloc bloc)
{
	_pcp.push_back(bloc);
	_length += 1;
}

void Pcp_solution::pop()
{
	if (!_pcp.empty())
	{
		_pcp.pop_back();
		_length -= 1;
	}
}


bool Pcp_solution::solve(int depth, Pcp_instance instance = Pcp_instance(6, 6)){
    if (is_solution())
    {
        std::cout << "SOLUTION SIZE = " << _pcp.size() << std::endl;
        // write in db
        return true;
    }
        //else if (pcp.get_length() == LENGTH)
    else if (depth == 0)
    {
        // pas de solution trouvé
        std::cout << "pas de solution taille length" << std::endl;
        return false;
    }
    for (Pcp_bloc bloc : instance.getInstance())
    {
        if (is_bloc_possible(bloc))
        {
            push(bloc);
            solve(depth -1, instance);
            pop();
            //solve(depth -1, instance);
        }
    }
}



std::string Pcp_solution::stringify() {
    std::string res;
    Pcp_bloc bloc;
    for (int i = 0; i < _length; i++){
        Pcp_bloc bloc = _pcp[i];
        res += bloc.get_top() + "," + bloc.get_bottom() + ",";
    }
    res.pop_back(); //removes last ','
    return res;
}


void Pcp_solution::write_instance() {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("localhost", "PCPadmin", "AXaHUKc])n2D%t*\"T6Ve");
        con->setSchema("PCP");

        stmt = con->createStatement();
        stmt->execute("INSERT INTO instances(pairs, sol_len) VALUES ('" + stringify() + "', '" + std::to_string(_pcp.size())+ "')");

        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line "
                  << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}


bool Pcp_solution::is_in_db() {
    try {
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
    catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line "
                  << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}


std::ostream& operator<< (std::ostream& out,  Pcp_solution& v){
	out << "[ "; for (auto x: v._pcp) out << x << ' '; out << ']';
	return out;
}
