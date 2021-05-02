/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:01:15 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:14:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void			MateriaSource::learnMateria(AMateria *pAmateria)
{
	if (pAmateria == NULL)
		return ;
	if (_slots[_idx_free] != NULL)
		delete _slots[_idx_free];
	_slots[_idx_free] = pAmateria->clone();
	_idx_free = (_idx_free + 1) % 4;
}

AMateria		*MateriaSource::createMateria(std::string const &rType)
{
	for (int i = 0; i < 4; ++i)
		if (_slots[i] != NULL)
		{
			if (!_slots[i]->getType().compare(rType))
				return (_slots[i]->clone());
		}
		else
			return (NULL);
	return (NULL);
}

AMateria const	*MateriaSource::getAMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (_slots[idx]);
}

				MateriaSource::MateriaSource(void) :
				_idx_free(0)
{
	for (int i = 0; i < 4; ++i)
		_slots[i] = NULL;
}

				MateriaSource::MateriaSource(MateriaSource const &rSrc) :
				_idx_free(0)
{
	for (int i = 0; i < 4; ++i)
		_slots[i] = NULL;
	*this = rSrc;
}

				MateriaSource::~MateriaSource(void)
{
	_clearSlots();
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rRhs)
{
	AMateria const		*pAmateria;

	if (this != &rRhs)
	{
		_clearSlots();
		for (int i = 0; i < 4; ++i)
			if ((pAmateria = rRhs.getAMateria(i)))
			{
				_slots[i] = pAmateria->clone();
				_idx_free = (i + 1) % 4;
			}
			else
				return (*this);
	}
	return (*this);
}

void			MateriaSource::_clearSlots(void)
{
	for (int i = 0; i < 4; ++i)
		if (_slots[i] != NULL)
		{
			delete _slots[i];
			_slots[i] = NULL;
		}
	_idx_free = 0;
}
