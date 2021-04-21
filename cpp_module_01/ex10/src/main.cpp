/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:50:33 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 20:08:04 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <cstring>
#include <sys/stat.h>

static void		pstream(std::istream &rIs)
{
	std::string		input;

	while (std::getline(rIs, input))
	{
		std::cout << input << std::flush;
		if (!rIs.eof())
			std::cout << std::endl << std::flush;
	}
}

static int		ifs_test_open(std::ifstream &rIfs, char const *pFile)
{
	struct stat		st;
	std::string		err_msg;

	rIfs.open(pFile);
	stat(pFile, &st);

	if (!rIfs || S_ISDIR(st.st_mode))
	{
		rIfs.close();
		err_msg = static_cast<std::string>("cato9tails: ") + pFile;
		if (rIfs && S_ISDIR(st.st_mode))
			errno = EISDIR;
		perror(err_msg.c_str());
		errno = 0;
		return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	std::ifstream	ifs;
	int				ret = 0;

	if (argc == 1)
		pstream(std::cin);
	else
		for (int i = 1; i < argc; ++i)
		{
			if (ifs_test_open(ifs, argv[i]))
			{
				ret = 1;
				continue ;
			}
			pstream(ifs);
			ifs.close();
		}
	return (ret);
}
