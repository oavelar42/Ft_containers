/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:11:56 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/15 17:00:19 by oavelar          ###   ########.fr       */
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
  std::cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << std::endl;
  std::cout << name << " empty() (1: true 0: false): " << vector.empty() << std::endl;
}

void contructors()
{
	print_title("DEFAULT CONSTRUCTOR", "vector");
	ft::vector<int> vector;
	print_size(vector, "vector");

	print_title("FILL CONSTRUCTOR", "vector");
	ft::vector<int> vector_fill(10, 42);
	print_size(vector_fill, "vector_fill");
	print_vector(vector_fill, "vector_fill");

	print_title("RANGE CONSTRUCTOR", "vector");
	ft::vector<int> vector_range(vector_fill.begin(), vector_fill.end());
	print_size(vector_range, "vector_range");
	print_vector(vector_range, "vector_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "vector");
	ft::vector<int> vector_copy(vector_range);
	print_size(vector_copy, "vector_copy");
	print_vector(vector_copy, "vector_copy");

	print_title("COPY CONSTRUCTOR WITH STRING", "vector");
	std::vector<std::string> cop(5, "yo");
	std::vector<std::string> copy(cop);
	std::vector<std::string>::iterator copyIt = copy.begin();

	while (copyIt != copy.end())
		std::cout << LET << *copyIt++ << ' ';
	std::cout << std::endl;

	print_title("ASSIGNATION OPERATOR", "vector");
	ft::vector<int> vector_assignation;
	vector_assignation = vector_copy;
	print_size(vector_assignation, "vector_assignation");
	print_vector(vector_assignation, "vector_assignation");

	print_title("ASSIGNATION OPERATOR WITH STRING", "vector");
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
	print_title("ITERATOR TEST", "vector");

	ft::vector<char> vector;

	for (int i = 65; i < 80; i++)
		vector.push_back(i);

	std::cout << "vector (ITERATOR): ";
	for (ft::vector<char>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "vector (CONST_ITERATOR): ";
	for (ft::vector<char>::const_iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "vector (REVERSE_ITERATOR): ";
	for (ft::vector<char>::reverse_iterator rit = vector.rbegin(); rit != vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << "\n" << std::endl;
	std::cout << std::endl;
	
	std::cout << "vector (CONST_REVERSE_ITERATOR): ";
	for (ft::vector<char>::const_reverse_iterator rit = vector.rbegin(); rit != vector.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << "\n";
}

void capacity()
{
	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, capacity, resize, empty, reserve");
	
	ft::vector<int> tab(5, 10);
	print_title("BEFORE RESIZE", "vector");
	std::cout << LET << "size : " << tab.size() << std::endl;

	tab.resize(10, 10);
	print_title("AFTER RESIZE", "(10)");
	std::cout << LET << "size : " << tab.size() << std::endl;

	print_title("VECTOR EMPTY()", "vector");
	print_size(tab, "vector");

	print_title("VECTOR RESERVE", "(20)");
	tab.reserve(20);
	std::cout << LET << "size : " << tab.size() 
		<< LET << ", capacity : " << tab.capacity() << std::endl;
	std::cout << std::endl;
}

void	access()
{
	print_title("ELEMENT ACCESS" , "vector");
	ft::vector<int> tab;
	for (int i = 65; i < 80; i++)
		tab.push_back(i);
	print_vector(tab, "vector");

	print_title("VECTOR AT()" , "vector");
	std::cout << LET << "tab at 5 : " << tab.at(5) << std::endl;

	print_title("VECTOR FRONT()", "vector");
	std::cout << LET << "front : " << tab.front() << std::endl;

	print_title("VECTOR BACK()", "vector");
	std::cout << LET << "back : " << tab.back() << std::endl;

	std::cout << std::endl;
}

void	modifiers()
{
	print_title("MODIFIERS", "vector");

	ft::vector<int> tab(3, 2);
	
	print_vector(tab, "vector(tab)");
	
	print_title("VECTOR PUSH_BACK", "(5)");
	tab.push_back(5);
	print_vector(tab, "vector(tab)");

	print_title("VECTOR POP_BACK()", "Remove 5");
	tab.pop_back();
	print_vector(tab, "vector(tab)");

	print_title("VECTOR ASSIGN(n, val)", "assign two 3 : ");
	tab.assign(2, 3);
	print_vector(tab, "vector(tab)");

	print_title("VECTOR INSERT", "(insert 1");
	tab.insert(tab.begin(), 1);
	print_vector(tab, "vector(tab)");

	print_title("VECTOR ERASE(position)", "erase 1");
	tab.erase(tab.begin());
	print_vector(tab, "vector(tab)");

	print_title("VECTOR CLEAR()", "All");
	tab.clear();
	print_size(tab, "vector after clear()");

	ft::vector<int> a(3, 10);
	ft::vector<int> b(5, 7);
	
	print_title("BEFORE SWAP", "vector");
	std::cout << LET << "a : ";
	print_vector(a, "vector(a)");
	std::cout  << "b : ";
	print_vector(b, "vector(b)");
	print_title("AFTER SWAP", "vector");
	a.swap(b);
	std::cout << LET << "a : ";
	print_vector(a, "vector(a)");
	std::cout << "b : ";
	print_vector(b, "vector(b)");

	std::cout << std::endl;
}

void operators()
{
	print_title("OPERATIONAL OPERATOR", "vector");

	ft::vector<int> vect (100);
	ft::vector<int> copy(50);
	
	std::cout << "0-> (vect == copy) |==| " << (vect == copy) << std::endl;
	std::cout << "1-> (vect != copy) |!=| " << (vect != copy) << std::endl;
	std::cout << "2-> (vect < copy)  |< | " << (vect < copy) << std::endl;
	std::cout << "3-> (vect <= copy) |<=| " << (vect <= copy) << std::endl;
	std::cout << "4-> (vect > copy)  | >| " << (vect > copy) << std::endl;
	std::cout << "5-> (vect >= copy) |>=| " << (vect >= copy) << std::endl;
	std::cout << "6->  vect[0] 	   |[]| " << vect[0] << std::endl;
	
	print_title("OPERATIONAL OPERATOR", "different operations");
	ft::vector<int> str(50);
	std::cout << "7-> (str == copy)  |==| " << (str == copy) << std::endl;
	std::cout << "8-> (str != copy)  |!=| " << (str != copy) << std::endl;
	std::cout << "9-> (str < copy)   |< | " << (str < copy) << std::endl;
	std::cout << "10-> (str <= copy) |<=| "  << (str <= copy) << std::endl;
	std::cout << "11-> (str > copy)  | >| " << (str > copy) << std::endl;
	std::cout << "12-> (str >= copy) |>=| " << (str >= copy) << std::endl;
	std::cout << "13->  str[0]	   |[]| " << str[0] << std::endl;
}

void test_vector()
{
	//int start = clock();
	
	contructors();
	iterators();
	capacity();
	access();
	modifiers();
	operators();

	std::cout << "\n";
	//int end = clock();
	//std::cout << RED "Execution time (vector): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
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