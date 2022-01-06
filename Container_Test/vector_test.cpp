/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:11:56 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/06 18:06:00 by oavelar          ###   ########.fr       */
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

	print_title("RANGE CONSTRUCTOR", "ft::vector & std::vector");
	ft::vector<int> ft_vector_range(ft_vector_fill.begin(), ft_vector_fill.end());
	print_size(ft_vector_range, "ft_vector_range");
	print_vector(ft_vector_range, "ft_vector_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "ft::vector & std::vector");
	ft::vector<int> ft_vector_copy(ft_vector_range);
	print_size(ft_vector_copy, "ft_vector_copy");
	print_vector(ft_vector_copy, "ft_vector_copy");

	print_title("ASSIGNATION OPERATOR", "ft::vector & std::vector");
	ft::vector<int> ft_vector_assignation;
	ft_vector_assignation = ft_vector_copy;
	print_size(ft_vector_assignation, "ft_vector_assignation");
	print_vector(ft_vector_assignation, "ft_vector_assignation");

	ft_vector = ft_vector_assignation;

	print_title("ITERATOR TEST");
	std::cout << "ft_vector (iterator): ";
	for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "ft_vector (const_iterator): ";
	for (ft::vector<int>::const_iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "ft_vector (reverse_iterator): ";
	for (ft::vector<int>::reverse_iterator rit = ft_vector.rbegin(); rit != ft_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "ft_vector (const_reverse_iterator): ";
	for (ft::vector<int>::const_reverse_iterator rit = ft_vector.rbegin(); rit != ft_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "\n";


	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, capacity, resize, empty, reserve");
	print_title("BEFORE RESIZE");
	print_size(ft_vector, "ft_vector");

	print_title("AFTER RESIZE(20)");
	ft_vector.resize(20);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("AFTER RESIZE(20, 42)");
	ft_vector.resize(40, 42);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");


	print_title("VECTOR EMPTY()");
	print_size(ft_vector, "ft_vector");


	print_title("VECTOR RESERVE(max_size)");
	try
	{
		ft_vector.reserve(ft_vector.max_size());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	print_title("VECTOR RESERVE(max_size + 1)");
	try
	{
		ft_vector.reserve(ft_vector.max_size() + 1);
		// ft_vector.reserve(4611686018427387904);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	print_title("VECTOR RESERVE(50)");
	ft_vector.reserve(50);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR [] OPERATOR");
	std::cout << "ft_vector : ";
	for (int i = 0; ft_vector[i]; i++)
		std::cout << ft_vector[i] << " ";
	std::cout << std::endl;

	print_title("VECTOR AT()");
	try
	{
		std::cout << "ft_vector : ";
		for (size_t i = 0; i < ft_vector.size() + 1; i++)
			std::cout << ft_vector.at(i) << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	print_title("VECTOR FRONT()");
	std::cout << "ft_vector : " << ft_vector.front() << std::endl;
	std::cout << std::endl;

	print_title("VECTOR BACK()");
	std::cout << "ft_vector : " << ft_vector.back() << std::endl;
	std::cout << std::endl;

	print_title("VECTOR ASSIGN(first, last)");
	ft_vector.assign(ft_vector_fill.begin(), ft_vector_fill.end());
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR ASSIGN(n, val)");
	ft_vector.assign(10, 42);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR PUSH_BACK(i * 42)");
	for (int i = 0; i <= 10; i++)
	{
		ft_vector.push_back(i * 42);
		print_size(ft_vector, "ft_vector");
	}
	std::cout << std::endl;
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR POP_BACK()");
	for (int i = 0; i < 10; i++)
	{
		ft_vector.pop_back();
		print_size(ft_vector, "ft_vector");
	}
	std::cout << std::endl;
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR INSERT(position, n, val)");
	ft_vector.insert(ft_vector.begin(), 5, 420);
	std::cout << "ft_vector : ";
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR INSERT(position, first, last)");
	ft_vector.insert(ft_vector.end(), ft_vector_fill.begin(), ft_vector_fill.end());
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR ERASE(position)", "erasing first half");
	for (ft::vector<int>::iterator it = (ft_vector.begin() + (ft_vector.size() / 2)); it != ft_vector.end() - 1 ; it++)
		ft_vector.erase(it);
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR SWAP() (MEMBER)", "swaping vector and range vector");
	print_title("BEFORE SWAP");
	print_vector(ft_vector, "ft_vector");
	print_vector(ft_vector_range, "ft_vector_range");
	ft_vector.swap(ft_vector_range);
	print_title("AFTER SWAP");
	print_vector(ft_vector, "ft_vector");
	print_vector(ft_vector_range, "ft_vector_range");

	print_title("VECTOR SWAP() (NON MEMBER)", "swaping vector and range vector again");
	print_title("BEFORE SWAP");
	print_vector(ft_vector, "ft_vector");
	print_vector(ft_vector_range, "ft_vector_range");
	ft::swap(ft_vector, ft_vector_range);
	print_title("AFTER SWAP");
	print_vector(ft_vector, "ft_vector");
	print_vector(ft_vector_range, "ft_vector_range");


	print_title("OPERATIONAL OPERATOR", "ft_vector & ft_vector_copy");
	print_vector(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");
	std::cout << "ft_vector == ft_vector_copy: " << (ft_vector == ft_vector_copy) << std::endl;
	std::cout << "ft_vector != ft_vector_copy: " << (ft_vector != ft_vector_copy) << std::endl;
	std::cout << "ft_vector < ft_vector_copy: " << (ft_vector < ft_vector_copy) << std::endl;
	std::cout << "ft_vector <= ft_vector_copy: " << (ft_vector <= ft_vector_copy) << std::endl;
	std::cout << "ft_vector > ft_vector_copy: " << (ft_vector > ft_vector_copy) << std::endl;
	std::cout << "ft_vector >= ft_vector_copy: " << (ft_vector >= ft_vector_copy) << std::endl;
	std::cout << std::endl;

	print_title("OPERATIONAL OPERATOR", "ft_vector_assignation & ft_vector_copy");
	print_vector(ft_vector_assignation, "ft_vector_assignation");
	print_vector(ft_vector_copy, "ft_vector_copy");
	std::cout << "ft_vector_assignation == ft_vector_copy: " << (ft_vector_assignation == ft_vector_copy) << std::endl;
	std::cout << "ft_vector_assignation != ft_vector_copy: " << (ft_vector_assignation != ft_vector_copy) << std::endl;
	std::cout << "ft_vector_assignation < ft_vector_copy: " << (ft_vector_assignation < ft_vector_copy) << std::endl;
	std::cout << "ft_vector_assignation <= ft_vector_copy: " << (ft_vector_assignation <= ft_vector_copy) << std::endl;
	std::cout << "ft_vector_assignation > ft_vector_copy: " << (ft_vector_assignation > ft_vector_copy) << std::endl;
	std::cout << "ft_vector_assignation >= ft_vector_copy: " << (ft_vector_assignation >= ft_vector_copy) << std::endl;

	std::cout << std::endl;

	print_title("VECTOR CLEAR()");
	print_size(ft_vector, "ft_vector before clear()");
	print_size(ft_vector_range, "ft_vector_range before clear()");
	ft_vector.clear();
	print_size(ft_vector, "ft_vector after(clear)");
	print_size(ft_vector_range, "ft_vector_range after(clear)");

	std::cout << "\n";
	int end = clock();
	std::cout << RED "Execution time (map): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "\n";
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