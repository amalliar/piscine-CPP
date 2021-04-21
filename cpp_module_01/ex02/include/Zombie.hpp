/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:51:43 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 23:32:24 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class						Zombie
{
	public:
		int					setName(std::string const &rName);
		int					setType(std::string const &rType);

		static size_t const numZombieTypes = 11;
		static std::string	zombieTypes[numZombieTypes];

		void				announce(void) const;

							Zombie(void);
							Zombie(std::string const &rName, std::string const &rType);
							Zombie(Zombie const &rSrc);
							~Zombie(void);
		Zombie				&operator=(Zombie const &rRhs);

	private:
		std::string			_name;
		std::string			_type;
};

#endif // ZOMBIE_HPP
