#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"

# define DIV 4
# define ITERATION 1000000000

void generate_instance(int instance_size, int instance_width, int depth)
{
	int i = 0;
	while (i++ < ITERATION)
	{
		Pcp_instance inst = Pcp_instance(instance_size, instance_width);										// random gen
		if (!(inst.length_balance_filter() || inst.element_balance_filter() || inst.prefix_filter()))		// if instance can have solution
		{
			//std::cout << "rand instance " << i  << " : " << inst << std::endl;
			Pcp_solution pcp = Pcp_solution();
			//if (pcp.solve(depth, inst) && pcp.get_length() > depth/DIV )
			if (pcp.solve(depth, inst))
			{
				std::cout << "instance : " <<  inst << std::endl;
				std::cout << "solution : " << pcp << std::endl;
				// write in db (_best_pcp et non pas _pcp)
			}
		}
	}
}


int main(void)
{
	Pcp_solution pcp = Pcp_solution();
    //Pcp_instance instance = Pcp_instance(2, 6);
    Pcp_instance instance = {"1", "111", "10111", "10", "10", "0"};
	Pcp_instance inst2 = {"10", "0", "0", "000", "00", "01", "00", "11"};		// has length 10 solution
	Pcp_instance inst3 = {  "01", "0", "01", "110", "0", "100", "100", "10"};		// length 76 solution

	Pcp_solution solution;
	//solution.solve(10, inst2);
	//Pcp_solution sol2;
	//sol2.solve(15, inst2);
	//std::cout << sol2 << std::endl;

	srand(time(0));					// set random seed

    // LEVEL 1
	generate_instance(6, 3, 40);
	// LEVEL 2
	//generate_instance(3, 4, )
	// LEVEL 3
	//generate_instance(4, 4, )
	// LEVEL 4

	//bool res = pcp.is_in_db();
    //std::cout << res << std::endl;
}



