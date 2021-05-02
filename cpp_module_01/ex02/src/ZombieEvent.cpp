/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:09:22 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 16:54:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int				ZombieEvent::setZombieType(std::string const &rType)
{
	for (size_t i = 0; i < Zombie::numZombieTypes; ++i)
		if (!rType.compare(Zombie::zombieTypes[i]))
		{
			_curZombieType = rType;
			return (0);
		}
	return (1);
}

Zombie			*ZombieEvent::newZombie(std::string const &rName) const
{
	return (new Zombie(rName, _curZombieType));
}

Zombie			*ZombieEvent::randomChump(void) const
{
	Zombie	*zmb;

	zmb = new Zombie();
	if (_curZombieType == "Zombie Yeti")
		zmb->setName("???");
	zmb->setType(_curZombieType);
	zmb->announce();
	return (zmb);
}

				ZombieEvent::ZombieEvent(void) :
				_curZombieType(Zombie::zombieTypes[0])
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
	if (this != &rRhs)
	{
		_curZombieType = rRhs._curZombieType;
	}
	return (*this);
}
