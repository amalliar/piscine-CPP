/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:01:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 16:45:35 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int					Contact::setFirstName(std::string const &rFirstName)
{
	if (rFirstName.empty() || !_strIsAlpha(rFirstName))
		return (1);
	_firstName = rFirstName;
	return (0);
}

int					Contact::setLastName(std::string const &rLastName)
{
	if (rLastName.empty() || !_strIsAlpha(rLastName))
		return (1);
	_lastName = rLastName;
	return (0);
}

int					Contact::setNickname(std::string const &rNickname)
{
	if (rNickname.empty() || !_strIsAlnum(rNickname))
		return (1);
	_nickname = rNickname;
	return (0);
}

int					Contact::setLogin(std::string const &rLogin)
{
	if (rLogin.empty() || !_strIsAlnum(rLogin))
		return (1);
	_login = rLogin;
	return (0);
}

int					Contact::setPostalAddress(std::string const &rPostalAddr)
{
	if (rPostalAddr.empty())
		return (1);
	_postalAddress = rPostalAddr;
	return (0);
}

int					Contact::setEmailAddress(std::string const &rEmailAddr)
{
	if (rEmailAddr.empty() || !_strIsEmailFormat(rEmailAddr))
		return (1);
	_emailAddress = rEmailAddr;
	return (0);
}

int					Contact::setPhoneNumber(std::string const &rPhoneNbr)
{
	if (rPhoneNbr.length() != 11 || !_strIsDigit(rPhoneNbr))
		return (1);
	_phoneNumber = rPhoneNbr;
	return (0);
}

int					Contact::setBirthdayDate(std::string const &rBdayDate)
{
	if (rBdayDate.empty() || !_strIsDateFormat(rBdayDate))
		return (1);
	_birthdayDate = rBdayDate;
	return (0);
}

int					Contact::setFavoriteMeal(std::string const &rFavMeal)
{
	if (rFavMeal.empty() || !_strIsAlSpace(rFavMeal))
		return (1);
	_favoriteMeal = rFavMeal;
	return (0);
}

int					Contact::setUnderwearColor(std::string const &rUnderwearClr)
{
	if (rUnderwearClr.empty() || !_strIsAlSpace(rUnderwearClr))
		return (1);
	_underwearColor = rUnderwearClr;
	return (0);
}

int					Contact::setDarkestSecret(std::string const &rDarkestSecret)
{
	if (rDarkestSecret.empty() || !_strIsPalSpace(rDarkestSecret))
		return (1);
	_darkestSecret = rDarkestSecret;
	return (0);
}

std::string const	&Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	const	&Contact::getLastName(void) const
{
	return (_lastName);
}

std::string const	&Contact::getNickname(void) const
{
	return (_nickname);
}

std::string const	&Contact::getLogin(void) const
{
	return (_login);
}

std::string const	&Contact::getPostalAddress(void) const
{
	return (_postalAddress);
}

std::string	const	&Contact::getEmailAddress(void) const
{
	return (_emailAddress);
}

std::string const	&Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

std::string const	&Contact::getBirthdayDate(void) const
{
	return (_birthdayDate);
}

std::string const	&Contact::getFavoriteMeal(void) const
{
	return (_favoriteMeal);
}

std::string const	&Contact::getUnderwearColor(void) const
{
	return (_underwearColor);
}

std::string const	&Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

					Contact::Contact(void)
{
}

					Contact::Contact(Contact const &rSrc)
{
	*this = rSrc;
}

					Contact::~Contact(void)
{
}

Contact				&Contact::operator=(Contact const &rRhs)
{
	if (this != &rRhs)
	{
		_firstName = rRhs._firstName;
		_lastName = rRhs._lastName;
		_nickname = rRhs._nickname;
		_login = rRhs._login;
		_postalAddress = rRhs._postalAddress;
		_emailAddress = rRhs._emailAddress;
		_phoneNumber = rRhs._phoneNumber;
		_birthdayDate = rRhs._birthdayDate;
		_favoriteMeal = rRhs._favoriteMeal;
		_underwearColor = rRhs._underwearColor;
		_darkestSecret = rRhs._darkestSecret;
	}
	return (*this);
}

bool				Contact::_strIsAlpha(std::string const &str) const
{
	std::locale		loc;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isalpha(*it, loc))
			return (false);
	return (true);
}

bool				Contact::_strIsDigit(std::string const &str) const
{
	std::locale		loc;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isdigit(*it, loc))
			return (false);
	return (true);
}

bool				Contact::_strIsAlnum(std::string const &str) const
{
	std::locale		loc;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isalnum(*it, loc))
			return (false);
	return (true);
}

bool				Contact::_strIsAlSpace(std::string const &str) const
{
	std::locale		loc;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isalpha(*it, loc) && !std::isspace(*it, loc))
			return (false);
	return (true);
}

bool				Contact::_strIsPalSpace(std::string const &str) const
{
	std::locale		loc;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::ispunct(*it, loc) && !std::isalpha(*it, loc) && !std::isspace(*it))
			return (false);
	return (true);
}

bool				Contact::_strIsEmailFormat(std::string const &str) const
{
	std::locale		loc;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isalnum(*it, loc) && *it != '@' && *it != '.')
			return (false);
	if (str.find('@') == std::string::npos || str.find('.') == std::string::npos)
		return (false);
	return (true);
}

bool				Contact::_strIsDateFormat(std::string const &str) const
{
	std::locale				loc;

	if (str.length() != 10 || str[2] != '.' || str[5] != '.')
		return (false);
	if (str[0] > '3' || (str[0] == '3' && str[1] > '1') || \
		str[3] > '1' || (str[3] == '1' && str[4] > '2'))
		return (false);
	return (true);
}
