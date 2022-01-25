/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:53:53 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/25 14:30:35 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_tester.hpp"

void test_stack()
{
	int start = clock();

	std::cout << std::endl;
	 std::cout << YELLOW << "DEFAULT CONSTRUCTOR:" << OFF << " ft::stack"<< std::endl;
	ft::stack<int> ft_stack;

	std::cout << std::endl;

	std::cout << YELLOW << "SIZE:" << OFF << std::endl;
	std::cout << "ft_stack size: " << ft_stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "EMPTY:" << OFF << std::endl;
	std::cout << "ft_stack empty() (1: true  0: false): " << ft_stack.empty() << std::endl;

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
	std::cout << "ft_stack empty() (1: true  0: false): " << ft_stack.empty() << std::endl;
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
	//int start = clock();
	int end = clock();
	std::cout << RED "Execution time (stack): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
}






/* TEST for Stack:
	 
	 STACK = As pilhas são um tipo de adaptador de contêiner com o tipo de funcionamento LIFO (Last In First Out), 
	 	onde um novo elemento é adicionado em uma extremidade (topo) e um elemento é removido apenas dessa extremidade. 

	As funções associadas à pilha são: 

	empty() – Retorna se a pilha está vazia .
	size() – Retorna o tamanho da pilha.
	top() – Retorna uma referência para o elemento mais alto da pilha.
	push(g) – Adiciona o elemento 'g' no topo da pilha.
	pop() – Exclui o elemento mais alto da pilha.

*/