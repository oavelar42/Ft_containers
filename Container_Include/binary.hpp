/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:54:12 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/25 17:52:25 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_HPP
# define BINARY_HPP

# include <memory>
# include <math.h> 
# include "utils.hpp"

namespace ft
{
	/*********************/
	/*                   */
	/*   Class Binary    */
	/*                   */
	/*********************/
    template <	class T,
				class Compare = ft::less<typename T::first_type>,
				class Alloc = std::allocator<T> >
    class Binary
    {		
		public:
			
			/************************/
			/*     Member types     */
			/************************/
			
			typedef typename T::first_type 		key_type;
			typedef typename T::second_type 	mapped_type;
			typedef T							value_type;
			typedef	Compare						key_compare;
			typedef	Alloc						allocator_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef	value_type*					pointer;
			typedef	const value_type*			const_pointer;
			typedef	size_t						size_type;

			struct Node
			{
				value_type				value;
				Node*					left;
				Node*					right;
				Node*					parent;

				Node*	getParent() {
					Node* node = this;
					while (node->parent)
						node = node->parent;
					return node;
				}
				
				Node*	min() {
					Node* node = this;
					while (node->left)
						node = node->left;
					return node;
				}
				
				Node*	max() {
					Node* node = this;
					while (node->right)
						node = node->right;
					return node;
				}
			};
			
