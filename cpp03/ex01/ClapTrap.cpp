#include "ClapTrap.hpp"

// default
ClapTrap ::ClapTrap(void) : _Name("NoName"), _HitPoint(10), _EnergyPoints(10),
	_AttackDamage(0)
{
	std::cout << "Default constructor has been called" << std::endl;
}

ClapTrap ::ClapTrap(std::string name) : _Name(name), _HitPoint(10),
	_EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "personalized constructor with name has been called" << std::endl;
}
// copy
ClapTrap ::ClapTrap(const ClapTrap &copy) : _Name(copy._Name),
	_HitPoint(copy._HitPoint), _EnergyPoints(copy._EnergyPoints),
	_AttackDamage(copy._AttackDamage)
{
	std::cout << "Copy constructor has been called" << std::endl;
	*this = copy;
}
// destructor
ClapTrap ::~ClapTrap(void)
{
	std::cout << "Destructor has been called" << std::endl;
}
// operator overloading
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignement operator used" << std::endl;
	if (this != &other)
	{
		this->_Name = other._Name;
		this->_EnergyPoints = other._EnergyPoints;
		this->_HitPoint = other._HitPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

// member function
void ClapTrap::attack(const std::string &target)
{
	if (_EnergyPoints >= 1 && _HitPoint >= 1)
	{
		std::cout << "Claptrap " << _Name << " attacks " << target << ",causing ";
		std::cout << this->_AttackDamage << " points of damage !" << std::endl;
		_EnergyPoints--;
	}
	else
	{
		if (_EnergyPoints < 1)
			std::cout << "Claptrap " << _Name << "can t attack because of the lack of Energy point" << std::endl;
		else 
			std::cout << "Claptrap " << _Name << "can t attack because he is dead." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	// hit point
	// soustraire la vie
	if ( _HitPoint >= 1 )
	{
		std::cout << "Claptrap " << _Name << " take "  << amount << " damage " << std::endl;
		_HitPoint  = _HitPoint - amount;
		std::cout << "Hit point left: " << _HitPoint << std::endl;
	}
	else
		std::cout << "Claptrap " << _Name << " is already dead !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	// etre en vie
	// avoir des mp
	if (_HitPoint >= 1 && _EnergyPoints >= 1)
	{
		std::cout << "Claptrap " << _Name << " heal " << amount << " hitpoints" << std::endl;
		_HitPoint = _HitPoint + amount;
		std::cout << "Hit point left: " << _HitPoint << std::endl;
	}
	else 
	{
		if (_HitPoint < 1)
			std::cout << "Claptrap " << _Name << " is already dead !" << std::endl;
		else
			std::cout << "Claptrap " << _Name << " has no energy point" << std::endl;
	}
}

// unsigned int &ClapTrap::getHit()
// {
// 	return (_HitPoint);
// }

// unsigned int &ClapTrap::getEnergy()
// {
// 	return (_EnergyPoints);
// }

// unsigned int &ClapTrap::getAttack()
// {
// 	return (_AttackDamage);
// }

// std::string const ClapTrap::getName()
// {
// 	return (_Name);
// }
