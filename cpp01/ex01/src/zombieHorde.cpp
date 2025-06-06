/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:33:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 13:47:41 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

// Zombie* zombieHorde(int N, std::string name)
// {
// 	Zombie	*z[N];

// 	for (int i = 0; i < N; i++)
// 	{
// 		z[i] = new Zombie(name);
// 		std::cout << "tentative de mise en place des hordes nommee " << std::endl;
// 		z[i]->announce();
// 	}
// 	return (*z);
// }

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		std::cout << "tentative de mise en place des hordes nommee " << std::endl;
		horde[i].announce();
	}
	return (horde);
}