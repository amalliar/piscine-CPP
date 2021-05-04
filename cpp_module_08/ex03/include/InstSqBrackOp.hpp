/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstSqBrackOp.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:27:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_SQ_BRACK_OP_HPP
# define INST_SQ_BRACK_OP_HPP

# include "AInstruction.hpp"

class					Interpreter;

class					InstSqBrackOp : public AInstruction
{
	public:

		void			exec(void) const;

						InstSqBrackOp(Interpreter &rInterpreter);
						~InstSqBrackOp(void);

	private:

						InstSqBrackOp(InstSqBrackOp const &rSrc);

		InstSqBrackOp	&operator=(InstSqBrackOp const &rRhs);
};

#endif // INST_SQ_BRACK_OP_HPP
