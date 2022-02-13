#ifndef PCP_SOLVING_H
#define PCP_SOLVING_H


#include "pcp_bloc.h"

class Pcp_instance{

	unsigned int _lenght;				// nombre de bloc
	unsigned int _width; 				// longueur de la plus grande string
	std::vector<Pcp_bloc> _instance;	// liste des blocs

public:
	Pcp_instance(unsigned int lenght, unsigned int width) : _lenght(lenght), _width(width) {}
	Pcp_instance(std::initializer_list<std::string>);
	bool prefix_filter();
	bool length_balance_filter();
	bool element_balance_filter();

};

#endif
