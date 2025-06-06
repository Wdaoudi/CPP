#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    private :
        AMateria *book[4];

        void init_book(void);
        void clear_book(void);
        void copy_book(const MateriaSource &copy);

    public :
    MateriaSource(void);
    MateriaSource(std::string name);
    MateriaSource(const MateriaSource &copy);
    MateriaSource &operator=(const MateriaSource &other);
    ~MateriaSource(void);

    virtual void learnMateria(AMateria* spell);
    virtual AMateria* createMateria(std::string const & type);


};