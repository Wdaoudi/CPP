#include "../include/Dog.hpp"

Dog::Dog(void) : Animal()
{
    _type= "Dog";
    std::cout << "Dog default constructor called " << std::endl;
}

Dog::Dog(std::string type): Animal(type)
{
    _type = "Dog";
    std::cout << "Dog personnalized constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Assingnement Dog operator overload used" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Dog::Dog(const Dog &other)
{
    *this = other;
    std::cout << "Dog copy constructor has been called" << std::endl;
    return ;
}
Dog::~Dog(void)
{
    std::cout  << "Dog destructor has been called " << std::endl;
}

void Dog::makeSound() const 
{
    std::cout <<  getType() <<" WOUAFF" << std::endl;
}