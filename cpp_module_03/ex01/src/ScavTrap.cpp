/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 01:38:26 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string const	ScavTrap::_constructorVoiceLines[] =
{
	"Hey, check me out everybody! I'm dancin', I'm dancin'!",
	"Unce! Unce! Unce! Unce! Ooo, oh check me out. Unce! Unce! Unce! Unce! Oh, come on get down.",
	"I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!",
};

std::string const	ScavTrap::_destructorVoiceLines[] =
{
	"I can see through time...",
	"My servos... are seizing...",
	"I can see... the code"
};

std::string const	ScavTrap::_takeDamageVoiceLines[] =
{
	"Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!",
	"I'm detecting a motor unit malfunction... I can't move! I'm paralyzed with fear!",
	"Please don't shoot me, please don't shoot me, please don't shoot me!",
	"The traveler will protect me. The traveler will protect me."
};

std::string const	ScavTrap::_beRepairedVoiceLines[] =
{
	"Good as new, I think. Am I leaking?",
	"Yoo hoooooooooo!"
};

std::string const	ScavTrap::_rangedAttackVoiceLines[] =
{
	"Wow! You're not dead?",
	"I'm over here!",
	"I'm on a roll!",
	"Unts unts unts unts!"
};

std::string const	ScavTrap::_meleeAttackVoiceLines[] =
{
	"Rrrrrgh...this isn't working!",
	"Take that!",
	"Bop!"

};

std::string const	ScavTrap::_challengeNewcomerVoiceLines[] =
{
	"Read 'The Art of Computer Programming' by Don Knuth. All of it.",
	"Install Gentoo.",
	"Only use packages that are free software.",
	"Learn Haskell.",
	"Tick all the green checkmarks and finish this evaluation right here.",
	"Stop waisting my time."
};

std::string const	&ScavTrap::getName(void) const
{
	return (this->_name);
}

std::string const	&ScavTrap::getMsgColor(void) const
{
	return (this->_msgColor);
}

int					ScavTrap::getLevel(void) const
{
	return (this->_level);
}

int					ScavTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int					ScavTrap::getMaxHitPoints(void) const
{
	return (this->_maxHitPoints);
}

int					ScavTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int					ScavTrap::getMaxEnergyPoints(void) const
{
	return (this->_maxEnergyPoints);
}

int					ScavTrap::getMeleeAtkDamage(void) const
{
	return (this->_meleeAtkDamage);
}

int					ScavTrap::getRangedAtkDamage(void) const
{
	return (this->_rangedAtkDamage);
}

int					ScavTrap::getArmorDamageReduction(void) const
{
	return (this->_armorDamageReduction);
}

int					ScavTrap::setName(std::string const &name)
{
	this->_name = name;
	return (0);
}

int					ScavTrap::setMsgColor(std::string const &rMsgColor)
{
	std::string const	colors[] =
	{
		"\033[0;30m",
		"\033[1;30m",
		"\033[0;31m",
		"\033[1;31m",
		"\033[0;32m",
		"\033[1;32m",
		"\033[0;33m",
		"\033[1;33m",
		"\033[0;34m",
		"\033[1;34m",
		"\033[0;35m",
		"\033[1;35m",
		"\033[0;36m",
		"\033[1;36m",
		"\033[0;37m",
		"\033[1;37m"
	};
	size_t				n_colors = sizeof(colors) / sizeof(std::string);

	for (size_t i = 0; i < n_colors; ++i)
		if (!rMsgColor.compare(colors[i]))
		{
			this->_msgColor = rMsgColor;
			return (0);
		}
	return (1);
}

int					ScavTrap::setLevel(int level)
{
	if (level < 0)
		return (1);
	this->_level = level;
	return (0);
}

int					ScavTrap::setHitPoints(int hitPoints)
{
	if (hitPoints < 0 || hitPoints > this->_maxHitPoints)
		return (1);
	this->_hitPoints = hitPoints;
	return (0);
}

int					ScavTrap::setMaxHitPoints(int maxHitPoints)
{
	if (maxHitPoints < 0)
		return (1);
	this->_maxHitPoints = maxHitPoints;
	return (0);
}

int					ScavTrap::setEnergyPoints(int energyPoints)
{
	if (energyPoints < 0 || energyPoints > this->_maxEnergyPoints)
		return (1);
	this->_energyPoints = energyPoints;
	return (0);
}

int					ScavTrap::setMeleeAtkDamage(int meleeAtkDamage)
{
	if (meleeAtkDamage < 0)
		return (1);
	this->_meleeAtkDamage = meleeAtkDamage;
	return (0);
}

int					ScavTrap::setRangedAtkDamage(int rangedAtkDamage)
{
	if (rangedAtkDamage < 0)
		return (1);
	this->_rangedAtkDamage = rangedAtkDamage;
	return (0);
}

int					ScavTrap::setArmorDamageReduction(int armorDamageReduction)
{
	if (armorDamageReduction < 0)
		return (1);
	this->_armorDamageReduction = armorDamageReduction;
	return (0);
}

int					ScavTrap::challengeNewcomer(std::string const &rTarget)
{
	size_t				n_voices = sizeof(ScavTrap::_challengeNewcomerVoiceLines) / sizeof(std::string);
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
	this->_printVoiceMessage(ScavTrap::_challengeNewcomerVoiceLines[std::rand() % n_voices]);
	return (0);
}

