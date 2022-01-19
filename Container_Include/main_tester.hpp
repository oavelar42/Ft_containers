/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:35:58 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/19 19:12:16 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_TESTER_HPP
# define MAIN_TESTER_HPP

#define LET "\033[1m"
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
# include <stack>
# include <map>
# include <vector>
# include <time.h>
# include <functional>
# include <utility>
# include <stdlib.h>
# include <string.h>

#include "map.hpp"
#include "map_class.hpp"
#include "map_rev_iter.hpp"
#include "vector.hpp"
#include "vector_class.hpp"
#include "stack.hpp"
#include "stack_class.hpp"

void print_header(std::string container_name);
void print_title(std::string title, std::string subtitle = "");
void test_map();
void test_vector();
void test_stack();

#endif