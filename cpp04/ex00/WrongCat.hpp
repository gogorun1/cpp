#ifndef W_CAT_H
#define W_CAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    //ocf
    WrongCat();
    WrongCat(WrongCat const &other);
    WrongCat &operator=(WrongCat const &other);
    virtual ~WrongCat();

    //function
    virtual void makeSound() const;
};

#endif