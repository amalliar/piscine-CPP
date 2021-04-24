/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:46:21 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:25:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class						AssaultTerminator : public ISpaceMarine
{
	public:
		ISpaceMarine		*clone(void) const;
		void				battleCry(void) const;
		void				rangedAttack(void) const;
		void				meleeAttack(void) const;

							AssaultTerminator(void);
							AssaultTerminator(AssaultTerminator const &rSrc);
							~AssaultTerminator(void);
		AssaultTerminator	&operator=(AssaultTerminator const &rRhs);
};

#endif // ASSAULT_TERMINATOR_HPP
