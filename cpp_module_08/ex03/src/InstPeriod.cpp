/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstPeriod.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 16:12:47 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstPeriod.hpp"
#include "Interpreter.hpp"

void		InstPeriod::exec(void) const
{
	std::cout << *_rInterpreter._cellPointer << std::flush;
}

			InstPeriod::InstPeriod(Interpreter &rInterpreter) :
			AInstruction(rInterpreter)
{
	type = '.';
}

			InstPeriod::~InstPeriod(void)
{
}

			InstPeriod::InstPeriod(InstPeriod const &rSrc) :
			AInstruction(rSrc._rInterpreter)
{
	type = '.';
}

InstPeriod	&InstPeriod::operator=(InstPeriod const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
