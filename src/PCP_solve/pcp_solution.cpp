#include "pcp_solution.h"


bool Pcp_solution::is_solution()
{
	// peut être opti
	if (!_pcp.empty())
	{
		std::string top;
		std::string bottom;
		for (std::size_t i = 0; i < _length; i++)
		{
			Pcp_bloc bloc = _pcp[i];
			top += bloc.get_top();
			bottom += bloc.get_bottom();
		}
		return (top == bottom);
	}
	return (false);
}

bool Pcp_solution::is_bloc_possible(Pcp_bloc &bloc)
{
	size_t size;
	if (!_pcp.empty())
	{
		std::string top;
		std::string bottom;
		for (std::size_t i = 0; i < _length; i++)
		{
			Pcp_bloc b = _pcp[i];
			top += b.get_top();
			bottom += b.get_bottom();
		}
		top += bloc.get_top();
		bottom += bloc.get_bottom();
		size = MIN(top.length(), bottom.length());
		return (!top.compare(0, size, bottom, 0, size));
	}
	return (bloc.has_prefix());
}

void Pcp_solution::push(Pcp_bloc bloc)
{
	_pcp.push_back(bloc);
	_length += 1;
}

void Pcp_solution::pop()
{
	if (!_pcp.empty())
	{
		_pcp.pop_back();
		_length -= 1;
	}
}

std::ostream& operator<< (std::ostream& out,  Pcp_solution& v){
	out << "[ "; for (auto x: v._pcp) out << x << ' '; out << ']';
	return out;
}
