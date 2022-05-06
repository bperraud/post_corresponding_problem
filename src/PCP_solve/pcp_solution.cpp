#include "pcp_solution.h"

bool Pcp_solution::is_solution()
{
	int top;
	int bottom;

	if (!_pcp.empty())
	{
		top = 0;
		bottom = 0;
		for (std::size_t i = 0; i < _pcp.size(); i++)
		{
			Pcp_bloc bloc = _pcp[i];
			top += bloc.get_top().size();
			bottom += bloc.get_bottom().size();
		}
		return (top == bottom);
	}
	return (false);
}

bool Pcp_solution::is_bloc_possible(Pcp_bloc &bloc)
{
	size_t	size;
	bool	ret;

	if (_pcp.empty())
	{
		 if (_top_mask && bloc.top_less_bottom_len() > 0)
		 {
			 //std::cout << "top mask" << std::endl;
			 return (false);
		 }
		if (_bot_mask && bloc.bot_less_top_len() > 0)
		{
			//std::cout << "bot mask" << std::endl;
			return (false);
		}
	}
	else
	{
		push(bloc);
		size = MIN(_top_string.length(), _bot_string.length());
		ret = !_top_string.compare(0, size, _bot_string, 0, size);
		pop();
		return (ret);
	}
	return (bloc.has_prefix());
}

void Pcp_solution::push(Pcp_bloc bloc)
{
	_pcp.push_back(bloc);
	_top_string.append(bloc.get_top());
	_bot_string.append(bloc.get_bottom());
}

void Pcp_solution::pop()
{
	Pcp_bloc bloc;

	if (!_pcp.empty())
	{
		bloc = _pcp.back();
		for (unsigned int i = 0; i < bloc.get_top().size() ; i++)
			_top_string.pop_back();
		for (unsigned int i = 0; i < bloc.get_bottom().size() ; i++)
			_bot_string.pop_back();
		_pcp.pop_back();
	}
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
			push(bloc);
			if (solve(depth - 1, instance))
				return (true);
			pop();
		}
    }
    return (false);
}

/*
bool Pcp_solution::iterative_solve(Pcp_instance instance) {
	int it_depth[3] = {4, 7, 20};

	//int it_depth[3] = {3, 6, 20};

	int idx = 0;
	bool res;
	do{
		res = solve(it_depth[idx], instance);
		idx++;
	} while (!res && idx <= 2);

	return res;

}
 */

# define Final_Threshold 20
# define Starting_Threshold 2
// 10 in article
# define Depth_increment 5
// best for seed 1 = 5
// 20 in article
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
