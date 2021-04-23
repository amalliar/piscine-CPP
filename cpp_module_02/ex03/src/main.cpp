/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:37:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/23 05:21:17 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

// Note: tecnically the usage of STL containers is forbiden up until cpp_module_08,
// but we're gonna reimplement them anyway in ft_containers so I don't care.

int				main(int argc, char **argv)
{
	std::list<t_tok>	*tok_list;
	std::queue<t_tok>	*rpn_queue;

	if (argc != 2)
		exit_error("usage: eval_expr 'expression'", 2);

	tok_list = lexer_build(argv[1]);
	rpn_queue = parser_build(*tok_list);
	std::cout << eval_expr(*rpn_queue) << std::endl;
	delete tok_list;
	delete rpn_queue;

	return (0);
}
