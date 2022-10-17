#pragma once
#include <vector>
#include "Equation.h"

class OutputSet{
public:
	OutputSet(std::vector<int> set);
	OutputSet();
	~OutputSet();
	void change_set(std::vector<int> new_set);
	void print_output_set();
	void print_set_to_file();
private:
	std::vector<int> m_set;
};
