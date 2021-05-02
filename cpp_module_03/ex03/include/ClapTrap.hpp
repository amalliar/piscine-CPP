/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:16:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:26:54 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# define __DEBUG_PRINT__
# define __INFO_PRINT__

# include <cstdlib>
# include <ctime>
# include <iostream>
# include <string>
# include <typeinfo>

class								ClapTrap
{
	public:

		std::string const			&getName(void) const;
		std::string const			&getMsgColor(void) const;
		int							getLevel(void) const;
		int							getHitPoints(void) const;
		int							getMaxHitPoints(void) const;
		int							getEnergyPoints(void) const;
		int							getMaxEnergyPoints(void) const;
		int							getMeleeAtkDamage(void) const;
		int							getRangedAtkDamage(void) const;
		int							getArmorDamageReduction(void) const;

		int							setName(std::string const &rName);
		int							setMsgColor(std::string const &rMsgColor);
		int							setLevel(int level);
		int							setHitPoints(int hitPoints);
		int							setMaxHitPoints(int maxHitPoints);
		int							setEnergyPoints(int energyPoints);
		int							setMaxEnergyPoints(int maxEnergyPoints);
		int							setMeleeAtkDamage(int meleeAtkDamage);
		int							setRangedAtkDamage(int rangedAtkDamage);
		int							setArmorDamageReduction(int armorDamageReduction);

		int							rangedAttack(std::string const &rTarget);
		int							meleeAttack(std::string const &rTarget);
		int							takeDamage(unsigned int amount);
		int							beRepaired(unsigned int amount);

									ClapTrap(std::string const &rName);
									ClapTrap(ClapTrap const &rSrc);
									~ClapTrap(void);

		ClapTrap					&operator=(ClapTrap const &rRhs);

	protected:

		std::string					_name;
		std::string 				_msgColor;
		int							_level;
		int							_hitPoints;
		int							_maxHitPoints;
		int							_energyPoints;
		int							_maxEnergyPoints;
		int							_meleeAtkDamage;
		int							_rangedAtkDamage;
		int							_armorDamageReduction;

		std::string const			*_rangedAttackVoiceLines;
		std::string const			*_meleeAttackVoiceLines;
		std::string const			*_takeDamageVoiceLines;
		std::string const			*_beRepairedVoiceLines;
		size_t						_rangedAttackNumVoices;
		size_t						_meleeAttackNumVoices;
		size_t						_takeDamageNumVoices;
		size_t						_beRepairedNumVoices;

		void						_printVoiceMessage(std::string const &rMsg) const;
		void						_printInfoMessage(std::string const &rMsg) const;
		void						_printDebugMessage(std::string const &rMsg) const;

									ClapTrap(void);

	private:
		static std::string const	__constructorVoiceLines[];
		static std::string const	__destructorVoiceLines[];
		static std::string const	__rangedAttackVoiceLines[];
		static std::string const	__meleeAttackVoiceLines[];
		static std::string const	__takeDamageVoiceLines[];
		static std::string const	__beRepairedVoiceLines[];
};

std::ostream						&operator<<(std::ostream &rOs, ClapTrap const &rRhs);

#endif // CLAP_TRAP_HPP
