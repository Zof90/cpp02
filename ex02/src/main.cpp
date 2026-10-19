/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:48:36 by schouite          #+#    #+#             */
/*   Updated: 2026/10/19 15:18:30 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed big(10);
	Fixed const small(5.5f);
	Fixed c;

	// c = big + small;
	// c++;
	// std::cout << Fixed::max(big, small) << std::endl;
	// std::cout << big << std::endl;
	// std::cout << small << std::endl;
	std::cout << big << std::endl;
	// --big;
	std::cout << ++big << std::endl;
}