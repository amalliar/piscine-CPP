/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:37:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 16:48:03 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include "Interpreter.hpp"
#include "colors.hpp"

static void		ifs_test_open(std::ifstream &rIfs, char const *pFile)
{
	struct stat		st;
	std::string		err_msg;

	rIfs.open(pFile);
	stat(pFile, &st);

	if (!rIfs || S_ISDIR(st.st_mode))
	{
		rIfs.close();
		err_msg = static_cast<std::string>("mindopen: ") + pFile;
		if (rIfs && S_ISDIR(st.st_mode))
			errno = EISDIR;
		perror(err_msg.c_str());
		exit(1);
	}
}

static void		exit_error(std::string const &rMsg)
{
	std::cerr << "mindopen: " << clr_bred("error: ") << rMsg << std::endl;
	exit(1);
}

int				main(int argc, char **argv)
{
	Interpreter		inter;
	std::ifstream	ifs;
	std::string		input;

	if (argc == 1)
		exit_error("no input files");
	for (int i = 1; i < argc; ++i)
	{
		ifs_test_open(ifs, argv[i]);
		input.assign((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));
		ifs.close();
		try
		{
			inter.setInput(input);
			inter.execute();
		}
		catch (std::exception &ex)
		{
			exit_error(ex.what());
		}
		if (i != argc - 1)
			std::cout << std::endl;
	}
	return (0);
}
