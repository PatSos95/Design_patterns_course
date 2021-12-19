#include "PersonBuilder.hpp"
#include "PersonBuilderName.hpp"

PersonBuilderName PersonBuilderBase::create_1st_group_parameters()
{
	return PersonBuilderName{ p };
}

PersonBuilderName& PersonBuilderName::createName(std::string personName)
{
    this->p.name = personName;
    return *this;
}

PersonBuilderBase::operator Person()
{
    return std::move(p);
}
