/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:53:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/13 13:44:11 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

int		main(void)
{
	IMateriaSource *ms0 = new MateriaSource();
	AMateria *am;

	am = new Ice();
	ms0->learnMateria(am);
	ms0->learnMateria(am);
	ms0->learnMateria(am);
	ms0->learnMateria(am);
	delete am;

	am = new Cure();
	ms0->learnMateria(am);  // ms0 should replace _slots[0] whith cure
	delete am;

	Character *me = new Character("me");
	me->equip(ms0->createMateria("ice"));
	me->equip(ms0->createMateria("ice"));
	me->equip(ms0->createMateria("cure"));
	me->equip(ms0->createMateria("cure"));

	Character *bob = new Character("bob");
	me->use(0, *bob);
	me->use(0, *bob);  // _slots[0] is now 20 xp
	me->use(2, *bob);
	me->use(2, *bob);  // _slots[2] is now 20 xp

	std::cout << std::endl;
	std::cout << "me[0]->getXP(): " << me->getAMateria(0)->getXP() << std::endl;
	std::cout << "me[1]->getXP(): " << me->getAMateria(1)->getXP() << std::endl;
	std::cout << "me[2]->getXP(): " << me->getAMateria(2)->getXP() << std::endl;
	std::cout << "me[3]->getXP(): " << me->getAMateria(3)->getXP() << std::endl;

	std::cout << std::endl;
	Character *_me = new Character(*me);
	std::cout << "_me[0]->getXP(): " << _me->getAMateria(0)->getXP() << std::endl;
	std::cout << "_me[1]->getXP(): " << _me->getAMateria(1)->getXP() << std::endl;
	std::cout << "_me[2]->getXP(): " << _me->getAMateria(2)->getXP() << std::endl;
	std::cout << "_me[3]->getXP(): " << _me->getAMateria(3)->getXP() << std::endl;

	std::cout << std::endl;
	_me->use(1, *bob);
	_me->use(1, *bob);  // _slots[1] is now 20 xp
	_me->use(3, *bob);
	_me->use(3, *bob);  // _slots[3] is now 20 xp

	std::cout << std::endl;
	std::cout << "_me[0]->getXP(): " << _me->getAMateria(0)->getXP() << std::endl;
	std::cout << "_me[1]->getXP(): " << _me->getAMateria(1)->getXP() << std::endl;
	std::cout << "_me[2]->getXP(): " << _me->getAMateria(2)->getXP() << std::endl;
	std::cout << "_me[3]->getXP(): " << _me->getAMateria(3)->getXP() << std::endl;

	*me = *_me;  // Deep copy calls materia's clone() method.
	*me = *me;   // Check for same object assignment.

	std::cout << std::endl;
	std::cout << "me[0]->getXP(): " << me->getAMateria(0)->getXP() << std::endl;
	std::cout << "me[1]->getXP(): " << me->getAMateria(1)->getXP() << std::endl;
	std::cout << "me[2]->getXP(): " << me->getAMateria(2)->getXP() << std::endl;
	std::cout << "me[3]->getXP(): " << me->getAMateria(3)->getXP() << std::endl;

	delete ms0;
	delete me;
	delete _me;
	delete bob;

	return (0);
}
