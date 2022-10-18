#include <iostream>
#include <vector>
#include "Component.h"
#include "Equation.h"
#include "OutputSet.h"

void generate_equation() {
	int start, end;
	Equation equation;
	equation.print_equation();
	std::cout << "Enter the start range for number set: ";
	std::cin >> start;
	std::cout << "Enter the end range for number set: ";
	std::cin >> end;
	equation.change_output_set(equation.create_output_set( start, end));
	equation.print_output_set();
	/*OutputSet set(equation.see_output_set());
	set.print_set_to_file();*/
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
	equation.solve_equation();
	equation.print_equation();
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

	return 0;
}
