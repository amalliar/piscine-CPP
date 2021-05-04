/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstSqBrackCl.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:26:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_SQ_BRACK_CL_HPP
# define INST_SQ_BRACK_CL_HPP

# include "AInstruction.hpp"

class					Interpreter;

class					InstSqBrackCl : public AInstruction
{
	public:

		void			exec(void) const;

						InstSqBrackCl(Interpreter &rInterpreter);
						~InstSqBrackCl(void);

	private:

						InstSqBrackCl(InstSqBrackCl const &rSrc);

		InstSqBrackCl	&operator=(InstSqBrackCl const &rRhs);
};

#endif // INST_SQ_BRACK_CL_HPP
