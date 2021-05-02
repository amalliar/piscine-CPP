/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:24:35 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:15:21 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

t_action		Logger::actMap[] =
{
	{"logToConsole", &Logger::_logToConsole},
	{"logToFile", &Logger::_logToFile}
};

int				Logger::log(std::string const &rDest, std::string const &rMsg) const
{
	std::string		log_entry = _makeLogEntry(rMsg);
	size_t			i;

	for (i = 0; i < numActs; ++i)
		if (!rDest.compare(actMap[i].name))
			return ((this->*actMap[i].func)(log_entry));
	return (1);
}

				Logger::Logger(std::string const &rOfile) :
				_oFile(rOfile + ".log")
{
}

				Logger::Logger(Logger const &rSrc) :
				_oFile(rSrc._oFile)
{
}

				Logger::~Logger(void)
{
}

Logger			&Logger::operator=(Logger const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}

std::string		Logger::_makeLogEntry(std::string const &rMsg) const
{
	std::string		log_entry;
	time_t			rawtime;
	struct tm 		*timeinfo;
  	char 			buffer[32];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 32, "[%Y%m%d_%H%M%S] ",timeinfo);
	log_entry = buffer + rMsg + "\n";
	return (log_entry);
}

int				Logger::_logToConsole(std::string const &rLogEntry) const
{
	return (!(std::cout << rLogEntry));
}

int				Logger::_logToFile(std::string const &rLogEntry) const
{
	std::ofstream 	ofs;

	ofs.open(_oFile, std::ofstream::app);
	ofs << rLogEntry;
	ofs.close();
	return (!ofs.good());
}

				Logger::Logger(void) :
				_oFile("logger")
{
}
