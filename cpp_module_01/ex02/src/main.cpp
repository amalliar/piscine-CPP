/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:10:02 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 23:00:01 by amalliar         ###   ########.fr       */
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
		zmb_event.setZombieType(std::rand() % ZombieEvent::numZombieTypes);
		delete zmb_event.randomChump();
	}
	return (0);
}
