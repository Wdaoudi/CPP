/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:48 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:49 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

class Harl
{

    private :
        void debug();
        void info();
        void warning();
        void error();

    public:
            Harl();
            ~Harl();
            void complain(std::string level);
};

#endif