#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor has been called" << std::endl;
	init_book();
}

MateriaSource::MateriaSource(std::string name)
{
	(void)name;
	init_book();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource afffectation overload has been called";
	if (this != &other)
	{
		clear_book();
		init_book();
		copy_book(other);
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
	clear_book();
	init_book();
	copy_book(cpy);
	std::cout << "MateriaSource copy constructor has been called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor has been called" << std::endl;
	clear_book();
}

void MateriaSource::init_book()
{
	for (int i = 0; i < 4; i++)
		book[i] = NULL;
}

void MateriaSource::clear_book()
{
	for (int i = 0; i < 4; i++)
	{
		if (book[i])
		{
			delete (book[i]);
			book[i] = NULL;
		}
	}
}

void MateriaSource::copy_book(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.book[i] == NULL)
			book[i] = NULL;
		else
			book[i] = copy.book[i]->clone();
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	else
		return (NULL);
}

void MateriaSource::learnMateria(AMateria *spell)
{
	if (!spell)
	{
		std::cout << "AMateria is empty" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!book[i])
		{
			book[i] = spell->clone();
			delete spell;
			return ;
		}
	}
	std::cout << "book is full sry" << std::endl;
	delete spell;
}