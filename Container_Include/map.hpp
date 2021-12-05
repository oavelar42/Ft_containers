/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/05 18:25:13 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
//# include "rev_iterator.hpp"

# define OTA "\x1B[36m"
# define RED "\x1B[31m"
# define OFF "\033[0m"
# define GRE "\x1B[32m"

namespace ft
{
     /*********************/
    /*     Class Map     */
    /*********************/
    template < class key, class T, class Compare = std::less<key>, class Alloc = std::allocator<std::pair<const key,T>>>
    class Map
    {
        public :
            test_map();
                        /*     Member types     */
            typedef key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef std::pair<const key_type, mapped_type>                      value_type;
            typedef Compare                                                     key_compare;
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef typename map::iterator<key_type, mapped_type>               iterator;
            typedef typename map::const_iterator<key_type, mapped_type>         const_iterator;
            typedef typename map::reverse_iterator<key_type, mapped_type>       reverse_iterator;
            typedef typename map::const_reverse_iterator<key_type, mapped_type> const_reverse_iterator;
            typedef size_t                                                      size_type;
            
            class value_compare
            {
                friend class Map;
                    protected :
                        Compare comp;
                        value_compare (Compare c) : comp(c) { }
                    public :
                        typedef bool result_type;
                        typedef value_type first_arg_type;
                        typedef value_type second_arg_type;
                        bool operator() (const valeu_type& x, const value_type& y) const
                        {
                            return comp(x.key_value, y.key_value);
                        }
            };
    };
}

#endif