/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:24:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 17:54:06 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "colors.hpp"

class						PresidentialPardonForm : public AForm
{
	public:
		std::string const	&getTarget(void) const;

							PresidentialPardonForm(std::string const &rTarget);
							PresidentialPardonForm(PresidentialPardonForm const &rSrc);
							~PresidentialPardonForm(void);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rRhs);

	protected:
		void				_exec(void) const;

	private:
		std::string			_target;

							PresidentialPardonForm(void);
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
