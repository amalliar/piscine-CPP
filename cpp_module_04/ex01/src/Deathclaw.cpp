/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deathclaw.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:54:16 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:26:03 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Deathclaw.hpp"

void				Deathclaw::takeDamage(int damage)
{
	if (_hp <= 0 || damage - 9 <= 0)
		return ;
	if ((_hp -= damage - 9) < 0)
		_hp = 0;
}

					Deathclaw::Deathclaw(void) :
					Enemy(300, "Deathclaw")
{
	std::cout << CLR_BRED(Raaawr!) << std::endl;
}

					Deathclaw::Deathclaw(Deathclaw const &rSrc)
{
	*this = rSrc;
	std::cout << CLR_BRED(Raaawr!) << std::endl;
}

					Deathclaw::~Deathclaw(void)
{
	std::cout << CLR_BRED(Rwhe...) << std::endl;
}

Deathclaw			&Deathclaw::operator=(Deathclaw const &rRhs)
{
	if (this != &rRhs)
	{
		_hp = rRhs.getHP();
		_type = rRhs.getType();
	}
	return (*this);
}
