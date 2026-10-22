/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:18:07 by schouite          #+#    #+#             */
/*   Updated: 2026/10/22 10:46:54 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <ostream>

class Fixed
{
  public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;

  private:
	float _floatValue;
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);
#endif