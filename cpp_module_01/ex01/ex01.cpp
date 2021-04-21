/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:54:16 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/01 13:59:57 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void		memoryLeak()
{
	std::string		*panther = new std::string("String panther");

	std::cout << *panther << std::endl;
	delete panther;
}

int			main(void)
{
	memoryLeak();
	return (0);
}
