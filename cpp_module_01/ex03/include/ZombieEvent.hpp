/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:09:07 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 22:59:17 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <string>
# include "Zombie.hpp"

class							Zombie;

class							ZombieEvent
{
	public:
		static const int		numZombieTypes = 11;
		static std::string		zombieTypes[numZombieTypes];

		int						setZombieType(int type);
		Zombie					*newZombie(std::string const &rName) const;
		Zombie					*randomChump(void) const;

								ZombieEvent(void);
								ZombieEvent(ZombieEvent const &rSrc);
								~ZombieEvent(void);
		ZombieEvent				&operator=(ZombieEvent const &rRhs);

	private:
		int						_curZombieType;
};

#endif // ZOMBIE_EVENT_HPP
