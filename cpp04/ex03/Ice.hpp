#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();

	// OCF
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);

	// Pure virtual
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif