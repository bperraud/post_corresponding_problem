#ifndef PCP_SOLVING_H
#define PCP_SOLVING_H


#include "pcp_bloc.h"

class Pcp_instance{

	unsigned int _length;				// nombre de bloc
	unsigned int _width; 				// longueur de la plus grande string
	std::vector<Pcp_bloc> _instance;	// liste des blocs
    unsigned int sol_len = 0;

public:
	Pcp_instance(unsigned int length, unsigned int width) : _length(length), _width(width) {}
	Pcp_instance(std::initializer_list<std::string>);
	bool prefix_filter();
	bool length_balance_filter();
	bool element_balance_filter();
    std::string stringify();
    void write_instance();
    bool is_in_db();

};

#endif
