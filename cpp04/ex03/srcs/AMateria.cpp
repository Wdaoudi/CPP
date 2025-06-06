#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
AMateria::AMateria(void)
{
    _type= "No Type";
    std::cout << "AMateria default constructor called " << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    _type = type;
    std::cout << "AMateria personnalized constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "Assingnement AMateria operator overload used" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

AMateria::AMateria(const AMateria &other)
{
    _type =other._type;
    std::cout << "AMateria copy constructor has been called" << std::endl;
    return ;
}
AMateria::~AMateria(void)
{
    std::cout  << "AMateria destructor has been called " << std::endl;
}

std::string const &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target) 
{
	std::cout << "Default AMateria use member function !!" << std::endl << "Nothing to " << target.getName() << std::endl;
}

