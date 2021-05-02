/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:20:39 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:23:34 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_WEAPON_HPP
# define A_WEAPON_HPP

# include <string>

class						AWeapon
{
	public:

		std::string const	&getName(void) const;
		int					getAPCost(void) const;
		int					getDamage(void) const;

		virtual void		attack(void) const = 0;

							AWeapon(std::string const &rName, int apcost, int damage);
							AWeapon(AWeapon const &rSrc);
		virtual				~AWeapon(void);

		AWeapon				&operator=(AWeapon const &rRhs);

	protected:

		std::string			_name;
		int					_apcost;
		int					_damage;

							AWeapon(void);
};

#endif // A_WEAPON_HPP
