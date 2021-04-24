/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:03:34 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:42:06 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

AMateria			*Cure::clone(void) const
{
	return (new Cure(*this));
}

void				Cure::use(ICharacter &rTarget)
{
	std::cout << "* heals " << rTarget.getName() << "’s wounds *" << std::endl;
	this->_xp += 10;
}

					Cure::Cure(void) :
					AMateria("cure")
{
}

					Cure::Cure(Cure const &rSrc) :
					AMateria("cure")
{
	*this = rSrc;
}

					Cure::~Cure(void)
{
}

Cure				&Cure::operator=(Cure const &rRhs)
{
	this->_xp = rRhs.getXP();
	return (*this);
}
