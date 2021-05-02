/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:31:53 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:57:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"
# include "colors.hpp"

class				Bureaucrat;

class				Form
{
	public:

		std::string const	&getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		bool				isSigned(void) const;

		void				beSigned(Bureaucrat const &rBureaucrat)
								throw (GradeTooLowException, FormIsAlreadySignedException);

							Form(std::string const &rName, int gradeToSign, int gradeToExec)
								throw (GradeTooHighException, GradeTooLowException);
							Form(Form const &rSrc);
							~Form(void);

		Form				&operator=(Form const &rRhs);

		class				GradeTooHighException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
		class				GradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
		class				FormIsAlreadySignedException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};

	private:

		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExec;
		bool				_isSigned;

							Form(void);
};

std::ostream				&operator<<(std::ostream &rOs, Form const &rRhs);

#endif // FORM_HPP
