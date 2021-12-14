/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:22:33 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/14 22:48:34 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_rev_ite.hpp"
#include "map.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ft::Map < char, int > map;
        if (strcmp(av[1], "map") == 0)
        {
            map.test_map();
        }
        else
            std::cout << "Error : <executable> <example>" << std::endl;
    }
    return (0);
}