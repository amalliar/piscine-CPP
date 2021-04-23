/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:29:58 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/08 06:03:30 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "FragTrap.hpp"

int			main(void)
{
	std::srand(std::time(NULL));

	FragTrap	ftrap_a("Claptrap P. Claptrappington");
	FragTrap	ftrap_b("CLAP-9000");
	FragTrap	*actors[] = {&ftrap_a, &ftrap_b};
	int			idx;
	int			dmg;

	ftrap_b.setMsgColor("\033[0;35m");
	std::cout << std::endl << *actors[0];
	std::cout << *actors[1] << std::endl;

	while (1)
	{
		idx = std::rand() % 2;
		switch (std::rand() % 4)
		{
			case	0:
				actors[idx]->rangedAttack(actors[(idx + 1) % 2]->getName());
				actors[(idx + 1) % 2]->takeDamage(actors[idx]->getRangedAtkDamage());
				if (actors[(idx + 1) % 2]->getHitPoints() == 0)
					goto END;
				break ;
			case	1:
				actors[idx]->meleeAttack(actors[(idx + 1) % 2]->getName());
				actors[(idx + 1) % 2]->takeDamage(actors[idx]->getMeleeAtkDamage());
				if (actors[(idx + 1) % 2]->getHitPoints() == 0)
					goto END;
				break ;
			case	2:
				if (std::rand() % 10)
					break ;
				dmg = actors[idx]->vaulthunter_dot_exe(actors[(idx + 1) % 2]->getName());
				if (dmg > 0)
					actors[(idx + 1) % 2]->takeDamage(dmg);
				if (actors[(idx + 1) % 2]->getHitPoints() == 0)
					goto END;
				break ;
			case	3:
				if (actors[idx]->getHitPoints() < actors[idx]->getMaxHitPoints())
					actors[idx]->beRepaired(std::rand() % 25 + 1);
				break ;
		}
	}

END:
	std::cout << std::endl;
	return (0);
}
