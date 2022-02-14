/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:11:56 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/14 23:28:21 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Container_Include/main_tester.hpp"

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

void contructors()
{
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

	print_title("COPY CONSTRUCTOR WITH STRING", "ft::vector");
	std::vector<std::string> cop(5, "yo");
	std::vector<std::string> copy(cop);
	std::vector<std::string>::iterator copyIt = copy.begin();

	while (copyIt != copy.end())
		std::cout << LET << *copyIt++ << ' ';
	std::cout << std::endl;

	print_title("ASSIGNATION OPERATOR", "ft::vector");
	ft::vector<int> ft_vector_assignation;
	ft_vector_assignation = ft_vector_copy;
	print_size(ft_vector_assignation, "ft_vector_assignation");
	print_vector(ft_vector_assignation, "ft_vector_assignation");

	print_title("ASSIGNATION OPERATOR WITH STRING", "ft::vector");
	std::vector<std::string> o1(5, "cy");
	std::vector<std::string> o3 = o1;
	std::vector<std::string>::iterator oit = o3.begin();

	while (oit != o3.end())
		std::cout << LET << *oit++ << ' ';
	std::cout << std::endl;
	std::cout << std::endl;
}

void iterators()
{
	print_title("ITERATOR TEST", "ft::vector");

	ft::vector<char> ft_vector;

	for (int i = 65; i < 80; i++)
		ft_vector.push_back(i);
	//ft::vector<char>::iterator it = ft_vector.begin();
	

	std::cout << "ft_vector (ITERATOR): ";
	for (ft::vector<char>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "ft_vector (CONST_ITERATOR): ";
	for (ft::vector<char>::const_iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "ft_vector (REVERSE_ITERATOR): ";
	for (ft::vector<char>::reverse_iterator rit = ft_vector.rbegin(); rit != ft_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << "\n" << std::endl;
	std::cout << std::endl;
	
	std::cout << "ft_vector (CONST_REVERSE_ITERATOR): ";
	for (ft::vector<char>::const_reverse_iterator rit = ft_vector.rbegin(); rit != ft_vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "\n";
}

void capacity()
{
	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, capacity, resize, empty, reserve");
	
	ft::vector<int> tab(5, 10);
	print_title("BEFORE RESIZE", "ft::vector");
	std::cout << LET << "size : " << tab.size() << std::endl;

	tab.resize(10, 10);
	print_title("AFTER RESIZE", "(10)");
	std::cout << LET << "size : " << tab.size() << std::endl;

	print_title("VECTOR EMPTY()");
	print_size(tab, "ft_vector");

	print_title("VECTOR RESERVE", "(20)");
	tab.reserve(20);
	std::cout << LET << "size : " << tab.size() 
		<< LET << ", capacity : " << tab.capacity() << std::endl;
	std::cout << std::endl;
}

void	access()
{
	print_title("ELEMENT ACCESS" , "ft::vector");
	ft::vector<int> tab;
	for (int i = 65; i < 80; i++)
		tab.push_back(i);
	print_vector(tab, "ft_vector");

	print_title("VECTOR AT()" , "ft::vector");
	std::cout << LET << "tab at 5 : " << tab.at(5) << std::endl;

	print_title("VECTOR FRONT()", "ft::vector");
	std::cout << LET << "front : " << tab.front() << std::endl;

	print_title("VECTOR BACK()", "ft::vector");
	std::cout << LET << "back : " << tab.back() << std::endl;

	std::cout << std::endl;
}

void	modifiers()
{
	print_title("MODIFIERS", "ft::vector");

	ft::vector<int> tab(3, 2);
	
	print_vector(tab, "ft_vector(tab)");
	
	print_title("VECTOR PUSH_BACK", "(5)");
	tab.push_back(5);
	print_vector(tab, "ft_vector(tab)");

	print_title("VECTOR POP_BACK()", "Remove 5");
	tab.pop_back();
	print_vector(tab, "ft_vector(tab)");

	print_title("VECTOR ASSIGN(n, val)", "assign two 3 : ");
	tab.assign(2, 3);
	print_vector(tab, "ft_vector(tab)");

	print_title("VECTOR INSERT", "(insert 1");
	tab.insert(tab.begin(), 1);
	print_vector(tab, "ft_vector(tab)");

	print_title("VECTOR ERASE(position)", "erase 1");
	tab.erase(tab.begin());
	print_vector(tab, "ft_vector(tab)");

	print_title("VECTOR CLEAR()", "All");
	tab.clear();
	print_size(tab, "ft_vector after clear()");

	ft::vector<int> a(3, 10);
	ft::vector<int> b(5, 7);
	
	print_title("BEFORE SWAP", "ft::vector");
	std::cout << LET << "a : ";
	print_vector(a, "ft_vector(a)");
	std::cout  << "b : ";
	print_vector(b, "ft_vector(b)");
	print_title("AFTER SWAP", "ft::vector");
	a.swap(b);
	std::cout << LET << "a : ";
	print_vector(a, "ft_vector(a)");
	std::cout << "b : ";
	print_vector(b, "ft_vector(b)");

	std::cout << std::endl;
}

void operators()
{
	print_title("OPERATIONAL OPERATOR", "ft::vector");

	ft::vector<int> vect (3,100);
	ft::vector<int> copy(vect);
	
	std::cout << "0#  == " << (vect == copy) << std::endl;
	std::cout << "1#  != " << (vect != copy) << std::endl;
	std::cout << "2#  <  " << (vect < copy) << std::endl;
	std::cout << "3#  <= " << (vect <= copy) << std::endl;
	std::cout << "4#  >  " << (vect > copy) << std::endl;
	std::cout << "5#  >= " << (vect >= copy) << std::endl;
	std::cout << "6#  [] " << vect[0] << std::endl;
	
	print_title("OPERATIONAL OPERATOR", "different operations");
	copy.erase(copy.begin());
	std::cout << "7#  == " << (vect == copy) << std::endl;
	std::cout << "8#  != " << (vect != copy) << std::endl;
	std::cout << "9#  <  " << (vect < copy) << std::endl;
	std::cout << "10# <= " << (vect <= copy) << std::endl;
	std::cout << "11# >  " << (vect > copy) << std::endl;
	std::cout << "12# >= " << (vect >= copy) << std::endl;
	std::cout << "13# [] " << vect[0] << std::endl;
}

void test_vector()
{
	int start = clock();
	
	contructors();
	iterators();
	capacity();
	access();
	modifiers();
	operators();

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