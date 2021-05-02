/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:59:38 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:09:36 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const		&Weapon::getType(void) const
{
	return (_type);
}

void					Weapon::setType(std::string const &rType)
{
	_type = rType;
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
	if (this != &rRhs)
	{
		_type = rRhs._type;
	}
	return (*this);
}

						Weapon::Weapon(void)
{
}
