/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:53:50 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/24 13:52:51 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "stack_class.hpp"

namespace ft
{
    template < class T, class Container >
    stack<T, Container>::stack(const container_type& ctnr) : c(ctnr) {}

    template < class T, class Container >
    stack<T, Container>::~stack()
    {
        return ;
    }

    template < class T, class Container >
    bool stack<T, Container>::empty() const
    {
        return c.empty();
    }

    template < class T, class Container >
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return c.size();
    }

    template < class T, class Container >
    typename stack<T, Container>::value_type& stack<T, Container>::top()
    {
        return c.back();
    }

    template < class T, class Container >
    const typename stack<T, Container>::value_type&  stack<T, Container>::top() const
    {
        return c.back();
    }

    template < class T, class Container >
    void stack<T, Container>::push(const value_type& val)
    {
        return c.push_back(val);
    }

    template <class T, class Container >
    void stack<T, Container>::pop()
    {
        return c.pop_back();
    }

    template <class T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(lhs < rhs);
    }

}

#endif