/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:59:14 by schouite          #+#    #+#             */
/*   Updated: 2026/10/21 17:17:02 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
  public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	const Fixed &getX() const;
	const Fixed &getY() const;
	const Fixed &getDiff() const;
	~Point();

  private:
	Fixed const _x;
	Fixed const _y;
};

bool		bsp(Point const a, Point const b, Point const c, Point const point);
bool		areOnSameSide(Point const tested_Point, Point const point);
const Fixed	getPointSide(Point const ref_side, Point tested_side,
				Point const p);
const Fixed	handleVertical(Point const tested_side, Point const point);
const Fixed	handleHorizontal(Point const tested_side, Point const point);
const Fixed	handleStandard(Point const tested_side, Point const point);
#endif