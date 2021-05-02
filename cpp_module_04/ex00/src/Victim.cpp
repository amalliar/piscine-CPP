/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:06:13 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:21:54 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

std::string const	&Victim::getName(void) const
{
	return (_name);
}

int					Victim::setName(std::string const &rName)
{
	_name = rName;
	return (0);
}

void				Victim::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a cute little " << CLR_BWHITE(sheep) << "!" << std::endl;
}

					Victim::Victim(std::string const &rName) :
					_name(rName)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

					Victim::Victim(Victim const &rSrc)
{
	*this = rSrc;
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

					Victim::~Victim(void)
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

Victim				&Victim::operator=(Victim const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
	}
	return (*this);
}

					Victim::Victim(void)
{
}

std::ostream		&operator<<(std::ostream &rOs, Victim const &rRhs)
{
	rOs << "I'm " << rRhs.getName() << " and I like otters!" << std::endl;
	return (rOs);
}
