/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:09:26 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 18:02:05 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

t_action		Intern::actionMap[Intern::numKnownForms] = \
{
	{"shrubbery creation", &Intern::makeShrubberyCreationForm},
	{"robotomy request", &Intern::makeRobotomyRequestForm},
	{"presidential pardon", &Intern::makePresidentialPardonForm}
};

AForm			*Intern::makeForm(std::string const &rName, std::string const &rTarget)
{
	AForm		*p_form;

	for (int i = 0; i < Intern::numKnownForms; ++i)
		if (!Intern::actionMap[i].name.compare(rName))
		{
			p_form = (this->*actionMap[i].func)(rTarget);
			std::cout << "Intern creates " << p_form->getName() << std::endl;
			return (p_form);
		}
	std::cout << "Requested form is not known: " << rName << std::endl;
	return (NULL);
}

AForm			*Intern::makeShrubberyCreationForm(std::string const &rTarget)
{
	return (new ShrubberyCreationForm(rTarget));
}

AForm			*Intern::makeRobotomyRequestForm(std::string const &rTarget)
{
	return (new RobotomyRequestForm(rTarget));
}

AForm			*Intern::makePresidentialPardonForm(std::string const &rTarget)
{
	return (new PresidentialPardonForm(rTarget));
}

				Intern::Intern(void)
{
}

				Intern::Intern(Intern const &rSrc)
{
	*this = rSrc;
}

				Intern::~Intern(void)
{
}

Intern			&Intern::operator=(Intern const &rRhs)
{
	(void)rRhs;
	return (*this);
}
