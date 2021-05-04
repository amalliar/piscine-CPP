/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstMinus.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:25:13 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_MINUS_HPP
# define INST_MINUS_HPP

# include "AInstruction.hpp"

class				Interpreter;

class				InstMinus : public AInstruction
{
	public:

		void		exec(void) const;

					InstMinus(Interpreter &rInterpreter);
					~InstMinus(void);

	private:

					InstMinus(InstMinus const &rSrc);

		InstMinus	&operator=(InstMinus const &rRhs);
};

#endif // INST_MINUS_HPP
