#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"

# define DIV 0.75
# define ITERATION 10

void generate_instance(int instance_size, int instance_width, int depth, int hard_mode = 0)
{
    int easy_amount = 0;
    int medium_amount = 0;
    int hard_amount = 0;
	int i = 0;
	while (i++ < ITERATION)
	{
	    std::cout << i << std::endl;
		Pcp_instance inst = Pcp_instance(instance_size, instance_width);
        inst.strip_duplicate();
		if (!(inst.length_balance_filter() || inst.element_balance_filter() || inst.prefix_filter()) && (hard_mode ? !inst.has_symetrical() : 1))		    // if instance can have solution
		{
			Pcp_solution pcp = Pcp_solution();
			if (pcp.iterative_solve(inst))			// filtre
			{
                if (!inst.is_in_db()){
                    int size = pcp.get_sol_size();
                    if (size <= 4){
                        easy_amount++;
                        inst.write_instance(0, size);
                    }
                    else if (size > 4 && size <=7){
                        medium_amount++;
                        inst.write_instance(1, size);
                    }
                    else{
                        hard_amount++;
                        inst.write_instance(2, size);
                    }
                }

			}
		}
	}
    std::cout << easy_amount << std::endl;
    std::cout << medium_amount << std::endl;
    std::cout << hard_amount << std::endl;
}


int main(void)
{
	Pcp_solution pcp = Pcp_solution();
    //Pcp_instance instance = Pcp_instance(2, 6);
    Pcp_instance instance = {"1", "111", "10111", "10", "10", "0"};
	Pcp_instance inst2 = {"10", "0", "0", "000", "00", "01", "00", "11"};		// has length 10 solution
	Pcp_instance inst3 = {  "01", "0", "01", "110", "0", "100", "100", "10"};		// length 76 solution
	Pcp_instance inst4 = {"1", "111", "1", "100", "111", "11", "00", "10", "10", "00", "010", "0"};
	Pcp_instance inst5 = {"1", "11", "11", "111" , "1", "100", "001", "1"};


	Pcp_solution solution;
	//solution.solve(10, inst5);

	srand(time(0));					// set random seed

    // LEVEL 1
	//generate_instance(4, 3, 5);
	// LEVEL 2
	//generate_instance(3, 4, )
	// LEVEL 3
	generate_instance(6, 6, 15, 1);
	// LEVEL 4
	//generate_instance(4, 3, 5);
	// LEVEL 5
	//generate_instance(3, 4, )
	// LEVEL 6
	//generate_instance(4, 4, 20, 1);
	// LEVEL 7

	//bool res = pcp.is_in_db();
    //std::cout << res << std::endl;
}



