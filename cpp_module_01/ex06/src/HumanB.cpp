/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:21:59 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 01:19:32 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void			HumanB::attack(void) const
{
	if (this->_pWeapon != NULL)
		std::cout << this->_name << " attacks with his " << this->_pWeapon->getType() << std::endl;
}

void			HumanB::setWeapon(Weapon &rWeapon)
{
	this->_pWeapon = &rWeapon;
}

				HumanB::HumanB(std::string const &rName) :
				_name(rName),
				_pWeapon(NULL)
{
}

				HumanB::HumanB(HumanB const &rSrc) :
				_name(rSrc._name),
				_pWeapon(rSrc._pWeapon)
{
}

				HumanB::~HumanB(void)
{
}

HumanB			&HumanB::operator=(HumanB const &rRhs)
{
	this->_name = rRhs._name;
	this->_pWeapon = rRhs._pWeapon;
	return (*this);
}

				HumanB::HumanB(void)
{
}
