/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:22:33 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/10 13:51:48 by oavelar          ###   ########.fr       */
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
	std::string header = RED + container_name + " TESTS:" + OFF + " press enter to continue\n";
	int width = 100 - (header.length() / 2);

	std::cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;
	std::cout << std::setw(width) << header << std::endl;
	std::cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;

}

int main()
{
	print_header("MAP");
	while (std::cin.get() != '\n') {}
	test_map();
	
	print_header("VECTOR");
	while (std::cin.get() != '\n') {}
	test_vector();

	print_header("STACK");
	while (std::cin.get() != '\n') {}
	test_stack();

	system("leaks identify | grep bytes");

	return 0;
}