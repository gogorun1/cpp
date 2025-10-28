#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

#define PRINT(x) std::cout << x << std::endl;

class Brain
{
protected:
    static const int _ideaCount = 100;
    std::string _ideas[100];
    int _ideaIndex;
public:
    //ocf
    Brain();
    Brain(Brain const &other);
    Brain &operator=(Brain const &other);
    virtual ~Brain();

    //functions
    void setIdea(const std::string& idea);
    std::string getIdea(int index) const;
    void displayIdeas() const;
};

#endif