#ifndef PCP_BLOC_H
#define PCP_BLOC_H


#define ABS(Value) (Value < 0) ? - (Value) : (Value)
#define MAX(a,b) ((a)>(b)?(a):(b))

#include <string>
#include <vector>
#include <iostream>

class Pcp_bloc{

	std::string		_top;				// string du haut
	std::string		_bottom;			// string du bas
	unsigned int	_width;

public:
	Pcp_bloc() noexcept = default;
	Pcp_bloc (std::string, std::string);
	// Getters
	std::string get_top() {return _top;}
	std::string get_bottom() {return _bottom;}
	// Utils
	bool has_prefix();
	inline int top_less_bottom() {return (_top.length() - _bottom.length());}

};


#endif
