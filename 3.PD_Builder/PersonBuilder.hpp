#pragma once

#include "Person.hpp"
#include "PersonBuilderBase.hpp"
#include <string>

class PersonBuilder : public PersonBuilderBase
{
public:
    PersonBuilder() : PersonBuilderBase(p) {}
    Person p;
};