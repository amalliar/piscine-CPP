/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 01:54:59 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string const	ScavTrap::__constructorVoiceLines[] =
{
	"Hey, check me out everybody! I'm dancin', I'm dancin'!",
	"Unce! Unce! Unce! Unce! Ooo, oh check me out. Unce! Unce! Unce! Unce! Oh, come on get down.",
	"I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!",
};

std::string const	ScavTrap::__destructorVoiceLines[] =
{
	"I can see through time...",
	"My servos... are seizing...",
	"I can see... the code"
};

std::string const	ScavTrap::__rangedAttackVoiceLines[] =
{
	"Wow! You're not dead?",
	"I'm over here!",
	"I'm on a roll!",
	"Unts unts unts unts!"
};

std::string const	ScavTrap::__meleeAttackVoiceLines[] =
{
	"Rrrrrgh...this isn't working!",
	"Take that!",
	"Bop!"

};

std::string const	ScavTrap::__takeDamageVoiceLines[] =
{
	"Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!",
	"I'm detecting a motor unit malfunction... I can't move! I'm paralyzed with fear!",
	"Please don't shoot me, please don't shoot me, please don't shoot me!",
	"The traveler will protect me. The traveler will protect me."
};

std::string const	ScavTrap::__beRepairedVoiceLines[] =
{
	"Good as new, I think. Am I leaking?",
	"Yoo hoooooooooo!"
};


std::string const	ScavTrap::__challengeNewcomerVoiceLines[] =
{
	"Read 'The Art of Computer Programming' by Don Knuth. All of it.",
	"Install Gentoo.",
	"Only use packages that are free software.",
	"Learn Haskell.",
	"Tick all the green checkmarks and finish this evaluation right here.",
	"Stop waisting my time."
};

int					ScavTrap::challengeNewcomer(std::string const &rTarget)
{
	size_t				n_voices = sizeof(__challengeNewcomerVoiceLines) / sizeof(std::string);
	std::string			msg;

	if (this->_hitPoints <= 0 || rTarget.empty())
		return (1);
	if (this->_energyPoints < 10)
	{
		_printInfoMessage("Not enough energy points to challengeNewcomer");
		return (1);
	}
	if ((this->_energyPoints -= 10) < 0)
		this->_energyPoints = 0;
	msg = typeid(*this).name();
	msg += " " + this->_name + " challenges " + rTarget + "!";
	this->_printInfoMessage(msg);
	msg = "Greetings " + rTarget + "! I have a new challenge for you:";
	this->_printVoiceMessage(msg);
	this->_printVoiceMessage(__challengeNewcomerVoiceLines[std::rand() % n_voices]);
	return (0);
}

					ScavTrap::ScavTrap(std::string const &rName) :
					ClapTrap(rName)
{
	size_t			n_voices = sizeof(__constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	this->_msgColor = "\033[0;35m";
	this->_meleeAtkDamage = 20;
	this->_rangedAtkDamage = 15;
	this->_armorDamageReduction = 3;
	this->_rangedAttackVoiceLines = __rangedAttackVoiceLines;
	this->_meleeAttackVoiceLines = __meleeAttackVoiceLines;
	this->_takeDamageVoiceLines = __takeDamageVoiceLines;
	this->_beRepairedVoiceLines = __beRepairedVoiceLines;
	this->_rangedAttackNumVoices = sizeof(__rangedAttackVoiceLines) / sizeof(std::string);
	this->_meleeAttackNumVoices = sizeof(__meleeAttackVoiceLines) / sizeof(std::string);
	this->_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	this->_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	this->_printDebugMessage(dmsg);
	this->_printVoiceMessage(__constructorVoiceLines[std::rand() % n_voices]);
}

					ScavTrap::ScavTrap(ScavTrap const &rSrc)
{
	*this = rSrc;
	this->_rangedAttackVoiceLines = __rangedAttackVoiceLines;
	this->_meleeAttackVoiceLines = __meleeAttackVoiceLines;
	this->_takeDamageVoiceLines = __takeDamageVoiceLines;
	this->_beRepairedVoiceLines = __beRepairedVoiceLines;
	this->_rangedAttackNumVoices = sizeof(__rangedAttackVoiceLines) / sizeof(std::string);
	this->_meleeAttackNumVoices = sizeof(__meleeAttackVoiceLines) / sizeof(std::string);
	this->_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	this->_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);
}

					ScavTrap::~ScavTrap(void)
{
	size_t			n_voices = sizeof(__destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	this->_printVoiceMessage(__destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	this->_printDebugMessage(dmsg);
}

ScavTrap			&ScavTrap::operator=(ScavTrap const &rRhs)
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

					ScavTrap::ScavTrap(void)
{
}
