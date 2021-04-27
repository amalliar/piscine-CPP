/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:23:08 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/13 22:13:33 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

std::string	clr_black(std::string const &msg) { return ("\033[0;30m" + msg + "\033[0m"); }
std::string	clr_bblack(std::string const &msg) { return ("\033[1;30m" + msg + "\033[0m"); }
std::string	clr_red(std::string const &msg) { return ("\033[0;31m" + msg + "\033[0m"); }
std::string	clr_bred(std::string const &msg) { return ("\033[1;31m" + msg + "\033[0m"); }
std::string	clr_green(std::string const &msg) { return ("\033[0;32m" + msg + "\033[0m"); }
std::string	clr_bgreen(std::string const &msg) { return ("\033[1;32m" + msg + "\033[0m"); }
std::string	clr_yellow(std::string const &msg) { return ("\033[0;33m" + msg + "\033[0m"); }
std::string	clr_byellow(std::string const &msg) { return ("\033[1;33m" + msg + "\033[0m"); }
std::string	clr_blue(std::string const &msg) { return ("\033[0;34m" + msg + "\033[0m"); }
std::string	clr_bblue(std::string const &msg) { return ("\033[1;34m" + msg + "\033[0m"); }
std::string	clr_purple(std::string const &msg) { return ("\033[0;35m" + msg + "\033[0m"); }
std::string	clr_bpurple(std::string const &msg) { return ("\033[1;35m" + msg + "\033[0m"); }
std::string	clr_cyan(std::string const &msg) { return ("\033[0;36m" + msg + "\033[0m"); }
std::string	clr_bcyan(std::string const &msg) { return ("\033[1;36m" + msg + "\033[0m"); }
std::string	clr_white(std::string const &msg) { return ("\033[0;37m" + msg + "\033[0m"); }
std::string	clr_bwhite(std::string const &msg) { return ("\033[1;37m" + msg + "\033[0m"); }
