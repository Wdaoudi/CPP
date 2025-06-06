#include "../include/Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called " << std::endl;
}

Brain::Brain(std::string type)
{
    (void)type;
    std::cout << "Brain personnalized constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Assingnement Brain operator overload used" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100 ; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Brain copy constructor has been called" << std::endl;
    return ;
}
Brain::~Brain(void)
{
    std::cout  << "Brain destructor has been called " << std::endl;
}

void Brain::SetIdeas(std::string& id, int index)
{
    if (index < 100 && index > -1)
        ideas[index] = id;
    else
        std::cout << "Don t have enough place to set ideas!" << std::endl;
}

std::string Brain::GetIdeas(int index) const 
{
	if (index < 0 || index > 99)
    	return NULL;
	return (ideas[index]);
	
}