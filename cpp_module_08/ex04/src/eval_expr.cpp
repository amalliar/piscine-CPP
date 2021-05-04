/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:07:34 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 13:20:07 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

static Fixed	apply_oper(Fixed const &lhs, Fixed const &rhs, char oper)
{
	if (oper == '+')
		return (lhs + rhs);
	if (oper == '-')
		return (lhs - rhs);
	if (oper == '*')
		return (lhs * rhs);
	if (oper == '/')
		return (lhs / rhs);
	return (Fixed(0));
}

Fixed			eval_expr(std::queue<t_tok> &rRpnQueue)
{
	MutantStack<t_tok>			expr_stack;
	std::pair<t_tok, t_tok>		operands;
	t_tok						token;

	while (!rRpnQueue.empty())
	{
		token = rRpnQueue.front();

		//	If the token is a number, push this value onto the stack.
		if (token.type == TT_NUMBER)
			expr_stack.push(token);

		//	Else if the token is an operator then, pop two items from the top of the stack and
		//	push the result of the operation onto the stack.
		else if (token.type == TT_OPERATOR && expr_stack.size() >= 1)
		{
			operands.second = expr_stack.top();
			expr_stack.pop();
			operands.first.fixedNum = Fixed(0);
			if (expr_stack.size() > 0)
			{
				operands.first = expr_stack.top();
				expr_stack.pop();
			}
			token.fixedNum = \
				apply_oper(operands.first.fixedNum, operands.second.fixedNum, token.sData[0]);
			token.type = TT_NUMBER;
			expr_stack.push(token);
		}
		else
			exit_error("eval_expr: parse error", 1);

		print_step(rRpnQueue.front(), expr_stack);
		rRpnQueue.pop();
	}
	if (expr_stack.size() != 1)
		exit_error("eval_expr: parse error", 1);
	return (expr_stack.top().fixedNum);
}
