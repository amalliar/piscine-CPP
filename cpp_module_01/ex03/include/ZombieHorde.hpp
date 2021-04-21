/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:13:00 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 00:26:51 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include <string>
# include <cstdlib>
# include "Zombie.hpp"
# include "ZombieEvent.hpp"

class					ZombieHorde
{
	public:
		void			announce(void) const;

						ZombieHorde(int zmbHordeSize);
						ZombieHorde(ZombieHorde const &rSrc);
						~ZombieHorde(void);
		ZombieHorde		&operator=(ZombieHorde const &rRhs);

	private:
		size_t			_zmbHordeSize;
		Zombie			*_pZmbHorde;

						ZombieHorde(void);
};

#endif // ZOMBIE_HORDE_HPP
