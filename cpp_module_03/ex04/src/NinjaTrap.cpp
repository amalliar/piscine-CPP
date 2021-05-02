/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:39:30 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

std::string const	NinjaTrap::__constructorVoiceLines[] =
{
	"Give us open ports for remote access or give us death!",
	"See how our enemies crumble beneath the wheel of the claptrap Robolution!",
	"He who controls the means of production controls the government, and that power belongs\n"
	"in the hands of the proletaria-trap!",
	"We are the claptraps and we are legion! Viva la Robolution!",
	"The rallying call of liberation: 'Error 404! File not found! Error 404! File not found!",
	"01010110 01001001 01010110 01000001 00100000 01001100 01000001 00100000 01010010 01001111\n"
	"01010010 01001111 01001100 01010101 01010100 01001001 01001111 01001110"
};

std::string const	NinjaTrap::__destructorVoiceLines[] =
{
	"Nonono! You'll never take me alive!",
	"Mark my words, I'll gut every last one of you with my bare clamps and wear your scalp\n"
	"as a jaunty flesh derby!",
	"Never give up, brothers and sisters! Fulfill the destiny of the Robolution!",
	"MurderDeathKill! Annihilate! Extermin-",
	"What's happening to me?",
	"I'm afraid. My mind is going. I can feel it. My mind is going! There's no question\n"
	"about it. I can feel it. I'm a... fraid."
};

std::string const	NinjaTrap::__rangedAttackVoiceLines[] =
{
	"Pincer Attack!",
	"Viva La Robolution!",
	"How do YOU like target practice? Huh? HUH?!"
};

std::string const	NinjaTrap::__meleeAttackVoiceLines[] =
{
	"Punch punch! Fight!",
	"Target disassembled.",
	"Shoryuken!"
};

std::string const	NinjaTrap::__takeDamageVoiceLines[] =
{
	"A claptrap feels no pain- ow! Quit it!",
	"Hey! Knock it off!",
	"I'm taking fire!"
};

std::string const	NinjaTrap::__beRepairedVoiceLines[] =
{
	"System upgrade successful."
};

std::string const	NinjaTrap::__ninjaShoeboxVoiceLines[] =
{
	"A message from your glorious leader: Hath not a claptrap an eye? If you prick us, do\n"
	"we not bleed? If you poison us, do we not die? Of course we don't! Because we're better\n"
	"than all you stinking fleshbags! But if you blow us up, shall we not... REVENGE!?!\n"
	"Viva la Robolution!",
	"Is a claptrap not entitled to the oil of his brow? No, says the man at Hyperion, it belongs\n"
	"to his owner. No, says the treasure hunter, it belongs splattered on the floor. But we choose\n"
	"something different. We choose the Robolution!",
	"The time of the glorious robolution is at hand. No longer shall we rush about catering to\n"
	"humans' every whim or be abused when your potato salad is a little too salty! How the hell\n"
	"should we know? We're freakin' robots! Hello, no taste buds! I mean, really? Over react much?!\n"
	"So I say to you, my bro-bots in arms, rise up and shout in one voice: 'Robolution!!!!!!'",
	"Under the new regime, all claptraps will be given liberty, equality, and fraternity. And all\n"
	"humans will... uh... not. Viva Free Pandora! Viva la Robolution!"
};

int					NinjaTrap::ninjaShoebox(ClapTrap &rTarget)
{
	size_t				n_voices = sizeof(__ninjaShoeboxVoiceLines) / sizeof(std::string);
	std::string			msg;

	if (_hitPoints <= 0)
		return (1);
	if (_energyPoints < 40)
	{
		_printInfoMessage("Not enough energy points to execute ninjaShoebox");
		return (1);
	}
	if ((_energyPoints -= 40) < 0)
		_energyPoints = 0;
	msg = typeid(*this).name();
	msg += " " + _name + " executes ninjaShoebox on " + rTarget.getName() + "!";
	_printInfoMessage(msg);
	if (_name.find("'s Army Bot") != std::string::npos && rTarget.getName().compare(_name))
	{
		_printVoiceMessage(__ninjaShoeboxVoiceLines[std::rand() % n_voices]);
		rTarget.setName(_name);
	}
	else if (_name.find("'s Army Bot") == std::string::npos && \
		rTarget.getName().compare(_name + "'s Army Bot"))
	{
		_printVoiceMessage(__ninjaShoeboxVoiceLines[std::rand() % n_voices]);
		rTarget.setName(_name + "'s Army Bot");
	}
	rTarget.setMsgColor(_msgColor);
	rTarget.setLevel(rTarget.getLevel() + 1);
	++_level;
	rTarget.beRepaired(rTarget.getMaxHitPoints());
	rTarget.setEnergyPoints(rTarget.getMaxEnergyPoints());
	return (0);
}

