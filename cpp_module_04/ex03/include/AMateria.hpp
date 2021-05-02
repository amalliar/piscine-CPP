/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:26:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:09:50 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>

class						ICharacter;

class						AMateria
{
	public:

		std::string const	&getType(void) const;
		unsigned int		getXP(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &rTarget);

							AMateria(std::string const &rType);
							AMateria(AMateria const &rSrc);
		virtual				~AMateria(void);

		AMateria			&operator=(AMateria const &rRhs);

	protected:

		std::string			_type;
		unsigned int		_xp;

							AMateria(void);
};

#endif // A_MATERIA_HPP
