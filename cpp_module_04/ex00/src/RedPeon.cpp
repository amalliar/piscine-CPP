/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedPeon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:22:46 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 02:23:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedPeon.hpp"

void			RedPeon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a " << CLR_BBLUE(blue pony) << "!" << std::endl;
}

				RedPeon::RedPeon(std::string const &rName) :
				Peon(rName)
{
}

				RedPeon::RedPeon(RedPeon const &rSrc)
{
	*this = rSrc;
}

				RedPeon::~RedPeon(void)
{
}

RedPeon			&RedPeon::operator=(RedPeon const &rRhs)
{
	this->_name = rRhs.getName();
	return (*this);
}

				RedPeon::RedPeon(void)
{
}
