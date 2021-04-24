/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:42:24 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:10:53 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

std::string const		&AWeapon::getName(void) const
{
	return (this->_name);
}

int						AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}

int						AWeapon::getDamage(void) const
{
	return (this->_damage);
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
	this->_name = rRhs.getName();
	this->_apcost = rRhs.getAPCost();
	this->_damage = rRhs.getDamage();
	return (*this);
}

						AWeapon::AWeapon(void)
{
}
