/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:41:58 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 20:46:20 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class						Fixed
{
	public:
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

							Fixed(void);
							Fixed(Fixed const &rSrc);
							~Fixed(void);
		Fixed				&operator=(Fixed const &rRhs);

	private:
		int					_value;
		static const int	_fractBits = 8;
};

#endif // FIXED_HPP
