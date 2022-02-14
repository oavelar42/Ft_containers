/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:34:57 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/14 19:06:45 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITER_HPP
# define REVERSE_ITER_HPP

# include <iostream>
# include <vector>
# include "utils.hpp"

namespace ft
{
		/****************************/
		/*                          */
		/*     Reverse_iterator     */
		/*                          */
		/****************************/

	template <class Iterator>
	class reverse_iterator
	{
		  	   /************************/
			  /*     Member types     */
			 /************************/

		public:
			typedef Iterator        											iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;

			 /****************************/
			/*     Member functions     */
		   /****************************/

			/***************************************************************************/
		   /*** constructors ------------------------------------------------------ ***/
			   
			/* Default */ 	
			reverse_iterator() {}

			/* Init */
			explicit reverse_iterator (iterator_type it) : _it(it) {}

			/* Copy */
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) {}

			// Destructor 
			//virtual ~reverse_iterator() {}

			 /***************************************************************************/
		    /*** operator= --------------------------------------------------------- ***/
			template <class Iter>
			reverse_iterator&	operator=(const reverse_iterator<Iter> &rev_it) {
				this->_it = rev_it.base();
				return *this;
			}

			 /***************************************************************************/
			/*** overloads --------------------------------------------------------- ***/

			iterator_type base() const { return this->_it; }
			reverse_iterator&	operator+=(difference_type n) { this->_it -= n; return *this; }
			reverse_iterator&	operator-=(difference_type n) { this->_it += n; return *this; }

			/* operators : member access */
			reference   		operator*() const {
				iterator_type tmp = this->_it;
				return *--tmp;
			}
			pointer				operator->() const { return &(operator*()); }
			reference			operator[](difference_type n) { return this->_it[-n-1]; }

			/* operators : incr / decr */
			reverse_iterator&   operator++() { --this->_it; return *this; }
			reverse_iterator    operator++(int) { reverse_iterator tmp = *this; --this->_it; return tmp; }
			reverse_iterator&   operator--() { ++this->_it; return *this; }
			reverse_iterator    operator--(int) { reverse_iterator tmp = *this; ++this->_it; return tmp; }

			/* operators : arithmetic */
			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(this->_it - n); }
			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(this->_it + n); }


		private:
			iterator_type	_it;
	};

	template<class It>
	reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n, const reverse_iterator<It>& rev_it) 
	{
		reverse_iterator<It> tmp(rev_it); tmp += n; return tmp;
	}
	
	template<class It>
	reverse_iterator<It> operator-(typename reverse_iterator<It>::difference_type n, const reverse_iterator<It>& rev_it)
	{
		reverse_iterator<It> tmp(rev_it); tmp -= n;; return tmp;
	}
	
	template<class It>
	typename reverse_iterator<It>::difference_type	operator-(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
		return rhs.base() - lhs.base();
	}
	
	template<class It1, class It2>
	typename reverse_iterator<It1>::difference_type	operator-(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return rhs.base() - lhs.base();
	}
	
	/*  Operadores de comparação   */
	template< class It1, class It2 >
	bool operator== (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) 
	{
		return lhs.base() == rhs.base();
	}
	
	template< class It1, class It2 >
	bool operator!= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	
	template< class It1, class It2 >
	bool operator< (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return lhs.base() > rhs.base();
	}
	
	template< class It1, class It2 >
	bool operator<= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	
	template< class It1, class It2 >
	bool operator> (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	
	template< class It1, class It2 >
	bool operator>= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return lhs.base() <= rhs.base();
	}
}
#endif
