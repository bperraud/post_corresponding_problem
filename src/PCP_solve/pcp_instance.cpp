#include "pcp_instance.h"


Pcp_instance::Pcp_instance(std::initializer_list<std::string> blocs) : _lenght(blocs.size()/2), _instance(blocs.size()/2, Pcp_bloc())
{
	auto bloc = blocs.begin();
	for (std::size_t i = 0; i < _lenght; i++)
	{
		_instance[i] = Pcp_bloc(*bloc, *(bloc+1));
		bloc += 2;
	}
}


bool Pcp_instance::prefix_filter()
{
	for (int i = 0; i < _lenght ; i++)
	{
		if (_instance[i].has_prefix())
			return (false);
	}
	return (true);
}


bool Pcp_instance::length_balance_filter()
{
	for (int i = 0; i < _lenght ; i++)
	{
		if (_instance[i].has_prefix())		// si le bloc i peut être placé en premier
		{
			for (int j = 0; j < _lenght; j++)
			{
				if ( j != i && _instance[j].top_less_bottom() + _instance[i].top_less_bottom(); < 0)
					return (false);
			}
		}
	}
	return (true);
}


bool Pcp_instance:: element_balance_filter()
{
	return (true);
}












