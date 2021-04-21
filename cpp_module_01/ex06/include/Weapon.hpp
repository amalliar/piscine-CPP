/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:56:13 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 01:15:20 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class						Weapon
{
	public:
		std::string const	&getType(void) const;
		void				setType(std::string const &rType);

							Weapon(std::string const &rType);
							Weapon(Weapon const &rSrc);
							~Weapon(void);
		Weapon				&operator=(Weapon const &rRhs);

	private:
		std::string			_type;

							Weapon(void);
};

#endif // WEAPON_HPP
