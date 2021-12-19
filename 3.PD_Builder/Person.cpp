#include "Person.hpp"
#include "PersonBuilder.hpp"

#include <iostream>

PersonBuilder Person::create()
{
	return PersonBuilder();
}

void Person::printName()
{
	std::cout << name;
}
