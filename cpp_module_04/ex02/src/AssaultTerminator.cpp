/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:55:17 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:26:13 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

ISpaceMarine		*AssaultTerminator::clone(void) const
{
	return (new AssaultTerminator);
}

void				AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void				AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void				AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}

					AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
}

					AssaultTerminator::AssaultTerminator(AssaultTerminator const &rSrc)
{
	(void)rSrc;
	std::cout << "* teleports from space *" << std::endl;
}

					AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator		&AssaultTerminator::operator=(AssaultTerminator const &rRhs)
{
	(void)rRhs;
	return (*this);
}
