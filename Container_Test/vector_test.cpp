/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:11:56 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/25 14:58:12 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_tester.hpp"

void print_vector(ft::vector<int> vector, std::string name)
{
  std::cout << name << ": ";
  for (ft::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	  std::cout << *it << " ";
  std::cout << std::endl;
}

void print_size(ft::vector<int> vector, std::string name)
{
  std::cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << ", max_size: " << vector.max_size() << std::endl;
  std::cout << name << " empty() (1: true 0: false): " << vector.empty() << std::endl;
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

	print_title("RANGE CONSTRUCTOR", "ft::vector");
	ft::vector<int> ft_vector_range(ft_vector_fill.begin(), ft_vector_fill.end());
	print_size(ft_vector_range, "ft_vector_range");
	print_vector(ft_vector_range, "ft_vector_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "ft::vector");
	ft::vector<int> ft_vector_copy(ft_vector_range);
	print_size(ft_vector_copy, "ft_vector_copy");
	print_vector(ft_vector_copy, "ft_vector_copy");

	print_title("ASSIGNATION OPERATOR", "ft::vector");
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

	
	ft::vector<int> vec;
	for (int i = 0; i <= 10; i++)
	{
		vec.push_back(i);
	}
	print_vector(vec, "ft_vector ");

	std::cout << vec.at(2) << std::endl;
	vec.at(2) = 42;
	std::cout << vec.at(2) << std::endl;
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
	std::cout << RED "Execution time (vector): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "\n";
}






/*
	Os vetores são iguais aos arrays dinâmicos com a capacidade de se redimensionar automaticamente quando
		 um elemento é inserido ou excluído, com seu armazenamento sendo tratado automaticamente pelo contêiner. 
		 Os elementos vetoriais são colocados em armazenamento contíguo para que possam ser acessados ​​e percorridos
		  usando iteradores. Nos vetores, os dados são inseridos no final

	--- principais funçoes de vector que sao assoaciadas a iterator:
	
  	begin () - Retorna um iterador para o primeiro elemento no mapa 
	end () - Retorna um iterador para o elemento teórico que segue o último elemento no mapa
	rbegin() – Retorna um iterador reverso apontando para o último elemento no vetor (início reverso). Ele se move do último para o primeiro elemento
	rend() – Retorna um iterador reverso apontando para o elemento teórico que precede o primeiro elemento no vetor (considerado como final reverso)
	cbegin() – Retorna um iterador constante apontando para o primeiro elemento no vetor.
	cend() – Retorna um iterador constante apontando para o elemento teórico que segue o último elemento no vetor.
	crbegin() – Retorna um iterador reverso constante apontando para o último elemento no vetor (início reverso). Ele se move do último para o primeiro elemento
	crend() – Retorna um iterador reverso constante apontando para o elemento teórico que precede o primeiro elemento no vetor (considerado como final reverso)

	fill consntruc - A função 'fill' atribui o valor 'val' a todos os elementos no intervalo [begin, end),
			Porque o construtor só aloca a memória exata necessária
	resize(n) – Redimensiona o contêiner para que contenha 'n' elementos.
	reserve() – Solicita que a capacidade do vetor seja pelo menos suficiente para conter n elementos.

	at(g) – Retorna uma referência ao elemento na posição 'g' no vetor
	front() – Retorna uma referência ao primeiro elemento do vetor
	back() – Retorna uma referência ao último elemento do vetor

	assign() – Atribui um novo valor aos elementos do vetor substituindo os antigos
	push_back() – Ele empurra os elementos para um vetor de trás
	pop_back() – É usado para pop ou remover elementos de um vetor da parte de trás.
	insert() – Insere novos elementos antes do elemento na posição especificada
	erase() – É usado para remover elementos de um contêiner da posição ou intervalo especificado.
*/