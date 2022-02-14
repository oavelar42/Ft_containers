/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:42:14 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/14 21:27:27 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <cstddef>

namespace ft
{
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};
	
	/*********************/
	/*    Vector         */
	/*       iterator    */
	/*********************/

	template <	class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class vector_iterator
	{
		public: 
			  /************************/
			 /*     Member types     */
			/************************/
			typedef T         						value_type;
			typedef Distance						difference_type;
			typedef Pointer   						pointer;
			typedef Reference 						reference;
			typedef Category						iterator_category;

			  /****************************/
			 /*     Member functions     */
			/****************************/

			 /***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
			vector_iterator() {}

			/*  Copy  */
			vector_iterator(const vector_iterator<Category, T, Distance, T*, T&> &toCopy) : _ptr(toCopy.base()) {}
			
			/*  Pointer constructor */
			vector_iterator(T* ptr) : _ptr(ptr) {}

			/*  Destructor  */
			virtual ~vector_iterator() {}

			T*			base() const { return this->_ptr ; } 
			/* operators : assignment */
			vector_iterator&	operator=(pointer ptr) { this->_ptr = ptr; return *this; }
			vector_iterator&	operator=(const vector_iterator &toCopy) { this->_ptr = toCopy._ptr; return *this; }
			vector_iterator&	operator+=(difference_type n) { this->_ptr += n; return *this; }
			vector_iterator&	operator-=(difference_type n) { this->_ptr -= n; return *this; }
			vector_iterator&	operator-=(const vector_iterator &it) { this->_ptr -= it._ptr; return *this; }

			/* operators : member access */
			reference   		operator*() const { return *this->_ptr; }
			pointer     		operator->() const { return &(operator*()); }
			reference			operator[](const difference_type &i) { return this->_ptr[i]; }

			/* operators : incr / decr */
			vector_iterator&   operator++() { this->_ptr++; return *this; }
			vector_iterator    operator++(int) { vector_iterator tmp = *this; ++*this; return tmp; }
			vector_iterator&   operator--() { this->_ptr--; return *this; }
			vector_iterator    operator--(int) { vector_iterator tmp = *this; --*this; return tmp; }

			/* operators : arithmetic */
			friend vector_iterator	operator+(const vector_iterator& it, difference_type n) { return vector_iterator(it._ptr + n); }
			friend vector_iterator	operator+(difference_type n, const vector_iterator& it) { return vector_iterator(it._ptr + n); }
			friend vector_iterator	operator-(const vector_iterator& it, difference_type n) { return vector_iterator(it._ptr - n); }
			friend vector_iterator	operator-(difference_type n, const vector_iterator& it) { return vector_iterator(it._ptr - n); }
			friend difference_type	operator-(const vector_iterator& a, const vector_iterator& b) { return (a._ptr - b._ptr); }

			/*  Operadores de comparação   */
			friend bool 	operator== (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr == rhs._ptr; }
			friend bool 	operator!= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr != rhs._ptr; }
			friend bool 	operator< (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr < rhs._ptr; }
			friend bool 	operator<= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr <= rhs._ptr; }
			friend bool 	operator> (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr > rhs._ptr; }
			friend bool 	operator>= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr >= rhs._ptr; }

		private:
			T*	_ptr;
	};


	/*********************/
	/*    Map            */
	/*       iterator    */
	/*********************/
	
	template <	class Category, class T, class not_const_T = T>
	class map_iterator
	{
		public:
		
			/************************/
			/*     Member types     */
			/************************/

			typedef typename T::value_type				value_type;
			typedef typename not_const_T::Node			Node;
			typedef typename T::key_type				key_type;
			typedef typename T::mapped_type				mapped_type;
			typedef	typename T::key_compare				key_compare;
			typedef typename T::pointer   				pointer;
			typedef typename T::reference 				reference;
			typedef ptrdiff_t							difference_type;
			typedef Category							iterator_category;

			  /****************************/
			 /*     Member functions     */
			/****************************/

			 /***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
			map_iterator() {}

			/* Copy */ 
			map_iterator(const map_iterator<Category, not_const_T> &toCopy) : _ptr(toCopy.base()), _end(toCopy.end()) {}
			
			/*  Pointer constructor */
			map_iterator(Node* node, Node* end) {
				this->_ptr = node;
				this->_end = end;
			}

			/*  Destructor  */
			virtual ~map_iterator() {}

			Node*			base() const { return this->_ptr; }
			Node*			end() const { return this->_end; }
			
			 /***************************************************************************/
			/*** operator= --------------------------------------------------------- ***/
			map_iterator&	operator=(const map_iterator<Category, not_const_T> &toCopy) {
				this->_ptr = toCopy._ptr;
				this->_end = toCopy._end;
				return *this;
			}

			/* operators : member access */
			reference   	operator*() const { return this->_ptr->value; }
			pointer     	operator->() const { return &(operator*()); }

			/* operators : incr / decr */
			map_iterator&   operator++()
			{
				if (this->_ptr->right)
				{
					this->_ptr = this->_ptr->right->min();   // find the smallest
					return *this;
				}
				else if (this->_ptr->parent)
				{
					key_type key = this->_ptr->value.first;  // find first previous greater node
					Node *tmp = this->_ptr->parent;
					while (tmp && this->_key_comp(tmp->value.first, key))
						tmp = tmp->parent;
					if (tmp)
					{
						this->_ptr = tmp;
						return *this;
					}
				}
				this->_ptr = this->_end;
				return *this;
			}
			
			map_iterator    operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }
			
			map_iterator&   operator--()
			{
				if (this->_ptr == this->_end)
				{
					this->_ptr = this->_ptr->parent;   // find the greatest
					return *this;
				}
				else if (this->_ptr->left)
				{
					this->_ptr = this->_ptr->left->max();
					return *this;
				}
				else if (this->_ptr->parent)
				{
					key_type key = this->_ptr->value.first;   // find first previous smaller node
					Node *tmp = this->_ptr->parent;
					while (tmp && this->_key_comp(key, tmp->value.first))
						tmp = tmp->parent;
					if (tmp)
					{
						this->_ptr = tmp;
						return *this;
					}
				}
				else
				{
					// just check one case ( undefined )
				}
				
				return *this;
			}
			
			map_iterator    operator--(int) { map_iterator tmp = *this; --*this; return tmp; }

			/*  Operadores de comparação   */
			friend bool		operator== (const map_iterator& lhs, const map_iterator& rhs) {
				return lhs._ptr == rhs._ptr; }
			friend bool 	operator!= (const map_iterator& lhs, const map_iterator& rhs) {
				return lhs._ptr != rhs._ptr; }

		private:
			Node*		_ptr;
			Node*		_end;
			key_compare	_key_comp;
	};
}

#endif
