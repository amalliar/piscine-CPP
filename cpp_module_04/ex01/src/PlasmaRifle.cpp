/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:53:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:29:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

void			PlasmaRifle::attack(void) const
{
	std::cout << CLR_BGREEN(* piouuu piouuu piouuu *) << std::endl;
}

				PlasmaRifle::PlasmaRifle(void) :
				AWeapon("Plasma Rifle", 5, 21)
{
}

				PlasmaRifle::PlasmaRifle(PlasmaRifle const &rSrc)
{
	*this = rSrc;
}

				PlasmaRifle::~PlasmaRifle(void)
{
}

PlasmaRifle		&PlasmaRifle::operator=(PlasmaRifle const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
		_apcost = rRhs.getAPCost();
		_damage = rRhs.getDamage();
	}
	return (*this);
}
