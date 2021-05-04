/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstGreater.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:21:57 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_GREATER_HPP
# define INST_GREATER_HPP

# include "AInstruction.hpp"

class				Interpreter;

class				InstGreater : public AInstruction
{
	public:

		void		exec(void) const;

					InstGreater(Interpreter &rInterpreter);
					~InstGreater(void);

	private:

					InstGreater(InstGreater const &rSrc);

		InstGreater	&operator=(InstGreater const &rRhs);
};

#endif // INST_GREATER_HPP
