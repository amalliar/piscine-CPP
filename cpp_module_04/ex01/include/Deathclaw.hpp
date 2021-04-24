/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deathclaw.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:48:55 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:17:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEATH_CLAW_HPP
# define DEATH_CLAW_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"
# include "colors.hpp"

class					Deathclaw : public Enemy
{
	public:
		virtual void	takeDamage(int damage);

						Deathclaw(void);
						Deathclaw(Deathclaw const &rSrc);
		virtual			~Deathclaw(void);
		Deathclaw		&operator=(Deathclaw const &rRhs);
};

#endif // DEATH_CLAW_HPP
