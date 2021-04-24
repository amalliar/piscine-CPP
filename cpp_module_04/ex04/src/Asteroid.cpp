/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:00:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 15:43:39 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"

std::string			Asteroid::getName(void) const
{
	return ("Asteroid");
}

std::string			Asteroid::beMined(DeepCoreMiner *pDeepCoreMiner) const
{
	static_cast<void>(pDeepCoreMiner);
	return ("Dragonite");
}

std::string			Asteroid::beMined(StripMiner *pStripMiner) const
{
	static_cast<void>(pStripMiner);
	return ("Flavium");
}

					Asteroid::Asteroid(void)
{
}

					Asteroid::Asteroid(Asteroid const &rSrc)
{
	static_cast<void>(rSrc);
}

					Asteroid::~Asteroid(void)
{
}

Asteroid			&Asteroid::operator=(Asteroid const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
