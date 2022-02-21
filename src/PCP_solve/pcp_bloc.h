#ifndef PCP_BLOC_H
#define PCP_BLOC_H

#define ABS(Value) (Value < 0) ? - (Value) : (Value)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Pcp_bloc {
	std::string		_top;				// string du haut
	std::string		_bottom;			// string du bas
	unsigned int	_width;				// longueur de la plus grande string

public:
	Pcp_bloc() noexcept = default;
	Pcp_bloc (std::string, std::string);
	// Getters
	std::string get_top() {return _top;}
	std::string get_bottom() {return _bottom;}
	// Utils
	bool has_prefix();
	inline int top_less_bottom_len() {return _top.size() - _bottom.size();}
	inline int top_less_bottom_ones() {return std::count(_top.begin(), _top.end(), '1') - std::count(_bottom.begin(), _bottom.end(), '1');}

	friend std::ostream& operator<< (std::ostream&, Pcp_bloc&);
};

#endif
