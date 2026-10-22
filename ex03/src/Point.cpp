/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:03:38 by schouite          #+#    #+#             */
/*   Updated: 2026/10/22 10:41:39 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}
Point::~Point()
{
}
Point::Point(float x, float y) : _x(x), _y(y)
{
}
Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}
const Fixed &Point::getX() const
{
	return (_x);
}
const Fixed &Point::getY() const
{
	return (_y);
}
