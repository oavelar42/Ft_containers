/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:12:02 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/25 18:09:29 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "iterators.hpp"
# include "reverse_iter.hpp"
# include "enable_if.hpp"

namespace ft
{
	 /*********************/
	 /*                   */
	 /*   Class Vector    */
	 /*                   */
	 /*********************/
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			  /************************/
			 /*     Member types     */
			/************************/

			typedef	T															value_type;
			typedef	Alloc														allocator_type;
			typedef	typename allocator_type::reference							reference;
			typedef	typename allocator_type::const_reference					const_reference;
			typedef	typename allocator_type::pointer							pointer;
			typedef	typename allocator_type::const_pointer						const_pointer;
			typedef	ft::vector_iterator<random_access_iterator_tag, value_type,
					ptrdiff_t, const T*, const T&>								const_iterator;
			typedef	ft::vector_iterator<random_access_iterator_tag, value_type>		iterator;
			typedef	ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef	ft::reverse_iterator<iterator>									reverse_iterator;	
			typedef	typename iterator::difference_type							difference_type;
			typedef	size_t														size_type;

				 /****************************/
				/*     Member functions     */
			   /****************************/

			 /***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
			explicit vector(const allocator_type& alloc = allocator_type())  :
			_alloc(alloc), _size(0), _capacity(0) { this->_begin = this->_alloc.allocate(0); }
			
			/* Fill */ 
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _size(n), _capacity(n)
			{
				this->_begin = this->_alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(&this->_begin[i], val);		
			}
			
