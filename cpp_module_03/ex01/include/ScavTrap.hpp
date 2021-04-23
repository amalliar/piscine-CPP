/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:16:32 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 01:42:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# define __DEBUG_PRINT__
# define __INFO_PRINT__

# include <cstdlib>
# include <ctime>
# include <iostream>
# include <string>
# include <typeinfo>

class								ScavTrap
{
	public:
		std::string const			&getName(void) const;
		std::string	const			&getMsgColor(void) const;
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

		int							challengeNewcomer(std::string const &rTarget);
		int							rangedAttack(std::string const &rTarget);
		int							meleeAttack(std::string const &rTarget);
		int							takeDamage(unsigned int amount);
		int							beRepaired(unsigned int amount);

									ScavTrap(std::string const &rName);
									ScavTrap(ScavTrap const &rSrc);
									~ScavTrap(void);
		ScavTrap					&operator=(ScavTrap const &rRhs);

	private:
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

		static std::string const	_constructorVoiceLines[];
		static std::string const	_destructorVoiceLines[];
		static std::string const	_takeDamageVoiceLines[];
		static std::string const	_beRepairedVoiceLines[];
		static std::string const	_rangedAttackVoiceLines[];
		static std::string const	_meleeAttackVoiceLines[];
		static std::string const	_challengeNewcomerVoiceLines[];

		void						_printVoiceMessage(std::string const &rMsg) const;
		void						_printInfoMessage(std::string const &rMsg) const;
		void						_printDebugMessage(std::string const &rMsg) const;

									ScavTrap(void);
};

std::ostream						&operator<<(std::ostream &rOs, ScavTrap const &rRhs);

#endif // SCAV_TRAP_HPP
