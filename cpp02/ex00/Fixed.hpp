/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:27 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/04/04 15:05:04 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

/*
A default constructor: used internally to initialize objects and data members when no other value is available.
A copy constructor: used in the implementation of call-by-value parameters.
An assignment operator: used to assign one value to another.
A destructor: Invoked when an object is deleted.
*/

class Fixed {

    private :
    int _fixedPointValue ; //Stocke la valeur complète du nombre à virgule fixe (parties entière et fractionnaire)
    static const int  _fractionnalBit = 8; // 8 pour le moment exemple : fixed(8,3) <00010110> 8 bits 3 right most bits are fractionnal
    
    public :
    Fixed (void); // default
    Fixed (const Fixed& src); // copy
    Fixed& operator=(const Fixed& autre); // copy assignment operator overload
    ~Fixed (void);//destructor
    
    int getRawBits(void) const; // return the raw value of the fixed point 
    void setRawBits(int const raw);// set the raww value of the fixed point number
    
};

#endif 