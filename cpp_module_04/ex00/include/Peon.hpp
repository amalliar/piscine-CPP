/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:25:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:16:36 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"
# include "colors.hpp"

class						Peon : public Victim
{
	public:

		virtual void		getPolymorphed(void) const;

							Peon(std::string const &rName);
							Peon(Peon const &rSrc);
		virtual				~Peon(void);

		Peon				&operator=(Peon const &rRhs);

	protected:

							Peon(void);
};

#endif // PEON_HPP
