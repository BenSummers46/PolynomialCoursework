#include <iostream>
#include <vector>
#include "Component.h"
#include "Equation.h"
#include "OutputSet.h"

std::vector<int> generate_set(Equation equation, int start, int end) {
	std::vector<int> set;
	for (int i = start; i <= end; i++) {
		set.push_back(equation.create_output_set(i));
	}
	return set;
}

int main() {
	Component* c1 = new Component(2, 2);
	Component* c2 = new Component(5, 0);
	Component* c3 = new Component(0, 3);

	std::cout << *c1;
	std::cout << std::endl;
	std::cout << *c2;
	std::cout << std::endl;
	std::cout << *c3;
	std::cout << std::endl;
	//c1->print_component();
	//c2->print_component();
	std::cout << "value of c1 at index 2: " << c1->value(2) << std::endl;//8
	std::cout << "value of c2 at index 2: " << c2->value(2) << std::endl;//5
	std::cout << "value of c3 at index 2: " << c3->value(2) << std::endl;//8

	std::vector<Component> equation;
	equation.push_back(*c1);
	equation.push_back(*c2);
	equation.push_back(*c3);
	
	Equation* new_equation = new Equation(equation);
	new_equation->print_equation();
	/*std::cout << new_equation;*/

	std::vector<int> output_set = generate_set(*new_equation, 0, 10);
	new_equation->change_output_set(output_set);
	new_equation->print_output_set();

	OutputSet* new_set = new OutputSet(new_equation->see_output_set());
	new_set->print_output_set();
	new_set->print_set_to_file();

	delete new_equation;
	delete c1;
	delete c2;
	delete c3;
	delete new_set;
}