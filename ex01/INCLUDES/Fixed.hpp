/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:18:07 by schouite          #+#    #+#             */
/*   Updated: 2026/10/15 17:18:28 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

class Fixed
{
  public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;

  private:
	float _floatValue;
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &other);
