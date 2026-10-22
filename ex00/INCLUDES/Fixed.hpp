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

#ifndef FIXED_HPP
# define FIXED_HPP
class Fixed
{
  public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(const int raw);

  private:
	int _value;
	static int const fractionalBits = 8;
};
#endif