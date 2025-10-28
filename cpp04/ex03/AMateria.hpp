#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>
#include <string>

#define PRINT(x) std::cout << x << std::endl;

class AAnimal
{
protected:
    std::string _type;
public:
    //ocf
    AAnimal();
    AAnimal(std::string type);
    AAnimal(AAnimal const &other);
    AAnimal &operator=(AAnimal const &other);
    virtual ~AAnimal();

    //function
    virtual void makeSound() const = 0;

    //getters
    std::string getType() const;
};

#endif

class AMateria
{
protected:
    std::string _type;

public:
AMateria(std::string const & type);
    AAnimal(AAnimal const &other);
    AAnimal &operator=(AAnimal const &other);
    virtual ~AAnimal();
std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};