#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{

    private:
        Brain* brain;

    public :

        Cat(void);
        Cat(std::string type);
        Cat(const Cat &copy);
        ~Cat(void);
        Cat &operator=(const Cat &other);

        void makeSound(void) const;
        std::string GetIdeas(int index);
        void SetIdeas(std::string ideas,  int index);


};


#endif