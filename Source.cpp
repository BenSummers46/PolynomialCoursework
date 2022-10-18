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

void generate_equation() {
	int start, end;
	Equation equation;
	equation.print_equation();
	std::cout << "Enter the start range for number set: ";
	std::cin >> start;
	std::cout << "Enter the end range for number set: ";
	std::cin >> end;
	equation.change_output_set(generate_set(equation, start, end));
	equation.print_output_set();
	return;
}

void generate_output() {
	OutputSet output_set;
	output_set.print_output_set();
}

void generate_and_solve() {
	OutputSet output_set;
	output_set.print_output_set();
	Equation equation(output_set.see_set());
	
}

int main() {
	bool quit = false;
	while (!quit) {
		int choice;
		std::cout << "1. Create new equation and number set" << std::endl << "2. Read in numbers from a file" << std::endl << "3. Solve equation from number list" << std::endl << "4. Quit" << std::endl;
		std::cout << "Enter number choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			generate_equation(); std::cout << std::endl;
			break;
		case 2:
			generate_output(); std::cout << std::endl;
			break;
		case 3:
			generate_and_solve(); std::cout << std::endl;
			break;
		case 4:
			quit = true;
			break;
		}
	}

	//output_set.print_set_to_file();
	return 0;
}

int main2() {
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