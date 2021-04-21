/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 00:28:40 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 19:16:32 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class						Human;

typedef struct				s_action
{
	std::string				name;
	void					(Human::*func)(std::string const &rTarget);
}							t_action;

class						Human
{
	public:
		static size_t const	numActs = 3;
		static t_action		actMap[numActs];

		void 				action(std::string const &rActionName, std::string const &rTarget);

							Human(std::string const &rName);
							Human(Human const &rSrc);
							~Human(void);
		Human				&operator=(Human const &rRhs);

	private:
		std::string			_name;

		void				_meleeAttack(std::string const &rTarget);
		void 				_rangedAttack(std::string const &rTarget);
		void 				_intimidatingShout(std::string const &rTarget);

							Human(void);
};

#endif // HUMAN_HPP
