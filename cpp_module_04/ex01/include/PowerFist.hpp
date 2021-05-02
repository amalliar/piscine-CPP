/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:48:42 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:27:40 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "colors.hpp"

class						PowerFist : public AWeapon
{
	public:

		virtual void		attack(void) const;

							PowerFist(void);
							PowerFist(PowerFist const &rSrc);
		virtual				~PowerFist(void);

		PowerFist			&operator=(PowerFist const &rRhs);
};

#endif // POWER_FIST_HPP
