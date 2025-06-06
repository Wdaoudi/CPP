
#include "./include/AMateria.hpp"
#include "./include/IMateriaSource.hpp"
#include "./include/MateriaSource.hpp"
#include "./include/Ice.hpp"
#include "./include/Cure.hpp"
#include "./include/ICharacter.hpp"
#include "./include/Character.hpp"
#include <iostream>

int main()
{
    /*-------------------------TEST 1-------------------------*/
    std::cout << "\n\033[34m[TEST 1]\033[0m" << std::endl;
    {
        Character player_1("Bob");

        // Création et équipement avec gestion mémoire
        AMateria* cure_1 = new Cure();
        player_1.equip(cure_1);
        delete cure_1;  // Libération après clonage

        AMateria* ice_1 = new Ice();
        player_1.equip(ice_1);
        delete ice_1;

        AMateria* cure_2 = new Cure();
        player_1.equip(cure_2);
        delete cure_2;

        AMateria* ice_2 = new Ice();
        player_1.equip(ice_2);
        delete ice_2;

        // Test inventaire plein
        AMateria* cure_3 = new Cure();
        player_1.equip(cure_3); // Ne doit pas s'équiper
        delete cure_3;

        player_1.display_inventory();
    } // Les clones sont automatiquement supprimés ici

    /*-------------------------TEST 2-------------------------*/
    std::cout << "\n\033[34m[TEST 2]\033[0m" << std::endl;
    {
        Character player_2("Jack");
        
        AMateria* cure = new Cure();
        player_2.equip(cure);
        delete cure;

        AMateria* ice = new Ice();
        player_2.equip(ice);
        delete ice;

        player_2.use(0, player_2);
        player_2.use(1, player_2);
    }

    /*-------------------------TEST 3-------------------------*/
    std::cout << "\n\033[34m[TEST 3]\033[0m" << std::endl;
    {
        Character original("Original");
        AMateria *cure = new Cure();
        original.equip(cure);
        AMateria *ice = new Ice();
        original.equip(ice);

        Character copy(original);
        copy.display_inventory();
        delete cure;
        delete ice;
    }

    /*-------------------------TEST 4-------------------------*/
    std::cout << "\n\033[34m[TEST 4]\033[0m" << std::endl;
    {
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());

        Character wizard("Gandalf");
        AMateria* spell = src.createMateria("ice");
        wizard.equip(spell);
        delete spell;

        spell = src.createMateria("cure");
        wizard.equip(spell);
        delete spell;

        wizard.display_inventory();
    }

    /*---------------------TEST SUJET---------------------*/
    std::cout << "\n\033[34m[TEST SUJET]\033[0m" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria* tmp;
        
        tmp = src->createMateria("ice");
        me->equip(tmp);
        delete tmp;
        
        tmp = src->createMateria("cure");
        me->equip(tmp);
        delete tmp;

        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    return 0;
}