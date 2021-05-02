/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:48:42 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:27:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "colors.hpp"

class						PlasmaRifle : public AWeapon
{
	public:

		virtual void		attack(void) const;

							PlasmaRifle(void);
							PlasmaRifle(PlasmaRifle const &rSrc);
		virtual				~PlasmaRifle(void);

		PlasmaRifle			&operator=(PlasmaRifle const &rRhs);
};

#endif // PLASMA_RIFLE_HPP
