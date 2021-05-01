/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:01:53 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/27 00:34:53 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

std::list<t_tok>	*lexer_build(std::string const &rExpr)
{
	std::list<t_tok>	*p_tok_list = new std::list<t_tok>;
	t_tok				token;
	std::string			char_parenth = "()";
	std::string			char_operator = "+-*/";  // Note: all of these operators are left-associative.
	std::string			char_number = "0123456789.";
	char				c;

	for (std::string::const_iterator it = rExpr.begin(); it != rExpr.end(); ++it)
	{
		c = *it;
		if (char_parenth.find(c) != std::string::npos || \
			char_operator.find(c) != std::string::npos)
		{
			if (!token.sData.empty())
				p_tok_list->push_back(token);
			token.sData = c;
			if (c == '(')
				token.type = TT_LEFT_PARENTH;
			else if (c == ')')
				token.type = TT_RIGHT_PARENTH;
			else
				token.type = TT_OPERATOR;
			p_tok_list->push_back(token);
			token.sData.erase();
		}
		else if (char_number.find(c) != std::string::npos)
		{
			token.sData += c;
			token.type = TT_NUMBER;
		}
		else if (std::isspace(c))
		{
			if (!token.sData.empty())
				p_tok_list->push_back(token);
			token.sData.erase();
		}
		else
			exit_error(std::string("eval_expr: illegal character: ") + c, 1);
	}
	if (!token.sData.empty())
		p_tok_list->push_back(token);
	return (p_tok_list);
}
