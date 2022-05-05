#include "pcp_instance.h"
#include "pcp_solution.h"

Pcp_instance::Pcp_instance(std::initializer_list<std::string> blocs) : _size(blocs.size()/2), _instance(blocs.size()/2, Pcp_bloc()), _top_mask(0), _bot_mask(0)
{
	auto bloc = blocs.begin();
	for (std::size_t i = 0; i < _size; i++)
	{
		_instance[i] = Pcp_bloc(*bloc, *(bloc+1));
		bloc += 2;
	}
	create_reversal();
}

Pcp_instance::Pcp_instance(unsigned int size, unsigned int width) : _size(size), _top_mask(0), _bot_mask(0)
{
	for (unsigned int i = 0; i < _size; i++){
		Pcp_bloc bloc = Pcp_bloc();
		bloc.generate_blocs(width);
		_instance.push_back(bloc);
		size_t len;
		len = MAX(bloc.get_top().length(), bloc.get_bottom().length());
		if ( len > _width)
			_width = len;
	}
	create_reversal();
}

bool Pcp_instance::has_symetrical()
{
	for (unsigned int i = 0; i < _size ; i++)
	{
		for (unsigned int j = 0; j < _size ; j++)
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

void Pcp_instance::strip_duplicate(){
    for (unsigned int i = 0; i < _instance.size() ; i++)
    {
        for (unsigned int j = i; j < _instance.size() ; j++)
        {
            if (i != j && _instance[i].get_top() == _instance[j].get_top() && _instance[i].get_bottom() == _instance[j].get_bottom()){
                _instance.erase(_instance.begin() + j);
                j--;
            }
        }
    }
}

bool Pcp_instance::prefix_filter()
{
	for (unsigned int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())
			return (false);
	}
	return (true);
}

bool Pcp_instance::length_balance_filter()
{
	for (unsigned int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())																		  // le bloc i peut être placé en premier
		{
			for (unsigned int j = 0; j < _size; j++)
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
	for (unsigned int i = 0; i < _size ; i++)
	{
		if (_instance[i].has_prefix())																		   // le bloc i peut être placé en premier
		{
			for (unsigned int j = 0; j < _size; j++)
			{
				if ( j != i && _instance[j].top_less_bottom_ones() + _instance[i].top_less_bottom_ones() <= 0) // il existe un autre bloc qui contrebalance le nombre de 1
					return (false);
			}
		}
	}
	return (true);
}

void	Pcp_instance::mask_top()
{
	// a) search for larger bot string

	std::vector<Pcp_bloc> config_top;

	for (Pcp_bloc bbot : _instance)
	{
		if (bbot.get_bottom().size() > bbot.get_top().size())  // bloc larger bottom
		{
			std::string config;
			std::string copy;
			for (int i = 0; i < bbot.bot_less_top_len() ; i++ )
			{
				config.append(1, bbot.get_bottom()[i]);
			}
			copy = config;
			if (copy.append(bbot.get_top()) == bbot.get_bottom())
			{
				reverse(config.begin(), config.end());
				//std::cout << "config" << config << std::endl;
				Pcp_bloc bruh = Pcp_bloc(config, "");
				config_top.push_back(bruh);
			}
		}
	}
	// b) find fully matched string
	bool	pushable;
	pushable = 0;
	for (Pcp_bloc confi : config_top)
	{
		for (Pcp_bloc bloc: _reversal)
		{
			if (perfect_match(confi, bloc))
			{
				//std::cout << "bloc" << bloc << std::endl;
				pushable = 1;
				break;
			}
		}
		if (pushable == 0)
		{
			//std::cout << "confi" << confi << std::endl;
			_top_mask = 1;
		}
	}
}


void	Pcp_instance::mask_bot()
{
	// a) search for larger bot string

	std::vector<Pcp_bloc> config_bot;

	for (Pcp_bloc btop : _instance)
	{
		if (btop.get_bottom().size() < btop.get_top().size())  // bloc larger bottom
		{
			std::string config;
			std::string copy;
			for (int i = 0; i < btop.top_less_bottom_len() ; i++ )
			{
				config.append(1, btop.get_top()[i]);
			}
			copy = config;
			if (copy.append(btop.get_bottom()) == btop.get_top())
			{
				reverse(config.begin(), config.end());
				Pcp_bloc bruh = Pcp_bloc(config, "");
				config_bot.push_back(bruh);
			}
		}
	}
	// b) find fully matched string
	bool	pushable;
	pushable = 0;
	for (Pcp_bloc confi : config_bot)
	{
		for (Pcp_bloc bloc: _reversal)
		{
			if (perfect_match(confi, bloc))
			{
				pushable = 1;
				break;
			}
		}
		if (pushable == 0)
		{
			_bot_mask = 1;
		}
	}
}

bool	Pcp_instance::perfect_match(Pcp_bloc a, Pcp_bloc b)
{
	return (a.get_top() + b.get_top() == a.get_bottom() + b.get_bottom());
}

std::ostream& operator<< (std::ostream& out,  Pcp_instance& v){
	out << "[ "; for (auto x: v._instance) out << x << ' '; out << ']';
	//out << "[ "; for (auto x: v._reversal) out << x << ' '; out << ']';
	return out;
}


void	Pcp_instance::create_reversal()
{
	Pcp_bloc	rev;
	std::string	copy_top;
	std::string	copy_bot;

	for (Pcp_bloc bloc : _instance)
	{
		copy_top = bloc.get_top();
		copy_bot = bloc.get_bottom();
		reverse(copy_bot.begin(), copy_bot.end());
		reverse(copy_top.begin(), copy_top.end());
		rev = Pcp_bloc(copy_top, copy_bot);
		_reversal.push_back(rev);
	}
}
