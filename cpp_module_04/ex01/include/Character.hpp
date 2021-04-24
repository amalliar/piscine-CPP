/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:50:06 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:13:25 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class						Character
{
	public:
		std::string const	&getName(void) const;
		int					getAP(void) const;
		AWeapon				*getWeapon(void) const;

		void				equip(AWeapon *pWeapon);
		virtual void		attack(Enemy *pEnemy);
		virtual void		recoverAP(void);

							Character(std::string const &rName);
							Character(Character const &rSrc);
		virtual				~Character(void);
		Character			&operator=(Character const &rSrc);

	protected:
		std::string			_name;
		int					_ap;
		AWeapon				*_pWeapon;

							Character(void);
};

std::ostream				&operator<<(std::ostream &rOs, Character const &rRhs);

#endif // CHARACTER_HPP
