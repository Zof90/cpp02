/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Counter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:55:47 by schouite          #+#    #+#             */
/*   Updated: 2026/10/12 16:27:54 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
	static const int fractionalBits = 8;

  public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;

  private:
	int _value;
};