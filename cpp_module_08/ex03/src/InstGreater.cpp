/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstGreater.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:20:30 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstGreater.hpp"
#include "Interpreter.hpp"

void		InstGreater::exec(void) const
{
	//	No bounds checking is done to avoid extra overhead.
	++_rInterpreter._cellPointer;
}

			InstGreater::InstGreater(Interpreter &rInterpreter) :
			AInstruction(rInterpreter)
{
	type = '>';
}

			InstGreater::~InstGreater(void)
{
}

			InstGreater::InstGreater(InstGreater const &rSrc) :
			AInstruction(rSrc._rInterpreter)
{
	type = '>';
}

InstGreater	&InstGreater::operator=(InstGreater const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
