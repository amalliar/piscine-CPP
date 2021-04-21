/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:13:00 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 23:54:34 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

void			ZombieHorde::announce(void) const
{
	for (size_t i = 0; i < this->_zmbHordeSize; ++i)
		this->_pZmbHorde[i].announce();
}

				ZombieHorde::ZombieHorde(size_t zmbHordeSize) :
				_zmbHordeSize(zmbHordeSize)
{
	this->_pZmbHorde = new Zombie[this->_zmbHordeSize];
}

				ZombieHorde::ZombieHorde(ZombieHorde const &rSrc) :
				_zmbHordeSize(rSrc._zmbHordeSize)
{
	this->_pZmbHorde = new Zombie[this->_zmbHordeSize];
	for (size_t i = 0; i < this->_zmbHordeSize; ++i)
		this->_pZmbHorde[i] = rSrc._pZmbHorde[i];
}

				ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_pZmbHorde;
}

ZombieHorde		&ZombieHorde::operator=(ZombieHorde const &rRhs)
{
	this->_zmbHordeSize = rRhs._zmbHordeSize;
	this->_pZmbHorde = new Zombie[this->_zmbHordeSize];
	for (size_t i = 0; i < this->_zmbHordeSize; ++i)
		this->_pZmbHorde[i] = rRhs._pZmbHorde[i];
	return (*this);
}

				ZombieHorde::ZombieHorde(void)
{
}
