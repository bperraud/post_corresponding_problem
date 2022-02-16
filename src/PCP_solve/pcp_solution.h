#ifndef PCP_SOLUTION_H
#define PCP_SOLUTION_H

#include "pcp_bloc.h"

class Pcp_solution {
	unsigned int _lenght;				// nombre de bloc
	//unsigned int _width; 				// longueur de la plus grande string
	std::vector<Pcp_bloc> _pcp			// liste des blocs actuellement en place

public:
	bool is_solution();

};

#endif
