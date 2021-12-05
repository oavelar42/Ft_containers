/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:17 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/05 18:30:20 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

void test_map()
{
    std::cout << "|------------------------MAP TEST------------------------|" << std::endl;
    ft::Map<char, int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;
    first['l']=30;


}

int main(void)
{
    test_map();
    return (0);
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