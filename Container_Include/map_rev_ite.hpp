/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rev_ite.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:13:09 by oavelar           #+#    #+#             */
/*   Updated: 2021/12/21 22:11:03 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REV_ITE_HPP
# define MAP_REV_ITE_HPP

#include <iostream>

namespace ft
{
    /**************************/
    /*                        */
    /*     Struct of node     */
    /*                        */
    /**************************/
    template <class Key, class T>
    struct map_node
    {
        std::pair<Key, T>   content;
        bool                color;
        map_node            *right;
        map_node            *left;
        map_node            *parent;
    };
    //namespace map
    //{
        /**************************/
        /*                        */
        /*     Const_iterator     */
        /*                        */
        /**************************/
        template <class Key, class T>
        class const_iterator
        {
            public:
                /************************/
                /*     Member types     */
                /************************/
                typedef Key                                 key_type;
                typedef T                                   mapped_type;
                typedef std::pair<key_type, mapped_type>    value_type;
                typedef std::pair<key_type, mapped_type>    &reference;
			    typedef std::pair<key_type, mapped_type>    *pointer;
			    typedef std::ptrdiff_t                      difference_type;

                /****************************/
                /*     Member functions     */
                /****************************/

                /***************************************************************************/
                /*** constructors ------------------------------------------------------ ***/
                const_iterator() {};
                const_iterator(map_node<key_type, mapped_type> *current_node) : _current_node(current_node) {}
                const_iterator(const_iterator const &copy) : _current_node(copy._current_node) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                const_iterator &operator=(const_iterator const &b) const
                {
                    if (this != &b)
                        _current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                virtual ~const_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type const    &operator*() { return (_current_node->content);}
                value_type const    *operator->() { return (&(this->_current_node->content));}
                const_iterator      &operator++() //++i
                {
                    if (_current_node->right)
                    {
                        _current_node = _current_node->right;
                        while (_current_node->left)
                            _current_node = _current_node->left;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = _current_node->parent;
                    while (parent_node != 0 && _current_node == parent_node->right)
                    {
                        _current_node = _current_node->parent;
                        parent_node = _current_node->parent;
                    }
                    _current_node = parent_node;
                    return (*this);
                }
                const_iterator      operator++(int)
                {
                    const_iterator tmp(*this);
                    operator++();
                    return (tmp);
                }
                const_iterator      &operator--()
                {
                    if (_current_node->left)
                    {
                        _current_node = _current_node->left;
                        while (_current_node->right)
                            _current_node = _current_node->right;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = _current_node->parent;
                    while (parent_node != 0 && _current_node == parent_node->left)
                    {
                        _current_node = _current_node->parent;
                        parent_node = _current_node->parent;
                    }
                    _current_node = parent_node;
                    return (*this);
                }
                const_iterator      operator--(int)
                {
                    const_iterator tmp(*this);
                    operator--();
                    return (tmp);
                }
                bool operator==(const_iterator<key_type, mapped_type> const &b)
                {
                    return (_current_node == b._current_node);
                }
                bool operator!=(const_iterator<key_type, mapped_type> const &b)
                {
                    return (_current_node != b._current_node);
                }

                /***************************************************************************/
                /*** getters ----------------------------------------------------------- ***/
                map_node<key_type, mapped_type> *get_node() { return (_current_node);}

                protected:
                    map_node<key_type, mapped_type> *_current_node;
        };

        /********************/
        /*                  */
        /*     Iterator     */
        /*                  */
        /********************/
        template <class Key, class T>
        class iterator : public const_iterator<Key, T>
        {
            public:
                /************************/
                /*     Member types     */
                /************************/
                typedef Key                                 key_type;
                typedef T                                   mapped_type;
                typedef std::pair<key_type, mapped_type>    value_type;
                typedef std::pair<key_type, mapped_type>    &reference;
			    typedef std::pair<key_type, mapped_type>    *pointer;
			    typedef std::ptrdiff_t                      difference_type;

                /****************************/
                /*     Member functions     */
                /****************************/

                /***************************************************************************/
                /*** constructors ------------------------------------------------------ ***/
                iterator(){};
                iterator(map_node<key_type, mapped_type> *current_node) : const_iterator<key_type, mapped_type>(current_node) {}
                iterator(iterator const &copy) : const_iterator<key_type, mapped_type>(copy) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                iterator &operator=(iterator const &b)
                {
                    if (this != &b)
                        this->_current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                ~iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type  &operator*() { return (this->_current_node->content);}
                value_type  *operator->() { return (&(this->_current_node->content));}
                iterator    &operator++() //++i
                {
                    if (this->_current_node->right)
                    {
                        this->_current_node = this->_current_node->right;
                        while (this->_current_node->left)
                            this->_current_node = this->_current_node->left;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = this->_current_node->parent;
                    while (parent_node != 0 && this->_current_node == parent_node->right)
                    {
                        this->_current_node = this->_current_node->parent;
                        parent_node = this->_current_node->parent;
                    }
                    this->_current_node = parent_node;
                    return (*this);
                }
                iterator    operator++(int)
                {
                    iterator tmp(*this);
                    operator++();
                    return (tmp);
                }
                iterator    &operator--()
                {
                    if (this->_current_node->left)
                    {
                        this->_current_node = this->_current_node->left;
                        while (this->_current_node->right)
                            this->_current_node = this->_current_node->right;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = this->_current_node->parent;
                    while (parent_node != 0 && this->_current_node == parent_node->left)
                    {
                        this->_current_node = this->_current_node->parent;
                        parent_node = this->_current_node->parent;
                    }
                    this->_current_node = parent_node;
                    return (*this);
                }
                iterator    operator--(int)
                {
                    iterator tmp(*this);
                    operator--();
                    return (tmp);
                }
        };

        /**********************************/
        /*                                */
        /*     Const_reverse_iterator     */
        /*                                */
        /**********************************/
        template <class Key, class T>
        class const_reverse_iterator
        {
            public:
                /************************/
                /*     Member types     */
                /************************/
                typedef Key                                 key_type;
                typedef T                                   mapped_type;
                typedef std::pair<key_type, mapped_type>    value_type;
                typedef std::pair<key_type, mapped_type>    &reference;
			    typedef std::pair<key_type, mapped_type>    *pointer;
			    typedef std::ptrdiff_t                      difference_type;

                /****************************/
                /*     Member functions     */
                /****************************/

                /***************************************************************************/
                /*** constructors ------------------------------------------------------ ***/
                const_reverse_iterator() {};
                const_reverse_iterator(map_node<key_type, mapped_type> *current_node) : _current_node(current_node) {}
                const_reverse_iterator(const_reverse_iterator const &copy) : _current_node(copy._current_node) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                const_reverse_iterator &operator=(const_reverse_iterator const &b) const
                {
                    if (this != &b)
                        _current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                virtual ~const_reverse_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type const            &operator*() { return (_current_node->content);}
                value_type const            *operator->() { return (&(this->_current_node->content));}
                const_reverse_iterator      &operator++() //++i
                {
                    if (_current_node->left)
                    {
                        _current_node = _current_node->left;
                        while (_current_node->right)
                            _current_node = _current_node->right;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = _current_node->parent;
                    while (parent_node != 0 && _current_node == parent_node->left)
                    {
                        _current_node = _current_node->parent;
                        parent_node = _current_node->parent;
                    }
                    _current_node = parent_node;
                    return (*this);
                }
                const_reverse_iterator      operator++(int) 
                {
                    const_reverse_iterator tmp(*this);
                    operator++();
                    return (tmp);
                }
                const_reverse_iterator      &operator--()
                {
                    if (_current_node->right)
                    {
                        _current_node = _current_node->right;
                        while (_current_node->left)
                            _current_node = _current_node->left;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = _current_node->parent;
                    while (parent_node != 0 && _current_node == parent_node->right)
                    {
                        _current_node = _current_node->parent;
                        parent_node = _current_node->parent;
                    }
                    _current_node = parent_node;
                    return (*this);
                }
                const_reverse_iterator      operator--(int)
                {
                    const_reverse_iterator tmp(*this);
                    operator--();
                    return (tmp);
                }
                bool    operator==(const_reverse_iterator<key_type, mapped_type> const &b)
                {
                    return (_current_node == b._current_node);
                }
                bool    operator!=(const_reverse_iterator<key_type, mapped_type> const &b)
                {
                    return (_current_node != b._current_node);
                }

                /***************************************************************************/
                /*** getters ----------------------------------------------------------- ***/
                map_node<key_type, mapped_type> *get_node() { return (_current_node);}

                protected:
                    map_node<key_type, mapped_type> *_current_node;
        };

        /****************************/
        /*                          */
        /*     Reverse_iterator     */
        /*                          */
        /****************************/
        template <class Key, class T>
        class reverse_iterator : public const_reverse_iterator<Key, T>
        {
            public:
                /************************/
                /*     Member types     */
                /************************/
                typedef Key                                 key_type;
                typedef T                                   mapped_type;
                typedef std::pair<key_type, mapped_type>    value_type;
                typedef std::pair<key_type, mapped_type>    &reference;
			    typedef std::pair<key_type, mapped_type>    *pointer;
			    typedef std::ptrdiff_t                      difference_type;

                /****************************/
                /*     Member functions     */
                /****************************/

                /***************************************************************************/
                /*** constructors ------------------------------------------------------ ***/
                reverse_iterator(){};
                reverse_iterator(map_node<key_type, mapped_type> *current_node) : const_reverse_iterator<key_type, mapped_type>(current_node) {}
                reverse_iterator(reverse_iterator const &copy) : const_reverse_iterator<key_type, mapped_type>(copy) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                reverse_iterator &operator=(reverse_iterator const &b)
                {
                    if (this != &b)
                        this->_current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                ~reverse_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type          &operator*() { return (this->_current_node->content);}
                value_type          *operator->() { return (&(this->_current_node->content));}
                reverse_iterator    &operator++() //++i
                {
                    if (this->_current_node->left)
                    {
                        this->_current_node = this->_current_node->left;
                        while (this->_current_node->right)
                            this->_current_node = this->_current_node->right;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = this->_current_node->parent;
                    while (parent_node != 0 && this->_current_node == parent_node->left)
                    {
                        this->_current_node = this->_current_node->parent;
                        parent_node = this->_current_node->parent;
                    }
                    this->_current_node = parent_node;
                    return (*this);
                }
                reverse_iterator      operator++(int) 
                {
                    reverse_iterator tmp(*this);
                    operator++();
                    return (tmp);
                }
                reverse_iterator      &operator--()
                {
                    if (this->_current_node->right)
                    {
                        this->_current_node = this->_current_node->right;
                        while (this->_current_node->left)
                            this->_current_node = this->_current_node->left;
                        return (*this);
                    }
                    map_node<key_type, mapped_type> *parent_node;
                    parent_node = this->_current_node->parent;
                    while (parent_node != 0 && this->_current_node == parent_node->right)
                    {
                        this->_current_node = this->_current_node->parent;
                        parent_node = this->_current_node->parent;
                    }
                    this->_current_node = parent_node;
                    return (*this);
                }
                reverse_iterator      operator--(int)
                {
                    reverse_iterator tmp(*this);
                    operator--();
                    return (tmp);
                }
        };
    //}
}

#endif