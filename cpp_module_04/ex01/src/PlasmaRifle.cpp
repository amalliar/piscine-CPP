/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:53:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:19:55 by amalliar         ###   ########.fr       */
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
	this->_name = rRhs.getName();
	this->_apcost = rRhs.getAPCost();
	this->_damage = rRhs.getDamage();
	return (*this);
}
