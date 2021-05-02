/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:16:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:12:45 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

# include <string>

class								AMateria;

class								ICharacter
{
	public:

		virtual						~ICharacter() {}
		virtual std::string const	&getName() const = 0;
		virtual void				equip(AMateria *pAmateria) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &rTarget) = 0;
};

#endif // I_CHARACTER_HPP
