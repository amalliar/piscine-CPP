/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlienBlaster.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:48:42 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:11:32 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIEN_BLASTER_HPP
# define ALIEN_BLASTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "colors.hpp"

class						AlienBlaster : public AWeapon
{
	public:
		virtual void		attack(void) const;

							AlienBlaster(void);
							AlienBlaster(AlienBlaster const &rSrc);
		virtual				~AlienBlaster(void);
		AlienBlaster		&operator=(AlienBlaster const &rRhs);
};

#endif // ALIEN_BLASTER_HPP
