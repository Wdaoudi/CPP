#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <cstring>
# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
    public :
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap(void);

    void highFivesGuys(void);
    void attack(const std::string &target);

};

#endif