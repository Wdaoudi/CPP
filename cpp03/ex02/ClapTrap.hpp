#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <cstring>
# include <iostream>
# include <string>

class ClapTrap
{
  protected:
	std::string _Name;
	unsigned int _HitPoint;     // pv
	unsigned int _EnergyPoints; //mp 1 cost
	unsigned int _AttackDamage; //dps

  public:
	//constructor
	ClapTrap(void);                 //default
	ClapTrap(std::string _name);    // default with name
	ClapTrap(const ClapTrap &copy); //copy
									//destructor
	~ClapTrap(void);
	//assignement operator overloading
	ClapTrap &operator=(const ClapTrap &Claptrap);

	//member function (fixe)
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//necessary function
	// unsigned int &getHit();
	// unsigned int &getEnergy();
	unsigned int &getAttack();
	std::string const getName();
};

#endif