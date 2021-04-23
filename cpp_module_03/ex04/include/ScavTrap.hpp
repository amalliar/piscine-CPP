/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:16:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 01:54:04 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# define __DEBUG_PRINT__
# define __INFO_PRINT__

# include <iostream>
# include <string>
# include <typeinfo>
# include "ClapTrap.hpp"

class								ScavTrap : public ClapTrap
{
	public:
		int							challengeNewcomer(std::string const &rTarget);

									ScavTrap(std::string const &rName);
									ScavTrap(ScavTrap const &rSrc);
									~ScavTrap(void);
		ScavTrap					&operator=(ScavTrap const &rRhs);

	protected:
									ScavTrap(void);

	private:
		static std::string const	__constructorVoiceLines[];
		static std::string const	__destructorVoiceLines[];
		static std::string const	__rangedAttackVoiceLines[];
		static std::string const	__meleeAttackVoiceLines[];
		static std::string const	__takeDamageVoiceLines[];
		static std::string const	__beRepairedVoiceLines[];
		static std::string const	__challengeNewcomerVoiceLines[];
};

#endif // SCAV_TRAP_HPP
