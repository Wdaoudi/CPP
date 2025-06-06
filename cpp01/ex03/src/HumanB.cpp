/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:17 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:18 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"


HumanB::HumanB(std::string _name): _name(_name),_weapon(NULL)
{
    // std::cout << "perso HumanA constructor called" << std::endl;

}
HumanB::HumanB(std::string _name,Weapon &weapon): _name(_name),_weapon(&weapon)
{
}



HumanB::~HumanB(void)
{
    // std::cout << "default HumanA destructor called" << std::endl;
}
void HumanB::setWeapon(Weapon& _weapon)
{
    this->_weapon = &_weapon;
}

void HumanB::attack()
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their "<< this->_weapon->getType() <<std::endl;
    else 
        std::cout << this->_name << " has no weapon to attack with " <<std::endl;

}
