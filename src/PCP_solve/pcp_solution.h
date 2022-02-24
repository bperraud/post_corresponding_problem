#ifndef PCP_SOLUTION_H
#define PCP_SOLUTION_H

#include "pcp_bloc.h"
#include "pcp_instance.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>

class Pcp_solution {
	unsigned int _length = 0;				// nombre de bloc
	//unsigned int _width; 				// longueur de la plus grande string
	std::vector<Pcp_bloc> _pcp;			// liste des blocs actuellement en place

public:
	Pcp_solution() noexcept = default;
	inline unsigned int get_length(){ return _length; }
	bool is_bloc_possible(Pcp_bloc &bloc);
	bool is_solution();
	void push(Pcp_bloc bloc);
	void pop();

    bool solve(int depth, Pcp_instance instance);

    std::string stringify();
    void write_instance();
    bool is_in_db();

	friend std::ostream& operator<< (std::ostream&, Pcp_solution&);
};

#endif
