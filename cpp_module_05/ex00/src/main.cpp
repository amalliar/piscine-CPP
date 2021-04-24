/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:01:10 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/14 14:43:47 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "colors.hpp"

int			main(void)
{
	try
	{
		std::cout << clr_bblack("// Bureaucrat bc(\"Hermes Conrad\", 0);") << std::endl;
		Bureaucrat bc("Hermes Conrad", 0);
	}
	catch (std::exception &ex)
	{
		std::cout << clr_bred(ex.what()) << std::endl << std::endl;
	}

	try
	{
		std::cout << clr_bblack("// Bureaucrat bc(\"Hermes Conrad\", 151);") << std::endl;
		Bureaucrat bc("Hermes Conrad", 151);
	}
	catch (std::exception &ex)
	{
		std::cout << clr_bred(ex.what()) << std::endl << std::endl;
	}

	try
	{
		std::cout << clr_bblack("// Bureaucrat bc(\"Hermes Conrad\", 1);") << std::endl;
		Bureaucrat bc("Hermes Conrad", 1);
		std::cout << bc;
		std::cout << clr_bblack("// bc.incGrade();") << std::endl;
		bc.incGrade();
	}
	catch (std::exception &ex)
	{
		std::cout << clr_bred(ex.what()) << std::endl << std::endl;
	}

	try
	{
		std::cout << clr_bblack("// Bureaucrat bc(\"Hermes Conrad\", 150);") << std::endl;
		Bureaucrat bc("Hermes Conrad", 150);
		std::cout << bc;
		std::cout << clr_bblack("// bc.decGrade();") << std::endl;
		bc.decGrade();
	}
	catch (std::exception &ex)
	{
		std::cout << clr_bred(ex.what()) << std::endl;
	}

	return (0);
}
