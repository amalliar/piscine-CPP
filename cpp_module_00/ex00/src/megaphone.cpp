/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:24:16 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 07:09:09 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int		main(int argc, char **argv)
{
	char	*arg;

	for (int i = 1; i < argc; ++i)
	{
		arg = argv[i];
		while (*arg)
			std::cout << static_cast<char>(std::toupper(*arg++));
	}
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
