/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstPlus.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:26:25 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_PLUS_HPP
# define INST_PLUS_HPP

# include "AInstruction.hpp"

class				Interpreter;

class				InstPlus : public AInstruction
{
	public:

		void		exec(void) const;

					InstPlus(Interpreter &rInterpreter);
					~InstPlus(void);

	private:

					InstPlus(InstPlus const &rSrc);

		InstPlus	&operator=(InstPlus const &rRhs);
};

#endif // INST_PLUS_HPP
