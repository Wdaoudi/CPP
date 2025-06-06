#include "../include/Animal.hpp"

Animal::Animal(void)
{
    _type= "Animal";
    std::cout << "Animal default constructor called " << std::endl;
}

Animal::Animal(std::string type)
{
    (void)type;
    _type = "Animal";
    std::cout << "Animal personnalized constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Assingnement Animal operator overload used" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Animal copy constructor has been called" << std::endl;
    return ;
}
Animal::~Animal(void)
{
    std::cout  << "Animal destructor has been called " << std::endl;
}

void Animal::makeSound() const 
{
    std::cout << "No sound" << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}