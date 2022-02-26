/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:53:50 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/25 18:10:29 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	/*********************/
	/*                   */
	/*    Class stack    */
	/*                   */
	/*********************/
	template <class T, class Container = vector<T> >
    class stack
	{
		public:
			typedef Container	container_type;
			typedef	T			value_type;
			typedef size_t		size_type;
			
			 /***************************************************************************/
	        /*** constructors ------------------------------------------------------ ***/

			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}

			
			  ////////////////////////
			 //      Capacity      //
			////////////////////////
			bool                empty() const				{ return this->c.empty(); }
			size_type           size() const				{ return this->c.size(); }
			
			  ////////////////////////
			 //    Element acess   //
			////////////////////////
			value_type&         top()						{ return (this->c.back()); }
			const value_type&   top() const					{ return (this->c.back()); }
			
			  ////////////////////////
			 //      Modifiers     //
			////////////////////////
			void                push(const value_type& val)	{ this->c.push_back(val); }
			void                pop()						{ this->c.pop_back(); }

		 ////////////////////////////////////////
	 	//     Non-member func overloads      //
	   ////////////////////////////////////////

		/*  Operadores relacionais */
		friend bool operator==	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs.c == rhs.c);}
		friend bool operator!=	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs.c != rhs.c);}
		friend bool operator<	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs.c < rhs.c);}
		friend bool operator<=	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs.c <= rhs.c);}
		friend bool operator>	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs.c > rhs.c);}
		friend bool operator>=	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs.c >= rhs.c);}
		
		protected:
			container_type		c;
	};
}

#endif