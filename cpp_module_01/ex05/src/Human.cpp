/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:59:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:03:44 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Brain const		&Human::getBrain(void) const
{
	return (_brain);
}

std::string		Human::identify(void) const
{
	return (_brain.identify());
}

				Human::Human(void)
{
}

				Human::Human(Human const &rSrc)
{
	static_cast<void>(rSrc);
}

				Human::~Human(void)
{
}

Human			&Human::operator=(Human const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
