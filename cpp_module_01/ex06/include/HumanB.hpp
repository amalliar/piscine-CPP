/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:18:41 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 01:11:16 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include <string>
# include <cstddef>
# include "Weapon.hpp"

class					HumanB
{
	public:
		void			attack(void) const;
		void			setWeapon(Weapon &rWeapon);

						HumanB(std::string const &rName);
						HumanB(HumanB const &rSrc);
						~HumanB(void);
		HumanB			&operator=(HumanB const &rRhs);

	private:
		std::string		_name;
		Weapon			*_pWeapon;

						HumanB(void);
};

#endif // HUMAN_B_HPP
