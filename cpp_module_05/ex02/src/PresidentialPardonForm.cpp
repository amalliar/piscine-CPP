/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:34:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 17:54:36 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

std::string const		&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

						PresidentialPardonForm::PresidentialPardonForm(std::string const &rTarget) :
						AForm("PresidentialPardonForm", 25, 5),
						_target(rTarget)
{
}

						PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rSrc) :
						AForm("PresidentialPardonForm", 25, 5),
						_target(rSrc.getTarget())
{
}

						PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rRhs)
{
	this->_target = rRhs.getTarget();
	return (*this);
}

void					PresidentialPardonForm::_exec(void) const
{
	std::cout << clr_bblue(this->_target + " has been pardoned by Zafod Beeblebrox!") << std::endl;
}

						PresidentialPardonForm::PresidentialPardonForm(void) :
						AForm("PresidentialPardonForm", 25, 5),
						_target("")
{
}
