/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantPigTerminationForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:34:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 10:03:34 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantPigTerminationForm.hpp"

std::string const			&MutantPigTerminationForm::getTarget(void) const
{
	return (_target);
}

							MutantPigTerminationForm::MutantPigTerminationForm(std::string const &rTarget) :
							AForm("Mutant Pig Termination Form", 130, 50),
							_target(rTarget)
{
}

							MutantPigTerminationForm::MutantPigTerminationForm(MutantPigTerminationForm const &rSrc) :
							AForm("Mutant Pig Termination Form", 130, 50),
							_target(rSrc.getTarget())
{
}

							MutantPigTerminationForm::~MutantPigTerminationForm(void)
{
}

MutantPigTerminationForm	&MutantPigTerminationForm::operator=(MutantPigTerminationForm const &rRhs)
{
	if (this != &rRhs)
	{
		_target = rRhs.getTarget();
	}
	return (*this);
}

void						MutantPigTerminationForm::_exec(void) const
{
	std::cout << clr_bwhite("That'll do, " + _target + ". That'll do...") << std::endl;
}

							MutantPigTerminationForm::MutantPigTerminationForm(void) :
							AForm("Mutant Pig Termination Form", 130, 50),
							_target("")
{
}
