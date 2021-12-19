#pragma once

#include <string>

class PersonBuilder;

class Person
{
    std::string name;
    int age;

public:
    static PersonBuilder create();
    void printName();

    friend class PersonBuilderBase;
    friend class PersonBuilderName;
};
