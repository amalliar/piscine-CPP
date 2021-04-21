/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:09:22 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 23:01:29 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string		ZombieEvent::zombieTypes[ZombieEvent::numZombieTypes] =
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

int				ZombieEvent::setZombieType(int type)
{
	if (type >= 0 && type < numZombieTypes)
	{
		this->_curZombieType = type;
		return (0);
	}
	return (-1);
}

Zombie			*ZombieEvent::newZombie(std::string const &rName) const
{
	return (new Zombie(rName, zombieTypes[this->_curZombieType]));
}

Zombie			*ZombieEvent::randomChump(void) const
{
	std::string const	names[] = 
	{
		"Martin", "Tyler", "Victor", "Arron", "Norman", "Oliver",
		"Olyvia", "Patric", "Paula", "Peter", "Philip", "Rachel"
	};	
	size_t			num_names = sizeof(names) / sizeof(std::string);
	Zombie			*zmb;

	zmb = this->newZombie((this->_curZombieType == 10) ? "???" : names[std::rand() % num_names]);
	zmb->announce();
	return (zmb);
}

				ZombieEvent::ZombieEvent(void) :
				_curZombieType(0)
{
}

				ZombieEvent::ZombieEvent(ZombieEvent const &rSrc) :
				_curZombieType(rSrc._curZombieType)
{
}

				ZombieEvent::~ZombieEvent(void)
{
}

ZombieEvent		&ZombieEvent::operator=(ZombieEvent const &rRhs)
{
	this->_curZombieType = rRhs._curZombieType;
	return (*this);
}
