/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:35:58 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/20 22:44:27 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

#include <string>
#include <iostream>
#include <iomanip>

#include "map.hpp"
#include <map>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define SET "\033[0m"

void test_vector();
void test_stack();
void test_map();
void test_set();


#endif