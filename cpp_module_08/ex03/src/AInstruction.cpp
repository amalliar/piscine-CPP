/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AInstruction.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:25:17 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 13:57:35 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AInstruction.hpp"

				AInstruction::AInstruction(Interpreter &rInterpreter) :
				_rInterpreter(rInterpreter)
{
}

				AInstruction::~AInstruction(void)
{
}

				AInstruction::AInstruction(AInstruction const &rSrc) :
				_rInterpreter(rSrc._rInterpreter)
{
}

AInstruction	&AInstruction::operator=(AInstruction const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
