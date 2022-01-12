/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:53:53 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/12 23:33:52 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_tester.hpp"

void test_stack()
{
	
	int start = clock();
	 std::cout << YELLOW << "DEFAULT CONSTRUCTOR:" << OFF << " ft::stack"<< std::endl;
	/*ft::stack<int> ft_stack;

	std::cout << std::endl;

	std::cout << YELLOW << "SIZE:" << OFF << std::endl;
	std::cout << "ft_stack size: " << ft_stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "EMPTY:" << OFF << std::endl;
	std::cout << "ft_stack empty() (1/true if empty 0/false if not): " << ft_stack.empty() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "PUSH:" << OFF << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		ft_stack.push(42 * i);
		std::cout << YELLOW << "TOP:" << OFF << " ft = " << ft_stack.top() << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "SIZE:" << OFF << std::endl;
	std::cout << "ft_stack size: " << ft_stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "EMPTY:" << OFF << std::endl;
	std::cout << "ft_stack empty() (1/true if empty 0/false if not): " << ft_stack.empty() << std::endl;
	(
	std::cout) << std::endl;

	std::cout << YELLOW << "COPY CONSTRUCTOR:" << OFF << std::endl;
	ft::stack<int> ft_stack_copy(ft_stack);

	std::cout << std::endl;

	std::cout << YELLOW << "POP:" << OFF << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		std::cout << YELLOW << "TOP:" << OFF << " ft = " << ft_stack.top() << std::endl;
		ft_stack.pop();
	}

	std::cout << std::endl;

	std::cout << YELLOW << "ASSIGNATION OPERATOR:" << OFF << std::endl;
	ft_stack_copy = ft_stack;

	std::cout << std::endl;

	std::cout << YELLOW << "OPERATIONAL OPERATOR:" << OFF << std::endl;
	std::cout << "(ft_stack == ft_stack_copy) : " << (ft_stack == ft_stack_copy) << std::endl;
	std::cout << "(ft_stack != ft_stack_copy) : " << (ft_stack != ft_stack_copy) << std::endl;
	std::cout << "(ft_stack < ft_stack_copy) : " << (ft_stack < ft_stack_copy) << std::endl;
	std::cout << "(ft_stack <= ft_stack_copy) : " << (ft_stack <= ft_stack_copy) << std::endl;
	std::cout << "(ft_stack > ft_stack_copy) : " << (ft_stack > ft_stack_copy) << std::endl;
	std::cout << "(ft_stack >= ft_stack_copy) : " << (ft_stack >= ft_stack_copy) << std::endl;

	std::cout << std::endl;

	std::cout << "(std_stack == std_stack_copy) : " << (std_stack == std_stack_copy) << std::endl;
	std::cout << "(std_stack != std_stack_copy) : " << (std_stack != std_stack_copy) << std::endl;
	std::cout << "(std_stack < std_stack_copy) : " << (std_stack < std_stack_copy) << std::endl;
	std::cout << "(std_stack <= std_stack_copy) : " << (std_stack <= std_stack_copy) << std::endl;
	std::cout << "(std_stack > std_stack_copy) : " << (std_stack > std_stack_copy) << std::endl;
	std::cout << "(std_stack >= std_stack_copy) : " << (std_stack >= std_stack_copy) << std::endl;
	std::cout << std::endl;*/
		
	int end = clock();
	std::cout << "Execution time (stack): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	


}






/* TEST for Stack:
	Constructors
		default, fill, range, copy, assignation operator
	Accessors, iterators, getters, setters:
		iterator, const_iterator, reverse_iterator, const_reverse_iterator, begin, end, rbegin, rend
		size, max_size, resize, capacity, empty, reserve
		operator[], at, front, back
		assign, push_back, pop_back, insert, erase, swap, clear
*/