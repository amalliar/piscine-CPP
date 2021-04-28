/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:57:43 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/28 06:32:39 by amalliar         ###   ########.fr       */
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
			this->_officeBlocks[i].setSigner(rBureaucrat);
			return ;
		}
		catch (OfficeBlock::SameObjectRefException)
		{
			throw (SameObjectRefException());
		}
		catch (OfficeBlock::ObjectIsAlreadySetException) {}

		try
		{
			this->_officeBlocks[i].setExecutor(rBureaucrat);
			this->_officeBlocks[i].setIntern(this->_generateIntern());
			this->_numFilledOfficeBlocks += 1;
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
	this->_targetQueue.push(rTarget);
}

void				CentralBureaucracy::doBureaucracy(void)
						throw (NoFilledOfficeBlocksException)
{
	size_t		ob_idx = 0;

	if (this->_numFilledOfficeBlocks == 0)
		throw (NoFilledOfficeBlocksException());
	while (this->_targetQueue.size() != 0)
	{
		try
		{
			this->_officeBlocks[ob_idx].doBureaucracy(Intern::actionMap[std::rand() % Intern::numKnownForms].name, \
				this->_targetQueue.front());
			this->_targetQueue.pop();
		}
		catch (...) {}
		ob_idx = (ob_idx + 1) % this->_numFilledOfficeBlocks;
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
	this->_internList.push_back(Intern());
	return (this->_internList.back());
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
