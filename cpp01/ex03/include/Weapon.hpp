/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:07:50 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:07:51 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

class Weapon 
{
    public:
    Weapon(void);
    Weapon(std::string type); // constructeur personnalise
    ~Weapon(void);


    std::string const &getType() const;
    void setType(std::string type);

    private:
    std::string _type;

};

#endif