/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:07:56 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:07:57 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include "./Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string _name,Weapon& _weapon);
        ~HumanA(void);

        void attack();

    private:
         Weapon& _weapon;
        std::string _name;

};

#endif