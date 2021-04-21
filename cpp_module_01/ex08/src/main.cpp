/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:47:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 19:18:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <string>
#include "Human.hpp"

int		main(void)
{
	Human	bob("Bob");

	std::srand(std::time(NULL));
	for (int i = 0; i < 20; ++i)
		bob.action(Human::actMap[std::rand() % Human::numActs].name, "rabbit");
	return (0);
}
