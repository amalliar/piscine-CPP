/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:04:27 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/23 05:07:21 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

// Shunting-yard algorithm.

std::queue<t_tok>	*parser_build(std::list<t_tok> const &rTokList)
{
	std::queue<t_tok>	*p_out_queue = new std::queue<t_tok>;
	std::stack<t_tok>	*p_oper_stack = new std::stack<t_tok>;
	t_tok				token;

	for (std::list<t_tok>::const_iterator it = rTokList.begin(); it != rTokList.end(); ++it)
	{
		token = *it;
		if (token.type == TT_NUMBER)
		{
			size_t idx;
			try
			{
				token.fval = Fixed(std::stof(token.data, &idx));
				if (idx != token.data.length())
					exit_error("eval_expr: invalid argument", 1);
			}
			catch (std::invalid_argument &ia)
			{
				exit_error("eval_expr: invalid argument", 1);
			}
			catch (std::out_of_range &oor)
			{
				exit_error("eval_expr: out of range", 1);
			}
			p_out_queue->push(token);
		}
		else if (token.type == TT_OPERATOR)
		{
			while (!p_oper_stack->empty() && p_oper_stack->top().type == TT_OPERATOR && \
				oper_precedence(token.data[0]) <= oper_precedence(p_oper_stack->top().data[0]))
			{
				p_out_queue->push(p_oper_stack->top());
				p_oper_stack->pop();
			}
			p_oper_stack->push(token);
		}
		else if (token.type == TT_LEFT_PARENTH)
			p_oper_stack->push(token);
		else if (token.type == TT_RIGHT_PARENTH)
		{
			while (!p_oper_stack->empty() && p_oper_stack->top().type != TT_LEFT_PARENTH)
			{
				p_out_queue->push(p_oper_stack->top());
				p_oper_stack->pop();
			}
			if (!p_oper_stack->empty())  // Found left parenthesis.
				p_oper_stack->pop();
			else
				exit_error("eval_expr: parse error", 1);
		}
	}
	while (!p_oper_stack->empty())
		if (p_oper_stack->top().type == TT_LEFT_PARENTH || p_oper_stack->top().type == TT_RIGHT_PARENTH)
			exit_error("eval_expr: parse error", 1);
		else
		{
			p_out_queue->push(p_oper_stack->top());
			p_oper_stack->pop();
		}
	delete p_oper_stack;
	return (p_out_queue);
}
