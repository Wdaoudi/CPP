#include "../include/Cat.hpp"

Cat::Cat(void)
{
    brain = new  Brain();
    _type= "Cat";
    std::cout << "Cat default constructor called " << std::endl;
}

Cat::Cat(std::string type)
{
    (void) type;
    
    brain = new Brain();
    _type = "Cat";
    std::cout << "Cat personnalized constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Assingnement Cat operator overload used" << std::endl;
    if (this != &other)
    {
        delete brain;
        Animal::operator=(other);
        _type = other._type;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::Cat(const Cat &other): Animal()
{
    _type = other._type;
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor has been called" << std::endl;
    return ;
}
Cat::~Cat(void)
{
    delete brain;
    std::cout  << "Cat destructor has been called " << std::endl;
}

void Cat::makeSound() const
{
    std::cout << getType() <<" MEOW" << std::endl;
}


std::string Cat :: GetIdeas(int index) 
{
	if (index > 99 || index < 0 ) index = 0;
	return (this->brain->GetIdeas(index));
}

void Cat::SetIdeas(std::string ideas,  int index)
{
	this->brain->SetIdeas(ideas, index);
}