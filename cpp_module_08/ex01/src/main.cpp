/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:27:06 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/28 08:00:20 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Span.hpp"
#include "colors.hpp"

static void		print_span(Span &rSp)
{
	std::cout << "{";
	for (Span::iterator it = rSp.begin(); it != rSp.end(); ++it)
		std::cout << *it << ((it + 1 != rSp.end()) ? ", " : "");
	std::cout << "}" << std::endl;
}

int			main(void)
{
	std::srand(std::time(NULL));

	int					arr[6] = {4, 8, 15, 16, 23, 42};
	std::vector<int>	v0(100000);
	Span				sp = Span(11);
	Span				sp2(100000);
	Span				sp3(3);
	Span::iterator		it;

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addRange(arr, arr + 6);


	std::cout << clr_bgreen("==>") << " test normal span" << std::endl;  // ----------------------
	print_span(sp);
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl << std::endl;;

	std::cout << clr_bgreen("==>") << " test 100000 span" << std::endl;  // ----------------------
	std::generate(v0.begin(), v0.end(), std::rand);
	sp2.addRange(v0.begin(), v0.end());
	std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp2.longestSpan() << std::endl << std::endl;

	std::cout << clr_bgreen("==>") << " test container overflow" << std::endl;  // ---------------
	try
	{
		sp2.addNumber(42);
	}
	catch (std::exception &ex)
	{
		std::cout << clr_bred(ex.what()) << std::endl << std::endl;
	}

	std::cout << clr_bgreen("==>") << " test empty span" << std::endl;  // -----------------------
	try
	{
		sp3.shortestSpan();
	}
	catch (std::exception &ex)
	{
		std::cout << clr_bred(ex.what()) << std::endl;
	}

	return (0);
}
