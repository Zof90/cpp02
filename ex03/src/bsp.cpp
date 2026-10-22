/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:39:37 by schouite          #+#    #+#             */
/*   Updated: 2026/10/22 10:41:45 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	areOnSameSide(const Fixed point_diff, const Fixed opposite_diff)
{
	if ((point_diff < 0 && opposite_diff < 0) || (point_diff > 0
			&& opposite_diff > 0))
		return (true);
	return (false);
}

const Fixed	handleVertical(const Point tested_side, const Point point)
{
	Fixed	diff;

	diff = point.getX() - tested_side.getX();
	return (diff);
}
const Fixed	handleHorizontal(const Point tested_side, const Point point)
{
	Fixed	diff;

	diff = point.getY() - tested_side.getY();
	;
	return (diff);
}
const Fixed	handleStandard(const Point ref_side, const Point tested_side,
		const Point point)
{
	Fixed	move_x;
	Fixed	move_y;
	Fixed	slope;
	Fixed	start_y;
	Fixed	diff;

	slope = (tested_side.getY() - ref_side.getY()) / (tested_side.getX()
			- ref_side.getX());
	move_x = point.getX() - ref_side.getX();
	move_y = move_x * slope;
	start_y = ref_side.getY() + move_y;
	diff = point.getY() - start_y;
	return (diff);
}
const Fixed	getPointSide(Point const ref_side, Point const tested_side,
		Point const point)
{
	Fixed	diff;

	if (ref_side.getX() == tested_side.getX())
		diff = handleVertical(tested_side, point);
	else if (ref_side.getY() == tested_side.getY())
		diff = handleHorizontal(tested_side, point);
	else
		diff = handleStandard(ref_side, tested_side, point);
	return (diff);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed point_diff;
	Fixed opposite_diff;

	point_diff = getPointSide(a, b, point);
	opposite_diff = getPointSide(a, b, c);
	if (!areOnSameSide(point_diff, opposite_diff))
		return (false);
	point_diff = getPointSide(a, c, point);
	opposite_diff = getPointSide(a, c, b);
	if (!areOnSameSide(point_diff, opposite_diff))
		return (false);
	point_diff = getPointSide(b, c, point);
	opposite_diff = getPointSide(b, c, a);
	if (!areOnSameSide(point_diff, opposite_diff))
		return (false);
	return (true);
}