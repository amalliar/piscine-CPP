/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:01:10 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 18:03:38 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int			main(void)
{
	std::srand(std::time(NULL));

	Bureaucrat	bc("Hermes Conrad", 34);
	Intern		it;

	AForm		*p_scf = it.makeForm("shrubbery creation", "home");
	AForm		*p_rrf = it.makeForm("robotomy request", "Zaz");
	AForm		*p_ppf = it.makeForm("presidential pardon", "Zaz");
	AForm		*p_pef = it.makeForm("pointless existence", "self");

	std::cout << std::endl << bc << *p_scf;
	bc.signForm(*p_scf);
	bc.executeForm(*p_scf);

	while (bc.getGrade() > p_rrf->getGradeToSign())
		bc.incGrade();
	while (bc.getGrade() > p_rrf->getGradeToExec())
		bc.incGrade();
	std::cout << std::endl << bc << *p_rrf;
	bc.signForm(*p_rrf);
	bc.executeForm(*p_rrf);

	while (bc.getGrade() > p_ppf->getGradeToSign())
		bc.incGrade();
	while (bc.getGrade() > p_ppf->getGradeToExec())
		bc.incGrade();
	std::cout << std::endl << bc << *p_ppf;
	bc.signForm(*p_ppf);
	bc.executeForm(*p_ppf);

	delete p_scf;
	delete p_rrf;
	delete p_ppf;
	static_cast<void>(p_pef);
	return (0);
}
