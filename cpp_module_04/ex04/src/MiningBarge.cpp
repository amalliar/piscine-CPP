/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:21 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:19:01 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

void			MiningBarge::equip(IMiningLaser *pMiningLaser)
{
	for (size_t i = 0; i < _numMiningLasers; ++i)
		if (_pMiningLasers[i] == NULL)
		{
			_pMiningLasers[i] = pMiningLaser;
			return ;
		}
}

void			MiningBarge::mine(IAsteroid *pAsteroid) const
{
	if (_pMiningLasers[0] == NULL)
	{
		std::cout << "MiningBarge has no equiped lasers." << std::endl;
		return ;
	}
	for (size_t i = 0; i < _numMiningLasers; ++i)
		if (_pMiningLasers[i] != NULL)
			_pMiningLasers[i]->mine(pAsteroid);
		else
			break ;
}

				MiningBarge::MiningBarge(void)
{
	for (size_t i = 0; i < _numMiningLasers; ++i)
		_pMiningLasers[i] = NULL;
}

				MiningBarge::MiningBarge(MiningBarge const &rSrc)
{
	*this = rSrc;
}

				MiningBarge::~MiningBarge(void)
{
}

MiningBarge		&MiningBarge::operator=(MiningBarge const &rRhs)
{
	if (this != &rRhs)
	{
		for (size_t i = 0; i < _numMiningLasers; ++i)
			_pMiningLasers[i] = rRhs._pMiningLasers[i];
	}
	return (*this);
}
