/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:32:51 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 17:25:30 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "colors.hpp"

class							Bureaucrat
{
	public:
		std::string const		&getName(void) const;
		int						getGrade(void) const;

		void					incGrade(void) throw (GradeTooHighException);
		void					decGrade(void) throw (GradeTooLowException);

								Bureaucrat(std::string const &rName, int grade)
									throw (GradeTooHighException, GradeTooLowException);
								Bureaucrat(Bureaucrat const &rSrc);
								~Bureaucrat(void);
		Bureaucrat				&operator=(Bureaucrat const &rRhs);

		class					GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class					GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const		_name;
		int						_grade;

								Bureaucrat(void);
};

std::ostream					&operator<<(std::ostream &rOs, Bureaucrat const &rRhs);

#endif // BUREAUCRAT_HPP
