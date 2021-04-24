/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:55:17 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:32:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

ISpaceMarine		*TacticalMarine::clone(void) const
{
	return (new TacticalMarine);
}

void				TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void				TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void				TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

					TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

					TacticalMarine::TacticalMarine(TacticalMarine const &rSrc)
{
	(void)rSrc;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

					TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine		&TacticalMarine::operator=(TacticalMarine const &rRhs)
{
	(void)rRhs;
	return (*this);
}
