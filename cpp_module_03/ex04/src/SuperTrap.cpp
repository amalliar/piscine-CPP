/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 02:12:50 by amalliar         ###   ########.fr       */
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

	this->_msgColor = "\033[0;34m";
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_meleeAtkDamage = 60;
	this->_rangedAtkDamage = 20;
	this->_armorDamageReduction = 5;
	this->_rangedAttackVoiceLines = FragTrap::__rangedAttackVoiceLines;
	this->_meleeAttackVoiceLines = NinjaTrap::__meleeAttackVoiceLines;
	this->_takeDamageVoiceLines = __takeDamageVoiceLines;
	this->_beRepairedVoiceLines = __beRepairedVoiceLines;
	this->_rangedAttackNumVoices = 1;
	this->_meleeAttackNumVoices = 1;
	this->_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	this->_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	this->_printDebugMessage(dmsg);
	this->_printVoiceMessage(__constructorVoiceLines[std::rand() % n_voices]);
}

					SuperTrap::SuperTrap(SuperTrap const &rSrc)
{
	*this = rSrc;
	this->_rangedAttackVoiceLines = FragTrap::__rangedAttackVoiceLines;
	this->_meleeAttackVoiceLines = NinjaTrap::__meleeAttackVoiceLines;
	this->_takeDamageVoiceLines = __takeDamageVoiceLines;
	this->_beRepairedVoiceLines = __beRepairedVoiceLines;
	this->_rangedAttackNumVoices = 1;
	this->_meleeAttackNumVoices = 1;
	this->_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	this->_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);
}

					SuperTrap::~SuperTrap(void)
{
	size_t			n_voices = sizeof(__destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	this->_printVoiceMessage(__destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	this->_printDebugMessage(dmsg);
}

SuperTrap			&SuperTrap::operator=(SuperTrap const &rRhs)
{
	this->_name = rRhs.getName();
	this->_msgColor = rRhs.getMsgColor();
	this->_level = rRhs.getLevel();
	this->_hitPoints = rRhs.getHitPoints();
	this->_maxHitPoints = rRhs.getMaxHitPoints();
	this->_energyPoints = rRhs.getEnergyPoints();
	this->_maxEnergyPoints = rRhs.getMaxEnergyPoints();
	this->_meleeAtkDamage = rRhs.getMeleeAtkDamage();
	this->_rangedAtkDamage = rRhs.getRangedAtkDamage();
	this->_armorDamageReduction = rRhs.getArmorDamageReduction();
	return (*this);
}

					SuperTrap::SuperTrap(void)
{
}
