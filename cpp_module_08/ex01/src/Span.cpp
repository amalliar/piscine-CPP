/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:38:16 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 13:43:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

typedef std::vector<int>::iterator	Iter;

void		Span::addNumber(int nbr)
				throw (std::length_error)
{
	if (size() >= _N)
		throw (std::length_error("Span::_M_fill_insert"));
	push_back(nbr);
}

int			Span::shortestSpan(void)
				throw (std::length_error)
{
	Span	tmp(*this);
	int		min_delta = std::numeric_limits<int>::max();

	if (size() < 2)
		throw (std::length_error("Span::_M_empty_span"));
	std::sort(tmp.begin(), tmp.end());
	for (Iter it = tmp.begin() + 1; it != tmp.end(); ++it)
		if (it[0] - it[-1] < min_delta)
			min_delta = it[0] - it[-1];
	return (min_delta);
}

int			Span::longestSpan(void)
				throw (std::length_error)
{
	std::pair<Iter, Iter>	p;

	if (size() < 2)
		throw (std::length_error("Span::_M_empty_span"));
	p = std::minmax_element(begin(), end());
	return (*p.second - *p.first);
}

			Span::Span(size_t N) :
			_N(N)
{
}

			Span::Span(Span const &rSrc) :
			_N(rSrc._N)
{
	*this = rSrc;
}

			Span::~Span(void)
{
}

Span		&Span::operator=(Span const &rRhs)
				throw (std::length_error)
{
	if (this != &rRhs)
	{
		if (rRhs.size() > _N)
			throw (std::length_error("Span::_M_fill_insert"));
		assign(rRhs.begin(), rRhs.end());
	}
	return (*this);
}

			Span::Span(void) :
			_N(0)
{
}
