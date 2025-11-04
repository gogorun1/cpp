#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

#define PRINT(x) std::cout << x << std::endl;

class Animal
{
protected:
    std::string _type;
public:
    //ocf
    Animal();
    Animal(std::string type);
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    virtual ~Animal();

    //function
    virtual void makeSound() const;

    //getters
    std::string getType() const;
};

#endif