/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:29:44 by amalliar         ###   ########.fr       */
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

	if (_hitPoints <= 0 || rTarget.empty())
		return (1);
	if (_energyPoints < 10)
	{
		_printInfoMessage("Not enough energy points to challengeNewcomer");
		return (1);
	}
	if ((_energyPoints -= 10) < 0)
		_energyPoints = 0;
	msg = typeid(*this).name();
	msg += " " + _name + " challenges " + rTarget + "!";
	_printInfoMessage(msg);
	msg = "Greetings " + rTarget + "! I have a new challenge for you:";
	_printVoiceMessage(msg);
	_printVoiceMessage(__challengeNewcomerVoiceLines[std::rand() % n_voices]);
	return (0);
}

					ScavTrap::ScavTrap(std::string const &rName) :
					ClapTrap(rName)
{
	size_t			n_voices = sizeof(__constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_msgColor = "\033[0;35m";
	_meleeAtkDamage = 20;
	_rangedAtkDamage = 15;
	_armorDamageReduction = 3;
	_rangedAttackVoiceLines = __rangedAttackVoiceLines;
	_meleeAttackVoiceLines = __meleeAttackVoiceLines;
	_takeDamageVoiceLines = __takeDamageVoiceLines;
	_beRepairedVoiceLines = __beRepairedVoiceLines;
	_rangedAttackNumVoices = sizeof(__rangedAttackVoiceLines) / sizeof(std::string);
	_meleeAttackNumVoices = sizeof(__meleeAttackVoiceLines) / sizeof(std::string);
	_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	_printDebugMessage(dmsg);
	_printVoiceMessage(__constructorVoiceLines[std::rand() % n_voices]);
}

					ScavTrap::ScavTrap(ScavTrap const &rSrc)
{
	*this = rSrc;
	_rangedAttackVoiceLines = __rangedAttackVoiceLines;
	_meleeAttackVoiceLines = __meleeAttackVoiceLines;
	_takeDamageVoiceLines = __takeDamageVoiceLines;
	_beRepairedVoiceLines = __beRepairedVoiceLines;
	_rangedAttackNumVoices = sizeof(__rangedAttackVoiceLines) / sizeof(std::string);
	_meleeAttackNumVoices = sizeof(__meleeAttackVoiceLines) / sizeof(std::string);
	_takeDamageNumVoices = sizeof(__takeDamageVoiceLines) / sizeof(std::string);
	_beRepairedNumVoices = sizeof(__beRepairedVoiceLines) / sizeof(std::string);
}

					ScavTrap::~ScavTrap(void)
{
	size_t			n_voices = sizeof(__destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_printVoiceMessage(__destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	_printDebugMessage(dmsg);
}

ScavTrap			&ScavTrap::operator=(ScavTrap const &rRhs)
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

					ScavTrap::ScavTrap(void)
{
}
