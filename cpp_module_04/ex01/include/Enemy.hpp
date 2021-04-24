/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:23:54 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:18:38 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class						Enemy
{
	public:
		int					getHP(void) const;
		std::string const	&getType(void) const;

		virtual void		takeDamage(int damage);

							Enemy(int hp, std::string const &rType);
							Enemy(Enemy const &rSrc);
		virtual				~Enemy(void);
		Enemy				&operator=(Enemy const &rRhs);

	protected:
		int					_hp;
		std::string			_type;

							Enemy(void);
};

#endif // ENEMY_HPP
