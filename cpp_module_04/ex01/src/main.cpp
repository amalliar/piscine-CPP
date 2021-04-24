/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:04:55 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/13 12:59:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Deathclaw.hpp"

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "AlienBlaster.hpp"

int		main(void)
{
	AWeapon			*plasma_rifle = new PlasmaRifle();
	AWeapon			*power_fist = new PowerFist();
	AWeapon			*alien_blaster = new AlienBlaster();
	Character		*player = new Character("Vault Dweller");

	std::cout << *player;
	Enemy *rad_scorp = new RadScorpion();
	player->equip(plasma_rifle);
	std::cout << *player;
	player->equip(power_fist);
	player->attack(rad_scorp);
	std::cout << *player;
	player->equip(plasma_rifle);
	std::cout << *player;
	player->attack(rad_scorp);
	std::cout << *player;
	player->attack(rad_scorp);
	std::cout << *player;

	player->equip(NULL);
	std::cout << *player;
	player->recoverAP();
	std::cout << *player;
	player->recoverAP();
	std::cout << *player;
	player->recoverAP();  // 40 AP -> fail
	std::cout << *player;
	Enemy *sup_mutant = new SuperMutant();
	player->equip(power_fist);
	std::cout << *player;
	player->attack(sup_mutant);
	std::cout << *player;
	player->attack(sup_mutant);
	std::cout << *player;
	player->attack(sup_mutant);
	std::cout << *player;
	player->attack(sup_mutant);
	std::cout << *player;

	player->equip(NULL);
	std::cout << *player;
	Enemy *deathclaw = new Deathclaw();
	player->equip(alien_blaster);
	std::cout << *player;
	player->attack(deathclaw);
	std::cout << *player;
	player->attack(deathclaw);
	std::cout << *player;

	player->equip(NULL);
	std::cout << *player;
	sup_mutant = new SuperMutant();
	player->equip(alien_blaster);
	std::cout << *player;
	player->attack(sup_mutant);  // 0 AP -> fail
	player->recoverAP();
	std::cout << *player;
	player->attack(sup_mutant);
	std::cout << *player;
	player->equip(NULL);
	std::cout << *player;

	return (0);
}
