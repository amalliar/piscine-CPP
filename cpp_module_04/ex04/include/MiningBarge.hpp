/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:11:07 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:18:09 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINING_BARGE_HPP
# define MINING_BARGE_HPP

# include <iostream>
# include <cstddef>
# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class							MiningBarge
{
	public:

			void				equip(IMiningLaser *pMiningLaser);
			void				mine(IAsteroid *pAsteroid) const;

								MiningBarge(void);
								MiningBarge(MiningBarge const &rSrc);
								~MiningBarge(void);

		MiningBarge				&operator=(MiningBarge const &rRhs);

	private:

		static size_t const		_numMiningLasers = 4;
		IMiningLaser			*_pMiningLasers[_numMiningLasers];
};

#endif // MINING_BARGE_HPP
