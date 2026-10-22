/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:18:10 by schouite          #+#    #+#             */
/*   Updated: 2026/10/22 10:48:28 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value * (1 << _fractionalBits);
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other._value;
	return (*this);
}
std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	float	value;

	value = other.toFloat();
	out << value;
	return (out);
}
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(const int raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	float floatValue;

	floatValue = (float)_value / (1 << _fractionalBits);
	return (floatValue);
}
int Fixed::toInt(void) const
{
	int intValue;

	intValue = _value / (1 << _fractionalBits);
	return (intValue);
}