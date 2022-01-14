/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rev_iter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:34:57 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/14 23:02:03 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REV_ITER_HPP
# define MAP_REV_ITER_HPP

# include "map_class.hpp"

namespace ft
{
	template < class T, typename Node >
	class MapIter
	{
		protected:
			Node    *_node;
			MapIter(Node *src) { _node = src; } 

		/*  iter traits  */
		public:
			typedef T                   value_type;
			typedef value_type&         reference;
			typedef value_type const&   const_reference;
			typedef value_type*         pointer;
			typedef ptrdiff_t           difference_type;
			typedef Node*               node_ptr;

			MapIter() : _node(NULL) {}
			MapIter(MapIter const& src) { *this = src; }
			virtual ~MapIter() {}
			MapIter&  operator=(MapIter const& rhs)
			{
				if (this != &rhs)
					_node = rhs._node;
				return *this; 
			}
			operator MapIter<const T, Node>(void) const { return MapIter<const T, Node>(this->_node); };

			bool operator==(MapIter const& rhs) { return _node == rhs._node; }
			bool operator!=(MapIter const& rhs) { return _node != rhs._node; }
			
			MapIter& operator++() 
			{
				if (_node->right)
				{
					_node = min_node(_node->right);
				}
				else if (_node->parent)
				{
					Node  *tmp = _node;
					_node = _node->parent;
					while (_node && tmp == _node->right)
					{
						tmp = _node;
						_node = _node->parent;        
					}
				}
				return *this;
			}

			MapIter operator++(int)
			{
				MapIter<T, Node> tmp(*this);
				operator++();
				return tmp;
			}
			
			MapIter& operator--()
			{
				if (_node->left)
					_node = max_node(_node->left);
				else if (_node->parent)
				{
					Node  *tmp = _node;
					_node = _node->parent;
					while (_node && tmp == _node->left)
					{
						tmp = _node;
						_node = _node->parent;        
					}
				}
				return *this;
			}

			MapIter operator--(int)
			{
				MapIter<T, Node> tmp(*this);
				operator--();
				return tmp;
			}

			reference operator*() const { return _node->data; }
			pointer operator->() const { return &_node->data; }

			template <class, class, class, class>
			friend class map;
			template <class, class>
			friend class MapIter;
	};

		/****************************/
		/*                          */
		/*     Reverse_iterator     */
		/*                          */
		/****************************/

	template < class Iterator >
	class reverse_iterator
	{
		protected:
			Iterator _base;

		public:

			   /************************/
			  /*     Member types     */
			 /************************/

			typedef Iterator        iterator_type;
			typedef typename Iterator::difference_type      difference_type;
			typedef typename Iterator::pointer              pointer;
			typedef typename Iterator::reference            reference;

				 /****************************/
				/*     Member functions     */
			   /****************************/

				/***************************************************************************/
			   /*** constructors ------------------------------------------------------ ***/
			   
			   /* Default */ 
				reverse_iterator() : _base() {} 
				
				/* Init */
				explicit reverse_iterator(iterator_type it) : _base(it) {}
				
				/* Copy , estou iniciando const_rev_iter com parametro em rever_iter */
				template < class Iter >
					reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {} 
			   
				/***************************************************************************/
			   /*** operator= --------------------------------------------------------- ***/
			   
				template <class Iter> 
					reverse_iterator &operator=(const reverse_iterator<Iter> &x) { _base = x.base(); return *this; };


				 /***************************************************************************/
				/*** overloads --------------------------------------------------------- ***/

				iterator_type       base() const { return _base; };
				reference           operator*() const { Iterator tmp = _base; return *--tmp; };
				pointer             operator->() const { return &(operator*()); };
				reverse_iterator    operator+(difference_type n) const { return reverse_iterator(_base - n); };
				reverse_iterator    operator-(difference_type n) const { return reverse_iterator(_base + n); };
				template <class T>
					difference_type		operator-(reverse_iterator<T> const& n) { return n.base().operator-(_base); };
				reverse_iterator&   operator++() {--_base; return *this; };
				reverse_iterator    operator++(int) { reverse_iterator tmp(*this); --_base; return tmp; };
				reverse_iterator&   operator--(){ ++_base; return *this; };
				reverse_iterator    operator--(int) { reverse_iterator tmp(*this); ++_base; return tmp; };
				reverse_iterator&   operator+=(difference_type n) { _base -= n; return *this; };
				reverse_iterator&   operator-=(difference_type n) { _base += n; return *this; };
				reference           operator[](difference_type n) const { return *(*this + n); };
	};

