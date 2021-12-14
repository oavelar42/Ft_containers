/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/14 22:50:39 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <string.h>
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
    /*     Class pair    */
    /*********************/
    template<typename key, typename T>
    struct _pair
    {
        typedef key first_type;
        typedef T second_type;

        first_type key_value;
        second_type mapped_value;
        
        _pair* prev;
        _pair* next;

        _pair(first_type t1, second_type t2): key_value(t1), mapped_value(t2) {}
        
        _pair(first_type t1, second_type t2, _pair *prev_, _pair *next_): key_value(t1), mapped_value(t2), prev(prev_), next(next_) {}
        
        
        void insert_before(_pair *node) {
            if (this->prev) {
                node->prev = this->prev;
                this->prev->next = node;
            }
            node->next = this;
            this->prev = node;
        }
};

        /********************/
        /*     Iterator     */
        /********************/

            template <typename key, typename T>
    class MapIterator
    {
    public:      
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef std::ptrdiff_t difference_type;
    protected:
        typedef MapIterator<key, T> _Self;
        typedef _pair<key, T> pair;
        pair* _p;
    public:
        MapIterator(): _p(nullptr) { }
        MapIterator(pair* p): _p(p) { }
        MapIterator(const MapIterator &x): _p(x._p) { }
        virtual ~MapIterator() {};
        MapIterator &operator=(const MapIterator &x) { this->_p = x._p; return *this; }

        pair* base() const {
            return _p;
        }
        
        reference operator*() const { return _p->mapped_value; }
        pointer operator->() const { return &_p->mapped_value; }
        const_reference operator*() { return _p->mapped_value; }
        const_pointer operator->() { return &_p->mapped_value; }
        
        _Self& operator++() {
            _p = _p->next;
            return *this;
        }
        
        _Self operator++(int) { 
            _Self tmp = *this;
            _p = _p->next;
            return tmp;
        }
        
        _Self& operator--() {
            _p = _p->prev;
            return *this;
        }
        
        _Self operator--(int) {
            _Self tmp = *this;
            _p = _p->prev;
            return *this;
        }

        bool operator==(MapIterator const &other) const {
            return (this->_p == other._p);
        }
        bool operator!=(MapIterator const &other) const {
            return (this->_p != other._p);
        }
        bool operator<(MapIterator const &other) const {
            return (this->_p < other._p);
        }
        bool operator<=(MapIterator const &other) const {
            return (this->_p <= other._p);
        }
        bool operator>(MapIterator const &other) const {
            return (this->_p > other._p);
        }
        bool operator>=(MapIterator const &other) const {
            return (this->_p >= other._p);
        }
};
     /*********************/
    /*     Class Map     */
    /*********************/
        template <class Key, class T, class Compare = std::less<Key>>
        class Map
        {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef _pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef MapIterator<key_type, mapped_type> iterator;
            typedef MapIterator<const key_type, const mapped_type> const_iterator;
            typedef reverseIterator<iterator>  reverse_iterator;
            typedef reverseIterator<const_iterator> const_reverse_iterator; 
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;

            class value_compare
            {
            friend class Map;
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.key_value, y.key_value);
                }

};
        private:
            
            /*********************************/
            /*     Member types | private    */
            /*********************************/
                typedef Map<Key, T, Compare> _Self;
                _pair<Key, T> *_head;
                _pair<Key, T> *_tail;
                key_compare comp;
                size_type _n;            

        public:
            
            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
                Map(const key_compare& comp = key_compare()): comp(comp), _n(0) {
                    _head = new _pair<Key, T>(0, 0, NULL, NULL);
                    _tail = _head;
                }

                Map(iterator first, iterator last): _n(0) {
                    _head = new _pair<Key, T>(0, 0, NULL, NULL);
                    _tail = _head;
                    insert(begin(), first, last);
                }

                Map(const Map& x): _n(0) {
                    _head = new _pair<Key, T>(0, 0, NULL, NULL);
                    _tail = _head;
                    insert(begin(), x.begin(), x.end());
                }
              
            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            Map &operator=(const Map& x)
            {
                this->clear();
                insert(begin(), x.begin(), x.end());
                return *this;
            }
            
            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
             
            virtual ~Map() {
                    this->clear();
                    delete _tail;
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
                mapped_type& operator[] (const key_type& k) {
                iterator ite = this->end();
                    for (iterator it = this->begin(); it != ite; it++)
                    {
                        if (it.base()->key_value == k)
                            return it.base()->mapped_value;
                    }
                    insert(_pair<const key_type, mapped_type>(k, mapped_type()));
                    iterator it1 = lower_bound(k);
                return it1.base()->mapped_value;
                }

             /***************************************************************************/
            /*** Modifiers --------------------------------------------------------- ***/
                iterator insert (iterator position, const value_type& val) {
                iterator ite = this->end();
                for (iterator it = this->begin(); it != ite; it++)
                {
                    if (it.base()->key_value == val.key_value)
                        return iterator(it.base());
                }
                if (position == this->begin())
                {
                    _pair<Key, T>* pair = new _pair<Key, T>(val.key_value, val.mapped_value, nullptr, nullptr);
                    this->_head->insert_before(pair);
                    this->_head = pair;
                    _n++;
                    return iterator(this->begin());
                }
                else if (position == this->end())
                {
                    _pair<Key, T>* pair = new _pair<Key, T>(val.key_value, val.mapped_value, nullptr, nullptr);
                    this->_tail->insert_before(pair);
                    _n++;
                    return iterator(this->end());
                }
                else
                {
                    _pair<Key, T>* pair = new _pair<Key, T>(val.key_value, val.mapped_value, nullptr, nullptr);
                    position.base()->insert_before(pair);
                    _n++;
                    return iterator(pair);
                }
            }
            
                _pair<iterator,bool> insert (const value_type& val) {
                    iterator ite = this->end();
                    for (iterator it = this->begin(); it != ite; it++)
                    {
                        if (it.base()->key_value == val.key_value)
                            return (_pair<iterator, bool>(it.base(), false));
                    }
                    iterator it1 = insert(lower_bound(val.key_value), val);
                    return _pair<iterator, bool>(it1, true);
                }
                
                 void insert (iterator position, const_iterator first, const_iterator last) {
                    while (first != last)
                    {
                    value_type val = _pair<const key_type, mapped_type>(first.base()->key_value, first.base()->mapped_value);
                    this->insert(position, val);
                    first++;
                }
            }

                void insert (iterator position, iterator first, iterator last) {
                while (first != last)
                {
                    value_type val = _pair<const key_type, mapped_type>(first.base()->key_value, first.base()->mapped_value);
                    this->insert(position, val);
                    first++;
                }
            }
            
                void erase (iterator position)
                {
                if (position == this->begin()) {
                    if (_n == 1)
                    {
                        delete this->_head;
                        this->_head = this->_tail;
                        this->_tail->prev = nullptr;
                    }
                    else if (_n >= 1)
                    {
                        _pair<Key, T> *tmp = this->_head->next;
                        if (_head->prev)
                            _head->prev->next = _head->next;
                        if (_head->next)
                            _head->next->prev = _head->prev;
                        delete this->_head;
                        this->_head = tmp;
                    }
                    --_n;
                } 
                else if (position == this->end()) {
                    if (_n == 1)
                        erase(this->begin());
                    else if (_n >= 1)
                    {
                        _pair<Key, T> *tmp = this->_tail->prev;
                        if (_tail->prev->prev)
                            _tail->prev->prev->next = _tail->prev->next;
                        if (_tail->prev->next)
                            _tail->prev->next->prev = _tail->prev->prev;
                        delete tmp;
                        --_n;
                    }
                }
                else
                {
                    position.base()->next->prev = position.base()->prev;
                    position.base()->prev->next = position.base()->next;
                    delete position.base();
                    _n--;
                }
            }

            size_type erase (const key_type& k) {
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
            
            void erase (iterator first, iterator last) {
                while (first != last)
                    erase(first++);
            }
                    
                void swap (Map& x) {
                std::swap(_head, x._head);
                std::swap(_tail, x._tail);
                std::swap(_n, x._n);
            }
            
            void clear() {
                erase(begin(), end());
            }

             /***************************************************************************/
            /*** Observers --------------------------------------------------------- ***/

             key_compare key_comp() const {
                return comp;
            }

            value_compare value_comp() const {
                return value_compare(comp);
            }

            /***************************************************************************/
            /*** Operations -------------------------------------------------------- ***/
                iterator find (const key_type& k) {
                    iterator ite = this->end();
                    for (iterator it = this->begin(); it != ite; it++)
                    {
                        if (it.base()->key_value == k)
                            return iterator(it.base());
                    }
                    return iterator(this->end());
                }
                
                const_iterator find (const key_type& k) const {
                    iterator ite = this->end();
                    for (iterator it = this->begin(); it != ite; it++)
                    {
                        if (it.base()->key_value == k)
                            return const_iterator(it.base());
                    }
                    return const_iterator(this->end());
                }
                
                size_type count (const key_type& k) const {
                    const_iterator ite = this->end();
                    size_type sum = 0;
                    for (const_iterator it = this->begin(); it != ite; it++)
                    {
                        if (it.base()->key_value == k)
                            sum++;
                    }
                    return sum;
                }

                iterator lower_bound (const key_type& k) {
                    key_compare cmp = key_comp();
                    iterator ite = this->end();
                    iterator it = this->begin();
                    while(it != ite)
                    {
                        if (cmp(it.base()->key_value, k) == false)
                            return iterator(it.base());
                        it++;
                    }
                    return iterator(this->end());
                }
                
                const_iterator lower_bound (const key_type& k) const {
                    key_compare cmp = key_comp();
                    iterator ite = this->end();
                    iterator it = this->begin();
                    while(it != ite)
                    {
                        if (cmp(it.base()->key_value, k) == false)
                            return iterator(it.base());
                        it++;
                    }
                    return const_iterator(this->end());
                }

                iterator upper_bound (const key_type& k) {
                    iterator it = lower_bound(k);
                    if (it.base()->next)
                        it++;
                    return it;
                }

                const_iterator upper_bound (const key_type& k) const {
                    iterator it = lower_bound(k);
                    if (it.base()->next)
                        it++;
                    return it;
                }

                _pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
                    return _pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
                }
                
                _pair<iterator,iterator>             equal_range (const key_type& k) {
                    return _pair<iterator, iterator>(lower_bound(k), upper_bound(k));
                }
};

     void test_map(void);

}

#endif