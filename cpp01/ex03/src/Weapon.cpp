/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:12 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:13 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(void)
{
    // std::cout << "default weapon constructor called" << std::endl;
}

Weapon::Weapon(std::string type): _type(type)
{
    this->_type = type;
    // std::cout << "perso weapon constructor called" << std::endl;
}
Weapon::~Weapon(void)
{
    // std::cout << "default weapon destructor called" << std::endl;
}

std::string const &Weapon:: getType() const
{
    return (this->_type);
}

void Weapon:: setType(std::string type)
{
    this->_type = type;
}