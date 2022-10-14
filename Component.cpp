#include <iostream>
#include <cmath>
#include "Component.h"

Component::Component()
{
	this->m_coefficient = NULL;
	this->m_exponent = NULL;
}

Component::Component(int coefficient, int exponent)
{
	this->m_coefficient = coefficient;
	this->m_exponent = exponent;
}

Component::~Component()
{
}

Component Component::operator+(const Component& compA)
{
	return Component();
}

Component Component::operator-(const Component& compB)
{
	return Component();
}

void Component::print_component()
{
	//std::cout << get_coefficient() << "x^" << get_exponent() << std::endl;
	std::cout << this->m_coefficient << "x^" << this->m_exponent << std::endl;
}

int Component::value(int i)
{
	return (pow(i, m_exponent) * m_coefficient);
}

void Component::change_coefficient(int x)
{
	this->m_coefficient = x;
}

void Component::change_exponent(int x)
{
	this->m_exponent = x;
}

std::ostream& operator<<(std::ostream& ostr, const Component& comp)
{
	//const char* expo = (comp.get_exponent() > 0) ? "x^" + (char)comp.get_exponent() : "";
	if(comp.m_exponent > 0){
		ostr << comp.m_coefficient << "x^" << comp.m_exponent;
		return ostr;
	}
	
	ostr << comp.m_coefficient << "";
	return ostr;
}
