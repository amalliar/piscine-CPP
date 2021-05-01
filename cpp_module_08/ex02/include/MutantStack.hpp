/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:03:09 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 08:01:25 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <deque>
# include <stack>

template <typename T>
class							MutantStack : public std::stack<T, std::deque<T> >
{
	public:
								MutantStack(void);
								MutantStack(MutantStack const &rSrc);
								~MutantStack(void);
		MutantStack				&operator=(MutantStack const &rRhs);

		typedef typename std::deque<T>::iterator				iterator;
		typedef typename std::deque<T>::const_iterator			const_iterator;
		typedef typename std::deque<T>::reverse_iterator		reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void);
		iterator				end(void);
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
		const_iterator			cbegin(void) const;
		const_iterator			cend(void) const;
		const_reverse_iterator	crbegin(void) const;
		const_reverse_iterator	crend(void) const;
};

template <typename T>
													MutantStack<T>::MutantStack(void) :
													std::stack<T>()
{
}

template <typename T>
													MutantStack<T>::MutantStack(MutantStack const &rSrc) :
													std::stack<T>(rSrc)
{
}

template <typename T>
													MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
MutantStack<T>										&MutantStack<T>::operator=(MutantStack const &rRhs)
{
	static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(rRhs);
}

template <typename T>
typename MutantStack<T>::iterator					MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator					MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator			MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator			MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_iterator				MutantStack<T>::cbegin(void) const
{
	return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator				MutantStack<T>::cend(void) const
{
	return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator		MutantStack<T>::crbegin(void) const
{
	return (this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator		MutantStack<T>::crend(void) const
{
	return (this->c.crend());
}

#endif // MUTANT_STACK_HPP
