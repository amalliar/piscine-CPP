/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:58:46 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 00:59:51 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include "Brain.hpp"

class					Human
{
	public:
		Brain const		&getBrain(void) const;
		std::string		identify(void) const;

						Human(void);
						~Human(void);

	private:
		Brain const 	_brain;

						Human(Human const &rSrc);
		Human			&operator=(Human const &rRhs);
};

#endif // HUMAN_HPP
