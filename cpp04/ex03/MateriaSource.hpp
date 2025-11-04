#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[4];

public:
    MateriaSource();
    virtual ~MateriaSource();

    // OCF 
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);

    // IMateriaSource 
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif