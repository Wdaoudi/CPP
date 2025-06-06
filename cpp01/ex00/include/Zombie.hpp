/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:32:30 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 13:32:31 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>


class Zombie
{
    private: 
    std::string _name;
    
    public:
    /* constructeur */
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);

    /* methode */
    void setName(std::string name);
     void announce(void);
};

/* fonction implementee */

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif