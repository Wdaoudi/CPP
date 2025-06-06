#include "../include/Cure.hpp"
#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure default constructor has been called" << std::endl;
}
Cure::Cure(std::string const &type) : AMateria("cure")
{
    (void)type;
    std::cout << "Cure personalized constructor has been called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Assignement Cure operator overload used" << std::endl;
    if(this != &other)
    {
    _type = other._type;
    }
    return (*this);
}

Cure::Cure(const Cure &other): AMateria(other._type)
{
    *this = other;
    std::cout << "Cure copy cosntructor has been called" << std::endl;
    return;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor has been called" << std::endl; 
}

Cure* Cure::clone() const
{
    std::cout << "Cure clone method has been called" << std::endl;
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << " * heals " << target.getName() << "'s wounds *" <<std::endl;
}
