#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"


int main(void)
{
	Pcp_solution pcp = Pcp_solution();
    Pcp_instance instance = Pcp_instance(2, 6);
    std::cout << instance << std::endl;
	std::cout << pcp.solve(5, instance) << std::endl;
}



