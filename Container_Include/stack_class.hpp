/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:54:12 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/24 13:50:59 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP

# include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;

             /***************************************************************************/
	        /*** constructors ------------------------------------------------------ ***/
            explicit            stack (const container_type& ctnr = container_type());
           
             /***************************************************************************/
			/*** destructor -------------------------------------------------------- ***/
            virtual             ~stack();

            bool                empty() const;
            size_type           size() const;
            value_type&         top();
            const value_type&   top() const;
            void                push (const value_type& val);
            void                pop();

            friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c == rhs.c; };
            friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c < rhs.c; };
        
        protected:
            container_type      c;
    };

      ////////////////////////////////////////
	 //     Non-member func overloads      //
	////////////////////////////////////////

	/*  Operadores relacionais */
    template <class T, class Container>
        bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>
        bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>
        bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>
        bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

#endif