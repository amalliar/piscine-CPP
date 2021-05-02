/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:09:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 16:55:38 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class					Pony
{
	public:

		void			drawAscii(void) const;
		int				setAsciiColor(std::string const &rColor);

						Pony(void);
						Pony(Pony const &rSrc);
						~Pony(void);

		Pony			&operator=(Pony const &rRhs);

	private:

		std::string		_asciiColorFmtString;
		std::string		_memType;

		std::string		_getMemType(void *pStack) const;
		std::string		_strToLower(std::string const str) const;
};

#endif // PONY_HPP
