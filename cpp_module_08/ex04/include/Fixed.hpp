/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:41:58 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 22:22:08 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class						Fixed
{
	public:
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		int					toInt(void) const;
		float				toFloat(void) const;

		static Fixed		&min(Fixed &rLhs, Fixed &rRhs);
		static Fixed const	&min(Fixed const &rLhs, Fixed const &rRhs);
		static Fixed		&max(Fixed &rLhs, Fixed &rRhs);
		static Fixed const	&max(Fixed const &rLhs, Fixed const &rRhs);

							Fixed(void);
							Fixed(Fixed const &rSrc);
							Fixed(int const iNum);
							Fixed(float const fNum);
							~Fixed(void);
		Fixed				&operator=(Fixed const &rRhs);
		bool				operator>(Fixed const &rRhs) const;
		bool				operator<(Fixed const &rRhs) const;
		bool				operator>=(Fixed const &rRhs) const;
		bool				operator<=(Fixed const &rRhs) const;
		bool				operator==(Fixed const &rRhs) const;
		bool				operator!=(Fixed const &rRhs) const;
		Fixed				operator+(Fixed const &rRhs) const;
		Fixed				operator-(Fixed const &rRhs) const;
		Fixed				operator*(Fixed const &rRhs) const;
		Fixed				operator/(Fixed const &rRhs) const;
		Fixed				operator++(void);
		Fixed				operator++(int);
		Fixed				operator--(void);
		Fixed				operator--(int);

	private:
		int					_value;
		static const int	_fractBits = 8;
};

std::ostream				&operator<<(std::ostream &rOs, Fixed const &rRhs);

#endif // FIXED_HPP
