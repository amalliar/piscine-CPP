/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlienBlaster.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:53:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:12:06 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlienBlaster.hpp"

void			AlienBlaster::attack(void) const
{
	std::cout << CLR_BBLUE(* zappp *) << std::endl;
}

				AlienBlaster::AlienBlaster(void) :
				AWeapon("Alien Blaster", 4, 179)
{
}

				AlienBlaster::AlienBlaster(AlienBlaster const &rSrc)
{
	*this = rSrc;
}

				AlienBlaster::~AlienBlaster(void)
{
}

AlienBlaster	&AlienBlaster::operator=(AlienBlaster const &rRhs)
{
	this->_name = rRhs.getName();
	this->_apcost = rRhs.getAPCost();
	this->_damage = rRhs.getDamage();
	return (*this);
}
