/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:42:24 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:23:21 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

std::string const		&AWeapon::getName(void) const
{
	return (_name);
}

int						AWeapon::getAPCost(void) const
{
	return (_apcost);
}

int						AWeapon::getDamage(void) const
{
	return (_damage);
}

						AWeapon::AWeapon(std::string const &rName, int apcost, int damage) :
						_name(rName),
						_apcost(apcost),
						_damage(damage)
{
}

						AWeapon::AWeapon(AWeapon const &rSrc)
{
	*this = rSrc;
}

						AWeapon::~AWeapon(void)
{
}

AWeapon					&AWeapon::operator=(AWeapon const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
		_apcost = rRhs.getAPCost();
		_damage = rRhs.getDamage();
	}
	return (*this);
}

						AWeapon::AWeapon(void)
{
}
