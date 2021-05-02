/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:24:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:34:46 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class						ShrubberyCreationForm : public AForm
{
	public:

		std::string const	&getTarget(void) const;

							ShrubberyCreationForm(std::string const &rTarget);
							ShrubberyCreationForm(ShrubberyCreationForm const &rSrc);
							~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rRhs);

	protected:

		void				_exec(void) const;

	private:

		std::string			_target;

							ShrubberyCreationForm(void);
};

#endif // SHRUBBERY_CREATION_FORM_HPP
