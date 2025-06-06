#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
    _Name = "No_Name";
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap default constructor has been called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    this->_Name = name;
    ClapTrap::_Name = name + "_clap_name";
    // std::cout << _Name << std::endl;
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap paremeter constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other)/*:  ClapTrap(other),  FragTrap(other),ScavTrap(other)*/
{
    *this = other;
    std::cout << "DiamondTrap copy  constructor has been called" <<std::endl;
    return ; 
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "Destructor DiamondTrap has been called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Assignement DiamondTrap operator used" << std::endl;
	if (this != &other)
	{
		this->_Name = other._Name;
        ClapTrap::_Name = other.ClapTrap::_Name;
		this->_EnergyPoints = other._EnergyPoints;
		this->_HitPoint = other._HitPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _Name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::_Name << std::endl;

}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}