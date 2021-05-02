/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:55:35 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:12:26 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class					Cure : public AMateria
{
	public:

		AMateria		*clone(void) const;
		void			use(ICharacter &rTarget);

						Cure(void);
						Cure(Cure const &rSrc);
						~Cure(void);

		Cure			&operator=(Cure const &rRhs);
};

#endif // CURE_HPP
