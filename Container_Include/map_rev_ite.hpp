/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rev_ite.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:13:09 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/06 17:16:25 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REV_ITE_HPP
# define MAP_REV_ITE_HPP

# include <iostream>

namespace ft
{
    /**************************/
    /*                        */
    /*     Struct of node     */
    /*                        */
    /**************************/
    template <class Key, class T>
    struct map_node
    {
        std::pair<Key, T>   content;
        bool                color;
        map_node            *right;
        map_node            *left;
        map_node            *parent;
    };
}

#endif