#include "../include/Dog.hpp"

Dog::Dog(void) : Animal()
{
    brain = new Brain();
    _type= "Dog";
    std::cout << "Dog default constructor called " << std::endl;
}

Dog::Dog(std::string type): Animal(type)
{
    (void)type;
    brain = new Brain();
    _type = "Dog";
    std::cout << "Dog personnalized constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Assingnement Dog operator overload used" << std::endl;
    if (this != &other)
    {
        delete brain;
        Animal::operator=(other);
        _type = other._type;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::Dog(const Dog &other) :Animal()
{
    _type = other._type;
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor has been called" << std::endl;
    return ;
}
Dog::~Dog(void)
{
    delete brain;
    std::cout  << "Dog destructor has been called " << std::endl;
}

void Dog::makeSound() const 
{
    std::cout <<  getType() <<" WOUAFF" << std::endl;
}

std::string Dog :: GetIdeas(int index) 
{
	if (index > 99 || index < 0 ) index = 0; // assign the index if isnt in range
	return (this->brain->GetIdeas(index));
}

void Dog::SetIdeas(std::string ideas,  int index)
{
	this->brain->SetIdeas(ideas, index);
}