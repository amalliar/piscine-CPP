/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:10:36 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/27 06:48:30 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

static bool		ischar(std::string const &rArg)
{
	if (rArg.length() == 3 && rArg[0] == rArg[2] && rArg[2] == '\'')
		return (true);
	return (false);
}

static bool		isint(std::string const &rArg)
{
	size_t	idx;

	try
	{
		std::stoi(rArg, &idx);
		if (rArg.length() != idx)
			return (false);
	}
	catch (std::invalid_argument &ia)
	{
		return (false);
	}
	catch (std::out_of_range &oor) {}
	return (true);
}

static bool		isfloat(std::string rArg)
{
	size_t	idx;

	try
	{
		if (rArg.back() != 'f')
			return (false);
		rArg.pop_back();
		std::stof(rArg, &idx);
		if (rArg.length() != idx || \
			(rArg.find('.') == std::string::npos && \
			rArg.find("inf") == std::string::npos && \
			rArg.find("nan") == std::string::npos))
			return (false);
	}
	catch (std::invalid_argument &ia)
	{
		return (false);
	}
	catch (std::out_of_range &oor) {}
	return (true);
}

static bool		isdouble(std::string const &rArg)
{
	size_t	idx;

	try
	{
		std::stod(rArg, &idx);
		if (rArg.length() != idx || \
			(rArg.find('.') == std::string::npos && \
			rArg.find("inf") == std::string::npos && \
			rArg.find("nan") == std::string::npos))
			return (false);
	}
	catch (std::invalid_argument &ia)
	{
		return (false);
	}
	catch (std::out_of_range &oor) {}
	return (true);
}

static void		conv_from_char(std::string const &rArg)
{
	char	c;

	c = rArg[1];
	std::cout << "char: ";
	if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void		conv_from_int(std::string const &rArg)
					throw (std::out_of_range)
{
	int		i;

	i = std::stoi(rArg);
	std::cout << "char: ";
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void		conv_from_float(std::string rArg)
					throw (std::out_of_range)
{
	float	f;

	rArg.pop_back();
	f = std::stof(rArg);
	std::cout << "char: ";
	if (std::isnan(f) || f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(f)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: ";
	if (std::isnan(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void		conv_from_double(std::string const &rArg)
					throw (std::out_of_range)
{
	double		d;

	d = std::stod(rArg);
	std::cout << "char: ";
	if (std::isnan(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: ";
	if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (!std::isnan(d) && !std::isinf(d) && (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void		convert(std::string const arg)
{
	std::cout << std::fixed << std::setprecision(1);
	try
	{
		if (ischar(arg))
			conv_from_char(arg);
		else if (isint(arg))
			conv_from_int(arg);
		else if (isfloat(arg))
			conv_from_float(arg);
		else if (isdouble(arg))
			conv_from_double(arg);
		else
			std::cout << "convert: unknown type: " << arg << std::endl;
	}
	catch (std::out_of_range &oor)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

int				main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "usage: convert [value ...]" << std::endl;
		return (2);
	}
	for (int i = 1; i < argc; ++i)
	{
		if (std::strlen(argv[i]))
		{
			if (argc > 2)
				std::cout << "==> " << argv[i] << " <==" << std::endl;
			convert(argv[i]);
		}
		if (i + 1 < argc && std::strlen(argv[i + 1]))
			std::cout << std::endl;
	}
	return (0);
}
