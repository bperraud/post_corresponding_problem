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
        return (true);
    }
	else if (depth == 0)
		return (false);
    for (Pcp_bloc bloc : instance.getInstance())
    {
		if (is_bloc_possible(bloc))
		{
			push(bloc);
			if (solve(depth - 1, instance))
				return (true);
			pop();
		}
    }
    return (false);
}

bool Pcp_solution::iterative_solve(Pcp_instance instance) {
    int it_depth[3] = {4, 7, 15};
    int idx = 0;
    bool res;
    do{
        res = solve(it_depth[idx], instance);
        idx++;
    } while (!res && idx <= 2);

    return res;

}

std::ostream& operator<< (std::ostream& out,  Pcp_solution& v){
	//out << "[ "; for (auto x: v._pcp) out << x << ' '; out << ']';
	out << "[ "; for (auto x: v._best_pcp) out << x << ' '; out << ']';
	return out;
}






