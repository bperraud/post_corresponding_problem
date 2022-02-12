#include "pcp_bloc.h"

Pcp_bloc::Pcp_bloc(std::string top, std::string bottom)
{
	_top = top;
	_bottom = bottom;
	_width = MAX(top.length(), bottom.length());
}

bool Pcp_bloc::has_prefix()
{
	return !_top.compare(0, ABS( _width - top_less_bottom()), _bottom);
}



