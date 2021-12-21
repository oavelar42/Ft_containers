/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:22:33 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/21 22:02:55 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_tester.hpp"

void print_title(std::string title, std::string subtitle)
{
	std::cout << std::endl;
  std::cout << YELLOW << title << ": " << SET << subtitle << "\n" << std::endl;
}

int main()
{
	/*std::cout << "VECTOR" << std::endl;
	while (std::cin.get() != '\n') {}
	test_vector();

    /*std::cout << "STACK" << std::endl;
	while (std::cin.get() != '\n') {}
	test_stack();*/

    std::cout << "MAP" << std::endl;
	while (std::cin.get() != '\n') {}
	test_map();

    /*std::cout << "SET" << std::endl;
	while (std::cin.get() != '\n') {}
	test_set();*/

	return 0;
}