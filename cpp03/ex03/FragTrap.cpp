#include "FragTrap.hpp"


FragTrap::FragTrap(void) /*: ClapTrap("noName")*/
{
    this->_HitPoint = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap default constructor has been called" << std::endl;
    return;
}
FragTrap::FragTrap(std::string name) :  ClapTrap(name)
{
    this->_HitPoint = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap personalized has been called" << std::endl; 
    return;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap copy  constructor has been called" <<std::endl;
    return ; 
}

FragTrap::~FragTrap(void)
{
    std::cout << "Destructor FragTrap has been called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Assignement FragTrap operator used" << std::endl;
	if (this != &other)
	{
		this->_Name = other._Name;
		this->_EnergyPoints = other._EnergyPoints;
		this->_HitPoint = other._HitPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (_EnergyPoints >= 1 && _HitPoint >= 1)
	{
		std::cout << "FragTrap " << _Name << " attacks " << target << ",causing ";
		std::cout << this->_AttackDamage << " points of damage !" << std::endl;
		_EnergyPoints--;
		std::cout << "Energy points remaining: " << _EnergyPoints << std::endl;
	}
	else
	{
		if (_EnergyPoints < 1)
			std::cout << "FragTrap " << _Name << "can t attack because of the lack of Energy point" << std::endl;
		else
			 std::cout << "FragTrap " << _Name << "can t attack because he is dead." << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
    if (_HitPoint >= 1)
        std::cout << "FragTrap "<< _Name <<" requests a high five! Let's spread some positivity!" << std::endl;
    else
        std::cout << "FragTrap " << _Name << " can t enter request for an high five because he is dead (any Hit points left)." << std::endl;

}