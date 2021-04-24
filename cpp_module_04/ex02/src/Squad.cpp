/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:16:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:33:23 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

int				Squad::getCount(void) const
{
	return (this->_count);
}

ISpaceMarine	*Squad::getUnit(int idx) const
{
	t_list		*p_lst = this->_pBeginList;

	while (p_lst && idx-- > 0)
		p_lst = p_lst->pNext;
	return ((p_lst) ? (ISpaceMarine *)p_lst->pData : NULL);
}

int				Squad::push(ISpaceMarine *pSpMarine)
{
	t_list		*p_lst = this->_pBeginList;

	if (pSpMarine == NULL)
		return (this->_count);
	if (this->_count == 0)
	{
		this->_pBeginList = new t_list;
		this->_pBeginList->pData = pSpMarine;
		this->_pBeginList->pNext = NULL;
		return (++this->_count);
	}
	while (1)
	{
		if (p_lst->pData == pSpMarine)
			return (this->_count);
		if (p_lst->pNext)
			p_lst = p_lst->pNext;
		else
			break ;
	}
	p_lst->pNext = new t_list;
	p_lst->pNext->pData = pSpMarine;
	p_lst->pNext->pNext = NULL;
	return (++this->_count);
}

				Squad::Squad(void) :
				_count(0),
				_pBeginList(NULL)
{
}

				Squad::Squad(Squad const &rSrc) :
				_count(0),
				_pBeginList(NULL)

{
	*this = rSrc;
}

				Squad::~Squad(void)
{
	this->_lstClear();
}

Squad			&Squad::operator=(Squad const &rRhs)
{
	int				idx = 0;
	ISpaceMarine	*p_sp_marine;

	if (this != &rRhs)
	{
		this->_lstClear();
		while ((p_sp_marine = rRhs.getUnit(idx++)))
			this->push(p_sp_marine->clone());
	}
	return (*this);
}

void			Squad::_lstClear(void)
{
	t_list		*p_lst = this->_pBeginList;
	t_list		*tmp;

	while ((tmp = p_lst))
	{
		p_lst = p_lst->pNext;
		delete (ISpaceMarine *)tmp->pData;
		delete tmp;
	}
	this->_count = 0;
	this->_pBeginList = NULL;
}
