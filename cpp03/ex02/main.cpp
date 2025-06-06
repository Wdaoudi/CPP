#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap player1("wassim");
	FragTrap player2(player1);
	


	// FragTrap player3(player1);

	// player1.getAttack();
	// player3.getAttack();
	// player1.attack("test");
	// player3.attack(player2.getName());
	player2.highFivesGuys();
	player1.attack("test");


	return (0);
}

// int main(void)
// {
//     // Test des différents constructeurs
//     std::cout << "--- CREATING FRAGTRAP INSTANCES ---" << std::endl;
//     FragTrap frag1("Destroyer");
//     FragTrap frag2;
//     FragTrap frag3(frag1);  // Test du constructeur de copie
    
//     std::cout << "\n--- TESTING FRAGTRAP ATTRIBUTES ---" << std::endl;
//     std::cout << "FragTrap hit points, energy points and attack damage: " << std::endl;
//     // La fonction getAttack() affiche l'attack damage qui devrait être 30
//     frag1.getAttack();      // Devrait afficher 30
    
//     std::cout << "\n--- TESTING FRAGTRAP FIGHT CAPABILITIES ---" << std::endl;
//     // Test des fonctions de combat
//     frag1.attack("Enemy1");    // Attaque avec 30 de dégâts
//     frag1.takeDamage(20);      // Prend 20 de dégâts (reste 80 HP)
//     frag1.beRepaired(10);      // Réparation de 10 HP (remonte à 90 HP)
    
//     std::cout << "\n--- TESTING SPECIAL FUNCTION ---" << std::endl;
//     // Test de la fonction spéciale de FragTrap
//     frag1.highFivesGuys();     // Demande un high five
    
//     std::cout << "\n--- TESTING INHERITANCE ---" << std::endl;
//     // Test de l'héritage et fonction de ClapTrap
//     frag2.attack("Enemy2");    // Utilise la fonction attack surchargée
    
//     std::cout << "\n--- TESTING OPERATOR OVERLOAD ---" << std::endl;
//     // Test de l'opérateur d'affectation
//     frag2 = frag1;
//     frag2.attack("Enemy3");    // Devrait utiliser le même nom que frag1
    
//     // Cas limite: test quand les energy points sont épuisés
//     std::cout << "\n--- EDGE CASE: NO ENERGY POINTS LEFT ---" << std::endl;
//     // On simule l'épuisement des points d'énergie en attaquant plusieurs fois
//     for (int i = 0; i < 6; i++) {
//         std::cout << "Attack " << i+1 << ": ";
//         frag3.attack("Enemy4");  // Après 100 attaques, plus d'energy points
//     }
    
//     std::cout << "\n--- DESTRUCTORS SHOULD BE CALLED IN ORDER ---" << std::endl;
//     return 0;
// }