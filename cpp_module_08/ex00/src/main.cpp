/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:27:06 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/18 20:06:11 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int			main(void)
{
	int							arr[6] = {16, 2, 77, 42, 29, 21};
	std::vector<int>			v0(arr, arr + 6);
	std::list<int>				l0(arr, arr + 6);
	std::deque<int>				d0(arr, arr + 6);

	std::cout << "easyfind(v0, 42): " << *easyfind(v0, 42) << std::endl;
	std::cout << "easyfind(l0, 42): " << *easyfind(l0, 42) << std::endl;
	std::cout << "easyfind(d0, 42): " << *easyfind(d0, 42) << std::endl;
	if (easyfind(d0, 24) == d0.end())
		std::cout << "easyfind(d0, 24): not found" << std::endl;

	return (0);
}
