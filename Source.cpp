#include <iostream>
#include "Component.h"
#include <vector>

int main() {
	Component* c1 = new Component(3, 2);
	Component* c2 = new Component(5, 3);

	std::cout << *c1;
	std::cout << std::endl;
	std::cout << *c2;
	std::cout << std::endl;
	c1->print_component();
	c2->print_component();

	std::vector<Component> equation;
	equation.push_back(*c1);
	equation.push_back(*c2);
	for (int i = 0; i < equation.size(); i++) {
		std::cout << equation[i] << " ";
	}

	delete c1;
}