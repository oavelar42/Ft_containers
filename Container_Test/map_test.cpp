/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:17 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/03 17:50:26 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_tester.hpp"
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <cstddef>
#include "map.hpp" 
#include <time.h>

#ifndef NAMESPACE
    #define NAMESPACE ft
#endif

template<class T1, class T2>
void print_elem_map(NAMESPACE::map<T1, T2> mp)
{
    typename NAMESPACE::map<T1, T2>::iterator it = mp.begin();
    typename NAMESPACE::map<T1, T2>::iterator ite = mp.end();

    typename NAMESPACE::map<T1, T2>::const_iterator ct_it = mp.begin();
    typename NAMESPACE::map<T1, T2>::const_iterator ct_ite = mp.end();

    typename NAMESPACE::map<T1, T2>::reverse_iterator rev_it = mp.rbegin();
    typename NAMESPACE::map<T1, T2>::reverse_iterator rev_ite = mp.rend();

    typename NAMESPACE::map<T1, T2>::const_reverse_iterator crev_it = mp.rbegin();
    typename NAMESPACE::map<T1, T2>::const_reverse_iterator crev_ite = mp.rend();
    
    std::cout << "Elem (iterator):               \n";
    while(it != ite)
    {
        std::cout << "fisrt: " << it->first << "| Second: " << it->second << "\n";
        it++;
    }
    std::cout << "Elem (const_iterator):         \n";
    while(ct_it != ct_ite)
    {
        std::cout << "fisrt: " << ct_it->first << "| Second: " << ct_it->second << "\n";
        ct_it++;
    }
    std::cout << "Elem (reverse_iterator):       \n";
    while(rev_it != rev_ite)
    {
        std::cout << "fisrt: " << rev_it->first << "| Second: " << rev_it->second << "\n";
        rev_it++;
    }
    std::cout << "Elem (const_reverse_iterator): \n";
    while(crev_it != crev_ite)
    {
        std::cout << "fisrt: " << crev_it->first << "| Second: " << crev_it->second << "\n";
        crev_it++;
    }
    if (!mp.empty())
        std::cout << "operator[4]: " << mp[4] << std::endl;
    std::cout << "\n";
}

template<class T1, class T2>
void print_size_map(NAMESPACE::map<T1, T2> mp)
{
    std::cout << "Empty:    " << mp.empty() << std::endl;
    std::cout << "Size:     " << mp.size() << std::endl;
    std::cout << "Max_Size: " << mp.max_size() << std::endl;
}

void map(void)
{
    int start = clock();
    std::cout << "#######" << std::endl;
    std::cout << "MAP" << std::endl;
    std::cout << "#######" << std::endl;

    std::cout << "Constructors\n\n";
    
    std::cout << "Default:" << std::endl;
    NAMESPACE::map<int, int> mp;
    NAMESPACE::map<int, int> mp_;

    std::cout << "Let's try the insert(value_type) function" << std::endl;
    NAMESPACE::pair<int, int> foo;
    foo = NAMESPACE::make_pair(1, 10);
    mp.insert(foo);
    mp.insert(NAMESPACE::map<int, int>::value_type(5, 30));
    mp.insert(NAMESPACE::map<int, int>::value_type(2, 15));
    mp.insert(NAMESPACE::map<int, int>::value_type(4, 25));
    mp.insert(NAMESPACE::map<int, int>::value_type(3, 20));
    print_elem_map(mp);
    print_size_map(mp);
    
    std::cout << "Let's try the insert(position, val) function" << std::endl;
    mp.insert(mp.begin(), NAMESPACE::map<int, int>::value_type(6, 35));
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Let's try the insert(first, last) function. With an empty map instance of course !" << std::endl;
    mp_.insert(mp.begin(), mp.end());
    print_elem_map(mp_);
    print_size_map(mp_);

    std::cout << "Range:" << std::endl;
    NAMESPACE::map<int, int> mp_range(mp.begin(), (--(mp.end())));
    print_elem_map(mp_range);
    print_size_map(mp_range);

    std::cout << "Copy:" << std::endl;
    NAMESPACE::map<int, int> mp_cpy(mp);
    print_elem_map(mp_cpy);
    print_size_map(mp_cpy);

    std::cout << "Operator= :" << std::endl;
    NAMESPACE::map<int, int> mp_equal_op;
    mp_equal_op = mp;
    print_elem_map(mp_equal_op);
    print_size_map(mp_equal_op);

    std::cout << "Erase(position) :" << std::endl;
    mp.erase(++(++mp.begin()));
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Erase(key_type) :" << std::endl;
    mp.erase(5);
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Erase(first, last) :" << std::endl;
    mp.erase(mp.begin(), (++(++(++(mp.begin())))));
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Swap:" << std::endl;
    mp.swap(mp_range);
    std::cout << "mp:" << std::endl;
    print_elem_map(mp);
    print_size_map(mp);
    std::cout << "mp_range:" << std::endl;
    print_elem_map(mp_range);
    print_size_map(mp_range);

    std::cout << "Clear:" << std::endl;
    mp.clear();
    std::cout << "mp:" << std::endl;
    print_elem_map(mp);
    print_size_map(mp);

    int end = clock();
    std::cout << "Execution time (map): " << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
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