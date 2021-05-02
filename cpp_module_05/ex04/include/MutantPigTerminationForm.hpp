/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantPigTerminationForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:24:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 09:47:55 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_PIG_TERMINATION_FORM_HPP
# define MUTANT_PIG_TERMINATION_FORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "colors.hpp"

class								MutantPigTerminationForm : public AForm
{
	public:

		std::string const			&getTarget(void) const;

									MutantPigTerminationForm(std::string const &rTarget);
									MutantPigTerminationForm(MutantPigTerminationForm const &rSrc);
									~MutantPigTerminationForm(void);

		MutantPigTerminationForm	&operator=(MutantPigTerminationForm const &rRhs);

	protected:

		void						_exec(void) const;

	private:

		std::string					_target;

									MutantPigTerminationForm(void);
};

#endif // MUTANT_PIG_TERMINATION_FORM_HPP
