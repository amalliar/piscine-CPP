/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:10:02 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 00:53:45 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>
# include <iomanip>

class					Brain
{
	public:
		std::string		identify(void) const;

						Brain(void);
						~Brain(void);

	private:
						Brain(Brain const &rSrc);
		Brain			&operator=(Brain const &rRhs);
};

#endif // BRAIN_HPP
