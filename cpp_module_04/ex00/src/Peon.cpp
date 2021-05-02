/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:36:29 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:16:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

void			Peon::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a " << CLR_BPURPLE(pink pony) << "!" << std::endl;
}

				Peon::Peon(std::string const &rName) :
				Victim(rName)
{
	std::cout << "Zog zog." << std::endl;
}

				Peon::Peon(Peon const &rSrc)
{
	*this = rSrc;
	std::cout << "Zog zog." << std::endl;
}

				Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon			&Peon::operator=(Peon const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
	}
	return (*this);
}

				Peon::Peon(void)
{
}
