/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:54:16 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:22:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

void				SuperMutant::takeDamage(int damage)
{
	if (this->_hp <= 0 || damage - 3 <= 0)
		return ;
	if ((this->_hp -= damage - 3) < 0)
		this->_hp = 0;
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
	this->_hp = rRhs.getHP();
	this->_type = rRhs.getType();
	return (*this);
}
