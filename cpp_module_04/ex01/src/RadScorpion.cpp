/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:54:16 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:28:26 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

					RadScorpion::RadScorpion(void) :
					Enemy(80, "RadScorpion")
{
	std::cout << CLR_BRED(* click click click *) << std::endl;
}

					RadScorpion::RadScorpion(RadScorpion const &rSrc)
{
	*this = rSrc;
	std::cout << CLR_BRED(* click click click *) << std::endl;
}

					RadScorpion::~RadScorpion(void)
{
	std::cout << CLR_BRED(* SPROTCH *) << std::endl;
}

RadScorpion			&RadScorpion::operator=(RadScorpion const &rRhs)
{
	if (this != &rRhs)
	{
		_hp = rRhs.getHP();
		_type = rRhs.getType();
	}
	return (*this);
}
