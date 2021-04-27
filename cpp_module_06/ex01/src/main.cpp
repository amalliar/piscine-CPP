/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:18 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/27 06:58:13 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "colors.hpp"

typedef struct __attribute__ ((packed))	s_data
{
	std::string		*p_str0;
	int				nbr;
	std::string		*p_str1;
}										t_data;

std::ostream	&operator<<(std::ostream &rOs, t_data &rRhs)
{
	rOs << clr_byellow("struct") << " t_data" << std::endl;
	rOs << "{" << std::endl;
	rOs << "    " << clr_bpurple("p_str0") << ": " << *rRhs.p_str0 << std::endl;
	rOs << "    " << clr_bpurple("nbr") << ": " << rRhs.nbr << std::endl;
	rOs << "    " << clr_bpurple("p_str1") << ": " << *rRhs.p_str1 << std::endl;
	rOs << "}" << std::endl;
	return (rOs);
}

void			*serialize(void)
{
	t_data		*p_data = new t_data;

	p_data->nbr = rand();
	p_data->p_str0 = new std::string;
	p_data->p_str1 = new std::string;
	p_data->p_str0->resize(p_data->nbr % 64 + 1);
	p_data->p_str1->resize(p_data->nbr % 64 + 1);
	for (int i = 0; i < p_data->nbr % 64 + 1; ++i)
	{
		(*p_data->p_str0)[i] = rand() % 96 + 32;  // ASCII printable characters (character code 32-127)
		(*p_data->p_str1)[i] = rand() % 96 + 32;
	}
	std::cout << *p_data;
	return (reinterpret_cast<void *>(p_data));
}

t_data			*deserialize(void *p_raw)
{
	return (reinterpret_cast<t_data *>(p_raw));
}

int				main(void)
{
	void		*p_raw;
	t_data		*p_data;

	std::srand(std::time(NULL));
	p_raw = serialize();
	p_data = deserialize(p_raw);
	std::cout << *p_data;
	return (0);
}
