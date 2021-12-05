/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:22:33 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/05 17:31:59 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <iostream>
#include <string.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        if (strcmp(av[1], "map") == 0)
        {
            test_map();
        }
        else
            std::cout << "Error : <executable> <example>" << std::endl;
    }
    return (0);
}