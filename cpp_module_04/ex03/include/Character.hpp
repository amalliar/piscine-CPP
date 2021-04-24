/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:23:24 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:38:59 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class						Character : public ICharacter
{
	public:
		std::string const	&getName(void) const;
		AMateria const		*getAMateria(int idx) const;

		void				equip(AMateria *pAmateria);
		void				unequip(int idx);
		void				use(int idx, ICharacter &rTarget);

							Character(std::string const &rName);
							Character(Character const &rSrc);
							~Character(void);
		Character			&operator=(Character const &rRhs);

	protected:
		std::string			_name;
		AMateria			*_slots[4];

		void				_clearSlots(void);
							Character(void);
};

#endif // CHARACTER_HPP
