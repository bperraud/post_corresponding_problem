#include "pcp_instance.h"

Pcp_instance::Pcp_instance(std::initializer_list<std::string> blocs) : _size(blocs.size()/2), _instance(blocs.size()/2, Pcp_bloc())
{
	auto bloc = blocs.begin();
	for (std::size_t i = 0; i < _size; i++)
	{
		_instance[i] = Pcp_bloc(*bloc, *(bloc+1));
		bloc += 2;
	}
}

Pcp_instance::Pcp_instance(unsigned int size, unsigned int width) : _size(size)
{
	for (int i = 0; i < _size; i++){
		Pcp_bloc bloc = Pcp_bloc();
		bloc.generate_blocs(width);
		_instance.push_back(bloc);
		size_t len;
		len = MAX(bloc.get_top().length(), bloc.get_bottom().length());
		if ( len > _width)
			_width = len;
	}
}

bool Pcp_instance::has_symetrical()
{
	for (int i = 0; i < _size ; i++)
	{
		for (int j = 0; j < _size ; j++)
		{
			std::string top;
			std::string bot;
			if (i != j)
			{
				top += _instance[i].get_top();
				top += _instance[j].get_top();;
				bot += _instance[i].get_bottom();;
				bot += _instance[j].get_bottom();
				if (top == bot)
					return (true);
			}
		}
	}
	return (false);
}

void Pcp_instance::strip_duplicate(){
    for (int i = 0; i < _instance.size() ; i++)
    {
        for (int j = i; j < _instance.size() ; j++)
        {
            if (i != j && _instance[i].get_top() == _instance[j].get_top() && _instance[i].get_bottom() == _instance[j].get_bottom()){
                _instance.erase(_instance.begin() + j);
                j--;
            }
        }
    }
}


bool Pcp_instance::prefix_filter()
{
	for (int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())
			return (false);
	}
	return (true);
}

bool Pcp_instance::length_balance_filter()
{
	for (int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())																		  // le bloc i peut être placé en premier
		{
			for (int j = 0; j < _size; j++)
			{
				if ( j != i && _instance[j].top_less_bottom_len() + _instance[i].top_less_bottom_len() <= 0)  // il existe un autre bloc qui contrebalance la longueur de la plus grande string
					return (false);
			}
		}
	}
	return (true);
}

bool Pcp_instance::element_balance_filter()
{
	for (int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())																		   // le bloc i peut être placé en premier
		{
			for (int j = 0; j < _size; j++)
			{
				if ( j != i && _instance[j].top_less_bottom_ones() + _instance[i].top_less_bottom_ones() <= 0) // il existe un autre bloc qui contrebalance le nombre de 1
					return (false);
			}
		}
	}
	return (true);
}


std::string Pcp_instance::stringify() {
    std::string res;
    Pcp_bloc bloc;
    for (int i = 0; i < _instance.size(); i++){
        Pcp_bloc bloc = _instance[i];
        res += bloc.get_top() + "," + bloc.get_bottom() + ",";
    }
    if (res.size() > 0) res.pop_back(); //removes last ','
    return res;
}

void Pcp_instance::write_instance(int level, int size) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        // Create a connection
        driver = get_driver_instance();
        con = driver->connect("pcp.digitelstudios.lu:3306", "pcp-user", "86Ex$y3s");
        con->setSchema("pcp-db");

        stmt = con->createStatement();
        stmt->execute("INSERT INTO instances(pairs, sol_len, level) VALUES ('" + stringify() + "', '" + std::to_string(size)+ "', '" + std::to_string(level) + "')");

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


bool Pcp_instance::is_in_db() {
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


std::ostream& operator<< (std::ostream& out,  Pcp_instance& v){
	out << "[ "; for (auto x: v._instance) out << x << ' '; out << ']';
	return out;
}
