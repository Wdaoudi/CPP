#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void)
{
    _type= "WrongCat";
    std::cout << "WrongCat default constructor called " << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    (void)type;
    _type = "WrongCat";
    std::cout << "WrongCat personnalized constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "Assingnement WrongCat operator overload used" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
    *this = other;
    std::cout << "WrongCat copy constructor has been called" << std::endl;
    return ;
}
WrongCat::~WrongCat(void)
{
    std::cout  << "WrongCat destructor has been called " << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Can t meow" << std::endl;
}