			/*  Range  */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value>::type * = 0) :
			_alloc(alloc), _size(0)
			{
				for (InputIterator it = first; it != last; it++)
					++this->_size;
				this->_capacity = this->_size;
				this->_begin = this->_alloc.allocate(this->_capacity);
				
				int i = 0;
				for (InputIterator it = first; it != last; it++, i++)
					this->_alloc.construct(&this->_begin[i], *it);
			}
			
			/* Copy */
			vector(const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._size)
			{
				this->_begin = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_begin[i], x._begin[i]);
			}
			
			 /***************************************************************************/
			/*** destructor -------------------------------------------------------- ***/
			~vector()
			{
				this->clear();
				this->_alloc.deallocate(this->_begin, this->_capacity);
			}

			 /***************************************************************************/
			/*** operator= --------------------------------------------------------- ***/
			vector& operator= (const vector& x)
			{		
				if (this == &x)
					return *this;

				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_begin[i]);
				if (this->_capacity < x._size)
				{
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_capacity = x._size;
					this->_begin = this->_alloc.allocate(this->_capacity);
				}
				this->_alloc = x._alloc;
				this->_size = x._size;

				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_begin[i], x._begin[i]);

				return *this;
			}

			      ////////////////////////
				 //      Iterator      //
				////////////////////////
			
			iterator begin() { return iterator(this->_begin); }
			const_iterator begin() const { return const_iterator(this->_begin); }

			iterator end() { return iterator(this->_begin) + this->_size; }
			const_iterator end() const { return const_iterator(this->_begin + this->_size); }

			reverse_iterator rbegin() { return reverse_iterator(this->end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }

			reverse_iterator rend() { return reverse_iterator(iterator(this->begin())); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); } 

			      ////////////////////////
				 //      Capacity      //
				////////////////////////

			size_type	size() const { return this->_size; }

			size_type	max_size() const { return this->_alloc.max_size(); } 
			
			void		resize(size_type n, value_type val = value_type())
			{
				pointer tmp = this->_begin;

				this->_begin = this->_alloc.allocate(n);

				for (size_type i = 0; i < this->_size && i < n; i++)
				{
					this->_alloc.construct(&this->_begin[i], tmp[i]);
					this->_alloc.destroy(&tmp[i]);
				}
				for (size_type i = this->_size; i < n; i++)
					this->_alloc.construct(&this->_begin[i], val);
				for (size_type i = n; i < this->_size; i++)
					this->_alloc.destroy(&tmp[i]);

				this->_alloc.deallocate(tmp, this->_capacity);
				this->_size = n;
				this->_capacity = n;
			}
			
			size_type	capacity() const	{ return this->_capacity; }
			
			bool		empty() const		{ return (this->_size == 0); }
			
			void			reserve(size_type n)
			{
				if (n <= this->_capacity)
					return ;

				pointer tmp = this->_begin;
 
				this->_begin = this->_alloc.allocate(n);

				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&this->_begin[i], tmp[i]);
					this->_alloc.destroy(&tmp[i]);
				}

				this->_alloc.deallocate(tmp, this->_capacity);
				this->_capacity = n;
			}

			      ////////////////////////
				 //    Element acess   //
				////////////////////////
			
			reference		operator[] (size_type n) { return this->_begin[n]; }
			const_reference	operator[] (size_type n) const { return this->_begin[n]; }
			
			reference		at (size_type n)
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_begin[n];
			}

			const_reference	at (size_type n) const
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_begin[n];
			}

			reference		front() { return this->_begin[0]; }
			const_reference	front() const { return this->_begin[0]; }
			reference		back() { return this->_begin[this->_size - 1]; }
			const_reference	back() const { return this->_begin[this->_size - 1]; }

			      ////////////////////////
				 //      Modifiers     //
				////////////////////////
			
			template <class InputIterator>
  			void			assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
			{
				size_type size = 0;
				for (InputIterator it = first; it != last; it++)
					++size;
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_begin[i]);
				if (this->_capacity < size)
				{
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_capacity = size;
					this->_begin = this->_alloc.allocate(size);
				}
				this->_size = size;

				size_type i = 0;
				for (InputIterator it = first; it != last; it++, i++)
					this->_alloc.construct(&this->_begin[i], *it);
			}

			void			assign (size_type n, const value_type& val)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_begin[i]);
				if (this->_capacity < n)
				{
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_capacity = n;
					this->_begin = this->_alloc.allocate(n);
				}
				this->_size = n;

				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(&this->_begin[i], val);
			}

			void			push_back (const value_type& val)
			{
				if (this->_capacity >= this->_size + 1)
				{
					this->_alloc.construct(&this->_begin[this->_size], val);
					++this->_size;
					return ;
				}
				pointer tmp = this->_begin;
				this->_begin = this->_alloc.allocate(this->_size + 1);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&this->_begin[i], tmp[i]);
					this->_alloc.destroy(&tmp[i]);
				}
				this->_alloc.construct(&this->_begin[this->_size], val);
				this->_alloc.deallocate(tmp, this->_capacity);
				++this->_size;
				this->_capacity = this->_size;
			}
			
			void			pop_back ()
			{
				if (this->_size > 0)
				{
					--this->_size;
					this->_alloc.destroy(&this->_begin[this->_size]);
				}
			}

			iterator		insert (iterator position, const value_type& val)
			{
				size_type n = position - this->begin();
				this->insert(position, 1, val);

				return this->_begin + n;
			}

			void			insert (iterator position, size_type n, const value_type& val)
			{
				vector		tmp = *this;
				size_type	start = position - this->begin();
				size_type	i;

				for (i = start; i < n + start && i < this->size(); i++)
					(*this)[i] = val;
				for (size_type j = i; j < n + start; j++, i++)
					this->push_back(val);

				for (iterator it = tmp.begin() + start; it != tmp.end(); it++, i++)
				{
					if (i < this->size())
						(*this)[i] = *it;
					else
						this->push_back(*it);
				}
			}	

			template <class InputIterator>
			void			insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
			{
				vector		tmp = *this;
				size_type	start = position - this->begin();
				size_type	i;

				for (i = start; first != last; first++, i++)
				{
					if (i < this->size())
						(*this)[i] = *first;
					else
						this->push_back(*first);
				}
				for (iterator it = tmp.begin() + start; it != tmp.end(); it++, i++)
				{
					if (i < this->size())
						(*this)[i] = *it;
					else
						this->push_back(*it);
				}
			}
			
			iterator erase (iterator position) { return erase(position, position + 1); }
			
			iterator erase (iterator first, iterator last)
			{
				size_type n = first - this->begin();
				size_type len = last - first;

				for (size_type i = n; i < this->_size && i + len < this->_size; i++)
				{
					(*this)[i] = (*this)[i + len];
				}
				for (difference_type i = 0; i < last - first; i++)
					this->pop_back();
				
				return this->_begin + n;
			}

			void swap (vector& x)
			{
				pointer t_begin = this->_begin;
				allocator_type t_alloc = this->_alloc;
				size_type t_size = this->_size;
				size_type t_capacity = this->_capacity;

				this->_begin = x._begin;
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_capacity = x._capacity;
				
				x._begin = t_begin;
				x._alloc = t_alloc;
				x._size = t_size;
				x._capacity = t_capacity;
			}

			void clear()
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					this->_alloc.destroy(&*it);
				this->_size = 0;
			}
			
			  ////////////////////////////////////////
		     //     Non-member func overloads      //
		    ////////////////////////////////////////
			
			friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				if (lhs._size != rhs._size)
					return false;
				for (size_type i = 0; i < lhs._size && i < rhs._size; i++)
				{
					if (lhs[i] != rhs[i])
						return false;
				}
				return true;
			}
			friend bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return !(lhs == rhs); }
			friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
			friend bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(rhs < lhs); }
			friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return rhs < lhs; }
			friend bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); }

		private:
			pointer			_begin;
			allocator_type	_alloc;
			size_type 		_size;
			size_type 		_capacity;
	};

	template <class T, class Alloc>
  		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}

#endif