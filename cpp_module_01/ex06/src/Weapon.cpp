/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:59:38 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 01:18:35 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const		&Weapon::getType(void) const
{
	return (this->_type);
}

void					Weapon::setType(std::string const &rType)
{
	this->_type = rType;
}

						Weapon::Weapon(std::string const &rType) :
						_type(rType)
{
}

						Weapon::Weapon(Weapon const &rSrc) :
						_type(rSrc._type)
{
}

						Weapon::~Weapon(void)
{
}

Weapon					&Weapon::operator=(Weapon const &rRhs)
{
	this->_type = rRhs._type;
	return (*this);
}

						Weapon::Weapon(void)
{
}
