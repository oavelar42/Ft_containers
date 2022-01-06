/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:11:56 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/06 11:13:26 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "main_tester.hpp"
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <cstddef>
#include "map.hpp" 
#include <time.h>

void print_vector(ft::vector<int> vector, std::string name)
{
  std::cout << name << ": ";
  for (ft::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	  std::cout << *it << " ";
  std::cout << std::endl;
}

void print_vector(std::vector<int> vector, std::string name)
{
  std::cout << name << ": ";
  for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	  std::cout << *it << " ";
  std::cout << std::endl;
}

void print_size(ft::vector<int> vector, std::string name)
{
  std::cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << ", max_size: " << vector.max_size() << std::endl;
  std::cout << name << " empty() (1: true 0:false): " << vector.empty() << std::endl;
}

void print_size(std::vector<int> vector, std::string name)
{
  std::cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << ", max_size: " << vector.max_size() << std::endl;
  std::cout << name << " empty() (1: true 0:false): " << vector.empty() << std::endl;
}

void test_vector(void)
{
	int start = clock();
	print_title("DEFAULT CONSTRUCTOR", "ft::vector");
	ft::vector<int> ft_vector;
	print_size(ft_vector, "ft_vector");

	print_title("FILL CONSTRUCTOR", "ft::vector");
	ft::vector<int> ft_vector_fill(10, 42);
	print_size(ft_vector_fill, "ft_vector_fill");
	print_vector(ft_vector_fill, "ft_vector_fill");

	int end = clock();
    std::cout << "Execution time (vector): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
}






/*
		Constructors
		default, fill, copy, assignation operator
		Accessors, iterators, getters, setters:
		iterator, const_iterator, reverse_iterator, const_reverse_iterator, begin, end, rbegin, rend
		size, max_size, resize, capacity, empty, reserve
		operator[], front, back
		assign, push_back, pop_back, insert, erase, swap, clear
*/