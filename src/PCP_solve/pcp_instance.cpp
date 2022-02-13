#include "pcp_instance.h"


Pcp_instance::Pcp_instance(std::initializer_list<std::string> blocs) : _lenght(blocs.size()/2), _instance(blocs.size()/2, Pcp_bloc())
{
	auto bloc = blocs.begin();
	for (std::size_t i = 0; i < _lenght; ++i)
	{
		_instance[i] = Pcp_bloc(*bloc, *(bloc+1));
		bloc += 2;
		std::cout << "top : " << (_instance[i].get_top()) << " " ;
		std::cout << "bottom : " << (_instance[i].get_bottom()) << std::endl;
		std::cout << "hasprefix : " << _instance[i].has_prefix()  << std::endl;
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
		//std::cout << "hasprefix" << _instance[i].has_prefix()  << std::endl;
		if (_instance[i].has_prefix())		// si le bloc i peut être placé en premier
		{
			for (int j = 0; j < _lenght; j++)
			{
				std::cout << " diff " << i << j << _instance[i].top_less_bottom() - _instance[j].top_less_bottom() << std::endl;

				if ( j != i && _instance[i].top_less_bottom() - _instance[j].top_less_bottom() == 0)
					return (true);
			}
		}
	}
	return (false);
}


bool Pcp_instance:: element_balance_filter()
{
	return (true);
}












