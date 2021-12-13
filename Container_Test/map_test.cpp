/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:17 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/13 22:14:51 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

void test_map()
{
    std::cout << "| MAP TEST |\n\n";

    ft::Map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['f']=70;

    ft::Map<char,int> second (first.begin(),first.end());

    ft::Map<char,int> third (second);
    
    ft::Map<char,int> fourth = third;

    std::cout << "first:\n";
    for (ft::Map<char,int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nsecond:\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nthird:\n";
    for (ft::Map<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
    
    std::cout << "\nfourth:\n";
    for (ft::Map<char,int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nsecond empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
        
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "max_size: " << second.max_size() << "\n";

    std::cout << "\nsecond['a'] is " << second['a'] << '\n';
    std::cout << "second['a'] is " << second['c'] << '\n';

    second.insert(ft::_pair<const char, int>('e', 42));
    std::cout << "\nsecond.insert(_pair<const char, int>('e', 42)):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    second.insert(ft::_pair<const char, int>('e', 42));
    std::cout << "\nsecond.insert(_pair<const char, int>('e', 42)):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
            
    second.erase('a');
    std::cout << "\nsecond.erase('a'):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    third.swap(second);
    std::cout << "\nthird.swap('second'):\n";
    std::cout << "third: \n";
    for (ft::Map<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    ft::Map<char,int>::key_compare mycomp = third.key_comp();
    ft::Map<char,int>::iterator it = third.begin();
    ft::Map<char,int>::iterator it2 = third.begin();
    it2++;
    if (mycomp(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "\nmy comp == less\n";
    if (third.value_comp()(ft::_pair<const char, int>('c', 42), ft::_pair<const char, int>('d', 44)) == true)
        std::cout << "value_comp == less\n";

    std::cout << "\nthird.find('b'): \n";
    std::cout << "b => " << third.find('b').base()->mapped_value << '\n';

    std::cout << "third.count('b'): \n";
    std::cout << third.count('b') << "\n";

    ft::Map<char,int>::iterator it3 = third.lower_bound('b');
    std::cout << "\nthird.lower_bound ('b'):\n";
    std::cout << it3.base()->key_value << " " << it3.base()->mapped_value << "\n";
    
    ft::Map<char,int>::iterator it4 = third.upper_bound('b');
    std::cout << "third.upper_bound ('b'):\n";
    std::cout << it4.base()->key_value << " " << it4.base()->mapped_value << "\n";

    ft::_pair<ft::Map<char,int>::iterator,ft::Map<char,int>::iterator> ret = third.equal_range('c');

    std::cout << "\n";
    std::cout << "lower bound points to: ";
    std::cout << ret.key_value.base()->key_value << " => " << ret.key_value.base()->mapped_value << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.mapped_value.base()->key_value << " => " << ret.mapped_value.base()->mapped_value << '\n';
    
}







/*
    begin () - Retorna um iterador para o primeiro elemento no mapa 
    end () - Retorna um iterador para o elemento teórico que segue o último elemento no mapa
    size () - Retorna o número de elementos no map
    max_size () - Retorna o número máximo de elementos que o mapa pode conter
    vazio () - Retorna se o mapa está vazio, insert par (keyvalue, mapvalue) - Adiciona um novo elemento para apagar o mapa
       (posição do iterador)- Remove o elemento na posição apontada pelo iterador
    erase (const g) - Remove o valor-chave g do mapa
    clear () - Remove todos os elementos do mapa 
*/