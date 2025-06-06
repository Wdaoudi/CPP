#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <cstring>
# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    public: 
    // forme canonique orthodoxe
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap(void);

    void guardGate(void);
    void attack(const std::string &target);
};


#endif 