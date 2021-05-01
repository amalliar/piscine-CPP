/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:10:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 07:31:52 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_HPP
# define EVAL_EXPR_HPP

# include <cctype>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <list>
# include <queue>
# include <stack>
# include <string>
# include "Fixed.hpp"
# include "MutantStack.hpp"

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
	std::string		sData;
	Fixed			fixedNum;
}					t_tok;

std::ostream		&operator<<(std::ostream &rOs, t_tok const &rRhs);

std::list<t_tok>	*lexer_build(std::string const &rExpr);
std::queue<t_tok>	*parser_build(std::list<t_tok> const &rTokList);
Fixed				eval_expr(std::queue<t_tok> &rRpnQueue);
void				exit_error(std::string const &rErrMsg, int status);
int					oper_precedence(char const oper);
void				print_toks(std::list<t_tok> const &rTokList, std::string const &rMsg);
void				print_toks(std::queue<t_tok> tokQueue, std::string const &rMsg);
void				print_step(t_tok const &rTok, MutantStack<t_tok> const &rStack);

#endif // EVAL_EXPR_HPP
