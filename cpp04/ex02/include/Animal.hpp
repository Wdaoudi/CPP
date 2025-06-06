#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

/*
classe abstraite = Ne peut pas être instanciée directement
Contient au moins une fonction virtuelle pure (déclarée avec = 0)
Sert de "contrat" que les classes dérivées doivent respecter

interface = classe abstraite qui ne contient que des classe virtuelle pure



*/
class Animal
{

    protected :

        std::string _type;

    public :

        Animal(void);
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal &operator=(const Animal &other);
        virtual ~Animal(void);

        virtual void makeSound() const = 0;
        virtual std::string getType() const;

};


#endif