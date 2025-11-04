#ifndef W_ANIMAL_H
#define W_ANIMAL_H

#include <iostream>
#include <string>

#define PRINT(x) std::cout << x << std::endl;

class WrongAnimal
{
protected:
    std::string _type;
public:
    //ocf
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const &other);
    WrongAnimal &operator=(WrongAnimal const &other);
    virtual ~WrongAnimal();

    //function
    void makeSound() const;

    //getters
    std::string getType() const;
};

#endif