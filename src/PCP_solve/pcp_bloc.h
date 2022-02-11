#ifndef PCP_BLOC_H
#define PCP_BLOC_H


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



#endif
