/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:31:53 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:58:57 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"
# include "colors.hpp"

class								Bureaucrat;

class								AForm
{
	public:

		std::string const			&getName(void) const;
		virtual std::string const	&getTarget(void) const = 0;
		int							getGradeToSign(void) const;
		int							getGradeToExec(void) const;
		bool						isSigned(void) const;

		void						beSigned(Bureaucrat const &rSigner)
										throw (SignerGradeTooLowException, FormIsAlreadySignedException);
		void						execute(Bureaucrat const &rExecutor) const
										throw (ExecutorGradeTooLowException, FormIsNotSignedException);

									AForm(std::string const &rName, int gradeToSign, int gradeToExec)
										throw (GradeTooHighException, GradeTooLowException);
									AForm(AForm const &rSrc);
		virtual						~AForm(void);

		AForm						&operator=(AForm const &rRhs);

		class						GradeTooHighException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
		class						GradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
		class						SignerGradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
		class						ExecutorGradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
		class						FormIsAlreadySignedException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
		class						FormIsNotSignedException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};

	protected:

		virtual void				_exec(void) const = 0;

	private:

		std::string const			_name;
		int const					_gradeToSign;
		int const					_gradeToExec;
		bool						_isSigned;

									AForm(void);
};

std::ostream						&operator<<(std::ostream &rOs, AForm const &rRhs);

#endif // A_FORM_HPP
