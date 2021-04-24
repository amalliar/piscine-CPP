/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:29:51 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 03:28:38 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <cstddef>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

typedef struct			s_list
{
		void			*pData;
		struct s_list	*pNext;
}						t_list;

class					Squad : public ISquad
{
	public:
		int				getCount(void) const;
		ISpaceMarine	*getUnit(int idx) const;
		int				push(ISpaceMarine *pSpMarine);

						Squad(void);
						Squad(Squad const &rSrc);
						~Squad(void);
		Squad			&operator=(Squad const &rRhs);

	protected:
		int				_count;
		t_list			*_pBeginList;

		void			_lstClear(void);
};

#endif // SQUAD_HPP
