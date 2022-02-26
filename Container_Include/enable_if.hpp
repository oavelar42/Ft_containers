/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:19:19 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/25 18:01:31 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
            /*  struct enable_if : */
                  /*  pode ser usado como um argumento de função adicional  */ 
                 /*   pode ser usado como um tipo de retorno               */ 
                /*    pode ser usado como um modelo de classe 
                                        ou parâmetro de modelo de função  */
            /*https://www.cplusplus.com/reference/type_traits/enable_if/?kw=enable_if*/
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

}

#endif