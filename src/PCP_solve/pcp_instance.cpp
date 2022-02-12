#include "pcp_instance.h"


Pcp_instance::Pcp_instance(std::initializer_list<std::string> blocs) : _width(blocs.size()/2), _instance(blocs.size()/2, Pcp_bloc())
{
	auto bloc = blocs.begin();
	for (std::size_t i = 0; i < _width; ++i)
		_instance[i] = Pcp_bloc(*bloc++, *bloc++);
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
	int good_balance = 0;
	for (int i = 0; i < _lenght ; i++)
	{
		if (_instance[i].has_prefix())
		{
			for (int j = 0; j < _lenght; j++)
			{
				if (j != i)
				{
					if (_instance[i].top_less_bottom() - _instance[j].top_less_bottom() == 0)
						good_balance += 1;
				}
			}
		}
	}
	return (good_balance > 0);
}


bool Pcp_instance:: element_balance_filter()
{
	return (true);
}












