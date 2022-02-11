#ifndef PCP_SOLVING_H
#define PCP_SOLVING_H

#define ABS(Value) (Value < 0) ? - (Value) : (Value)
#define MAX(a,b) ((a)>(b)?(a):(b))

#include <cstring>
#include <iostream>




class Pcp_instance{
	Pcp_instance(unsigned int p_lenght, unsigned int p_width)	: _lenght(p_lenght), _width(p_width) {}

	unsigned int _lenght;			// nombre de bloc
	unsigned int _width; 			// longueur de la plus grande string
	Pcp_bloc _instance[];			// liste des blocs

public:
	//
	unsigned int excess_one();
};

#endif
