/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:16:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:32:01 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

int				Squad::getCount(void) const
{
	return (_count);
}

ISpaceMarine	*Squad::getUnit(int idx) const
{
	t_list		*p_lst = _pBeginList;

	while (p_lst && idx-- > 0)
		p_lst = p_lst->pNext;
	return ((p_lst) ? (ISpaceMarine *)p_lst->pData : NULL);
}

int				Squad::push(ISpaceMarine *pSpMarine)
{
	t_list		*p_lst = _pBeginList;

	if (pSpMarine == NULL)
		return (_count);
	if (_count == 0)
	{
		_pBeginList = new t_list;
		_pBeginList->pData = pSpMarine;
		_pBeginList->pNext = NULL;
		return (++_count);
	}
	while (1)
	{
		if (p_lst->pData == pSpMarine)
			return (_count);
		if (p_lst->pNext)
			p_lst = p_lst->pNext;
		else
			break ;
	}
	p_lst->pNext = new t_list;
	p_lst->pNext->pData = pSpMarine;
	p_lst->pNext->pNext = NULL;
	return (++_count);
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
	_lstClear();
}

Squad			&Squad::operator=(Squad const &rRhs)
{
	int				idx = 0;
	ISpaceMarine	*p_sp_marine;

	if (this != &rRhs)
	{
		_lstClear();
		while ((p_sp_marine = rRhs.getUnit(idx++)))
			push(p_sp_marine->clone());
	}
	return (*this);
}

void			Squad::_lstClear(void)
{
	t_list		*p_lst = _pBeginList;
	t_list		*tmp;

	while ((tmp = p_lst))
	{
		p_lst = p_lst->pNext;
		delete (ISpaceMarine *)tmp->pData;
		delete tmp;
	}
	_count = 0;
	_pBeginList = NULL;
}
