/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:13:42 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 19:56:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include "Logger.hpp"

static void		exit_fatal(std::string const &rMsg)
{
	std::cout << rMsg << std::endl;
	exit(EXIT_FAILURE);
}

int				main(int argc, char **argv)
{
	std::string		prompt = "logger> ";
	std::string		input;
	std::string		err_msg;

	if (argc == 1)
	{
		err_msg = "usage: logger file";
		exit_fatal(err_msg);
	}
	Logger lg(argv[1]);
	std::cout << prompt;
	while (std::getline(std::cin, input))
	{
		if (lg.log("logToConsole", input) || lg.log("logToFile", input))
		{
			err_msg = static_cast<std::string>("logger: ") + argv[1] + ": " + strerror(errno);
			exit_fatal(err_msg);
		}
		std::cout << prompt;
	}
	static_cast<void>(argc);
	return (0);
}
