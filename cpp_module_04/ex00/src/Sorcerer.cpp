/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:20:09 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:20:45 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

std::string const	&Sorcerer::getName(void) const
{
	return (_name);
}

std::string const	&Sorcerer::getTitle(void) const
{
	return (_title);
}

void				Sorcerer::polymorph(Victim const &rVictim) const
{
	rVictim.getPolymorphed();
}

					Sorcerer::Sorcerer(std::string const &rName, std::string const &rTitle) :
					_name(rName),
					_title(rTitle)
{
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

					Sorcerer::Sorcerer(Sorcerer const &rSrc)
{
	*this = rSrc;
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

					Sorcerer::~Sorcerer(void)
{
	std::cout << _name << ", " << _title << ", is dead. "
		"Consequences will never be the same!" << std::endl;
}

Sorcerer			&Sorcerer::operator=(Sorcerer const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
		_title = rRhs.getTitle();
	}
	return (*this);
}

					Sorcerer::Sorcerer(void)
{
}

std::ostream		&operator<<(std::ostream &rOs, Sorcerer const &rRhs)
{
	rOs << "I am " << rRhs.getName() << ", " << rRhs.getTitle() << ", and I like ponies!" << std::endl;
	return (rOs);
}
