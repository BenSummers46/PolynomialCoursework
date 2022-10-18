#include <vector>
#include <iostream>
#include "Equation.h"
#include "Component.h"

Equation::Equation(std::vector<Component> equation)
{
	m_equation = equation;
}

Equation::Equation(std::vector<int> output_set) {
	m_output_set = output_set;
}

Equation::Equation()
{
	int num_of_terms, exponent, coefficient;
	std::cout << "Please enter number of terms: ";
	std::cin >> num_of_terms;
	for (int i = 0; i < num_of_terms; i++) {
		std::cout << "Please Enter a coefficient " << i+1 << ": ";
		std::cin >> coefficient;
		std::cout << "Please Enter a exponent " << i+1 << "(enter 0 for a constant, 1 for nx)" << ": ";
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

std::vector<int> Equation::create_output_set(int start, int end)
{
	int sum = 0;
	std::vector<int> set;
	for (int i = start; i <= end; i++) {
		for (auto item : this->m_equation) {
			sum = sum + item.value(i);
		}
		set.push_back(sum);
		sum = 0;
	}
	return set;
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

int Equation::factorial(int n)
{
	return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

void Equation::solve_equation()
{
	int difference;
	int constant = find_constant(this->m_output_set);
	int exponent = find_greatest_power(this->m_output_set, 1, &difference);
	int coefficient = (int)find_coefficient(difference, exponent);
	this->m_equation.push_back(Component(coefficient, exponent));
	if (constant != 0) { this->m_equation.push_back(Component(constant, 0)); }
	Equation temp(m_equation);
	temp.change_output_set(create_output_set(0, 20));
	if (this->see_output_set() == temp.see_output_set()) { std::cout<< "Equation was correct!" <<std::endl; return; }
	std::cout << "Equation was not correct!" << std::endl;
	return;
}

int Equation::find_greatest_power(std::vector<int> list, int i, int* difference)
{
	std::vector<int> temp;
	for (int i = 0; i < list.size() - 1; i++) {
		temp.push_back(list[i + 1] - list[i]);
	}
	if (all_equal(temp)) { 
		*difference = temp[0];
		return i; 
	}
	return find_greatest_power(temp, i + 1, difference);
}

float Equation::find_coefficient(int difference, int exponent)
{
	return (float)difference / (float)factorial(exponent);
}

int Equation::find_constant(std::vector<int> set)
{
	if (set[0] == 0) { return 0; }
	return set[0];
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
