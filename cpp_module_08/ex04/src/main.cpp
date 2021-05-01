/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:37:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 08:18:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

int		main(int argc, char **argv)
{
	std::list<t_tok>	*tok_list;
	std::queue<t_tok>	*rpn_queue;
	Fixed				res;

	if (argc != 2)
		exit_error("usage: eval_expr 'expression'", 2);

	tok_list = lexer_build(argv[1]);
	print_toks(*tok_list, "Tokens:");
	rpn_queue = parser_build(*tok_list);
	print_toks(*rpn_queue, "Postfix:");
	std::cout << std::endl;
	res = eval_expr(*rpn_queue);
	std::cout << std::endl << "Result: " << res << std::endl;
	delete tok_list;
	delete rpn_queue;

	return (0);
}
