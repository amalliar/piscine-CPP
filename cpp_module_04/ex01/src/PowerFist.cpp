/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:53:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:27:59 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

void			PowerFist::attack(void) const
{
	std::cout << CLR_BYELLOW(* pschhh... SBAM! *) << std::endl;
}

				PowerFist::PowerFist(void) :
				AWeapon("Power Fist", 8, 50)
{
}

				PowerFist::PowerFist(PowerFist const &rSrc)
{
	*this = rSrc;
}

				PowerFist::~PowerFist(void)
{
}

PowerFist		&PowerFist::operator=(PowerFist const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
		_apcost = rRhs.getAPCost();
		_damage = rRhs.getDamage();
	}
	return (*this);
}
