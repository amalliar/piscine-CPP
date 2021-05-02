/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:09:26 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:54:33 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

t_action		Intern::actionMap[Intern::numKnownForms] = \
{
	{"shrubbery creation", &Intern::makeShrubberyCreationForm},
	{"robotomy request", &Intern::makeRobotomyRequestForm},
	{"presidential pardon", &Intern::makePresidentialPardonForm},
	{"mutant pig termination", &Intern::makeMutantPigTerminationForm}
};

AForm			*Intern::makeForm(std::string const &rName, std::string const &rTarget) const
{
	AForm		*p_form;

	for (int i = 0; i < Intern::numKnownForms; ++i)
		if (!Intern::actionMap[i].name.compare(rName))
		{
			p_form = (this->*actionMap[i].func)(rTarget);
			std::cout << "Intern creates a " << p_form->getName();
			std::cout << " (s.grade " << p_form->getGradeToSign();
			std::cout << ", ex.grade " << p_form->getGradeToExec();
			std::cout << ") targeted on " << rTarget;
			std::cout << ((p_form->isSigned()) ? " (Signed)" : " (Unsigned)");
			std::cout << std::endl;
			return (p_form);
		}
	std::cout << "Intern is puzzled with this request: " << rName << std::endl;
	return (NULL);
}

AForm			*Intern::makeShrubberyCreationForm(std::string const &rTarget) const
{
	return (new ShrubberyCreationForm(rTarget));
}

AForm			*Intern::makeRobotomyRequestForm(std::string const &rTarget) const
{
	return (new RobotomyRequestForm(rTarget));
}

AForm			*Intern::makePresidentialPardonForm(std::string const &rTarget) const
{
	return (new PresidentialPardonForm(rTarget));
}

AForm			*Intern::makeMutantPigTerminationForm(std::string const &rTarget) const
{
	return (new MutantPigTerminationForm(rTarget));
}

				Intern::Intern(void)
{
}

				Intern::Intern(Intern const &rSrc)
{
	static_cast<void>(rSrc);
}

				Intern::~Intern(void)
{
}

Intern			&Intern::operator=(Intern const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
