#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* _brain;
public:
    //ocf
    Cat();
    Cat(Cat const &other);
    Cat &operator=(Cat const &other);
    virtual ~Cat();

    //function
    virtual void makeSound() const;
};

#endif