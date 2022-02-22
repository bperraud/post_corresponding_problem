#include "pcp_bloc.h"
#include <random>

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

std::ostream& operator<< (std::ostream& out,  Pcp_bloc& v){
	out << '[' << v._top << '/' << v._bottom << ']';
	return out;
}

std::string generate_blocs(int max_len){
    int len = rand() % max_len;
    std::string top;
    int bin_gen;
    for (int i = 0; i < len){
        bin_gen = rand() % 2;
        top.append(std::to_string(bin_gen));
    }

    len = rand() % max_len;
    std::string bot;
    for (int i = 0; i < len){
        bin_gen = rand() % 2;
        bot.append(std::to_string(bin_gen));
    }

    _top = top;
    _bot = bot;
}

