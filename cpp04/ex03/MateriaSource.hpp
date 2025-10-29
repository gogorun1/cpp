#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[4]; // 存储学习到的 Materia 模板

public:
    MateriaSource();
    virtual ~MateriaSource();

    // OCF (也需要深拷贝，因为要复制模板 Materia)
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);

    // IMateriaSource 接口实现
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif