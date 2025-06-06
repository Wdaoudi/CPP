#pragma once //ifndef,define,endif

# include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
    private:
    public: 
    Ice(void);// default
    Ice(std::string const &type);//personalise
	Ice(const Ice &copy);//copy
	Ice &operator=(const Ice &other);//surcharge =
	virtual ~Ice(void);//dest

    std::string const &getType() const;
    Ice* clone() const;
    virtual void use(ICharacter& target);
};