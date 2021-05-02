/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:27:28 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

std::string const	ClapTrap::__constructorVoiceLines[] =
{
	"Greetings Traveller!"
};

std::string const	ClapTrap::__destructorVoiceLines[] =
{
	"Sure is lonely around here."
};

std::string const	ClapTrap::__rangedAttackVoiceLines[] =
{
	"This is why I was built!"
};

std::string const	ClapTrap::__meleeAttackVoiceLines[] =
{
	"Bop!"
};

std::string const	ClapTrap::__takeDamageVoiceLines[] =
{
	"Ow hohoho, that hurts! Yipes!"
};

std::string const	ClapTrap::__beRepairedVoiceLines[] =
{
	"Healsies!"
};

std::string const	&ClapTrap::getName(void) const
{
	return (_name);
}

std::string const	&ClapTrap::getMsgColor(void) const
{
	return (_msgColor);
}

int					ClapTrap::getLevel(void) const
{
	return (_level);
}

int					ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int					ClapTrap::getMaxHitPoints(void) const
{
	return (_maxHitPoints);
}

int					ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int					ClapTrap::getMaxEnergyPoints(void) const
{
	return (_maxEnergyPoints);
}

int					ClapTrap::getMeleeAtkDamage(void) const
{
	return (_meleeAtkDamage);
}

int					ClapTrap::getRangedAtkDamage(void) const
{
	return (_rangedAtkDamage);
}

int					ClapTrap::getArmorDamageReduction(void) const
{
	return (_armorDamageReduction);
}

int					ClapTrap::setName(std::string const &rName)
{
	_name = rName;
	return (0);
}

int					ClapTrap::setMsgColor(std::string const &rMsgColor)
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
		"\033[1;37m",
		"\033[0m"
	};
	size_t				n_colors = sizeof(colors) / sizeof(std::string);

	for (size_t i = 0; i < n_colors; ++i)
		if (!rMsgColor.compare(colors[i]))
		{
			_msgColor = rMsgColor;
			return (0);
		}
	return (1);
}

int					ClapTrap::setLevel(int level)
{
	if (level < 0)
		return (1);
	_level = level;
	return (0);
}

int					ClapTrap::setHitPoints(int hitPoints)
{
	if (hitPoints < 0 || hitPoints > _maxHitPoints)
		return (1);
	_hitPoints = hitPoints;
	return (0);
}

int					ClapTrap::setMaxHitPoints(int maxHitPoints)
{
	if (maxHitPoints < 0)
		return (1);
	_maxHitPoints = maxHitPoints;
	return (0);
}

int					ClapTrap::setEnergyPoints(int energyPoints)
{
	if (energyPoints < 0 || energyPoints > _maxEnergyPoints)
		return (1);
	_energyPoints = energyPoints;
	return (0);
}

int					ClapTrap::setMeleeAtkDamage(int meleeAtkDamage)
{
	if (meleeAtkDamage < 0)
		return (1);
	_meleeAtkDamage = meleeAtkDamage;
	return (0);
}

int					ClapTrap::setRangedAtkDamage(int rangedAtkDamage)
{
	if (rangedAtkDamage < 0)
		return (1);
	_rangedAtkDamage = rangedAtkDamage;
	return (0);
}

int					ClapTrap::setArmorDamageReduction(int armorDamageReduction)
{
	if (armorDamageReduction < 0)
		return (1);
	_armorDamageReduction = armorDamageReduction;
	return (0);
}

int					ClapTrap::rangedAttack(std::string const &rTarget)
{
	std::string		msg;

	if (_hitPoints <= 0 || rTarget.empty())
		return (1);
	msg = typeid(*this).name();
	msg += " " + _name + " attacks " + rTarget + " at range causing " + \
		std::to_string(_rangedAtkDamage) + " points of damage!";
	_printInfoMessage(msg);
	_printVoiceMessage(_rangedAttackVoiceLines[std::rand() % \
		_rangedAttackNumVoices]);
	return (0);
}

