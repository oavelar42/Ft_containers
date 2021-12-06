/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/06 17:16:19 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <new>
# include <limits>
# include <utility>
# include <iterator>
# include "map_rev_ite.hpp"

# define OTA "\x1B[36m"
# define RED "\x1B[31m"
# define OFF "\033[0m"
# define GRE "\x1B[32m"

namespace ft
{
     /*********************/
    /*     Class Map     */
    /*********************/
    template < class key, class T, class Compare = std::less<key>, class Alloc = std::allocator<std::pair<const key,T>>>
    class Map
    {
        public :
            
                        /*     Member types     */
            typedef key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef std::pair<const key_type, mapped_type>                      value_type;
            typedef Compare                                                     key_compare;
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef typename map::iterator<key_type, mapped_type>               iterator;
            typedef typename map::const_iterator<key_type, mapped_type>         const_iterator;
            typedef typename map::reverse_iterator<key_type, mapped_type>       reverse_iterator;
            typedef typename map::const_reverse_iterator<key_type, mapped_type> const_reverse_iterator;
            typedef size_t                                                      size_type;
            
            class value_compare
            {
                friend class Map;
                    protected :
                        Compare comp;
                        value_compare (Compare c) : comp(c) { }
                    public :
                        typedef bool result_type;
                        typedef value_type first_arg_type;
                        typedef value_type second_arg_type;
                        bool operator() (const valeu_type& x, const value_type& y) const
                        {
                            return comp(x.key_value, y.key_value);
                        }
            };
        private:
            
            /*********************************/
            /*     Member types | private    */
            /*********************************/
            typedef typename allocator_type::template rebind<map_node<key_type, mapped_type> >::other   node_alloc; //equivalent allocator fot type node
            typedef typename node_alloc::pointer                                                        node_pointer;
            typedef typename node_alloc::const_reference                                                node_const_reference;
                
            /****************************/
            /*     Members | private    */
            /****************************/
            map_node<key_type, mapped_type> *_tail;
            map_node<key_type, mapped_type> *_head;
            map_node<key_type, mapped_type> *_root;
            size_type                       _current_size;
            node_alloc                      _alloc_for_node;
            allocator_type                  _alloc;
            key_compare                     _key_comp;

        public:
            test_map();
            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
            explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(0), _current_size(0), _alloc(alloc), _key_comp(comp)
            {
                _head = create_node();
                _head->parent = create_node();

                _tail = _head->parent;
                _tail->parent = _head;
            }

            template <class InputIterator>
            Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
                typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) : _root(0), _current_size(0), _alloc(alloc), _key_comp(comp)
            {
                _head = create_node();
                _head->parent = create_node();
                _tail = _head->parent;
                _tail->parent = _head;

                while (first != last)
                    add_new_node(*(first++));
            }

            Map (const Map &x) : _root(0), _current_size(0), _alloc(x._alloc), _key_comp(x._key_comp)
            {
                _head = create_node();
                _head->parent = create_node();
                _tail = _head->parent;
                _tail->parent = _head;

                for (const_iterator it = x.begin(); it != x.end(); it++)
                    add_new_node(*it);
            }

            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            Map &operator=(const Map& x)
            {
                if (this != &x)
                {
                    clear();
                    _alloc = x._alloc;
                    _key_comp = x._key_comp;
                    insert(x.begin(), x.end());
                }
                return(*this);
            }
            
            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~Map()
            {
                clear();
                destroy_deallocate_node(_head);
                destroy_deallocate_node(_tail);
            }

             /***************************************************************************/
            /*** iterators --------------------------------------------------------- ***/
            iterator begin() {
                return iterator(_head);
            }
            
            const_iterator begin() const {
                typedef _pair<const Key, const T> const_pair;
                return const_iterator(reinterpret_cast<const_pair *>(_head));
            }
            
            iterator end() {
                return iterator(_tail);
            }

            const_iterator end() const {
                typedef _pair<const Key, const T> const_pair;
                return const_iterator(reinterpret_cast<const_pair *>(_tail));
            }

            reverse_iterator rbegin() {
                return reverse_iterator(_tail);
            }
            
            const_reverse_iterator rbegin() const {
                return const_reverse_iterator(_tail);
            }
            
            reverse_iterator rend() {
                return reverse_iterator(_head);
            }
            const_reverse_iterator rend() const {
                return const_reverse_iterator(_head);
            }
            
            /***************************************************************************/
            /*** Capacity ---------------------------------------------------------- ***/
            bool empty() const {
                return (_n == 0);
            }
            
            size_type size() const {
                return _n;
            }
            
            size_type max_size() const {
                return std::numeric_limits<difference_type>::max() / sizeof(value_type);
            }

            /***************************************************************************/
            /*** Element access ---------------------------------------------------- ***/
            mapped_type &operator[](const key_type& k)
            {
                return ((*(insert(std::make_pair(k, mapped_type()))).first).second);
            }

             /***************************************************************************/
            /*** Modifiers --------------------------------------------------------- ***/
              std::pair<iterator, bool>   insert(const value_type& val)
            {
                map_node<key_type, mapped_type> *new_node;
                if ((new_node = find_node(val.first, _root)) != 0)
                {
                    iterator it(new_node);
                    return (std::make_pair(it, false));
                }
                new_node = add_new_node(val);
                iterator it(new_node);
                return (std::make_pair(it, true));
            }
            iterator                    insert(iterator position, const value_type& val)
            {
                map_node<key_type, mapped_type> *new_node;
                if ((new_node = find_node(val.first, position.get_node())) != 0)
                {
                    iterator it(new_node);
                    return (it);
                }
                iterator it(add_new_node(val));
                return (it);
            }
            template <class InputIterator>
            void                        insert(InputIterator first, InputIterator last, typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            {
                map_node<key_type, mapped_type> *new_node;
                for (; first != last; first++)
                {
                    if ((new_node = find_node((*first).first, _root)) != 0)
                        continue;
                    new_node = add_new_node(*first);
                }
            }

            void                        erase (iterator position)
            {
                delete_node(position.get_node());
            }

            size_type erase (const key_type& k)
            {
                size_type ret = 0;
                iterator ite = this->end();
                for (iterator it = this->begin(); it != ite; it++)
                {
                    if (it.base()->key_value == k)
                    {
                        erase(it);
                        ret++;
                    }
                }
                return ret;
            }

            void erase (iterator first, iterator last) 
            {
                while (first != last)
                    erase(first++);
            }
            
            void swap (Map& x) {
                std::swap(_head, x._head);
                std::swap(_tail, x._tail);
                std::swap(_n, x._n);
            }

            void                        clear()
            {
                erase(this->begin(), this->end());
            }

             /***************************************************************************/
            /*** Observers --------------------------------------------------------- ***/

    };
 

}

#endif