/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:10:08 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 00:58:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string		Brain::identify(void) const
{
	std::ostringstream		fmt;

	fmt << std::hex << (void *)this;
	return (fmt.str());
}

				Brain::Brain(void)
{
}

				Brain::~Brain(void)
{
}

				Brain::Brain(Brain const &rSrc)
{
	static_cast<void>(rSrc);
}

Brain			&Brain::operator=(Brain const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
