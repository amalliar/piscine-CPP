/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAsteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:38:25 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 15:56:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_ASTEROID_HPP
# define I_ASTEROID_HPP

# include <string>

class							DeepCoreMiner;
class							StripMiner;

class							IAsteroid
{
	public:
		virtual std::string		getName(void) const = 0;

		virtual std::string		beMined(DeepCoreMiner *pDeepCoreMiner) const = 0;
		virtual std::string		beMined(StripMiner *pStripMiner) const = 0;

		virtual					~IAsteroid(void) {}
};

#endif // I_ASTEROID_HPP
