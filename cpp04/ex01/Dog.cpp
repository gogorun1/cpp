#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	PRINT("Dog default constructor called");
	_brain = new Brain();
}

Dog::Dog(Dog const &other) : Animal(other._type)
{
	PRINT("Dog copy constructor called");
	_brain = new Brain();
	*_brain = *(other._brain);
}

Dog &Dog::operator=(Dog const &other)
{
	PRINT("Dog assign operator called");
	if (this != &other)
	{
		this->_type = other._type;
		*_brain = *(other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	PRINT("Dog destructor called");
	delete _brain;
}

void Dog::makeSound() const
{
	PRINT("Woof woof");
}
