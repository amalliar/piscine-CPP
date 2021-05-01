/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 05:09:26 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 08:38:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

void				exit_error(std::string const &rErrMsg, int status)
{
	std::cerr << rErrMsg << std::endl;
	exit(status);
}

int					oper_precedence(char const oper)
{
	static std::string		preced_2 = "+-";
	static std::string		preced_3 = "*/";

	if (preced_2.find(oper) != std::string::npos)
		return (2);
	if (preced_3.find(oper) != std::string::npos)
		return (3);
	return (0);
}

void				print_toks(std::list<t_tok> const &rTokList, std::string const &rMsg)
{
	std::cout << rMsg;
	for (std::list<t_tok>::const_iterator it = rTokList.begin(); it != rTokList.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void				print_toks(std::queue<t_tok> tokQueue, std::string const &rMsg)
{
	std::cout << rMsg;
	while (tokQueue.size() != 0)
	{
		std::cout << " " << tokQueue.front();
		tokQueue.pop();
	}
	std::cout << std::endl;
}

static std::string	get_operation(t_tok const &rTok)
{
	if (rTok.type == TT_NUMBER)
		return ("OP Push");
	else if (rTok.sData[0] == '+')
		return ("OP Add");
	else if (rTok.sData[0] == '-')
		return ("OP Subtract");
	else if (rTok.sData[0] == '*')
		return ("OP Multiply");
	else if (rTok.sData[0] == '/')
		return ("OP Divide");
	return ("OP Unknown");
}

void				print_step(t_tok const &rTok, MutantStack<t_tok> const &rStack)
{

	// Set left-justified field formatting.
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << "I " << std::setw(12) << rTok;
	std::cout << "| " << std::setw(12) << get_operation(rTok);
	std::cout << "| ST";
	for (MutantStack<t_tok>::const_reverse_iterator it = rStack.crbegin(); it != rStack.crend(); ++it)
		std::cout << " " << it->fixedNum;
	std::cout << "]" << std::endl;
	// Clear field formatting.
	std::cout.setf(std::ios::adjustfield);
}

std::ostream		&operator<<(std::ostream &rOs, t_tok const &rRhs)
{
	// Note: use ostringstream object in order to buffer output for
	// ostream in case some formatting is applied.
	std::ostringstream	oss;

	if (rRhs.type == TT_NUMBER)
		oss << "Num(" << rRhs.sData << ")";
	else if (rRhs.type == TT_LEFT_PARENTH)
		oss << "ParOpen";
	else if (rRhs.type == TT_RIGHT_PARENTH)
		oss << "ParClose";
	else if (rRhs.type == TT_OPERATOR)
		oss << "Op(" << rRhs.sData << ")";
	rOs << oss.str();
	return (rOs);
}