			/*  Classe de função para comparar elementos  */
			class value_compare
			{
					friend class Binary;
				protected:
					Compare comp;
					value_compare (key_compare c) : comp(c) {}
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first); }
			};
			
			/****************************/
			/*     Member functions     */
			/****************************/

			/***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
			Binary(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :
				_comp(comp), _allocValue(alloc) {
					this->_root = 0;
					this->_end_node = this->_allocNode.allocate(1);
					this->set_end_node();
			}
			
			/* Copy */
			Binary(const Binary& x) { *this = x; }
			
			Binary(const Node& node, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :
				_comp(comp), _allocValue(alloc) {
					this->_root = &node;
					this->_end_node = this->_allocNode.allocate(1);
					this->set_end_node();
			}
			

			/* Destructor all */
			~Binary() {
				this->clear();
				this->_allocNode.deallocate(this->_end_node, 1);
			}

			 /***************************************************************************/
			/*** operator= --------------------------------------------------------- ***/
			Binary&			operator=(const Binary& x)
			{		
				if(this == &x)
					return *this;
				destroyNode(this->_root);
				this->_root = 0;
				this->_allocNode.deallocate(this->_end_node, 1);
				this->_allocValue = x._allocValue;
				this->_allocNode = x._allocNode;
				this->_end_node = this->_allocNode.allocate(1);
				this->_comp = x._comp;
				this->_root = copyNode(this->_root, x._root);
				this->set_end_node();
				return *this;
			}

				////////////////////////
			   //      Capacity      //
			  ////////////////////////
			
			size_type		size() const {
				return sizeNode(this->_root);
			}
			
			int				height() const {
				return heightNode(this->_root);
			}
			
			size_type		max_size() const { return this->_allocNode.max_size(); }
			
				////////////////////////
			   //    Element acess   //
			  ////////////////////////
			
			
			mapped_type& 	operator[](const key_type& k) {
				Node* node = this->find(k);
				if (node)
					return node->value.second;
				this->_root = insertNode(this->_root,
				ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
				this->set_end_node();
				return (*this)[k];
			}
			
				////////////////////////
			   //      Modifiers     //
			  ////////////////////////
			
			/* nó vazio que representa a extremidade da árvore (depois do maior elemento) */
			void			set_end_node() {
				if (this->_root)
					this->_end_node->parent = this->_root->max();
				else
					this->_end_node->parent = 0;
				this->_end_node->right = 0;
				this->_end_node->left = 0;
			}

			void			swap(Binary& x) {
				Node* tmp = this->_root;
				this->_root = x._root;
				x._root = tmp;
			}
			
			void			insertValue(const value_type& val) {
				this->_root = insertNode(this->_root, val);
				this->set_end_node();
			}

			void			deleteKey(const key_type key) {
				this->_root = deleteNode(this->_root, key);
				this->set_end_node();
			}
			
			void			clear() {
				if (this->_root)
					destroyNode(this->_root->getParent());
				this->_root = 0;
				this->set_end_node();
			}
			
			  ////////////////////////
			 //     Observers      //
			////////////////////////
			
			Node*			begin_node() const { return this->_root ? this->_root->min() : this->_end_node; }
			Node*			end_node() const { return this->_end_node; }
			Node*			root() const { return this->_root; }
			key_compare		key_comp() const { return this->_comp; }
			value_compare	value_comp() const { return value_compare(this->_comp); }
			
			   ////////////////////////
			  //     Operation      //
			 ////////////////////////
			
			Node*			find(const key_type& k) const
			{
				Node *tmp = this->_root;
				while (tmp)
				{
					if (this->_comp(k, tmp->value.first))
						tmp = tmp->left;
					else if (this->_comp(tmp->value.first, k))
						tmp = tmp->right;
					else
						return tmp;
				}
				return 0;
			}
			
		private:
			 /***************************************************************************/
			/*** rotation check ---------------------------------------------------- ***/

			/* X rodar para o top do lado esquerdo  */
			Node*	leftRotate(Node* x)
			{
				Node *top = x->right;
				Node *tmp = top->left;
				
				top->parent = x->parent;
				x->parent = top;
				if (tmp)
					tmp->parent = x;
				x->right = tmp;
				top->left = x;

				return top;
			}

			/* X rodar para o top do lado direito  */
			Node*	rightRotate(Node* y)
			{
				Node* top = y->left;
				Node* tmp = top->right;
				
				top->parent = y->parent;   
				y->parent = top;
				if (tmp)
					tmp->parent = y;
				y->left = tmp;
				top->right = y;  

				return top;
			}
			
			/* vericaçao dos lados  */
			int	lastcheck(Node* node) const {
				if (!node)
					return 0;
				return heightNode(node->right) - heightNode(node->left);
			}
			
			Node*			balance_after_insert(Node* node, const key_type key)
			{
				int bf = lastcheck(node);
				
				/* segundo caso da esquerda */
				if (bf < -1 && this->_comp(key, node->left->value.first))
					return rightRotate(node);

				/* segundo caso da direita  */
				if (bf > 1 && this->_comp(node->right->value.first, key))
					return leftRotate(node);
				
				/* primeiro lado esquerdo , e depois lado direito */
				if (bf < -1 && this->_comp(node->left->value.first, key))
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}

				/* primeiro lado direito , e depois lado esquerdo */
				if (bf > 1 && this->_comp(key, node->right->value.first))
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
				
				return node;
			}
			
			Node*			balance_after_delete(Node* node)
			{
				if (!node)
					return node;
					
				int bf = lastcheck(node);
				/* segundo caso a esquerda*/
				if (bf < -1 && lastcheck(node->left) <= 0)
					return rightRotate(node);
				/* segundo caso a direita */
				if (bf > 1 && lastcheck(node->right) >= 0)
					return leftRotate(node);
				/* primeiro lado esquerdo , e depois lado direito  */
				if (bf < -1 && lastcheck(node->left) > 0)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
				/* primeiro lado direito , e depois lado esquerdo  */
				if (bf > 1 && lastcheck(node->right) < 0)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
				return node;
			}

		public:
			 /***************************************************************************/
			/*** node utils -------------------------------------------------------- ***/
			
			size_type		sizeNode(Node* node) const {
				size_type s = 0;
				if (node)
				{
					s += sizeNode(node->right);
					s += sizeNode(node->left);
					++s;
				}
				return s;
			}
			
			int				heightNode(Node* node, int h = 0) const
			{
				if (node)
				{
					h++;
					int tmp = h;
					h = heightNode(node->right, h);
					tmp = heightNode(node->left, tmp); 
					h = h > tmp ? h : tmp;
				}
				
				return h;
			}
			
			Node*			copyNode(Node* dest, Node* src) {
				if (src)
				{
					dest = copyNode(dest, src->left);
					dest = copyNode(dest, src->right);
					dest = insertNode(dest, src->value);
				}
				return dest;
			}
			
			Node*			newNode(value_type val, Node* parent)
			{
				Node* node;
				
				node = this->_allocNode.allocate(1);
				this->_allocValue.construct(&node->value, val);
				
				node->parent = parent;
				node->left = 0;
				node->right = 0;

				return node;
			}
			
			Node*			insertNode(Node* node, const value_type& val, Node* parent = 0)
			{
				if (!node)
					return newNode(val, parent);

				if (this->_comp(val.first, node->value.first))
					node->left = insertNode(node->left, val, node);
				else if (this->_comp(node->value.first, val.first))
					node->right = insertNode(node->right, val, node);
				else
					return node;

				node = this->balance_after_insert(node, val.first);
				
				return node;
			}


			Node*			deleteNode(Node* node, const key_type key)
			{
				if (!node)
					return node;
				if (this->_comp(key, node->value.first))
					node->left = deleteNode(node->left, key);
				else if (this->_comp(node->value.first, key))
					node->right = deleteNode(node->right, key);
				else
				{
					if (!node->left || !node->right)
					{
						Node* tmp = node;
						node = node->left ? node->left : node->right;
						if (node)
							node->parent = tmp->parent;
						this->_allocValue.destroy(&tmp->value);
						this->_allocNode.deallocate(tmp, 1);
						
					}
					else
					{
						// encontrar o maior
						Node *tmp = node->right->min();   	

						if (tmp != node->right)
						{
							tmp->right = node->right;
							node->right->parent = tmp;
						}
						if (tmp != node->left)
						{
							tmp->left = node->left;
							node->left->parent = tmp;
						}
						tmp->parent->left = 0;
						tmp->parent = node->parent;
						this->_allocValue.destroy(&node->value);
						this->_allocNode.deallocate(node, 1);
						node = tmp;
					}
				}
				node = balance_after_delete(node);
				return node;
			}
			
			void	destroyNode(Node *node) {
				if (node)
				{
					destroyNode(node->left);
					destroyNode(node->right);
					this->_allocValue.destroy(&node->value);
					this->_allocNode.deallocate(node, 1);
				}
			}

		private:
			key_compare				_comp;
			allocator_type  		_allocValue;
			std::allocator<Node>	_allocNode;
			Node*					_root;
			Node*					_end_node;
    };
}

#endif
