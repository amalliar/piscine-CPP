/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:29:58 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/10 09:30:00 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int			main(void)
{
	std::srand(std::time(NULL));

	ClapTrap	ctrap("CL4P-TP");
	FragTrap	ftrap("Claptrap P. Claptrappington");
	ScavTrap	strap("CLAP-9000");
	NinjaTrap	ntrap("INAC");
	NinjaTrap	_ntrap(ntrap);
	SuperTrap	sutrap("HAL-9000");

	int			idx;
	int			dmg;

	_ntrap.setName("CAIN");
	_ntrap.setMsgColor("\033[1;31m");
	std::cout << std::endl << ctrap << ftrap << strap << ntrap << _ntrap << sutrap << std::endl;

	while (1)
	{
		idx = std::rand() % 2;
		switch (std::rand() % 8)
		{
			case	0:
				(idx) ? ftrap.rangedAttack(strap.getName()) : strap.rangedAttack(ftrap.getName());
				(idx) ? strap.takeDamage(ftrap.getRangedAtkDamage()) : ftrap.takeDamage(strap.getRangedAtkDamage());
				if (ftrap.getHitPoints() == 0 || strap.getHitPoints() == 0)
					goto END;
				break ;
			case	1:
				(idx) ? ftrap.meleeAttack(strap.getName()) : strap.meleeAttack(ftrap.getName());
				(idx) ? strap.takeDamage(ftrap.getMeleeAtkDamage()) : ftrap.takeDamage(strap.getMeleeAtkDamage());
				if (ftrap.getHitPoints() == 0 || strap.getHitPoints() == 0)
					goto END;
				break ;
			case	2:
				if (std::rand() % 10)
					break ;
				dmg = (idx) ? ftrap.vaulthunter_dot_exe(strap.getName()) : strap.challengeNewcomer(ftrap.getName());
				strap.takeDamage(dmg);
				if (strap.getHitPoints() == 0)
					goto END;
				break ;
			case	3:
				if ((idx && ftrap.getHitPoints() < ftrap.getMaxHitPoints()) || (!idx && strap.getHitPoints() < strap.getMaxHitPoints()))
					(idx) ? ftrap.beRepaired(std::rand() % 25 + 1) : strap.beRepaired(std::rand() % 25 + 1);
				break ;
			case	4:
				if (std::rand() % 3)
					break ;
				(std::rand() % 2) ? ntrap.ninjaShoebox(strap) : ntrap.ninjaShoebox(_ntrap);
				ntrap.ninjaShoebox(ctrap);
				break ;
			case	5:
				if (std::rand() % 3)
					break ;
				(std::rand() % 2) ? _ntrap.ninjaShoebox(strap) : _ntrap.ninjaShoebox(ntrap);
				_ntrap.ninjaShoebox(ctrap);
				break ;
			case	6:
				if (std::rand() % 42)
					break ;
				(idx) ? dmg = ntrap.ninjaShoebox(ftrap) : dmg = _ntrap.ninjaShoebox(ftrap);
				if (!dmg)
					goto END;
				break ;
			case	7:
				if (std::rand() % 10)
					break ;
				sutrap.meleeAttack(ftrap.getName());
				sutrap.rangedAttack(ntrap.getName());
				sutrap.vaulthunter_dot_exe(strap.getName());
				sutrap.ninjaShoebox(ctrap);
				sutrap.ninjaShoebox(ftrap);
				sutrap.ninjaShoebox(_ntrap);
				sutrap.ninjaShoebox(ntrap);
				goto END;
		}
	}

END:
	std::cout << std::endl << ctrap << ftrap << strap << ntrap << _ntrap << sutrap << std::endl;
	return (0);
}
