/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:39:48 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/23 22:24:36 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "binary.hpp"
# include "iterators.hpp"
# include "reverse_iter.hpp"

namespace ft
{
	/*********************/
	/*                   */
	/*     Class Map     */
	/*                   */
	/*********************/
	template < class Key, class T, class Compare = ft::less<Key>,
		   class Alloc = std::allocator<ft::pair<const Key,T> >  >
	class map
	{
		public:

			/************************/
			/*     Member types     */
			/************************/
			
			typedef Key											key_type;
			typedef T				    						mapped_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			
		private:
			typedef Binary< const value_type, Compare, Alloc>		const_tree;
			typedef Binary< value_type, Compare, Alloc>			tree;
			typedef typename tree::Node							node;

		public:
			typedef	typename tree::reference					reference;
			typedef	typename tree::const_reference				const_reference;
			typedef	typename tree::pointer						pointer;
			typedef	typename tree::const_pointer				const_pointer;
			typedef	typename tree::size_type					size_type;
			
			typedef	ft::map_iterator<bidirectional_iterator_tag,
			const_tree, tree>												const_iterator;
			typedef	ft::map_iterator<bidirectional_iterator_tag, tree>		iterator;
			typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	ft::reverse_iterator<iterator>							reverse_iterator;	
			typedef typename iterator_traits<iterator>::difference_type		difference_type;

			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

			
			  /****************************/
			 /*     Member functions     */
			/****************************/

			/***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
			explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {}

			/*  Range  */
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc)
			{
				this->insert(first, last);
			}
			
			/*  Copy  */
			map(const map& x) { *this = x; }

			 /***************************************************************************/
			/*** destructor -------------------------------------------------------- ***/
			~map() {}

			 /***************************************************************************/
			/*** operator= --------------------------------------------------------- ***/
			map& operator=(const map& x)
			{		
				if(this == &x)
					return *this;
				this->_tree = x._tree;
				return *this;
			}

			  ////////////////////////
			 //      Iterator      //
			////////////////////////
			
 			iterator	begin() { return iterator(this->_tree.begin_node(), this->_tree.end_node()); }

 			const_iterator	begin() const { return const_iterator(this->_tree.begin_node(), this->_tree.end_node()); }
				
 			iterator	end() { return iterator(this->_tree.end_node(), this->_tree.end_node()); }
 			
			const_iterator	end() const { return const_iterator(this->_tree.end_node(), this->_tree.end_node()); }

			reverse_iterator		rbegin() { return reverse_iterator(this->end()); }
			
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->end()); }

			reverse_iterator		rend() { return reverse_iterator(iterator(this->begin())); }
			
			const_reverse_iterator	rend() const { return const_reverse_iterator(this->begin()); } 
			 

			 ////////////////////////
			//      Capacity      //
		   ////////////////////////

			size_type				size() const { return this->_tree.size(); }

			size_type				max_size() const { return this->_tree.max_size(); }
			
			bool					empty() const { return this->size() == 0; }

			  ////////////////////////
			 //    Element acess   //
			////////////////////////
			
			mapped_type& 			operator[](const key_type& k) { return this->_tree[k]; }

			  ////////////////////////
			 //      Modifiers     //
			////////////////////////

			pair<iterator,bool>		insert(const value_type& val) {
				size_type n = this->size();
				this->_tree.insertValue(val);
				pair<iterator,bool> ret;
				ret.second = (n != this->size());
				ret.first = this->find(val.first);
				return ret;
			}
			
			iterator				insert(iterator position, const value_type& val) 
			{
				iterator prec(position);
				if (value_comp()(*prec, val) && value_comp()(val, *++position))
				{
					this->_tree.insertValue(val);
					return this->find(val.first);
				}
				return this->insert(val).first;
			}
			
			template <class InputIterator>
  			void					insert(InputIterator first, InputIterator last) {
				for (InputIterator it = first; it != last; it++)
					this->_tree.insertValue(*it);
				
			}

			size_type				erase(const key_type& k) {
				size_type n = this->size();
				this->_tree.deleteKey(k);
				return (n != this->size());
			}
			
			void					erase(iterator position) { this->erase((*position).first); }

			void					erase(iterator first, iterator last) {
				iterator tmp;
				while (first != last)
				{
					tmp = first;
					++first;
					this->erase(tmp);
				}
			}

			void	swap(map& x) { this->_tree.swap(x._tree); }

			void	clear() { this->_tree.clear(); }
			
			  ////////////////////////
			 //     Observers      //
			////////////////////////
			
			key_compare				key_comp() const { return (key_compare()); }
			
			value_compare			value_comp() const { return (value_compare(key_compare())); }

			  ////////////////////////
			 //     Operation      //
			////////////////////////
    			
			iterator				find(const key_type& k) {
				node* node = this->_tree.find(k);
				if (node)
					return iterator(node, this->_tree.end_node());
				return this->end();
			}

			const_iterator			find(const key_type& k) const {
				node* node = this->_tree.find(k);
				if (node)
					return const_iterator(node, this->_tree.end_node());
				return this->end();
			}

			size_type				count(const key_type& k) const {
				return (this->_tree.find(k)) ? 1 : 0;
			}

			iterator				lower_bound(const key_type& k) {
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp()(it->first, k))
						return it;
				return this->end();
			}

			const_iterator			lower_bound(const key_type& k) const {
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp()(it->first, k))
						return it;
				return this->end();
			}

			iterator 				upper_bound(const key_type& k) {
				for (iterator it = this->begin(); it != this->end(); it++)
					if (this->_tree.key_comp()(k, it->first))
						return it;
				return this->end();
			}

			const_iterator			upper_bound(const key_type& k) const {
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (this->_tree.key_comp()(k, it->first))
						return it;
				return this->end();
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp()(k, it->first) && !this->_tree.key_comp()(it->first, k))
						return pair<const_iterator, const_iterator>(it++, it);
				return pair<const_iterator, const_iterator>(this->lower_bound(k), this->lower_bound(k));
			}

			pair<iterator,iterator>				equal_range(const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp()(k, it->first) && !this->_tree.key_comp()(it->first, k))
						return pair<iterator, iterator>(it++, it);
				return pair<iterator, iterator>(this->lower_bound(k), this->lower_bound(k));
			}

		private:
			tree					_tree;
	};

	  ////////////////////////////////////////
	 //     Non-member func overloads      //
	////////////////////////////////////////
	template< class Key, class T, class Compare, class Alloc >
	bool operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return 0;
		typename ft::map<Key,T,Compare,Alloc>::const_iterator rit = rhs.begin();
		for (typename ft::map<Key,T,Compare,Alloc>::const_iterator lit = lhs.begin(); lit != lhs.end(); lit++, rit++)
			if (*lit != *rit)
				return 0;
		return 1;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 
	{
		return !(rhs < lhs);
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 
	{
		return (rhs < lhs);
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 
	{
		return !(lhs < rhs);
	}
	
	template< class Key, class T, class Compare, class Alloc >
	void swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif