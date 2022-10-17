#pragma once
#include "Component.h"
#include <vector>

class Equation {
private:
	std::vector<Component> m_equation;
	std::vector<int> m_output_set;
public:
	Equation(std::vector<Component> equation);
	~Equation();

	friend std::ostream& operator<<(std::ostream& ostr, const Equation& equation);

	void print_equation();
	int create_output_set(int i);
	void change_output_set(std::vector<int> set);
	void print_output_set();
};
