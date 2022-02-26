#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"


int main(void)
{
	Pcp_solution pcp = Pcp_solution();
    //Pcp_instance instance = Pcp_instance(2, 6);
    Pcp_instance instance = {"1", "111", "10111", "10", "10", "0"};

	Pcp_instance instance2 = {"10", "0", "0", "000", "00", "01"};		// has length 10 solution
    std::cout << instance << std::endl;

	Pcp_solution solution;
	//solution.solve(instance2);
	//solution.solve(0, instance2);

	srand(time(0));		// set random seed

	int i = 100;
	while (i--)
	{
		Pcp_instance inst = Pcp_instance(4, 4);
		if (!(inst.length_balance_filter()  || inst.element_balance_filter()  || inst.prefix_filter()))			// instance can have solution
		{
			std::cout << "rand instance " << i  << " : " << inst << std::endl;
			Pcp_solution pcp = Pcp_solution();
			if (pcp.solve(0, inst))
			{
				std::cout << "solution" << pcp << std::endl;
				// write in db
			}
		}
	}
	//bool res = pcp.is_in_db();
    //std::cout << res << std::endl;
}



