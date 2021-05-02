/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:55:35 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:13:44 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class					Ice : public AMateria
{
	public:

		AMateria		*clone(void) const;
		void			use(ICharacter &rTarget);

						Ice(void);
						Ice(Ice const &rSrc);
						~Ice(void);

		Ice				&operator=(Ice const &rRhs);
};

#endif // ICE_HPP
