#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal 
{


    public :

        Cat(void);
        Cat(std::string type);
        Cat(const Cat &copy);
        ~Cat(void);
        Cat &operator=(const Cat &other);

        void makeSound(void) const;


};


#endif