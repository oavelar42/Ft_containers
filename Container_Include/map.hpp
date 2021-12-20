/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/20 22:33:37 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <functional>
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
    /*     Class Map     */
    /*********************/
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef std::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			class												value_compare;
			typedef Alloc										allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;

			typedef typename map::iterator<key_type, mapped_type>               iterator;
            typedef typename map::const_iterator<key_type, mapped_type>         const_iterator;
            typedef typename map::reverse_iterator<key_type, mapped_type>       reverse_iterator;
            typedef typename map::const_reverse_iterator<key_type, mapped_type> const_reverse_iterator;

            class value_compare
            {
                public:
                    value_compare(key_compare c) : _comp(c) {}

                    bool operator()(const value_type& x, const value_type& y) const
                    {
                        return _comp(x.first, y.first);
                    }
                    key_compare _comp;
            };
  
                /****************************/
                /*     Member functions     */
                /****************************/
            
            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
           explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _rbTree() {}

			// range
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc)
			{
				this->insert(first, last);
			}

			// copy
			map (const map& x)
			{
				this->insert(x.begin(), x.end());
			}
              
            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
          	map& operator= (const map& x)
			{
				if (this != &x)
				{
					this->clear();
					this->_alloc = x._alloc;
					this->_comp = x._comp;
					this->insert(x.begin(), x.end());
				}
				return (*this);
			}
            
            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
             
           ~Map()
            {
                clear();
                //destroy_deallocate_node(_head);
                //destroy_deallocate_node(_tail);
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
                ft::pair<iterator, bool> insert(const value_type& val)
                    {
                        bool succes = _rbTree.insert(val);
                        iterator it = find(val.first);
                        return ft::pair<iterator, bool>(it, succes);
                    }

                iterator insert (iterator position, const value_type& val)
                    {
                        (void)position;
                        return insert(val).first;
                    }

                template <class InputIterator>
                void insert (InputIterator first, InputIterator last)
                    {
                            while (first != last)
                                insert(*(first++));
                    }

                void erase (iterator position)
                    {
                        this->erase((*position).first);
                    }

                size_type erase(const key_type& k)
                    {
                        if (_rbTree.deleteNode(k))
                            return 1;
                        return 0;
                    }

                void erase (iterator first, iterator last)
                    {
                        while (first != last)
                            this->erase((*(first++)).first);
                    }

                void swap (map& x)
                    {
                        _rbTree.swap(x._rbTree);
                    }

                void clear()
                    {
                        erase(begin(), end());
                    }

             /***************************************************************************/
            /*** Observers --------------------------------------------------------- ***/

           	key_compare		key_comp() const { 
                   return this->_comp; 
                }

			value_compare	value_comp() const { 
                return value_compare(this->_comp); 
                }

            /***************************************************************************/
            /*** Operations -------------------------------------------------------- ***/
   
			iterator find(const key_type& k)
			{
				node_ptr node = _rbTree.search(k);
				if (node == _rbTree.getNil())
					return end();
				return (iterator(_rbTree.getRoot(), _rbTree.getNil(), node));
			}

			const_iterator find (const key_type& k) const
			{
				node_ptr node = _rbTree.search(k);
				if (node == _rbTree.getNil())
					return end();
				return (const_iterator(_rbTree.getRoot(), _rbTree.getNil(), node));
			}


			size_type count (const key_type& k) const
			{
				const_iterator beg = this->begin();
				const_iterator end = this->end();

				while (beg != end)
					if ((*(beg++)).first == k)
						return (1);
				return (0);
			}

			iterator lower_bound (const key_type& k)
			{
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end)
				{
					if (_comp((*beg).first, k) == false)
						break;
					beg++;
				}
				return (beg);
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator beg = this->begin();
				const_iterator end = this->end();

				while (beg != end)
				{
					if (_comp((*beg).first, k) == false)
						break;
					beg++;
				}
				return (beg);
			}

			iterator upper_bound (const key_type& k)
			{
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end)
				{
					if (_comp(k, (*beg).first))
						break;
					beg++;
				}
				return (beg);
			}
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator beg = this->begin();
				const_iterator end = this->end();

				while (beg != end)
				{
					if (_comp(k, (*beg).first))
						break;
					beg++;
				}
				return (beg);
			}

			ft::pair<iterator, iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			allocator_type get_allocator() const { return _alloc; }

			protected:
				key_compare			_comp;
				allocator_type		_alloc;
				tree_type			_rbTree;

};

}

#endif