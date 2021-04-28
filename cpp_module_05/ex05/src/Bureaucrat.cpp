/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:38:47 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 23:47:48 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string const		&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int						Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void					Bureaucrat::incGrade(void) throw (GradeTooHighException)
{
	if (this->_grade <= 1)
		throw (GradeTooHighException());
	--this->_grade;
}

void					Bureaucrat::decGrade(void) throw (GradeTooLowException)
{
	if (this->_grade >= 150)
		throw (GradeTooLowException());
	++this->_grade;
}

void					Bureaucrat::signForm(AForm &rForm) const
							throw (FormIsAlreadySignedException, SignerGradeTooLowException)
{
	if (!rForm.isSigned() && this->_grade <= rForm.getGradeToSign())
	{
		this->_describeAction(rForm, "signes");
		std::cout << std::endl;
		rForm.beSigned(*this);
	}
	else if (rForm.isSigned())
	{
		this->_describeAction(rForm, "cannot sign");
		std::cout << " because the form is already signed" << std::endl;
		throw (FormIsAlreadySignedException());
	}
	else if (this->_grade > rForm.getGradeToSign())
	{
		this->_describeAction(rForm, "cannot sign");
		std::cout << " because his/her grade is too low" << std::endl;
		throw (SignerGradeTooLowException());
	}
}

void					Bureaucrat::executeForm(AForm const &rForm) const
							throw (FormIsNotSignedException, ExecutorGradeTooLowException)
{
	if (rForm.isSigned() && this->_grade <= rForm.getGradeToExec())
	{
		this->_describeAction(rForm, "executes");
		std::cout << std::endl;
		rForm.execute(*this);
	}
	else if (!rForm.isSigned())
	{
		this->_describeAction(rForm, "cannot execute");
		std::cout << " because the form is not signed" << std::endl;
		throw (FormIsNotSignedException());
	}
	else if (this->_grade > rForm.getGradeToExec())
	{
		this->_describeAction(rForm, "cannot execute");
		std::cout << " because his/her grade is too low" << std::endl;
		throw (ExecutorGradeTooLowException());
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
	this->_grade = rRhs._grade;
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

const char				*Bureaucrat::SignerGradeTooLowException::what() const throw()
{
	return ("Bureaucrat::SignerGradeTooLowException");
}

const char				*Bureaucrat::ExecutorGradeTooLowException::what() const throw()
{
	return ("Bureaucrat::ExecutorGradeTooLowException");
}

const char				*Bureaucrat::FormIsAlreadySignedException::what() const throw()
{
	return ("Bureaucrat::FormIsAlreadySignedException");
}

const char				*Bureaucrat::FormIsNotSignedException::what() const throw()
{
	return ("Bureaucrat::FormIsNotSignedException");
}

void					Bureaucrat::_describeAction(AForm const &rForm, std::string const &rAction) const
{
	std::cout << "Bureaucrat " << this->_name;
	std::cout << " (Grade " << this->_grade << ") ";
	std::cout << rAction;
	std::cout << " a " << rForm.getName();
	std::cout << " (s.grade " << rForm.getGradeToSign();
	std::cout << ", ex.grade " << rForm.getGradeToExec() << ")";
	std::cout << " targeted on " << rForm.getTarget();
	std::cout << ((rForm.isSigned()) ? " (Signed)" : " (Unsigned)");
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
