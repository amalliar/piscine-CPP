/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:42:09 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/13 12:42:10 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "RedPeon.hpp"
#include "Perifalk.hpp"
#include "colors.hpp"

int		main(void)
{
	Sorcerer	robert("Robert", "the Magnificent");

	Victim		jim("Jimmy");
	Peon		joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << std::endl << CLR_BWHITE(==> Begin extra tests) << std::endl;

	Victim		*james = new Peon("James");
	Victim		*jack = new RedPeon("Jack");
	Victim		*jon = new Perifalk("Jon");

	std::cout << *james << *jack << *jon;

	robert.polymorph(*james);
	robert.polymorph(*jack);
	robert.polymorph(*jon);

	delete jon;
	delete jack;
	delete james;

	std::cout << CLR_BWHITE(==> End extra tests) << std::endl << std::endl;

	return (0);
}
