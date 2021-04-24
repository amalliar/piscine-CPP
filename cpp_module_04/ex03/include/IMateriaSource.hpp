/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:23:24 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:43:35 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include <string>
# include "AMateria.hpp"

class 						IMateriaSource
{
	public:
		virtual				~IMateriaSource() {}
		virtual void		learnMateria(AMateria *pAmateria) = 0;
		virtual AMateria	*createMateria(std::string const &rType) = 0;
};

#endif // I_MATERIA_SOURCE_HPP
