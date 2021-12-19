#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonBuilderName.hpp"

int main()
{
    Person p = Person::create().create_1st_group_parameters().createName("Patryk");
    p.printName();
}

