/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstPlus.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:26:26 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstPlus.hpp"
#include "Interpreter.hpp"

void		InstPlus::exec(void) const
{
	++*_rInterpreter._cellPointer;
}

			InstPlus::InstPlus(Interpreter &rInterpreter) :
			AInstruction(rInterpreter)
{
	type = '+';
}

			InstPlus::~InstPlus(void)
{
}

			InstPlus::InstPlus(InstPlus const &rSrc) :
			AInstruction(rSrc._rInterpreter)
{
	type = '+';
}

InstPlus	&InstPlus::operator=(InstPlus const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
