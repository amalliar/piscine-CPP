/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:18 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/29 02:15:58 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include "whatever.hpp"
#include "colors.hpp"

template <typename T>
void			print(T &rLhs, T &rRhs)
{
	std::cout << "type: " << clr_byellow(typeid(T).name()) << std::endl;
	std::cout << "swap(" << rLhs << ", " << rRhs << "): ";
	::swap(rLhs, rRhs);
	std::cout << rLhs << ", " << rRhs << std::endl;
	std::cout << "min(" << rLhs << ", " << rRhs << "): " << ::min(rLhs, rRhs) << std::endl;
	std::cout << "max(" << rLhs << ", " << rRhs << "): " << ::max(rLhs, rRhs) << std::endl;
}

class			Awesome
{
	public:
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
	char			cx = 'x', cy = 'y';
	int				ix = 21, iy = 42;
	float			fx = 21, fy = 42;
	double			dx = 21, dy = 42;
	std::string 	sx = "chaine1", sy = "chaine2";
	Awesome			ax(21), ay(42);

	std::cout << std::showpoint;

	print(cx, cy);
	std::cout << std::endl;

	print(ix, iy);
	std::cout << std::endl;

	print(fx, fy);
	std::cout << std::endl;

	print(dx, dy);
	std::cout << std::endl;

	print(sx, sy);
	std::cout << std::endl;

	print(ax, ay);

	return (0);
}
