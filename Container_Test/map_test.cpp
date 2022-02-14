/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:17 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/14 22:01:23 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Container_Include/main_tester.hpp"

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

void map_constructors()
{
	print_title("CONSTRUCTOR", "ft::map");
	
	ft::map<char, int> ft_map;
	print_size(ft_map, "ft_map");

	print_title("COPY CONSTRUCTOR (copy of range)", "ft::map");
	
	ft::map<char, int> ft_map_copy;
	ft_map_copy.insert(ft::make_pair('a', 1));
	print_size(ft_map_copy, "ft_map_copy");
	print_map(ft_map_copy, "ft_map_copy");

	ft_map_copy.insert(ft::make_pair('c', 13));
	print_size(ft_map_copy, "ft_map_copy");
	print_map(ft_map_copy, "ft_map_copy");
	
	ft_map_copy.insert(ft::make_pair('j', 3));
	print_size(ft_map_copy, "ft_map_copy");
	print_map(ft_map_copy, "ft_map_copy");

	print_title("FILL", "ft::map");

	ft::map<char, int> fill(ft_map_copy.begin(), ft_map_copy.end());
	print_size(fill, "fill");
	print_map(fill, "fill");

	print_title("ASSIGNATION OPERATOR", "ft::map");

	ft::map<char, int> oper = fill;
	print_size(oper, "operator");
	print_map(oper, "operator");
}

