#pragma once

#include "Person.hpp"

class PersonBuilderName;

class PersonBuilderBase
{
protected:
    PersonBuilderBase(Person& person) : p(person) {}
    Person& p;

public:
    PersonBuilderName create_1st_group_parameters();
    operator Person();
};