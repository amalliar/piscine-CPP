/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:55:54 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 15:57:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
# define ASTEROID_HPP

# include <string>
# include "IAsteroid.hpp"
# include "DeepCoreMiner.hpp"
# include "StripMiner.hpp"

class					DeepCoreMiner;
class					StripMiner;

class					Asteroid : public IAsteroid
{
	public:
		std::string		getName(void) const;

		std::string		beMined(DeepCoreMiner *pDeepCoreMiner) const;
		std::string		beMined(StripMiner *pStripMiner) const;

						Asteroid(void);
						Asteroid(Asteroid const &rSrc);
						~Asteroid(void);
		Asteroid		&operator=(Asteroid const &rRhs);
};

#endif // ASTEROID_HPP
