#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	PRINT("AMateria default constructor called");
}

AMateria::AMateria(std::string const &type): _type(type)
{
	PRINT("AMateria constructor with parameters called");
}

AMateria::AMateria(AMateria const &other) : _type(other._type)
{
	PRINT("AMateria copy constructor called");
}

AMateria &AMateria::operator=(AMateria const &other)
{
	PRINT("AMateria assign operator called");
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria()
{
	PRINT("AMateria destructor called");
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}