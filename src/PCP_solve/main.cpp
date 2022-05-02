#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"

# define ITERATION 10000000

void generate_instance(int instance_size, int instance_width, int depth, int hard_mode = 0)
{
	int i = 0;

	while (i++ < ITERATION)
	{
	    std::cout << i << std::endl;
		Pcp_instance inst = Pcp_instance(instance_size, instance_width);
        inst.strip_duplicate();
		if (!(inst.length_balance_filter() || inst.element_balance_filter() || inst.prefix_filter()) && (hard_mode ? !inst.has_symetrical() : 1))		    // if instance can have solution
		{
			Pcp_solution pcp = Pcp_solution();
			if (pcp.iterative_solve(inst))
			{
				std::cout << "instance :" << inst << std::endl;

				std::cout << "solution :" << pcp << std::endl;

			}
		}
	}
	/*
    std::cout << easy_amount << std::endl;
    std::cout << medium_amount << std::endl;
    std::cout << hard_amount << std::endl;
    */
}


int main(void)
{
	//srand(time(0));					// set random seed
	srand(1);					// set random seed

	Pcp_solution pcp = Pcp_solution();
	//Pcp_instance instance = Pcp_instance(2, 6);
	Pcp_instance instance = {"1", "111", "10111", "10", "10", "0"};
	Pcp_instance inst = {"101", "1", "0", "01", "10", "110", "11", "10"};		// has length 84 solution
	Pcp_instance inst66 = {"001", "01", "1", "011", "011", "10", "010", "01"};		// has length 66 solution

	Pcp_instance inst160 = {"01", "0", "00", "011", "1", "101", "001", "1"};

	Pcp_bloc bloc1 = {"01", "101"};
	Pcp_bloc bloc2 = {"01", "01"};

	std::cout << (bloc1 == bloc2) << std::endl;

	//pcp.iterative_solve(inst);

	pcp.solve(161, inst);

	std::cout << "instance :" << inst160 << std::endl;
	std::cout << "SOLUTION SIZE = " << pcp.get_sol_size() << std::endl;
	std::cout << "solution :" << pcp << std::endl;

	//generate_instance(5, 6, 10, 1);

}



