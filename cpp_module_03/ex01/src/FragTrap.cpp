/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:17:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:23:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::string const	FragTrap::_constructorVoiceLines[] =
{
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

std::string const	FragTrap::_destructorVoiceLines[] =
{
	"I'll stop talking when I'm dead!",
	"I'll die the way I lived: annoying!",
	"Come back here! I'll gnaw your legs off!",
	"This could've gone better!",
	"Good thing I don't have a soul!",
	"You can't kill me!",
	"I'm too pretty to die!",
	"Robot down!",
	"No, nononono NO!",
	"I'll never go back to the bad place!",
	"I have many regrets!"
};

std::string const	FragTrap::_takeDamageVoiceLines[] =
{
	"My assets... frozen!",
	"I can't feel my fingers! Gah! I don't have any fingers!",
	"Too cold... can't move!",
	"I am a robot popsicle!",
	"Brrh... So cold... brrh...",
	"Metal gears... frozen solid!",
	"Why do I even feel pain?!",
	"Why did they build me out of galvanized flesh?!",
	"Ow hohoho, that hurts! Yipes!",
	"My robotic flesh! AAHH!",
	"Yikes! Ohhoho!",
	"Woah! Oh! Jeez!",
	"If only my chassis... weren't made of recycled human body parts! Wahahaha!"
};

std::string const	FragTrap::_beRepairedVoiceLines[] =
{
	"Can I just say... yeehaw.",
	"You are ace high!",
	"You're the wub to my dub!",
	"Sweet life juice!",
	"Healsies!"
};

std::string const	FragTrap::_rangedAttackVoiceLines[] =
{
	"Step right up, to the Bulletnator 9000!",
	"I am a tornado of death and bullets!",
	"Stop me before I kill again, except don't!",
	"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
	"Ha ha ha! Fall before your robot overlord!",
	"Can't touch this!",
	"Ha! Keep 'em coming!",
	"There is no way this ends badly!",
	"This is why I was built!"
};

std::string const	FragTrap::_meleeAttackVoiceLines[] =
{
	"Hyah!",
	"Heyyah!",
	"Take that!",
	"Bop!"
};

std::string const	FragTrap::_vaulthunterVoiceLines[] =
{
	"Place your bets!",
	"Defragmenting!",
	"Running the sequencer!",
	"It's happening... it's happening!",
	"It's about to get magical!",
	"I'm pulling tricks outta my hat!",
	"You can't just program this level of excitement!",
	"What will he do next?",
	"Things are about to get awesome!",
	"Push this button, flip this dongle, voila! Help me!",
	"Square the I, carry the 1... YES!",
	"Resequencing combat protocols!",
	"Look out everybody, things are about to get awesome!",
	"I have an IDEA!",
	"Round and around and around she goes!",
	"It's like a box of chocolates...",
	"Step right up to the sequence of Trapping!",
	"Loading combat packages!",
	"F to the R to the 4 to the G to the WHAAT!"
};

std::string	const	&FragTrap::getName(void) const
{
	return (_name);
}

std::string	const	&FragTrap::getMsgColor(void) const
{
	return (_msgColor);
}

int					FragTrap::getLevel(void) const
{
	return (_level);
}

int					FragTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int					FragTrap::getMaxHitPoints(void) const
{
	return (_maxHitPoints);
}

int					FragTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int					FragTrap::getMaxEnergyPoints(void) const
{
	return (_maxEnergyPoints);
}

int					FragTrap::getMeleeAtkDamage(void) const
{
	return (_meleeAtkDamage);
}

int					FragTrap::getRangedAtkDamage(void) const
{
	return (_rangedAtkDamage);
}

int					FragTrap::getArmorDamageReduction(void) const
{
	return (_armorDamageReduction);
}

int					FragTrap::setName(std::string const &rName)
{
	_name = rName;
	return (0);
}

int					FragTrap::setMsgColor(std::string const &rMsgColor)
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
			_msgColor = rMsgColor;
			return (0);
		}
	return (1);
}

int					FragTrap::setLevel(int level)
{
	if (level < 0)
		return (1);
	_level = level;
	return (0);
}

int					FragTrap::setHitPoints(int hitPoints)
{
	if (hitPoints < 0 || hitPoints > _maxHitPoints)
		return (1);
	_hitPoints = hitPoints;
	return (0);
}

int					FragTrap::setMaxHitPoints(int maxHitPoints)
{
	if (maxHitPoints < 0)
		return (1);
	_maxHitPoints = maxHitPoints;
	return (0);
}

int					FragTrap::setEnergyPoints(int energyPoints)
{
	if (energyPoints < 0 || energyPoints > _maxEnergyPoints)
		return (1);
	_energyPoints = energyPoints;
	return (0);
}

int					FragTrap::setMeleeAtkDamage(int meleeAtkDamage)
{
	if (meleeAtkDamage < 0)
		return (1);
	_meleeAtkDamage = meleeAtkDamage;
	return (0);
}

int					FragTrap::setRangedAtkDamage(int rangedAtkDamage)
{
	if (rangedAtkDamage < 0)
		return (1);
	_rangedAtkDamage = rangedAtkDamage;
	return (0);
}

int					FragTrap::setArmorDamageReduction(int armorDamageReduction)
{
	if (armorDamageReduction < 0)
		return (1);
	_armorDamageReduction = armorDamageReduction;
	return (0);
}

