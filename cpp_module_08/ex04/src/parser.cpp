/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:04:27 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 16:53:33 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

//	Shunting-yard algorithm.

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
				token.fixedNum = Fixed(std::stof(token.sData, &idx));
				if (idx != token.sData.length())
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
			//	While ((there is an operator at the top of the operator stack) and 
			//	((the operator at the top of the operator stack has greater precedence) or
			//	(the operator at the top of the operator stack has equal precedence and
			//	the token is left associative)) and
			//	(the operator at the top of the operator stack is not a left parenthesis)):
			//	pop operators from the operator stack onto the output queue.
			while (!p_oper_stack->empty() && p_oper_stack->top().type == TT_OPERATOR && \
				oper_precedence(token.sData[0]) <= oper_precedence(p_oper_stack->top().sData[0]))
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
			//	While the operator at the top of the operator stack is not a left parenthesis:
			//	pop the operator from the operator stack onto the output queue.
			while (!p_oper_stack->empty() && p_oper_stack->top().type != TT_LEFT_PARENTH)
			{
				p_out_queue->push(p_oper_stack->top());
				p_oper_stack->pop();
			}
			//	If there is a left parenthesis at the top of the operator stack, then:
			//	pop the operator from the operator stack and discard it.
			if (!p_oper_stack->empty())
				p_oper_stack->pop();
			else
				//	If the stack runs out without finding a left parenthesis, then:
				//	there are mismatched parentheses.
				exit_error("eval_expr: parse error", 1);
		}
	}
	
	//	After for loop, if operator stack not null, pop everything to output queue.
	while (!p_oper_stack->empty())
		//	If the operator token on the top of the stack is a parenthesis, then:
		//	there are mismatched parentheses.
		if (p_oper_stack->top().type == TT_LEFT_PARENTH || \
			p_oper_stack->top().type == TT_RIGHT_PARENTH)
			exit_error("eval_expr: parse error", 1);
		else
		{
			p_out_queue->push(p_oper_stack->top());
			p_oper_stack->pop();
		}

	delete p_oper_stack;
	return (p_out_queue);
}
