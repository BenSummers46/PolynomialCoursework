#pragma once
#include <iostream>

class Component {
private:
	int m_coefficient;
	int m_exponent;
public:
	Component();
	Component(int coefficient, int exponent);
	~Component();
	
	Component operator+(Component const& compA);
	Component operator-(Component const& compB);
	friend std::ostream& operator<<(std::ostream& ostr, const Component& comp);

	void print_component();
	int value(int i);
	
	int get_coefficient() const {return m_coefficient;}
	void change_coefficient(int x);
	int get_exponent() const { return m_exponent; }
	void change_exponent(int x);
};
