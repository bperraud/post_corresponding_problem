
#include "pcp_bloc.h"
#include "pcp_instance.h"

using namespace std;

int main(void)
{
	Pcp_bloc* bloc = new Pcp_bloc("001", "010");

	//Pcp_instance *instance = new Pcp_instance{"001", "00", "00", "01", "1", "0", "101", "10"};

	Pcp_instance instance = {"001", "00", "00", "01", "1", "0", "101", "10"};


	//cout << bloc->has_prefix() << endl;

}