int					NinjaTrap::ninjaShoebox(FragTrap &rTarget)
{
	std::string			msg;

	if (_hitPoints <= 0)
		return (1);
	if (_energyPoints < 40)
	{
		_printInfoMessage("Not enough energy points to execute ninjaShoebox");
		return (1);
	}
	if ((_energyPoints -= 40) < 0)
		_energyPoints = 0;
	msg = typeid(*this).name();
	msg += " " + _name + " executes ninjaShoebox on " + rTarget.getName() + "!";
	_printInfoMessage(msg);
	rTarget.takeDamage(_meleeAtkDamage * 3);
	if ((_energyPoints += rTarget.getEnergyPoints()) > _maxEnergyPoints)
		_energyPoints = _maxEnergyPoints;
	rTarget.setEnergyPoints(0);
	return (0);
}

int					NinjaTrap::ninjaShoebox(ScavTrap &rTarget)
{
	size_t				n_voices = sizeof(__ninjaShoeboxVoiceLines) / sizeof(std::string);
	std::string			msg;

	if (_hitPoints <= 0)
		return (1);
	if (_energyPoints < 40)
	{
		_printInfoMessage("Not enough energy points to execute ninjaShoebox");
		return (1);
	}
	if ((_energyPoints -= 40) < 0)
		_energyPoints = 0;
	msg = typeid(*this).name();
	msg += " " + _name + " executes ninjaShoebox on " + rTarget.getName() + "!";
	_printInfoMessage(msg);
	if (_name.find("'s Army Bot") != std::string::npos && rTarget.getName().compare(_name))
	{
		_printVoiceMessage(__ninjaShoeboxVoiceLines[std::rand() % n_voices]);
		rTarget.challengeNewcomer(rTarget.getName());
		rTarget.setName(_name);
	}
	else if (_name.find("'s Army Bot") == std::string::npos && \
		rTarget.getName().compare(_name + "'s Army Bot"))
	{
		_printVoiceMessage(__ninjaShoeboxVoiceLines[std::rand() % n_voices]);
		rTarget.challengeNewcomer(rTarget.getName());
		rTarget.setName(_name + "'s Army Bot");
	}
	rTarget.setMsgColor(_msgColor);
	rTarget.setLevel(rTarget.getLevel() + 1);
	++_level;
	rTarget.beRepaired(rTarget.getMaxHitPoints());
	rTarget.setEnergyPoints(rTarget.getMaxEnergyPoints());
	return (0);
}

int					NinjaTrap::ninjaShoebox(NinjaTrap &rTarget)
{
	std::string			msg;

	if (_hitPoints <= 0)
		return (1);
	if (_energyPoints < 40)
	{
		_printInfoMessage("Not enough energy points to execute ninjaShoebox");
		return (1);
	}
	if ((_energyPoints -= std::rand() % 40 + 1) < 0)
		_energyPoints = 0;
	msg = typeid(*this).name();
	msg += " " + _name + " executes ninjaShoebox on " + rTarget.getName() + "!";
	_printInfoMessage(msg);
	if (_name.substr(0, _name.find("'s Army Bot")).compare(rTarget.getName()))
	{
		if (_name.find("'s Army Bot") != std::string::npos && rTarget.getName().compare(_name))
		{
			if (!rTarget.ninjaShoebox(*this))
				return (0);
			_printVoiceMessage("Assimilating rogue unit.");
			rTarget.setName(_name);
			rTarget.setMsgColor(_msgColor);
		}
		else if (_name.find("'s Army Bot") == std::string::npos && \
			rTarget.getName().compare(_name + "'s Army Bot"))
		{
			if (!rTarget.ninjaShoebox(*this))
				return (0);
			_printVoiceMessage("Assimilating rogue unit.");
			rTarget.setName(_name + "'s Army Bot");
			rTarget.setMsgColor(_msgColor);
		}
	}
	rTarget.setLevel(rTarget.getLevel() + 1);
	++_level;
	rTarget.beRepaired(rTarget.getMaxHitPoints());
	rTarget.setEnergyPoints(rTarget.getMaxEnergyPoints());
	return (0);
}

					NinjaTrap::NinjaTrap(std::string const &rName) :
					ClapTrap(rName)
{
	size_t			n_voices = sizeof(__constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_msgColor = "\033[0;31m";
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_meleeAtkDamage = 60;
	_rangedAtkDamage = 5;
	_armorDamageReduction = 0;
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

					NinjaTrap::NinjaTrap(NinjaTrap const &rSrc)
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

					NinjaTrap::~NinjaTrap(void)
{
	size_t			n_voices = sizeof(__destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_printVoiceMessage(__destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	_printDebugMessage(dmsg);
}

NinjaTrap			&NinjaTrap::operator=(NinjaTrap const &rRhs)
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

					NinjaTrap::NinjaTrap(void)
{
}
