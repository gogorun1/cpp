#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter; 

class AMateria
{
protected:
    std::string _type;

public:
    AMateria(std::string const & type);
    virtual ~AMateria(); 

    // OCF 
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);

    std::string const & getType() const; 

    // Pure virtual
    virtual AMateria* clone() const = 0;
    
    // Virtual
    virtual void use(ICharacter& target);
};

#endif