/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:13:00 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 00:28:02 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

void			ZombieHorde::announce(void) const
{
	for (size_t i = 0; i < this->_zmbHordeSize; ++i)
		this->_pZmbHorde[i].announce();
}

				ZombieHorde::ZombieHorde(int zHordeSize) :
				_zmbHordeSize(zHordeSize)
{
	std::string const	names[] = 
	{
		"Martin", "Tyler", "Victor", "Arron", "Norman", "Oliver",
		"Olyvia", "Patric", "Paula", "Peter", "Philip", "Rachel"
	};	
	size_t			num_names = sizeof(names) / sizeof(std::string);
	size_t			zmb_type;

	this->_pZmbHorde = new Zombie [this->_zmbHordeSize];
	for (size_t i = 0; i < this->_zmbHordeSize; ++i)
	{
		zmb_type = std::rand() % ZombieEvent::numZombieTypes;
		this->_pZmbHorde[i].setType(ZombieEvent::zombieTypes[zmb_type]);
		this->_pZmbHorde[i].setName(names[std::rand() % num_names]);
		if (zmb_type == 10)
			this->_pZmbHorde[i].setName("???");
	}
}

				ZombieHorde::ZombieHorde(ZombieHorde const &rSrc) :
				_zmbHordeSize(rSrc._zmbHordeSize)
{
	this->_pZmbHorde = new Zombie [this->_zmbHordeSize];
	for (size_t i = 0; i < this->_zmbHordeSize; ++i)
		this->_pZmbHorde[i] = rSrc._pZmbHorde[i];
}

				ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_pZmbHorde;
}

ZombieHorde		&ZombieHorde::operator=(ZombieHorde const &rRhs)
{
	this->_zmbHordeSize = rRhs._zmbHordeSize;
	this->_pZmbHorde = new Zombie [this->_zmbHordeSize];
	for (size_t i = 0; i < this->_zmbHordeSize; ++i)
		this->_pZmbHorde[i] = rRhs._pZmbHorde[i];
	return (*this);
}

				ZombieHorde::ZombieHorde(void)
{
}
