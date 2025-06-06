/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:31 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/27 02:12:47 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed ::Fixed(void): _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
// constructeur de copie 
Fixed :: Fixed(const Fixed& number)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = number;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = number << this->_fractionnalBit ; 
    // deviens un entier virgule fixe en decalant de 8 bits vers la gauche 
}
Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(number * (1 << this->_fractionnalBit));
    // calcule d abord 2^8 en decalant les bits puis number et on arrondis
    // obtention d une representation a virgule fixe 
}

//operateur d affectation surcharge '='
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
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);   
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;

}

//inverser les constructeurs de type 
float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue/(float)(1<<this->_fractionnalBit));
    //implementation de virgule fixe vers float (virgule flottante)
}

int Fixed::toInt(void) const
{
    //implementation de virgule fixe vers int  
    return((this->_fixedPointValue >> this->_fractionnalBit));
}

//surcharge operateur
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat(); // pour conserver la partie decimale en virgule flottante
    return (os);
}
/*
std::ostream&os
std::ostream = classe de base pour les flux de sortie en c++ (comme cout ou cerr)
ref = eviter les copies et modifier le flux pas en creer un nouveau

const Fixed& fixed
ref d un objet volumineux
const pour pas modifier l objet
 
*/