	 /*  Funções para comparar se e const ou não-const  */
	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() <= rhs.base();
	} 

	template <class Iterator>
		reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
		{
			return reverse_iterator<Iterator>(rev_it.base() - n);
		}

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return lhs.base() - rhs.base();
		}

	/*  Class random para acesso iter     */
   /*      todas as calculos necessarios */
	template < class T >
	class RandAccess
	{
		protected:
			T          *_val;

		public:
			typedef T&          reference;
			typedef T*          pointer;
			typedef ptrdiff_t   difference_type;

			RandAccess() : _val(NULL) {}
			RandAccess(T *src) : _val(src) {}
			RandAccess(RandAccess const& src) : _val(NULL) { *this = src; }
			virtual ~RandAccess() {}
			RandAccess& operator=(RandAccess const& rhs) {
				if (this != &rhs)
					_val = rhs._val;
				return (*this);
			};

			bool            operator==(RandAccess const& rhs) const { return _val == rhs._val; }
			bool            operator!=(RandAccess const& rhs) const { return _val != rhs._val; }
			bool            operator>(RandAccess const& rhs) const { return _val > rhs._val; }
			bool            operator>=(RandAccess const& rhs) const { return _val >= rhs._val; }
			bool            operator<(RandAccess const& rhs) const { return _val < rhs._val; };
			bool            operator<=(RandAccess const& rhs) const { return _val <= rhs._val; };

			RandAccess<T>&  operator++() { _val++; return *this; }
			RandAccess<T>   operator++(int) {  RandAccess<T> tmp(*this); _val++; return tmp; }
			RandAccess<T>&  operator--() { _val--; return *this; }
			RandAccess<T>   operator--(int) { RandAccess<T> tmp(*this); _val--; return tmp; }
			RandAccess<T>   operator+(difference_type n) const { return RandAccess(_val + n); }
			friend RandAccess<T>    operator+(difference_type n, RandAccess const& rhs) { return rhs.operator+(n); }

			RandAccess<T>   operator-(difference_type n) const { return RandAccess(_val - n); }
			difference_type operator-(RandAccess const& n) const { return _val - n._val; }
			RandAccess<T>&  operator+=(difference_type n) { _val += n; return *this; }
			RandAccess<T>&  operator-=(difference_type n) { _val -= n; return *this; }

			pointer         operator->() const { return _val; }
			reference       operator*() const { return *_val; }
			reference       operator[](difference_type n) const { return _val[n]; }
	};


	  /***************************************************************************/
	 /****** UTILS ---------------------------------------------------------- ***/


	/*  struct enable_if : */
		/*  pode ser usado como um argumento de função adicional  */ 
	   /*   pode ser usado como um tipo de retorno               */ 
	  /*    pode ser usado como um modelo de classe 
							ou parâmetro de modelo de função   */
	template <bool, class _Tp = void>
	struct enable_if {};
	
	template <class _Tp>
	struct enable_if<true, _Tp>  {typedef _Tp type;};

	template <class InputIterator>
	size_t InputIterator_len(InputIterator first, InputIterator last)
	{
		size_t i = 0;
		for(; first != last; first++)
			i++;
		return i;
	}

		 /*  lexicographical_compare é :  */ 
		/*  Dois intervalos são comparados elemento por elemento.                                                                   */
	   /*  O primeiro elemento incompatível define qual intervalo é lexicograficamente menor ou maior que o outro.                 */
	  /*  Se um intervalo for um prefixo de outro, o intervalo mais curto será lexicograficamente menor que o outro.              */
	 /*  Se dois intervalos têm elementos equivalentes e são do mesmo comprimento, os intervalos são lexicograficamente iguais . */
	/*  Um intervalo vazio é lexicograficamente menor do que qualquer intervalo não vazio.                                      */
   /*  Dois intervalos vazios são lexicograficamente iguais                                                                    */
   
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{   
		while (first1 != last1)                       
		{
			if (first2 == last2 || *first2 < *first1)   // retorna falso se chegar ao fim
				return false;
			else if (*first1 < *first2)               // retorna verdadeiro se 1 for maior que 2
				return true;
			++first1; 
			++first2;
		}
		return (first2 != last2);                  // retorna true se completar os 2 container
	}                                             // se não retorna falso

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	  ///////////////////////
	 //        NODE       //
	///////////////////////
	template<class T>
	struct Node
	{
		private:
			bool empty;
		public:
			T       data;
			Node    *right;
			Node    *left;
			Node    *parent;
	};

	template< class T >
	Node<T>* min_node(Node<T>* node)
	{
		while (node && node->left != NULL)
			node = node->left;
		return node;
	}

	template< class T >
	Node<T>* max_node(Node<T>* node)
	{
		while (node && node->right != NULL)
			node = node->right;
		return node;
	}

}

#endif