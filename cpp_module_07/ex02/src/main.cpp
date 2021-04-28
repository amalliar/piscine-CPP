/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:18 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/29 02:27:32 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Array.hpp"
#include "colors.hpp"

template <typename T>
void			print_arr(Array<T> const &rArr, size_t sz)
{
	std::cout << "(" << sz << ") {";
	for (size_t i = 0; i < sz; ++i)
		std::cout << rArr[i] << ((i + 1 < sz) ? ", " : "");
	std::cout << "}" << std::endl;
}

class			Awesome
{
	public:
				Awesome(void) : _n(42) {}
				Awesome(int n) : _n(n) {}
		bool	operator==(Awesome const &rRhs) const { return (this->_n == rRhs._n); }
		bool	operator!=(Awesome const &rRhs) const { return (this->_n != rRhs._n); }
		bool	operator>(Awesome const &rRhs) const { return (this->_n > rRhs._n); }
		bool	operator<(Awesome const &rRhs) const { return (this->_n < rRhs._n); }
		bool	operator>=(Awesome const &rRhs) const { return (this->_n >= rRhs._n); }
		bool	operator<=(Awesome const &rRhs) const { return (this->_n <= rRhs._n); }

		friend std::ostream &operator<<(std::ostream &rOs, Awesome const &rRhs);

	private:
		int		_n;
};

std::ostream	&operator<<(std::ostream &rOs, Awesome const &rRhs) { rOs << rRhs._n; return (rOs); }

int				main(void)
{
	std::cout << std::fixed << std::setprecision(1);

	std::cout << clr_bgreen("==>") << " test_default_int_0" << std::endl << "{" << std::endl;
	Array<> iarr;
	std::cout << "    iarr ";
	print_arr(iarr, iarr.size());
	std::cout << "}" << std::endl << std::endl;

	std::cout << clr_bgreen("==>") << " test_float_4" << std::endl << "{" << std::endl;
	Array<float> farr(4);
	std::cout << "    farr ";
	print_arr(farr, farr.size());
	for (size_t i = 0; i < 4; ++i)
		farr[i] = 42.5;
	std::cout << "    farr ";
	print_arr(farr, farr.size());
	std::cout << "}" << std::endl << std::endl;

	std::cout << clr_bgreen("==>") << " test_arr_assign" << std::endl << "{" << std::endl;
	Array<float> farr2;
	Array<float> farr3(farr2);
	farr3 = farr2 = farr;
	for (size_t i = 0; i < 4; ++i)
		farr[i] = 21;
	std::cout << "    farr  ";
	print_arr(farr, farr.size());
	std::cout << "    farr2 ";
	print_arr(farr2, farr2.size());
	std::cout << "    farr3 ";
	print_arr(farr3, farr3.size());
	std::cout << "}" << std::endl << std::endl;

	std::cout << clr_bgreen("==>") << " test_out_of_range" << std::endl << "{" << std::endl;
	try
	{
		farr[4] = 42.42;
	}
	catch (std::exception &ex)
	{
		std::cout << "    farr ";
		print_arr(farr, farr.size());
		std::cout << "    farr [4]: " << ex.what() << std::endl;
	}
	std::cout << "}" << std::endl << std::endl;

	std::cout << clr_bgreen("==>") << " test_class_awesome_4" << std::endl << "{" << std::endl;
	Array<Awesome> aarr(4);
	Array<Awesome> aarr2;
	aarr2 = aarr;
	std::cout << "    aarr  ";
	print_arr(aarr, aarr.size());
	std::cout << "    aarr2 ";
	print_arr(aarr2, aarr2.size());
	std::cout << "}" << std::endl;

	return (0);
}
