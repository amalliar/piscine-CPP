/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:47:59 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 00:33:04 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(void)
{
	std::string		msg = "HI THIS IS BRAIN";
	std::string		*p_msg = &msg;
	std::string		&r_msg = msg;

	std::cout << "p_msg: " << *p_msg << std::endl;
	std::cout << "r_msg: " << r_msg << std::endl;
	return (0);
}
