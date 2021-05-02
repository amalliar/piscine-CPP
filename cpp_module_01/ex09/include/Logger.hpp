/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:24:04 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:15:00 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <ctime>

class						Logger;

typedef struct				s_action
{
	std::string				name;
	int						(Logger::*func)(std::string const &msg) const;
}							t_action;

class						Logger
{
	public:

		static size_t const	numActs = 2;
		static t_action		actMap[numActs];

		int					log(std::string const &rDest, std::string const &rMsg) const;

							Logger(std::string const &rOfile);
							Logger(Logger const &rSrc);
							~Logger(void);

		Logger				&operator=(Logger const &rRhs);

	private:

		std::string	const	_oFile;

		std::string			_makeLogEntry(std::string const &rMsg) const;
		int					_logToConsole(std::string const &rLogEntry) const;
		int					_logToFile(std::string const &rLogEntry) const;

							Logger(void);
};

#endif // LOGGER_HPP
