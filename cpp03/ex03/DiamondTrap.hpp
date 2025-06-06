#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include <cstring>
# include <iostream>
# include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private :
	std::string _Name;

    public :
    
		//constructor
		DiamondTrap();//default
		DiamondTrap(std::string name);//personalised
		DiamondTrap(DiamondTrap &to_copy);//copy
		// Destructor
		~DiamondTrap();
		// Operator overloading
		DiamondTrap &operator=(const DiamondTrap &other);
		
		void attack(const std::string &target);
    	void whoAmI();


};



#endif