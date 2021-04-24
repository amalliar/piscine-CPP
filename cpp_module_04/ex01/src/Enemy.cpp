/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:29:25 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:19:10 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

std::string const		&Enemy::getType(void) const
{
	return (this->_type);
}

int						Enemy::getHP(void) const
{
	return (this->_hp);
}

void					Enemy::takeDamage(int damage)
{
	if (this->_hp <= 0 || damage <= 0)
		return ;
	if ((this->_hp -= damage) < 0)
		this->_hp = 0;
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
	this->_hp = rRhs.getHP();
	this->_type = rRhs.getType();
	return (*this);
}

						Enemy::Enemy(void)
{
}
