/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:39:27 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/04 15:27:36 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

# include <exception>
# include <map>
# include <stack>
# include <string>
# include <vector>
# include "InstPlus.hpp"
# include "InstMinus.hpp"
# include "InstGreater.hpp"
# include "InstLess.hpp"
# include "InstPeriod.hpp"
# include "InstComma.hpp"
# include "InstSqBrackOp.hpp"
# include "InstSqBrackCl.hpp"

class								AInstruction;

class								Interpreter
{
	public:

		typedef std::vector<char>					cells_t;
		typedef std::vector<AInstruction const *>	instructions_t;

		void						setInput(std::string const &rInput)
										throw (UnmatchedSqBrackOpException,
												UnmatchedSqBrackClException);
		void						execute(void);
		
									Interpreter(void);
									Interpreter(std::string const &rInput)
										throw (UnmatchedSqBrackOpException,
												UnmatchedSqBrackClException);
									~Interpreter(void);

		class						UnmatchedSqBrackOpException : public std::exception
		{
			public:

				virtual const char	*what() const throw ();
		};
		class						UnmatchedSqBrackClException : public std::exception
		{
			public:

				virtual const char	*what() const throw ();
		};

	private:

		cells_t						_cells;
		cells_t::iterator			_cellPointer;
		instructions_t				_instructions;
		instructions_t::iterator	_instPointer;

		//	Instruction classes are so tightly coupled with Interpreter
		//	that it just makes sense to mark them as friends of this class.

		friend class				InstPlus;
		friend class				InstMinus;
		friend class				InstGreater;
		friend class				InstLess;
		friend class				InstPeriod;
		friend class				InstComma;
		friend class				InstSqBrackOp;
		friend class				InstSqBrackCl;

		InstPlus const				_instPlus;
		InstMinus const				_instMinus;
		InstGreater const			_instGreater;
		InstLess const				_instLess;
		InstPeriod const			_instPeriod;
		InstComma const				_instComma;
		InstSqBrackOp const			_instSqBrackOp;
		InstSqBrackCl const			_instSqBrackCl;

		std::map<size_t, size_t>	_sqBrackLookupMap;

		void						_buildSqBrackLookupMap(void)
										throw (UnmatchedSqBrackOpException,
												UnmatchedSqBrackClException);
		void						_clear(void);

									Interpreter(Interpreter const &rSrc);
		Interpreter					&operator=(Interpreter const &rRhs);
};

#endif // INTERPRETER_HPP
