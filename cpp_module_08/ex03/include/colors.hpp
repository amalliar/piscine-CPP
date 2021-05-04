/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:00:18 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/14 12:00:21 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# define CLR_BLACK(msg)		("\033[0;30m" #msg "\033[0m")
# define CLR_BBLACK(msg)	("\033[1;30m" #msg "\033[0m")
# define CLR_RED(msg)		("\033[0;31m" #msg "\033[0m")
# define CLR_BRED(msg)		("\033[1;31m" #msg "\033[0m")
# define CLR_GREEN(msg)		("\033[0;32m" #msg "\033[0m")
# define CLR_BGREEN(msg)	("\033[1;32m" #msg "\033[0m")
# define CLR_YELLOW(msg)	("\033[0;33m" #msg "\033[0m")
# define CLR_BYELLOW(msg)	("\033[1;33m" #msg "\033[0m")
# define CLR_BLUE(msg)		("\033[0;34m" #msg "\033[0m")
# define CLR_BBLUE(msg)		("\033[1;34m" #msg "\033[0m")
# define CLR_PURPLE(msg)	("\033[0;35m" #msg "\033[0m")
# define CLR_BPURPLE(msg)	("\033[1;35m" #msg "\033[0m")
# define CLR_CYAN(msg)		("\033[0;36m" #msg "\033[0m")
# define CLR_BCYAN(msg)		("\033[1;36m" #msg "\033[0m")
# define CLR_WHITE(msg)		("\033[0;37m" #msg "\033[0m")
# define CLR_BWHITE(msg)	("\033[1;37m" #msg "\033[0m")

# include <string>

std::string		clr_black(std::string const &msg);
std::string		clr_bblack(std::string const &msg);
std::string		clr_red(std::string const &msg);
std::string		clr_bred(std::string const &msg);
std::string		clr_green(std::string const &msg);
std::string		clr_bgreen(std::string const &msg);
std::string		clr_yellow(std::string const &msg);
std::string		clr_byellow(std::string const &msg);
std::string		clr_blue(std::string const &msg);
std::string		clr_bblue(std::string const &msg);
std::string		clr_purple(std::string const &msg);
std::string		clr_bpurple(std::string const &msg);
std::string		clr_cyan(std::string const &msg);
std::string		clr_bcyan(std::string const &msg);
std::string		clr_white(std::string const &msg);
std::string		clr_bwhite(std::string const &msg);

#endif // COLORS_HPP
