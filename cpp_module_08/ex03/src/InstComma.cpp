/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstComma.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:11:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:24:16 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstComma.hpp"
#include "Interpreter.hpp"

void		InstComma::exec(void) const
{
	char c = std::cin.get();
	if (std::cin.good())
		*_rInterpreter._cellPointer = c;
}

			InstComma::InstComma(Interpreter &rInterpreter) :
			AInstruction(rInterpreter)
{
	type = ',';
}

			InstComma::~InstComma(void)
{
}

			InstComma::InstComma(InstComma const &rSrc) :
			AInstruction(rSrc._rInterpreter)
{
	type = ',';
}

InstComma	&InstComma::operator=(InstComma const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
