#include <iostream>
#include <vector>
#include "Component.h"
#include "Equation.h"
#include "OutputSet.h"

auto options = []() {
	std::cout << "1. Create a number sequence from given equation" << std::endl << "2. Return to menu" << std::endl << "Enter number choice: ";
};

void create_output_set_UI(Equation* equation) {
	int choice, start, end;
	options();
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Enter the start range for number set: ";
		std::cin >> start;
		std::cout << "Enter the end range for number set: ";
		std::cin >> end;
		equation->change_output_set(equation->create_output_set(start, end));
		equation->print_output_set();
		break;
	case 2:
		return;
	default:
		std::cout << "Invalid Entry" << std::endl;
		return;
	}
	return;
}

void generate_equation() {
	Equation equation;
	equation.print_equation();
	create_output_set_UI(&equation);
	OutputSet set(equation.see_output_set());
	set.print_set_to_file();
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
		default:
			std::cout << "Please enter a number between 1 and 4!" << std::endl;
			std::cout << std::endl;
			break;
		}
	}
	return 0;
}