int					FragTrap::vaulthunter_dot_exe(std::string const &rTarget)
{
	std::string const	vhunter_atk_pool[][3] =
	{
		{"Shhhhh...trap", "I'm a robot ninja...", "0"},
		{"Funzerker", "I'm a sexy dinosaur! Rawr!", "0"},
		{"Rubber Ducky", "I am rubber, and you are so dead!", "0"},
		{"Pirate Ship Mode", "Avast ye scurvy dogs!", "0"},
		{"Meat Unicycle", "It's the only way to stop the voices!", "180"}
	};
	std::string			msg;
	size_t				n_voices = sizeof(FragTrap::_vaulthunterVoiceLines) / sizeof(std::string);
	size_t				n_atks = sizeof(vhunter_atk_pool) / sizeof(std::string[3]);
	int					idx;

	if (_hitPoints <= 0 || rTarget.empty())
		return (-1);
	if (_energyPoints < 25)
	{
		_printInfoMessage("Not enough energy points to execute VaultHunter.EXE");
		return (-1);
	}
	_printVoiceMessage(FragTrap::_vaulthunterVoiceLines[std::rand() % n_voices]);
	if ((_energyPoints -= 25) < 0)
		_energyPoints = 0;
	idx = std::rand() % n_atks;
	msg = typeid(*this).name();
	msg += " " + _name + " executes VaultHunter.EXE <" + vhunter_atk_pool[idx][0] + \
		"> on " + rTarget + " dealing " + vhunter_atk_pool[idx][2] + " points of damage! Wow!";
	_printInfoMessage(msg);
	_printVoiceMessage(vhunter_atk_pool[idx][1]);
	return (std::stoi(vhunter_atk_pool[idx][2]));
}

int					FragTrap::rangedAttack(std::string const &rTarget)
{
	size_t			n_voices = sizeof(FragTrap::_rangedAttackVoiceLines) / sizeof(std::string);
	std::string		msg;

	if (_hitPoints <= 0 || rTarget.empty())
		return (1);
	msg = typeid(*this).name();
	msg += " " + _name + " attacks " + rTarget + " at range causing " + \
		std::to_string(_rangedAtkDamage) + " points of damage!";
	_printInfoMessage(msg);
	_printVoiceMessage(FragTrap::_rangedAttackVoiceLines[std::rand() % n_voices]);
	return (0);
}

int					FragTrap::meleeAttack(std::string const &rTarget)
{
	size_t			n_voices = sizeof(FragTrap::_meleeAttackVoiceLines) / sizeof(std::string);
	std::string		msg;

	if (_hitPoints <= 0 || rTarget.empty())
		return (1);
	msg = typeid(*this).name();
	msg += " " + _name + " punches " + rTarget + " causing " + \
		std::to_string(_meleeAtkDamage) + " points of damage!";
	_printInfoMessage(msg);
	_printVoiceMessage(FragTrap::_meleeAttackVoiceLines[std::rand() % n_voices]);
	return (0);
}

int					FragTrap::takeDamage(unsigned int amount)
{
	size_t			n_voices = sizeof(FragTrap::_takeDamageVoiceLines) / sizeof(std::string);
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
	_printVoiceMessage(FragTrap::_takeDamageVoiceLines[std::rand() % n_voices]);
	return (0);
}

int					FragTrap::beRepaired(unsigned int amount)
{
	size_t			n_voices = sizeof(FragTrap::_beRepairedVoiceLines) / sizeof(std::string);
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
	_printVoiceMessage(FragTrap::_beRepairedVoiceLines[std::rand() % n_voices]);
	return (0);
}

					FragTrap::FragTrap(std::string const &rName) :
					_name(rName),
					_msgColor("\033[0;33m"),
					_level(1),
					_hitPoints(100),
					_maxHitPoints(100),
					_energyPoints(100),
					_maxEnergyPoints(100),
					_meleeAtkDamage(30),
					_rangedAtkDamage(20),
					_armorDamageReduction(5)
{
	size_t			n_voices = sizeof(FragTrap::_constructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been created.";
	_printDebugMessage(dmsg);
	_printVoiceMessage(FragTrap::_constructorVoiceLines[std::rand() % n_voices]);
}

					FragTrap::FragTrap(FragTrap const &rSrc)
{
	*this = rSrc;
}

					FragTrap::~FragTrap(void)
{
	size_t			n_voices = sizeof(FragTrap::_destructorVoiceLines) / sizeof(std::string);
	std::string		dmsg;

	_printVoiceMessage(FragTrap::_destructorVoiceLines[std::rand() % n_voices]);
	dmsg = "Object of type ";
	dmsg += typeid(*this).name();
	dmsg += " has been destroyed.";
	_printDebugMessage(dmsg);
}

FragTrap			&FragTrap::operator=(FragTrap const &rRhs)
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

void				FragTrap::_printVoiceMessage(std::string const &rMsg) const
{
	std::string const	noc = "\033[0m";

	std::cout << _msgColor << _name << ": " << rMsg << noc << std::endl;
}

void				FragTrap::_printInfoMessage(std::string const &rMsg) const
{
	#ifndef __INFO_PRINT__
		return ;
	#endif

	std::cerr << "[info]: " << rMsg << std::endl;
}

void				FragTrap::_printDebugMessage(std::string const &rMsg) const
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

					FragTrap::FragTrap(void)
{
}

std::ostream		&operator<<(std::ostream &rOs, FragTrap const &rRhs)
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
