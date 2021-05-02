/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:02:30 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:05:20 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class					HumanA
{
	public:

		void			attack(void) const;

						HumanA(std::string const &rName, Weapon &rWeapon);
						HumanA(HumanA const &rSrc);
						~HumanA(void);

		HumanA			&operator=(HumanA const &rRhs);

	private:

		std::string		_name;
		Weapon			&_rWeapon;

						HumanA(void);
};

#endif // HUMAN_A_HPP
