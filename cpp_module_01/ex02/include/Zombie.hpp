/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:51:43 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 22:25:14 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class					Zombie
{
	public:
		void			announce(void) const;

						Zombie(std::string const &rName, std::string const &rType);
						Zombie(Zombie const &rSrc);
						~Zombie(void);
		Zombie			&operator=(Zombie const &rRhs);

	private:
		std::string		_name;
		std::string		_type;

						Zombie(void);
};

#endif // ZOMBIE_HPP
