#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{

    private:
    Brain* brain;

    public :

        Dog(void);
        Dog(std::string type);
        Dog(const Dog &copy);
        ~Dog(void);
        Dog &operator=(const Dog &other);

        void makeSound() const;
        std::string GetIdeas(int index);
        void SetIdeas(std::string ideas,  int index);

};


#endif