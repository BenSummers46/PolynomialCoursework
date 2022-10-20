#pragma once
#include "Component.h"
#include <vector>
#include <algorithm>

class Equation {
private:
	std::vector<Component> m_equation;
	std::vector<int> m_output_set;
public:
	Equation(std::vector<Component> equation);
	Equation(std::vector<int> output_set);
	Equation();
	~Equation();

	void print_equation();
	std::vector<int> create_output_set(int start, int end);
	void change_output_set(std::vector<int> set);
	void change_equation(std::vector<Component> new_equation);
	std::vector<int> see_output_set() { return m_output_set; }
	void print_output_set();

	int factorial(int n);
	void solve_equation();
	int find_greatest_power(std::vector<int> list, int i, int* difference);
	float find_coefficient(int difference, int exponent);
	int find_constant(std::vector<int> set);
	std::vector<int> difference_in_set(std::vector<int> temp, std::vector<int> original_set);
	void find_next_items(int* difference, int* exponent, int* coefficient, Equation* temp);
	void change_temp(Equation* temp);
	
	template<typename T>
	bool all_equal(std::vector<T> const &v);
};

template<typename T>
inline bool Equation::all_equal(std::vector<T> const &v)
{
	return std::adjacent_find(v.begin(), v.end(), std::not_equal_to<T>()) == v.end();
}
