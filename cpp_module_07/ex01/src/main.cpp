/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:18 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/27 07:29:47 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

class			Awesome
{
	public:
				Awesome(void) : _n(0) {}
				Awesome(int n) : _n(n) {}
		Awesome	&operator=(Awesome const &rRhs) { this->_n = rRhs._n; return (*this); }
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

template <typename T>
int				func(T &rT) { return (rT = rT + 1.5); }

template <typename T>
void			print(T const &rX) { std::cout << rX << std::endl; }

int				main(void)
{
	char		sz = 5;
	int			iarr[5] = {0};
	float		farr[5] = {0};

	iter(iarr, sz, func<int>);
	iter(iarr, sz, print);
	std::cout << std::endl;

	iter(farr, sz, func<float>);
	iter(farr, sz, print);
	std::cout << std::endl;

	int			tab[] = {0, 1, 2, 3, 4};
	Awesome		tab2[5];

	iter(tab, 5, print);
	std::cout << std::endl;

	iter(tab2, 5, print);

	return (0);
}
