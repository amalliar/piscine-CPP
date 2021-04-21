/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:59:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 01:00:11 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Brain const		&Human::getBrain(void) const
{
	return (this->_brain);
}

std::string		Human::identify(void) const
{
	return (this->_brain.identify());
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
