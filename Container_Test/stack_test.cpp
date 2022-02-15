/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:53:53 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/15 17:12:21 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Container_Include/main_tester.hpp"

void test_stack()
{
	//int start = clock();

	std::cout << std::endl;
	 std::cout << YELLOW << "DEFAULT CONSTRUCTOR:" OFF << " stack" << std::endl;
	ft::stack<int> stack;

	std::cout << std::endl;

	std::cout << YELLOW << "SIZE:" << OFF << std::endl;
	std::cout << "stack size: " << stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "EMPTY:" << OFF << std::endl;
	std::cout << "stack empty() (1: true 0: false): " << stack.empty() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "PUSH:" << OFF << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		stack.push(42 * i);
		std::cout << YELLOW << "TOP:" << OFF << stack.top() << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "SIZE:" << OFF << std::endl;
	std::cout << "stack size: " << stack.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "EMPTY:" << OFF << std::endl;
	std::cout << "stack empty() (1: true 0: false): " << stack.empty() << std::endl;
	(
	std::cout) << std::endl;

	std::cout << YELLOW << "COPY CONSTRUCTOR:" << OFF << std::endl;
	ft::stack<int> stack_copy(stack);

	std::cout << std::endl;

	std::cout << YELLOW << "POP:" << OFF << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		std::cout << YELLOW << "TOP:" << OFF <<  stack.top() << std::endl;
		stack.pop();
	}

	std::cout << std::endl;

	std::cout << YELLOW << "ASSIGNATION OPERATOR:" << OFF << std::endl;
	stack_copy = stack;

	std::cout << std::endl;

	std::cout << YELLOW << "OPERATIONAL OPERATOR:" << OFF << std::endl;
	std::cout << "(stack == stack_copy) : " << (stack == stack_copy) << std::endl;
	std::cout << "(stack != stack_copy) : " << (stack != stack_copy) << std::endl;
	std::cout << "(stack < stack_copy) : " << (stack < stack_copy) << std::endl;
	std::cout << "(stack <= stack_copy) : " << (stack <= stack_copy) << std::endl;
	std::cout << "(stack > stack_copy) : " << (stack > stack_copy) << std::endl;
	std::cout << "(stack >= stack_copy) : " << (stack >= stack_copy) << std::endl;
	
	std::cout << std::endl;
	//int end = clock();
	//std::cout << RED "Execution time (stack): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;

	std::cout << std::endl;
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