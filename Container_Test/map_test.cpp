/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:17 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/25 14:31:46 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_tester.hpp"

void print_map(ft::map<char, int> map, std::string name)
{
	std::cout << name << ":\n";
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_size(ft::map<char, int> map, std::string name)
{
	std::cout << name << " size: " << map.size() << ", max_size: " << map.max_size() << std::endl;
	std::cout << name << " empty() (1: true 0: false): " << map.empty() << std::endl;
	std::cout << std::endl;
}

void test_map(void)
{
	int start = clock();

	print_title("CONSTRUCTOR", "ft::map");

	ft::map<char, int> ft_map;
	print_size(ft_map, "ft_map");

	char c = 'a';
	for (int i = 1; i <= 13; i++, c++)
	{
		ft_map[c] = i;
	}
	print_map(ft_map, "ft_map");
	print_size(ft_map, "ft_map");

	print_title("RANGE", "ft::map");
	ft::map<char, int> ft_map_range(ft_map.begin(), ft_map.end());
	print_size(ft_map_range, "ft_map_range");
	print_map(ft_map_range, "ft_map_range");

//É chamado quando um novo objeto é criado a partir de um objeto existente, como uma cópia do objeto existente
	print_title("COPY CONSTRUCTOR (copy of range)", "ft::map");
	ft::map<char, int> ft_map_copy(ft_map_range);
	print_size(ft_map_copy, "ft_map_copy");
	print_map(ft_map_copy, "ft_map_copy");

//Este operador é chamado quando um objeto já inicializado recebe um novo valor de outro objeto existente.
	print_title("ASSIGNATION OPERATOR", "ft::map");
	ft::map<char, int> ft_map_assignation;
	ft_map_assignation = ft_map_copy;
	print_size(ft_map_assignation, "ft_map_assignation");
	print_map(ft_map_assignation, "ft_map_assignation");

	print_title("ITERATORS TESTS");
	std::cout << "ft_map (iterator): ";
	for (ft::map<char, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "ft_map (const_iterator): ";
	for (ft::map<char, int>::const_iterator it = ft_map.begin(); it != ft_map.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "ft_map (reverse_iterator): ";
	for (ft::map<char, int>::reverse_iterator rit = ft_map.rbegin(); rit != ft_map.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "ft_map (const_reverse_iterator): ";
	for (ft::map<char, int>::const_reverse_iterator rit = ft_map.rbegin(); rit != ft_map.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;

	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, empty");
	print_size(ft_map, "ft_map");

	print_title("MAP INSERT(val)");
	for (int i = 14; i <= 19; i++, c++)
	{
		ft_map.insert(ft::make_pair(c, i));
	}
	print_map(ft_map, "ft_map");
	print_size(ft_map, "ft_map");

	print_title("MAP INSERT(position, val)");
	for (int i = 20; i <= 26; i++, c++)
	{
		ft_map.insert(ft::make_pair(c, i));
	}
	print_map(ft_map, "ft_map");
	print_size(ft_map, "ft_map");

	print_title("MAP INSERT(first, last)", "map -> map_copy");
	print_title("BEFORE INSERT");
	print_map(ft_map_copy, "ft_map_copy");

	print_title("AFTER INSERT");
	ft_map_copy.insert(ft_map.begin(), ft_map.end());
	print_map(ft_map_copy, "ft_map_copy");
	print_size(ft_map_copy, "ft_map_copy");

	ft::map<char, int>::iterator ft_it_half = ft_map_copy.find('n');
	for (ft::map<char, int>::iterator it = ft_map_copy.begin(); it != ft_it_half; it++)
	ft_map_copy.erase(it);
	print_map(ft_map_copy, "ft_map_copy");
	print_size(ft_map_copy, "ft_map_copy");

	print_title("MAP ERASE(key)", "erasing another half of map_copy");
	c = 'n';
	for (int i = 0; i < 6; i++, c++)
	{
		ft_map_copy.erase(c);
	}
	print_map(ft_map_copy, "ft_map_copy");
	print_size(ft_map_copy, "ft_map_copy");

	print_title("MAP ERASE(first, last)", "finishing the job map_copy");
	ft_map_copy.erase(ft_map_copy.begin(), ft_map_copy.end());
	print_map(ft_map_copy, "ft_map_copy");
	print_size(ft_map_copy, "ft_map_copy");

	print_title("MAP SWAP() (MEMBER)", "swaping map_range and map_copy");
	print_title("BEFORE SWAP");
	print_map(ft_map_range, "ft_map_range");
	print_map(ft_map_copy, "ft_map_copy");

	ft_map_range.swap(ft_map_copy);
	print_title("AFTER SWAP");
	print_map(ft_map_range, "ft_map_range");
	print_map(ft_map_copy, "ft_map_copy");

	print_title("MAP CLEAR", "clearing map");
	print_title("BEFORE");
	print_map(ft_map_copy, "ft_map_copy");
	print_size(ft_map_copy, "ft_map_copy");
	ft_map_copy.clear();
	print_title("AFTER");
	print_map(ft_map_copy, "ft_map_copy");
	print_size(ft_map_copy, "ft_map_copy");

	print_title("My ft_map still has elements from 1 to 26...");
	print_map(ft_map, "ft_map");

	print_title("MAP FIND(key) const and non_const");
	ft::map<char, int>::iterator find_a = ft_map.find('a');
	ft::map<char, int>::const_iterator find_z = ft_map.find('z');
	std::cout << "find('a'): " << (*find_a).first << " = " << (*find_a).second << '\n';
	std::cout << "find('z'): " << (*find_z).first << " = " << (*find_z).second << '\n';

	print_title("MAP COUNT(key)");
	std::cout << 'a';
	if (ft_map.count('a') > 0)
	std::cout << " is an element of ft_map.\n";
	else
	std::cout << " is not an element of ft_map.\n";
	std::cout << '1';
	if (ft_map.count('1') > 0)
	std::cout << " is an element of ft_map.\n";
	else
	std::cout << " is not an element of ft_map.\n";

	print_title("MAP LOWER_BOUND AND UPPER_BOUND", "using it to erase from b to g");
	ft::map<char,int>::iterator itlow = ft_map.lower_bound('b');
	ft::map<char,int>::iterator itup = ft_map.upper_bound('g');
	ft_map.erase(itlow, itup);
	print_map(ft_map, "ft_map");
	print_size(ft_map, "ft_map");

	print_title("MAP EQUAL_RANGE", "for h");
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = ft_map.equal_range('h');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	print_title("MAP KEY_COMP AND VALUE_COMP", "display everything lower than m");
	ft::map<char,int>::key_compare mycomp = ft_map.key_comp();

	char highest_key = 'm';
	ft::pair<char,int> highest = *ft_map.find('m');

	ft::map<char,int>::iterator it = ft_map.begin();
	while (ft_map.value_comp()(*it, highest) \
		&& mycomp((*it).first, highest_key))
	{
		std::cout << it->first << " => " << it->second << '\n';
		it++;
	}

	print_title("MAP ERASE(all)", "all empty and clear");
	ft_map.erase(ft_map.begin(), ft_map.end());
	print_map(ft_map, "ft_map");
	print_size(ft_map, "ft_map");

	int end = clock();
	std::cout << RED "Execution time (map): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
	
	std::cout << "\n";
	std::cout << "\n";
}






















/*
	MAP e basicamente um container que tem a chave e o tamanho ( ft::map < chave, tamanho > map)
	uso o iterator para poder navegar dentro desse map e encotrar o que solicito de acordo com as funções
	
	--- principais funçoes de MAP:
	
	begin () - Retorna um iterador para o primeiro elemento no mapa 
	end () - Retorna um iterador para o elemento teórico que segue o último elemento no mapa
	at() a função é usada para retornar a referência ao elemento associado à chave
	size () - Retorna o número de elementos no map
	max_size () - Retorna o número máximo de elementos que o mapa pode conter
	empty () - Retorna se o mapa está vazio, insert par (keyvalue, mapvalue) - Adiciona um novo elemento para apagar o mapa
		 (posição do iterador)- Remove o elemento na posição apontada pelo iterador
	erase (const g) - Remove o valor-chave g do mapa
	clear () - Remove todos os elementos do mapa 

	lower_bound retorna um iterador apontando para o primeiro elemento no intervalo 
			[first, last) que tem um valor não inferior a 'val '. 
	upper_bound retorna um iterador apontando para o primeiro elemento no intervalo 
			[primeiro, último) que tem um valor maior que 'val'. 

	operator[] – Este operador é usado para referenciar o elemento presente na posição dada dentro do operador.

	equal_range() em C++ STL – Retorna um iterador de pares. O par refere-se aos limites de um intervalo que 
			inclui todos os elementos do contêiner que possuem uma chave equivalente a k

	iterator -  Um iterador é um objeto (como um ponteiro) que aponta para um elemento dentro do contêiner.
				Podemos usar iteradores para percorrer o conteúdo do contêiner. Eles podem ser visualizados como algo semelhante 
				a um ponteiro apontando para algum local e podemos acessar o conteúdo desse local específico usando-os.	
				server para navegar em uma coleçao de dados , podemos dizer que um iterator
				vai apontar para um item dentro de um container ,

	const_iterator - a diferença do const iterator como ja haviamos aprendido sobre const e que o 
				const_iterator não pode ser alterado, ele e usado apenas para acesso e não pode ser usado
				para ser modificado

	insert - e utilizada para inserir elementos de uma chave especifica no container 
						ex.:   insert < chave , elemento >

	pair - usada para combinar 2 valores que podem ser de tipos de diferentes 
					ex.: pair < int , char >
	make_pair - Esta função de template permite criar um par de valores sem escrever os tipos explicitamente. 

*/