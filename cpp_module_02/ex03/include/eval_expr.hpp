/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:10:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/23 05:22:34 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_HPP
# define EVAL_EXPR_HPP

# include <cctype>
# include <cstdlib>
# include <iostream>
# include <list>
# include <queue>
# include <stack>
# include <string>
# include "Fixed.hpp"

enum				e_tok_types
{
	TT_NUMBER,
	TT_OPERATOR,
	TT_LEFT_PARENTH,
	TT_RIGHT_PARENTH
};

typedef struct		s_tok
{
	int				type;
	std::string		data;
	Fixed			fval;
}					t_tok;

std::list<t_tok>	*lexer_build(std::string const &rExpr);
std::queue<t_tok>	*parser_build(std::list<t_tok> const &rTokList);
Fixed				eval_expr(std::queue<t_tok> &rRpnQueue);
void				exit_error(std::string const &rErrMsg, int status);
int					oper_precedence(char const oper);

#endif // EVAL_EXPR_HPP
