/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:35:31 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:11:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const		&Character::getName(void) const
{
	return (_name);
}

AMateria const			*Character::getAMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (_slots[idx]);
}

void					Character::equip(AMateria *pAmateria)
{
	for (int i = 0; i < 4; ++i)
		if (_slots[i] == NULL)
		{
			_slots[i] = pAmateria;
			return ;
		}
}

void					Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	_slots[idx] = NULL;
}

void					Character::use(int idx, ICharacter &rTarget)
{
	if (idx < 0 || idx > 3 || _slots[idx] == NULL)
		return ;
	_slots[idx]->use(rTarget);
}

						Character::Character(std::string const &rName) :
						_name(rName)
{
	for (int i = 0; i < 4; ++i)
		_slots[i] = NULL;
}

						Character::Character(Character const &rSrc)
{
	for (int i = 0; i < 4; ++i)
		_slots[i] = NULL;
	*this = rSrc;
}

						Character::~Character(void)
{
	_clearSlots();
}

Character				&Character::operator=(Character const &rRhs)
{
	AMateria const		*pAmateria;

	if (this != &rRhs)
	{
		_name = rRhs.getName();
		_clearSlots();
		for (int i = 0; i < 4; ++i)
			if ((pAmateria = rRhs.getAMateria(i)))
				_slots[i] = pAmateria->clone();
	}
	return (*this);
}

void					Character::_clearSlots(void)
{
	for (int i = 0; i < 4; ++i)
		if (_slots[i] != NULL)
		{
			delete _slots[i];
			_slots[i] = NULL;
		}
}
