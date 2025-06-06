#include "../include/Ice.hpp"
#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

Ice::Ice(void) :AMateria("ice")
{
    std::cout << "Ice default constructor has been called" << std::endl;
}
Ice::Ice(std::string const &type): AMateria("ice")
{
    (void)type;
    std::cout << "Ice personalized constructor has been called" << std::endl;
}
Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Assignement Ice operator overload used" << std::endl;
    if(this != &other)
    {
    _type = other._type;
    }
    return (*this);
}

Ice::Ice(const Ice &other): AMateria(other._type)
{
    *this = other;
    std::cout << "Ice copy cosntructor has been called" << std::endl;
    return;
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor has been called" << std::endl; 
}
Ice* Ice::clone() const
{
    std::cout << "Ice clone method has been called" << std::endl;
    return (new Ice(*this));
}


void Ice::use(ICharacter& target)
{
    std::cout << " * shoots an ice bolt at " << target.getName()<< " *"<<std::endl;
}

