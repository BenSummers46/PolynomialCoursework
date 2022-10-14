#pragma once
#include "Component.h"
#include <vector>

class Equation {
private:
	std::vector<Component> m_equation;
public:
	Equation(std::vector<Component> equation);

	friend std::ostream& operator<<(std::ostream& ostr, const Equation& equation);

	void print_equation();
};
