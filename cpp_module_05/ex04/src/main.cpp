/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:01:10 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 22:58:44 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "colors.hpp"

int			main(void)
{
	Intern			idiot_one;
	Bureaucrat		hermes = Bureaucrat("Hermes Conrad", 51);
	Bureaucrat		bob = Bureaucrat("Bobby Bobson", 131);
	OfficeBlock		ob;

	try
	{
		ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (OfficeBlock::InternNotSetException &ex)
	{
		std::cout << clr_bred(ex.what()) << std::endl;
		ob.setIntern(idiot_one);
		try
		{
			ob.doBureaucracy("mutant pig termination", "Pigley");
		}
		catch (OfficeBlock::SignerNotSetException &ex)
		{
			std::cout << clr_bred(ex.what()) << std::endl;
			ob.setSigner(bob);
			try
			{
				ob.doBureaucracy("mutant pig termination", "Pigley");
			}
			catch (OfficeBlock::ExecutorNotSetException &ex)
			{
				std::cout << clr_bred(ex.what()) << std::endl << std::endl;
				ob.setExecutor(hermes);
				try
				{
					ob.doBureaucracy("mutant pig termination", "Pigley");
				}
				catch (OfficeBlock::SignerGradeTooLowException &ex)
				{
					std::cout << clr_bred(ex.what()) << std::endl << std::endl;
					while (bob.getGrade() > 123)
						bob.incGrade();
					try
					{
						ob.doBureaucracy("mutant pig termination", "Pigley");
					}
					catch (OfficeBlock::ExecutorGradeTooLowException &ex)
					{
						std::cout << clr_bred(ex.what()) << std::endl << std::endl;
						while (hermes.getGrade() > 37)
							hermes.incGrade();
						ob.doBureaucracy("mutant pig termination", "Pigley");
						std::cout << std::endl;
						try
						{
							ob.doBureaucracy("mutant pig preservation", "Pigley");
						}
						catch (OfficeBlock::UnknownFormException &ex)
						{
							std::cout << clr_bred(ex.what()) << std::endl;
						}
					}
				}
			}
		}
	}

	return (0);
}
