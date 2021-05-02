/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:42:20 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:25:18 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const		&Character::getName(void) const
{
	return (_name);
}

int						Character::getAP(void) const
{
	return (_ap);
}

AWeapon					*Character::getWeapon(void) const
{
	return (_pWeapon);
}

void					Character::equip(AWeapon *pWeapon)
{
	_pWeapon = pWeapon;
}

void					Character::attack(Enemy *pEnemy)
{
	if (!_pWeapon || !pEnemy || _ap < _pWeapon->getAPCost())
		return ;
	std::cout << _name << " attacks " << pEnemy->getType() << " with a " << \
		_pWeapon->getName() << std::endl;
	_pWeapon->attack();
	_ap -= _pWeapon->getAPCost();
	pEnemy->takeDamage(_pWeapon->getDamage());
	if (pEnemy->getHP() <= 0)
		delete pEnemy;
}

void					Character::recoverAP(void)
{
	if ((_ap += 10) > 40)
		_ap = 40;
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

Character				&Character::operator=(Character const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs._name;
		_ap = rRhs._ap;
		_pWeapon = rRhs._pWeapon;
	}
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
