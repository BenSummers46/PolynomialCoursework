#include <iostream>
#include <vector>
#include "Component.h"
#include "Equation.h"

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
	std::cout << "value of c1 at index 2: " << c1->value(2) << std::endl;

	std::vector<Component> equation;
	equation.push_back(*c1);
	equation.push_back(*c2);
	equation.push_back(*c3);
	
	Equation* new_equation = new Equation(equation);
	new_equation->print_equation();
	/*std::cout << new_equation;*/

	delete new_equation;
	delete c1;
}