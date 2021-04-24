/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:42:20 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:23:09 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const		&Character::getName(void) const
{
	return (this->_name);
}

int						Character::getAP(void) const
{
	return (this->_ap);
}

AWeapon					*Character::getWeapon(void) const
{
	return (this->_pWeapon);
}

void					Character::equip(AWeapon *pWeapon)
{
	this->_pWeapon = pWeapon;
}

void					Character::attack(Enemy *pEnemy)
{
	if (!this->_pWeapon || !pEnemy || this->_ap < this->_pWeapon->getAPCost())
		return ;
	std::cout << this->_name << " attacks " << pEnemy->getType() << " with a " << \
		this->_pWeapon->getName() << std::endl;
	this->_pWeapon->attack();
	this->_ap -= this->_pWeapon->getAPCost();
	pEnemy->takeDamage(this->_pWeapon->getDamage());
	if (pEnemy->getHP() <= 0)
		delete pEnemy;
}

void					Character::recoverAP(void)
{
	if ((this->_ap += 10) > 40)
		this->_ap = 40;
}

						Character::Character(std::string const &rName) :
						_name(rName),
						_ap(40),
						_pWeapon(NULL)
{
}

						Character::~Character(void)
{
}

Character				&Character::operator=(Character const &rSrc)
{
	this->_name = rSrc._name;
	this->_ap = rSrc._ap;
	this->_pWeapon = rSrc._pWeapon;
	return (*this);
}

						Character::Character(void)
{
}

std::ostream			&operator<<(std::ostream &rOs, Character const &rRhs)
{
	AWeapon		*p_wpn;

	rOs << rRhs.getName() << " has " << rRhs.getAP() << " AP and ";
	if ((p_wpn = rRhs.getWeapon()))
		rOs << "wields a " << p_wpn->getName() << std::endl;
	else
		rOs << "is unarmed" << std::endl;
	return (rOs);
}
