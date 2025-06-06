/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:31 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/26 13:46:36 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed ::Fixed(void): _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
// constructeur de copie 
Fixed :: Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

//operateur d affectation 
Fixed &Fixed::operator=(const Fixed &autre)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &autre)
    {
        this->_fixedPointValue = autre.getRawBits();
    }
        return *this;
}

// destructeur 
Fixed ::~Fixed ()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);   
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;

}