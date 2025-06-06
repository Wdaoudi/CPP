/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/04/02 17:58:22 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



// int	main(void)
// {
	// 	Fixed a(3.47f);
	// 	Fixed b(3);
	// 	Fixed const c(5);
	// 	Fixed const d(6);
	// 	// Fixed const b(Fixed(5.05f) * Fixed(2));
	
	// 	// std::cout << (b < a) << std::endl;//1
	// 	// std::cout << (b > a) << std::endl;//0
	// 	// std::cout << (b >= a) << std::endl;//0
	// 	// std::cout << (b <= a) << std::endl;//1
	// 	// std::cout << (b==a) << std::endl;//0
	// 	// std::cout << (b!=a) << std::endl;//1
	// 	// std::cout << (b+a) << std::endl;//6.468785 ?
	// 	// std::cout << b << std::endl;
	// 	// std::cout << (b-a) << std::endl;
	// 	// std::cout << b << std::endl;
	// 	// std::cout << (b*a) << std::endl;//10.40625
	// 	// std::cout << b << std::endl;
	// 	// std::cout << (b/a) << std::endl;//0.86455331412
	
	// 	std::cout << a << std::endl;//3.46875
	// 	std::cout << b << std::endl;//3
	// 	// std::cout << b << std::endl;//3
	// 	// std::cout << ++b << std::endl;//4
	// 	// std::cout << b << std::endl;//4
	// 	// std::cout << --b << std::endl;//3
	// 	// std::cout << b << std::endl;//3
	
	// 	// std::cout << b++ << std::endl;//3
	// 	// std::cout << b << std::endl;//4
	// 	// std::cout << b-- << std::endl;//4
	// 	// std::cout << b << std::endl;//3
	
	// 	// std::cout << Fixed::max(a,b) << std::endl;
	// 	// std::cout << Fixed::min(a,b) << std::endl;
	// 	// std::cout << Fixed::max(c,d) << std::endl;
	// 	// std::cout << Fixed::min(c,d) << std::endl;
	
	// 	// std::cout << ++a << std::endl;
	// 	// std::cout << a << std::endl;
	// 	// std::cout << a++ << std::endl;
	// 	// std::cout << a << std::endl;
	// 	// std::cout << b << std::endl;
	// 	// std::cout << Fixed::max(a, b) << std::endl;
	// 	// return (0);
	// }
	int	main(void)
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		return (0);
	}
	
/*
expected output 
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/