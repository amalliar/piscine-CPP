/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:18 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/27 07:10:09 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

class				Base
{
	public:
		virtual		~Base(void) {};
};

class				A : public Base {};
class				B : public Base {};
class				C : public Base {};

static Base 		*generate(void)
{
	switch (std::rand() % 3)
	{
		case	0: return (new A());
		case	1: return (new B());
		case	2: return (new C());
	}
	return (NULL);
}

static void			identify_from_pointer(Base *pBase)
{
	// dynamic_cast returns NULL if pointer conversion is impossible
	if (dynamic_cast<A *>(pBase))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(pBase))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(pBase))
		std::cout << "C" << std::endl;
}

static void			identify_from_reference(Base &rBase)
{
	// dynamic_cast throws std::bad_cast exception if reference conversion is impossible
	try
	{
		static_cast<void>(dynamic_cast<A &>(rBase));
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast) {}

	try
	{
		static_cast<void>(dynamic_cast<B &>(rBase));
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast) {}

	try
	{
		static_cast<void>(dynamic_cast<C &>(rBase));
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast) {}
}

int			main(void)
{
	Base	*p_base;

	std::srand(std::time(NULL));
	for (int i = 0; i < 8; ++i)
	{
		p_base = generate();
		std::cout << "identify_from_pointer(Base *pBase):   ";
		identify_from_pointer(p_base);
		std::cout << "identify_from_reference(Base &rBase): ";
		identify_from_reference(*p_base);
		if (i < 7)
			std::cout << std::endl;
		delete p_base;
	}
	return (0);
}