int					ScavTrap::rangedAttack(std::string const &rTarget)
{
	size_t			n_voices = sizeof(ScavTrap::_rangedAttackVoiceLines) / sizeof(std::string);
	std::string		msg;

	if (this->_hitPoints <= 0 || rTarget.empty())
		return (1);
	msg = typeid(*this).name();
	msg += " " + this->_name + " attacks " + rTarget + " at range causing " + \
		std::to_string(this->_rangedAtkDamage) + " points of damage!";
	this->_printInfoMessage(msg);
	this->_printVoiceMessage(ScavTrap::_rangedAttackVoiceLines[std::rand() % n_voices]);
	return (0);
}

int					ScavTrap::meleeAttack(std::string const &rTarget)
{
	size_t			n_voices = sizeof(ScavTrap::_meleeAttackVoiceLines) / sizeof(std::string);
	std::string		msg;

	if (this->_hitPoints <= 0 || rTarget.empty())
		return (1);
	msg = typeid(*this).name();
	msg += " " + this->_name + " punches " + rTarget + " causing " + \
		std::to_string(this->_meleeAtkDamage) + " points of damage!";
	this->_printInfoMessage(msg);
	this->_printVoiceMessage(ScavTrap::_meleeAttackVoiceLines[std::rand() % n_voices]);
	return (0);
}

int					ScavTrap::takeDamage(unsigned int amount)
{
	size_t			n_voices = sizeof(ScavTrap::_takeDamageVoiceLines) / sizeof(std::string);
	std::string		msg;

	if (this->_hitPoints <= 0 || amount <= 0)
		return (1);
	amount -= this->_armorDamageReduction;
	msg = typeid(*this).name();
	msg += " " + this->_name + " is hit for " + std::to_string(amount) + " points of damage!";
	this->_printInfoMessage(msg);
	if ((this->_hitPoints -= amount) <= 0)
	{
		this->_hitPoints = 0;
		msg = typeid(*this).name();
		msg += " " + this->_name + " has been knocked out.";
		this->_printInfoMessage(msg);
		return (0);
	}
	this->_printVoiceMessage(ScavTrap::_takeDamageVoiceLines[std::rand() % n_voices]);
	return (0);
}

int					ScavTrap::beRepaired(unsigned int amount)
{
	size_t			n_voices = sizeof(ScavTrap::_beRepairedVoiceLines) / sizeof(std::string);
	std::string		msg;

	if (this->_hitPoints <= 0 || amount <= 0)
		return (1);
	if ((this->_hitPoints += amount) > this->_maxHitPoints)
	{
		amount -= this->_hitPoints - this->_maxHitPoints;
		this->_hitPoints = this->_maxHitPoints;
	}
	msg = typeid(*this).name();
	msg += " " + this->_name + " has been repaired for " + std::to_string(amount) + " hit points.";
	this->_printInfoMessage(msg);
	this->_printVoiceMessage(ScavTrap::_beRepairedVoiceLines[std::rand() % n_voices]);
	return (0);
}

					ScavTrap::ScavTrap(std::string const &rName) :
					_name(rName),
					_msgColor("\033[0;35m"),
					_level(1),
					_hitPoints(100),
					_maxHitPoints(100),
					_energyPoints(50),
					_maxEnergyPoints(50),
					_meleeAtkDamage(20),
					_rangedAtkDamage(15),
					_armorDamageReduction(3)
{
	size_t			n_voices = sizeof(ScavTrap::_constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	this->_printDebugMessage(dmsg);
	this->_printVoiceMessage(ScavTrap::_constructorVoiceLines[std::rand() % n_voices]);
}

					ScavTrap::ScavTrap(ScavTrap const &rSrc)
{
	*this = rSrc;
}

					ScavTrap::~ScavTrap(void)
{
	size_t			n_voices = sizeof(ScavTrap::_destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	this->_printVoiceMessage(ScavTrap::_destructorVoiceLines[std::rand() % n_voices]);
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

void				ScavTrap::_printVoiceMessage(std::string const &rMsg) const
{
	std::string const	noc = "\033[0m";

	std::cout << this->_msgColor << this->_name << ": " << rMsg << noc << std::endl;
}

void				ScavTrap::_printInfoMessage(std::string const &rMsg) const
{
	#ifndef __INFO_PRINT__
		return ;
	#endif

	std::cerr << "[info]: " << rMsg << std::endl;
}

void				ScavTrap::_printDebugMessage(std::string const &rMsg) const
{
	#ifndef __DEBUG_PRINT__
		return ;
	#endif

	time_t		rawtime;
	struct tm 	*timeinfo;
  	char 		buffer[32];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 32, "[%Y%m%d_%H%M%S] ",timeinfo);
	std::cerr << buffer << rMsg << std::endl;
}

					ScavTrap::ScavTrap(void)
{
}

std::ostream		&operator<<(std::ostream &rOs, ScavTrap const &rRhs)
{
	std::string const	noc = "\033[0m";

	rOs << "{" << std::endl;
	rOs << "  _name: " << rRhs.getName() << std::endl;
	rOs << "  _msgColor: " << rRhs.getMsgColor() << "color" << noc << std::endl;
	rOs << "  _level: " << rRhs.getLevel() << std::endl;
	rOs << "  _hitPoints: " << rRhs.getHitPoints() << std::endl;
	rOs << "  _maxHitPoints: " << rRhs.getMaxHitPoints() << std::endl;
	rOs << "  _energyPoints: " << rRhs.getEnergyPoints() << std::endl;
	rOs << "  _maxEnergyPoints: " << rRhs.getMaxEnergyPoints() << std::endl;
	rOs << "  _meleeAtkDamage: " << rRhs.getMeleeAtkDamage() << std::endl;
	rOs << "  _rangedAtkDamage: " << rRhs.getRangedAtkDamage() << std::endl;
	rOs << "  _armorDamageReduction: " << rRhs.getArmorDamageReduction() << std::endl;
	rOs << "}" << std::endl;
	return (rOs);
}
