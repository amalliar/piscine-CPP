/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstSqBrackOp.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:27:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstSqBrackOp.hpp"
#include "Interpreter.hpp"

void			InstSqBrackOp::exec(void) const
{
	if (!*_rInterpreter._cellPointer)
		//	Jump to the matching square bracket.
		_rInterpreter._instPointer = _rInterpreter._instructions.begin() + \
			_rInterpreter._sqBrackLookupMap[_rInterpreter._instPointer - _rInterpreter._instructions.begin()];
}

				InstSqBrackOp::InstSqBrackOp(Interpreter &rInterpreter) :
				AInstruction(rInterpreter)
{
	type = '[';
}

				InstSqBrackOp::~InstSqBrackOp(void)
{
}

				InstSqBrackOp::InstSqBrackOp(InstSqBrackOp const &rSrc) :
				AInstruction(rSrc._rInterpreter)
{
	type = '[';
}

InstSqBrackOp	&InstSqBrackOp::operator=(InstSqBrackOp const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
