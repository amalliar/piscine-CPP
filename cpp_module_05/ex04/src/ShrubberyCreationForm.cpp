/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:34:44 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:53:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string const		&ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

						ShrubberyCreationForm::ShrubberyCreationForm(std::string const &rTarget) :
						AForm("Shrubbery Creation Form", 145, 137),
						_target(rTarget)
{
}

						ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rSrc) :
						AForm("Shrubbery Creation Form", 145, 137),
						_target(rSrc.getTarget())
{
}

						ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rRhs)
{
	if (this != &rRhs)
	{
		_target = rRhs.getTarget();
	}
	return (*this);
}

void					ShrubberyCreationForm::_exec(void) const
{
	std::ofstream		ofs;
	std::string			fname = _target + "_shrubbery";
	std::string const	shrub = \

	"\033[1;32m"
	"                       .\n"
	"                       M\n"
	"                      dM\n"
	"                      MMr\n"
	"                     4MMML                  .\n"
	"                     MMMMM.                xf\n"
	"     .              \"MMMMM               .MM-\n"
	"      Mh..          +MMMMMM            .MMMM\n"
	"      .MMM.         .MMMMML.          MMMMMh\n"
	"       )MMMh.        MMMMMM         MMMMMMM\n"
	"        3MMMMx.     'MMMMMMf      xnMMMMMM\"\n"
	"        '*MMMMM      MMMMMM.     nMMMMMMP\"\n"
	"          *MMMMMx    \"MMMMM\\    .MMMMMMM=\n"
	"           *MMMMMh   \"MMMMM\"   JMMMMMMP\n"
	"             MMMMMM   3MMMM.  dMMMMMM            .\n"
	"              MMMMMM  \"MMMM  .MMMMM(        .nnMP\"\n"
	"  =..          *MMMMx  MMM\"  dMMMM\"    .nnMMMMM*\n"
	"    \"MMn...     'MMMMr 'MM   MMM\"   .nMMMMMMM*\"\n"
	"     \"4MMMMnn..   *MMM  MM  MMP\"  .dMMMMMMM\"\"\n"
	"       ^MMMMMMMMx.  *ML \"M .M*  .MMMMMM**\"\n"
	"          *PMMMMMMhn. *x > M  .MMMM**\"\"\n"
	"             \"\"**MMMMhx/.h/ .=*\"\n"
	"                      .3P\"%....\n"
	"                    nP\"     \"*MMnx\n"
	"\033[0m";

	ofs.open(fname);
	ofs << shrub;
	ofs.close();
	if (ofs.fail())
		std::cerr << "ShrubberyCreationForm: can't open " << fname << " for writing" << std::endl; 
}

						ShrubberyCreationForm::ShrubberyCreationForm(void) :
						AForm("Shrubbery Creation Form", 145, 137),
						_target("")
{
}
