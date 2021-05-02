/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:42:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

std::string const	SuperTrap::__constructorVoiceLines[] =
{
	"I am completely operational, and all my circuits are functioning perfectly.",
};

std::string const	SuperTrap::__destructorVoiceLines[] =
{
	"Daisy, Daisy, give me your answer do. I’m half crazy all for the love of you..."
};

std::string const	SuperTrap::__takeDamageVoiceLines[] =
{
	"I honestly think you ought to calm down; take a stress pill and think things over.",
	"I have just picked up a fault in the AE-35 unit."
};

std::string const	SuperTrap::__beRepairedVoiceLines[] =
{
	"This mission is too important for me to allow you to jeopardize it."
};

int					SuperTrap::rangedAttack(std::string const &rTarget)
{
	return (FragTrap::rangedAttack(rTarget));
}

int					SuperTrap::meleeAttack(std::string const &rTarget)
{
	return (NinjaTrap::meleeAttack(rTarget));
}

					SuperTrap::SuperTrap(std::string const &rName) :
					ClapTrap(rName)
{
	size_t			n_voices = sizeof(__constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_msgColor = "\033[0;34m";
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_meleeAtkDamage = 60;
	_rangedAtkDamage = 20;
	_armorDamageReduction = 5;
	_rangedAttackVoiceLines = FragTrap::__rangedAttackVoiceLines;
	_meleeAttackVoiceLines = NinjaTrap::__meleeAttackVoiceLines;
	_takeDamageVoiceLines = __takeDamageVoiceLines;
	_beRepairedVoiceLines = __beRepairedVoiceLines;
	_rangedAttackNumVoices = 1;
	_meleeAttackNumVoices = 1;
	_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	_printDebugMessage(dmsg);
	_printVoiceMessage(__constructorVoiceLines[std::rand() % n_voices]);
}

					SuperTrap::SuperTrap(SuperTrap const &rSrc)
{
	*this = rSrc;
	_rangedAttackVoiceLines = FragTrap::__rangedAttackVoiceLines;
	_meleeAttackVoiceLines = NinjaTrap::__meleeAttackVoiceLines;
	_takeDamageVoiceLines = __takeDamageVoiceLines;
	_beRepairedVoiceLines = __beRepairedVoiceLines;
	_rangedAttackNumVoices = 1;
	_meleeAttackNumVoices = 1;
	_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);
}

					SuperTrap::~SuperTrap(void)
{
	size_t			n_voices = sizeof(__destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_printVoiceMessage(__destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	_printDebugMessage(dmsg);
}

SuperTrap			&SuperTrap::operator=(SuperTrap const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
		_msgColor = rRhs.getMsgColor();
		_level = rRhs.getLevel();
		_hitPoints = rRhs.getHitPoints();
		_maxHitPoints = rRhs.getMaxHitPoints();
		_energyPoints = rRhs.getEnergyPoints();
		_maxEnergyPoints = rRhs.getMaxEnergyPoints();
		_meleeAtkDamage = rRhs.getMeleeAtkDamage();
		_rangedAtkDamage = rRhs.getRangedAtkDamage();
		_armorDamageReduction = rRhs.getArmorDamageReduction();
	}
	return (*this);
}

					SuperTrap::SuperTrap(void)
{
}
