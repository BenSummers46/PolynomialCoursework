#pragma once
#include "Component.h"
#include <vector>

class Equation {
private:
	std::vector<Component> m_equation;
	std::vector<int> m_output_set;
public:
	Equation(std::vector<Component> equation);
	Equation(std::vector<int> output_set);
	Equation();
	~Equation();

	friend std::ostream& operator<<(std::ostream& ostr, const Equation& equation);

	void print_equation();
	int create_output_set(int i);
	void change_output_set(std::vector<int> set);
	void change_equation(std::vector<Component> new_equation);
	std::vector<int> see_output_set() { return m_output_set; }
	void print_output_set();
};
