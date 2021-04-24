/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:25:33 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 16:02:16 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

void			DeepCoreMiner::mine(IAsteroid *pAsteroid)
{
	std::cout << "* mining deep... got " << pAsteroid->beMined(this) << "! *" << std::endl;
}

				DeepCoreMiner::DeepCoreMiner(void)
{
}

				DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &rSrc)
{
	static_cast<void>(rSrc);
}

				DeepCoreMiner::~DeepCoreMiner(void)
{
}

DeepCoreMiner	&DeepCoreMiner::operator=(DeepCoreMiner const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
