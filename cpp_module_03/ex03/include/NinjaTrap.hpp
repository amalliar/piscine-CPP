/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:16:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:39:10 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP
# define __DEBUG_PRINT__
# define __INFO_PRINT__

# include <iostream>
# include <string>
# include <typeinfo>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class								NinjaTrap : public ClapTrap
{
	public:

		int							ninjaShoebox(ClapTrap &rTarget);
		int							ninjaShoebox(FragTrap &rTarget);
		int							ninjaShoebox(ScavTrap &rTarget);
		int							ninjaShoebox(NinjaTrap &rTarget);

									NinjaTrap(std::string const &rName);
									NinjaTrap(NinjaTrap const &rSrc);
									~NinjaTrap(void);

		NinjaTrap					&operator=(NinjaTrap const &rRhs);

	protected:

									NinjaTrap(void);

	private:

		static std::string const	__constructorVoiceLines[];
		static std::string const	__destructorVoiceLines[];
		static std::string const	__rangedAttackVoiceLines[];
		static std::string const	__meleeAttackVoiceLines[];
		static std::string const	__takeDamageVoiceLines[];
		static std::string const	__beRepairedVoiceLines[];
		static std::string const	__ninjaShoeboxVoiceLines[];
};

#endif // NINJA_TRAP_HPP
