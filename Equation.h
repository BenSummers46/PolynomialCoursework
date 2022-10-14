#pragma once
#include "Component.h"
#include <vector>

class Equation {
private:
	std::vector<Component> m_equation;
public:
	Equation(std::vector<Component> equation);
	//Equation(int* input_set);

	void print_equation(std::vector<Component> equation);
};
