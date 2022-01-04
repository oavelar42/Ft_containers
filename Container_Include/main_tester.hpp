/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:35:58 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/04 10:59:40 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_TESTER_HPP
# define MAIN_TESTER_HPP
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define OFF "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>
# include <memory>
# include <cstddef>
# include <limits>
# include <utility>
# include <iostream>
# include <limits>
# include <stack>
# include <map>
# include <vector>

#include "map.hpp"
#include "map_class.hpp"
#include "map_rev_iter.hpp"

void print_header(std::string container_name);
void print_title(std::string title, std::string subtitle = "");
//void test_vector();
//void test_stack();
void test_map();

#endif