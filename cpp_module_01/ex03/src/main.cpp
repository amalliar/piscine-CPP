/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:10:02 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 00:07:36 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "ZombieHorde.hpp"

int		main(void)
{
	std::srand(std::time(NULL));
	ZombieHorde zhorde(10);
	zhorde.announce();
	return (0);
}
