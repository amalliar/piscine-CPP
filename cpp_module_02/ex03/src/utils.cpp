/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:09:26 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/23 05:09:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

void		exit_error(std::string const &rErrMsg, int status)
{
	std::cerr << rErrMsg << std::endl;
	exit(status);
}


int			oper_precedence(char const oper)
{
	static std::string		preced_2 = "+-";
	static std::string		preced_3 = "*/";

	if (preced_2.find(oper) != std::string::npos)
		return (2);
	if (preced_3.find(oper) != std::string::npos)
		return (3);
	return (0);
}
