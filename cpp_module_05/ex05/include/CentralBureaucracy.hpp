/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:12:01 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/28 06:34:00 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRAL_BUREAUCRACY_HPP
# define CENTRAL_BUREAUCRACY_HPP

# include <cstddef>
# include <cstdlib>
# include <exception>
# include <list>
# include <queue>
# include <string>
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "OfficeBlock.hpp"

class							CentralBureaucracy
{
	public:
		void					feedBureaucrat(Bureaucrat const &rBureaucrat)
									throw (SameObjectRefException, BureaucracyIsFullException);
		void					queueUp(std::string const &rTarget);
		void					doBureaucracy(void)
									throw (NoFilledOfficeBlocksException);

								CentralBureaucracy(void);
								~CentralBureaucracy(void);

		class					SameObjectRefException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class					BureaucracyIsFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class					NoFilledOfficeBlocksException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		static const size_t		_numOfficeBlocks = 20;
		size_t					_numFilledOfficeBlocks;
		OfficeBlock				_officeBlocks[_numOfficeBlocks];
		std::list<Intern>		_internList;
		std::queue<std::string>	_targetQueue;

		Intern const			&_generateIntern(void);

								CentralBureaucracy(CentralBureaucracy const &rSrc);
		CentralBureaucracy		&operator=(CentralBureaucracy const &rRhs);
};

#endif // CENTRAL_BUREAUCRACY_HPP
