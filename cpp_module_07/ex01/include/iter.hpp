/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:52:58 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 13:36:42 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename U = void>
void	iter(T *pT, size_t const length, U (*func)(T const &arg))
{
	for (size_t i = 0; i < length; ++i)
		func(pT[i]);
}

template <typename T, typename U = void>
void	iter(T *pT, size_t const length, U (*func)(T &arg))
{
	for (size_t i = 0; i < length; ++i)
		func(pT[i]);
}

#endif // ITER_HPP
