#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

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

        virtual void makeSound() const;
        virtual std::string getType() const;

};


#endif