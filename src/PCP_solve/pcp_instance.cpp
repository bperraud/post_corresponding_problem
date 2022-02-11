#include "pcp_instance.h"

using namespace std;

bool Pcp_bloc::has_prefix()
{
	return strncmp(_top, _bottom,  ABS( _width - top_less_bottom()));
}


unsigned int Pcp_instance::excess_one()
{



}



Pcp_bloc::Pcp_bloc(const char *top, const char *bottom){
	_top = top;
	_bottom = bottom;
	_width = MAX(strlen(top), strlen(bottom));
}

int main(void)
{
	Pcp_bloc* bloc = new Pcp_bloc((char*)"100", (char*)"101");

	cout << bloc->has_prefix() << endl;
}





