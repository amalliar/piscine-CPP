/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:07:34 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/23 05:08:21 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

Fixed		eval_expr(std::queue<t_tok> &rRpnQueue)
{
	std::stack<t_tok>			expr_stack;
	std::pair<t_tok, t_tok>		operands;
	t_tok						token;

	while (!rRpnQueue.empty())
	{
		token = rRpnQueue.front();
		rRpnQueue.pop();
		if (token.type == TT_NUMBER)
			expr_stack.push(token);
		else if (token.type == TT_OPERATOR && expr_stack.size() >= 1)
		{
			operands.second = expr_stack.top();
			expr_stack.pop();
			operands.first.fval = Fixed(0);
			if (expr_stack.size() > 0)
			{
				operands.first = expr_stack.top();
				expr_stack.pop();
			}
			token.type = TT_NUMBER;
			switch (token.data[0])
			{
				case	'+':
					token.fval = Fixed(operands.first.fval + operands.second.fval);
					break ;
				case	'-':
					token.fval = Fixed(operands.first.fval - operands.second.fval);
					break ;
				case	'*':
					token.fval = Fixed(operands.first.fval * operands.second.fval);
					break ;
				case	'/':
					token.fval = Fixed(operands.first.fval / operands.second.fval);
					break ;
			}
			expr_stack.push(token);
		}
		else
			exit_error("eval_expr: parse error", 1);
	}
	if (expr_stack.size() != 1)
		exit_error("eval_expr: parse error", 1);
	return (expr_stack.top().fval);
}
