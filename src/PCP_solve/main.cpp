
#include "pcp_bloc.h"
#include "pcp_instance.h"

using namespace std;

int main(void)
{
	Pcp_bloc* bloc = new Pcp_bloc("101", "10");

	//cout << "has prefix " << bloc->has_prefix() << endl;

	std::string top = "001";
	std::string bot = "00" ;

	// _top.compare(0, _top.length(), _bottom, 0, _width - (ABS(top_less_bottom())))
	//Pcp_instance *instance = new Pcp_instance{"001", "00", "00", "01", "1", "0", "101", "10"};

	//Pcp_instance instance = {"001", "00", "00", "01", "1", "0", "101", "10"};
	Pcp_instance instance = {"001", "00", "00", "01", "1", "0", "101", "10"};

	cout << instance.length_balance_filter() << endl;

}
