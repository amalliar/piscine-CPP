/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstComma.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:24:06 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_COMMA_HPP
# define INST_COMMA_HPP

# include <iostream>
# include "AInstruction.hpp"

class				Interpreter;

class				InstComma : public AInstruction
{
	public:

		void		exec(void) const;

					InstComma(Interpreter &rInterpreter);
					~InstComma(void);

	private:

					InstComma(InstComma const &rSrc);

		InstComma	&operator=(InstComma const &rRhs);
};

#endif // INST_COMMA_HPP
