#include <vector>
#include <iostream>
#include "Equation.h"
#include "Component.h"

Equation::Equation(std::vector<Component> equation)
{
	m_equation = equation;
}

Equation::Equation()
{
	int num_of_terms, exponent, coefficient;
	std::cout << "Please enter number of terms: ";
	std::cin >> num_of_terms;
	for (int i = 0; i < num_of_terms; i++) {
		std::cout << "Please Enter a coefficient " << i+1 << ": ";
		std::cin >> coefficient;
		std::cout << "Please Enter an exponent " << i+1 << ": ";
		std::cin >> exponent;

		m_equation.push_back(Component(coefficient, exponent));
	}
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

void Equation::change_equation(std::vector<Component> new_equation)
{
	m_equation = new_equation;
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
