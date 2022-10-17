#include <vector>
#include "Equation.h"
#include "Component.h"

Equation::Equation(std::vector<Component> equation)
{
	m_equation = equation;
}

Equation::~Equation()
{
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

int Equation::create_output_set(int i)
{
	int sum = 0;
	for (auto item : this->m_equation) {
		sum = sum + item.value(i);
	}
	return sum;
}

void Equation::change_output_set(std::vector<int> set)
{
	m_output_set = set;
}

void Equation::print_output_set()
{
	for (auto& item : this->m_output_set) {
		if (&item == &this->m_output_set.back()) {
			std::cout << item << std::endl;
		}
		else {
			std::cout << item << ", ";
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
