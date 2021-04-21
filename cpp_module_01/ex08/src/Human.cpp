/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 00:31:34 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 19:23:02 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

t_action		Human::actMap[] =
{
	{"atkMelee", &Human::_meleeAttack},
	{"atkRanged", &Human::_rangedAttack},
	{"atkShout", &Human::_intimidatingShout}
};

void			Human::action(std::string const &rActionName, std::string const &rTarget)
{
	size_t		i;

	for (i = 0; i < numActs; ++i)
		if (!rActionName.compare(actMap[i].name))
		{
			(this->*actMap[i].func)(rTarget);
			return ;
		}
}

				Human::Human(std::string const &rName) :
				_name(rName)
{
}

				Human::Human(Human const &rSrc) :
				_name(rSrc._name)
{
}

				Human::~Human(void)
{
}

Human			&Human::operator=(Human const &rRhs)
{
	this->_name = rRhs._name;
	return (*this);
}

void			Human::_meleeAttack(std::string const &rTarget)
{
	std::string		clr_crit = "\033[1;31m";
	std::string 	clr_noc = "\033[0m";
	int				max_damage = 30;
	int				damage;
	bool			is_crit = false;

	damage = rand() % (max_damage + 1);
	if (damage % 20 == rand() % 20)
	{
		is_crit = true;
		std::cout << clr_crit;
	}
	std::cout << this->_name << " punches " << rTarget;
	if (is_crit)
		std::cout << " with a devastating melee attack for " << damage * 2 << " hit points.";
	else
		std:: cout << " for " << damage << " hit points.";
	std::cout << clr_noc << std::endl;
}

void			Human::_rangedAttack(std::string const &rTarget)
{
	std::string		clr_crit = "\033[1;31m";
	std::string 	clr_noc = "\033[0m";
	int				max_damage = 55;
	int				damage;
	bool			is_crit = false;

	damage = rand() % (max_damage + 1);
	if (damage % 20 == rand() % 20)
	{
		is_crit = true;
		std::cout << clr_crit;
	}
	std::cout << this->_name << " shoots " << rTarget;
	if (is_crit)
		std::cout << " in the eye for " << damage * 2 << " hit points. Ouch!";
	else
		std:: cout << " for " << damage << " hit points.";
	std::cout << clr_noc << std::endl;
}

void			Human::_intimidatingShout(std::string const &rTarget)
{
	std::string		clr_crit = "\033[1;31m";
	std::string 	clr_noc = "\033[0m";
	int				max_damage = 0;
	int				damage;
	bool			is_crit = false;

	damage = rand() % (max_damage + 1);
	if (damage % 20 == rand() % 20)
	{
		is_crit = true;
		std::cout << clr_crit;
	}
	std::cout << this->_name << " shouts at " << rTarget;
	if (is_crit)
		std::cout << " intimidatingly loudly for " << damage * 2 << " hit points.";
	else
		std:: cout << " for " << damage << " hit points.";
	std::cout << clr_noc << std::endl;
}

				Human::Human(void)
{
}
