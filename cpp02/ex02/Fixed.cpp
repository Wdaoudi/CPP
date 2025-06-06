/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:31 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/04/02 18:06:53 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed ::Fixed(void) : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}
// constructeur de copie
Fixed ::Fixed(const Fixed &number)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

Fixed::Fixed(const int number)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = number << this->_fractionnalBit;
	// deviens un entier virgule fixe en decalant de 8 bits vers la gauche
}
Fixed::Fixed(const float number)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(number * (1 << this->_fractionnalBit));
	// calcule d abord 2^8 en decalant les bits puis number et on arrondis
	// obtention d une representation a virgule fixe
}

// operateur d affectation surcharge '='
Fixed &Fixed::operator=(const Fixed &autre)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &autre)
	{
		this->_fixedPointValue = autre.getRawBits();
	}
	return (*this);
}

// destructeur
Fixed ::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

int Fixed::getFractionnalBits(void) const
{
	return (this->_fractionnalBit);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

// inverser les constructeurs de type
float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionnalBit));
	// implementation de virgule fixe vers float (virgule flottante)
}

int Fixed::toInt(void) const
{
	// implementation de virgule fixe vers int
	return ((this->_fixedPointValue >> this->_fractionnalBit));
}

// surcharge operateur
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
		// pour conserver la partie decimale en virgule flottante
	return (os);
}

bool Fixed::operator<(const Fixed &right) const
{
	return (/*this->*/getRawBits() < right.getRawBits());
	//unecessary this because the left hand side is implied 
}

bool Fixed::operator>(const Fixed &right) const
{
	return (this->getRawBits() > right.getRawBits());
}

bool Fixed::operator>=(const Fixed &right) const
{
	return (this->getRawBits() >= right.getRawBits());
}

bool Fixed::operator<=(const Fixed &right) const
{
	return (this->getRawBits() <= right.getRawBits());
}

bool Fixed::operator==(const Fixed &right) const
{
	return (this->getRawBits() == right.getRawBits());
}

bool Fixed::operator!=(const Fixed &right) const
{
	return (this->getRawBits() != right.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	// _fixedPointValue = _fixedPointValue+ other._fixedPointValue;// modifie la valeurs sous entendu par le this
	Fixed result(*this);
	result._fixedPointValue += other._fixedPointValue;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result(*this);
	result._fixedPointValue -= other._fixedPointValue;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	// Fixed result;
	// result._fixedPointValue = (other._fixedPointValue* this->_fixedPointValue) >> _fractionnalBit;//decalage necessaire
	// car lorsqu on multiplie les valeurs les fractionnal bit s additionnent
	// donc on dois soit diviser par 2^8 soit decalee de 8 bits
	// return (result);//decalage de bit plus compliquee
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	// Fixed result;
    // result._fixedPointValue = (((long long)_fixedPointValue) << _fractionnalBit) / other._fixedPointValue;
    // return (result);
	return Fixed(this->toFloat() / other.toFloat());
}

// prefix
Fixed &Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);//self referencing pointer
	// copie de this renvoye modifie	
}
Fixed &Fixed::operator--()
{
	_fixedPointValue --;
	return (*this);//self referencing pointer
	// copie de this renvoye modifie	
}

/*postfix methode:
1.preserve original object state
2. update the object
3.return the preserved object state
*/
Fixed Fixed::operator++(int)
{
	Fixed temp=*this;
	++*this;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp=*this;
	--*this;
	return (temp);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
Fixed const Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
Fixed const Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}
/*
std::ostream&os
std::ostream = classe de base pour les flux de sortie en c++ (comme cout ou cerr)
ref = eviter les copies et modifier le flux pas en creer un nouveau

const Fixed& fixed
ref d un objet volumineux
const pour pas modifier l objet
*/
