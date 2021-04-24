/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:35:31 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:40:58 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const		&Character::getName(void) const
{
	return (this->_name);
}

AMateria const			*Character::getAMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_slots[idx]);
}

void					Character::equip(AMateria *pAmateria)
{
	for (int i = 0; i < 4; ++i)
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = pAmateria;
			return ;
		}
}

void					Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->_slots[idx] = NULL;
}

void					Character::use(int idx, ICharacter &rTarget)
{
	if (idx < 0 || idx > 3 || this->_slots[idx] == NULL)
		return ;
	this->_slots[idx]->use(rTarget);
}

						Character::Character(std::string const &rName) :
						_name(rName)
{
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = NULL;
}

						Character::Character(Character const &rSrc)
{
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = NULL;
	*this = rSrc;
}

						Character::~Character(void)
{
	this->_clearSlots();
}

Character				&Character::operator=(Character const &rRhs)
{
	AMateria const		*pAmateria;

	if (this == &rRhs)
		return (*this);
	this->_name = rRhs.getName();
	this->_clearSlots();
	for (int i = 0; i < 4; ++i)
		if ((pAmateria = rRhs.getAMateria(i)))
			this->_slots[i] = pAmateria->clone();
	return (*this);
}

void					Character::_clearSlots(void)
{
	for (int i = 0; i < 4; ++i)
		if (this->_slots[i] != NULL)
		{
			delete this->_slots[i];
			this->_slots[i] = NULL;
		}
}
