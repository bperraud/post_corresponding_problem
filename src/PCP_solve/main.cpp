#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"

# define DIV 0.75
# define ITERATION 10000000

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

	srand(time(0));					// set random seed

	generate_instance(5, 6, 15, 1);

}



