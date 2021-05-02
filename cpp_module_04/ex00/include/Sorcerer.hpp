/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:10:03 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:20:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class						Sorcerer
{
	public:

		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;

		void				polymorph(Victim const &rVictim) const;

							Sorcerer(std::string const &rName, std::string const &rTitle);
							Sorcerer(Sorcerer const &rSrc);
							~Sorcerer(void);

		Sorcerer			&operator=(Sorcerer const &rRhs);

	protected:

		std::string			_name;
		std::string			_title;

							Sorcerer(void);
};

std::ostream				&operator<<(std::ostream &rOs, Sorcerer const &rRhs);

#endif // SORCERER_HPP
