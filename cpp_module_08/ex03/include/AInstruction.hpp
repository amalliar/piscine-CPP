/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AInstruction.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:33:53 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:23:15 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_INSTRUCTION_HPP
# define A_INSTRUCTION_HPP

class						Interpreter;

class						AInstruction
{
	public:

		char				type;

		virtual void		exec(void) const = 0;

							AInstruction(Interpreter &rInterpreter);
		virtual				~AInstruction(void);

	protected:

		Interpreter			&_rInterpreter;

							AInstruction(AInstruction const &rSrc);

		AInstruction		&operator=(AInstruction const &rRhs);
};

#endif // A_INSTRUCTION_HPP
