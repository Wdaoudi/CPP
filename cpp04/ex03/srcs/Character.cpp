#include "../include/Character.hpp"

Character::Character(void)
{
    init_tab();
    _name = "No Name";
    std::cout << "Character default constructor has been called " << std::endl;
}

Character:: Character(std::string name)
{
    init_tab();
    _name = name;
    std::cout << "Character personalized constructor has been called " << std::endl;   
}

Character:: Character(const Character &copy)
{
    init_tab();
    _name = copy._name;
    cpy_tab(copy);
    std::cout << "Character copy constructor has been called " << std::endl;
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Character afffectation overload has been called";
    if (this != &other)
    {
        _name = other._name;
        clear_tab();
        init_tab();
        cpy_tab(other);
    }
    return (*this);
}

Character::~Character(void)
{
    std::cout << "Character destructor has been called" << std::endl;
    clear_tab();
}

std::string const &Character::getName(void) const
{
    return (_name);
}

void Character::init_tab(void)
{
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

void Character::clear_tab(void)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
        {
            delete(this->inventory[i]);
            inventory[i] = NULL;
        }
    }
}

void Character::cpy_tab(const Character &copy)
{
    for (int i = 0;i < 4;i++)
    {
        if(copy.inventory[i] == NULL)
            inventory[i] = NULL;
        else
            inventory[i] = copy.inventory[i]->clone();
    }
}

void Character::equip(AMateria* m)
{
    int i = 0;

    if (!m)
    {
        std::cout << "Invalid material!" << std::endl;
        return ;
    }
    while (i <= 3)
    {
        if(inventory[i] != NULL)
            i++;
        else
        {
            inventory[i] = m->clone();
            std::cout << "Equipement " << m->getType() << " have been equiped position " << i << std::endl;
            return;
        }    
    }
    std::cout << "can t equip the inventory is full." << std::endl;
}

void Character::use(int idx,ICharacter &target)
{
    if(idx < 0 || idx > 3 || inventory[idx]== NULL)
    {
        std::cout << "Not a valid index" <<std::endl;
        return;
    }
    // if (inventory[idx] == NULL)
    // {
    //     std::cout << "this emplacement is empty" << std::endl;
    //     return;
    // }
    
    inventory[idx]->use(target);
}

void Character::display_inventory()
{
    std::cout << "===============================" << std::endl;
    std::cout <<"Inventory of " << _name << ":" << std::endl;
    for(int i = 0; i < 4 ; i++)
    {
        if (inventory[i] == NULL)
            std::cout << "["<< i <<"]"<<": Empty" << std::endl;
        else 
            std::cout << "["<< i <<"]: " << inventory[i]->getType() << std::endl;
    }
    std::cout << "===========================" << std::endl;
}

void Character::unequip(int idx)
{
    if(idx < 0 || idx > 3 )
    {
        std::cout << "Not a valid index" <<std::endl;
        return;
    }
    if (inventory[idx] == NULL)
    {
        std::cout << "Can t unequip slot:" << idx << " because emplacement is empty" << std::endl;
        return;
    }
    std::cout << _name << " unequip a " << inventory[idx]->getType() << std::endl;
    inventory[idx] = NULL;
}

