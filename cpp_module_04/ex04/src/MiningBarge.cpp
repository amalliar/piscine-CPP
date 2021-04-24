/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:21 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 16:15:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

void			MiningBarge::equip(IMiningLaser *pMiningLaser)
{
	for (size_t i = 0; i < _numMiningLasers; ++i)
		if (this->_pMiningLasers[i] == NULL)
		{
			this->_pMiningLasers[i] = pMiningLaser;
			return ;
		}
}

void			MiningBarge::mine(IAsteroid *pAsteroid) const
{
	if (this->_pMiningLasers[0] == NULL)
	{
		std::cout << "MiningBarge has no equiped lasers." << std::endl;
		return ;
	}
	for (size_t i = 0; i < _numMiningLasers; ++i)
		if (this->_pMiningLasers[i] != NULL)
			this->_pMiningLasers[i]->mine(pAsteroid);
		else
			break ;
}

				MiningBarge::MiningBarge(void)
{
	for (size_t i = 0; i < _numMiningLasers; ++i)
		this->_pMiningLasers[i] = NULL;
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
	for (size_t i = 0; i < _numMiningLasers; ++i)
		this->_pMiningLasers[i] = rRhs._pMiningLasers[i];
	return (*this);
}
