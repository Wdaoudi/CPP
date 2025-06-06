/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:32:36 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 13:32:37 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main()
{
    Zombie z1;
    Zombie z3("AAA");

    z3.announce();

    z1.setName("zzzzz");
    z1.announce();

    Zombie *z2 = newZombie("bob");
    z2->announce();

    randomChump("random chump");

    delete z2;
    return 0;
}