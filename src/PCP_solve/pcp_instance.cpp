#include "pcp_instance.h"

Pcp_instance::Pcp_instance(std::initializer_list<std::string> blocs) : _size(blocs.size()/2), _instance(blocs.size()/2, Pcp_bloc())
{
	auto bloc = blocs.begin();
	for (std::size_t i = 0; i < _size; i++)
	{
		_instance[i] = Pcp_bloc(*bloc, *(bloc+1));
		bloc += 2;
	}
}

Pcp_instance::Pcp_instance(unsigned int size, unsigned int width) : _size(size)
{
	for (int i = 0; i < _size; i++){
		Pcp_bloc bloc = Pcp_bloc();
		bloc.generate_blocs(width);
		_instance.push_back(bloc);
		size_t len;
		len = MAX(bloc.get_top().length(), bloc.get_bottom().length());
		if ( len > _width)
			_width = len;
	}
}

bool Pcp_instance::has_symetrical()
{
	for (int i = 0; i < _size ; i++)
	{
		for (int j = 0; j < _size ; j++)
		{
			std::string top;
			std::string bot;
			if (i != j)
			{
				top += _instance[i].get_top();
				top += _instance[j].get_top();;
				bot += _instance[i].get_bottom();;
				bot += _instance[j].get_bottom();
				if (top == bot)
					return (true);
			}
		}
	}
	return (false);
}

bool Pcp_instance::prefix_filter()
{
	for (int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())
			return (false);
	}
	return (true);
}

bool Pcp_instance::length_balance_filter()
{
	for (int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())																		  // le bloc i peut être placé en premier
		{
			for (int j = 0; j < _size; j++)
			{
				if ( j != i && _instance[j].top_less_bottom_len() + _instance[i].top_less_bottom_len() <= 0)  // il existe un autre bloc qui contrebalance la longueur de la plus grande string
					return (false);
			}
		}
	}
	return (true);
}

bool Pcp_instance::element_balance_filter()
{
	for (int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())																		   // le bloc i peut être placé en premier
		{
			for (int j = 0; j < _size; j++)
			{
				if ( j != i && _instance[j].top_less_bottom_ones() + _instance[i].top_less_bottom_ones() <= 0) // il existe un autre bloc qui contrebalance le nombre de 1
					return (false);
			}
		}
	}
	return (true);
}

std::ostream& operator<< (std::ostream& out,  Pcp_instance& v){
	out << "[ "; for (auto x: v._instance) out << x << ' '; out << ']';
	return out;
}
