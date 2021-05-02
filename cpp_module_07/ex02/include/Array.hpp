/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 23:05:11 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/02 13:39:08 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>

template <typename T = int>
class				Array
{
	public:

		size_t		size(void) const;

					Array(void);
					Array(unsigned int n);
					Array(Array const &rRhs);
					~Array(void);

		Array<T>	&operator=(Array<T> const &rRhs);
		T			&operator[](size_t idx) const throw (std::out_of_range);

	private:

		size_t		_sz;
		T			*_pArr;
};

template <typename T>
size_t				Array<T>::size(void) const
{
	return (_sz);
}

template <typename T>
					Array<T>::Array(void) :
					_sz(0),
					_pArr(new T[0])
{
}

template <typename T>
					Array<T>::Array(unsigned int n) :
					_sz(n),
					_pArr(new T[n]())
{
}

template <typename T>
					Array<T>::Array(Array<T> const &rRhs) :
					_sz(rRhs.size()),
					_pArr(new T[_sz])
{
	for (size_t i = 0; i < _sz; ++i)
		_pArr[i] = rRhs[i];
}

template <typename T>
					Array<T>::~Array(void)
{
	delete [] _pArr;
}

template <typename T>
Array<T>			&Array<T>::operator=(Array<T> const &rRhs)
{
	if (this != &rRhs)
	{
		delete [] _pArr;
		_sz = rRhs.size();
		_pArr = new T[_sz];
		for (size_t i = 0; i < _sz; ++i)
			_pArr[i] = rRhs[i];
	}
	return (*this);
}

template <typename T>
T					&Array<T>::operator[](size_t idx) const throw (std::out_of_range)
{
	if (idx >= _sz)
		throw (std::out_of_range("Array::_M_range_check"));
	return (*(_pArr + idx));
}

#endif // ARRAY_HPP
