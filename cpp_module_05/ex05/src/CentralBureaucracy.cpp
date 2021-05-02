/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:57:43 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 10:02:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

void				CentralBureaucracy::feedBureaucrat(Bureaucrat const &rBureaucrat)
						throw (SameObjectRefException, BureaucracyIsFullException)
{
	for (size_t i = 0; i < _numOfficeBlocks; ++i)
	{
		try
		{
			_officeBlocks[i].setSigner(rBureaucrat);
			return ;
		}
		catch (OfficeBlock::SameObjectRefException)
		{
			throw (SameObjectRefException());
		}
		catch (OfficeBlock::ObjectIsAlreadySetException) {}

		try
		{
			_officeBlocks[i].setExecutor(rBureaucrat);
			_officeBlocks[i].setIntern(_generateIntern());
			_numFilledOfficeBlocks += 1;
			return ;
		}
		catch (OfficeBlock::SameObjectRefException)
		{
			throw (SameObjectRefException());
		}
		catch (OfficeBlock::ObjectIsAlreadySetException) {}
	}
	throw (BureaucracyIsFullException());
}

void				CentralBureaucracy::queueUp(std::string const &rTarget)
{
	_targetQueue.push(rTarget);
}

void				CentralBureaucracy::doBureaucracy(void)
						throw (NoFilledOfficeBlocksException)
{
	size_t		ob_idx = 0;

	if (_numFilledOfficeBlocks == 0)
		throw (NoFilledOfficeBlocksException());
	while (_targetQueue.size() != 0)
	{
		try
		{
			_officeBlocks[ob_idx].doBureaucracy(Intern::actionMap[std::rand() % Intern::numKnownForms].name, \
				_targetQueue.front());
			_targetQueue.pop();
		}
		catch (...) {}
		ob_idx = (ob_idx + 1) % _numFilledOfficeBlocks;
	}
}

					CentralBureaucracy::CentralBureaucracy(void) :
					_numFilledOfficeBlocks(0)
{
}

					CentralBureaucracy::~CentralBureaucracy(void)
{
}

const char			*CentralBureaucracy::SameObjectRefException::what() const throw ()
{
	return ("CentralBureaucracy::SameObjectRefException");
}

const char			*CentralBureaucracy::BureaucracyIsFullException::what() const throw ()
{
	return ("CentralBureaucracy::BureaucracyIsFullException");
}

const char			*CentralBureaucracy::NoFilledOfficeBlocksException::what() const throw ()
{
	return ("CentralBureaucracy::NoFilledOfficeBlocksException");
}

Intern const		&CentralBureaucracy::_generateIntern(void)
{
	_internList.push_back(Intern());
	return (_internList.back());
}

					CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &rSrc)
{
	static_cast<void>(rSrc);
}

CentralBureaucracy	&CentralBureaucracy::operator=(CentralBureaucracy const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}
