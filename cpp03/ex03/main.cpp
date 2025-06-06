#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap player1("zeus");
    DiamondTrap player2;
    player2 = player1;

    player1.whoAmI();
    player2.whoAmI();
    return 0;
}