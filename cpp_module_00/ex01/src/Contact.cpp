/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:01:57 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 08:44:55 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int					Contact::setFirstName(std::string const &rFirstName)
{
	if (rFirstName.empty() || !this->_strIsAlpha(rFirstName))
		return (1);
	this->_firstName = rFirstName;
	return (0);
}

int					Contact::setLastName(std::string const &rLastName)
{
	if (rLastName.empty() || !this->_strIsAlpha(rLastName))
		return (1);
	this->_lastName = rLastName;
	return (0);
}

int					Contact::setNickname(std::string const &rNickname)
{
	if (rNickname.empty() || !this->_strIsAlnum(rNickname))
		return (1);
	this->_nickname = rNickname;
	return (0);
}

int					Contact::setLogin(std::string const &rLogin)
{
	if (rLogin.empty() || !this->_strIsAlnum(rLogin))
		return (1);
	this->_login = rLogin;
	return (0);
}

int					Contact::setPostalAddress(std::string const &rPostalAddr)
{
	if (rPostalAddr.empty())
		return (1);
	this->_postalAddress = rPostalAddr;
	return (0);
}

int					Contact::setEmailAddress(std::string const &rEmailAddr)
{
	if (rEmailAddr.empty() || !this->_strIsEmailFormat(rEmailAddr))
		return (1);
	this->_emailAddress = rEmailAddr;
	return (0);
}

int					Contact::setPhoneNumber(std::string const &rPhoneNbr)
{
	if (rPhoneNbr.length() != 11 || !this->_strIsDigit(rPhoneNbr))
		return (1);
	this->_phoneNumber = rPhoneNbr;
	return (0);
}

int					Contact::setBirthdayDate(std::string const &rBdayDate)
{
	if (rBdayDate.empty() || !this->_strIsDateFormat(rBdayDate))
		return (1);
	this->_birthdayDate = rBdayDate;
	return (0);
}

int					Contact::setFavoriteMeal(std::string const &rFavMeal)
{
	if (rFavMeal.empty() || !this->_strIsAlSpace(rFavMeal))
		return (1);
	this->_favoriteMeal = rFavMeal;
	return (0);
}

int					Contact::setUnderwearColor(std::string const &rUnderwearClr)
{
	if (rUnderwearClr.empty() || !this->_strIsAlSpace(rUnderwearClr))
		return (1);
	this->_underwearColor = rUnderwearClr;
	return (0);
}

int					Contact::setDarkestSecret(std::string const &rDarkestSecret)
{
	if (rDarkestSecret.empty() || !this->_strIsPalSpace(rDarkestSecret))
		return (1);
	this->_darkestSecret = rDarkestSecret;
	return (0);
}

std::string const	&Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	const	&Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string const	&Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string const	&Contact::getLogin(void) const
{
	return (this->_login);
}

std::string const	&Contact::getPostalAddress(void) const
{
	return (this->_postalAddress);
}

std::string	const	&Contact::getEmailAddress(void) const
{
	return (this->_emailAddress);
}

std::string const	&Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string const	&Contact::getBirthdayDate(void) const
{
	return (this->_birthdayDate);
}

std::string const	&Contact::getFavoriteMeal(void) const
{
	return (this->_favoriteMeal);
}

std::string const	&Contact::getUnderwearColor(void) const
{
	return (this->_underwearColor);
}

std::string const	&Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
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
	this->_firstName = rRhs._firstName;
	this->_lastName = rRhs._lastName;
	this->_nickname = rRhs._nickname;
	this->_login = rRhs._login;
	this->_postalAddress = rRhs._postalAddress;
	this->_emailAddress = rRhs._emailAddress;
	this->_phoneNumber = rRhs._phoneNumber;
	this->_birthdayDate = rRhs._birthdayDate;
	this->_favoriteMeal = rRhs._favoriteMeal;
	this->_underwearColor = rRhs._underwearColor;
	this->_darkestSecret = rRhs._darkestSecret;
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
