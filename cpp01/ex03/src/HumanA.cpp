/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:19 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:20 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weapon): _name(_name), _weapon(_weapon)
{
    // std::cout << "perso HumanA constructor called" << std::endl;

}

HumanA::~HumanA(void)
{
    // std::cout << "default HumanA destructor called" << std::endl;
}
void HumanA:: attack()
{
    std::cout << this->_name << " attacks with their "<< this->_weapon.getType() << std::endl;
}