#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap player1;
	ClapTrap player2("wassim");
	ClapTrap player3(player2);
	player1 = player2;
	
	player2.attack("test");
	player1.beRepaired(500);
	return (0);
}