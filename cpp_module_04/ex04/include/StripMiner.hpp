/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:21:56 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 15:58:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIP_MINER_HPP
# define STRIP_MINER_HPP

# include <iostream>
# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class					StripMiner : public IMiningLaser
{
	public:
		void			mine(IAsteroid *pAsteroid);

						StripMiner(void);
						StripMiner(StripMiner const &rSrc);
						~StripMiner(void);
		StripMiner		&operator=(StripMiner const &rRhs);
};

#endif // STRIP_MINER_HPP
