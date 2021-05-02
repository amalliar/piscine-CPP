/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:13:00 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:00:57 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

void			ZombieHorde::announce(void) const
{
	for (size_t i = 0; i < _zmbHordeSize; ++i)
		_pZmbHorde[i].announce();
}

				ZombieHorde::ZombieHorde(size_t zmbHordeSize) :
				_zmbHordeSize(zmbHordeSize)
{
	_pZmbHorde = new Zombie[_zmbHordeSize];
}

				ZombieHorde::ZombieHorde(ZombieHorde const &rSrc)
{
	*this = rSrc;
}

				ZombieHorde::~ZombieHorde(void)
{
	delete [] _pZmbHorde;
}

ZombieHorde		&ZombieHorde::operator=(ZombieHorde const &rRhs)
{
	if (this != &rRhs)
	{
		if (_zmbHordeSize)
			delete [] _pZmbHorde;
		_zmbHordeSize = rRhs._zmbHordeSize;
		_pZmbHorde = new Zombie[_zmbHordeSize];
		for (size_t i = 0; i < _zmbHordeSize; ++i)
			_pZmbHorde[i] = rRhs._pZmbHorde[i];
	}
	return (*this);
}

				ZombieHorde::ZombieHorde(void)
{
}
