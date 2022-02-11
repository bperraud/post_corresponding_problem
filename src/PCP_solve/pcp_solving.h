#ifndef INFOF308_PCP_SOLVING_H
#define INFOF308_PCP_SOLVING_H

#define ABS(Value) (Value < 0) ? - (Value) : (Value)
#define MAX(a,b) ((a)>(b)?(a):(b))

#include <cstring>
#include <iostream>

class Pcp_bloc{

	const char*		_top;				// string du haut
	const char*		_bottom;			// string du bas
	unsigned int	_width;

public:
	Pcp_bloc (const char* top, const char* bottom);
	// Getters
	inline const char* get_top() {return _top;}
	inline const char* get_bottom() {return _bottom;}
	// Utils
	bool has_prefix();
	inline int top_less_bottom() {return (strlen(_top) - strlen(_bottom));}


};


class Pcp_instance{
	Pcp_instance(unsigned int p_lenght, unsigned int p_width)	: _lenght(p_lenght), _width(p_width) {}

	unsigned int _lenght;			// nombre de bloc
	unsigned int _width; 			// longueur de la plus grande string
	Pcp_bloc _instance[];			// liste des blocs

public:
	//
};

#endif //INFOF308_PCP_SOLVING_H
