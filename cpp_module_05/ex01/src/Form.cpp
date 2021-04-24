/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:45:51 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 17:34:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::string const		&Form::getName(void) const
{
	return (this->_name);
}

int						Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int						Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

bool					Form::isSigned(void) const
{
	return (this->_isSigned);
}

void					Form::beSigned(Bureaucrat const &rBureaucrat)
							throw (GradeTooLowException, FormIsAlreadySignedException)
{
	if (this->_isSigned)
		throw (FormIsAlreadySignedException());
	if (this->_gradeToSign < rBureaucrat.getGrade())
		throw (GradeTooLowException());
	this->_isSigned = true;
}

						Form::Form(std::string const &rName, int gradeToSign, int gradeToExec)
							throw (GradeTooHighException, GradeTooLowException) :
						_name(rName),
						_gradeToSign(gradeToSign),
						_gradeToExec(gradeToExec),
						_isSigned(false)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (GradeTooHighException());
	if (gradeToSign > 150 || gradeToExec > 150)
		throw (GradeTooLowException());
}

						Form::Form(Form const &rSrc) :
						_name(rSrc.getName()),
						_gradeToSign(rSrc.getGradeToSign()),
						_gradeToExec(rSrc.getGradeToExec()),
						_isSigned(rSrc.isSigned())
{
}

						Form::~Form(void)
{
}

Form					&Form::operator=(Form const &rRhs)
{
	this->_isSigned = rRhs.isSigned();
	return (*this);
}

const char				*Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char				*Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

const char				*Form::FormIsAlreadySignedException::what() const throw()
{
	return ("Form::FormIsAlreadySignedException");
}

						Form::Form(void) :
						_name(""),
						_gradeToSign(0),
						_gradeToExec(0),
						_isSigned(false)
{
}

std::ostream			&operator<<(std::ostream &rOs, Form const &rRhs)
{
	rOs << clr_byellow("class") << " Form" << std::endl;
	rOs << "{" << std::endl;
	rOs << "    " << clr_bpurple("_name") << ": " << rRhs.getName() << std::endl;
	rOs << "    " << clr_bpurple("_gradeToSign") << ": " << rRhs.getGradeToSign() << std::endl;
	rOs << "    " << clr_bpurple("_gradeToExec") << ": " << rRhs.getGradeToExec() << std::endl;
	rOs << "    " << clr_bpurple("_isSigned") << ": " << rRhs.isSigned() << std::endl;
	rOs << "}" << std::endl;
	return (rOs);
}
