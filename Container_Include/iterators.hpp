/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:42:14 by oavelar           #+#    #+#             */
/*   Updated: 2022/02/25 18:10:03 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <cstddef>

namespace ft
{
	/*********************/
	/*    Vector         */
	/*       iterator    */
	/*********************/

	template <	class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class vector_iterator
	{
		public: 
			  /************************/
			 /*     Member types     */
			/************************/
			typedef T         						value_type;
			typedef Distance						difference_type;
			typedef Pointer   						pointer;
			typedef Reference 						reference;
			typedef Category						iterator_category;

			  /****************************/
			 /*     Member functions     */
			/****************************/

			 /***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
			vector_iterator() {}

			/*  Copy  */
			vector_iterator(const vector_iterator<Category, T, Distance, T*, T&> &toCopy) : _ptr(toCopy.base()) {}
			
			/*  Pointer constructor */
			vector_iterator(T* ptr) : _ptr(ptr) {}

			/*  Destructor  */
			virtual ~vector_iterator() {}

			T*			base() const { return this->_ptr ; } 
			/* operators : assignment */
			vector_iterator&	operator=(pointer ptr) { this->_ptr = ptr; return *this; }
			vector_iterator&	operator=(const vector_iterator &toCopy) { this->_ptr = toCopy._ptr; return *this; }
			vector_iterator&	operator+=(difference_type n) { this->_ptr += n; return *this; }
			vector_iterator&	operator-=(difference_type n) { this->_ptr -= n; return *this; }
			vector_iterator&	operator-=(const vector_iterator &it) { this->_ptr -= it._ptr; return *this; }

			/* operators : member access */
			reference   		operator*() const { return *this->_ptr; }
			pointer     		operator->() const { return &(operator*()); }
			reference			operator[](const difference_type &i) { return this->_ptr[i]; }

			/* operators : incr / decr */
			vector_iterator&   operator++() { this->_ptr++; return *this; }
			vector_iterator    operator++(int) { vector_iterator tmp = *this; ++*this; return tmp; }
			vector_iterator&   operator--() { this->_ptr--; return *this; }
			vector_iterator    operator--(int) { vector_iterator tmp = *this; --*this; return tmp; }

			/* operators : arithmetic */
			friend vector_iterator	operator+(const vector_iterator& it, difference_type n) { return vector_iterator(it._ptr + n); }
			friend vector_iterator	operator+(difference_type n, const vector_iterator& it) { return vector_iterator(it._ptr + n); }
			friend vector_iterator	operator-(const vector_iterator& it, difference_type n) { return vector_iterator(it._ptr - n); }
			friend vector_iterator	operator-(difference_type n, const vector_iterator& it) { return vector_iterator(it._ptr - n); }
			friend difference_type	operator-(const vector_iterator& a, const vector_iterator& b) { return (a._ptr - b._ptr); }

			/*  Operadores de comparação   */
			friend bool 	operator== (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr == rhs._ptr; }
			friend bool 	operator!= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr != rhs._ptr; }
			friend bool 	operator< (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr < rhs._ptr; }
			friend bool 	operator<= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr <= rhs._ptr; }
			friend bool 	operator> (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr > rhs._ptr; }
			friend bool 	operator>= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr >= rhs._ptr; }

		private:
			T*	_ptr;
	};

	/*********************/
	/*    Map            */
	/*       iterator    */
	/*********************/
	
	template <	class Category, class T, class not_const_T = T>
	class map_iterator
	{
		public:
		
			/************************/
			/*     Member types     */
			/************************/

			typedef typename T::value_type				value_type;
			typedef typename not_const_T::Node			Node;
			typedef typename T::key_type				key_type;
			typedef typename T::mapped_type				mapped_type;
			typedef	typename T::key_compare				key_compare;
			typedef typename T::pointer   				pointer;
			typedef typename T::reference 				reference;
			typedef ptrdiff_t							difference_type;
			typedef Category							iterator_category;

			  /****************************/
			 /*     Member functions     */
			/****************************/

			 /***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
			map_iterator() {}

			/* Copy */ 
			map_iterator(const map_iterator<Category, not_const_T> &toCopy) : _ptr(toCopy.base()), _end(toCopy.end()) {}
			
			/*  Pointer constructor */
			map_iterator(Node* node, Node* end) {
				this->_ptr = node;
				this->_end = end;
			}

			/*  Destructor  */
			virtual ~map_iterator() {}

			Node*			base() const { return this->_ptr; }
			Node*			end() const { return this->_end; }
			
			 /***************************************************************************/
			/*** operator= --------------------------------------------------------- ***/
			map_iterator&	operator=(const map_iterator<Category, not_const_T> &toCopy) {
				this->_ptr = toCopy._ptr;
				this->_end = toCopy._end;
				return *this;
			}

			/* operators : member access */
			reference   	operator*() const { return this->_ptr->value; }
			pointer     	operator->() const { return &(operator*()); }

			/* operators : incr / decr */
			map_iterator&   operator++()
			{
				if (this->_ptr->right)
				{
					// encontrar o menor
					this->_ptr = this->_ptr->right->min();   
					return *this;
				}
				else if (this->_ptr->parent)
				{
					 //encontrar o primeiro nó anterior maior
					key_type key = this->_ptr->value.first; 
					Node *tmp = this->_ptr->parent;
					while (tmp && this->_key_comp(tmp->value.first, key))
						tmp = tmp->parent;
					if (tmp)
					{
						this->_ptr = tmp;
						return *this;
					}
				}
				this->_ptr = this->_end;
				return *this;
			}
			
			map_iterator    operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }
			
			map_iterator&   operator--()
			{
				if (this->_ptr == this->_end)
				{
					//encontrar o maior
					this->_ptr = this->_ptr->parent;   
					return *this;
				}
				else if (this->_ptr->left)
				{
					this->_ptr = this->_ptr->left->max();
					return *this;
				}
				else if (this->_ptr->parent)
				{
					//encontrar o primeiro nó menor anterior
					key_type key = this->_ptr->value.first;   
					Node *tmp = this->_ptr->parent;
					while (tmp && this->_key_comp(key, tmp->value.first))
						tmp = tmp->parent;
					if (tmp)
					{
						this->_ptr = tmp;
						return *this;
					}
				}
				else
				{
					//so verificar um caso
				}
				
				return *this;
			}
			
			map_iterator    operator--(int) { map_iterator tmp = *this; --*this; return tmp; }

			/*  Operadores de comparação   */
			friend bool		operator== (const map_iterator& lhs, const map_iterator& rhs) {
				return lhs._ptr == rhs._ptr; }
			friend bool 	operator!= (const map_iterator& lhs, const map_iterator& rhs) {
				return lhs._ptr != rhs._ptr; }

		private:
			Node*		_ptr;
			Node*		_end;
			key_compare	_key_comp;
	};

		struct random_access_iterator_tag {};
		struct bidirectional_iterator_tag {};

		template< typename U >
    	class random_access  {
        public :

			  /************************/
			 /*     Member types     */
			/************************/

            typedef U iter_value;
            typedef U								value_type;
		    typedef value_type&						reference;
		    typedef value_type*						pointer;
		    typedef value_type const&				const_reference;
		    typedef value_type const*				const_pointer;

		    typedef typename std::ptrdiff_t			difference_type;
		    typedef std::random_access_iterator_tag	iterator_category;

            pointer _ptr;

			  /****************************/
			 /*     Member functions     */
			/****************************/
            
			 /***************************************************************************/
			/*** constructors ------------------------------------------------------ ***/

			/* Default */ 
            random_access() : _ptr(NULL) {}

			/*  Copy  */
            random_access( pointer iter ) : _ptr(iter){}

			/*  Pointer constructor */
            random_access( random_access const& rhs ) : _ptr(rhs._ptr) { }

			/*  Destructor  */
            ~random_access( void ) {}

             /***************************************************************************/
			/*** operator= --------------------------------------------------------- ***/
            template< class T >
            random_access& operator=( const random_access<T>& rhs ) {
                if ( this == &rhs )
                    return ( *this );
                this->_ptr = rhs.base();
                return *this;
            }

			/* operators : incr / decr */
            random_access& operator++() { this->_ptr++; return (*this); }

            random_access operator++(int) { 
                random_access tmp(*this);
                _ptr++;
                return (tmp);
            }

            random_access& operator--() { this->_ptr--; return (*this); }

            random_access operator--(int) { 
                random_access tmp(*this);
                _ptr--;
                return (tmp);
            }

            random_access operator+( difference_type n ) const {
                random_access aux(*this);
                aux += n;
                return ( aux );
            }

            random_access& operator+=(difference_type i ) {
                this->_ptr += i;
                return ( *this );
            }

            random_access operator-(difference_type i ) const { return (*this + (-i)); }
            random_access operator-=(difference_type i ) { 
                this->_ptr -= i;
                return ( *this );
            }
            reference operator[](int i ) const{ return (this->_ptr[i]);}
            reference operator*() const { return *this->_ptr; }
            pointer operator->() { return this->_ptr; }
            pointer get(){return this->_ptr;}

            /*  Operadores de comparação   */
            operator random_access<value_type const>() const
		    {
			    return random_access<value_type const>(_ptr);
		    }    

		    bool operator==(random_access const& rhs) const { return (_ptr == rhs._ptr); }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator==(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator!=(random_access const& rhs) const { return _ptr != rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator!=(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator<(random_access const& rhs) const { return _ptr < rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator<(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator>(random_access const& rhs) const { return _ptr > rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool
		    operator>(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator<=(random_access const& rhs) const { return _ptr <= rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator<=(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);
    
		    bool operator>=(random_access const& rhs) const { return _ptr >= rhs._ptr; }
    
		    template<typename iterator, typename iterator2>
		    friend bool operator>=(ft::random_access<iterator> const& lhs, ft::random_access<iterator2> const& rhs);

        };
          ////////////////////////////////////////
	 	 //     Non-member func overloads      //
		////////////////////////////////////////
        template <class Iterator, class Iterator2>
        bool operator==(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }

        template <class Iterator, class Iterator2>
        bool operator!=(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }

        template <class Iterator, class Iterator2>
        bool operator<(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }

    	template <class Iterator, class Iterator2>
        bool operator<=(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }

        template <class Iterator, class Iterator2>
        bool operator>(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }

        template <class Iterator, class Iterator2>
        bool operator>=(const ft::random_access<Iterator>& lhs, const ft::random_access<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }

        template<class iterator>
	    ft::random_access<iterator>
	    operator+(typename ft::random_access<iterator>::difference_type n,
	    			ft::random_access<iterator> const& rhs) { return rhs.base() + n.base(); }
        
        template<class iterator>
	    ft::random_access<iterator>
	    operator-(typename ft::random_access<iterator>::difference_type n,
	    			ft::random_access<iterator> const& rhs) { return n.base() - rhs.base() ; }

}

#endif