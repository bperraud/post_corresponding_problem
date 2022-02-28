#include "pcp_solution.h"

bool Pcp_solution::is_solution()
{
	// peut être opti
	if (!_pcp.empty())
	{
		std::string top;
		std::string bottom;
		for (std::size_t i = 0; i < _pcp.size(); i++)
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
		for (Pcp_bloc b : _pcp)
		{
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
}

void Pcp_solution::pop()
{
	if (!_pcp.empty())
		_pcp.pop_back();
}

bool Pcp_solution::solve(int depth, Pcp_instance instance)
{
    if (is_solution())
    {
		if (_pcp.size() < _best )
		{
			_best_pcp = _pcp;
			_best = _pcp.size();
		}
        std::cout << "SOLUTION SIZE = " << _pcp.size() << std::endl;
        return (true);
    }
	else if (depth == 0)
		return (false);
    for (Pcp_bloc bloc : instance.getInstance())
    {
		if (is_bloc_possible(bloc))
		{
			push(bloc);
			if (solve(depth - 1, instance))
				return (true);
			pop();
		}
    }
    return (false);
}

std::ostream& operator<< (std::ostream& out,  Pcp_solution& v){
	//out << "[ "; for (auto x: v._pcp) out << x << ' '; out << ']';
	out << "[ "; for (auto x: v._best_pcp) out << x << ' '; out << ']';
	return out;
}

/*
std::string Pcp_solution::stringify() {
    std::string res;
    Pcp_bloc bloc;
    for (int i = 0; i < _pcp.size(); i++){
        Pcp_bloc bloc = _pcp[i];
        res += bloc.get_top() + "," + bloc.get_bottom() + ",";
    }
    if (res.size() > 0) res.pop_back(); //removes last ','
    return res;
}

void Pcp_solution::write_instance() {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        // Create a connection
        driver = get_driver_instance();
        con = driver->connect("pcp.digitelstudios.lu:3306", "pcp-user", "86Ex$y3s");
        con->setSchema("pcp-db");

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
    //std::cout << "here then 1";
    try {
        //std::cout << "here then";
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        bool is_in_db = false;

        // Create a connection
        driver = get_driver_instance();
        //std::cout << "here";
        con = driver->connect("pcp.digitelstudios.lu:3306", "pcp-user", "86Ex$y3s");
        con->setSchema("pcp-db");
        //std::cout << "there";
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
    catch (std::bad_alloc &e){
        std::cout << "error in the block" << std::endl;
    }
    return false;
}
 */


