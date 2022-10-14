#include "Equation.h"
#include "Component.h"

Equation::Equation(std::vector<Component> equation)
{
	m_equation = equation;
}

void Equation::print_equation()
{
	for (auto& item : this->m_equation) {
		if (&item == &this->m_equation.back()) {
			std::cout << item << std::endl;
		}
		else {
			std::cout << item << " + ";
		}
	}
}

std::ostream& operator<<(std::ostream& ostr, const Equation& equation)
{
	/*for (auto item : equation.m_equation) {
		if (&item == &equation.m_equation.back()) {
			ostr << item << std::endl;
		}
		else {
			ostr << item << " + ";
		}
	}
	return ostr;*/
	return ostr;
}
