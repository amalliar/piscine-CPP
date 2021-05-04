/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstPeriod.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:34:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:25:57 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_PERIOD_HPP
# define INST_PERIOD_HPP

# include <iostream>
# include "AInstruction.hpp"

class				Interpreter;

class				InstPeriod : public AInstruction
{
	public:

		void		exec(void) const;

					InstPeriod(Interpreter &rInterpreter);
					~InstPeriod(void);

	private:

					InstPeriod(InstPeriod const &rSrc);

		InstPeriod	&operator=(InstPeriod const &rRhs);
};

#endif // INST_PERIOD_HPP
