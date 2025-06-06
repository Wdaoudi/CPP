/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:14 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:15 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"
#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"

int main()
{
    {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
     {
     Weapon club = Weapon("crude spiked club");
     HumanB jim("Jim");
     jim.setWeapon(club);
     jim.attack();
     club.setType("some other type of club");
     jim.attack();
    }

    return 0;
}

// verifier les leaks au retours 