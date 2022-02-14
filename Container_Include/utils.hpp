/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:19:19 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/14 18:28:03 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

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
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};


	/***************************************************************************/
   /****** UTILS ---------------------------------------------------------- ***/


	/*  struct enable_if : */
		/*  pode ser usado como um argumento de função adicional  */ 
	   /*   pode ser usado como um tipo de retorno               */ 
	  /*    pode ser usado como um modelo de classe 
							ou parâmetro de modelo de função   */
 
	template <bool Cond>
	struct enable_if {};

	template <>
	struct enable_if<true> { typedef int type; };

	  /***************************************************************************/
	 /****** IS_INTEGRAL ---------------------------------------------------- ***/

	// template <class T>
	// struct is_node { static const bool value = false; };
	// template <>
	// struct is_node<Node> { static const bool value = true; };

	
	template <class T>
	struct is_integral { static const bool value = false; };
	
	template <>
	struct is_integral<bool> { static const bool value = true; };
	template <>
	struct is_integral<char> { static const bool value = true; };
	template <>
	struct is_integral<wchar_t> { static const bool value = true; };
	template <>
	struct is_integral<signed char> { static const bool value = true; };
	template <>
	struct is_integral<short int> { static const bool value = true; };
	template <>
	struct is_integral<int> { static const bool value = true; };
	template <>
	struct is_integral<long int> { static const bool value = true; };
	template <>
	struct is_integral<long long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned char> { static const bool value = true; };
	template <>
	struct is_integral<unsigned short int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long long int> { static const bool value = true; };


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
