#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"


int main(void)
{
	Pcp_solution pcp = Pcp_solution();
    //Pcp_instance instance = Pcp_instance(2, 6);
    Pcp_instance instance = {"1", "111", "10111", "10", "10", "0"};
    std::cout << instance << std::endl;
	bool res = pcp.is_in_db();
    std::cout << res << std::endl;
}



