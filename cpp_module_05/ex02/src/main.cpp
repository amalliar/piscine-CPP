/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:01:10 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/14 14:56:23 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int			main(void)
{
	std::srand(std::time(NULL));

	Bureaucrat	bc("Hermes Conrad", 34);
	AForm		*scf = new ShrubberyCreationForm("home");
	AForm		*rrf = new RobotomyRequestForm("Zaz");
	AForm		*ppf = new PresidentialPardonForm("Zaz");

	std::cout << bc << *scf;
	bc.signForm(*scf);
	bc.executeForm(*scf);

	while (bc.getGrade() > rrf->getGradeToSign())
		bc.incGrade();
	while (bc.getGrade() > rrf->getGradeToExec())
		bc.incGrade();
	std::cout << std::endl << bc << *rrf;
	bc.signForm(*rrf);
	bc.executeForm(*rrf);

	while (bc.getGrade() > ppf->getGradeToSign())
		bc.incGrade();
	while (bc.getGrade() > ppf->getGradeToExec())
		bc.incGrade();
	std::cout << std::endl << bc << *ppf;
	bc.signForm(*ppf);
	bc.executeForm(*ppf);

	delete scf;
	delete rrf;
	delete ppf;
	return (0);
}
