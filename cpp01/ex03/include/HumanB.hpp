/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:07:53 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/04/05 22:22:18 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include "./Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string _name);
        HumanB(std::string _name,Weapon &weapon);
        ~HumanB(void);

        void attack();
        void setWeapon(Weapon& _weapon);

    private:
         Weapon* _weapon;
        std::string _name;

};



#endif