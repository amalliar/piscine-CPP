/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:54:16 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:28:54 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

void				SuperMutant::takeDamage(int damage)
{
	if (_hp <= 0 || damage - 3 <= 0)
		return ;
	if ((_hp -= damage - 3) < 0)
		_hp = 0;
}

					SuperMutant::SuperMutant(void) :
					Enemy(170, "Super Mutant")
{
	std::cout << CLR_BRED(Gaaah. Me want smash heads!) << std::endl;
}

					SuperMutant::SuperMutant(SuperMutant const &rSrc)
{
	*this = rSrc;
	std::cout << CLR_BRED(Gaaah. Me want smash heads!) << std::endl;
}

					SuperMutant::~SuperMutant(void)
{
	std::cout << CLR_BRED(Aaargh...) << std::endl;
}

SuperMutant			&SuperMutant::operator=(SuperMutant const &rRhs)
{
	if (this != &rRhs)
	{
		_hp = rRhs.getHP();
		_type = rRhs.getType();
	}
	return (*this);
}
