/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Comet.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:55:54 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 15:57:46 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMET_HPP
# define COMET_HPP

# include <string>
# include "IAsteroid.hpp"
# include "DeepCoreMiner.hpp"
# include "StripMiner.hpp"

class					DeepCoreMiner;
class					StripMiner;

class					Comet : public IAsteroid
{
	public:
		std::string		getName(void) const;

		std::string		beMined(DeepCoreMiner *pDeepCoreMiner) const;
		std::string		beMined(StripMiner *pStripMiner) const;

						Comet(void);
						Comet(Comet const &rSrc);
						~Comet(void);
		Comet			&operator=(Comet const &rRhs);
};

#endif // COMET_HPP
