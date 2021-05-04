/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:03:25 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:42:53 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interpreter.hpp"
#include "AInstruction.hpp"

void			Interpreter::setInput(std::string const &rInput)
					throw (UnmatchedSqBrackOpException, UnmatchedSqBrackClException)
{
	std::string								inst_string = "+-><.,[]";
	std::map<char, AInstruction const *>	inst_map;

	inst_map['+'] = &_instPlus;
	inst_map['-'] = &_instMinus;
	inst_map['>'] = &_instGreater;
	inst_map['<'] = &_instLess;
	inst_map['.'] = &_instPeriod;
	inst_map[','] = &_instComma;
	inst_map['['] = &_instSqBrackOp;
	inst_map[']'] = &_instSqBrackCl;

	_clear();
	for (size_t i = 0; i < rInput.length(); ++i)
		if (inst_string.find(rInput[i]) != std::string::npos)
			_instructions.push_back(inst_map[rInput[i]]);
	_buildSqBrackLookupMap();
}

void			Interpreter::execute(void)
{
	for (_instPointer = _instructions.begin(); _instPointer != _instructions.end(); ++_instPointer)
		(*_instPointer)->exec();
}

				Interpreter::Interpreter(void) :
				_cells(32768, 0),
				_cellPointer(_cells.begin()),
				_instPointer(_instructions.begin()),
				_instPlus(*this),
				_instMinus(*this),
				_instGreater(*this),
				_instLess(*this),
				_instPeriod(*this),
				_instComma(*this),
				_instSqBrackOp(*this),
				_instSqBrackCl(*this)
{
}

				Interpreter::Interpreter(std::string const &rInput)
					throw (UnmatchedSqBrackOpException, UnmatchedSqBrackClException) :
				_cells(32768, 0),
				_cellPointer(_cells.begin()),
				_instPointer(_instructions.begin()),
				_instPlus(*this),
				_instMinus(*this),
				_instGreater(*this),
				_instLess(*this),
				_instPeriod(*this),
				_instComma(*this),
				_instSqBrackOp(*this),
				_instSqBrackCl(*this)
{
	setInput(rInput);
}

				Interpreter::~Interpreter(void)
{
}

const char		*Interpreter::UnmatchedSqBrackOpException::what() const throw ()
{
	return ("unmatched [");
}

const char		*Interpreter::UnmatchedSqBrackClException::what() const throw ()
{
	return ("unmatched ]");
}

void			Interpreter::_buildSqBrackLookupMap(void)
					throw (UnmatchedSqBrackOpException, UnmatchedSqBrackClException)
{
	std::stack<size_t>		sq_brack_stack;

	for (instructions_t::iterator it = _instructions.begin(); it != _instructions.end(); ++it)
	{
		if ((*it)->type == '[')
			sq_brack_stack.push(it - _instructions.begin());
		else if ((*it)->type == ']')
		{
			if (sq_brack_stack.empty())
				throw (UnmatchedSqBrackClException());
			//	Use iterators' offsets as key-value pairs for quick jumping.
			_sqBrackLookupMap[it - _instructions.begin()] = sq_brack_stack.top();
			_sqBrackLookupMap[sq_brack_stack.top()] = it - _instructions.begin();
			sq_brack_stack.pop();
		}
	}
	if (!sq_brack_stack.empty())
		throw (UnmatchedSqBrackOpException());
}

void			Interpreter::_clear(void)
{
	_instructions.clear();
	_sqBrackLookupMap.clear();
}

				Interpreter::Interpreter(Interpreter const &rSrc) :
				_cells(32768, 0),
				_cellPointer(_cells.begin()),
				_instPointer(_instructions.begin()),
				_instPlus(*this),
				_instMinus(*this),
				_instGreater(*this),
				_instLess(*this),
				_instPeriod(*this),
				_instComma(*this),
				_instSqBrackOp(*this),
				_instSqBrackCl(*this)
{
	static_cast<void>(rSrc);
}

Interpreter		&Interpreter::operator=(Interpreter const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
