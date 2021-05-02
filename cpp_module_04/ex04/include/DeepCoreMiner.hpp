/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:21:56 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:17:33 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEP_CORE_MINER_HPP
# define DEEP_CORE_MINER_HPP

# include <iostream>
# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class					DeepCoreMiner : public IMiningLaser
{
	public:

		void			mine(IAsteroid *pAsteroid);

						DeepCoreMiner(void);
						DeepCoreMiner(DeepCoreMiner const &rSrc);
						~DeepCoreMiner(void);

		DeepCoreMiner	&operator=(DeepCoreMiner const &rRhs);
};

#endif // DEEP_CORE_MINER_HPP
