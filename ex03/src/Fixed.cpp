/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:48:19 by schouite          #+#    #+#             */
/*   Updated: 2026/10/21 23:07:17 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : _value(0)
{
}
Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}
Fixed::Fixed(const int value)
{
	_value = value * (1 << _fractionalBits);
}
Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits));
}
Fixed &Fixed::operator=(const Fixed &other)
{
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
bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (!(this->getRawBits() > other.getRawBits()));
}
bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (!(this->getRawBits() < other.getRawBits()));
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (!(this->getRawBits() == other.getRawBits()));
}
Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	if (left > right)
		return (left);
	return (right);
}
const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
	if (left > right)
		return (left);
	return (right);
}
Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	if (left < right)
		return (left);
	return (right);
}
const Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
	if (left < right)
		return (left);
	return (right);
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
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;

	res._value = _value + other._value;
	return (res);
}
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;

	res._value = _value - other._value;
	return (res);
}
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;

	res._value = _value * other._value / (1 << _fractionalBits);
	return (res);
}
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;

	res._value = _value * (1 << _fractionalBits)/ other._value;
	return (res);
}
Fixed &Fixed::operator++()
{
	this->_value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	this->_value++;
	return (old);
}
Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	this->_value--;
	return (old);
}
int Fixed::getRawBits() const
{
	return (_value);
}

void Fixed::setRawBits(const int raw)
{
	_value = raw;
}