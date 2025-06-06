/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:27 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/04/02 17:54:47 by wdaoudi-         ###   ########.fr       */
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
    int _fixedPointValue ;  //Stocke la valeur complète du nombre à virgule fixe (parties entière et fractionnaire) 
    static const int  _fractionnalBit = 8; //Spécifie combien de bits sont consacrés à la partie fractionnaire
    //variable static partagee entre tout les objets 
    
    public :
    Fixed (void); // default
    Fixed(const int number);//int const
    Fixed(const float number);// float const
    Fixed (const Fixed& number); // copy
    ~Fixed (void);
    
    int getRawBits(void) const; // return the raw value of the fixed point 
    int getFractionnalBits(void) const; // tentes de recuperer _fractionnalBit
    void setRawBits(int const raw);// set the raw value of the fixed point number
    
    float toFloat(void) const;
    int toInt(void) const;
    
    //asignement operator
    Fixed& operator=(const Fixed& autre);
    // nouvelle implementation
    //comparaison operator 
    bool operator<(const Fixed& right) const; // erreur prcq this sous-entendu
    bool operator>(const Fixed& right) const;
    bool operator>=(const Fixed& right) const;
    bool operator<=(const Fixed& right) const;
    bool operator==(const Fixed& right) const;
    bool operator!=(const Fixed& right) const;
    //arithmetic operator
    Fixed operator+(const Fixed& other)const;// le return en reference permet de chain le operation
    //l argument est const pour ne pas modifier la valeur 
    //est & pour envoyer une copie et ne pas avoir a faire une copie
    Fixed operator-(const Fixed& other)const;
    Fixed operator*(const Fixed& other)const;
    Fixed operator/(const Fixed& other)const;
    //increment/decrement operator 
    Fixed& operator++();//no parameter prefix
    Fixed operator++(int);//dummy parameter donc postfix
    Fixed& operator--();
    Fixed operator--(int);

    //public overloaded member function
    static const Fixed max(Fixed const &a,Fixed const &b);
    static  Fixed max(Fixed  &a,Fixed &b);
    static const Fixed min(Fixed const &a,Fixed const &b);
    static Fixed min(Fixed  &a,Fixed &b);
    //une methode static ne necessite pas d instance
    // ne peut pas utiliser this (qui est propre a chaque instance)
};  

//surcharge d operateur (en dehors de la classe car sinon std::ostream& = fixed soit l element de la classe)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);



#endif 