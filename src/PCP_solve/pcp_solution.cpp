#include "pcp_solution.h"

bool Pcp_solution::is_solution()
{
	// peut être opti
	if (!_pcp.empty())
	{
		std::string top;
		std::string bottom;
		for (std::size_t i = 0; i < _pcp.size(); i++)
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
		for (Pcp_bloc b : _pcp)
		{
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
}

void Pcp_solution::pop()
{
	if (!_pcp.empty())
		_pcp.pop_back();
}

bool Pcp_solution::solve(int depth, Pcp_instance instance)
{
    if (is_solution())
    {
		/*
		if (_pcp.size() < _best )
		{
			_best_pcp = _pcp;
			_best = _pcp.size();
		}
		std::cout << "SOLUTION SIZE = " << _pcp.size() << std::endl;
		 */
		return (true);
    }
	else if (depth == 0)
		return (false);
    for (Pcp_bloc bloc : instance.getInstance())
    {
		if (is_bloc_possible(bloc))
		{
			if (!(_pcp.size() == 0 && bloc == Pcp_bloc("01", "0")))
				push(bloc);
			if (solve(depth - 1, instance))
				return (true);
			pop();
		}
    }
    return (false);
}

# define Final_Threshold 100
# define Starting_Threshold 10
# define Depth_increment 20

bool Pcp_solution::iterative_solve(Pcp_instance instance) {
	int threshold = Starting_Threshold;

    bool res;
    do{
        res = solve(threshold, instance);
		threshold+= Depth_increment;
    } while (!res && threshold <= Final_Threshold);
    return res;
}

std::ostream& operator<< (std::ostream& out,  Pcp_solution& v){
	out << "[ "; for (auto x: v._pcp) out << x << ' '; out << ']';
	//out << "[ "; for (auto x: v._best_pcp) out << x << ' '; out << ']';
	return out;
}
