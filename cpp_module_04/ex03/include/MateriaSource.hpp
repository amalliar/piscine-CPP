/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:55:12 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:15:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include <cstddef>
# include "IMateriaSource.hpp"

class					MateriaSource : public IMateriaSource
{
	public:

		void			learnMateria(AMateria *pAmateria);
		AMateria		*createMateria(std::string const &rType);
		AMateria const	*getAMateria(int idx) const;

						MateriaSource(void);
						MateriaSource(MateriaSource const &rSrc);
						~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &rRhs);

	protected:

		AMateria		*_slots[4];
		int				_idx_free;

		void			_clearSlots(void);
};

#endif // MATERIA_SOURCE_HPP
