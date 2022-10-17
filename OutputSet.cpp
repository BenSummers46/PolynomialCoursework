#include "OutputSet.h"
#include <fstream>

OutputSet::OutputSet(std::vector<int> set)
{
	m_set = set;
}

OutputSet::~OutputSet()
{
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
	file.open("Write_output_set.txt", std::ios_base::out);
	for (auto& item : this->m_set) {
		if (&item == &this->m_set.back()) {
			file << item << std::endl;
		}
		else {
			file << item << ", ";
		}
	}
	return;
}
