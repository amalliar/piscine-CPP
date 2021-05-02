/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:38:34 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 13:41:34 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iterator>
# include <limits>
# include <stdexcept>
# include <utility>
# include <vector>

class					Span : public std::vector<int>
{
	public:

		template <typename InputIterator>
		void			addRange(InputIterator first, InputIterator last)
							throw (std::length_error);
		void			addNumber(int nbr)
							throw (std::length_error);
		int				shortestSpan(void)
							throw (std::length_error);
		int				longestSpan(void)
							throw (std::length_error);
		
						Span(size_t N);
						Span(Span const &rSrc);
						~Span(void);

		Span			&operator=(Span const &rRhs)
							throw (std::length_error);

	private:

		size_t const	_N;

		// Restrict access to some of the base class member functions.
		using std::vector<int>::resize;
		using std::vector<int>::shrink_to_fit;
		using std::vector<int>::reserve;
		using std::vector<int>::assign;
		using std::vector<int>::push_back;
		using std::vector<int>::pop_back;
		using std::vector<int>::insert;
		using std::vector<int>::erase;
		using std::vector<int>::clear;

						Span(void);
};

template <typename InputIterator>
void		Span::addRange(InputIterator first, InputIterator last) throw (std::length_error)
{
	if (size() + std::distance(first, last) > _N)
		throw (std::length_error("Span::_M_fill_insert"));
	insert(end(), first, last);
}

#endif // SPAN_HPP
