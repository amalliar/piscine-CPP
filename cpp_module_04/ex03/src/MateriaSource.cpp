/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:01:15 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:47:14 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void			MateriaSource::learnMateria(AMateria *pAmateria)
{
	if (pAmateria == NULL)
		return ;
	if (this->_slots[this->_idx_free] != NULL)
		delete this->_slots[this->_idx_free];
	this->_slots[this->_idx_free] = pAmateria->clone();
	this->_idx_free = (this->_idx_free + 1) % 4;
}

AMateria		*MateriaSource::createMateria(std::string const &rType)
{
	for (int i = 0; i < 4; ++i)
		if (this->_slots[i] != NULL)
		{
			if (!this->_slots[i]->getType().compare(rType))
				return (this->_slots[i]->clone());
		}
		else
			return (NULL);
	return (NULL);
}

AMateria const	*MateriaSource::getAMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_slots[idx]);
}

				MateriaSource::MateriaSource(void) :
				_idx_free(0)
{
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = NULL;
}

				MateriaSource::MateriaSource(MateriaSource const &rSrc) :
				_idx_free(0)
{
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = NULL;
	*this = rSrc;
}

				MateriaSource::~MateriaSource(void)
{
	this->_clearSlots();
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rRhs)
{
	AMateria const		*pAmateria;

	if (this == &rRhs)
		return (*this);
	this->_clearSlots();
	for (int i = 0; i < 4; ++i)
		if ((pAmateria = rRhs.getAMateria(i)))
		{
			this->_slots[i] = pAmateria->clone();
			this->_idx_free = (i + 1) % 4;
		}
		else
			return (*this);
	return (*this);
}

void			MateriaSource::_clearSlots(void)
{
	for (int i = 0; i < 4; ++i)
		if (this->_slots[i] != NULL)
		{
			delete this->_slots[i];
			this->_slots[i] = NULL;
		}
	this->_idx_free = 0;
}
