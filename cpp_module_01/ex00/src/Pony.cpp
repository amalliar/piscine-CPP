/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:12:27 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 16:50:54 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void			Pony::drawAscii(void) const
{
	std::cout << _asciiColorFmtString << \
"                               -.\n"
"                              |  \\\n"
"                              |   \\\n"
"                              F    L\n"
"                |'-._         F    L\n"
"                |  `.`--.     L    |\n"
"                J    `.  `.   |    |   __\n"
"                 \\     `.  `. J    |.-'_.-\n"
"                  \\      `.  \\ \\.-     `-. \n"
"     J'.           `.      \\  >'          `.\n"
"     |  \\            `-.    L/       `---.._\\\n"
"     J   L              `'-/               |\n"
"      \\  |                J        / .-.   4\n"
"       J F                |       | / d8   |\n"
"        L\\                F         | 8P   J\n"
"        J L               |         `-'     `-.\n"
"        | |                L  .          .-    )\n"
"        | J                |   \\        . dP  / \n"
"        J  \\               |    `.       `-.-'\n"
"         \\  >-''''-.      .F      >'--.---._) \n"
"          >'        ''--''        |\n"
"         J                        F\n"
"         |                        L\n"
"         J                        |\n"
"          \\        L         `.   J\n"
"           )       | % |      | eJ' u+L\n"
"          d'      d'  '|     :Fd'     4\n"
"         P      u$'b.  $r    $*L u@'.  F\n"
"         $  ?F'' 4L ^F''$   F      zP $\n"
"         4F  N    *. %. ^  4     $#  zF\n"
"          #r '.    $  $ $  $   $$F :'\n"
"          -F  $    ^k Jr@F $   $$$'\n"
"           #. F     9$$$9  4\n"
"           '$$$          $  *\n"
"             ^'          3ed$.\n"
"                          $$$#'\n"
"\033[0m" << std::endl;
}

int				Pony::setAsciiColor(std::string const &rColor)
{
	std::string		lowc = _strToLower(rColor);

	if (!lowc.compare("black"))
		_asciiColorFmtString = "\033[0;30m";
	else if (!lowc.compare("b_black"))
		_asciiColorFmtString = "\033[1;30m";
	else if (!lowc.compare("red"))
		_asciiColorFmtString = "\033[0;31m";
	else if (!lowc.compare("b_red"))
		_asciiColorFmtString = "\033[1;31m";
	else if (!lowc.compare("green"))
		_asciiColorFmtString = "\033[0;32m";
	else if (!lowc.compare("b_green"))
		_asciiColorFmtString = "\033[1;32m";
	else if (!lowc.compare("yellow"))
		_asciiColorFmtString = "\033[0;33m";
	else if (!lowc.compare("b_yellow"))
		_asciiColorFmtString = "\033[1;33m";
	else if (!lowc.compare("blue"))
		_asciiColorFmtString = "\033[0;34m";
	else if (!lowc.compare("b_blue"))
		_asciiColorFmtString = "\033[1;34m";
	else if (!lowc.compare("purple"))
		_asciiColorFmtString = "\033[0;35m";
	else if (!lowc.compare("b_purple"))
		_asciiColorFmtString = "\033[1;35m";
	else if (!lowc.compare("cyan"))
		_asciiColorFmtString = "\033[0;36m";
	else if (!lowc.compare("b_cyan"))
		_asciiColorFmtString = "\033[1;36m";
	else if (!lowc.compare("white"))
		_asciiColorFmtString = "\033[0;37m";
	else if (!lowc.compare("b_white"))
		_asciiColorFmtString = "\033[1;37m";
	else if (!lowc.compare("noc"))
		_asciiColorFmtString = "\033[0m";
	else
		return (-1);
	return (0);
}

				Pony::Pony(void)
{
	int 	stack;

	_memType = _getMemType(&stack);
	if (!_memType.compare("stack"))
		setAsciiColor("b_red");
	else
		setAsciiColor("b_blue");
	std::cout << "Pony on the " << _memType << " was born." << std::endl;
}

				Pony::Pony(Pony const &rSrc)
{
	static_cast<void>(rSrc);
}

				Pony::~Pony(void)
{
	std::cout << "Pony on the " << _memType << " died." << std::endl;
}

Pony			&Pony::operator=(Pony const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}

std::string		Pony::_getMemType(void *pStack) const
{
	int		stack;

	if ((pStack < static_cast<void *>(&stack)) == \
		(reinterpret_cast<void const *>(this) < static_cast<void *>(&stack)))
		return ("stack");
	return ("heap");
}

std::string		Pony::_strToLower(std::string const str) const
{
	std::string		lowc = str;

	for (unsigned i = 0; i < lowc.length(); ++i)
		lowc[i] = std::tolower(lowc[i]);
	return (lowc);
}
