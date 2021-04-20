/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:02:14 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 08:49:41 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <locale>

class						Contact
{
	public:
		int					setFirstName(std::string const &rFirstName);
		int					setLastName(std::string const &rLastName);
		int					setNickname(std::string const &rNickname);
		int					setLogin(std::string const &rLogin);
		int					setPostalAddress(std::string const &rPostalAddr);
		int					setEmailAddress(std::string const &rEmailAddr);
		int					setPhoneNumber(std::string const &rPhoneNbr);
		int					setBirthdayDate(std::string const &rBdayDate);
		int					setFavoriteMeal(std::string const &rFavMeal);
		int					setUnderwearColor(std::string const &rUnderwearClr);
		int					setDarkestSecret(std::string const &rDarkestSecret);
		std::string	const	&getFirstName(void) const;
		std::string	const	&getLastName(void) const;
		std::string	const	&getNickname(void) const;
		std::string	const	&getLogin(void) const;
		std::string	const	&getPostalAddress(void) const;
		std::string	const	&getEmailAddress(void) const;
		std::string	const	&getPhoneNumber(void) const;
		std::string	const	&getBirthdayDate(void) const;
		std::string	const	&getFavoriteMeal(void) const;
		std::string	const	&getUnderwearColor(void) const;
		std::string	const	&getDarkestSecret(void) const;

							Contact(void);
							Contact(Contact const &rSrc);
							~Contact(void);
		Contact				&operator=(Contact const &rRhs);

private:
		std::string			_firstName;
		std::string			_lastName;
		std::string			_nickname;
		std::string			_login;
		std::string			_postalAddress;
		std::string			_emailAddress;
		std::string			_phoneNumber;
		std::string			_birthdayDate;
		std::string			_favoriteMeal;
		std::string			_underwearColor;
		std::string			_darkestSecret;

		bool				_strIsAlpha(std::string const &rStr) const;
		bool				_strIsDigit(std::string const &rStr) const;
		bool				_strIsAlnum(std::string const &rStr) const;
		bool				_strIsAlSpace(std::string const &rStr) const;
		bool				_strIsPalSpace(std::string const &rStr) const;
		bool				_strIsEmailFormat(std::string const &rStr) const;
		bool				_strIsDateFormat(std::string const &rStr) const;
};

#endif // CONTACT_HPP
