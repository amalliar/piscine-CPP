/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Comet.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:00:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 15:43:21 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Comet.hpp"

std::string			Comet::getName(void) const
{
	return ("Comet");
}

std::string			Comet::beMined(DeepCoreMiner *pDeepCoreMiner) const
{
	static_cast<void>(pDeepCoreMiner);
	return ("Meium");
}

std::string			Comet::beMined(StripMiner *pStripMiner) const
{
	static_cast<void>(pStripMiner);
	return ("Tartarite");
}

					Comet::Comet(void)
{
}

					Comet::Comet(Comet const &rSrc)
{
	static_cast<void>(rSrc);
}

					Comet::~Comet(void)
{
}

Comet				&Comet::operator=(Comet const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
