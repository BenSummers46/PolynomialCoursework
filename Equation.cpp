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
	std::cout << "Please enter number of terms: "; std::cin >> num_of_terms;
	for (int i = 0; i < num_of_terms; i++) {
		do {
			std::cout << "No coefficients > 9; exponents > 4; constants > 1000" << std::endl;
			std::cout << "Please Enter a coefficient " << i + 1 << ": ";
			std::cin >> coefficient;
			std::cout << "Please Enter a exponent " << i + 1 << "(enter 0 for a constant, 1 for nx)" << ": ";
			std::cin >> exponent;
		} while (exponent > 4 || (coefficient > 9 && exponent > 0)|| (exponent == 0 && coefficient > 1000));
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

void Equation::find_next_items(int* difference, int* exponent, int* coefficient, Equation* temp) {
	std::vector<int> difference_set = difference_in_set(temp->see_output_set(), this->see_output_set());
	*exponent = find_greatest_power(difference_set, 1, difference);
	*coefficient = (*exponent != 1) ? (int)find_coefficient(*difference, *exponent) : *difference;
}

void Equation::change_temp(Equation* temp)
{
	temp->change_equation(this->m_equation);
	temp->change_output_set(create_output_set(0, this->m_output_set.size() - 1));
}

void Equation::solve_equation() {
	int difference;
	int loop = 0;
	int constant = find_constant(this->m_output_set);
	int exponent = find_greatest_power(this->m_output_set, 1, &difference);
	int coefficient = (exponent != 1) ? (int)find_coefficient(difference, exponent) : difference;
	this->m_equation.push_back(Component(coefficient, exponent));
	if (constant != 0) { this->m_equation.push_back(Component(constant, 0)); }
	Equation temp(m_equation);
	temp.change_output_set(create_output_set(0, this->m_output_set.size()-1));
	while (this->see_output_set() != temp.see_output_set()) {
		if (loop > 5) { std::cout << "Equation not solveable with current constraints!"; return; }
		find_next_items(&difference, &exponent, &coefficient, &temp);
		this->m_equation.push_back(Component(coefficient, exponent));
		change_temp(&temp);
		loop = loop + 1;
	}
	std::cout << "Equation was correct!" << std::endl;
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

std::vector<int> Equation::difference_in_set(std::vector<int> temp, std::vector<int> original_set)
{
	std::vector<int> difference;
	for (int i = 0; i < temp.size(); i++) {
		difference.push_back(original_set[i] - temp[i]);
	}
	return difference;
}

