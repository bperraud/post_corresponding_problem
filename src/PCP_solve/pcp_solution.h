#ifndef PCP_SOLUTION_H
#define PCP_SOLUTION_H

#include "pcp_bloc.h"

class Pcp_solution {
	unsigned int _length;				// nombre de bloc
	//unsigned int _width; 				// longueur de la plus grande string
	std::vector<Pcp_bloc> _pcp;			// liste des blocs actuellement en place

public:
	Pcp_solution() noexcept = default;
	inline unsigned int get_length(){ return _length; }
	bool is_bloc_possible(Pcp_bloc &bloc);
	bool is_solution();
	void push(Pcp_bloc bloc);
	void pop();

	friend std::ostream& operator<< (std::ostream&, Pcp_solution&);
};

#endif
