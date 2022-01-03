/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:35:58 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/03 17:49:04 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_TESTER_HPP
# define MAIN_TESTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <memory>
# include <utility>
# include <iostream>
# include <limits>

#include "map.hpp"
#include <stack>
#include <map>
#include <vector>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define SET "\033[0m"

void print_title(std::string title, std::string subtitle = "");
//void test_vector();
//void test_stack();
void test_map();
//void test_set();


#endif