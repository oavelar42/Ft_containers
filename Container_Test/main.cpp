/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:22:33 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/20 17:10:57 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_tester.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>

void print_title(std::string title, std::string subtitle)
{
	std::cout << std::endl;
  	std::cout << YELLOW << title << ": " << OFF << LET " " << subtitle << "\n" << std::endl;
}

void print_header(std::string container_name)
{
	std::cout << std::endl;
	std::cout << RED << container_name << " TESTS:" << " press enter to continue" OFF << std::endl;
}

int main()
{
	int start = clock();

	print_header("MAP");
	while (std::cin.get() != '\n') {}
	test_map();
	
	print_header("VECTOR");
	while (std::cin.get() != '\n') {}
	test_vector();

	print_header("STACK");
	while (std::cin.get() != '\n') {}
	test_stack();

	int end = clock();
	std::cout << RED "Execution time (stack): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	system("leaks identify | grep bytes");

	return 0;
}