/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 01:10:13 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/03/09 10:19:39 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP_
# define ITERATOR_HPP_

# include "nullptr_t.hpp"
# include "iterator_traits.hpp"

namespace ft {
	template<class T>
	class iterator {
		public:
			// typedefs
			typedef T													it_type;

			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

			// constructors
			iterator() : _it(ft::nullptr_t) {}
			iterator(const it_type& it) : _it(it) {}
			template<class U>
			iterator(const iterator<U>& other) : _it(other.base()) {}
			virtual ~iterator() {}

			// assign operator
			template<class U>
			iterator& operator=(const iterator<U>& other) {
				if (this == &other) return *this;
				this->_it = other.base();
				return *this;
			}

			// getter
			it_type base() const { return this->_it; }

			// access operators
			reference operator*() const { return *_it; }
			pointer operator->() const { return &(*_it); }
			reference operator[](difference_type n) const { return *(_it + n); }
			// arithmetic operators
			iterator& operator++() {
				++_it;
				return *this;
			}
			iterator& operator--() {
				--_it;
				return *this;
			}
			iterator operator++(int) {
				iterator ret(*this);
				++_it;
				return ret;
			}
			iterator operator--(int) {
				iterator ret(*this);
				--_it;
				return ret;
			}
			iterator operator+(difference_type n) const {
				return iterator(this->_it + n);
			}
			iterator operator-(difference_type n) const {
				//return iterator(this->_it - n);
				return iterator(*this + (-n));
			}
			iterator& operator+=(difference_type n) const {
				*this = *this + n;
				return *this;
			}
			iterator& operator-=(difference_type n) const {
				*this = *this + (-n);
				return *this;
			}
		protected:
			it_type _it;
	};

	// iterator & iterator operators
	template<class T, class U>
	bool operator>(const iterator<T>& lhs, const iterator<U>& rhs) {
		return lhs.base() < rhs.base();
	}
	template<class T, class U>
	bool operator<(const iterator<T>& lhs, const iterator<U>& rhs) {
		return rhs > lhs;
	}
	template<class T, class U>
	bool operator>=(const iterator<T>& lhs, const iterator<U>& rhs) {
		return !(rhs > lhs);
	}
	template<class T, class U>
	bool operator<=(const iterator<T>& lhs, const iterator<U>& rhs) {
		return !(lhs > rhs);
	}
	template<class T, class U>
	bool operator==(const iterator<T>& lhs, const iterator<U>& rhs) {
		return lhs.base() == rhs.base();
	}
	template<class T, class U>
	bool operator!=(const iterator<T>& lhs, const iterator<U>& rhs) {
		return !(lhs == rhs);
	}

	// iterator & iterator arithmetic operators
	//template<class T, class U>
}

#endif
