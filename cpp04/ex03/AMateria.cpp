#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default")
{
	PRINT("AAnimal default constructor called");
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	PRINT("AAnimal constructor with parameters called");
}

AAnimal::AAnimal(AAnimal const &other) : _type(other._type)
{
	PRINT("AAnimal copy constructor called");
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	PRINT("AAnimal assign operator called");
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	PRINT("AAnimal destructor called");
}

// void AAnimal::makeSound() const
// {
// }

std::string AAnimal::getType() const
{
	return _type;
}
