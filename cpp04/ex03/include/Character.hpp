#pragma once

#include "./ICharacter.hpp"
#include "./AMateria.hpp"
#include <iostream>


class Character: public ICharacter
{
    private :
        std::string _name;
        AMateria *inventory[4];
        
        
        public :
        Character(void);
        Character(std::string name);
        Character(const Character &copy);
        Character &operator=(const Character &other);
        ~Character(void);
        
        //heritee de l interface
        virtual std::string const &getName(void) const;
        virtual void equip(AMateria* m); //a faire avec unequip et use 
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

        //utils
        void init_tab(void);
        void clear_tab(void);
        void cpy_tab(const Character &copy);
        //supp pour verif
	void display_inventory();

};