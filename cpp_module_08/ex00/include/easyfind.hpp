/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:27:35 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/28 07:49:33 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(T const &rContainer, int const val)
{
	return (std::find(rContainer.begin(), rContainer.end(), val));
}

#endif // EASYFIND_HPP
