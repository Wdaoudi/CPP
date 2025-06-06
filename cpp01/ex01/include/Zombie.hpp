/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:33:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 13:33:17 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Zombie
{
    private : 
    std::string _name;
    
    public: 
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    
    //methode
    void announce(void);
    void setName(std::string name);
    
};
//fonction 
Zombie* zombieHorde(int N, std::string name);

#endif