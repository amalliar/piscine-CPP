/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:16:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:28:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# define __DEBUG_PRINT__
# define __INFO_PRINT__

# include <iostream>
# include <string>
# include <typeinfo>
# include "ClapTrap.hpp"

class								FragTrap : public ClapTrap
{
	public:

		int							vaulthunter_dot_exe(std::string const &rTarget);

									FragTrap(std::string const &rName);
									FragTrap(FragTrap const &rSrc);
									~FragTrap(void);

		FragTrap					&operator=(FragTrap const &rRhs);

	protected:

									FragTrap(void);

	private:

		static std::string const	__constructorVoiceLines[];
		static std::string const	__destructorVoiceLines[];
		static std::string const	__rangedAttackVoiceLines[];
		static std::string const	__meleeAttackVoiceLines[];
		static std::string const	__takeDamageVoiceLines[];
		static std::string const	__beRepairedVoiceLines[];
		static std::string const	__vaulthunterVoiceLines[];
};

#endif // FRAG_TRAP_HPP
