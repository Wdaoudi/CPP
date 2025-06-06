/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:33:25 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 13:33:26 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "constructor for zombie called" << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
    std::cout << "name constructor for zombie called" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "destructor for zombie called"<< std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name; // car defini dans une methode donc this tire sur l instance
}