/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstLess.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:21:51 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_LESS_HPP
# define INST_LESS_HPP

# include "AInstruction.hpp"

class				Interpreter;

class				InstLess : public AInstruction
{
	public:

		void		exec(void) const;

					InstLess(Interpreter &rInterpreter);
					~InstLess(void);

	private:

					InstLess(InstLess const &rSrc);

		InstLess	&operator=(InstLess const &rRhs);
};

#endif // INST_LESS_HPP
