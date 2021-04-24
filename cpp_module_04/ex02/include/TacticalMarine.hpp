/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:46:21 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:32:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class						TacticalMarine : public ISpaceMarine
{
	public:
		ISpaceMarine		*clone(void) const;
		void				battleCry(void) const;
		void				rangedAttack(void) const;
		void				meleeAttack(void) const;

							TacticalMarine(void);
							TacticalMarine(TacticalMarine const &rSrc);
							~TacticalMarine(void);
		TacticalMarine		&operator=(TacticalMarine const &rRhs);
};

#endif // TACTICAL_MARINE_HPP
