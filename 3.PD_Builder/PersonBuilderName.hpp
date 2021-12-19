#pragma once

#include "Person.hpp"
#include "PersonBuilderBase.hpp"

class PersonBuilderName : public PersonBuilderBase
{
public:
    PersonBuilderName(Person& person) : PersonBuilderBase(person) {}

    PersonBuilderName& createName(std::string personName);
};