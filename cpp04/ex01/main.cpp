#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    static const int ARRAY_SIZE = 4;
    Animal *animal[ARRAY_SIZE];
    for(int index = 0; index < ARRAY_SIZE; index++)
    {
        if (index < ARRAY_SIZE / 2)
            animal[index] = new Cat();
        else
            animal[index] = new Dog();
        PRINT("===============an animal is created===============");
    }
    PRINT("===============================================");
    for(int index = 0; index < ARRAY_SIZE; index++)
    {
        delete animal[index];
        PRINT("===============an animal is deleted===============");
    }
    return 0;
}