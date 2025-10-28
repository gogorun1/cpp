#include "Brain.hpp"

Brain::Brain(): _ideaIndex(0)
{
    PRINT("Brain default constructor called");
    for(int i = 0; i < _ideaCount; ++i)
    {
        _ideas[i] = "";
    }
}

Brain::Brain(Brain const &other): _ideaIndex(other._ideaIndex)
{
    PRINT("Brain copy constructor called");
    for(int i = 0; i < _ideaCount; ++i)
    {
        _ideas[i] = other._ideas[i];
    }
}

Brain &Brain::operator=(Brain const &other)
{
    PRINT("Brain assign operator called");
    if(this != &other)
    {
        _ideaIndex = other._ideaIndex;
        for(int i = 0; i < _ideaCount; ++i)
        {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    PRINT("Brain destructor called");
}

void Brain::setIdea(const std::string& idea)
{
    _ideas[_ideaIndex] = idea;
}

std::string Brain::getIdea(int index) const
{
    return _ideas[index];
}

void Brain::displayIdeas() const
{
    for(int i = 0; i < _ideaCount; ++i)
    {
        PRINT("The " << i << " index is " << _ideas[i]);
    }
}

