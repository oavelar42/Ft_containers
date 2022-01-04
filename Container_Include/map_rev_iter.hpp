/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rev_iter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:34:57 by rzafari           #+#    #+#             */
/*   Updated: 2022/01/04 09:51:10 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REV_ITER_HPP
# define MAP_REV_ITER_HPP

# include "map_class.hpp"

namespace ft
{
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

        //rand map iter


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


      //utils

    template <bool, class _Tp = void>
    struct enable_if {};
    
    template <class _Tp>
    struct enable_if<true, _Tp>  {typedef _Tp type;};

    template <class InputIterator>
    size_t InputIterator_len(InputIterator first, InputIterator last)
    {
        size_t i = 0;
        for(; first != last; first++)
            i++;
        return i;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {   
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1)
                return false;
            else if (*first1<*first2)
                return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

     ////////////////////////
    //        NODE       //
    ///////////////////////
    template<class T>
    struct Node
    {
        private:
            bool empty;
        public:
            T       data;
            Node    *right;
            Node    *left;
            Node    *parent;
    };

    template< class T >
    Node<T>* min_node(Node<T>* node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    template< class T >
    Node<T>* max_node(Node<T>* node)
    {
        while (node && node->right != NULL)
            node = node->right;
        return node;
    }

    template <typename T>
    void	printPairs(const T &iterator)
    {
        std::cout << "key: " << iterator->first << " | value: " << iterator->second << std::endl;
    }

}

#endif