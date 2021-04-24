/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:01:10 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/14 12:40:25 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int			main(void)
{
	Bureaucrat	bc("Hermes Conrad", 34);
	Form		fm0("TotallyUselessForm", 42, 32); 
	Form		fm1("SlightlyLessUselessForm", 32, 22); 

	std::cout << bc << fm0 << fm1 << std::endl;
	bc.signForm(fm0);
	bc.signForm(fm0);
	bc.signForm(fm1);

	return (0);
}
