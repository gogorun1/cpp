#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "iostream"
#include "string"


Base *generate(void)
{
    switch (std::rand() % 3)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    };
    return NULL;
}

void identify(Base *p)
{
    if (p == NULL)
    {
        std::cout << "Null Pointer Received" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p) == p)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) == p)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) == p)
        std::cout << "C" << std::endl;
    else
        std::cout << "Undefined Class" << std::endl;
}

void identify(Base& p) 
{
    // std::cout << "Identify ref" << std::endl;
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {} 

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) {}
}

int main()
{
    std::srand(std::time(0));
    for (int i = 1; i < 10; ++i)
    {
        Base *test = generate();
        std::cout << "Pointer:   ";
        identify(test);
        std::cout << "Reference: ";
        identify(*test);
    }
}