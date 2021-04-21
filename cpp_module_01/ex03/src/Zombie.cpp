/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:51:51 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 23:49:27 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string		Zombie::zombieTypes[] =
{
	"Zombie",
	"Flag Zombie",
	"Conehead Zombie",
	"Pole Vaulting Zombie",
	"Buckethead Zombie",
	"Football Zombie",
	"Dancing Zombie",
	"Zomboni",
	"Pogo Zombie",
	"Bungee Zombie",
	"Zombie Yeti"
};

int				Zombie::setName(std::string const &rName)
{
	this->_name = rName;
	return (0);
}

int				Zombie::setType(std::string const &rType)
{
	for (size_t i = 0; i < numZombieTypes; ++i)
		if (!rType.compare(zombieTypes[i]))
		{
			this->_type = rType;
			return (0);
		}
	return (1);
}

void			Zombie::announce(void) const
{
	std::string		clr_bred = "\033[1;31m";
	std::string		clr_noc = "\033[0m";

	if (!this->_type.compare("Zombie Yeti"))
		std::cout << clr_bred;
	std::cout << this->_type << " " << this->_name << ": Braiiiiiiinnnssss...";
	std::cout << clr_noc << std::endl;
}

				Zombie::Zombie(std::string const &rName, std::string const &rType) :
				_name(rName),
				_type("Zombie")
{
	this->setType(rType);
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

				Zombie::Zombie(void)
{
	std::string const	names[] = 
	{
		"Martin", "Tyler", "Victor", "Arron", "Norman", "Oliver",
		"Olyvia", "Patric", "Paula", "Peter", "Philip", "Rachel"
	};	
	size_t				num_names = sizeof(names) / sizeof(std::string);

	this->_name = names[std::rand() % num_names];
	this->_type = "Zombie";
}
