#include "../include/Cat.hpp"

Cat::Cat(void)
{
    _type= "Cat";
    std::cout << "Cat default constructor called " << std::endl;
}

Cat::Cat(std::string type)
{
    (void) type;
    _type = "Cat";
    std::cout << "Cat personnalized constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Assingnement Cat operator overload used" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Cat::Cat(const Cat &other)
{
    *this = other;
    std::cout << "Cat copy constructor has been called" << std::endl;
    return ;
}
Cat::~Cat(void)
{
    std::cout  << "Cat destructor has been called " << std::endl;
}

void Cat::makeSound() const
{
    std::cout << getType() <<" MEOW" << std::endl;
}