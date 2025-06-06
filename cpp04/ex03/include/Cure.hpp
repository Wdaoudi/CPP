#pragma once //ifndef,define,endif

# include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
    private:
    public: 
    Cure(void);
    Cure(std::string const &type);//personalise
	Cure(const Cure &copy);//copy
	Cure &operator=(const Cure &other);//surcharge =
	virtual ~Cure(void);//dest

    std::string const &getType() const;
    Cure* clone() const;
    virtual void use(ICharacter& target);
    
};