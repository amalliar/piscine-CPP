/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstLess.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:21:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstLess.hpp"
#include "Interpreter.hpp"

void		InstLess::exec(void) const
{
	//	No bounds checking is done to avoid extra overhead.
	--_rInterpreter._cellPointer;
}

			InstLess::InstLess(Interpreter &rInterpreter) :
			AInstruction(rInterpreter)
{
	type = '<';
}

			InstLess::~InstLess(void)
{
}

			InstLess::InstLess(InstLess const &rSrc) :
			AInstruction(rSrc._rInterpreter)
{
	type = '<';
}

InstLess	&InstLess::operator=(InstLess const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
