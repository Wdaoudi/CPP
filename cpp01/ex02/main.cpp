/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:07:37 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:07:38 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "memory address of the string variable "<<&str << std::endl;
    std::cout << "memory address held by stringPTR "<< stringPTR << std::endl;
    std::cout << "memory address held by stringREF "<<&stringREF << std::endl;
    
    std::cout << "value of the string "<< str << std::endl;
    std::cout << "value pointed by stringPTR "<< *stringPTR << std::endl;
    std::cout << "value pointed by stringREF "<< stringREF << std::endl;


    return (0);
}