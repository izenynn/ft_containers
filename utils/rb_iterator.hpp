/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:00:12 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/14 21:13:00 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_ITERATOR_HPP_
# define RB_ITERATOR_HPP_

# include "iterator_traits.hpp"

namespace ft {
	template<class Node, class T>
	class rbiterator {
		public:
			// typedefs
			typedef T											value_type;
			typedef Node										node_pointer; //
			typedef std::ptrdiff_t								difference_type; //
			typedef value_type&									reference;
			typedef value_type*									pointer;

			//typedef typename ft::iterator_traits<Node>::value_type		node_type;
			//typedef typename ft::iterator_traits<Node>::difference_type	difference_type;
			//typedef typename ft::iterator_traits<Node>::reference		node_reference;
			//typedef typename ft::iterator_traits<Node>::pointer			node_pointer;

			typedef typename std::bidirectional_iterator_tag			iterator_category;

			// constructors
			rbiterator() {} // public accessible?

			template<class U, class T1>
			rbiterator(const rbiterator<U, T1>& other) {
				this->_current = other.getCurrent();
				this->_root = other.getRoot();
				this->_nil = other.getNil();
			}

			explicit
			rbiterator(node_pointer current, node_pointer root, node_pointer nil)
			: _current(current),
			  _root(root),
			  _nil(nil) {}

			~rbiterator() {}

			// assign operator
			template<class U, class T1>
			rbiterator& operator=(const rbiterator<U, T1>& other) {
				this->_current = other.getCurrent();
				this->_root = other.getRoot();
				this->_nil = other.getNil();
				return *this;
			}

			// member functions
			node_pointer getCurrent() const { return this->_current; }
			node_pointer getRoot() const { return this->_root; }
			node_pointer getNil() const { return this->_nil; }

			// operators
			reference operator*() const { return this->_current->data; }
			pointer operator->() const { return &this->_current->data; }

			rbiterator& operator++() {
				if (this->_current->right != this->_nil) {
					this->_current = this->_current->right;
					while (this->_current->left != this->_nil) {
						this->_current = this->_current->left;
					}
				} else {
					while (this->_current->parent != this->_nil
							&& this->_current == this->_current->parent->right)
						this->_current = this->_current->parent;
					this->_current = this->_current->parent;
				}
				return *this;
			}
			rbiterator operator++(int) {
				rbiterator aux(*this);
				operator++();
				return aux;
			}

			rbiterator& operator--() {
				if (this->_current->left != this->_nil) {
					this->_current = this->_current->left;
					while (this->_current->right != this->_nil) {
						this->_current = this->_current->right;
					}
				} else {
					node_pointer aux = this->_current->parent;
					while (aux != this->_nil && this->_current == aux->left) {
						this->_current = aux;
						aux = aux->parent;
					}
					this->_current = this->_current->parent;
				}
				return *this;
			}
			rbiterator operator--(int) {
				rbiterator aux(*this);
				operator--();
				return aux;
			}
		protected:
			node_pointer _current;
			node_pointer _root;
			node_pointer _nil;
	};

	// operators overload
	template<class U1, class U2, class T1, class T2>
	bool operator==(const rbiterator<U1, T1>& lhs, const rbiterator<U2, T2>& rhs) {
		return lhs.getCurrent() == rhs.getCurrent();
	}
	template<class U1, class U2, class T1, class T2>
	bool operator!=(const rbiterator<U1, T1>& lhs, const rbiterator<U2, T2>& rhs) {
		return !(lhs == rhs);
	}
	template<class U1, class U2, class T1, class T2>
	bool operator<(const rbiterator<U1, T1>& lhs, const rbiterator<U2, T2>& rhs) {
		return lhs.getCurrent() < rhs.getCurrent();
	}
	template<class U1, class U2, class T1, class T2>
	bool operator>(const rbiterator<U1, T1>& lhs, const rbiterator<U2, T2>& rhs) {
		return rhs < lhs;
	}
	template<class U1, class U2, class T1, class T2>
	bool operator<=(const rbiterator<U1, T1>& lhs, const rbiterator<U2, T2>& rhs) {
		return !(rhs < lhs);
	}
	template<class U1, class U2, class T1, class T2>
	bool operator>=(const rbiterator<U1, T1>& lhs, const rbiterator<U2, T2>& rhs) {
		return !(lhs < rhs);
	}

	template<class U1, class U2, class T1, class T2>
	typename ft::rbiterator<U1, T1>::difference_type
	operator-(const ft::rbiterator<U1, T1>& lhs, const ft::rbiterator<U2, T2>& rhs) {
		return lhs.getCurrent() - rhs.getCurrent();
	}

	template<class U1, class T1>
	rbiterator<U1, T1>
	operator+(typename ft::rbiterator<U1, T1>::difference_type n, const ft::rbiterator<U1, T1>& rhs) {
		return ft::rbiterator<U1, T1>(rhs.getCurrent() + n);
	}
}

#endif
