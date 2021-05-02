/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:38:47 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:25:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string const		&Bureaucrat::getName(void) const
{
	return (_name);
}

int						Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void					Bureaucrat::incGrade(void)
							throw (GradeTooHighException)
{
	if (_grade <= 1)
		throw (GradeTooHighException());
	--_grade;
}

void					Bureaucrat::decGrade(void)
							throw (GradeTooLowException)
{
	if (_grade >= 150)
		throw (GradeTooLowException());
	++_grade;
}

void					Bureaucrat::signForm(Form &rForm)
{
	try
	{
		rForm.beSigned(*this);
		std::cout << getName() << " signs the " << rForm.getName() << std::endl;
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << getName() << " cannot sign the " << rForm.getName() << \
			" because his/her grade is too low" << std::endl;
	}
	catch (Form::FormIsAlreadySignedException)
	{
		std::cout << getName() << " cannot sign the " << rForm.getName() << \
			" because the form is already signed" << std::endl;
	}
}

						Bureaucrat::Bureaucrat(std::string const &rName, int grade)
							throw (GradeTooHighException, GradeTooLowException) :
						_name(rName),
						_grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

						Bureaucrat::Bureaucrat(Bureaucrat const &rSrc) :
						_name(rSrc.getName()),
						_grade(rSrc.getGrade())
{
}

						Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat				&Bureaucrat::operator=(Bureaucrat const &rRhs)
{
	if (this != &rRhs)
	{
		_grade = rRhs.getGrade();
	}
	return (*this);
}

const char				*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char				*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

						Bureaucrat::Bureaucrat(void) :
						_name(""),
						_grade(0)
{
}

std::ostream			&operator<<(std::ostream &rOs, Bureaucrat const &rRhs)
{
	rOs << clr_byellow("class") << " Bureaucrat" << std::endl;
	rOs << "{" << std::endl;
	rOs << "    " << clr_bpurple("_name") << ": " << rRhs.getName() << std::endl;
	rOs << "    " << clr_bpurple("_grade") << ": " << rRhs.getGrade() << std::endl;
	rOs << "}" << std::endl;
	return (rOs);
}
