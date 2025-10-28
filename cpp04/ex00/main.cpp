#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
//test 1
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << "===== Wrong Animal test =====" << std::endl;

//test 2
const WrongAnimal* d = new WrongAnimal();
const WrongAnimal* e = new WrongCat();
WrongCat f;
std::cout << d->getType() << " " << std::endl;
std::cout << e->getType() << " " << std::endl;
d->makeSound(); 
e->makeSound();//will output the wrong animal sound!
f.makeSound();//will output cat sound

return 0;
}