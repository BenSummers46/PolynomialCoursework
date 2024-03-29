#include "OutputSet.h"
#include <fstream>
#include <iostream>
#include <string>

OutputSet::OutputSet(std::vector<int> set)
{
	m_set = set;
}

OutputSet::OutputSet()
{
	std::string filename, line;
	std::fstream file;
	std::cout << "Please enter a filename: ";
	std::cin >> filename;
	try {
		file.open(filename);
		if (!file.is_open()) { std::cout << "Error opening the file" << std::endl; return; }
		while (getline(file, line, ',')) { m_set.push_back(std::stoi(line)); }
		file.close();
	}
	catch (std::exception const& e) { std::cout << "Error While reading from the file" << std::endl; }
}

OutputSet::~OutputSet()
{
}

void OutputSet::change_set(std::vector<int> new_set)
{
	this->m_set = new_set;
}

void OutputSet::print_output_set()
{
	for (auto& item : this->m_set) {
		if (&item == &this->m_set.back()) {
			std::cout << item << std::endl;
		}
		else {
			std::cout << item << ", ";
		}
	}
}

void OutputSet::print_set_to_file()
{
	std::fstream file;
	try {
		file.open("Write_output_set.txt", std::ios_base::app | std::ios_base::in);
		if (!file.is_open()) { std::cout << "Error When opening the file" << std::endl; return;}
		for (auto& item : this->m_set) {
			if (&item == &this->m_set.back()) { file << item << std::endl; }
			else { file << item << ","; }
		}
		file.close();
	}
	catch (std::exception const& e) { std::cout << "Error while writing to file!" << std::endl; } return;
}
