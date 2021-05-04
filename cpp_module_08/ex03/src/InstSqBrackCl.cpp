/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstSqBrackCl.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:26:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstSqBrackCl.hpp"
#include "Interpreter.hpp"

void			InstSqBrackCl::exec(void) const
{
	if (*_rInterpreter._cellPointer)
		//	Jump to the matching square bracket.
		_rInterpreter._instPointer = _rInterpreter._instructions.begin() + \
			_rInterpreter._sqBrackLookupMap[_rInterpreter._instPointer - _rInterpreter._instructions.begin()];
}

				InstSqBrackCl::InstSqBrackCl(Interpreter &rInterpreter) :
				AInstruction(rInterpreter)
{
	type = ']';
}

				InstSqBrackCl::~InstSqBrackCl(void)
{
}

				InstSqBrackCl::InstSqBrackCl(InstSqBrackCl const &rSrc) :
				AInstruction(rSrc._rInterpreter)
{
	type = ']';
}

InstSqBrackCl	&InstSqBrackCl::operator=(InstSqBrackCl const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
