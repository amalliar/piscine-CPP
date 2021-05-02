/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:24:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 10:06:05 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include "AForm.hpp"
# include "colors.hpp"

class						RobotomyRequestForm : public AForm
{
	public:

		std::string const	&getTarget(void) const;

							RobotomyRequestForm(std::string const &rTarget);
							RobotomyRequestForm(RobotomyRequestForm const &rSrc);
							~RobotomyRequestForm(void);
	RobotomyRequestForm		&operator=(RobotomyRequestForm const &rRhs);

	protected:

		void				_exec(void) const;

	private:

		std::string			_target;

							RobotomyRequestForm(void);
};

#endif // ROBOTOMY_REQUEST_FORM_HPP
