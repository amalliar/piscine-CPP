/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:54:05 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 20:03:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

static void			exit_fatal(std::string const &rMsg)
{
	std::cout << rMsg << std::endl;
	exit(EXIT_FAILURE);
}

static int			ifs_test_open(std::ifstream &rIfs, char const *pFile)
{
	struct stat		st;
	std::string		err_msg;

	rIfs.open(pFile);
	stat(pFile, &st);

	if (!rIfs || S_ISDIR(st.st_mode))
	{
		rIfs.close();
		err_msg = static_cast<std::string>("replace: ") + pFile;
		if (rIfs && S_ISDIR(st.st_mode))
			errno = EISDIR;
		perror(err_msg.c_str());
		errno = 0;
		return (1);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	std::ifstream 	ifs;
	std::string		err_msg;

	if (argc != 4 || !*argv[1] || !*argv[2] || !*argv[3])
	{
		err_msg = "usage: replace file string1 string2";
		exit_fatal(err_msg);
	}
	if (ifs_test_open(ifs, argv[1]))
		exit(EXIT_FAILURE);

	std::string data;
	data.assign((std::istreambuf_iterator<char>(ifs)),
                (std::istreambuf_iterator<char>()));
	ifs.close();

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	size_t pos = 0;
	while ((pos = data.find(s1, pos)) != std::string::npos)
	{
		data.replace(pos, s1.length(), s2);
		pos += s2.length();
	}

	std::string o_name = argv[1];
	o_name += ".replace";
	std::ofstream ofs(o_name);
	ofs << data.c_str();
	if (!ofs.good())
	{
		err_msg = "replace: " + o_name + ": " + strerror(errno);
		exit_fatal(err_msg);
	}
	ofs.close();

	return (0);
}