int					ClapTrap::meleeAttack(std::string const &rTarget)
{
	std::string		msg;

	if (_hitPoints <= 0 || rTarget.empty())
		return (1);
	msg = typeid(*this).name();
	msg += " " + _name + " punches " + rTarget + " causing " + \
		std::to_string(_meleeAtkDamage) + " points of damage!";
	_printInfoMessage(msg);
	_printVoiceMessage(_meleeAttackVoiceLines[std::rand() % \
		_meleeAttackNumVoices]);
	return (0);
}

int					ClapTrap::takeDamage(unsigned int amount)
{
	std::string		msg;

	if (_hitPoints <= 0 || amount <= 0)
		return (1);
	amount -= _armorDamageReduction;
	msg = typeid(*this).name();
	msg += " " + _name + " is hit for " + std::to_string(amount) + " points of damage!";
	_printInfoMessage(msg);
	if ((_hitPoints -= amount) <= 0)
	{
		_hitPoints = 0;
		msg = typeid(*this).name();
		msg += " " + _name + " has been knocked out.";
		_printInfoMessage(msg);
		return (0);
	}
	_printVoiceMessage(_takeDamageVoiceLines[std::rand() % \
		_takeDamageNumVoices]);
	return (0);
}

int					ClapTrap::beRepaired(unsigned int amount)
{
	std::string		msg;

	if (_hitPoints <= 0 || amount <= 0)
		return (1);
	if ((_hitPoints += amount) > _maxHitPoints)
	{
		amount -= _hitPoints - _maxHitPoints;
		_hitPoints = _maxHitPoints;
	}
	msg = typeid(*this).name();
	msg += " " + _name + " has been repaired for " + std::to_string(amount) + " hit points.";
	_printInfoMessage(msg);
	_printVoiceMessage(_beRepairedVoiceLines[std::rand() % \
		_beRepairedNumVoices]);
	return (0);
}

					ClapTrap::ClapTrap(std::string const &rName) :
					_name(rName),
					_msgColor("\033[0m"),
					_level(1),
					_hitPoints(100),
					_maxHitPoints(100),
					_energyPoints(100),
					_maxEnergyPoints(100),
					_meleeAtkDamage(20),
					_rangedAtkDamage(10),
					_armorDamageReduction(2),

					_rangedAttackVoiceLines(__rangedAttackVoiceLines),
					_meleeAttackVoiceLines(__meleeAttackVoiceLines),
					_takeDamageVoiceLines(__takeDamageVoiceLines),
					_beRepairedVoiceLines(__beRepairedVoiceLines),
					_rangedAttackNumVoices(sizeof(__rangedAttackVoiceLines) / sizeof(std::string)),
					_meleeAttackNumVoices(sizeof(__meleeAttackVoiceLines) / sizeof(std::string)),
					_takeDamageNumVoices(sizeof(__takeDamageVoiceLines) / sizeof(std::string)),
					_beRepairedNumVoices(sizeof(__beRepairedVoiceLines) / sizeof(std::string))
{
	size_t			n_voices = sizeof(__constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	_printDebugMessage(dmsg);
	_printVoiceMessage(__constructorVoiceLines[std::rand() % n_voices]);
}

					ClapTrap::ClapTrap(ClapTrap const &rSrc)
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

					ClapTrap::~ClapTrap(void)
{
	size_t			n_voices = sizeof(ClapTrap::__destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_printVoiceMessage(__destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	_printDebugMessage(dmsg);
}

ClapTrap			&ClapTrap::operator=(ClapTrap const &rRhs)
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

void				ClapTrap::_printVoiceMessage(std::string const &rMsg) const
{
	std::string const	noc = "\033[0m";

	std::cout << _msgColor << _name << ": " << rMsg << noc << std::endl;
}

void				ClapTrap::_printInfoMessage(std::string const &rMsg) const
{
	#ifndef __INFO_PRINT__
		return ;
	#endif

	std::cerr << "[info]: " << rMsg << std::endl;
}

void				ClapTrap::_printDebugMessage(std::string const &rMsg) const
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

					ClapTrap::ClapTrap(void)
{
}

std::ostream		&operator<<(std::ostream &rOs, ClapTrap const &rRhs)
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
