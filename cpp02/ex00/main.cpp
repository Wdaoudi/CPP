/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/25 03:54:47 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

/*  expected output
$> ./a.out
 Default constructor called
 Copy constructor called
 Copy assignment operator called // <-- This line may be missing depending on your implementation
 getRawBits member function called
 Default constructor called
 Copy assignment operator called
 getRawBits member function called
 getRawBits member function called
 0
 getRawBits member function called
 0
 getRawBits member function called
 0
 Destructor called
 Destructor called
 Destructor called
*/