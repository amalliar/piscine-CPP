/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:48:55 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:21:52 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"
# include "colors.hpp"

class					SuperMutant : public Enemy
{
	public:
		virtual void	takeDamage(int damage);

						SuperMutant(void);
						SuperMutant(SuperMutant const &rSrc);
		virtual			~SuperMutant(void);
		SuperMutant		&operator=(SuperMutant const &rRhs);
};

#endif // SUPER_MUTANT_HPP
