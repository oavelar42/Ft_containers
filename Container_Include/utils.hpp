/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:19:19 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/25 17:58:09 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	////////////////////////
	//        PAIR       //
	///////////////////////

	 /*  struct pair fornece uma maneira de guardar   */
	/*          2 obj como uma unica unidade         */
   /*        se não existir 2 tipos, é destruido    */

 	template< class T1, class T2 >
	struct pair {

		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;

		pair() :
			first(T1()),
			second(T2()) {}

		template< class U, class V >
		pair( const pair<U, V>& pr ) :
			first(pr.first),
			second(pr.second) {}

		pair( const first_type& a, const second_type& b ) :
			first(a),
			second(b) {}

		pair&	operator=( const pair& pr ) {
			if (this == &pr) {
				return (*this);
			}

			first = pr.first;
			second = pr.second;
			return (*this);
		}
    };

	  /***************************************************************************/
	 /****** ITERATOR_TRAITS ------------------------------------------------ ***/
	
    template <class Iterator> 
    struct iterator_traits 
	{
    	public:
			typedef typename    Iterator::difference_type       difference_type;   
			typedef typename    Iterator::value_type            value_type;         
			typedef typename    Iterator::pointer               pointer;             
			typedef typename    Iterator::reference             reference;         
			typedef typename    Iterator::iterator_category     iterator_category; 
    };

    /*  Specialized for pointers (T*) */
    template <class T> 
    struct iterator_traits<T*> 
	{
    	public:
			typedef ptrdiff_t   difference_type;  
			typedef T   value_type;       
			typedef T*  pointer;          
			typedef T&  reference;        
			typedef std::random_access_iterator_tag  iterator_category;
    };
    /* pointers to const (const T*) */
    template <class T>
    struct iterator_traits<const T*>
	{
    	public:
			typedef ptrdiff_t   difference_type;  
			typedef T   value_type;       
			typedef T   const*  pointer;          
			typedef T   const&  reference;        
			typedef std::random_access_iterator_tag  iterator_category;

    };


	/***************************************************************************/
   /****** UTILS ---------------------------------------------------------- ***/


	 /*  lexicographical_compare é :  */ 
		/*  Dois intervalos são comparados elemento por elemento.                                                                   */
	   /*  O primeiro elemento incompatível define qual intervalo é lexicograficamente menor ou maior que o outro.                 */
	  /*  Se um intervalo for um prefixo de outro, o intervalo mais curto será lexicograficamente menor que o outro.              */
	 /*  Se dois intervalos têm elementos equivalentes e são do mesmo comprimento, os intervalos são lexicograficamente iguais . */
	/*  Um intervalo vazio é lexicograficamente menor do que qualquer intervalo não vazio.                                      */
   /*  Dois intervalos vazios são lexicograficamente iguais                                                                    */
	
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
			{
				if (*first1 < *first2) return true;
				if (*first2 < *first1) return false;
			}
			
			return (first1 == last1) && (first2 != last2);
	}
	
	////////////////////////
	//        LESS       //
	///////////////////////

	 /*   struct less usada para dar ordem aos ponteiros,   */
	/*     realiza comparações ,quando o 'operator' e      */
   /*   como se fosse uma verificação de todos os casos   */
	
	template<class T>
	struct less
	{
		bool operator () (const T& lhs, const T& rhs) const {
			return (lhs < rhs);
		}
	};

	/*  Operadores de comparação   */
  	template< class T1, class T2 >
	bool	operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template< class T1, class T2 >
	bool	operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return !(lhs==rhs); }

	template< class T1, class T2 >
	bool	operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template< class T1, class T2 >
	bool	operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return !(rhs<lhs); }

	template< class T1, class T2 >
	bool	operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return rhs<lhs; }

	template< class T1, class T2 >
	bool	operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{ return !(lhs<rhs); }

	template< class T1, class T2 >
	pair<T1,T2>	make_pair( T1 x, T2 y ) {
		return (pair<T1,T2>(x,y));
	}
}

#endif