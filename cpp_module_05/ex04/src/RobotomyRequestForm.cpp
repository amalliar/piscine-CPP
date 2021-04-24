/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:34:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 19:56:44 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

std::string const		&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

						RobotomyRequestForm::RobotomyRequestForm(std::string const &rTarget) :
						AForm("Robotomy Request Form", 72, 45),
						_target(rTarget)
{
}

						RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rSrc) :
						AForm("Robotomy Request Form", 72, 45),
						_target(rSrc.getTarget())
{
}

						RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rRhs)
{
	this->_target = rRhs.getTarget();
	return (*this);
}

void					RobotomyRequestForm::_exec(void) const
{
	std::cout << "* Brrr Brrr Brrr *" << std::endl;
	if (std::rand() % 2)
		std::cout << clr_bgreen(this->_target + " has been robotomized successfully!") << std::endl;
	else
		std::cout << clr_bred("Failed to robotomize " + this->_target + "!") << std::endl;
}

						RobotomyRequestForm::RobotomyRequestForm(void) :
						AForm("Robotomy Request Form", 72, 45),
						_target("")
{
}
