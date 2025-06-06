#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal 
{


    public :

        Dog(void);
        Dog(std::string type);
        Dog(const Dog &copy);
        ~Dog(void);
        Dog &operator=(const Dog &other);

        void makeSound() const;


};


#endif