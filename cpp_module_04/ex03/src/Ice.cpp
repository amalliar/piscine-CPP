/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:03:34 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:13:25 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

AMateria			*Ice::clone(void) const
{
	return (new Ice(*this));
}

void				Ice::use(ICharacter &rTarget)
{
	std::cout << "* shoots an ice bolt at " << rTarget.getName() << " *" << std::endl;
	_xp += 10;
}

					Ice::Ice(void) :
					AMateria("ice")
{
}

					Ice::Ice(Ice const &rSrc) :
					AMateria("ice")
{
	*this = rSrc;
}

					Ice::~Ice(void)
{
}

Ice					&Ice::operator=(Ice const &rRhs)
{
	if (this != &rRhs)
	{
		_xp = rRhs.getXP();
	}
	return (*this);
}
