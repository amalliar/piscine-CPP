/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:25:27 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/29 02:13:47 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// Type T shall be copy-constructible and assignable.
template <typename T>
void		swap(T &rLhs, T &rRhs)
{
	T tmp(rLhs);
	rLhs = rRhs;
	rRhs = tmp;
}

template <typename T>
T const		&min(T const &rLhs, T const &rRhs)
{
	return ((rLhs < rRhs) ? rLhs : rRhs);
}

template <typename T>
T const		&max(T const &rLhs, T const &rRhs)
{
	return ((rLhs > rRhs) ? rLhs : rRhs);
}

#endif // WHATEVER_HPP
