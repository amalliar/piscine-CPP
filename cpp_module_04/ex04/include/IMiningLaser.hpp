/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMiningLaser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:33 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 15:57:04 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MINING_LASER_HPP
# define I_MINING_LASER_HPP

# include "IAsteroid.hpp"

class					IMiningLaser
{
	public:
		virtual void	mine(IAsteroid *pAsteroid) = 0;

		virtual			~IMiningLaser(void) {}
};

#endif // I_MINING_LASER_HPP
