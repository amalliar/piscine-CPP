/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:29:25 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:26:38 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

std::string const		&Enemy::getType(void) const
{
	return (_type);
}

int						Enemy::getHP(void) const
{
	return (_hp);
}

void					Enemy::takeDamage(int damage)
{
	if (_hp <= 0 || damage <= 0)
		return ;
	if ((_hp -= damage) < 0)
		_hp = 0;
}

						Enemy::Enemy(int hp, std::string const &rType) :
						_hp(hp),
						_type(rType)
{
}

						Enemy::Enemy(Enemy const &rSrc)
{
	*this = rSrc;
}

						Enemy::~Enemy(void)
{
}

Enemy					&Enemy::operator=(Enemy const &rRhs)
{
	if (this != &rRhs)
	{
		_hp = rRhs.getHP();
		_type = rRhs.getType();
	}
	return (*this);
}

						Enemy::Enemy(void)
{
}
