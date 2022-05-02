#include "pcp_bloc.h"

Pcp_bloc::Pcp_bloc(std::string top, std::string bottom)
{
	_top = top;
	_bottom = bottom;
	_width = MAX(top.length(), bottom.length());
}

bool Pcp_bloc::has_prefix()
{
	int size = _width - (ABS(top_less_bottom_len()));
	return !_top.compare(0, size, _bottom, 0, size);
}

bool operator==(const Pcp_bloc& left, const Pcp_bloc& right)
{
	return (left._top == right._top && left._bottom == right._bottom);
}

std::ostream& operator<< (std::ostream& out,  Pcp_bloc& v){
	out << '[' << v._top << '/' << v._bottom << ']';
	return out;
}

void Pcp_bloc::generate_blocs(int max_len){
    int len = rand() % max_len + 1; //no empty string
    std::string top;
    int bin_gen;
    for (int i = 0; i < len; i++)
	{
        bin_gen = rand() % 2;
        top.append(std::to_string(bin_gen));
    }
    len = rand() % max_len + 1;
    std::string bot;
    for (int i = 0; i < len; i++)
	{
        bin_gen = rand() % 2;
        bot.append(std::to_string(bin_gen));
    }
    _top = top;
    _bottom = bot;
	if (_top == _bottom)
		_top[0] = (_top[0] == '0' ? '1' : '0' );
	_width = MAX(_top.length(), _bottom.length());
}

