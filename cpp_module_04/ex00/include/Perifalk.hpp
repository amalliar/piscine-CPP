/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Perifalk.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:25:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 02:21:27 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERIFALK_HPP
# define PERIFALK_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"
# include "colors.hpp"

class						Perifalk : public Victim
{
	public:
		virtual void		getPolymorphed(void) const;

							Perifalk(std::string const &rName);
							Perifalk(Perifalk const &rSrc);
		virtual				~Perifalk(void);
		Perifalk			&operator=(Perifalk const &rRhs);

	protected:
							Perifalk(void);
};

#endif // PERIFALK_HPP
