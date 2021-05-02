/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:48:55 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:28:32 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"
# include "colors.hpp"

class					RadScorpion : public Enemy
{
	public:

						RadScorpion(void);
						RadScorpion(RadScorpion const &rSrc);
		virtual			~RadScorpion(void);

		RadScorpion		&operator=(RadScorpion const &rRhs);
};

#endif // RAD_SCORPION_HPP
