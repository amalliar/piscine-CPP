/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:16:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:42:09 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP
# define __DEBUG_PRINT__
# define __INFO_PRINT__

# include <iostream>
# include <string>
# include <typeinfo>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class								SuperTrap : public FragTrap, public NinjaTrap
{
	public:

		int							rangedAttack(std::string const &rTarget);
		int							meleeAttack(std::string const &rTarget);

									SuperTrap(std::string const &rName);
									SuperTrap(SuperTrap const &rSrc);
									~SuperTrap(void);

		SuperTrap					&operator=(SuperTrap const &rRhs);

	protected:

									SuperTrap(void);

	private:

		static std::string const	__constructorVoiceLines[];
		static std::string const	__destructorVoiceLines[];
		static std::string const	__rangedAttackVoiceLines[];
		static std::string const	__meleeAttackVoiceLines[];
		static std::string const	__takeDamageVoiceLines[];
		static std::string const	__beRepairedVoiceLines[];
};

#endif // SUPER_TRAP_HPP
