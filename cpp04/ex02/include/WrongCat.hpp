#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
    public :

        WrongCat(void);
        WrongCat(std::string type);
        WrongCat(const WrongCat &copy);
        ~WrongCat(void);
        WrongCat &operator=(const WrongCat &other);
        
        void makeSound() const;
};


#endif