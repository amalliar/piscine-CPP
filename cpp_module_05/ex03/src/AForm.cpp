/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:45:51 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:28:20 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::string const		&AForm::getName(void) const
{
	return (_name);
}

int						AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int						AForm::getGradeToExec(void) const
{
	return (_gradeToExec);
}

bool					AForm::isSigned(void) const
{
	return (_isSigned);
}

void					AForm::beSigned(Bureaucrat const &rBureaucrat)
							throw (GradeTooLowException, FormIsAlreadySignedException)
{
	if (_isSigned)
		throw (FormIsAlreadySignedException());
	if (_gradeToSign < rBureaucrat.getGrade())
		throw (GradeTooLowException());
	_isSigned = true;
}

void					AForm::execute(Bureaucrat const &rBureaucrat) const
							throw (GradeTooLowException, FormIsNotSignedException)
{
	if (!_isSigned)
		throw (FormIsNotSignedException());
	if (_gradeToExec < rBureaucrat.getGrade())
		throw (GradeTooLowException());
	_exec();
}

						AForm::AForm(std::string const &rName, int gradeToSign, int gradeToExec)
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

						AForm::AForm(AForm const &rSrc) :
						_name(rSrc.getName()),
						_gradeToSign(rSrc.getGradeToSign()),
						_gradeToExec(rSrc.getGradeToExec()),
						_isSigned(rSrc.isSigned())
{
}

						AForm::~AForm(void)
{
}

AForm					&AForm::operator=(AForm const &rRhs)
{
	if (this != &rRhs)
	{
		_isSigned = rRhs.isSigned();
	}
	return (*this);
}

const char				*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHighException");
}

const char				*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLowException");
}

const char				*AForm::FormIsAlreadySignedException::what() const throw()
{
	return ("AForm::FormIsAlreadySignedException");
}

const char				*AForm::FormIsNotSignedException::what() const throw()
{
	return ("AForm::FormIsNotSignedException");
}

						AForm::AForm(void) :
						_name(""),
						_gradeToSign(0),
						_gradeToExec(0),
						_isSigned(false)
{
}

std::ostream			&operator<<(std::ostream &rOs, AForm const &rRhs)
{
	rOs << clr_byellow("class") << " AForm" << std::endl;
	rOs << "{" << std::endl;
	rOs << "    " << clr_bpurple("_name") << ": " << rRhs.getName() << std::endl;
	rOs << "    " << clr_bpurple("_gradeToSign") << ": " << rRhs.getGradeToSign() << std::endl;
	rOs << "    " << clr_bpurple("_gradeToExec") << ": " << rRhs.getGradeToExec() << std::endl;
	rOs << "    " << clr_bpurple("_isSigned") << ": " << rRhs.isSigned() << std::endl;
	rOs << "}" << std::endl;
	return (rOs);
}
