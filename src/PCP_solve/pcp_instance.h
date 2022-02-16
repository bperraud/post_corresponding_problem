#ifndef PCP_SOLVING_H
#define PCP_SOLVING_H


#include "pcp_bloc.h"

class Pcp_instance {
	const unsigned int _size;					// nombre de bloc
	const unsigned int _width; 					// longueur de la plus grande string
	const std::vector<Pcp_bloc> _instance;		// liste des blocs

public:
	Pcp_instance(unsigned int size, unsigned int width) : _size(size), _width(width) {}
	Pcp_instance(std::initializer_list<std::string>);
	bool prefix_filter();
	bool length_balance_filter();
	bool element_balance_filter();
    std::string stringify();
    void write_instance();
    bool is_in_db();

};

#endif
