/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 04:08:54 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/21 22:13:05 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int				Fixed::getRawBits(void) const
{
	return (this->_value);
}

void			Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int				Fixed::toInt(void) const
{
	return (this->_value >> this->_fractBits);
}

float			Fixed::toFloat(void) const
{
	// Shift the fixed point _fractBits positions to the left
	// so that the fractional part is actually fractional.
	return ((float)this->_value / (1 << _fractBits));
}

Fixed			&Fixed::min(Fixed &rLhs, Fixed &rRhs)
{
	return ((rLhs < rRhs) ? rLhs : rRhs);
}

Fixed const		&Fixed::min(Fixed const &rLhs, Fixed const &rRhs)
{
	return ((rLhs < rRhs) ? rLhs : rRhs);
}

Fixed			&Fixed::max(Fixed &rLhs, Fixed &rRhs)
{
	return ((rLhs > rRhs) ? rLhs : rRhs);
}

Fixed const		&Fixed::max(Fixed const &rLhs, Fixed const &rRhs)
{
	return ((rLhs > rRhs) ? rLhs : rRhs);
}

				Fixed::Fixed(void) :
				_value(0)
{
}

				Fixed::Fixed(Fixed const &rSrc) :
				_value(rSrc._value)
{
}

				Fixed::Fixed(int const iNum)
{
	this->_value = iNum << _fractBits;
}

				Fixed::Fixed(float const fNum)
{
	// Shift the fixed point _fractBits positions to the right
	// so that the fractional part is now integer.
	this->_value = roundf(fNum * (1 << _fractBits));
}

				Fixed::~Fixed(void)
{
}

Fixed			&Fixed::operator=(Fixed const &rRhs)
{
	this->_value = rRhs._value;
	return (*this);
}

bool			Fixed::operator>(Fixed const &rRhs) const
{
	return (this->_value > rRhs._value);
}

bool			Fixed::operator<(Fixed const &rRhs) const
{
	return (this->_value < rRhs._value);
}

bool			Fixed::operator>=(Fixed const &rRhs) const
{
	return (this->_value >= rRhs._value);
}

bool			Fixed::operator<=(Fixed const &rRhs) const
{
	return (this->_value <= rRhs._value);
}

bool			Fixed::operator==(Fixed const &rRhs) const
{
	return (this->_value == rRhs._value);
}

bool			Fixed::operator!=(Fixed const &rRhs) const
{
	return (this->_value != rRhs._value);
}

Fixed			Fixed::operator+(Fixed const &rRhs) const
{
	Fixed	tmp;

	tmp._value = this->_value + rRhs._value;
	return (tmp);
}

Fixed			Fixed::operator-(Fixed const &rRhs) const
{
	Fixed	tmp;

	tmp._value = this->_value - rRhs._value;
	return (tmp);
}

Fixed			Fixed::operator*(Fixed const &rRhs) const
{
	return (Fixed(this->toFloat() * rRhs.toFloat()));
}

Fixed			Fixed::operator/(Fixed const &rRhs) const
{
	return (Fixed(this->toFloat() / rRhs.toFloat()));
}

Fixed			Fixed::operator++(void)  // Prefix form.
{
	++this->_value;
	return (Fixed(*this));
}

Fixed			Fixed::operator++(int)  // Postfix form.
{
	Fixed	tmp(*this);

	++this->_value;
	return (tmp);
}

Fixed			Fixed::operator--(void)
{
	--this->_value;
	return (Fixed(*this));
}

Fixed			Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--this->_value;
	return (tmp);
}

std::ostream	&operator<<(std::ostream &rOs, Fixed const &rRhs)
{
	rOs << rRhs.toFloat();
	return (rOs);
}
