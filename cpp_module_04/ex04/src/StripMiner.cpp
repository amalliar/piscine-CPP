/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:25:33 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 14:37:59 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

void			StripMiner::mine(IAsteroid *pAsteroid)
{
	std::cout << "* strip mining... got " << pAsteroid->beMined(this) << "! *" << std::endl;
}

				StripMiner::StripMiner(void)
{
}

				StripMiner::StripMiner(StripMiner const &rSrc)
{
	static_cast<void>(rSrc);
}

				StripMiner::~StripMiner(void)
{
}

StripMiner		&StripMiner::operator=(StripMiner const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
