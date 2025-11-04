#ifndef DOG_H
#define DOG_H

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal
{
private:
    Brain* _brain;
public:
    //ocf
    Dog();
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);
    virtual ~Dog();

    //function
    virtual void makeSound() const;
};

#endif