#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"

# define ITERATION 300

using namespace std;

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
			inst.mask_top();
			inst.mask_bot();

			if (!(inst.getTopmask() && inst.getBotmask()))
			{
				Pcp_solution pcp = Pcp_solution();
				if (pcp.iterative_solve(inst))
				{
					cout << "instance :" << inst << endl;

					cout << "solution :" << pcp << endl;

				}
			}
		}
	}
}


int main(void)
{
	//srand(time(0));					// set random seed

	clock_t start, end;
	start = clock();

	srand(1);					// set random seed

	Pcp_solution pcp = Pcp_solution();
	//Pcp_instance instance = Pcp_instance(2, 6);
	Pcp_instance instance = {"1", "111", "10111", "10", "10", "0"};
	Pcp_instance inst = {"101", "1", "0", "01", "10", "110", "11", "10"};		// has length 84 solution
	Pcp_instance inst66 = {"001", "01", "1", "011", "011", "10", "010", "01"};		// has length 66 solution

	Pcp_instance inst160 = {"01", "0", "00", "011", "1", "101", "001", "1"};

	Pcp_instance botmask = {"0", "01", "011", "00", "101", "1", "1", "001"};

	inst160.mask_top();

	botmask.mask_bot();

	/*
	pcp.solve(161, instance);
	pcp.iterative_solve(inst);

	std::cout << "instance :" << inst160 << std::endl;
	std::cout << "SOLUTION SIZE = " << pcp.get_sol_size() << std::endl;
	std::cout << "solution :" << pcp << std::endl;
	*/
	generate_instance(5, 6, 20, 1);

	// Recording the end clock tick.
	end = clock();

	// Calculating total time taken by the program.
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is : " << fixed
		 << time_taken << setprecision(7);
	cout << " sec " << endl;

}



