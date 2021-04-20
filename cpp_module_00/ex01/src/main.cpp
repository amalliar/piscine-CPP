/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:37:29 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 19:57:42 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

#define NUM_CONTACTS	8

static void		set_attr(Contact &rCont, int (Contact::*pFunc)(std::string const &rArg), \
					char const *pMsg, char const *pErrMsg)
{
	std::string		input;

	std::cout << pMsg;
	while (std::getline(std::cin, input))
	{
		if ((rCont.*pFunc)(input))
			std::cout << pErrMsg << std::endl;
		else
			return ;
		std::cout << pMsg;
	}
	exit(EXIT_SUCCESS);
}

static void		add_contact(Contact conts[])
{
	static int		next_free = 0;
	std::string		input;
	
	if (next_free == NUM_CONTACTS)
	{
		std::cout << "Phone book is full" << std::endl;
		return ;
	}
	set_attr(conts[next_free], &Contact::setFirstName, "First name: ", "Invalid argument: should only contain letters");
	set_attr(conts[next_free], &Contact::setLastName, "Last name: ", "Invalid argument: should only contain letters");
	set_attr(conts[next_free], &Contact::setNickname, "Nickname: ", "Invalid argument: should only contain letters");
	set_attr(conts[next_free], &Contact::setLogin, "Login: ", "Invalid argument: should only contain letters and digits");
	set_attr(conts[next_free], &Contact::setPostalAddress, "Postal address: ", "Invalid argument: should not be an empty string");
	set_attr(conts[next_free], &Contact::setEmailAddress, "Email address: ", "Invalid argument: should contain '@' and '.'");
	set_attr(conts[next_free], &Contact::setPhoneNumber, "Phone number: ", "Invalid argument: should only contain eleven digits");
	set_attr(conts[next_free], &Contact::setBirthdayDate, "Birthday date: ", "Invalid argument: should be a string of format dd.mm.yyyy");
	set_attr(conts[next_free], &Contact::setFavoriteMeal, "Favorite meal: ", "Invalid argument: should only contain letters or spaces");
	set_attr(conts[next_free], &Contact::setUnderwearColor, "Underwear color: ", "Invalid argument: should only contain letters or spaces");
	set_attr(conts[next_free], &Contact::setDarkestSecret, "Darkest secret: ", "Invalid argument: should only contain letters or spaces");
	++next_free;
}

static void		print_entry(std::string const &s0, std::string const &s1, std::string const &s2, std::string const &s3)
{
	if (s0.length() <= 10)
		std::cout << std::setw(10) << std::right << s0.substr(0, 10) << "|";
	else
		std::cout << s0.substr(0, 9) << ".|";
	if (s1.length() <= 10)
		std::cout << std::setw(10) << std::right << s1.substr(0, 10) << "|";
	else
		std::cout << s1.substr(0, 9) << ".|";
	if (s2.length() <= 10)
		std::cout << std::setw(10) << std::right << s2.substr(0, 10) << "|";
	else
		std::cout << s2.substr(0, 9) << ".|";
	if (s3.length() <= 10)
		std::cout << std::setw(10) << std::right << s3.substr(0, 10) << std::endl;
	else
		std::cout << s3.substr(0, 9) << "." << std::endl;
}

static void		list_contacts(Contact const conts[])
{
	std::string		data;
	int				i = 0;

	print_entry("Index", "First Name", "Last Name", "Nickname");
	while (i < NUM_CONTACTS && !conts[i].getFirstName().empty())
	{
		print_entry(std::to_string(i), conts[i].getFirstName(), conts[i].getLastName(), conts[i].getNickname());
		++i;
	}
}

static void		display_contact(Contact const &cont)
{
	std::cout << "First name: " << cont.getFirstName() << std::endl;
	std::cout << "Last name: " << cont.getLastName() << std::endl;
	std::cout << "Nickname: " << cont.getNickname() << std::endl;
	std::cout << "Login : " << cont.getLogin() << std::endl;
	std::cout << "Postal address : " << cont.getPostalAddress() << std::endl;
	std::cout << "Email address : " << cont.getEmailAddress() << std::endl;
	std::cout << "Phone number : " << cont.getPhoneNumber() << std::endl;
	std::cout << "Birthday date : " << cont.getBirthdayDate() << std::endl;
	std::cout << "Favorite meal : " << cont.getFavoriteMeal() << std::endl;
	std::cout << "Underwear color : " << cont.getUnderwearColor() << std::endl;
	std::cout << "Darkest secret : " << cont.getDarkestSecret() << std::endl;
}

static void		search_contact(Contact const conts[])
{
	std::string		input;
	std::locale		loc;
	int				idx;

	if (conts[0].getFirstName().empty())
	{
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}
	list_contacts(conts);
	std::cout << "Index: ";
	while (std::getline(std::cin, input))
	{
		try
		{
			if (!std::isdigit(input[0], loc) || (idx = std::stoi(input)) > 7 || \
				conts[idx].getFirstName().empty())
				std::cout << "Invalid argument" << std::endl;
			else
			{
				display_contact(conts[idx]);
				return ;
			}
		}
		catch (...)
		{
			std::cout << "Invalid argument" << std::endl;
		}
		std::cout << "Index: ";
	}
	exit(EXIT_SUCCESS);
}

int				main(int argc, char **argv)
{
	Contact			conts[NUM_CONTACTS];
	std::string		input;

	std::cout << argv[0] << "> ";
	while (std::getline(std::cin, input))
	{
		if (!input.compare("ADD"))
			add_contact(conts);
		else if (!input.compare("SEARCH"))
			search_contact(conts);
		else if (!input.compare("EXIT"))
			break;
		std::cout << argv[0] << "> ";
	}
	static_cast<void>(argc);
	return (0);
}
