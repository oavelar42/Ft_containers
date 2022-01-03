/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:13:09 by oavelar           #+#    #+#             */
/*   Updated: 2022/01/03 18:53:45 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MAP_CLASS_HPP
# define MAP_CLASS_HPP
# include <memory>
# include <utility>
# include <iostream>
# include <cstddef>
# include "map.hpp"

namespace ft 
{
    template < class Iterator >
    class reverse_iterator
    {
        protected:
            Iterator _base;

        public:
            typedef Iterator        iterator_type;
            typedef typename Iterator::difference_type      difference_type;
            typedef typename Iterator::pointer              pointer;
            typedef typename Iterator::reference            reference;

            //Member Functions
                //Constructors
                reverse_iterator() : _base() {} //default
                explicit reverse_iterator(iterator_type it) : _base(it) {}//initialization
                template < class Iter >
                    reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {} //copy
                template <class Iter> 
                    reverse_iterator &operator=(const reverse_iterator<Iter> &x) { _base = x.base(); return *this; };

                iterator_type       base() const { return _base; };
                reference           operator*() const { Iterator tmp = _base; return *--tmp; };
                pointer             operator->() const { return &(operator*()); };
                reverse_iterator    operator+(difference_type n) const { return reverse_iterator(_base - n); };
                reverse_iterator    operator-(difference_type n) const { return reverse_iterator(_base + n); };
                template <class T>
                    difference_type		operator-(reverse_iterator<T> const& n) { return n.base().operator-(_base); };
                reverse_iterator&   operator++() {--_base; return *this; };
                reverse_iterator    operator++(int) { reverse_iterator tmp(*this); --_base; return tmp; };
                reverse_iterator&   operator--(){ ++_base; return *this; };
                reverse_iterator    operator--(int) { reverse_iterator tmp(*this); ++_base; return tmp; };
                reverse_iterator&   operator+=(difference_type n) { _base -= n; return *this; };
                reverse_iterator&   operator-=(difference_type n) { _base += n; return *this; };
                reference           operator[](difference_type n) const { return *(*this + n); };
    };
    
    template <class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() >= rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() <= rhs.base();
    } 

    template <class Iterator>
        reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
        {
            return reverse_iterator<Iterator>(rev_it.base() - n);
        }

    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
        {
            return lhs.base() - rhs.base();
        }

        template < class T >
    class RandAccess
    {
        protected:
            T          *_val;

        public:
            typedef T&          reference;
            typedef T*          pointer;
            typedef ptrdiff_t   difference_type;

            RandAccess() : _val(NULL) {}
            RandAccess(T *src) : _val(src) {}
            RandAccess(RandAccess const& src) : _val(NULL) { *this = src; }
            virtual ~RandAccess() {}
            RandAccess& operator=(RandAccess const& rhs) {
                if (this != &rhs)
                    _val = rhs._val;
                return (*this);
            };

            bool            operator==(RandAccess const& rhs) const { return _val == rhs._val; }
            bool            operator!=(RandAccess const& rhs) const { return _val != rhs._val; }
            bool            operator>(RandAccess const& rhs) const { return _val > rhs._val; }
            bool            operator>=(RandAccess const& rhs) const { return _val >= rhs._val; }
            bool            operator<(RandAccess const& rhs) const { return _val < rhs._val; };
            bool            operator<=(RandAccess const& rhs) const { return _val <= rhs._val; };

            RandAccess<T>&  operator++() { _val++; return *this; }
            RandAccess<T>   operator++(int) {  RandAccess<T> tmp(*this); _val++; return tmp; }
            RandAccess<T>&  operator--() { _val--; return *this; }
            RandAccess<T>   operator--(int) { RandAccess<T> tmp(*this); _val--; return tmp; }
            RandAccess<T>   operator+(difference_type n) const { return RandAccess(_val + n); }
            friend RandAccess<T>    operator+(difference_type n, RandAccess const& rhs) { return rhs.operator+(n); }

            RandAccess<T>   operator-(difference_type n) const { return RandAccess(_val - n); }
            difference_type operator-(RandAccess const& n) const { return _val - n._val; }
            RandAccess<T>&  operator+=(difference_type n) { _val += n; return *this; }
            RandAccess<T>&  operator-=(difference_type n) { _val -= n; return *this; }

            pointer         operator->() const { return _val; }
            reference       operator*() const { return *_val; }
            reference       operator[](difference_type n) const { return _val[n]; }
    };

       template < class T, typename Node >
    class MapIter
    {
        protected:
            Node    *_node;
            MapIter(Node *src) { _node = src; } 

        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef value_type const&   const_reference;
            typedef value_type*         pointer;
            typedef ptrdiff_t           difference_type;
            typedef Node*               node_ptr;

            MapIter() : _node(NULL) {}
            MapIter(MapIter const& src) { *this = src; }
            virtual ~MapIter() {}
            MapIter&  operator=(MapIter const& rhs)
            {
                if (this != &rhs)
                    _node = rhs._node;
                return *this; 
            }
            operator MapIter<const T, Node>(void) const { return MapIter<const T, Node>(this->_node); };

            bool operator==(MapIter const& rhs) { return _node == rhs._node; }
            bool operator!=(MapIter const& rhs) { return _node != rhs._node; }
            
            MapIter& operator++() 
            {
                if (_node->right)
                {
                    _node = min_node(_node->right);
                }
                else if (_node->parent)
                {
                    Node  *tmp = _node;
                    _node = _node->parent;
                    while (_node && tmp == _node->right)
                    {
                        tmp = _node;
                        _node = _node->parent;        
                    }
                }
                return *this;
            }

            MapIter operator++(int)
            {
                MapIter<T, Node> tmp(*this);
                operator++();
                return tmp;
            }
            
            MapIter& operator--()
            {
                if (_node->left)
                    _node = max_node(_node->left);
                else if (_node->parent)
                {
                    Node  *tmp = _node;
                    _node = _node->parent;
                    while (_node && tmp == _node->left)
                    {
                        tmp = _node;
                        _node = _node->parent;        
                    }
                }
                return *this;
            }

            MapIter operator--(int)
            {
                MapIter<T, Node> tmp(*this);
                operator--();
                return tmp;
            }

            reference operator*() const { return _node->data; }
            pointer operator->() const { return &_node->data; }

            template <class, class, class, class>
            friend class map;
            template <class, class>
            friend class MapIter;
    };

    ////////////////////////
    //        LESS       //
    ///////////////////////
    template <class T> 
    struct less : std::binary_function <T,T,bool> 
    {
        bool operator() (const T& x, const T& y) const {return x < y;}
    };

    ////////////////////////
    //        PAIR       //
    ///////////////////////
   template <class T1, class T2> 
   struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(void) : first(), second() { return; };
		template<class U, class V>
		    pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) { return; };
		pair(const first_type& a, const second_type& b) : first(a), second(b) { return; };
		pair& operator=(const pair& pr) { first = pr.first; second = pr.second; return *this; };
	};

    template <class T1, class T2>
    bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    { 
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    };

    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    };

    template <class T1, class T2>
    bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first && lhs.second < rhs.second);
    };

    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first <= rhs.first && lhs.second <= rhs.second);
    };

    template <class T1, class T2>
    bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    {
        return (lhs.first > rhs.first && lhs.second > rhs.second);
    };

    template <class T1, class T2>
    bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    {
        return (lhs.first >= rhs.first && lhs.second >= rhs.second); 
    };

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y) 
    {
        return (pair<T1,T2>(x,y) );
    };

    template< class T1, class T2 >
    std::ostream & operator<<( std::ostream & flux, ft::pair<T1, T2> const & rhs)
    {
        flux << rhs.second << std::endl;
        return flux;
    }

    ////////////////////////
    //        MAP        //
    ///////////////////////

    template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public:
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef pair<const key_type, mapped_type>			                value_type;
            typedef Compare                                                     key_compare;
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef ptrdiff_t                                                   difference_type;
            typedef size_t                                                      size_type;
            typedef ft::Node<value_type>                                        node_type;
            typedef node_type*                                                  node_ptr;
            typedef typename allocator_type::template rebind<node_type>::other  _new;

            //Iterators
            typedef ft::MapIter<value_type, node_type>          iterator;
            typedef ft::MapIter<const value_type, node_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;


            class value_compare
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {};

                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const 
                    {
                        return comp(x.first, y.first);
                    }
            };

            //Member functions
                //Constructors
                explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()); //empty
                template <class InputIterator>
                        map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()); //range
                map (const map& x); //copy

                // Destructor
                ~map();

                //Operator=
                map& operator=(const map& x);

                //Iterators
                iterator begin();
                const_iterator begin() const;
                iterator end();
                const_iterator end() const;
                reverse_iterator rbegin();
                const_reverse_iterator rbegin() const;
                reverse_iterator rend();
                const_reverse_iterator rend() const;

                //Capacity
                bool empty() const;
                size_type size() const;
                size_type max_size() const;

                //Element Access
                mapped_type& operator[] (const key_type& k);

                //Modifiers
                pair<iterator,bool> insert(const value_type& val);
                iterator insert (iterator position, const value_type& val);
                template <class InputIterator>
                    void insert (InputIterator first, InputIterator last);

                void erase(iterator position);
                size_type erase (const key_type& k);
                void erase (iterator first, iterator last);

                void swap (map& x);
                void clear();

                //Observers
                key_compare key_comp() const;
                value_compare value_comp() const;

                //Operation
                iterator find (const key_type& k);
                const_iterator find (const key_type& k) const;
                size_type count (const key_type& k) const;
                iterator lower_bound (const key_type& k);
                const_iterator lower_bound (const key_type& k) const;
                iterator upper_bound (const key_type& k);
                const_iterator upper_bound (const key_type& k ) const;
                pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
                pair<iterator,iterator>             equal_range (const key_type& k);

                //Allocator
                allocator_type get_allocator() const;

        private:
                //Binary Search Tree specific functions
                node_ptr newNode(value_type &data);
                void createGhost(bool add);
                node_ptr insertNode(node_ptr node, value_type data);
                void _setGhost(bool add);
                node_ptr delete_node(node_ptr node, value_type data);
                void     PrintInOrder(node_ptr node);

        private:
            allocator_type                              _alloc;
            size_type                                   _size;
            size_type                                   _max_size;
            key_compare                                 _comp;
            std::allocator<node_type>                   _node_alloc;
            node_ptr                                    _root;
            node_ptr                                    _sentinel;
            node_ptr                                    _GreatestData;
        
         public:
            node_ptr    get_root(){ return this->_root;};
    };

    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs == rhs)
            return false;
        return true;
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    void	swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
    {
        x.swap(y);
    }
}
#endif