#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{

    protected :

        std::string _type;

    public :

        WrongAnimal(void);
        WrongAnimal(std::string type);// ???? ajouter un type peut etre
        WrongAnimal(const WrongAnimal &copy);
        virtual ~WrongAnimal(void);
        WrongAnimal &operator=(const WrongAnimal &other);

        virtual void makeSound() const;
        virtual std::string getType() const;


};


#endif