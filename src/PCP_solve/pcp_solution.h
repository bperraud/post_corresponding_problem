#ifndef PCP_SOLUTION_H
#define PCP_SOLUTION_H

#include "pcp_bloc.h"
#include "pcp_instance.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>

class Pcp_solution {
	std::vector<Pcp_bloc> _pcp;				// liste des blocs actuellement en place
	std::vector<Pcp_bloc> _best_pcp;
	size_t	_best;

public:
	Pcp_solution (int best = 1000) {_best = best; }
	inline size_t get_length(){ return _best; }
    inline int get_sol_size(){return _pcp.size();}
	bool is_bloc_possible(Pcp_bloc &bloc);
	bool is_solution();
	void push(Pcp_bloc);
	void pop();
	bool solve(int, Pcp_instance);

    bool iterative_solve(Pcp_instance);

	friend std::ostream& operator<< (std::ostream&, Pcp_solution&);
};

#endif
