/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:46 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "===test for debug===="<< std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "===test for INFO===="<< std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "===test for WARNING===="<< std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "===test for ERROR===="<< std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    return 0;
}