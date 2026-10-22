/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:59:14 by schouite          #+#    #+#             */
/*   Updated: 2026/10/22 11:32:38 by schouite         ###   ########.fr       */
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
	~Point();

  private:
	Fixed const _x;
	Fixed const _y;
};

bool		bsp(Point const a, Point const b, Point const c, Point const point);
bool		areOnSameSide(const Fixed point_diff, const Fixed opposite_diff);
const Fixed	getPointSide(Point const ref_side, Point tested_side,
				Point const p);
const Fixed	handleVertical(const Point ref_side, const Point opposite_diff,
				const Point point);
const Fixed	handleHorizontal(const Point ref_side, const Point opposite_diff,
				const Point point);
const Fixed	handleStandard(const Point ref_side, const Point opposite_diff,
				const Point point);
#endif