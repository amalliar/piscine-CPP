/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 04:08:54 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:18:27 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int				Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void			Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int				Fixed::toInt(void) const
{
	return (_value >> _fractBits);
}

float			Fixed::toFloat(void) const
{
	// Shift the fixed point _fractBits positions to the left
	// so that the fractional part is actually fractional.
	return ((float)_value / (1 << _fractBits));
}

				Fixed::Fixed(void) :
				_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

				Fixed::Fixed(Fixed const &rSrc) :
				_value(rSrc._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

				Fixed::Fixed(int const iNum)
{
	std::cout << "Int constructor called" << std::endl;
	_value = iNum << _fractBits;
}

				Fixed::Fixed(float const fNum)
{
	std::cout << "Float constructor called" << std::endl;

	// Shift the fixed point _fractBits positions to the right
	// so that the fractional part is now integer.
	_value = roundf(fNum * (1 << _fractBits));
}

				Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed			&Fixed::operator=(Fixed const &rRhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rRhs)
	{
		_value = rRhs._value;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &rOs, Fixed const &rRhs)
{
	rOs << rRhs.toFloat();
	return (rOs);
}
