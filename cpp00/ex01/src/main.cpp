/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:57:14 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/18 14:23:48 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"


int main(int ac, char **av)
{
    PhoneBook instance;
    std::string name;

	std::cout << "please tell me your name" << std :: endl;
	std::cin >> name;
	std::cout << "hello " << name << std :: endl;
    instance.StartPrompting();
    std::cout << "Thanks " << name << " for using the PhoneBook see u next time <3" << std::endl;
    return (0);
}