#ifndef PCP_SOLVING_H
#define PCP_SOLVING_H

#include "pcp_bloc.h"

class Pcp_instance {
	unsigned int _size;						// nombre de bloc
	unsigned int _width; 					// longueur de la plus grande string
	std::vector<Pcp_bloc> _instance;		// liste des blocs

public:
	Pcp_instance(unsigned int , unsigned int );
	Pcp_instance(std::initializer_list<std::string>);
	inline Pcp_bloc getBloc(unsigned int index) { return _instance[index];}
	inline unsigned int getSize() { return _size;};
	inline std::vector<Pcp_bloc> getInstance(){ return _instance; }
	bool prefix_filter();
	bool length_balance_filter();
	bool element_balance_filter();
	bool has_symetrical();
    //std::string stringify();
    //void write_instance();
    //bool is_in_db();

	friend std::ostream& operator<< (std::ostream&, Pcp_instance&);
};

#endif
