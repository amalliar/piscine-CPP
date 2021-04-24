/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:00:18 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/11 14:26:38 by amalliar         ###   ########.fr       */
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

#endif // COLORS_HPP
