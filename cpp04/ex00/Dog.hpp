#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
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