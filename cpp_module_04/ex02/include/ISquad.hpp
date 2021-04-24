/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:11:28 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:26:58 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SQUAD_HPP
# define I_SQUAD_HPP

# include "ISpaceMarine.hpp"

class							ISquad
{
	public:
		virtual					~ISquad() {}
		virtual int				getCount() const = 0;
		virtual ISpaceMarine	*getUnit(int) const = 0;
		virtual int				push(ISpaceMarine *) = 0;
};

#endif // I_SQUAD_HPP
