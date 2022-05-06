#ifndef PCP_BLOC_H
#define PCP_BLOC_H

#define ABS(Value) (Value < 0) ? - (Value) : (Value)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

class Pcp_bloc {
	std::string		_top;				// string du haut
	std::string		_bottom;			// string du bas
	unsigned int	_width;				// longueur de la plus grande string

public:
	Pcp_bloc() noexcept = default;
	Pcp_bloc (std::string, std::string);
	/* getters */
	std::string get_top() {return _top;}
	std::string get_bottom() {return _bottom;}
	/* utils */
	bool has_prefix();
	inline int top_less_bottom_len() {return _top.size() - _bottom.size();}
	inline int bot_less_top_len() {return _bottom.size() - _top.size();}
	inline int top_less_bottom_ones() {return std::count(_top.begin(), _top.end(), '1') - std::count(_bottom.begin(), _bottom.end(), '1');}
	void generate_blocs(int);
	/* operators */
	friend bool operator==(const Pcp_bloc& left, const Pcp_bloc& right);
	/* output */
	friend std::ostream& operator<< (std::ostream&, Pcp_bloc&);
};

#endif
