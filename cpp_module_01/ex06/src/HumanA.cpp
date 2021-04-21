/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:12:26 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 01:23:27 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void			HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_rWeapon.getType() << std::endl;
}

				HumanA::HumanA(std::string const &rName, Weapon &rWeapon) :
				_name(rName),
				_rWeapon(rWeapon)
{
}

				HumanA::HumanA(HumanA const &rSrc) :
				_name(rSrc._name),
				_rWeapon(rSrc._rWeapon)
{
}

				HumanA::~HumanA(void)
{
}

HumanA			&HumanA::operator=(HumanA const &rRhs)
{
	this->_name = rRhs._name;
	this->_rWeapon = rRhs._rWeapon;
	return (*this);
}
