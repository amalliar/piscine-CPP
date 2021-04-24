/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:01 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 20:51:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <cstddef>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class						Intern;

typedef struct				s_action
{
	std::string				name;
	AForm					*(Intern::*func)(std::string const &rTarget);
}							t_action;

class						Intern
{
	public:
		AForm				*makeForm(std::string const &rName, std::string const &rTarget);
		AForm				*makeShrubberyCreationForm(std::string const &rTarget);
		AForm				*makeRobotomyRequestForm(std::string const &rTarget);
		AForm				*makePresidentialPardonForm(std::string const &rTarget);

							Intern(void);
							Intern(Intern const &rSrc);
							~Intern(void);
		Intern				&operator=(Intern const &rRhs);

		static int const	numKnownForms = 3;
		static t_action		actionMap[Intern::numKnownForms];
};

#endif // INTERN_HPP
