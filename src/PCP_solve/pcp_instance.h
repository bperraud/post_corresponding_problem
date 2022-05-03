#ifndef PCP_SOLVING_H
#define PCP_SOLVING_H

#include "pcp_bloc.h"

#include <bits/stdc++.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>

class Pcp_instance {
	unsigned int _size;						// nombre de bloc
	unsigned int _width; 					// longueur de la plus grande string

	std::vector<Pcp_bloc> _instance;		// liste des blocs
	std::vector<Pcp_bloc> _reversal;		// liste des blocs
	std::vector<Pcp_bloc> _mask_bloc;		// liste des blocs qui ne peuvent pas être au début d'une solution

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
    void strip_duplicate();
    bool has_common_in_db();
    std::string stringify();
    void write_instance(int, int);
    bool is_in_db();

	void create_reversal();

	void mask_top();


	friend std::ostream& operator<< (std::ostream&, Pcp_instance&);
};

#endif
