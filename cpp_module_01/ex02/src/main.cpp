/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:10:02 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 23:44:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent		zmb_event;

	std::srand(std::time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		zmb_event.setZombieType(Zombie::zombieTypes[std::rand() % Zombie::numZombieTypes]);
		delete zmb_event.randomChump();
	}
	return (0);
}
