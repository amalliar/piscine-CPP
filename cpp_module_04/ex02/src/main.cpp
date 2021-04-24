/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:33:28 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/12 16:20:36 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"

#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"


int		main(void)
{
	ISpaceMarine *sm0 = new TacticalMarine;
	ISpaceMarine *sm1 = new TacticalMarine;
	ISpaceMarine *sm2 = new TacticalMarine;
	ISpaceMarine *sm3 = new TacticalMarine;
	ISpaceMarine *at0 = new AssaultTerminator;
	ISpaceMarine *at1 = new AssaultTerminator;
	ISpaceMarine *at2 = new AssaultTerminator;
	ISpaceMarine *at3 = new AssaultTerminator;

	ISquad *sq4_marine = new Squad;
	ISquad *sq4_term = new Squad;

	sq4_marine->push(sm0);
	sq4_marine->push(sm1);
	sq4_marine->push(sm2);
	sq4_marine->push(sm3);

	sq4_term->push(at0);
	sq4_term->push(at1);
	sq4_term->push(at2);
	sq4_term->push(at3);

	std::cout << std::endl;
	for (int i = 0; i < sq4_marine->getCount(); ++i)
	{
		ISpaceMarine *cur = sq4_marine->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	for (int i = 0; i < sq4_term->getCount(); ++i)
	{
		ISpaceMarine *cur = sq4_term->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << std::endl;
	*(Squad *)sq4_term = *(Squad *)sq4_marine;
	*(Squad *)sq4_term = *(Squad *)sq4_term;  // test for corect handling of same object assignment

	std::cout << std::endl;
	for (int i = 0; i < sq4_marine->getCount(); ++i)
	{
		ISpaceMarine *cur = sq4_marine->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	for (int i = 0; i < sq4_term->getCount(); ++i)
	{
		ISpaceMarine *cur = sq4_term->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << std::endl;
	delete sq4_marine;
	delete sq4_term;

	return (0);
}