void map_iterator()
{
	print_title("ITERATORS TESTS");

	ft::map<char, int> m1;
	int a = 1;
	for (int i = 65; i < 73; i++, a++)
		m1.insert(ft::make_pair(i, a));


	print_title("ITERATORS TESTS", "ft::map");
	
	std::cout << "ft_map::(iterator): " << std::endl;
	for (ft::map<char, int>::iterator it = m1.begin(); it != m1.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "ft_map::(const_iterator): " << std::endl;
	for (ft::map<char, int>::const_iterator it = m1.begin(); it != m1.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "ft_map::(reverse_iterator): " << std::endl;
	for (ft::map<char, int>::reverse_iterator rit = m1.rbegin(); rit != m1.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "ft_map::(const_reverse_iterator): " << std::endl;
	for (ft::map<char, int>::const_reverse_iterator rit = m1.rbegin(); rit != m1.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
}

void map_capacity()
{
	print_title("ACCESSOR AND MEMBER FUNCTIONS , size, empty", "ft::map");

	ft::map<char, int> len;
	int c = 'a';
	for (int i = 14; i <= 19; i++, c++)
	{
		len.insert(ft::make_pair(c, i));
	}
	print_map(len, "ft_map");
	print_size(len, "ft_map");

	std::cout << std::endl;
}

void map_access()
{
	print_title("ELEMENT ACCESS");
	
	ft::map<std::string, char> src;
	
	src.insert(ft::make_pair("BTC", 'a'));
	src.insert(ft::make_pair("ETH", 'b'));
	src.insert(ft::make_pair("DOGE", 'c'));

	std::cout << LET << "src: [\"BTC\"] == " << src["BTC"] << std::endl;

	std::cout << std::endl;
}

void map_modifiers(int i)
{
	
	if (i == 0)
	{
		print_title("MAP INSERT(position, val)" , "ft::map");
		std::cout << LET;
		ft::map<char,int> mymap;

		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));
		mymap.insert (it, ft::pair<char,int>('c',400));


		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c')); //find operation used

		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
	}
}

void map_erase(int i)
{
	if (!i)
	{
		print_title("MAP ERASE(key)", "ft::map");
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase(it);

		mymap.erase('c');

		it=mymap.find('e');
		mymap.erase(it, mymap.end() );

		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
	}
}

void map_swap(int i)
{
	if (!i)
	{
		print_title("MAP SWAP()", "ft::map");
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;
		print_map(foo, "foo before swap");

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		print_map(bar, "bar before swap");

		foo.swap(bar);

		std::cout << "foo after swap:\n";
		for (ft::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;

		std::cout << "bar after swap:\n";
		for (ft::map<char,int>::iterator it = bar.begin(); it !=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
	}
	
}

void map_clear()
{
	print_title("MAP CLEAR", "ft::map");
	ft::map<int, int> tab;

	tab.insert(ft::make_pair(1, 5));
	tab.insert(ft::make_pair(3, 8));
	tab.insert(ft::make_pair(5, 66));
	tab.insert(ft::make_pair(13, 5));

	std::cout << LET "size: " << tab.size() << std::endl;
	std::cout << LET "empty() (1: true 0: false): " << tab.empty() << std::endl;
	tab.clear();
	std::cout << std::endl;
	std::cout << LET "After clear tab ..." << std::endl;
	std::cout << LET << "size: " << tab.size() << std::endl;
	std::cout << std::endl;
}

void map_operations(int i)
{
	if (!i)
	{
		print_title("MAP COUNT(key)");
		ft::map<char,int> mymap;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
			std::cout << std::endl;
		}
	}
}

void map_find()
{
	print_title("MAP FIND", "ft::map");

	ft::map<char, int> ft_map;
	int c = 'a';
	for (int i = 1; i <= 26; i++, c++)
	{
		ft_map.insert(ft::make_pair(c, i));
	}

	ft::map<char, int>::iterator find_a = ft_map.find('c');
	ft::map<char, int>::const_iterator find_z = ft_map.find('u');
	std::cout << "find('c'): " << (*find_a).first << " = " << (*find_a).second << '\n';
	std::cout << "find('u'): " << (*find_z).first << " = " << (*find_z).second << '\n';
}

void map_bound(int i)
{
	print_title("MAP LOWER_BOUND AND UPPER_BOUND", "ft::map");
	if (!i)
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow = mymap.lower_bound('b');
		itup = mymap.upper_bound('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);

		for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	else if (i == 2)
	{
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		std::cout << std::endl;
	}
}

void map_operators(int i)
{
	if (!i)
	{
		print_title("Operation", "Check all operation( true | false )");
		ft::map<int, char> ott;
		ft::map<int, char> mma;
		ft::map<int, char> eve;

		ott.insert(ft::make_pair(1, 'a'));
		ott.insert(ft::make_pair(2, 'b'));
		ott.insert(ft::make_pair(3, 'c'));

		mma.insert(ft::make_pair(7, 'Z'));
		mma.insert(ft::make_pair(8, 'Y'));
		mma.insert(ft::make_pair(9, 'X'));
		mma.insert(ft::make_pair(10, 'W'));
 
		eve.insert(ft::make_pair(1, 'a'));
		eve.insert(ft::make_pair(2, 'b'));
		eve.insert(ft::make_pair(3, 'c'));
 
		std::cout << std::boolalpha;
 
		std::cout << "ott == mma returns " << (ott == mma) << '\n';
		std::cout << "ott != mma returns " << (ott != mma) << '\n';
		std::cout << "ott <  mma returns " << (ott < mma) << '\n';
		std::cout << "ott <= mma returns " << (ott <= mma) << '\n';
		std::cout << "ott >  mma returns " << (ott > mma) << '\n';
		std::cout << "ott >= mma returns " << (ott >= mma) << '\n';
 
		std::cout << '\n';

		std::cout << "ott == eve returns " << (ott == eve) << '\n';
		std::cout << "ott != eve returns " << (ott != eve) << '\n';
		std::cout << "ott <  eve returns " << (ott < eve) << '\n';
		std::cout << "ott <= eve returns " << (ott <= eve) << '\n';
		std::cout << "ott >  eve returns " << (ott > eve) << '\n';
		std::cout << "ott >= eve returns " << (ott >= eve) << '\n';
	}
}

void test_map()
{
	int start = clock();

	map_constructors();
	map_iterator();
	map_capacity();
	map_access();
	map_modifiers(0);
	map_erase(0);
	map_swap(0);
	map_clear();
	map_operations(0);
	map_bound(0);
	map_bound(2);
	map_find();
	map_operators(0);

	std::cout << std::endl;
	int end = clock();
	std::cout << RED "Execution time (map): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
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