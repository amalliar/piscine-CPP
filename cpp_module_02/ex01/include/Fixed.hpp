/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:41:58 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 20:53:25 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class					Fixed
{
	public:
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		int					toInt(void) const;
		float				toFloat(void) const;

							Fixed(void);
							Fixed(Fixed const &rSrc);
							Fixed(int const iNum);
							Fixed(float const fNum);
							~Fixed(void);
		Fixed				&operator=(Fixed const &rRhs);

	private:
		int					_value;
		static const int	_fractBits = 8;
};

std::ostream				&operator<<(std::ostream &rOs, Fixed const &rRhs);

#endif // FIXED_HPP
