#include <iostream>
#include <string>

class Person
{
    std::string name;
    int age;

public:
    friend class PersonBuilderBase;
    friend class PersonBuilderName;
};

class PersonBuilderBase
{
protected:
    PersonBuilderBase(Person& person) : p(person) {}
    Person& p;

public:
    const PersonBuilderName& create_1st_group_parameters() { return PersonBuilderName{ p }; }
};

class PersonBuilderName : public PersonBuilderBase
{
public:
    PersonBuilderName(Person& person) : PersonBuilderBase(person) {}

    PersonBuilderName& createName(std::string personName) 
    {
        this->p.name = personName;
        return *this;
    }

};

class PersonBuilder : public PersonBuilderBase
{
public:
    PersonBuilder() : PersonBuilderBase(p) {}
    Person p;
};



#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

