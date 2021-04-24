/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:55:33 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 02:26:37 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

class						Victim
{
	public:
		std::string const	&getName(void) const;
		int					setName(std::string const &rName);

		virtual void		getPolymorphed(void) const;

							Victim(std::string const &rName);
							Victim(Victim const &rSrc);
		virtual				~Victim(void);
		Victim				&operator=(Victim const &rRhs);

	protected:
		std::string			_name;

							Victim(void);
};

std::ostream				&operator<<(std::ostream &rOs, Victim const &rRhs);

#endif // VICTIM_HPP
