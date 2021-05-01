/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:27:06 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/28 08:09:08 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"
#include "colors.hpp"

int		main(void)
{
	std::cout << clr_bgreen("==>") << " std::list test" << std::endl;  // ------------------------
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator itl = lst.begin();
	std::list<int>::iterator itel = lst.end();
	++itl;
	--itl;
	while (itl != itel)
	{
    	std::cout << *itl << std::endl;
		++itl;
	}
	std::cout << std::endl;

	std::cout << clr_bgreen("==>") << " MutantStack test" << std::endl;  // ----------------------
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
    	std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << clr_bgreen("==>") << " std::stack test" << std::endl;  // -----------------------
	std::stack<int> s(mstack);
	for (it = mstack.begin(); it != mstack.end(); ++it)
	{
    	std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << std::endl;

	std::cout << clr_bgreen("==>") << " MutantStack copy constructor test" << std::endl;  // -----
	MutantStack<int> m(mstack);
	for (it = m.begin(); it != m.end(); ++it)
    	std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << clr_bgreen("==>") << " MutantStack 'operator=' test" << std::endl;  // ----------
	MutantStack<int> m1 = mstack;
	for (it = m1.begin(); it != m1.end(); ++it)
    	std::cout << *it << std::endl;
	
	return (0);
}
