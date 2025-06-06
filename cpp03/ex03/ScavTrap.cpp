#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->_HitPoint = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap default constructor has been called" << std::endl;
    return;
}
ScavTrap::ScavTrap(std::string name) :  ClapTrap(name)
{
	this->_Name = name;
    this->_HitPoint = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap personalized has been called" << std::endl; 
    return;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Assignement ScavTrap operator used" << std::endl;
	if (this != &other)
	{
		this->_Name = other._Name;
		this->_EnergyPoints = other._EnergyPoints;
		this->_HitPoint = other._HitPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	return (*this);
}


ScavTrap::ScavTrap(ScavTrap &other) /*: ClapTrap(other)*/
{
    *this = other;
    std::cout << "ScavTrap copy  constructor has been called" <<std::endl;
    return ; 

}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor ScavTrap has been called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_EnergyPoints >= 1 && _HitPoint >= 1)
	{
		std::cout << "ScavTrap " << _Name << " attacks " << target << ",causing ";
		std::cout << this->_AttackDamage << " points of damage !" << std::endl;
		_EnergyPoints--;
	}
	else
	{
		if (_EnergyPoints < 1)
			std::cout << "ScavTrap " << _Name << "can t attack because of the lack of Energy point" << std::endl;
		else
			 std::cout << "ScavTrap " << _Name << "can t attack because he is dead." << std::endl;
	}
}

void ScavTrap::guardGate()
{
    if (_HitPoint >= 1)
    {
        std::cout << "ScavTrap " << _Name << " is entering in Gate keeper mode." << std::endl;
    }
    else
        std::cout << "ScavTrap " << _Name << " can t enter in Gate keeper mode because he is dead." << std::endl;
}