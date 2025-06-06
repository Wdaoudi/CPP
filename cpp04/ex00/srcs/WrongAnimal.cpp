#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    _type= "Notype";
    std::cout << "WrongAnimal default constructor called " << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    (void)type;
    _type = "Notype";
    std::cout << "WrongAnimal personnalized constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "Assingnement WrongAnimal operator overload used" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "WrongAnimal copy constructor has been called" << std::endl;
    return ;
}
WrongAnimal::~WrongAnimal(void)
{
    std::cout  << "WrongAnimal destructor has been called " << std::endl;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "No sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}