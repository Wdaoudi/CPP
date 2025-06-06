#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	// ScavTrap player1("wassim");
	// ScavTrap player2;
	// player2 = player1;
	// ScavTrap player3(player1);

	// player1.attack("test");
	// player3.attack("TEST2");
	ScavTrap player1("test");
	ScavTrap player2(player1);
	// player1.guardGate();
	// player2.guardGate();

	return (0);
}