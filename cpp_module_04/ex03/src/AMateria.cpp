/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:34:48 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:36:52 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

std::string const		&AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int			AMateria::getXP(void) const
{
	return (this->_xp);
}

void					AMateria::use(ICharacter &rTarget)
{
	this->_xp += 10;
	static_cast<void>(rTarget);
}

						AMateria::AMateria(std::string const &rType) :
						_type(rType),
						_xp(0)
{
}

						AMateria::AMateria(AMateria const &rSrc)
{
	*this = rSrc;
}

						AMateria::~AMateria(void)
{
}

AMateria				&AMateria::operator=(AMateria const &rRhs)
{
	this->_type = rRhs.getType();
	this->_xp = rRhs.getXP();
	return (*this);
}

						AMateria::AMateria(void)
{
}
