/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:29:58 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/09 06:44:45 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int			main(void)
{
	std::srand(std::time(NULL));

	FragTrap	ftrap("Claptrap P. Claptrappington");
	ScavTrap	strap("CLAP-9000");
	int			idx;
	int			dmg;

	std::cout << std::endl << ftrap;
	std::cout << strap << std::endl;

	while (1)
	{
		idx = std::rand() % 2;
		switch (std::rand() % 4)
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
		}
	}

END:
	std::cout << std::endl;
	return (0);
}
