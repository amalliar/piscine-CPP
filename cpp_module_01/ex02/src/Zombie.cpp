/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:51:51 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 22:32:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void			Zombie::announce(void) const
{
	if (!this->_type.compare("Zombie Yeti"))
		std::cout << "\033[1;31m";  // clr_bred
	std::cout << this->_type << " " << this->_name << ": Braiiiiiiinnnssss...";
	std::cout << "\033[0m" << std::endl;

}

				Zombie::Zombie(std::string const &rName, std::string const &rType) :
				_name(rName),
				_type(rType)
{
}

				Zombie::Zombie(Zombie const &rSrc) :
				_name(rSrc._name),
				_type(rSrc._type)
{
}

				Zombie::~Zombie(void)
{
}

Zombie			&Zombie::operator=(Zombie const &rRhs)
{
	this->_name = rRhs._name;
	this->_type = rRhs._type;
	return (*this);
}

				Zombie::Zombie(void) :
				_name("Stubbs"),
				_type("Zombie")
{
}
