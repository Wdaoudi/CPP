/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:27 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/04/01 16:34:45 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed {

    private :
    int _fixedPointValue ; // entier pour stocker la valeur  en bit du nombre de la virgule fixe
    static const int  _fractionnalBit = 8; // 8 pour le moment exemple : fixed(8,3) <00010110> 8 bits 3 right most bits are fractionnal
    //8 bit = 1 byte== 1 octet
    public :
    Fixed (void); // default
    Fixed(const int number);//int const
    Fixed(const float number);// float const
    Fixed (const Fixed& number); // copy
    ~Fixed (void);
    //asignement operator
    Fixed& operator=(const Fixed& autre);
    
    int getRawBits(void) const; // return the raw value of the fixed point 
    void setRawBits(int const raw);// set the raww value of the fixed point number

    float toFloat(void) const;
    int toInt(void) const;

    
};
//surcharge d operateur (en dehors de la classe car sinon std::ostream& = fixed soit l element de la classe)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 