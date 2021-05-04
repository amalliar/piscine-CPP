/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstMinus.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:25:31 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstMinus.hpp"
#include "Interpreter.hpp"

void		InstMinus::exec(void) const
{
	--*_rInterpreter._cellPointer;
}

			InstMinus::InstMinus(Interpreter &rInterpreter) :
			AInstruction(rInterpreter)
{
	type = '-';
}

			InstMinus::~InstMinus(void)
{
}

			InstMinus::InstMinus(InstMinus const &rSrc) :
			AInstruction(rSrc._rInterpreter)
{
	type = '-';
}

InstMinus	&InstMinus::operator=(InstMinus const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
