#include "pcp_bloc.h"
#include "pcp_instance.h"
#include "pcp_solution.h"


int main(void)
{
	Pcp_bloc* bloc = new Pcp_bloc("11", "10");
	cout << *bloc << endl;
	string top = "001";
	string bot = "00" ;

	//Pcp_instance *instance = new Pcp_instance{"001", "00", "00", "01", "1", "0", "101", "10"};
	//Pcp_instance instance = {"001", "00", "00", "01", "1", "0", "101", "10"};
	Pcp_instance*  instance = new Pcp_instance{"001", "00", "00", "01", "1", "0", "101", "10"};

	Pcp_instance instance2 = {"10", "0", "0", "000", "00", "01"};

	Pcp_solution pcp;
	solve(0, instance2, pcp);

	/*
    if (!instance.is_in_db()){
        instance.write_instance();
    }
    if (!instance2.is_in_db()){
        instance2.write_instance();
    }
	cout << instance.length_balance_filter() << endl;
	cout << instance2.length_balance_filter() << endl;
	cout << instance.element_balance_filter() << endl;
	cout << instance2.element_balance_filter() << endl;
	 */
}



