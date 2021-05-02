/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedPeon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:25:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:18:03 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_PEON_HPP
# define RED_PEON_HPP

# include <iostream>
# include <string>
# include "Peon.hpp"
# include "colors.hpp"

class						RedPeon : public Peon
{
	public:

		virtual void		getPolymorphed(void) const;

							RedPeon(std::string const &rName);
							RedPeon(RedPeon const &rSrc);
		virtual				~RedPeon(void);

		RedPeon				&operator=(RedPeon const &rRhs);

	protected:

							RedPeon(void);
};

#endif // RED_PEON_HPP
